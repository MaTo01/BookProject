#include "Date.hpp"
#include <iostream>

Date::Date(int d, Month m, int y){
    if(validate(d, m, y))
        day = d, month = m, year = y;
    else throw Invalid{};
}

bool Date::validate(int d, Month m, int y){
    if(y<MIN_YEAR && d<1)
        return false;
        
    switch (m){
        case Month::feb:
            if(isLeapYear(y))
                if(day>29) return false;
            else 
                if(day>28) return false;
        case Month::apr:
        case Month::jun:
        case Month::sep:
        case Month::nov:
            if(day>30) return false;
        default:
            if(day>31) return false;
    }
    return true;
}

bool Date::isLeapYear(int y){
    if(y%4 != 0)
        return false;
    if(y%100==0 && y%400!=0)
        return false;
    return true;
}

/*
int Date::getDay(){
    return day;
}
Date::Month Date::getMonth(){
    return month;
}
int Date::getYear(){
    return year;
}
*/
void Date::setDay(int d){
    if(validate(d, month, year))
        day = d;
    else throw Invalid{};
}
void Date::setMonth(Month m){
    if(validate(day, m, year))
        month = m;
    else throw Invalid{};
}
void Date::setYear(int y){
    if(validate(day, month, y))
        year = y;
    else throw Invalid{};
}
std::ostream& operator<<(std::ostream& os, const Date& date){

    return os<<date.getDay()<<"/"<<date.getMonth()<<"/"<<date.getYear();

}