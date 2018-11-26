//date()构造函数 保证构造出一个正确的函数
//inPeriod(0):判断一个日期是否在两个日期内isLeap(); 判断该年是否为闰年

//Date date(2002， 1，22)://保证合法性， 如果没有初始化应为1980.1.1;
//bool flag  Date ->  isPeriod(Date (2005，1, 20)，Date(2008 ，10，20)): //判断是否在两个日期内
//bool flag2  Date ->  isLeap() ;
//Date date2 = date + 50:
//50是天的意思int days= date2 一date;, //返回相差的天数int day. int(date): //从1980年开始的天数



#include <cstring>
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;
class Date
{
    int day;
    int month;
    int year;
    Date(int _year = 1980, int _month = 1, int _day = 1):year(_year),month(_month),day(_day)
    {
        if (IsDateValid())
        {
            cout << "输入日期不合法" << endl;
            _year = 1980;
            _month = 1;
            _day = 1;
        }
    }



public:

    int DayofMonth(const int year, const int month )const
{
    int num;
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        num=31;
        break;
    case 2:
        num = 28+isLeap(year);
        break;
    default:
        num = 30;
    }
    return num;
}



int getYear() const {
    return this->year;
}

int getMonth() const{
    return this->month;
}

int getDay() const {
    return this->day;
}
int IsDateValid(int _year = 1980, int _month = 1, int _day = 1)
:year(_year),month(_month),day(_day)
{
    if ((_year<0) ||
        (_month<0 || _month>12) ||
        (_day<0 || _day>DayOfMonth(_year, _month)))
    {
        return true;
    }
    else
    {
        return false;
    }

}
//设置日期
void SetDate( Date & date)
{
    year = date.year;
    month = date.month ;
    day = date.day;
}

//是否闰年
int isLeap(int year)const
{
    return ((year%4==0) && (year%100!=0)||year%400==0);
}

    void operator =(Date & d1)
    {
        year=d1.year;
        month = d1.month;
        day = d1.day;
    }
    bool operator < (const Date & d1) const
    {
        if(year != d1.year)
        {
            return year < d1.year;
        }
        if(month != d1.month)
        {
            return month < d1.month;
        }
        return day< d1.day;
    }
    bool operator >= (const Date & d1) const{
        return !(*this < d1);
    }
    bool operator > (const Date & d1) const
    {
        return d1 < *this;
    }
    bool operator <= (const Date & d1) const
    {
        return !(*this > d1);
    }
    bool operator == (const Date & d1) const
    {
        return (!(*this > d1) )&&( !(*this < d1));
    }
    bool operator != (const Date & d1) const
    {
        return !(*this == d1);
    }



//计算两个日期的间隔天数


bool inperiod(const Date & date1, const Date & date2){
    if(this->year > date1.getYear()&&this->year < date2.getYear()){
        if(this->year==date1.getYear()){
            if(this->month>= date1.getMonth()) return true;
            else return this->day<=date2.getDay();
        }
        return true;
    }
    return false;
}
};





