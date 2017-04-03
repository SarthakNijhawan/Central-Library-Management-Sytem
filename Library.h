class Library{
  private:
    Book_Database book_database;
    User_Database user_database;

  public:
    Library(string book_database_file, string user_database_file);
    ~Library();
    bool addBook();
    bool deleteBook();
    bool searchBookByAccountNumber();
    bool searchBookByTitle();
    bool searchBookByAuthor();
    bool searchBookByPublisher();
    void issueBook(user user_info, Book book_to_be_issued);
    void returnBook();
    void claimBook();

};
