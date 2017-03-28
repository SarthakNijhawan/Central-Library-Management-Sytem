#include"Book.h"

class Book{
	String title;
	String author;
	String publisher;
	long unsigned int book_id;

public:
	/**
	 * Default constructor
	 */
	Book() {
		this->title = "";
		this->author = "";
		this->publisher = "";
		this->book_id = 0;
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
	 * @return book title
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
	 * @return book author name
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
	 * @return book publisher
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
	 * @return book ID
	 */
	long unsigned int getBookID() {
		return book_id;
	}

	/**
	 * Changes the ID of the book
	 * @param book_id The new ID that is to be set
	 */
	void setBookID(long unsigned int book_id) {
		this->book_id = book_id;
	}
};