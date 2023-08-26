#include <iostream>

class B; // 前向声明，用于让类 A 知道类 B 的存在

class A {
private:
    int dataA;

public:
    A(int d) : dataA(d) {}

    void display() {
        std::cout << "Data in A: " << dataA << std::endl;
    }

    // 将类 B 声明为友元类
    friend class B;
};

class B {
private:
    int dataB;

public:
    B(int d) : dataB(d) {}

    void display() {
        std::cout << "Data in B: " << dataB << std::endl;
    }

    // 类 B 可以访问类 A 的私有成员
    void showDataFromA(A& a) {
        std::cout << "Data in A from B: " << a.dataA << std::endl;
    }
};

int main() {
    A objA(10);
    B objB(20);

    objA.display();
    objB.display();

    // 调用类 B 的成员函数，让类 B 访问类 A 的私有成员
    objB.showDataFromA(objA);

    return 0;
}
