class BookDatabase{
  
  private:
    std::map<int, Book> ;
    std::unordered_map<>
    long unsigned int last_id = 1;

  public:

    bool loadDatabase(string filename);
    bool updateDatabase(string filename);
    Book* searchBookByAuthor(string author, Book* the_book );
    Book* searchBookByAccountNumber(int accountnumber, Book* the_book );
    Book* searchBookByTitle(string title, Book* the_book );
    Book* searchBookByPublisher(string publisher, Book* the_book );
    Book* addBook(Book book_obj);
    bool deleteBook(Book* book_obj);
};
