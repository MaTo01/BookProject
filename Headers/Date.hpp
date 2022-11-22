#ifndef DATE_HPP
#define DATE_HPP
#include <iostream>

class Date{
public:
    /* enumeratore per gestire i mesi */
    enum Month{
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };
    class Invalid{};

    /* Costruttori */
    Date() : day{1}, month{jan}, year{MIN_YEAR}, defaultDate{true} {}
    Date(int, Month, int);

    int getDay() const {return day;}
    Month getMonth() const {return month;}
    int getYear() const {return year;}
    void setDay(int d);
    void setMonth(Month m);
    void setYear(int y);

    /* Funzione utilizzata per distinguere una data di default dalla data minima */
    bool isDefault();

private:
    int day;
    Month month;
    int year;
    /* flag per distinguere una data 01/01/1600 impostata di default da una impostata manualmente*/
    bool defaultDate;
    /* valore minimo accettato per l'anno */
    static constexpr int MIN_YEAR = 1600;
    
    /* Funzione per validare i valori di una data */
    bool validate(int, Month, int);
    /* Funzione per verificare se un anno è bisestile */
    bool isLeapYear(int);
};

std::ostream& operator<<(std::ostream& os, const Date& date);

#endif