#include "User.h"
#include<string.h>
#include<Issue.h>
#include<Claim.h>
#include<Book>
#include<Date>

class User{
private:
    string name;
    unsigned int roll_number;
    float fine;
    list<Issue> issued_books_list;
    list<Claim> claimed_books_list;

public:
    User();
    User(string name, unsigned int roll_number, float fine = 0);
    User(string name, unsigned int roll_number, float fine = 0,
        list<Issue> issued_books, list<Claim> claimed_books);

    string getName();
    void setName(string name);
    float getFine();
    void setFine(float fine);
    unsigned int getRollNumber();
    void setRollNumber(unsigned int roll_number);

    void issueBook(Book* book);
    void reIssueBook(Book* book);
    void claimBook(Book* book);
    void returnBook(Book* book);
    void issueClaimedBook(Book* book);
    void updateFine();
    void displayInfo();

};

/**
 * Default constructor
 */
User::User() {
    this->name = "";
    this->roll_number = 0;
    this->fine = 0;
}

/**
 * Parameterized constructor
 * @param name Name of the user
 * @param roll_number Roll number of the user
 * @param fine Fine due against the user
 * @param number_of_books_issued Number of books issued by the user
 * @param books_issued Pointer to the array of pointers to the books issued by the user
 */
User::User(string name, unsigned int roll_number, float fine = 0) {
    this->name = name;
    this->roll_number = roll_number;
    this->fine = fine;

  }

User::User(string name, unsigned int roll_number, float fine = 0, list<Issue> issued_books, list<Claim> claimed_books) {
    this->name = name;
    this->roll_number = roll_number;
    this->fine = fine;
    this->issued_books_list = issued_books;
    this->claimed_books_list = claimed_books;
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
unsigned float User::getFine() {
    updateFine();
    return this->fine;
}

/**
 * Changes the fine against the user
 * @param name The new fine amount that is to be set
 */

void User::setFine(float fine) {
    this->fine = fine;
}

/*
Updates the total fine on a user
*/
void updateFine() {
    list<Issue>::iterator it = issued_books_list.begin();

    while(it != issued_books_list.end()) {
        fine += it->getFine();
    }
}

/*
Checks if the book is available and appends an issue object it into the list of Users and the book itself
Else asks for a claim to be done on the very same book
Note : doesnot issue any claimed books into consideration
*/

void User::issueBook(Book* book) {
    if (book->getState() == 1) {
        Issue book_issue(Date.get_instance(), (*book), (*this));
        this->issued_books_list.push_back(book_issue);
        book->issue_list.push_back(book_issue);

    }
    else {
        cout<<"Sorry but the book's already been issued by someone else."<<endl;

        while(1) {

            cout<<"Do you wish to rather claim the book? y/n"<<endl;
            int answer;
            cin >> answer;
            if(answer == 'y' || answer == 'Y') {
                this->claimBook(book);
                break;
            }
            else if (answer == 'n' || answer == 'N') {
                break;
            }
            else cout << "Please renter your answer to the following question." << endl;

        }
    }
}

void User::reIssueBook() {

}

void User::claimBook(Book* book) {
    if(book->getState() != 1) {
        Claim claim_book(Date.get_instance(), *book, *this);
        this->claimed_books_list.push_back(claim_book);
        book->claim_list.push_back(claim_book);
    }
    else cout << "Sorry the book's available, your request was dismissed."<<endl;
}

void User::returnBook(Book* book) {
    list<Issue>::iterator it = this->issued_books_list.begin();

    while(it != this->issued_books_list.end()) {
        if(it->book == book){
            this->issued_books_list.erase(it);
            break;
        }
    }

    list<Issue>::iterator it = book->issue_list.begin();

    while(it != book->issue_list.end()) {

    }


}

void User::displayInfo() {
    cout << this->roll_number << " : " << this->name << endl;
    cout<< "Overdue fine "<< this->fine << endl;
    cout<< "Issued books are : " << endl;

    list<Issue>::iterator it = this->issued_books_list.begin();
    while (it != this->issued_books_list.end()) {
        it->displayInfo();
    }

    cout<<"Claimed Books are : "

    list<Claim>::iterator it = this->claimed_books_list.begin();
    while (it != this->claimed_books_list.end()) {
        it->displayInfo();
    }

}
