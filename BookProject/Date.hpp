#ifndef DATE_HPP
#define DATE_HPP
#include <iostream>

class Date{    
public:

    enum Month{
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };
    class Invalid{};

    Date() : day{1}, month{jan}, year{MIN_YEAR} {}
    Date(int, Month, int);
    int getDay(void) const {return day;}
    Month getMonth(void) const {return month;}
    int getYear(void) const {return year;}
    void setDay(int d);
    void setMonth(Month m);
    void setYear(int y);

private:
    int day;
    Month month;
    int year;
    static constexpr int MIN_YEAR = 1600;
    
    bool validate(int, Month, int);
    bool isLeapYear(int);
};

std::ostream& operator<<(std::ostream& os, const Date& date);

#endif