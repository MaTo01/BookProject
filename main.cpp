#include "Date.hpp"
#include "Isbn.hpp"
#include "Book.hpp"
#include <iostream>

/*compile command: 
    g++ -o book.exe main.cpp source/Book.cpp source/Isbn.cpp source/Date.cpp -I headers
*/

int main()
{
	std::vector<Book> shelf(10);
	Book my_favourite_book("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "887-521-837-4");
	Book my_least_favorite_book("Bjarne", "Stroustrup", "Programming: Principles and Practice Using C++", "978-032-543-7", Date(15, Date::Month(12), 2008));
	Book my_second_favorite_book("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "887-521-837-4");

	std::cout<<my_favourite_book<<std::endl;
    std::cout<<my_least_favorite_book<<std::endl;
    
    std::cout<<(my_favourite_book==my_least_favorite_book)<<std::endl;
    std::cout<<(my_favourite_book!=my_least_favorite_book)<<std::endl;
    std::cout<<(my_favourite_book==my_second_favorite_book)<<std::endl;
    
    my_second_favorite_book.setData(Date(27,Date::may,2003));
    my_second_favorite_book.presta();
    std::cout<<my_second_favorite_book<<std::endl;
    my_second_favorite_book.restituisci();
    std::cout<<my_second_favorite_book<<std::endl<<std::endl;
    
    shelf[0] = my_favourite_book;
    shelf[1] = my_least_favorite_book;
    shelf[2] = my_second_favorite_book;
    for(int i=0; i<shelf.size(); i++){
        std::cout<<shelf[i]<<std::endl;
    }
    
	return 0;
}
