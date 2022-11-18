#include "Book.hpp"
#include <iostream>
/*
bool Book::operator==(Book b){
    return (this->isbn == b.getIsbn());
}

std::ostream& Book::operator<<(std::ostream& os){
    return os<<this->isbn;
}*/

Book::Book(std::string n, std::string c, std::string t, Isbn i) : 
    nome {n}, cognome {c}, titolo{t}, isbn{i} {}

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

bool Book::isDisponibile(){ /*gestisce lo stato del libro: */
    return disponibile;
}
void Book::presta(){
    if(isDisponibile){
        disponibile = false;
    }
}
void restituisci(){
    if(!isDisponibile){
        disponibile = true;
    }
}

//confronta due libri basandosi sul codice ISBN
bool operator==(Book){ 
    
}
bool operator!=(Book);
std::ostream& operator<<(std::ostream&);