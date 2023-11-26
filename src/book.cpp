#include "book.h"
#include <string.h>

Book::Book(const std::string& authorName, const std::string& authorSurname, const std::string& title, const std::string& ISBN, Date copyRightDate): copyRightDate_{copyRightDate}, isAvailable_{true}, authorName_{authorName}, authorSurname_{authorSurname}, title_{title}, ISBN_{ISBN} {
    if(authorName.size() == 0 || authorSurname.size() == 0 || title.size() == 0 || ISBN.size() != 13 || !checkDate(copyRightDate)){
        throw std::invalid_argument("Invalid argument");
    }
}

Book::Book(const std::string& authorName, const std::string& authorSurname, const std::string& title, const std::string& ISBN) : copyRightDate_{Date()}, isAvailable_{true}, authorName_{authorName}, authorSurname_{authorSurname}, title_{title}, ISBN_{ISBN} {
    if(authorName.size() == 0 || authorSurname.size() == 0 || title.size() == 0 || ISBN.size() != 13){
        throw std::invalid_argument("Invalid argument");
    }
}

std::string Book::ISBN() const{
    return ISBN_;
}

std::string Book::title() const{
    return title_;
}

std::string Book::authorName() const{
    return authorName_;
}

std::string Book::authorSurname() const{
    return authorSurname_;
}

bool Book::isAvailable() const{
    return isAvailable_;
}

void Book::isAvailable(bool isAvailable){
    isAvailable_ = isAvailable;
}

Date Book::copyRightDate() const{
    return copyRightDate_;
}

bool Book::checkDate(const Date& date){
    Date now_date; // default con
    return date <= now_date;
}

bool Book::operator==(const Book& other) const{
    return this->ISBN_ == other.ISBN_;
}

bool Book::operator!=(const Book& other) const{
    return this->ISBN_ != other.ISBN_;
}

std::ostream& operator<<(std::ostream& os, const Book& book){
    os << "Title: " << book.title() << std::endl << "Author: " << book.authorName() << " " << book.authorSurname() << std::endl << "ISBN: " << book.ISBN() << std::endl << "Copy right date: " << book.copyRightDate() << std::endl << "Is available: " << book.isAvailable() << std::endl;
    return os;
}