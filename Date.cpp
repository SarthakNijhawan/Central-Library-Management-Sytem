#include "Date.h"
#include <ctime>

class Date {
    unsigned int date;
    unsigned int month;
    unsigned int year;

    Date() {
        this->date = 0;
        this->month = 0;
        this->year = 0;
    }

    Date(unsigned int date, unsigned int month, unsigned int year) {
        this->date = date;
        this->month = month;
        this->year = year;
    }

    Date(const Date &original) {
        this->date = original.date;
        this->month = original.month;
        this->year = original.year;
    }

    unsigned int getDate() {
        return date;
    }

    void setDate(unsigned int date) {
        this->date = date;
    }

    unsigned int getMonth() {
        return month;
    }

    void setDate(unsigned int month) {
        this->month = month;
    }

    unsigned int getYear() {
        return year;
    }

    void setYear(unsigned int year) {
        this->year = year;
    }

    static Date getInstance() {
        time_t t = time(0);
        struct tm *now = localtime(&t);
        return new Date(now->tm_mday, now->tm_mon, now->tm_year);
    }
}
