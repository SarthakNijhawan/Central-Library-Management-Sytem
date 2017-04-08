#include"Book.h"

class Book{
	/**
     * Value of the {@link #state} field indicating
     * available.
     */
	static const int STATE_AVAILABLE = 1;
	/**
     * Value of the {@link #state} field indicating
     * issued.
     * If the book is claimed while it is issued,
     * the state remains issued until it is returned.
     */
	static const int STATE_ISSUED = 2;
	/**
     * Value of the {@link #state} field indicating
     * claimed.
     * If the book is claimed while it is issued,
     * the state remains issued until it is returned.
     */
	static const int STATE_CLAIMED = 3;

	long unsigned int accountnumber;
	unsigned int volumes;
	string title;
	string author;
	string publisher;
	int state = 1;
	list<User> users_issued = NULL;
	list<User> users_claimed = NULL;

public:
	/**
	Constructors
	**/
	Book();
	Book(int accountnumber, int volumes, string title, string author, string publisher);
	Book(const Book &original);

	/**
	Getters and setters
	**/
	long unsigned int getAccountNumber();
	void setAccountNumber(long unsigned int accountnumber);
	unsigned int getVolumes();
	void setVolumes(unsigned int volumes);
	void increamentVolumes();
	string getTitle();
	void setTitle(string title);
	string getAuthor();
	void setAuthor(string author);
	string getPublisher();
	void setPublisher(string publisher);
	int getState();
	void setState(int state);

	/*
	Operations on Book class
	*/
	void displayInfo();

};

/**
 * Default constructor
 */
Book::Book() {
	this->accountnumber = 0;
	this->volumes = 0;
	this->title = "";
	this->author = "";
	this->publisher = "";
}

/**
 * Parameterized constructor
 * @param title The title of the book
 * @param author The name of the author of the book
 * @param publisher The name of the publisher of the book
 * @param accountnumber The unique ID given to each book in the library
 */
Book::Book(int accountnumber, int volumes, string title, string author, string publisher) {
	this->accountnumber = accountnumber;
	this->volumes = volumes;
	this->title = title;
	this->author = author;
	this->publisher = publisher;
}

/**
 * Copy constructor
 * @param original The book object to make a copy of
 */
Book::Book(const Book &original) {
	this->accountnumber = original.accountnumber;
	this->volumes = original.volumes;
	this->title = original.title;
	this->author = original.author;
	this->publisher = original.publisher;
}

/**
 * Returns the ID of the book
 * @return book ID
 */
long unsigned int Book::getAccountNumber() {
	return accountnumber;
}

/**
 * Changes the ID of the book
 * @param accountnumber The new ID that is to be set
 */
void Book::setAccountNumber(long unsigned int accountnumber) {
	this->accountnumber = accountnumber;
}

/**
 * Returns the title of the book
 * @return book title
 */
string Book::getTitle() {
	return this->title;
}

/**
 * Changes the title of the book
 * @param title The new title that is to be set
 */
void Book::setTitle(string title) {
	this->title = title;
}

/**
 * Returns the name of the author of the book
 * @return book author name
 */
string Book::getAuthor() {
	return this->author;
}

/**
 * Changes the name of the author of the book
 * @param author The new author name that is to be set
 */
void Book::setAuthor(string author) {
	this->author = author;
}

/**
 * Returns the name of the publisher of the book
 * @return book publisher
 */
string Book::getPublisher() {
	return publisher;
}

/**
 * Changes the name of the publisher of the book
 * @param publisher The new publisher name that is to be set
 */
void Book::setPublisher(string publisher) {
	this->publisher = publisher;
}

/**
 * Returns the current state of the book
 * @return state
 */

int Book::getState() {
	return state;
}

/**
 * Changes the state of the book
 * @param publisher The new state that is to be set
 */
void Book::setState(int state) {
	this->state = state;
}

unsigned int Book::getVolumes(){
	return volumes;
}

void Book::increamentVolumes(){
	this->volumes++;
}

void Boook::setVolumes(int volumes){
	this->volumes = volumes;
}
