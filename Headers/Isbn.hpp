#ifndef ISBN_HPP
#define ISBN_HPP
#include <iostream>
#include <vector>

class Isbn {
private:
    std::string n1, n2, n3;
    char x;
    
    bool validate(std::string, std::string, std::string, char);
    bool validateString(std::string);
    bool validateChar(char);
    std::vector<std::string> splitString(std::string, char);

public:
    class Invalid{};

    Isbn() : n1{0}, n2{0}, n3{0}, x{'0'} {}
    Isbn(std::string, std::string, std::string, char);
    Isbn(std::string);
    std::string getN1();
    std::string getN2();
    std::string getN3();
    char getX();
    void setN1(std::string);
    void setN2(std::string);
    void setN3(std::string);
    void setX(char);

    std::ostream& operator<<(std::ostream&);
    bool operator==(Isbn);
    //TODO: == con std::string?
};

#endif