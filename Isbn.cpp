#include "Isbn.hpp"
#include <iostream>

Isbn::Isbn(int a = 0, int b = 0, int c = 0, char d = '0'){
    if(validate(a,b,c,toupper(d)))
       n1 = a, n2 = b, n3 = c, x = toupper(d); 
    else throw Invalid{};
}

int Isbn::getN1() { return n1; }
int Isbn::getN2() { return n2; }
int Isbn::getN3() { return n3; }
char Isbn::getX() { return x; }

void Isbn::setN1(int a) {
    if(validate(a,n2,n3,x))
        n1 = a;
    else throw Invalid{};
}
void Isbn::setN2(int b) {
    if(validate(n1,b,n3,x))
        n2 = b;
    else throw Invalid{};
}
void Isbn::setN3(int c) {
    if(validate(n1,n2,c,x))
        n3 = c;
    else throw Invalid{};
}
void Isbn::setX(char d) {
    if(validate(n1,n2,n3,toupper(d)))
        x = toupper(d);
    else throw Invalid{};
}

std::ostream& Isbn::operator<<(std::ostream& os){
    return os<<this->n1<<"-"<<this->n2<<"-"<<this->n3<<"-"<<this->x;
}

bool Isbn::operator==(Isbn a){
    return (this->n1==a.n1 && this->n2==a.n2 && this->n3==a.n3 && this->x==a.x);
}

bool Isbn::validate(int a, int b, int c, char d){
    if(a<0 || b<0 || c<0)
        return false;
    if((d<'0' || d>'9') && (d<'A' || d>'Z'))
        return false;
    return true;
}