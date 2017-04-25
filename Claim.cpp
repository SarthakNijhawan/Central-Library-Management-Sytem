#include "Claim.h"

class Claim {
    Date claim_date;
    Date expiry_date;
    Book book;
    User user;

public:
    Claim() {
        this->claim_date = NULL;
        this->expiry_date = NULL;
        this->book = NULL;
        this->user = NULL;
    }

    Claim(Date claim_date, Date expiry_date, Book book, User user) {
        this->claim_date = claim_date;
        this->expiry_date = expiry_date;
        this->book = book;
        this->user = user;
    }

    Claim(const Claim &original) {
        this->claim_date = original.claim_date;
        this->expiry_date = original.expiry_date;
        this->book = original.book;
        this->user = original.user;
    }

    Date getClaimDate() {
        return claim_date;
    }

    void setClaimDate(Date claim_date) {
        this->claim_date = claim_date;
    }

    Date getExpiryDate() {
        return expiry_date;
    }

    void setExpiryDate(Date expiry_date) {
        this->expiry_date = expiry_date;
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
}
