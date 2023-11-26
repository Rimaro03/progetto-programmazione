#ifndef BOOKSHELF_H
#define BOOKSHELF_H
#include "book.h"

class BookShelf
{
	private:
		unsigned int size_;
		unsigned int capacity_;
		Book *elem_;

		/**
		 * Perform a resize with deep copy
		 * @param dim new vector capacity
		*/
		void resize(int dim);

	public:
		/**
		 * Constructors and destructor for BookShelf objects
		 * @param capacity initial capacity of the bookshelf
		*/
		BookShelf(unsigned int capacity = 10);
		BookShelf(const BookShelf &item);
		BookShelf(BookShelf &&item);
		~BookShelf()
		{
			delete[] elem_;
		}

		/* Getters */
		int size() const;
		int capacity() const;

		Book& at(int index) const;
		void push_back(Book& item);
		Book& pop_back();
		void reserve(int dim);

		/* Operators overload */
		Book& operator[](int index);
		const Book& operator[](int index) const;
		BookShelf& operator=(const BookShelf &item);
		BookShelf& operator=(BookShelf &&item);
		friend std::ostream& operator<<(std::ostream& os, const BookShelf& item);
};

#endif
