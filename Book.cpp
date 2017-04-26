#include"Book.h"

class Book {
	/**
     * Value of the #state field indicating
     * available.
	 * The state of the book when
	 * atleast one copy of the book
	 * is available with the library.
     */
	static const int STATE_AVAILABLE = 1;
	/**
     * Value of the #state field indicating
     * issued.
     * The state of the book when
	 * all the copies are issued
	 * but there are no claims on the book.
     */
	static const int STATE_ISSUED = 2;
	/**
     * Value of the #state field indicating
     * claimed.
	 * The state of the book when
	 * there is atleast one claim on the book
	 * after all the copies have been issued.
     */
	static const int STATE_CLAIMED = 3;

	long unsigned int book_id;
	int state;
	unsigned int copies;
	string title;
	string author;
	string publisher;

	list<Issue> issue_list;
	list<Claim> claim_list;

public:
	/**
	 * Default constructor
	 */
	Book() {
		this->book_id = 0;
		this->copies = 0;
		this->title = "";
		this->author = "";
		this->publisher = "";
	}

	/**
	 * Parameterized constructor
	 * @param book_id The unique ID given to each book in the library
	 * @param title The title of the book
	 * @param author The name of the author of the book
	 * @param publisher The name of the publisher of the book
	 * @param copies The number of copies of the book
	 * @param state The current state of the book
	 * @param issue_list List of issue objects associated with the book
	 * @param claim_list List of claim objects associated with the book
	 */
	Book(int book_id, string title, string author, string publisher, int copies, int state = 1, list<Issue> issue_list, list<Claim> claim_list) {
		this->book_id = book_id;
		this->title = title;
		this->author = author;
		this->publisher = publisher;
		this->copies = copies;
	}

	/**
	 * Copy constructor
	 * @param original The book object to make a copy of
	 */
	Book(const Book &original) {
		this->book_id = original.book_id;
		this->title = original.title;
		this->author = original.author;
		this->publisher = original.publisher;
		this->copies = original.copies;
		this->state = original.state;
		this->issue_list = original.issue_list;
		this->claim_list = original.claim_list;
	}

	/**
	 * Returns the ID of the book
	 * @return book ID
	 */
	long unsigned int getBookId() {
		return book_id;
	}

	/**
	 * Changes the ID of the book
	 * @param book_id The new ID that is to be set
	 */
	void setBookId(long unsigned int book_id) {
		this->book_id = book_id;
	}

	/**
	 * Returns the title of the book
	 * @return book title
	 */
	string getTitle() {
		return this->title;
	}

	/**
	 * Changes the title of the book
	 * @param title The new title that is to be set
	 */
	void setTitle(string title) {
		this->title = title;
	}

	/**
	 * Returns the name of the author of the book
	 * @return book author name
	 */
	string getAuthor() {
		return this->author;
	}

	/**
	 * Changes the name of the author of the book
	 * @param author The new author name that is to be set
	 */
	void setAuthor(string author) {
		this->author = author;
	}

	/**
	 * Returns the name of the publisher of the book
	 * @return book publisher
	 */
	string getPublisher() {
		return publisher;
	}

	/**
	 * Changes the name of the publisher of the book
	 * @param publisher The new publisher name that is to be set
	 */
	void setPublisher(string publisher) {
		this->publisher = publisher;
	}

	/**
	 * Returns the current state of the book which is updated each time the function is called
	 * @return state
	 */
	int getState() {
		this->updateState();
		return state;
	}

	/**
	 * Changes the current state of the book
	 * @param state The new state that is to be set
	 */
	void setState(int state) {
		this->state = state;
	}

	/**
	 * Returns the number of copies of the book
	 * @return number of copies
	 */
	unsigned int getCopies(){
		return copies;
	}

	/**
	 * Changes the number of copies of the book
	 * @param publisher The new number of copies that is to be set
	 */
	void setCopies(int copies){
		this->copies = copies;
	}

	/**
	 * Returns the list of issue objects associated with the book
	 * @return issue list
	 */
	list<Issue> getIssueList(){
		return issue_list;
	}

	/**
	 * Changes the list of issue objects associated with the book
	 * @param issue_list The new list that is to be set
	 */
	void setIssueList(List<Issue> issue_list){
		this->issue_list = issue_list;
	}

	/**
	 * Returns the list of claim objects associated with the book
	 * @return claim list
	 */
	list<Claim> getClaimList(){
		return claim_list;
	}

	/**
	 * Changes the list of claim objects associated with the book
	 * @param claim_list The new list that is to be set
	 */
	void setClaimList(List<Claim> claim_list){
		this->claim_list = claim_list;
	}

	void updateState() {
		if(!claim_list.empty()) {
			this->state = STATE_CLAIMED;
		}
		else {
			if(issue_list.size() < this->copies) {
				this->state = STATE_AVAILABLE;
			}
			else(issue_list.size() == this->copies) {
				this->state = STATE_ISSUED;
			}
		}
	}

	void display() {
		cout << book_id << " : " << title << endl;
		cout << "Written by: " << author << endl;
		cout << "Published by: " << publisher << endl;
		cout << "Total number of copies: " << copies << endl;
		switch (state) {
			case STATE_AVAILABLE:
				cout << (copies - issue_list.size()) " copies are available.";
				if (issue_list.empty)
					break;
			case STATE_ISSUED:
				list<Issue>::iterator it = this->issue_list.begin();
				cout << "Users who have issued this book:" << endl;
				while (it != this->issue_list.end()) {
					it->display();
				}
				break;
			case STATE_CLAIMED:
				list<Issue>::iterator it = this->issue_list.begin();
				cout << "Users who have issued this book:" << endl;
				while (it != this->issue_list.end()) {
					it->display();
				}
				list<Claim>::iterator it = this->claim_list.begin();
				cout << "Users who have claimed this book:" << endl;
				while (it != this->issue_list.end()) {
					it->display();
				}
				break;
		}
	}
}
