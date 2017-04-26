#include "Issue.h"

class Issue {
    Date issue_date;
    Date due_date;
    float fine;
    Book book;
    User user;

public:
    Issue() {
        this->issue_date = NULL;
        this->due_date = NULL;
        this->fine = 0;
        this->book = NULL;
        this->user = NULL;
    }

    Issue(Date issue_date, Date due_date, float fine, Book book, User user) {
        this->issue_date = issue_date;
        this->due_date = due_date;
        this->fine = fine;
        this->book = book;
        this->user = user;
    }

    Issue(const Issue &original) {
        this->issue_date = original.issue_date;
        this->due_date = original.due_date;
        this->fine = original.fine;
        this->book = original.book;
        this->user = original.user;
    }

    Date getIssueDate() {
        return issue_date;
    }

    void setIssueDate(Date issue_date) {
        this->issue_date = issue_date;
    }

    Date getDueDate() {
        return due_date;
    }

    void setDueDate(Date due_date) {
        this->due_date = due_date;
    }

    float getFine() {
        generateFine();
        return fine;
    }

    void setFine(float fine) {
        this->fine = fine;
    }

    Book getBook() {
        return book;
    }

    void setBook(Book book) {
        this->book = book;
    }

    User getUser() {
        return user;
    }

    void setUser(User user) {
        this->user = user;
    }

    void generateFine() {
        Date current_date = Date.getInstance();
        if (current_date <= due_date)
            return;
        fine = (current_date - due_date)*5;
    }
}
