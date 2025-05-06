#ifndef MYDATE_H__
#define MYDATE_H__

class mydate
{
    int year, month, day;

public:
    mydate(int _year, int _month, int _day);
    ~mydate();
    void print();
};

#endif