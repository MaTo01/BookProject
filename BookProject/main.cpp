#include "Date.hpp"
#include "Isbn.hpp"
#include "Book.hpp"
#include <iostream>

int main()
{
	std::vector<Book> shelf(10);
	Book my_favourite_book("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "887-521-837-4");
    
    //Isbn i = Isbn("123","456","789",'A');
    
    //std::cout<<i;
	std::cout<<my_favourite_book;
	return 0;
}
