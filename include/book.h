#ifndef BOOK_H
#define BOOK_H

#include <stdexcept>
#include <iostream>

#include "date.h"
class Book{
private:
    std::string ISBN_;
    std::string title_;
    std::string authorName_;
    std::string authorSurname_;
    Date copyRightDate_;
    bool isAvailable_ = true;
    
    /**
     * Check if the date is valid (not in the future)
     * @param date Date to check
     * @return True if the date is valid, false otherwise
    */
    bool checkDate(const Date& date);

public:
    /**
     * Construct a new Book object
     * @param ISBN ISBN of the book
     * @param title Title of the book
     * @param authorName Name of the author of the book
    */
    Book(const std::string& authorName, const std::string& authorSurname, const std::string& title, const std::string& ISBN, Date copyRightDate);
    Book(const std::string& authorName, const std::string& authorSurname, const std::string& title, const std::string& ISBN);

    Book() = default;
    
    /* Getters and setters */
    std::string ISBN() const;
    std::string title() const;
    std::string authorName() const;
    std::string authorSurname() const;
    Date copyRightDate() const;
    bool isAvailable() const;

    void isAvailable(bool isAvailable);

    /* Operatos overload */
    bool operator==(const Book& other) const;
    bool operator!=(const Book& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};
#endif