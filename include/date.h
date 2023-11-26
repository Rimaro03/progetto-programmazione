#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date{
public:
	/**
	 * Construct a new Date object
	 * @param day Day of the date
	 * @param month Month of the date
	 * @param year Year of the date
	*/
	Date(int day, int month, int year);
	
	/**
	 * Construct a new Date object with the current date
	*/
	Date();
	
	int day() const;
	int month() const;
	int year() const;
	
	bool operator==(Date& d) const;
	bool operator<(Date& d) const;
	bool operator>(Date& d) const;
	bool operator<=(Date& d) const;
	bool operator>=(Date& d) const;
	friend std::ostream& operator<<(std::ostream& stream, const Date& d);
private:
	int day_;
	int month_;
	int year_;	
};

#endif
