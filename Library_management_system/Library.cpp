#include "Member.cpp"

// -----------------------------------------
// Library Class Definition
// -----------------------------------------
class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    bool addBook(Book& newbook) {
        for (auto& book : books) {
            if (book.getisbn() == newbook.getisbn()) {
                cout << "Invalid request! Book with same ISBN already exists" << endl;
                return false;
            }
        }
        books.push_back(newbook);
        return true;
    }

    vector<Book>& getvecbook() {
        return books;
    }

    bool registerMember(Member& mem) {
        for (auto& member : members) {
            if (member.memID == mem.memID) {
                cout << "Invalid request! Member with same ID already exists" << endl;
                return false;
            }
        }
        members.push_back(mem);
        return true;
    }

    vector<Member>& getvecmem() {
        return members;
    }

    bool borrowBook(string memberID, string isbn) {
        for (auto& book : books) {
            if (book.getisbn() == isbn) {
                if (!book.borrowBook()) return false;

                for (auto& member : members) {
                    if (member.memID == memberID) {
                        if (!member.borrowBook(isbn)) {
                            book.returnBook();
                            return false;
                        }
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool returnBook(string memberID, string isbn) {
        for (auto& book : books) {
            if (book.getisbn() == isbn) {
                if (!book.returnBook()) return false;

                for (auto& member : members) {
                    if (member.memID == memberID) {
                        if (!member.returnBook(isbn)) {
                            book.borrowBook();
                            return false;
                        }
                        return true;
                    }
                }
            }
        }
        return false;
    }

    void printLibraryDetails() {
        for (auto& book : books) {
            cout << book.title << " " << book.author << " " << book.getcopAva() << endl;
        }
        for (auto& member : members) {
            cout << member.memID << " " << member.name << endl;
        }
    }
};
