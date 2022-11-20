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
    Book(std::string, std::string, std::string, std::string, Date d = Date());
    class Invalid{};

    Isbn getIsbn();
    std::string getTitolo();
    std::string getNome();
    std::string getCognome();
    Date getData();

    void setIsbn(Isbn);
    void setTitolo(std::string);
    void setNome(std::string);
    void setCognome(std::string);
    void setData(Date);
    
    bool isDisponibile(); /*gestisce lo stato del libro: */
    void presta();
    void restituisci();
    
    bool operator==(Book); //confronta due libri basandosi sul codice ISBN
    bool operator!=(Book);
    std::ostream& operator<<(std::ostream&); //stampa titolo, autore, ISBN e la data di copyright su righe separate in output

};

#endif
