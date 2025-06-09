#include <iostream>
#include <map>
#include <vector>

using namespace std;

// -----------------------------------------
// Book Class Definition
// -----------------------------------------
class Book {
private:
    string isbn;
    int copAva;
    int totCop;

public:
    string title;
    string author;

    Book(string title, string author, string isbn, int copava, int totCop) {
        this->title = title;
        this->author = author;
        this->isbn = isbn;
        this->copAva = copava;
        this->totCop = totCop;
    }

    Book() {
        title = "UnknownTitle";
        author = "UnknownAuthor";
        isbn = "ISBN";
        copAva = 0;
        totCop = 5;
    }

    Book(Book& secbook, string newisbn) {
        title = secbook.title;
        author = secbook.author;
        isbn = newisbn;
        copAva = secbook.copAva;
        totCop = secbook.totCop;
    }

    string getisbn() {
        return isbn;
    }

    int getcopAva() {
        return copAva;
    }

    int gettotCop() {
        return totCop;
    }

    void updateCopies(int count) {
        if ((count + copAva < 0) || (count + totCop < 0)) {
            cout << "Invalid request! Count becomes negative" << endl;
            return;
        }
        copAva += count;
        totCop += count;
    }

    bool borrowBook() {
        if (copAva > 0) {
            copAva--;
            return true;
        }
        cout << "Invalid request! Copy of book not available" << endl;
        return false;
    }

    bool returnBook() {
        if (copAva >= totCop) {
            cout << "Invalid request! Copy of book exceeds total copies" << endl;
            return false;
        }
        copAva++;
        return true;
    }

    void printDetails() {
        cout << title << " " << author << endl;
    }

    friend class Library;
};
