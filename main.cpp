#include "Date.hpp"
#include "Isbn.hpp"
#include "Book.hpp"
#include <iostream>

/*Compile command: 
    g++ -o book.exe main.cpp source/Book.cpp source/Isbn.cpp source/Date.cpp -I headers
*/

int main()
{
	/* Test dichiarazione di un vettore di Book e inizializzazione di un paio di libri */
	std::vector<Book> shelf(10);
	Book my_favourite_book("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "887-521-837-4");
	Book my_second_favourite_book("Bjarne", "Stroustrup", "Programming: Principles and Practice Using C++", "978-032-543-7", Date(15, Date::Month(12), 2008));
	/* Uguale al primo per testare gli operatori di confronto */
	Book my_third_favourite_book("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "887-521-837-4");

	/* Test output to stream */
	std::cout<<"BOOK1\n"<<my_favourite_book<<"\n\n";
 	std::cout<<"BOOK2\n"<<my_second_favourite_book<<"\n\n";
   	std::cout<<"BOOK3\n"<<my_third_favourite_book<<"\n\n";

	/* Test operatori di confronto */
	std::cout<<"book1 == book2?\t"<<((my_favourite_book==my_second_favourite_book)?"SI":"NO")<<"\n";
	std::cout<<"book1 != book2?\t"<<((my_favourite_book!=my_second_favourite_book)?"SI":"NO")<<"\n";
	std::cout<<"book1 == book3?\t"<<((my_favourite_book==my_third_favourite_book)?"SI":"NO")<<"\n\n";

	/* Test set functions della classe Date */
	my_third_favourite_book.setData(Date(27,Date::may,2003));
	std::cout<<"Data di copyright di book3 modificata\n\n";
	
	/* Test disponibilità libro e verifica dell'aggiunta della data a BOOK3 */
	my_third_favourite_book.presta();
	std::cout<<"BOOK3 prestato\n"<<my_third_favourite_book<<"\n\n";
	my_third_favourite_book.restituisci();
	std::cout<<"BOOK3 restituito\n"<<my_third_favourite_book<<"\n\n";

	/* Inizializzazione della shelf */
	shelf[0] = my_favourite_book;
	shelf[1] = my_second_favourite_book;
	shelf[2] = my_third_favourite_book;
	std::cout<<"book1, book2, book3 aggiungi a shelf\n\n";
	std::cout<<"STAMPA DI SHELF\n";
    	for(int i=0; i<shelf.size(); i++){
        	std::cout<<shelf[i]<<"\n";
    	}	
    
	return 0;
}
