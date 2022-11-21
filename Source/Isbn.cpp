#include ".\headers\Isbn.hpp"
#include <iostream>
#include <vector>

Isbn::Isbn(std::string a, std::string b, std::string c, char d){
    if(validate(a,b,c,toupper(d)))
       n1 = a, n2 = b, n3 = c, x = toupper(d); 
    else throw Invalid{};
}

//costruttore che accetta una std::string
Isbn::Isbn(std::string s){
    std::vector<std::string> substrings = splitString(s, '-');   //separo in sottostringhe secondo il carattere delimitatore '-'

    if(substrings.size()<4 || substrings[3].length()>1)   //se non ci sono 4 sottostringhe (N1-N2-N3-X) o la 4° (X) non è un 
        throw Invalid{};                        //singolo carattere, non ho valori validi

    char d = toupper(substrings[3][0]);                          //salvo X in una variabile temporanea per comodità
    if(validate(substrings[0], substrings[1], substrings[2], d))           //valido N1, N2, N3 e X
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

std::ostream& operator<<(std::ostream&  os, const Isbn& isbn){
    return os<<isbn.getN1()<<"-"<<isbn.getN2()<<"-"<<isbn.getN3()<<"-"<<isbn.getX();
}

bool operator==(const Isbn& isbn1, const Isbn& isbn2){
    return (isbn1.getN1() == isbn2.getN1() &&
            isbn1.getN2() == isbn2.getN2() &&
            isbn1.getN3() == isbn2.getN3() &&
            isbn1.getX() == isbn2.getX());
}

//funzione che controlla la validità di una stringa secondo il formato di N (solo cifre)
bool Isbn::validateString(std::string s){
    if(s.empty() || s.length()>3)                       //se la stringa è vuota non è valida
        return false;
    for(int i=0; i<s.length(); i++){    //controlla ogni carattere
        if(s[i]<'0' || s[i]>'9')        //se almeno un carattere non è una cifra la stringa non è valida
            return false;
    }
    return true;
}

//funzione che controlla la validità di una stringa secondo il formato di X (solo cifre o lettere)
bool Isbn::validateChar(char c){
    if(isblank(c))                              //se il carattere è vuoto (inclusi spazio e tab) non è valido
        return false;
    if((c<'0' || c>'9') && (c<'A' || c>'Z'))    //se il carattere non è una cifra o una lettera maiuscola non è valido
        return false;                           //per comodità si è scelto di imporre valide solo le maiuscole
    return true;
}

//funzione che controlla la validità di 3 string e un char
bool Isbn::validate(std::string a, std::string b, std::string c, char d){
    return (validateString(a) && validateString(b) && validateString(c) && validateChar(d));    //devono essere tutti validi
}

//funzione che divide una string secondo un carattere delimitatore
std::vector<std::string> Isbn::splitString(std::string s, char delim){
    std::vector<std::string> elems;     //vettore ausiliario dove salvare le sottostringhe
    std::string aux = "";               //variabile ausiliaria per "costruire" carattere per carattere le sottostringhe

    for(int i=0; i<s.length(); i++){
        if(s[i]==delim){                //se il carattere è uguale al delimitatore
            elems.push_back(aux);       //aggiunge a elems la stringa costruita
            aux = "";                   //e la svuota
        } else {                        //altrimenti
            aux += s[i];                //continua a "costruire" la sottostringa
        }
    }                                   //l'ultima sottostringa non viene salvata se l'ultimo carattere non è il delimitatore
    if(!aux.empty())                    //perciò se aux contiene ancora una sottostringa non vuota
        elems.push_back(aux);           //questa viene aggiunta a elems

    return elems;                       //restituisce il vector contenente tutte le sottostringhe
}
