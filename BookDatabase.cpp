#include"BookDatabase.h"
#include"Book.h"
#include<fstream>
#include<map>
#include<unordered_map>
#include<sstream>
#include<string>
#include<vector>

class BookDatabase{

private:
  std::map<int, Book> ;
  std::unordered_map<>
  long unsigned int last_id = 1;

public:

  bool loadDatabase(string filename);
  bool updateDatabase(string filename);
  /*
  Returns NULL if book not found by any of the search functions
  */
  Book* searchBookByAuthor(string author, Book* the_book );
  Book* searchBookByAccountNumber(int accountnumber, Book* the_book );
  Book* searchBookByTitle(string title, Book* the_book );
  Book* searchBookByPublisher(string publisher, Book* the_book );

  /*
  Adds a totally new book to the database
  The book_object wont have any accountnumber, it has to be assigned.
  */
  Book* addBook(Book book_obj){

  }

  /*
  Deletes a book only when it exists and decreaments the number of volumes or delete the object completely if (volume==1)
  Input is a pointer to the book oject in the BookDatabase data structure
  */
  bool deleteBook(Book* book_obj){


  }



};
