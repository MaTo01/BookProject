#ifndef BOOK_HPP
#define BOOK_HPP
#include "Date.hpp"
#include "Isbn.hpp"
#include <iostream>

class Book {
private:
        
    Isbn isbn;  
    std::string titolo;
    std::string nome;
    std::string cognome;
    Date data;
    bool disponibile = true;       
    
public:
    /*Costruttore di default della classe Book che sfrutta la init list
    NOTA: non e' necessario il controllo degli argomenti del costruttore, gia' effettuato all'interno delle classi
    Isnb e Date; ogni Book creato e' reso disponibile*/
    Book() : nome{""}, cognome{""}, titolo{""}, isbn{Isbn()}, data{Date()} {}
    Book(const std::string& n, const std::string& c, const std::string& t, const std::string& i, const Date& d = Date());
    class Invalid{};

    Isbn getIsbn(void) const {return isbn;}
    std::string getTitolo(void) const {return titolo;}
    std::string getNome(void) const {return nome;}
    std::string getCognome(void) const {return cognome;}
    Date getData(void) const {return data;}

    void setIsbn(Isbn);
    void setTitolo(std::string);
    void setNome(std::string);
    void setCognome(std::string);
    void setData(Date);
    
    bool isDisponibile() const {return disponibile;} /*gestisce lo stato del libro: */
    void presta();
    void restituisci();
};

bool operator==(const Book& book1, const Book& book2);
bool operator!=(const Book& book1, const Book& book2);
std::ostream& operator<<(std::ostream& os, const Book& book); //stampa titolo, autore, ISBN e la data di copyright su righe separate in output

#endif
