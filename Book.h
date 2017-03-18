#include"String.h"

class Book{
	// Attributes for books
	String title;
	String author;
	String publisher;
	long unsigned int book_id;

	// Methods for Book class
	Book();
	Book(String title, String author, String publisher, long unsigned int book_id);
	String getTitle();
	void setTitle(String title);
	String getAuthor();
	void setAuthor(String author);
	String getPublisher();
	void setPublisher(String publisher);
	long unsigned int getBookID();
	void setBookID(long unsigned int book_id);
};
