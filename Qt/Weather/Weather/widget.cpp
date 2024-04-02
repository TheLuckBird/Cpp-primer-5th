#include "widget.h"
#include <QApplication>
#include <QContextMenuEvent>
#include <QLineEdit>
#include <QPushButton>
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include <QUrl>
#include <QMessageBox>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

// 温度曲线相关的宏
#define INCREMENT 3 // 温度每升高/降低1度，y轴坐标的增量
#define POINT_RADIUS 3 // 曲线描点的大小
#define TEXT_OFFSET_X 12 // 温度文本相对于点的偏移
#define TEXT_OFFSET_Y 10 // 温度文本相对于点的偏移

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    manager = new QNetworkAccessManager(this);
    connect(manager,&QNetworkAccessManager::finished,this,&Widget::onReplied);

    // 直接在构造中，去请求天气数据,服务器返回数据时，QNetworkAccessManager返回finished信号
    getWeatherInfo("101010100"); // 101010100 是北京的城市编码

    //ui无边框
    setWindowFlag(Qt::FramelessWindowHint);

    //实例化菜单和菜单项
    mExitMenu = new QMenu(this);
    mExitAct = new QAction();

    //菜单项添加到菜单里
    mExitMenu->addAction(mExitAct);
    mExitAct->setText("退出");
    mExitAct->setIcon(QIcon(":/res/close.png"));

    //mExitAct的信号槽
    connect(mExitAct,&QAction::triggered,this,[=]()
    {
        qApp->exit(0);
    });

    //设置背景
    this->setObjectName("weather_widget");

    this->setStyleSheet(R"(
        QWidget#weather_widget {
        background-color:rgba(50,115,165,255);
        }
        QLabel {
        font: 12pt "Microsoft YaHei";
        border-radius: 4px;
        color: rgb(255, 255, 255);
        padding: 12px;
        }
    )");

    //创建布局
    mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(10);
    mainLayout->setContentsMargins(18,18,18,18);

    //顶部
    topLayout = new QHBoxLayout(this);

    //底部
    QHBoxLayout *bottomLayout = new QHBoxLayout(this);
    leftLayout = new QVBoxLayout(this);
    rightLayout = new QVBoxLayout(this);

    leftLayout->setContentsMargins(0,0,0,0);
    rightLayout->setSpacing(16);

    bottomLayout->addLayout(leftLayout);
    bottomLayout->addLayout(rightLayout);
    bottomLayout->setStretch(0,2);
    bottomLayout->setStretch(1,4);

    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(bottomLayout);

    initTop();
    initLeft();
    initRight();

    initData();

    QTimer *timer = new QTimer();
    connect(timer,&QTimer::timeout,this,&Widget::updateUI);
    cityIndex = 0;
    timer->start(3000);



}

Widget::~Widget()
{

}

//重写父类的虚函数，父类默认的实现是忽略右键菜单事件，重写后处理右键菜单事件
void Widget::contextMenuEvent(QContextMenuEvent *event)
{
    mExitMenu->exec(QCursor::pos());

    event->accept();
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    // qDebug() << "界面左上角坐标：" << this->pos() << "光标坐标：" << event->globalPos();

    mOffset = this->pos() - event->globalPos();
    // qDebug() << mOffset;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() + mOffset);

}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == lbHigh && event->type() == QEvent::Paint)
    {
        paintHighCurve();
    }
    if(watched == lbLow && event->type() == QEvent::Paint)
    {
        paintLowCurve();
    }
    return QWidget::eventFilter(watched,event);
}

void Widget::getWeatherInfo(QString cityCode)
{
    QUrl url("http://t.weather.itboy.net/api/weather/city/" + cityCode);
    manager->get(QNetworkRequest(url));
}

void Widget::initTop()
{
    //城市输入框
    QLineEdit *leCity = new QLineEdit(this);
    leCity->setFixedWidth(360);
    leCity->setStyleSheet(R"(
        font:14pt Microsoft YaHei;
        background-color:rgb(255,255,255);
        border-radius:4px;
        padding:4px 8px;

    )");

    //搜索按钮
    QPushButton *btnSearch = new QPushButton(this);
    btnSearch->setStyleSheet(R"(
        background-color:rgba(255,255,255,0);
    )");
    btnSearch->setIcon(QIcon(":/res/search.png"));
    btnSearch->setIconSize(QSize(24,24));

    //弹簧
    QSpacerItem *space = new QSpacerItem(32,32,QSizePolicy::Expanding,QSizePolicy::Minimum);

    //日期
    lbDate = new QLabel(this);
    lbDate->setStyleSheet(R"(
        font:20pt Microsoft YaHei;
        background-color:rgba(255,255,255,0);

    )");

    lbDate->setAlignment(Qt::AlignCenter);
    lbDate->setText("2024/03/25 星期一");

    topLayout->addWidget(leCity);
    topLayout->addWidget(btnSearch);
    topLayout->addItem(space);
    topLayout->addWidget(lbDate);
}

void Widget::initLeft()
{
    //天气温度城市类型高低温
    QHBoxLayout *Layout = new QHBoxLayout();
    Layout->setSpacing(0);

    //天气
    lbTypeIcon = new QLabel(this);
    lbTypeIcon->setFixedSize(150,150);
    lbTypeIcon->setStyleSheet("background-color:rgba(255,255,255,0)");
    lbTypeIcon->setPixmap(QPixmap(":/res/DuoYun.png"));
    lbTypeIcon->setScaledContents(true);
    lbTypeIcon->setAlignment(Qt::AlignCenter);
    Layout->addWidget(lbTypeIcon);

    //温度
    lbTemp = new QLabel(this);
    lbTemp->setText("18°");
    lbTemp->setStyleSheet(R"(
        font:50pt Arial;
        background-color:rgba(255,255,255,0);
        padding:0px;
    )");
    lbTemp->setAlignment(Qt::AlignBottom);

    //城市
    lbCity = new QLabel(this);
    lbCity->setText("重庆");
    lbCity->setStyleSheet(R"(
        font:12pt Microsoft YaHei;
        background-color:rgba(255,255,255,0);
        padding:0px 0px 24px 0px;
    )");
    lbCity->setAlignment(Qt::AlignTop);
    QSpacerItem *item1 = new QSpacerItem(16,1,QSizePolicy::Fixed,QSizePolicy::Minimum);

    //类型
    lbType = new QLabel(this);
    lbType->setText("多云");
    lbType->setStyleSheet(R"(
        font:12pt Microsoft YaHei;
        background-color:rgba(255,255,255,0);
        padding:0px 0px 24px 0px;
    )");
    lbType->setAlignment(Qt::AlignTop);
    QSpacerItem *item2 = new QSpacerItem(16,1,QSizePolicy::Fixed,QSizePolicy::Minimum);

    //高低温
    lbLowHigh = new QLabel(this);
    lbLowHigh->setText("13-23°C");
    lbLowHigh->setStyleSheet(R"(
        font:12pt Microsoft YaHei;
        background-color:rgba(255,255,255,0);
        padding:0px 0px 24px 0px;
    )");
    lbLowHigh->setAlignment(Qt::AlignTop);

    QVBoxLayout *vLayout= new QVBoxLayout();
    QHBoxLayout *hLayout1 = new QHBoxLayout();
    QHBoxLayout *hLayout2 = new QHBoxLayout();

    hLayout1->addWidget(lbTemp);

    hLayout2->addWidget(lbCity);
    hLayout2->addItem(item1);
    hLayout2->addWidget(lbType);
    hLayout2->addItem(item2);
    hLayout2->addWidget(lbLowHigh);

    vLayout->addLayout(hLayout1);
    vLayout->addLayout(hLayout2);

    Layout->addLayout(vLayout);

    //弹簧
    QSpacerItem *space = new QSpacerItem(1,1,QSizePolicy::Fixed,QSizePolicy::Expanding);
    leftLayout->addItem(space);

    leftLayout->addLayout(Layout);


    //感冒指数
    lbGanMao = new QLabel(this);
    lbGanMao->setText("感冒指数：儿童、老人减少户外运动");
    lbGanMao->setStyleSheet(R"(
        font:12pt Arial;
        background-color:rgba(255,255,255,0);
        padding-left:5px;
        padding-right:5px
    )");
    lbGanMao->setWordWrap(true);
    lbGanMao->setAlignment(Qt::AlignTop);
    leftLayout->addWidget(lbGanMao);

    //风力PM2.5湿度空气质量
    QWidget *widget = new QWidget(this);
    widget->setStyleSheet(R"(
        background-color:rgb(157,133,255);
        border-radius:15px;
    )");
    QGridLayout *gridLayout = new QGridLayout(widget);
    gridLayout->setHorizontalSpacing(40);
    gridLayout->setVerticalSpacing(30);
    gridLayout->setContentsMargins(40,25,40,25);

    //风力
    QHBoxLayout *hItem1 = new QHBoxLayout();
    hItem1->setSpacing(0);

    lbFLIcon = new QLabel(this);
    lbFLIcon->setFixedSize(72,72);
    lbFLIcon->setStyleSheet("background-color:rgba(255,255,255,0)");
    lbFLIcon->setPixmap(QPixmap(":/res/wind.png"));
    lbFLIcon->setScaledContents(true);
    lbFLIcon->setAlignment(Qt::AlignCenter);
    hItem1->addWidget(lbFLIcon);

    QVBoxLayout *vItem1 = new QVBoxLayout();
    lbFX = new QLabel(this);
    lbFX->setText("东风");
    lbFX->setStyleSheet(R"(
        background-color:rgba(255,255,255,0);
        font:10pt "Microsoft YaHei";
        padding:24px 0px 0px 0px;
    )");
    lbFX->setAlignment(Qt::AlignCenter);
    lbFX->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    vItem1->addWidget(lbFX);

    lbFL = new QLabel(this);
    lbFL->setText("三级");
    lbFL->setStyleSheet(R"(
        background-color:rgba(255,255,255,0);
        font:bold 10pt "Microsoft YaHei";
        padding:0px 0px 24px 0px;
    )");

    lbFL->setAlignment(Qt::AlignCenter);
    lbFL->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    vItem1->addWidget(lbFL);

    hItem1->addLayout(vItem1);
    gridLayout->addLayout(hItem1,0,0,1,1);

    //PM2.5
    QHBoxLayout *hItem2 = new QHBoxLayout();
    hItem2->setSpacing(0);

    lbPm25Icon = new QLabel(this);
    lbPm25Icon ->setFixedSize(72,72);
    lbPm25Icon ->setStyleSheet("background-color:rgba(255,255,255,0)");
    lbPm25Icon ->setPixmap(QPixmap(":/res/pm25.png"));
    lbPm25Icon ->setScaledContents(true);
    lbPm25Icon ->setAlignment(Qt::AlignCenter);
    hItem2->addWidget(lbPm25Icon );

    QVBoxLayout *vItem2 = new QVBoxLayout();
    lbPmTitle = new QLabel(this);
    lbPmTitle->setText("PM2.5");
    lbPmTitle->setStyleSheet(R"(
        background-color:rgba(255,255,255,0);
        font:10pt "Microsoft YaHei";
        padding:24px 0px 0px 0px;
    )");
    lbPmTitle->setAlignment(Qt::AlignCenter);
    lbPmTitle->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    vItem2->addWidget(lbPmTitle);

    lbPM = new QLabel(this);
    lbPM->setText("47");
    lbPM->setStyleSheet(R"(
        background-color:rgba(255,255,255,0);
        font:bold 10pt "Arial";
        padding:0px 0px 24px 0px;
    )");

    lbPM->setAlignment(Qt::AlignCenter);
    lbPM->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    vItem2->addWidget(lbPM);

    hItem2->addLayout(vItem2);
    gridLayout->addLayout(hItem2,0,1,1,1);

    //湿度
    QHBoxLayout *hItem3 = new QHBoxLayout();
    hItem3->setSpacing(0);

    lbSDIcon = new QLabel(this);
    lbSDIcon->setFixedSize(72,72);
    lbSDIcon->setStyleSheet("background-color:rgba(255,255,255,0)");
    lbSDIcon->setPixmap(QPixmap(":/res/humidity.png"));
    lbSDIcon->setScaledContents(true);
    lbFLIcon->setAlignment(Qt::AlignCenter);
    hItem3->addWidget(lbSDIcon);

    QVBoxLayout *vItem3 = new QVBoxLayout();
    lbSDTitle = new QLabel(this);
    lbSDTitle->setText("湿度");
    lbSDTitle->setStyleSheet(R"(
        background-color:rgba(255,255,255,0);
        font:10pt "Microsoft YaHei";
        padding:24px 0px 0px 0px;
    )");
    lbSDTitle->setAlignment(Qt::AlignCenter);
    lbSDTitle->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    vItem3->addWidget(lbSDTitle);

    lbSD = new QLabel(this);
    lbSD->setText("77%");
    lbSD->setStyleSheet(R"(
        background-color:rgba(255,255,255,0);
        font:bold 10pt "Microsoft YaHei";
        padding:0px 0px 24px 0px;
    )");

    lbSD->setAlignment(Qt::AlignCenter);
    lbSD->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    vItem3->addWidget(lbSD);

    hItem3->addLayout(vItem3);
    gridLayout->addLayout(hItem3,1,0,1,1);

    //空气质量
    QHBoxLayout *hItem4 = new QHBoxLayout();
    hItem4->setSpacing(0);

    lbZLIcon = new QLabel(this);
    lbZLIcon->setFixedSize(72,72);
    lbZLIcon->setStyleSheet("background-color:rgba(255,255,255,0)");
    lbZLIcon->setPixmap(QPixmap(":/res/aqi.png"));
    lbZLIcon->setScaledContents(true);
    lbZLIcon->setAlignment(Qt::AlignCenter);
    hItem4->addWidget(lbZLIcon);

    QVBoxLayout *vItem4 = new QVBoxLayout();
    lbZLTitle = new QLabel(this);
    lbZLTitle->setText("空气质量");
    lbZLTitle->setStyleSheet(R"(
        background-color:rgba(255,255,255,0);
        font:10pt "Microsoft YaHei";
        padding:24px 0px 0px 0px;
    )");
    lbZLTitle->setAlignment(Qt::AlignCenter);
    lbZLTitle->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    vItem4->addWidget(lbZLTitle);

    lbZL = new QLabel(this);
    lbZL->setText("78");
    lbZL->setStyleSheet(R"(
        background-color:rgba(255,255,255,0);
        font:bold 10pt "Arial";
        padding:0px 0px 24px 0px;
    )");

    lbZL->setAlignment(Qt::AlignCenter);
    lbZL->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    vItem4->addWidget(lbZL);

    hItem4->addLayout(vItem4);
    gridLayout->addLayout(hItem4,1,1,1,1);

    leftLayout->addWidget(widget);

}

void Widget::initRight()
{
    //星期日期
    QGridLayout *gridLayout1 = new QGridLayout();
    gridLayout1->setHorizontalSpacing(6);
    gridLayout1->setVerticalSpacing(0);

    QStringList weekList = {"昨天", "今天", "明天", "周⼆", "周三", "周四"};
    QStringList dateList = {"03/24", "03/25", "03/26", "03/27", "03/28",
                            "03/29"};

    for(int i = 0;i != weekList.size();++i)
    {
        QLabel *lbWeek = new QLabel(this);
        QLabel *lbDate = new QLabel(this);

        lbWeek->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
        lbDate->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
        lbWeek->setText(weekList[i]);
        lbDate->setText(dateList[i]);
        lbWeek->setStyleSheet(R"(
            border-bottom-left-radius:0px;
            border-bottom-right-radius:0px;
            padding-bottom: 2px;
            padding-left:20px;
            padding-right:20px;
            background-color:rgb(10,180,190);
            )");
        lbDate->setStyleSheet(R"(
            border-top-left-radius:0px;
            border-top-right-radius:0px;
            padding-top: 2px;
            padding-left:20px;
            padding-right:20px;
            background-color:rgb(10,180,190);
            )");
        lbWeek->setAlignment(Qt::AlignCenter);
        lbDate->setAlignment(Qt::AlignCenter);

        mWeekList << lbWeek;
        mDateList << lbDate;

        gridLayout1->addWidget(lbWeek,0,i);
        gridLayout1->addWidget(lbDate,1,i);
        }
    rightLayout->addLayout(gridLayout1);

    //天气类型
    QGridLayout *gridLayout2 = new QGridLayout();
    gridLayout2->setHorizontalSpacing(6);
    gridLayout2->setVerticalSpacing(0);

    QMap<QString,QString> typeMap;
    typeMap.insert("⼩⾬", ":/res/XiaoYu.png");
    typeMap.insert("多云", ":/res/DuoYun.png");
    typeMap.insert("霾", ":/res/Mai.png");
    typeMap.insert("雾", ":/res/Wu.png");
    typeMap.insert("晴", ":/res/Qing.png");
    typeMap.insert("阴", ":/res/Yin.png");

    QList<QString> keys = typeMap.keys();
    for(int i = 0;i < keys.size();++i)
    {
        QLabel *lbTypeIcon = new QLabel(this);
        QLabel *lbType = new QLabel(this);
        lbTypeIcon->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
        lbType->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
        lbTypeIcon->setPixmap(typeMap[keys[i]]);
        lbType->setText(keys[i]);
        lbTypeIcon->setStyleSheet(R"(
                border-bottom-left-radius: 0px;
                border-bottom-right-radius: 0px;
                padding-bottom: 2px;
                padding-left:20px;
                padding-right:20px;
                background-color: rgb(54, 93, 122);
                )");
        lbType->setStyleSheet(R"(
                border-top-left-radius: 0px;
                border-top-right-radius: 0px;
                padding-top: 2px;
                padding-left:20px;
                padding-right:20px;
                background-color: rgb(54, 93, 122);
                )");
        lbTypeIcon->setAlignment(Qt::AlignCenter);
        lbType->setAlignment(Qt::AlignCenter);

        mTypeIconList << lbTypeIcon;
        mTypeList << lbType;

        gridLayout2->addWidget(lbTypeIcon,0,i);
        gridLayout2->addWidget(lbType,1,i);
    }
    rightLayout->addLayout(gridLayout2);

    //空气质量
    QWidget *qualityWidget = new QWidget(this);
    qualityWidget->setStyleSheet("background-color:rgba(51,115,163,255)");
    qualityWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed );

    QHBoxLayout *hLayout = new QHBoxLayout(qualityWidget);
    hLayout->setSpacing(6);
    hLayout->setContentsMargins(0,0,0,0);
    QStringList qualityList = {"优", "良", "轻度", "中度", "重度", "严重"};
    QStringList qualityBgList;
    qualityBgList << "rgb(121, 184, 0)"
                  << "rgb(255, 187, 23)"
                  << "rgb(255, 87, 97)"
                  << "rgb(235, 17, 27)"
                  << "rgb(170, 0, 0)"
                  << "rgb(110, 0, 0)";
    for(int i = 0;i < qualityList.size();++i)
    {
        QLabel *lbQuality = new QLabel(this);
        lbQuality->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        lbQuality->setText(qualityList[i]);
        lbQuality->setStyleSheet(QString("padding:8px;background-color:%1;").arg(qualityBgList[i]));
        lbQuality->setAlignment(Qt::AlignCenter);

        mAqiList << lbQuality;

        hLayout->addWidget(lbQuality);
    }
    rightLayout->addWidget(qualityWidget);

    //温度曲线
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->setSpacing(0);

    lbHigh = new QLabel(this);
    lbHigh->setMinimumHeight(80);
    lbHigh->setStyleSheet(R"(
        border-top-left-radius: 0px;
        border-top-right-radius: 0px;
        padding-bottom: 2px;
        padding-left:20px;
        padding-right:20px;
        background-color: rgba(54, 93, 122,255);
        )");
    lbLow = new QLabel(this);
    lbLow->setMinimumHeight(80);
    lbLow->setStyleSheet(R"(
        border-top-left-radius: 0px;
        border-top-right-radius: 0px;
        padding-top: 2px;
        padding-left:20px;
        padding-right:20px;
        background-color: rgba(54, 93, 122,255);
        )");
    lbHigh->installEventFilter(this);
    lbLow->installEventFilter(this);

    vLayout->addWidget(lbHigh);
    vLayout->addWidget(lbLow);
    rightLayout->addLayout(vLayout);

    //风向风力
    QGridLayout *gridLayout3 = new QGridLayout();
    gridLayout3->setHorizontalSpacing(6);
    gridLayout3->setVerticalSpacing(0);

    QStringList fxList = {"北⻛", "北⻛", "东⻛", "南⻛", "北⻛", "东北⻛"};
    QStringList flList = {"1级", "1级", "2级", "2级", "3级", "2级"};
    for(int i = 0;i != fxList.size();++i)
    {
        QLabel *lbFx = new QLabel(this);
        QLabel *lbFl = new QLabel(this);

        lbFx->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        lbFl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        lbFx->setText(fxList[i]);
        lbFl->setText(flList[i]);
        lbFx->setStyleSheet(R"(
            border-bottom-left-radius: 0px;
            border-bottom-right-radius: 0px;
            padding-bottom: 2px;
            padding-left:20px;
            padding-right:20px;
            background-color: rgb(54, 93, 122);
            )");
        lbFl->setStyleSheet(R"(
            border-top-left-radius: 0px;
            border-top-right-radius: 0px;
            padding-top: 2px;
            padding-left:20px;
            padding-right:20px;
            background-color: rgb(54, 93, 122);
            )");
        lbFx->setAlignment(Qt::AlignCenter);
        lbFl->setAlignment(Qt::AlignCenter);

        mFxList << lbFx;
        mFlList << lbFl;

        gridLayout3->addWidget(lbFx,0,i);
        gridLayout3->addWidget(lbFl,1,i);
    }
    rightLayout->addLayout(gridLayout3);



}

void Widget::initData()
{
    // 1. 初始化天气类型，以及对应的图标
    mTypeMap.insert("暴雪", ":/res/BaoXue.png");
    mTypeMap.insert("暴⾬", ":/res/BaoYu.png");
    mTypeMap.insert("暴⾬到⼤暴⾬", ":/res/BaoYuDaoDaBaoYu.png");
    mTypeMap.insert("⼤暴⾬", ":/res/DaBaoYu.png");
    mTypeMap.insert("⼤暴⾬到特⼤暴⾬", ":/res/DaBaoYuDaoTeDaBaoYu.png");
    mTypeMap.insert("⼤到暴雪", ":/res/DaDaoBaoXue.png");
    mTypeMap.insert("⼤雪", ":/res/DaXue.png");
    mTypeMap.insert("⼤⾬", ":/res/DaYu.png");
    mTypeMap.insert("冻⾬", ":/res/DongYu.png");
    mTypeMap.insert("多云", ":/res/DuoYun.png");
    mTypeMap.insert("浮沉", ":/res/FuChen.png");
    mTypeMap.insert("雷阵⾬", ":/res/LeiZhenYu.png");
    mTypeMap.insert("雷阵⾬伴有冰雹",":/res/LeiZhenYuBanYouBingBao.png");
    mTypeMap.insert("霾", ":/res/Mai.png");
    mTypeMap.insert("强沙尘暴", ":/res/QiangShaChenBao.png");
    mTypeMap.insert("晴", ":/res/Qing.png");
    mTypeMap.insert("沙尘暴", ":/res/ShaChenBao.png");
    mTypeMap.insert("特⼤暴⾬", ":/res/TeDaBaoYu.png");
    mTypeMap.insert("undefined", ":/res/undefined.png");
    mTypeMap.insert("雾", ":/res/Wu.png");
    mTypeMap.insert("⼩到中雪", ":/res/XiaoDaoZhongXue.png");
    mTypeMap.insert("⼩到中⾬", ":/res/XiaoDaoZhongYu.png");
    mTypeMap.insert("⼩雪", ":/res/XiaoXue.png");
    mTypeMap.insert("⼩⾬", ":/res/XiaoYu.png");
    mTypeMap.insert("雪", ":/res/Xue.png");
    mTypeMap.insert("扬沙", ":/res/YangSha.png");
    mTypeMap.insert("阴", ":/res/Yin.png");
    mTypeMap.insert("⾬", ":/res/Yu.png");
    mTypeMap.insert("⾬夹雪", ":/res/YuJiaXue.png");
    mTypeMap.insert("阵雪", ":/res/ZhenXue.png");
    mTypeMap.insert("阵⾬", ":/res/ZhenYu.png");
    mTypeMap.insert("中到⼤雪", ":/res/ZhongDaoDaXue.png");
    mTypeMap.insert("中到⼤⾬", ":/res/ZhongDaoDaYu.png");
    mTypeMap.insert("中雪", ":/res/ZhongXue.png");
    mTypeMap.insert("中⾬", ":/res/ZhongYu.png");

    // //2.初始化四个城市的天气信息
    //     WeatherInfo chongqing;
    //     chongqing.city = "重庆";
    //     chongqing.dateWeek = "2024/03/26 星期二";
    //     chongqing.temp = 23;
    //     chongqing.ganMao = "儿童、老年人及心脏呼吸系统疾病患者人群应减少长时间或高强度户外锻炼";
    //                     chongqing.pm25 = 76;
    //     chongqing.humidity = 66;
    //     chongqing.quality = "轻度";
    //     chongqing.weekList = {"周⽇", "周⼀", "周⼆", "周三", "周四", "周五"};
    //     chongqing.dateList = {"12/31", "01/01", "01/02", "01/03", "01/04", "01/05"};
    //     chongqing.typeList = {"小雨", "多云", "霾", "雾", "晴", "阴"};
    //     chongqing.qualityList = {23, 98, 150, 45, 98, 33};
    //     chongqing.highTemp = {29, 22, 20, 27, 23, 29};
    //     chongqing.lowTemp = {12, 18, 13, 15, 18, 12};
    //     chongqing.fx = {"北⻛", "南⻛", "西南⻛", "南⻛", "南⻛", "西⻛"};
    //     chongqing.fl = {2, 1, 2, 2, 2, 2};

    //     WeatherInfo beijing;
    //     // beijing.city = "北京";
    //     // beijing.dateWeek = "2024/03/26 星期二";
    //     // beijing.temp = -2;
    //     // beijing.ganMao = "儿童、老年人及心脏呼吸系统疾病患者人群应减少长时间或高强度户外锻炼";
    //     // beijing.pm25 = 92;
    //     // beijing.humidity = 55;
    //     // beijing.quality = "轻度";
    //     // beijing.weekList = {"周⽇", "周⼀", "周⼆", "周三", "周四", "周五"};
    //     // beijing.dateList = {"12/31", "01/01", "01/02", "01/03", "01/04", "01/05"};
    //     // beijing.typeList = {"晴", "晴", "多云", "晴", "多云", "⼩⾬"};
    //     // beijing.qualityList = {12, 45, 156, 88, 23, 9};
    //     // beijing.highTemp = {2, 6, 12, 8, 5, 10};
    //     // beijing.lowTemp = {-5, -9, -6, -12, -5, -1};
    //     // beijing.fx = {"北⻛", "北⻛", "西北⻛", "西北⻛", "西北⻛", "西北⻛"};
    //     // beijing.fl = {2, 1, 2, 2, 2, 2};

    //     WeatherInfo shanghai;
    //     shanghai.city = "上海";
    //     shanghai.dateWeek = "2024/03/26 星期二";
    //     shanghai.temp = 6;
    //     shanghai.ganMao = "极少数敏感人群应减少户外活动";
    //     shanghai.pm25 = 74;
    //     shanghai.humidity = 57;
    //     shanghai.quality = "良";
    //     shanghai.weekList = {"周⽇", "周⼀", "周⼆", "周三", "周四", "周五"};
    //     shanghai.dateList = {"12/31", "01/01", "01/02", "01/03", "01/04", "01/05"};
    //     shanghai.typeList = {"霾", "⼤暴⾬", "⼩雪", "晴", "晴", "晴"};
    //     shanghai.qualityList = {12, 65, 12, 23, 34, 155};
    //     shanghai.highTemp = {10, 15, 12, 8, 11, 14};
    //     shanghai.lowTemp = {5, 8, 4, 12, 6, 11};
    //     shanghai.fx = {"北⻛", "北⻛", "东北⻛", "西北⻛", "东南⻛", "北⻛"};
    //     shanghai.fl = {3, 2, 2, 3, 2, 2};

    //     WeatherInfo guangzhou;
    //     guangzhou.city = "⼴州";
    //     guangzhou.dateWeek = "2024/03/26 星期二";
    //     guangzhou.temp = 23;
    //     guangzhou.ganMao = "极少数敏感人群应减少户外活动";
    //     guangzhou.pm25 = 47;
    //     guangzhou.humidity = 77;
    //     guangzhou.quality = "良";
    //     guangzhou.weekList = {"周⽇", "周⼀", "周⼆", "周三", "周四", "周五"};
    //     guangzhou.dateList = {"12/31", "01/01", "01/02", "01/03", "01/04","01/05"};
    //     guangzhou.typeList = {"霾", "多云", "⼩⾬", "晴", "晴", "晴"};
    //     guangzhou.qualityList = {23, 78, 33, 45, 66, 155};
    //     guangzhou.highTemp = {25, 27, 21, 18, 24, 20};
    //     guangzhou.lowTemp = {14, 11, 18, 9, 12, 16};
    //     guangzhou.fx = {"北⻛", "东⻛", "南⻛", "北⻛", "东⻛", "东南⻛"};
    //     guangzhou.fl = {1, 2, 2, 3, 2, 1};

    //     weatherInfoList.append(chongqing);
    //     weatherInfoList.append(beijing);
    //     weatherInfoList.append(shanghai);
    //     weatherInfoList.append(guangzhou);


}

void Widget::updateUI()
{
    // cityIndex++;
    // if(cityIndex > 3)
    // {
    //     cityIndex = 0;
    // }

    // WeatherInfo info = weatherInfoList[cityIndex];

    // //更新日期
    // lbDate->setText(info.dateWeek);

    // //更新天气类型城市高低温
    // lbTypeIcon->setPixmap(mTypeMap[info.typeList[1]]);
    // lbTemp->setText(QString::number(info.temp) + "°");
    // lbCity->setText(info.city);
    // lbType->setText(info.typeList[1]);
    // lbLowHigh->setText(QString::number(info.lowTemp[1]) + "-" + QString::number(info.highTemp[1]) + "°");
    // lbGanMao->setText("感冒指数:" + info.ganMao);
    // lbFX->setText(info.fx[1]);
    // lbFL->setText(QString::number(info.fl[1]) + "级");
    // lbPM->setText(QString::number(info.pm25));
    // lbSD->setText(QString::number(info.humidity) + "%");
    // lbZL->setText(QString::number(info.qualityList[1]));

    // for(int i = 0;i < 6;++i)
    // {
    //     mWeekList[i]->setText(info.weekList[i]);
    //     mWeekList[0]->setText("昨天");
    //     mWeekList[1]->setText("今天");
    //     mWeekList[2]->setText("明天");

    //     mDateList[i]->setText(info.dateList[i]);
    //     //更新天气类型
    //     mTypeIconList[i]->setPixmap(mTypeMap[info.typeList[i]]);
    //     mTypeList[i]->setText(info.typeList[i]);

    //     // 3.3 更新空气质量
    //     if ( info.qualityList[i] >= 0 && info.qualityList[i] <= 50 ) {
    //         mAqiList[i]->setText("优");
    //         mAqiList[i]->setStyleSheet("background-color: rgb(121, 184, 0);");
    //     } else if ( info.qualityList[i] >= 50 && info.qualityList[i] <= 100 ) {
    //         mAqiList[i]->setText("良");
    //         mAqiList[i]->setStyleSheet("background-color: rgb(255, 187, 23);");
    //     } else if ( info.qualityList[i] >= 100 && info.qualityList[i] <= 150 )
    //     {
    //         mAqiList[i]->setText("轻度");
    //         mAqiList[i]->setStyleSheet("background-color: rgb(255, 87, 97);");
    //     } else if ( info.qualityList[i] >= 150 && info.qualityList[i] <= 200 )
    //     {
    //         mAqiList[i]->setText("中度");
    //         mAqiList[i]->setStyleSheet("background-color: rgb(235, 17, 27);");
    //     } else if ( info.qualityList[i] >= 200 && info.qualityList[i] <= 300 )
    //     {
    //         mAqiList[i]->setText("重度");
    //         mAqiList[i]->setStyleSheet("background-color: rgb(170, 0, 0);");
    //     } else {
    //         mAqiList[i]->setText("严重");
    //         mAqiList[i]->setStyleSheet("background-color: rgb(110, 0, 0);");
    //     }

    //     mFxList[i]->setText(info.fx[i]);
    //     mFlList[i]->setText(QString::number(info.fl[i]) + "级");
    // }

    //更新日期城市
    lbDate->setText(QDateTime::fromString(mToday.date,"yyyMMdd").toString("yyyy/MM/dd") + " " + mDay[1].week);
    lbTypeIcon->setPixmap(mTypeMap[mToday.type]);
    lbTemp->setText(QString::number(mToday.wendu) + "°");
    lbCity->setText(mToday.city);
    lbType->setText(mToday.type);
    lbLowHigh->setText(QString::number(mToday.high) + "-" + QString::number(mToday.low) + "°");
    lbGanMao->setText("感冒指数:" + mToday.ganmao);
    lbFX->setText(mToday.fx);
    lbFL->setText(mToday.fl + "级");
    lbPM->setText(QString::number(mToday.pm25));
    lbSD->setText(mToday.shidu + "%");
    lbZL->setText(mToday.quality);

    for(int i = 0;i < 6;++i)
    {
        mWeekList[i]->setText("周" + mDay[i].week.right(1));
        mWeekList[0]->setText("昨天");
        mWeekList[1]->setText("今天");
        mWeekList[2]->setText("明天");

        QStringList ymdList = mDay[i].date.split("-");
        mDateList[i]->setText(ymdList[1] + "/" + ymdList[2]);
        //更新天气类型
        mTypeIconList[i]->setPixmap(mTypeMap[mDay[i].type]);
        mTypeList[i]->setText(mDay[i].type);

        // 3.3 更新空气质量
        if ( mDay[i].aqi >= 0 && mDay[i].aqi <= 50 ) {
            mAqiList[i]->setText("优");
            mAqiList[i]->setStyleSheet("background-color: rgb(121, 184, 0);");
        } else if ( mDay[i].aqi > 50 && mDay[i].aqi <= 100 ) {
            mAqiList[i]->setText("良");
            mAqiList[i]->setStyleSheet("background-color: rgb(255, 187, 23);");
        } else if ( mDay[i].aqi > 100 && mDay[i].aqi <= 150 ) {
            mAqiList[i]->setText("轻度");
            mAqiList[i]->setStyleSheet("background-color: rgb(255, 87, 97);");
        } else if ( mDay[i].aqi > 150 && mDay[i].aqi <= 200 ) {
            mAqiList[i]->setText("中度");
            mAqiList[i]->setStyleSheet("background-color: rgb(235, 17, 27);");
        } else if ( mDay[i].aqi > 200 && mDay[i].aqi <= 300 ) {
            mAqiList[i]->setText("重度");
            mAqiList[i]->setStyleSheet("background-color: rgb(170, 0, 0);");
        } else {
            mAqiList[i]->setText("严重");
            mAqiList[i]->setStyleSheet("background-color: rgb(110, 0, 0);");
        }

        mFxList[i]->setText(mDay[i].fx);
        mFlList[i]->setText(mDay[i].fl);
    }


    lbHigh->update();
    lbLow->update();
}

void Widget::paintHighCurve()
{
    // WeatherInfo info = weatherInfoList[cityIndex];
    QPainter painter(lbHigh);//画家在标签lbHigh上作画

    //抗锯齿
    painter.setRenderHint(QPainter::Antialiasing,true);

    //x轴坐标
    int pointX[6] = {0};
    for(int i = 0;i != 6;++i)
    {
        pointX[i] = mAqiList[i]->pos().x() + mAqiList[i]->width() / 2;
    }
    //y轴坐标
    int tempSum = 0;
    int tempAvg = 0;

    for(int i =0;i != 6;++i)
    {
        tempSum += mDay[i].high;
    }
    tempAvg = tempSum / 6;

    int pointY[6] = {0};
    for(int i = 0;i != 6;++i)
    {
        pointY[i] = lbHigh->height() / 2 - ((mDay[i].high  - tempAvg) * INCREMENT);
    }

    //绘制
    QPen pen = painter.pen();
    pen.setWidth(1);
    pen.setColor(QColor(255,170,0));
    painter.save();

    painter.setPen(pen);
    painter.setBrush(QColor(255,170,0));

    //画点写文本
    for(int i = 0;i != 6;++i)
    {
        painter.drawEllipse(QPoint(pointX[i],pointY[i]),POINT_RADIUS,POINT_RADIUS);
        painter.drawText(QPoint(pointX[i] - TEXT_OFFSET_X,pointY[i] - TEXT_OFFSET_Y),QString::number(mDay[i].high) + "°");
    }

    for(int i = 0;i != 5;++i)
    {
        if(i == 0)
        {
            pen.setStyle(Qt::DotLine);
            painter.setPen(pen);
        }
        else
        {
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);
        }
        painter.drawLine(pointX[i],pointY[i],pointX[i+1],pointY[i+1]);
    }
    painter.restore();
}

void Widget::paintLowCurve()
{
    WeatherInfo info = weatherInfoList[cityIndex];
    QPainter painter(lbLow);//画家在标签lbHigh上作画

    //抗锯齿
    painter.setRenderHint(QPainter::Antialiasing,true);

    //x轴坐标
    int pointX[6] = {0};
    for(int i = 0;i != 6;++i)
    {
        pointX[i] = mAqiList[i]->pos().x() + mAqiList[i]->width() / 2;
    }
    //y轴坐标
    int tempSum = 0;
    int tempAvg = 0;

    for(int i =0;i != 6;++i)
    {
        tempSum += info.highTemp[i];
    }
    tempAvg = tempSum / 6;

    int pointY[6] = {0};
    for(int i = 0;i != 6;++i)
    {
        pointY[i] = lbLow->height() / 2 - ((info.lowTemp[i] - tempAvg) * INCREMENT);
    }

    //绘制
    QPen pen = painter.pen();
    pen.setWidth(1);
    pen.setColor(QColor(255,170,0));
    painter.save();

    painter.setPen(pen);
    painter.setBrush(QColor(255,170,0));

    //画点写文本
    for(int i = 0;i != 6;++i)
    {
        painter.drawEllipse(QPoint(pointX[i],pointY[i]),POINT_RADIUS,POINT_RADIUS);
        painter.drawText(QPoint(pointX[i] - TEXT_OFFSET_X,pointY[i] - TEXT_OFFSET_Y),QString::number(info.highTemp[i]) + "°");
    }

    for(int i = 0;i != 5;++i)
    {
        if(i == 0)
        {
            pen.setStyle(Qt::DotLine);
            painter.setPen(pen);
        }
        else
        {
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);
        }
        painter.drawLine(pointX[i],pointY[i],pointX[i+1],pointY[i+1]);
    }
}

void Widget::parseJson(QByteArray &byteArrary)
{
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(byteArrary,&err);
    if(err.error != QJsonParseError::NoError)
    {
        qDebug("%s(%d):%s",__FUNCTION__,__LINE__,err.errorString().toLatin1().data());
        return;
    }

    QJsonObject rootObj = doc.object();
    // qDebug() << rootObj.value("message").toString();
    if(!rootObj.value("message").toString().contains("success"))
    {
        QMessageBox::warning(this,"天气","请求数据失败",QMessageBox::Ok);
        return;
    }

    //解析城市和日期
    mToday.date = rootObj.value("date").toString();
    mToday.city = rootObj.value("cityInfo").toObject().value("city").toString();

    //解析昨天
    QJsonObject objYesterday = rootObj.value("data").toObject().value("yesterday").toObject();
    mDay[0].week = objYesterday.value("week").toString();
    mDay[0].date = objYesterday.value("ymd").toString();
    mDay[0].type = objYesterday.value("type").toString();

    QString s;
    s = objYesterday.value("high").toString().split(" ").at(1);
    mDay[0].high = s.left(s.length() - 1).toInt();
    s = objYesterday.value("low").toString().split(" ").at(1);
    mDay[0].low = s.left(s.length() - 1).toInt();

    mDay[0].fx = objYesterday.value("fx").toString();
    mDay[0].fl = objYesterday.value("fl").toString();
    mDay[0].aqi = objYesterday.value("aqi").toDouble();

    //解析未来五天
    QJsonArray forecastArr = rootObj.value("data").toObject().value("forecast").toArray();
    for(int i =0;i != 5;++i)
    {
        QJsonObject objForecast = forecastArr[i].toObject();
        mDay[i+1].week = objForecast.value("week").toString();
        mDay[i+1].date = objForecast.value("ymd").toString();
        mDay[i+1].type = objForecast.value("type").toString();

        QString s;
        s = objForecast.value("high").toString().split(" ").at(1);
        mDay[i+1].high = s.left(s.length() - 1).toInt();
        s = objForecast.value("low").toString().split(" ").at(1);
        mDay[i+1].low = s.left(s.length() - 1).toInt();

        mDay[i+1].fx = objForecast.value("fx").toString();
        mDay[i+1].fl = objForecast.value("fl").toString();
        mDay[i+1].aqi = objForecast.value("aqi").toDouble();
    }

    //解析今天
    mToday.ganmao = rootObj.value("data").toObject().value("ganmao").toString();
    mToday.wendu = rootObj.value("data").toObject().value("wendu").toInt();
    mToday.shidu = rootObj.value("data").toObject().value("shidu").toString();
    mToday.pm25 = rootObj.value("data").toObject().value("pm25").toInt();
    mToday.quality = rootObj.value("data").toObject().value("quality").toString();

    mToday.type = mDay[1].type;
    mToday.fx = mDay[1].fx;
    mToday.fl = mDay[1].fl;
    mToday.high = mDay[1].high;
    mToday.low = mDay[1].low;

    //更新ui
    updateUI();

}

void Widget::onReplied(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NoError || reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() != 200)
    {
        QMessageBox::warning(this,"天气","数据请求失败！",QMessageBox::Ok);

    }
    else
    {
        QByteArray byteArray = reply->readAll();
        qDebug() << byteArray.data();
        parseJson(byteArray);
    }
    reply->deleteLater();
}

