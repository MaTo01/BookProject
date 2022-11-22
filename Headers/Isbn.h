#ifndef ISBN_H
#define ISBN_H
#include <iostream>
#include <vector>

class Isbn {
private:
    std::string n1, n2, n3;
    char x;
    
    /* Funzioni che verificano che i parametri passati siano conformi al formato richiesto */
    bool validate(std::string, std::string, std::string, char);
    bool validateString(std::string);
    bool validateChar(char);
    /* Funzione generale per dividere una stringa in sottostringhe secondo un delimitatore */
    std::vector<std::string> splitString(std::string, char);

public:

    /* Costruttori */
    Isbn() : n1{"0"}, n2{"0"}, n3{"0"}, x{'0'} {}
    Isbn(std::string, std::string, std::string, char);
    Isbn(std::string);

    std::string getN1() const {return n1;}
    std::string getN2() const {return n2;}
    std::string getN3() const {return n3;}
    char getX() const {return x;}

    void setN1(std::string);
    void setN2(std::string);
    void setN3(std::string);
    void setX(char);
    
    class Invalid{};
};

/* Output to stream */
std::ostream& operator<<(std::ostream& os, const Isbn& isbn);

/* Operatore di confronto*/
bool operator==(const Isbn& isbn1, const Isbn& isbn2);

#endif
