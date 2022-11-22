#include "Isbn.hpp"
#include <iostream>
#include <vector>

/* Il costruttore assegna i valori passati solo se sono tutti validi */
Isbn::Isbn(std::string a, std::string b, std::string c, char d){
    if(validate(a,b,c,toupper(d)))
       n1 = a, n2 = b, n3 = c, x = toupper(d); 
    else throw Invalid{};
}

/* Questo costruttore accetta una stringa e la divide in sottostringhe per verificare i valori */
Isbn::Isbn(std::string s){
    //separo in sottostringhe secondo il carattere delimitatore '-'
    std::vector<std::string> substrings = splitString(s, '-');   

    //se non ci sono 4 sottostringhe (N1-N2-N3-X) o la 4° (X) non è un singolo carattere, non ho valori validi
    if(substrings.size()<4 || substrings[3].length()>1)
        throw Invalid{};

    //salvo X in una variabile temporanea per comodità
    char d = toupper(substrings[3][0]);
    //valido N1, N2, N3 e X
    if(validate(substrings[0], substrings[1], substrings[2], d))           
        n1 = substrings[0], n2 = substrings[1], n3 = substrings[2], x = d; 
    else throw Invalid{};
}

void Isbn::setN1(std::string a) {
    if(validateString(a))
        n1 = a;
    else throw Invalid{};
}
void Isbn::setN2(std::string b) {
    if(validateString(b))
        n2 = b;
    else throw Invalid{};
}
void Isbn::setN3(std::string c) {
    if(validateString(c))
        n3 = c;
    else throw Invalid{};
}
void Isbn::setX(char d) {
    if(validateChar(toupper(d)))
        x = toupper(d);
    else throw Invalid{};
}

/* Funzione che controlla la validità di una stringa secondo il formato di N richiesto */
bool Isbn::validateString(std::string s){
    // se la stringa è vuota o ha più di 3 caratteri non è valida
    if(s.empty() || s.length()>3)
        return false;
    // se almeno un carattere non è una cifra la stringa non è valida 
    for(int i=0; i<s.length(); i++){
        if(s[i]<'0' || s[i]>'9')
            return false;
    }
    return true;
}

/* Funzione che controlla la validità di una stringa secondo il formato di X richiesto*/
bool Isbn::validateChar(char c){
    //se il carattere è vuoto (inclusi spazio e tab) non è valido
    if(isblank(c))
        return false;
    //se il carattere non è una cifra o una lettera maiuscola non è valido
    //per comodità si è deciso di considerare valide solo lettere maiuscole
    if((c<'0' || c>'9') && (c<'A' || c>'Z'))
        return false;
    return true;
}

/* Funzione che raggruppa i controlli sui 4 parametri */
bool Isbn::validate(std::string a, std::string b, std::string c, char d){
    return (validateString(a) && validateString(b) && validateString(c) && validateChar(d));
}

std::vector<std::string> Isbn::splitString(std::string s, char delim){
    //variabili ausiliarie
    std::vector<std::string> elems;
    std::string aux = "";

    //controlla ogni carattere della stringa:
    //se non è il delimitatore continua a "costruire" la sottostringa tramite la variabile aux
    //altrimenti aggiunge aux al vettore delle sottostringhe e la svuota
    for(int i=0; i<s.length(); i++){
        if(s[i]==delim){
            elems.push_back(aux);
            aux = "";
        } else {
            aux += s[i];
        }
    }
    //per il funzionamento del ciclo soprastante l'ultima sottostringa non viene salvata nel vector 
    //se l'ultimo carattere non è un delimitatore
    //perciò se aux contiene ancora una sottostringa non vuota questa viene aggiunta a elems
    if(!aux.empty())
        elems.push_back(aux);

    return elems;
}

std::ostream& operator<<(std::ostream&  os, const Isbn& isbn){
    return os<<isbn.getN1()<<"-"<<isbn.getN2()<<"-"<<isbn.getN3()<<"-"<<isbn.getX();
}

bool operator==(const Isbn& isbn1, const Isbn& isbn2){
    return (isbn1.getN1() == isbn2.getN1() &&
            isbn1.getN2() == isbn2.getN2() &&
            isbn1.getN3() == isbn2.getN3() &&
            isbn1.getX() == isbn2.getX());
}
