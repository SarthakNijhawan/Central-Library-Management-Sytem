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

public:

	Book();
	Book(int book_id, string title, string author, string publisher);
	Book(const Book &original);

	//Getters and setters
	long unsigned int getBookID();
	void setBookID(long unsigned int book_id);
	string getTitle();
	void setTitle(string title);
	string getAuthor();
	void setAuthor(string author);
	string getPublisher();
	void setPublisher(string publisher);
	int getState();
	void setState(int state);
	void update_book_num(int i=1);
	void update_new_book_i(long unsigned int id);


};

/**
 * Default constructor
 */
Book::Book() {
	this->book_id = 0;
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
Book::Book(int book_id, string title, string author, string publisher) {
	this->book_id = book_id;
	this->title = title;
	this->author = author;
	this->publisher = publisher;
}

/**
 * Copy constructor
 * @param original The book object to make a copy of
 */
Book::Book(const Book &original) {
	this->book_id = original.book_id;
	this->title = original.title;
	this->author = original.author;
	this->publisher = original.publisher;
}

/**
 * Returns the ID of the book
 * @return book ID
 */
long unsigned int Book::getBookID() {
	return book_id;
}

/**
 * Changes the ID of the book
 * @param book_id The new ID that is to be set
 */
void Book::setBookID(long unsigned int book_id) {
	this->book_id = book_id;
	this->state=1;
}

/**
 * Returns the title of the book
 * @return book title
 */
string Book::getTitle() {
	return title;
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
	return author;
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

void Book::update_book_num(int i=1){ // i=1 when a book is added while i=-1 when the book is to be deleted
	this->book_id.number+=i;
	this->state=1;
}

void Book::update_new_book_i(long unsigned int id){ // Only for newly initialised books
	this->book_id.id=id;
	this->book_id.number++;
	this->state=1 ; //Now available
}
