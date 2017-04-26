#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<stdlib.h>
#include<vector>

// #include "Library.h"

using namespace std;

int main(){
    Library my_library("books.csv", "users.csv");

    cout<< "WELCOME THE LIBRARY !!" << endl << endl;

    while(true){

        cout<< "Please enter your UserID to proceed further !!"<<endl;
        unsigned int roll_number;
        cin >> roll_number;

        User* current_user = my_library.searchUser(roll_number);
        Book* current_book = NULL;

        if(current_user != NULL) {
            current_user->displayInfo();

            while (true) {
                displayOptions();
                int answer;
                cin>>answer;

                switch (answer) {
                    case 1:
                        current_book = searchBook();

                        if(current_book != NULL){
                            current_book->displayInfo();
                        }else {
                            cerr<< "Sorry no such book exists!"<<endl;
                        }

                        break;

                    case 2:
                        cout << "Please enter the following info : " << endl;
                        string title, publisher, author;
                        cout << "Title : ";
                        cin >> title;
                        cout << "Publisher : ";
                        cin >> publisher;
                        cout << "Author : ";
                        cin >> author;
                        if(my_library.addBook(title, publisher, author)){
                            cout << "The book is added successfully!" <<endl;
                        }
                        else {
                            cerr << "The book couldnot be added!! " << endl;
                        }
                        break;
                    case 3:
                        current_book = searchBook();

                        if(current_book != NULL) {
                            my_library.issueBook(current_book, current_book);
                            cout << "The book is issued successfully !"<< endl;
                        } else {
                            cerr<< "Sorry no such book exists!"<<endl;
                        }
                        break;

                    case 4:
                        current_book = searchBook();

                        if(current_book != NULL) {
                            my_library.deleteBook(current_book);
                            cout << "The book is deleted successfully !"<< endl;
                        } else {
                            cerr<< "Sorry no such book exists !"<<endl;
                        }
                        break;
                    case 5:
                        current_book = searchBook();

                        if(current_book != NULL) {
                            my_library.claimBook(current_book, current_book);
                            cout << "The book is claimed successfully !"<< endl;
                        } else {
                            cerr<< "Sorry no such book exists !"<<endl;
                        }
                        break;
                    case 6:
                        current_book = searchBook();

                        if(current_book != NULL) {
                            my_library.returnBook(current_book, current_book);
                            cout << "The book is returned successfully !"<< endl;
                        } else {
                            cerr<< "Sorry no such book exists !"<<endl;
                        }
                        break;
                }

            }

        }
        else {
            cout << "Sorry but the info you entered is wrong ! No such user exists !" << endl;
        }
    }

return 0;
}


void displayOptions(){

    cout << "Please select one of the following operations" << endl;
    cout << "\t1. Search a Book" << endl;
    cout << "\t2. Add a Book" << endl;
    cout << "\t3. Issue a Book" << endl;
    cout << "\t4. Remove a Book" << endl;
    cout << "\t5. Claim a Book" << endl;
    cout << "\t6. Return a Book" << endl;

}

void displaySearchOptions(){

    cout << "\t1. Title" << endl;
    cout << "\t2. Publisher" << endl;
    cout << "\t3. Author" << endl;
    cout << "\t4. BookId" << endl;
}

Book* searchBook(){
    Book* the_book;
    cout<<"Please select one of the following!" << endl;
    displaySearchOptions();
    int a; cin>>a;
    switch (a) {
        case 1:
            cout<<"Please enter the Title : " ;
            string title; cin>>title;
            the_book = my_library.searchBookByTitle(title);
            break;
        case 2:
            cout<<"Please enter the Publisher : " ;
            string publisher; cin>>publisher;
            the_book = my_library.searchBookByPublisher(publisher);
            break;
        case 3:
            cout<<"Please enter the Author : " ;
            string author; cin>>author;
            the_book = my_library.searchBookByAuthor(author);
            break;
        case 4:
            cout<<"Please enter the BookID : " ;
            unsigned int book_id; cin>>book_id;
            the_book = my_library.searchBookByBookId(book_id);
            break;
    }
    return the_book;
}
