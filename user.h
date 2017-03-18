class User{
  private:
    String name;
    unsigned int fine = 0;
    unsigned int num_of_books_issued = 0;
    Book* books_issued[num_of_books_issued] = NULL;

  public:
    User(String name, unsigned int fine);
    bool issue_book(Book book_obj);
    bool claim_book(Book book_obj);
    bool return_book();
    void display_info();
    bool update_info();

};
