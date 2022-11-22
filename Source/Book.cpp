#include "Book.hpp"
#include <iostream>

Book::Book(const std::string& n, const std::string& c, const std::string& t, const std::string& i, const Date& d) : 
    nome {n}, cognome {c}, titolo{t}, isbn{Isbn(i)}, data{d}, disponibile{true} {}

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
void Book::setDisponibile(bool d){
    disponibile = d;
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
bool operator==(const Book& book1, const Book& book2) { 
    return book1.getIsbn() == book2.getIsbn();
}

bool operator!=(const Book& book1, const Book& book2) {
    return !(book1.getIsbn() == book2.getIsbn());
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "TITOLO: " << book.getTitolo() << "\n"
    << "AUTORE: " << book.getNome() << " " << book.getCognome() << "\n"
    << "ISBN: " << book.getIsbn() << "\n"
    << "DATA DI COPYRIGHT: ";
    if(book.getData().isDefault())
        os << "non disponibile";
    else
        os << book.getData();
    os << "\nDISPONIBILE: " << ((book.isDisponibile())?"SI":"NO");  
    return os;
}
