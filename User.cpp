#include "User.h"

class User{
  private:
    String name;
    unsigned int roll_number;
    unsigned int fine ;
    unsigned int number_of_books_issued;
    Book* books_issued[number_of_books_issued] = NULL;

  public:
    User();
    String getName();
    void setName(String name);
    unsigned int getRollNumber();
    void setRollNumber(unsigned int roll_number);
    unsigned int getFine();
    void setFine(unsigned int fine);
    unsigned int getNumberOfBooksIssued();
    void setNumberOfBooksIssued(unsigned int number_of_books_issued);
    bool search_book(Book book);
    bool issue_boo  k(Book book);
    bool claim_book(Book book);
    bool return_book();
    void display_info();
    bool update_info();

};

/**
 * Default constructor
 */
User::User() {
    this->name = "";
    this->roll_number = 0;
    this->fine = 0;
    this->number_of_books_issued = 0;
    this->books_issued = NULL;
}

/**
 * Parameterized constructor
 * @param name Name of the user
 * @param roll_number Roll number of the user
 * @param fine Fine due of the user
 * @param number_of_books_issued Number of books issued by the user
 * @param books_issued Pointer to the array of pointers to the books issued by the user
 */
User::User(String name, unsigned int roll_number, unsigned int fine, unsigned int number_of_books_issued, Book* books_issued) {
    this->name = name;
    this->roll_number = roll_number;
    this->fine = fine;
    this->number_of_books_issued = number_of_books_issued;
    /**
     * TODO: FacAd, pointers wala kaam, initialize the books_issued array.
     * -UnstableBrainiac
     */
}

/**
 * Returns the name of the user
 * @return user name
 */
String User::getName() {
    return this->name;
}

/**
 * Changes the name of the user
 * @param name The new name that is to be set
 */
void User::setName(String name) {
    this->name = name;
}

/**
 * Returns the roll number of the user
 * @return user roll number
 */
unsigned int User::getRollNumber() {
    return this->roll_number;
}

/**
 * Changes the roll number of the user
 * @param name The new roll number that is to be set
 */
void User::setRollNumber(unsigned int roll_number) {
    this->roll_number = roll_number;
}

/**
 * Returns the fine amount due against the user
 * @return user fine amount due
 */
unsigned int User::getFine() {
    return this->fine;
}

/**
 * Changes the fine against the user
 * @param name The new fine amount that is to be set
 */
void User::setFine(unsigned int fine) {
    this->fine = fine;
}

/**
 * Returns the number of books issued by the user
 * @return number of books issued by the user
 */
unsigned int User::getNumberOfBooksIssued() {
    return this->number_of_books_issued;
}

/**
 * Changes the number of books issued by the user
 * @param name The new number of books that is to be set
 */
void User::setNumberOfBooksIssued(unsigned int number_of_books_issued) {
    this->number_of_books_issued = number_of_books_issued;
}

/**
 * TODO:   FacAd, pointers wala kaam, add getter/setter for books_issued
 * -UnstableBrainiac
 */

bool User::issue_book(Book book){
  // Search for the book

  // Check its state if found

  // return bool value
}
