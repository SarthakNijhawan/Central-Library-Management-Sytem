#include"Book.h"

class Book{
	String title;
	String author;
	long unsigned int book_id;

public:
	/**
	 * Default constructor
	 */
	Book() {
		this->title = "";
		this->author = "";
		this->book_id = 0;
	}

	/**
	 * Parameterized constructor
	 * @param title The title of the book
	 * @param author The name of the author of the book
	 * @param book_id The unique ID given to each book in the library
	 */
	Book(String title, String author, int book_id) {
		this->title = title;
		this->author = author;
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
		this.title = title;
	}

	/**
	 * Returns the author of the book
	 */
	String getAuthor() {
		return author;
	}

	/**
	 * Changes the author of the book
	 * @param title The new author name that is to be set
	 */
	void setAuthor(String author) {
		this.author = author;
	}

	/**
	 * Returns the ID of the book
	 */
	long unsigned int getBook_id() {
		return book_id;
	}

	/**
	 * Changes the ID of the book
	 * @param title The new ID that is to be set
	 */
	void setBook_id(int book_id) {
		this.book_id = book_id;
	}
};