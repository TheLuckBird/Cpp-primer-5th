class Y; // 前向声明 Y 类

class X {
    Y *y;
};

class Y {
    X x;
};

int main(int argc, char const *argv[])
{
    X x;
    Y y;
    return 0;
}
