class Library{
  private:
    Book_Database book_database;
    User_Database user_database;

  public:
    //Books realted stuff
    void add_book();
    void delete_book(Book book_obj);
    Book search_book_by_id(long int book_id); //Displays status along with search
    Book search_book_by_title(String title);
    Book search_book_by_author(String author);
    Book search_book_by_publisher(String publisher);

    //Issue and return
    void issue_book(user user_info, Book book_to_be_issued);
    void return_book();
    void claim_book();

    //user realted functions
    void add_user();
    void display_user_info();
    void delete_user();

};
