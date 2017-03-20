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

  bool load_database(string filename); //loads the database into a vector
  bool update_database(string filename);
  bool search_book_by_author(String author);
  bool search_book_by_book_id(Book_Id book_id);
  bool search_book_by_title(String title);
  bool search_book_by_publisher(String publisher);
  bool add_book(Book book_obj);
  bool delete_book(Book book_obj);

};


// Loads whole of the data into a vector
bool BookDatabase::load_database(string filename){

  ifstream  my_data_file;
  string line;
  my_data_file.open(filename);
  int total_books=0;

  while(std::getline(my_data_file,line))
  {
      total_books++;
      Book new_book;
      std::stringstream  lineStream(line);
      std::string        cell;

      //each cell is an attribute of the data object

      while(std::getline(lineStream, cell, ','))
      {
        

      }

  }

  my_data_file.close();

  }

bool BookDatabase::update_database(string filename){
  ofstream my_data_file;
  my_data_file.open(filename);
  map::iterator it;

  for(it = database_map.begin(); it!=database_map.end(); it++ ){

    string line;                                                            // book_id, title, author, publisher (Claim status)
    line.append(string(it->book_id.id));
    line.append(",");
    line.append(string(it->book_id.number));
    line.append(",");
    line.append(it->title);
    line.append(",");
    line.append(it->author);
    line.append(",");
    line.append(it->publisher);
    line.append("\n");
    my_data_file << line;

  }
  my_data_file.close();
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
