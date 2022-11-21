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
    Book() : nome{""}, cognome{""}, titolo{""}, isbn{Isbn()}/*, data{Date()}*/ {}
    Book(const std::string& n, const std::string& c, const std::string& t, const std::string& i/*, const Date& d*/);
    class Invalid{};

    Isbn getIsbn(void) const {return isbn;}
    std::string getTitolo(void) const {return titolo;}
    std::string getNome(void) const {return nome;}
    std::string getCognome(void) const {return cognome;}
    Date getData(void) const {return data;}

    void setIsbn(const Isbn);
    void setTitolo(const std::string);
    void setNome(const std::string);
    void setCognome(const std::string);
    void setData(const Date);
    
    bool isDisponibile(void) const {return disponibile;}/*gestisce lo stato del libro: */
    void presta();
    void restituisci();
    
    //bool operator==(Book); //confronta due libri basandosi sul codice ISBN
    //bool operator!=(Book);
    //std::ostream& operator<<(std::ostream&, Book&); //stampa titolo, autore, ISBN e la data di copyright su righe separate in output
    
    bool operator==(Isbn&);
    bool operator!=(Isbn&);

};

std::ostream& operator<<(std::ostream& os, const Book& book);

#endif