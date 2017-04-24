#include "User.h"

class User{
  private:
    string name;
    unsigned int roll_number;
    unsigned int fine;
    unsigned int number_of_books_issued;
    list<Book> books_issued = NULL;
    void issueAvailableBook(Book book);

  public:
    User();
    string getName();
    void setName(string name);
    unsigned int getRollNumber();
    void setRollNumber(unsigned int roll_number);
    unsigned int getFine();
    void setFine(unsigned int fine);
    unsigned int getNumberOfBooksIssued();
    void setNumberOfBooksIssued(unsigned int number_of_books_issued);
    bool issueBook(Book book);
    bool search_book(Book book);
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
 * @param fine Fine due against the user
 * @param number_of_books_issued Number of books issued by the user
 * @param books_issued Pointer to the array of pointers to the books issued by the user
 */
User::User(string name, unsigned int roll_number, unsigned int fine, unsigned int number_of_books_issued, Book* books_issued) {
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
string User::getName() {
    return this->name;
}

/**
 * Changes the name of the user
 * @param name The new name that is to be set
 */
void User::setName(string name) {
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

/**
 * Private method to be called after checking availability of book
 * @param book The book that is to be issued
 */
void User::issueAvailableBook(Book book) {
    /**
     * TODO: FacAd, Add to pointer array and everything
     * - UnstableBrainiac
     */
}

/**
 * Public method to issue a book if it is available
 * @param book The book that is to be issued
 * @return <code>true</code> if the book was successfully issued;
 * <code>false</code> otherwise.
 */
bool User::issueBook(Book book) {
    int state = book.getState();
    if (state == Book.STATE_AVAILABLE) {
        issueAvailableBook(book);
        return true;
    } else {
        return false;
    }
}
