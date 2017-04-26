#include "Claim.h"

class Claim {
    Date claim_date;
    Book book;
    User user;

public:
    Claim() {
        this->claim_date = NULL;
        this->book = NULL;
        this->user = NULL;
    }

    Claim(Date claim_date, Book book, User user) {
        this->claim_date = claim_date;
        this->book = book;
        this->user = user;
    }

    Claim(const Claim &original) {
        this->claim_date = original.claim_date;
        this->book = original.book;
        this->user = original.user;
    }

    Date getClaimDate() {
        return claim_date;
    }

    void setClaimDate(Date claim_date) {
        this->claim_date = claim_date;
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

    bool isValid() {
        Date current_date = Date.getInstance();
        if (claim_date == NULL || current_date > claim_date + 4)
            return false;
        return true;
    }
}
