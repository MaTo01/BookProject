#include "Book.hpp"
#include <iostream>

Book::Book(std::string n, std::string c, std::string t, std::string i/*, Date d*/) : 
    nome {n}, cognome {c}, titolo{t}, isbn{Isbn(i)}/*, data{d}*/, disponibile{true} {}


Isbn Book::getIsbn(){
    return isbn;
}
std::string Book::getTitolo(){
    return titolo;
}
std::string Book::getNome(){
    return nome;
}
std::string Book::getCognome(){
    return cognome;
}
Date Book::getData(){
    return data;
}


void Book::setIsbn(Isbn i){
    isbn = i;
}
void Book::setTitolo(std::string t){
    titolo = t;
}
void Book::setNome(std::string n){
    nome = n;
}
void Book::setCognome(std::string c){
    cognome = c;
}
void Book::setData(Date d){
    data = d;
}


bool Book::isDisponibile(){ 
    return disponibile;
}

void Book::presta(){
    if(disponibile){
        disponibile = false;
    }
}
void Book::restituisci(){
    if(!disponibile){
        disponibile = true;
    }
}

//confronta due libri basandosi sul codice ISBN
bool Book::operator==(Isbn& book) { 
    Book b = *this;
    if(b.getIsbn() == book) {return true;}
    else {return false;} 
}

bool Book::operator!=(Isbn& book) {
    Book b = *this;
    if( b.getIsbn() != book) {return true;}
    else {return false;}
}

std::ostream& Book::operator<<(std::ostream& os) {
   os << "TITOLO: " << this->getTitolo() << "\n"
   << "AUTORE: " << this->getNome() << " " << this->getCognome() << "\n"
   /*<< "ISBN: " << this->getIsbn() << "\n*/
   /*<< "DATA DI COPYRIGHT: " << this->getData() << "\n"*/
   << "DISPONIBILE: " << this->isDisponibile();  
   return os;
}
