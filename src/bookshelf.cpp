#include <stdexcept>
#include "bookshelf.h"

BookShelf::BookShelf(unsigned int c): size_{0}, capacity_{c}, elem_{new Book[c]} {}

BookShelf::BookShelf(const BookShelf &item): size_{item.size_}, capacity_{item.capacity_}, elem_{new Book[capacity_]}
{
    std::copy(item.elem_, item.elem_ + size_, elem_);
}

BookShelf::BookShelf(BookShelf &&item): size_{item.size_}, capacity_{item.capacity_}, elem_{item.elem_}
{
    item.size_ = 0;
    item.elem_ = nullptr;
}

int BookShelf::size() const
{
    return size_;
}

int BookShelf::capacity() const
{
    return capacity_;
}

Book& BookShelf::at(int index) const
{
    if(index < 0 || index >= size_)
    {
        throw std::out_of_range("Index out of range");
    }

    return elem_[index];
}
void BookShelf::push_back(Book& item)
{
    if(size_ == capacity_)
    {
        resize(2*capacity_);
    }
    elem_[size_] = item;
    size_++;
}

Book& BookShelf::pop_back()
{
    if(size_ == 0)
    {
        throw std::out_of_range("Index out of range");
    }

    return elem_[--size_];
}

void BookShelf::reserve(int dim)
{
    if(capacity_ < dim)
    {
        resize(dim);
    }
}

void BookShelf::resize(int dim)
{
    if(dim < size_)
    {
        throw std::invalid_argument("Invalid new size provided");
    }

    Book* p = new Book[dim];
    std::copy(elem_, elem_+size_, p);
    delete[] elem_;
    elem_ = p;
    capacity_ = dim;
}

BookShelf& BookShelf::operator=(const BookShelf &item)
{
    if(this != &item)
    {
        Book* p = new Book[item.capacity_];
        std::copy(item.elem_, item.elem_ + size_, p);
        delete[] elem_;
        elem_ = p;
        size_ = item.size_;
        capacity_ = item.capacity_;
    }
    
    return *this;
}

BookShelf& BookShelf::operator=(BookShelf &&item)
{
    if(this != &item)
    {
        elem_ = item.elem_;
        size_ = item.size_;
        capacity_ = item.capacity_;
        delete[] elem_;
        item.size_ = 0;
        item.elem_ = nullptr;
    }
    return *this;
}

Book& BookShelf::operator[](int index)
{
    return elem_[index];
}

const Book& BookShelf::operator[](int index) const
{
    return elem_[index];
}

std::ostream& operator<<(std::ostream& os, const BookShelf& item)
{
    for (size_t i = 0; i < item.size_; i++)
    {
        os << item.at(i) << "\n";
    }
    return os;
}