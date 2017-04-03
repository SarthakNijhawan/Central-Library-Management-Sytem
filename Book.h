#include"String.h"

class Book{
	
	Book();
	Book(int accountnumber, int volumes, string title, string author, string publisher);
	Book(const Book &original);
	long unsigned int getAccountNumber();
	void setAccountNumber(long unsigned int accountnumber);
	unsigned int getVolumes();
	void setVolumes(unsigned int volumes);
	void increamentVolumes();
	string getTitle();
	void setTitle(string title);
	string getAuthor();
	void setAuthor(string author);
	string getPublisher();
	void setPublisher(string publisher);
	int getState();
	void setState(int state);

	void displayInfo();
};
