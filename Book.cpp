#include"Book.h"


enum Status {1, 0, -1}; // 1 -> Available, 0-> Issued, -1-> Claimed

class Book_id{
public:
	unsigned long int id = 0;
	unsigned int number = 0;
}

class Book{

	String title;
	String author;
	String publisher;
	Book_Id book_id;
	Status state = 1;

public:
	/**
	 * Default constructor
	 */
	Book() {
		this->title = "";
		this->author = "";
		this->publisher = "";
		this->book_id.id = 0;
		this->book_id.add_book();
	}

	/**
	 * Parameterized constructor
	 * @param title The title of the book
	 * @param author The name of the author of the book
	 * @param publisher The name of the publisher of the book
	 * @param book_id The unique ID given to each book in the library
	 */
	Book(String title, String author, String publisher, int book_id) {
		this->title = title;
		this->author = author;
		this->publisher = publisher;
		this->book_id = book_id;
	}

	/**
	 * Returns the title of the book
	 */
	String getTitle() {
		return title;
	}

	/**
	 * Changes the title of the book
	 * @param title The new title that is to be set
	 */
	void setTitle(String title) {
		this->title = title;
	}

	/**
	 * Returns the name of the author of the book
	 */
	String getAuthor() {
		return author;
	}

	/**
	 * Changes the name of the author of the book
	 * @param author The new author name that is to be set
	 */
	void setAuthor(String author) {
		this->author = author;
	}

	/**
	 * Returns the name of the publisher of the book
	 */
	String getPublisher() {
		return publisher;
	}

	/**
	 * Changes the name of the publisher of the book
	 * @param publisher The new publisher name that is to be set
	 */
	void setPublisher(String publisher) {
		this->publisher = publisher;
	}

	/**
	 * Returns the ID of the book
	 */
	long unsigned int getBookID() {
		return book_id.id;
	}

	/**
	 * Changes the ID of the book
	 * @param book_id The new ID that is to be set
	 */
	void setBookID(long unsigned int book_id) {
		this->book_id = book_id;
	}

	void update_book_num(int i=1){ // i=1 when a book is added while i=-1 when the book is to be deleted
		this->book_id.number+=i;
		this->state=1;
	}

	void update_new_book_id(long unsigned int id){ // Only for newly initialised books
		this->book_id.id=id;
		this->book_id.number++;
		this->state=1 ; //Now available
	}

};
