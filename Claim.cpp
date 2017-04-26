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

    void display() {
        cout << book.getTitle() << " claimed by " << user.getName() << endl;
        if (claim_date == NULL) {
            /**
             * TODO: FacAd, search in queue to find position of current user
             * int position = ?
             * -UnstableBrainiac
             */
            string suffix;
            switch (position) {
                case 1:
                    suffix = "st";
                    break;
                case 2:
                    suffix = "nd";
                    break;
                case 3:
                    suffix = "rd";
                    break;
                default:
                    suffix = "th";
                    break;
            }
            cout << "The claim is " + position + suffix +" in the queue." << endl;
            return;
        }
        if (isValid()) {
            cout << "The claim is valid for " << (claim_date - current_date + 4) << " more days" << endl;
            return;
        }
        cout << "The claim has expired." << endl;
    }
}
