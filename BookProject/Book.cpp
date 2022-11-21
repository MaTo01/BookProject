#include "Book.hpp"
#include <iostream>

Book::Book(const std::string& n, const std::string& c, const std::string& t, const std::string& i/*,const Date& d*/) : 
    nome {n}, cognome {c}, titolo{t}, isbn{Isbn(i)}/*, data{d}*/, disponibile{true} {}


/*
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
*/

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

/*
bool Book::isDisponibile(){ 
    return disponibile;
}
*/
  
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

std::ostream& operator<<(std::ostream& os, const Book &book) {
   os << "TITOLO: " << book.getTitolo() << "\n"
   << "AUTORE: " << book.getNome() << " " << book.getCognome() << "\n"
   << "ISBN: " << book.getIsbn() << "\n"
   << "DATA DI COPYRIGHT: " << book.getData() << "\n"
   << "DISPONIBILE: " << book.isDisponibile();  
   return os;
}