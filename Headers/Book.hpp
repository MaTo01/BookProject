#ifndef BOOK_HPP
#define BOOK_HPP
#include "Date.hpp"
#include "Isbn.hpp"
#include <iostream>

class Book {
private:
    
    std::string nome;
    std::string cognome;
    std::string titolo;
    Isbn isbn;
    Date data;
    bool disponibile = false;       
    
public:

     /* Due costruttori:
     *
     * - Default: viene inizializzato tutto ad un valore di default;
     *            le variabili di tipo string sono stringhe vuote,
     *            mentre le variabili UDT vengono inizializzate con il loro
     *            costruttore di default
     *
     * - cinque argomenti: si inizializza un libro con titolo, autore, isbn e data di copyright.
     *
     */
    Book() : nome{""}, cognome{""}, titolo{""}, isbn{Isbn()}, data{Date()} {}
    Book(const std::string& n, const std::string& c, const std::string& t, const std::string& i, const Date& d = Date());

    /* Funzioni membro:
     *
     * Accessors / get functions: Utilizziamo l'indentazione di tipo get<var name> 
     * 
     * Mutators / set functions: Compe per le get functions, scriviamo set<var name>
     * 
     * NOTA: Definiamo le get functions all'interno della classe, dato che sono funzioni inline
     * 
     * NOTA: Definiamo isDisponibile in maniera diversa dalle get functions per evidenziare l'utilità
     *       della funzione stessa, presta() e restituisci() modificano indirettamente isDisponibile()
     * 
     */
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
    void setDisponibile(bool);
    
    bool isDisponibile() const {return disponibile;} /*gestisce lo stato del libro: */
    void presta();
    void restituisci();
    
    /*
     * Classe definita per la gestione delle eccezioni. 
     */
    class Invalid{};
};

/* Operatori di confronto 
 * 
 * NOTA: abbiamo deciso di sfruttare al meglio le get function della classe
 *       Book e far confrontare direttamente due libri anzichè due singoli isbn, 
 *       anche per una questione di generalizzazione, così possiamo confrontare
 *       non solo gli isbn ma anche tutti gli altri parametri dei libri
 *
 */
bool operator==(const Book& book1, const Book& book2);
bool operator!=(const Book& book1, const Book& book2);

// Output to stream
std::ostream& operator<<(std::ostream& os, const Book& book);

#endif
