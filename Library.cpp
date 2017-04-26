#include"Library.h"
#include"User_Database.h"
#include"Book_Database.h"
#include<fstream>
#include<sstream>
#include<string>


class Library{
private:
    static const int number_of_attributes_in_file = 6; //Keeps track of number of columns in csv file delimied by ','

    std::vector<Book> books_database_vector; // The indices will be nothing but the book_id
    std::unordered_map<std::string, Book> books_database_by_author; // Hashmaps used
    std::unordered_map<std::string, Book> books_database_by_publisher; // Hashmaps used
    std::unordered_map<std::string, Book> books_database_by_title; // Hashmaps used
    std::unordered_map<std::string, Book> users_database; // Hashmaps used

public:
    /*
    Constructor and Destructors
    */
    Library();
    Library(string book_database_file, string user_database_file);           //done
    ~Library();


    /*
    Operations on books
    */
    bool addBook(string title, string publisher, string author);           //done
    bool deleteBook(Book* the_book);           //done
    Book* searchBookByBookId(unsigned int book_id);           //done
    Book* searchBookByTitle(string title);           //done
    Book* searchBookByAuthor(string author);           //done
    Book* searchBookByPublisher(string publisher);
    User* searchUser(unsigned int roll_number);

    /*
    Issue and return functions
    */
    bool issueBook(Book* the_book, User* the_user);
    bool returnBook(Book* the_book, User* the_user);
    bool claimBook(Book* the_book, User* the_user);

    /*
    Database functions
    */
    bool loadDatabase(string filename);
    bool updateDatabase(string filename);
    Book vectorToBook(std::vector<string> book_vector);

};

Library::Library();

Library::Library(string book_database_file, string user_database_file){
    if(this->loadDatabase(book_database_file) && user_database.loadDatabase(user_database_file)){
        cout<<"Successfully loaded both the databases !!";
    }
    else {
        cerr<<"Error loading the databases !!!";
    }

}

Library::~Library(){
    if(updateDatabase(book_database, "books.txt") && updateDatabase(user_database, "users.txt")){
        cout<<"Successfully written into the databases !!";
    }
    else {
        cerr<<"Error writing into the databases !!!";
    }

}

/*
- Loads the database into a vector with book_ids as indices and
3 unordered maps each corresponding to the string searches
- Called by the library class Constructor
*/
bool Library::loadDatabase(string filename){
    ifstream file;
    file.open(filename);

    if(file.fail()){
        cerr<<"Error opening file!"<<endl;
        exit(1);
    }

    //Reads the file line by line
    string value;
    while(getline(file, value)){
        stringstream my_stream(value);
        std::vector<string> single_book_vector(number_of_attributes_in_file);
        int i = 0;

        // This while loop is feeding in info of a single book into a vector
        while(getline(my_stream, single_book_vector[i], ',')){
            i++;
        }

        a_book = vectorToBook(single_book_vector);
        books_database_vector.push_back(a_book);

        //Constructed pairs for inserting into unordered maps
        std::pair<std::string, Book> title_pair(a_book.title, a_book);
        std::pair<std::string, Book> author_pair(a_book.author, a_book);
        std::pair<std::string, Book> publisher_pair(a_book.publisher, a_book);
        books_database_by_title.insert(title_pair);
        books_database_by_author.insert(author_pair);
        books_database_by_publisher.insert(publisher_pair);
    }
    this->total_number_of_books = this->books_database_vector.size();
    file.close();
    return true;
}

/*
Converts a vector from a file into a book. The order follows:
- Book_id
- Title
- Author
- Publisher
- Number_of_copies
- State
*/
Book Library::vectorToBook(std::vector<string> book_vector){
    return Book(stoi(book_vector[0]), book_vector[1], book_vector[2], book_vector[3], stoi(book_vector[4]), stoi(book_vector[5]));
}



/*
Writes into the database
*/
bool Library::updateDatabase(string filename){
    ofstream file;
    file.open(filename);

    std::std::vector<Book>::iterator itr = books_database_vector.begin();

    if(file.fail()){
        cerr << "Opening the file! "<<endl;
        exit(1);
    }

    while(itr != books_database_vector.end()){
        stringstream my_stream;

        my_stream << *(itr).book_id << ',' << (*itr).title << ',' << (*itr).author
        << ',' << *(itr).publisher << ',' << (*itr).copies << ',' << (*itr).state;

        file << my_stream.str() << std::endl;

    }

    file.close();
    return true;
}

/*
Returns the pointer to the book searched for else a NULL if book doesnot exist.
*/
Book* Library::searchBookByAuthor(string author){

    unordered_map<std::string, Book>::const_iterator got = books_database_by_author.find(author);
    if(got == unordered_map.end()){
        return NULL;
    }
    else {
        return &(got->second);
    }

}

Book* Library::searchBookByBookId(unsigned int book_id){

    if(book_id < this->total_number_of_books){
        return &books_database_vector[book_id];
    }
    else return NULL;

}

Book* Library::searchBookByTitle(string title){

    unordered_map<std::string, Book>::const_iterator got = books_database_by_title.find(title);
    if(got == unordered_map.end()){
        return NULL;
    }
    else {
        return &(got->second);
    }


}

Book* Library::searchBookByPublisher(string publisher){

    unordered_map<std::string, Book>::const_iterator got = books_database_by_publisher.find(publisher);
    if(got == unordered_map.end()){
        return NULL;
    }
    else {
        return &(got->second);
    }


}

/*
Adds a book to the database
The book_object wont have any book_id initially, it has to be assigned.
*/
bool Library::addBook(title, publisher, author){
    Book* the_book = this->searchBookByTitle(title);
    if(the_book != NULL) {
        the_book->setCopies(the_book->getCopies() + 1);
    } else {
        books_database_vector.push_back(Book(title, publisher, author));
        unsigned int length = books_database_vector.size();
        books_database_vector[length-1].setBookId(length);
    }
    return true;
}

/*
- Deletes a book only when it exists and decreaments the number of copies
- Input is a pointer to the book oject in the BookDatabase data structure.
- When number of copies of a book goes to zero that doesnot mean that the book
object or book_id will be destroyed.
*/
bool Library::deleteBook(Book* book_obj){
    if(book_obj->getCopies()!=0) {
        book_obj->setCopies(book_obj->getCopies()-1);
        return true;
    }
    cerr << "The book has already been removed!"<<endl;
    return false;
}
