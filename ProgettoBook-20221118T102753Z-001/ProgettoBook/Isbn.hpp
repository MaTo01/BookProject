#ifndef ISBN_HPP
#define ISBN_HPP
#include <iostream>

class Isbn {
private:
    int n1, n2, n3;
    char x;
    
    bool validate(int, int, int, char);

public:
    class Invalid{};

    Isbn() : n1{0}, n2{0}, n3{0}, x{'0'} {}
    Isbn(int, int, int, char);
    int getN1();
    int getN2();
    int getN3();
    char getX();
    void setN1(int);
    void setN2(int);
    void setN3(int);
    void setX(char);

    std::ostream& operator<<(std::ostream&);
    bool operator==(Isbn);
};

#endif