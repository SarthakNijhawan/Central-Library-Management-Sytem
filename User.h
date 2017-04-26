class User{
private:
    string name;
    unsigned int roll_number;
    float fine;
    list<Issue> issued_books_list;
    list<Claim> claimed_books_list;

public:
    User();
    User(string name, unsigned int roll_number, float fine = 0, list<Issue> issued_books, list<Claim> claimed_books);
    User(const User &original);
    string getName();
    void setName(string name);
    unsigned int getRollNumber();
    void setRollNumber(unsigned int roll_number);
    float getFine();
    void setFine(float fine);
    void updateFine();
    void issueBook(Book* book);
    void claimBook(Book* book);
    void returnBook(Book* book);
    void display();
}
