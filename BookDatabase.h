class BookDatabase{
private:
  std::map<int, Book> database_map;
  long unsigned int last_id;

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
