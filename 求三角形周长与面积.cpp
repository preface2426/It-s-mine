#include <iostream>
#include <cmath>
using namespace std;

class Triangle
{
    double a, b, c;
    int type;
    double P;

public:
    // 定义三参数构造函数，分别给三边赋值，并调用后续函数计算出三角形的类型
    Triangle(double A, double B, double C)
        : a(A), b(B), c(C), type(0)
    {
        // 判断是否能构成三角形
        if (A + B > C && B + C > A && A + C > B)
        {
            judgement();
        }
    }

    // 分别定义求解周长和面积的两个函数
    double C()
    {
        return a + b + c;
    }

    double S()
    {
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    // 定义求解类型的函数
    void judgement()
    {
        if (abs(a - b) < 1e-10 && abs(b - c) < 1e-10)
        {
            type = 1; // 等边三角形
        }
        else if ((abs(a - b) < 1e-10 && abs(a * a + b * b - c * c) < 1e-10) ||
                 (abs(b - c) < 1e-10 && abs(b * b + c * c - a * a) < 1e-10) ||
                 (abs(a - c) < 1e-10 && abs(a * a + c * c - b * b) < 1e-10))
        {
            type = 2; // 等腰直角三角形
        }
        else if ((abs(a - b) < 1e-10 && abs(a - c) > 1e-10) ||
                 (abs(b - c) < 1e-10 && abs(b - a) > 1e-10) ||
                 (abs(a - c) < 1e-10 && abs(a - b) > 1e-10))
        {
            type = 3; // 普通等腰三角形
        }
        else if ((abs(a * a + b * b - c * c) < 1e-10) ||
                 (abs(b * b + c * c - a * a) < 1e-10) ||
                 (abs(a * a + c * c - b * b) < 1e-10))
        {
            type = 4; // 普通直角三角形
        }
        else
        {
            type = 5; // 其它三角形
        }
    }

    // 用成员函数的方式重载 < 号，比较两个三角形的面积
    bool operator<(Triangle &t2) 
    {
        return S() < t2.S();
    }

    // 用友元函数的方式重载 > 号，比较两个三角形的面积
    friend bool operator>(Triangle &t1,Triangle &t2);

    // 定义打印函数，输出类的相关信息
    void print()
    {
        cout << a << " " << b << " " << c << " " << C() << " " << S() << " " << type << endl;
    }
};

bool operator>(Triangle &t1, Triangle &t2)
{
    return t1.S() > t2.S();
}

int main()
{
    double a1{}, b1{}, c1{}, a2{}, b2{}, c2{};
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    Triangle t1{a1, b1, c1}, t2{a2, b2, c2};
    t1.print();
    t2.print();
    cout << (t1 < t2 ? "YES\n" : "NO\n");
    cout << (t1 > t2 ? "YES\n" : "NO\n");
}