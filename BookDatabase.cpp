#include"BookDatabase.h"
#include"Book.h"
#include<fstream>
#include<unordered_map>
#include<sstream>
#include<string>
#include<vector>

class BookDatabase{

private:

  long unsigned int total_number_of_books;
  std::vector<Book> books_database_vector; // The indices will be nothing but the book_id
  std::unordered_map<std::string, Book> books_database_by_author; // Hashmaps used
  std::unordered_map<std::string, Book> books_database_by_publisher; // Hashmaps used
  std::unordered_map<std::string, Book> books_database_by_title; // Hashmaps used

public:
  /*
  Constructor and Destructor
  */
  BookDatabase(){
    this->total_number_of_books = 0;
  }

  /*
  - Loads the database into an ordered map using the  book_id for comparison and
    3 unordered maps each corresponding to the string searches
  - Called by the library class Constructor
  */
  bool loadDatabase(string filename){

  }

  bool updateDatabase(string filename){

  }

  /*
  Returns the pointer to the book searched for else a NULL if book doesnot exist.
  */
  Book* searchBookByAuthor(string author){

  }
  Book* searchBookByBookId(int  book_id){

  }
  Book* searchBookByTitle(string title){

  }
  Book* searchBookByPublisher(string publisher){

  }

  /*
  Adds a totally new book to the database
  The book_object wont have any book_id initially, it has to be assigned.
  */
  Book* addBook(Book book_obj){

  }

  /*
  - Deletes a book only when it exists and decreaments the number of copies or
    delete the object completely if (volume==1)
  - Input is a pointer to the book oject in the BookDatabase data structure.
  - When number of copies of a book goes to zero that doesnot mean that the book
    object or book_id will be destroyed.
  */
  bool deleteBook(Book* book_obj){


  }

  /*
  Updates the info for an already existing book
  */
  bool updateInfo(){

  }

};
