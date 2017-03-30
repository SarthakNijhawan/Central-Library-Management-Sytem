#include"Library.h"
#include"User_Database.h"
#include"Book_Database.h"
#include<fstream>
#include<sstream>
#include<string>


class Library{
  private:
    Book_Database book_database;
    User_Database user_database;

  public:
    //Constructor and Destructors
    Library(string book_database_file, string user_database_file);
    ~Library();

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

    //Database loading and writing realted problem
    template<class T>
    bool load_database(T t_database, string filename);
    template<class T>
    bool update_database(T t_database, string filename);

};

  Library::Library(string book_database_file, string user_database_file){
    if(load_database(book_database, book_database_file) && load_database(user_database, user_database_file)){
      cout<<"Successfully loaded both the databases !!";
    }
    else {
      cerr<<"Error loading the databases !!!";
    }

  }

  Library::~Library(){
    if(update_database(book_database, "books.txt") && update_database(user_database, "users.txt")){
      cout<<"Successfully written into both the databases !!";
    }
    else {
      cerr<<"Error writing into the databases !!!";
    }

  }

  //Reads the databases
  bool Library::load_database(T t_database, String filename){

  }


  //Updates the databases with the containers
  bool Library::update_database(T t_database, String filename){
    
  }
