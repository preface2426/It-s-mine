#include <iostream>
using namespace std;

class MyDate
{
    int year, month, day;

public:
    // 定义三参数的默认构造函数，检查参数是否合法
    MyDate(int y = 2000, int m = 1, int d = 1)
        : year(y), month(m), day(d)
    {
        if (m < 1 || m > 12 || d < 1 || d > GetDaysInMonth(y, m))
        {
            year = 2000;
            month = 1;
            day = 1;
        }
    }

    // 重载 < 号，比较两个日期的早晚
    bool operator<(const MyDate &date2) const
    {
        if (year != date2.year)
            return year < date2.year;
        if (month != date2.month)
            return month < date2.month;
        return day < date2.day;
    }

    // 重载 + 号，日期对象 + 整数
    MyDate operator+(int days) const
    {
        int totalDays = DaysSince2000() + days; // 计算从2000年1月1日到当前日期的总天数，加上额外天数
        return FromDaysSince2000(totalDays);    // 将总天数转换回日期
    }

    // 重载 - 号，计算两个日期之间的天数差
    int operator-(const MyDate &date2) const
    {
        return DaysSince2000() - date2.DaysSince2000(); // 计算两个日期相对于2000年1月1日的天数差
    }

    // 定义输出函数，输出类的相关信息
    void print() const
    {
        cout << year << "-" << month << "-" << day << endl;
    }

private:
    // 获取某年某月的天数
    int GetDaysInMonth(int y, int m) const
    {
        int daysOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (m == 2 && IsLeapYear(y))
            return 29;
        return daysOfMonth[m - 1];
    }

    // 判断是否为闰年
    bool IsLeapYear(int y) const
    {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    // 计算从2000年1月1日到当前日期的总天数
    int DaysSince2000() const
    {
        int days = 0;
        for (int y = 2000; y < year; y++)
            days += IsLeapYear(y) ? 366 : 365;
        for (int m = 1; m < month; m++)
            days += GetDaysInMonth(year, m);
        days += day - 1;
        return days;
    }

    // 从总天数转换回日期
    MyDate FromDaysSince2000(int days) const
    {
        int year = 2000;
        while (days >= (IsLeapYear(year) ? 366 : 365))
        {
            days -= IsLeapYear(year) ? 366 : 365;
            year++;
        }
        int month = 1;
        while (days >= GetDaysInMonth(year, month))
        {
            days -= GetDaysInMonth(year, month);
            month++;
        }
        int day = days + 1;
        return MyDate(year, month, day);
    }
};

int main()
{
    int y1{}, m1{}, d1{}, y2{}, m2{}, d2{};
    int interval{};
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2 >> interval;

    MyDate date1{y1, m1, d1}, date2{y2, m2, d2};

    date1.print();
    date2.print();

    cout << (date1 < date2 ? "YES\n" : "NO\n");

    cout << date1 - date2 << '\n';

    (date1 + interval).print();

    return 0;
}