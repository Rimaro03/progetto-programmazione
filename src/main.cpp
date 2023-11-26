#include <iostream>
#include "bookshelf.h"

int main(int, char**){
    std::string ISBN = "1234567890123";
    std::string title = "La Divina Commedia";
    std::string authorName = "Leonardo";
    std::string authorSurname = "Battisti";
    Book book = Book(authorName, authorSurname, title, ISBN);
    std::cout << book.copyRightDate() << "\n";

    BookShelf shelf0 = BookShelf();
    shelf0.push_back(book);

    std::cout << shelf0[0] << "\n";
    BookShelf shelf2 (shelf0);
    std::cout << shelf2.at(0) << "\n";
    BookShelf shelf3 = shelf0;
    std::cout << shelf0.size() << "\n";
    std::cout << shelf2.capacity() << "\n";
    const BookShelf shelf4 = BookShelf(shelf0);
    std::cout << shelf4.at(0) << "\n";

    shelf0.push_back(book);
    shelf0.push_back(book);
    shelf0.push_back(book);

    std::cout << shelf0 << "\n";

    Book mybook = Book("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "887-521-837-4");
    std::cout << mybook << "\n";
    
    BookShelf shelf(10);
    shelf.push_back(book);
    shelf.pop_back();
}
