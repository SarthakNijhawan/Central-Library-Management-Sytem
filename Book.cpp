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

	long unsigned int book_id;
	unsigned int copies;
	string title;
	string author;
	string publisher;
	int state;

public:
	/**
	Constructors
	**/
	Book();
	Book(int book_id, string title, string author, string publisher, int copies = 1, int state = 1);// Default values will help in adding new book
	Book(const Book &original);

	/**
	Getters and setters
	**/
	long unsigned int getBookId();
	void setBookId(long unsigned int book_id);
	unsigned int getCopies();
	void setCopies(unsigned int copies);
	void increamentCopies();
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
	this->book_id = 0;
	this->copies = 0;
	this->title = "";
	this->author = "";
	this->publisher = "";
}

/**
 * Parameterized constructor
 * @param title The title of the book
 * @param author The name of the author of the book
 * @param publisher The name of the publisher of the book
 * @param book_id The unique ID given to each book in the library
 */
Book::Book(int book_id, string title, string author, string publisher, int copies, int state = 1) {
	this->book_id = book_id;
	this->copies = copies;
	this->title = title;
	this->author = author;
	this->publisher = publisher;
	this->state = 1;
}

/**
 * Copy constructor
 * @param original The book object to make a copy of
 */
Book::Book(const Book &original) {
	this->book_id = original.book_id;
	this->copies = original.copies;
	this->title = original.title;
	this->author = original.author;
	this->publisher = original.publisher;
}

/**
 * Returns the ID of the book
 * @return book ID
 */
long unsigned int Book::getBookId() {
	return book_id;
}

/**
 * Changes the ID of the book
 * @param book_id The new ID that is to be set
 */
void Book::setBookId(long unsigned int book_id) {
	this->book_id = book_id;
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

unsigned int Book::getCopies(){
	return copies;
}

void Book::increamentCopies(){
	this->copies++;
}

void Boook::setCopies(int copies){
	this->copies = copies;
}
