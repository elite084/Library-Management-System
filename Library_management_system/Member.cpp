#include "Book.cpp"

// -----------------------------------------
// Member Class Definition
// -----------------------------------------
class Member {
private:
    string memID;
    map<string, int> borbooks;
    int borlim;

public:
    string name;

    Member(string memID, string name) {
        this->memID = memID;
        this->name = name;
        this->borlim = 3;
    }

    Member(string memID, string name, int borlim) {
        this->memID = memID;
        this->name = name;
        this->borlim = borlim;
    }

    string getmemid() {
        return memID;
    }

    bool borrowBook(string isbn) {
        int totbor = 0;
        for (auto& borbook : borbooks) {
            totbor += borbook.second;
        }
        if (totbor < borlim) {
            borbooks[isbn]++;
            return true;
        }
        cout << "Invalid request! Borrow limit exceeded" << endl;
        return false;
    }

    bool returnBook(string isbn) {
        if ((borbooks.find(isbn) != borbooks.end()) && (borbooks[isbn] > 0)) {
            borbooks[isbn]--;
            return true;
        }
        cout << "Invalid request! Book not borrowed" << endl;
        return false;
    }

    void printDetails() {
        for (auto& borbook : borbooks) {
            if (borbook.second > 0) {
                cout << memID << " " << name << " " << borbook.first << " " << borbook.second << endl;
            }
        }
    }

    friend class Library;
};
