#include "Date.hpp"
#include "Isbn.hpp"
#include "Book.hpp"
#include <iostream>

int main()
{
	std::vector<Book> shelf(10);
	Book my_favourite_book("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "887-521-837-4");
	
	//TODO: Verifica cosa non va bene nell'operator<< (error: no match for "operator<<" (operand types are std::ostream and Isbn))
	//std::cout<<i;
	//std::cout<<my_favourite_book;
	return 0;
}
