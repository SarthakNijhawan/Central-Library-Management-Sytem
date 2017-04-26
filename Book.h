class Book{
private:
	static const int STATE_AVAILABLE = 1;
	static const int STATE_ISSUED = 2;
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
	Book();
	Book(int book_id, string title, string author, string publisher, int copies, int state = 1, list<Issue> issue_list, list<Claim> claim_list);
	Book(const Book &original);
	long unsigned int getBookId();
	void setBookId(long unsigned int book_id);
	string getTitle();
	void setTitle(string title);
	string getAuthor();
	void setAuthor(string author);
	string getPublisher();
	void setPublisher(string publisher);
	int getState();
	void setState(int state);
	unsigned int getCopies();
	void setCopies(unsigned int copies);
	void updateState();
	void display();
}
