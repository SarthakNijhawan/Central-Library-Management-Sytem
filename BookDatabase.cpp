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
  std::map<int, Book> database_map;
  long unsigned int last_id = 1;

public:
  BookDatabase();
  ~BookDatabase();
  bool load_database(); //loads the database into a vector
  bool search_book_by_author(String author);
  bool search_book_by_book_id(Book_Id book_id);
  bool search_book_by_title(String title);
  bool search_book_by_publisher(String publisher);
  bool add_book(Book book_obj);
  bool delete_book(Book book_obj);

};

//Default constructor (loads the data into a map)
BookDatabase::BookDatabase(){
  //load the database into the vector
  if(load_database())
  {
    cout<<"Data Loaded Successfully"<<endl;
    this->last_id = this->book_database_vector.size();

  }else cerr<<"Error loading the file";

}


// Destructor (Update the database with all the changes performed on the container)
BookDatabase::~BookDatabase(){


}

// Loads whole of the data into a vector
bool BookDatabase::load_database(){
  ifstream book_database_file;
  book_database_file.open("books.txt");

  std::string line;
  while (std::getline(infile, line))
  {
      std::istringstream iss(line);
      int a, b;
      if (!(iss >> a >> b)) { break; } // error

      // process pair (a,b)

  }

bool BookDatabase::add_book(Book book_obj){
  //search for the book
  if(book_obj.book_id.id!=0){
    //means already exists since book_ids will start assigning from 1
    book_database_vector[book_obj.book_id.id-1].update_book_num(1);
  }
  else{
    book_database_vector.append(book_obj);
    this->last_id++; //updating the last_id
    book_database_vector[last_id-1].update_new_book_id(last_id);
  }
}

bool BookDatabase::delete_book(Book book_obj){
  if(book_obj.book_id.id!=0){

  }
}

}
