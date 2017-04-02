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

  bool load_database(string filename);
  bool update_database(string filename);
  bool search_book_by_author(string author);
  bool search_book_by_book_id(Book_Id book_id);
  bool search_book_by_title(string title);
  bool search_book_by_publisher(string publisher);
  bool add_book(Book book_obj);
  bool delete_book(Book book_obj);

};
