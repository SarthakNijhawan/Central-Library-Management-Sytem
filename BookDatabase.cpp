#include"BookDatabase.h"
#include"Book.h"
#include<fstream.h>
#include<sstream.h>
#include<unordered_map.h>
#include<string>
#include<vector>
#include<pair>
#include<stdlib.h>

class BookDatabase{

private:
  static const int number_of_attributes_in_file = 6; //Keeps track of number of columns in csv file delimied by ','

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
  - Loads the database into a vector with book_ids as indices and
    3 unordered maps each corresponding to the string searches
  - Called by the library class Constructor
  */
  bool loadDatabase(string filename){
    ifstream file;
    file.open(filename);

    if(file.fail()){
      cerr<<"Error opening file!"<<endl;
      exit(1);
    }

    //Reads the file line by line
    string value;
    while(getline(file, value)){

      stringstream my_stream(value);
      std::vector<string> single_book_vector(number_of_attributes_in_file);
      int i = 0;

      // This while loop is feeding in info of a single book into a vector
      while(getline(my_stream, single_book_vector[i], ',')){
        i++;
      }

      a_book = vectorToBook(single_book_vector);

      books_database_vector.push_back(a_book);

      //Constructed pairs for inserting into unordered maps
      std::pair<std::string, Book> title_pair(a_book.title, a_book);
      std::pair<std::string, Book> author_pair(a_book.author, a_book);
      std::pair<std::string, Book> publisher_pair(a_book.publisher, a_book);

      books_database_by_title.insert(title_pair);
      books_database_by_author.insert(author_pair);
      books_database_by_publisher.insert(publisher_pair);

    }

    this->total_number_of_books = this->books_database_vector.size();

    file.close();

    return true;
  }

  /*
  Converts a vector from a file into a book. The order follows:
  - Book_id
  - Title
  - Author
  - Publisher
  - Number_of_copies
  - State
  */
  Book vectorToBook(std::vector<string> book_vector){
    return Book(stoi(book_vector[0]), book_vector[1], book_vector[2], book_vector[3], stoi(book_vector[4]), stoi(book_vector[5]));
  }



  /*
  Writes into the database
  */
  bool updateDatabase(string filename){
    ofstream file;
    file.open(filename);

    std::std::vector<Book>::iterator itr = books_database_vector.begin();

    if(file.fail()){
      cerr << "Opening the file! "<<endl;
      exit(1);
    }

    while(itr != books_database_vector.end()){
      stringstream my_stream;

      my_stream << (itr*).book_id << ',' << (itr*).title << ',' << (itr*).author
      << ',' << (itr*).publisher << ',' << (itr*).copies << ',' << (itr*).state;

      file << my_stream.str() << std::endl;

    }

    file.close();
    return true;
  }

  /*
  Returns the pointer to the book searched for else a NULL if book doesnot exist.
  */
  Book* searchBookByAuthor(string author){

    unordered_map<std::string, Book>::const_iterator got = books_database_by_author.find(author);
    if(got == unordered_map.end()){
      return NULL;
    }
    else {
      return &(got->second);
    }

  }

  Book* searchBookByBookId(int  book_id){

    if(book_id < this->total_number_of_books){
      return &books_database_vector[book_id];
    }
    else return NULL;

  }

  Book* searchBookByTitle(string title){

        unordered_map<std::string, Book>::const_iterator got = books_database_by_title.find(title);
        if(got == unordered_map.end()){
          return NULL;
        }
        else {
          return &(got->second);
        }


  }

  Book* searchBookByPublisher(string publisher){

        unordered_map<std::string, Book>::const_iterator got = books_database_by_publisher.find(publisher);
        if(got == unordered_map.end()){
          return NULL;
        }
        else {
          return &(got->second);
        }


  }

  /*
  Adds a totally new book to the database
  The book_object wont have any book_id initially, it has to be assigned.
  */
  Book* addBook(Book book_obj){

    book_obj.book_id = total_number_of_books;
    total_number_of_books++;
    books_database_vector.push_back(book_obj);

    return &books_database_vector[book_id];
  }

  /*
  - Deletes a book only when it exists and decreaments the number of copies
  - Input is a pointer to the book oject in the BookDatabase data structure.
  - When number of copies of a book goes to zero that doesnot mean that the book
    object or book_id will be destroyed.
  */
  bool deleteBook(Book* book_obj){

    book_obj->copies--;
    return true;
  }

  /*
  Updates the info for an already existing book
  */
  bool updateInfo(){

  }

};
