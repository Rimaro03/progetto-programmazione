#include "date.h"

#include <time.h>

bool is_acceptable_month(int month){ return month > 0 && month < 13; }
bool is_acceptable_day(int day, int month, int year){
	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return day > 0 && day < 32;
	if(month == 4 || month == 6 || month == 9 || month == 11)
		return day > 0 && day < 32;
	if(month == 2){
		if(year % 4 == 0)
			return day > 0 && day < 30;
		return day > 0 && day < 29; 
	}
	return false;
}

bool is_acceptable_date(int day, int month, int year) {
	return is_acceptable_day(day, month, year) && is_acceptable_month(month);
}

Date::Date(int day, int month, int year){
	year_ = year;
	month_ = month;
	day_ = day;
	if (!is_acceptable_date(day, month, year)) {
		std::cout << "Invalid date : " << *this;
		throw std::exception();
	}
}

Date::Date(){
	time_t theTime = time(NULL);
	tm* aTime = localtime(&theTime);

	day_ = aTime->tm_mday;
	month_ = aTime->tm_mon + 1;
	year_ = aTime->tm_year + 1900; // year starts from 1900
}

int Date::day() const { return day_; }
int Date::month() const { return month_; }
int Date::year() const { return year_; }

bool Date::operator==(Date& d) const {
	return this->day() == d.day() && this->month() == d.month() && this->year() == d.year();
}
bool Date::operator<(Date& d) const {
	if (this->year() == d.year()) {
		if (this->month() == d.month())
			return this->day() < d.day();
		return this->month() < d.month();
	}
	return this->year() < d.year();
}
bool Date::operator>(Date& d) const {
	if (this->year() == d.year()) {
		if (this->month() == d.month())
			return this->day() > d.day();
		return this->month() > d.month();
	}
	return this->year() > d.year();
}
bool Date::operator<=(Date& d) const {
	return !(*this > d);
}
bool Date::operator>=(Date& d) const {
	return !(*this < d);
}

std::ostream& operator<<(std::ostream& stream, const Date& d) {
	return stream << d.day() << "/" << d.month() << "/" << d.year();
}