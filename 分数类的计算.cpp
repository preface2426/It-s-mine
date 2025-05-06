#include <iostream>
#include <cmath> // 用于 abs 函数
using namespace std;

class fraction {
public:
    // 构造函数，要求分子默认为0，分母默认为1
    fraction(int num=0, int den=1)
        : numerator(num), denominator(den),sign(1) {
    }

    // 约分函数
    void reduction() {
        if (denominator < 0) {
            denominator = -denominator;
            sign *= -1;
        }
        if (numerator < 0) {
            numerator = -numerator;
            sign *= -1;
        }
        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
    }

    // 通分函数
    void make_common_denominator(fraction &f) {
        int pubmin = (denominator * f.denominator) / gcd(denominator, f.denominator);
        numerator *= (pubmin / denominator);
        f.numerator *= (pubmin / f.denominator);
        denominator = pubmin;
        f.denominator = pubmin;
    }

    // 输出特定格式的分数
    void print() {
        reduction();
        std::cout << '(' << sign*numerator << '/' << denominator << ')';
    }

    // 加法函数
    fraction add(fraction &f)  {
        fraction result(*this); 
        result.make_common_denominator(f); 
        result.numerator += f.numerator; 
        
        result.reduction(); 
        return result;
    }

private:
    int numerator;        // 分子
    int denominator;        //分母
    int sign;

    // 最大公约数函数
    static int gcd(int x, int y) {
        while (y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }
};

int main() {
    // main函数的代码不需要更动
    int numerator1{}, denominator1{}, numerator2{}, denominator2{}; // 两个有理数各自的分子和分母
    std::cin >> numerator1 >> denominator1 >> numerator2 >> denominator2;
    fraction f1{numerator1, denominator1}, f2{numerator2, denominator2};
    fraction f3 = f1.add(f2); // 注意这里使用等号赋值
    f1.print();
    std::cout << " + ";
    f2.print();
    std::cout << " = ";
    f3.print();
    std::cout << std::endl;
}