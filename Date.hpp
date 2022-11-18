#ifndef DATE_HPP
#define DATE_HPP
#include <iostream>

class Date{    
public:

    enum Month{
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };
    class Invalid{};

    Date() : day{1}, month{jan}, year{1600} {}
    Date(int, Month, int);
    int getDay();
    Month getMonth();
    int getYear();
    void setDay(int d);
    void setMonth(Month m);
    void setYear(int y);

private:
    int day;
    Month month;
    int year;
    
    bool validate(int, Month, int);
    bool isLeapYear(int);
};

#endif