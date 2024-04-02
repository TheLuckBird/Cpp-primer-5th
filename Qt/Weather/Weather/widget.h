#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMenu>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <weatherdata.h>

struct WeatherInfo
{
    QString city;
    QString dateWeek;
    qint8 temp;

    QString ganMao;
    qint8 pm25;
    qint8 humidity;
    QString quality;

    QList<QString> weekList;
    QList<QString> dateList;
    QList<QString> typeList;
    QList<qint16> qualityList;
    QList<qint8> highTemp;
    QList<qint8> lowTemp;
    QList<QString> fx;
    QList<qint8> fl;
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void contextMenuEvent(QContextMenuEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    //事件过滤器：过滤带标签的update事件
    bool eventFilter(QObject *watched,QEvent *event);
    void getWeatherInfo(QString cityCode);


private:

    QMenu *mExitMenu;//右键退出的菜单
    QAction *mExitAct;//推出的行为

    QPoint mOffset;

    //布局
    //主体
    QVBoxLayout *mainLayout;
    //顶部
    QHBoxLayout *topLayout;
    QLabel *lbDate;
    //底部
    QVBoxLayout *leftLayout,*rightLayout;
    //--左侧
    QLabel *lbTypeIcon;//天气图标
    QLabel *lbTemp;//温度
    QLabel *lbCity;//城市
    QLabel *lbType;//天气
    QLabel *lbLowHigh;//高低温

    QLabel *lbGanMao;//感冒指数

    QLabel *lbFLIcon;//风力图标
    QLabel *lbFX;//风向
    QLabel *lbFL;//风力

    QLabel *lbPm25Icon;//PM2.5图标
    QLabel *lbPmTitle;//PM2.5标题
    QLabel *lbPM;//PM2.5数值

    QLabel *lbSDIcon;//湿度图标
    QLabel *lbSDTitle;//湿度标题
    QLabel *lbSD;//湿度数值

    QLabel *lbZLIcon;//空气质量图标
    QLabel *lbZLTitle;//空气质量图标
    QLabel *lbZL;//空气质量数值
    //--右侧
    QList<QLabel*> mWeekList;//星期
    QList<QLabel*> mDateList;//日期

    QList<QLabel*> mTypeIconList;//天气图标
    QList<QLabel*> mTypeList;//天气
    QMap<QString,QString> mTypeMap;//天气类型map

    QList<QLabel*> mAqiList;//天气指数

    QLabel *lbLow;//低温
    QLabel *lbHigh;//高温

    QList<QLabel*> mFxList;//风向
    QList<QLabel*> mFlList;//风力

    QList<WeatherInfo> weatherInfoList;
    qint8 cityIndex;

    QNetworkAccessManager *manager;

    Today mToday;
    Day mDay[6];

private:
    void initTop();
    void initLeft();
    void initRight();
    void initData();
    void updateUI();
    void paintHighCurve();
    void paintLowCurve();
    void parseJson(QByteArray &byteArrary);

private slots:
    void onReplied(QNetworkReply *reply);


};
#endif // WIDGET_H
