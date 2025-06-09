#include "Library.cpp"
// -----------------------------------------
// Main Function
// -----------------------------------------
int main() {
    Library lib;
    string entity;

    while (cin >> entity && entity != "Done") {
        if (entity == "Book") {
            string b;
            cin >> b;

            if (b != "None" && b != "ExistingBook") {
                string author, isbn;
                int copAva, totCop;
                cin >> author >> isbn >> copAva >> totCop;
                Book b1(b, author, isbn, copAva, totCop);
                lib.addBook(b1);
            } else if (b == "ExistingBook") {
                string oldisbn, newisbn;
                cin >> oldisbn >> newisbn;
                vector<Book>& vecbook = lib.getvecbook();
                for (auto& book : vecbook) {
                    if (book.getisbn() == oldisbn) {
                        Book b1(book, newisbn);
                        lib.addBook(b1);
                    }
                }
            } else if (b == "None") {
                Book b1;
                lib.addBook(b1);
            }
        }

        else if (entity == "Member") {
            string m;
            cin >> m;

            if (m != "NoBorrowLimit") {
                string name;
                int blim;
                cin >> name >> blim;
                Member m1(m, name, blim);
                lib.registerMember(m1);
            } else {
                string mid, name;
                cin >> mid >> name;
                Member m1(mid, name);
                lib.registerMember(m1);
            }
        }

        else if (entity == "UpdateCopiesCount") {
            string isbn;
            int newCount;
            cin >> isbn >> newCount;
            vector<Book>& vecbook = lib.getvecbook();
            for (auto& book : vecbook) {
                if (book.getisbn() == isbn) {
                    book.updateCopies(newCount);
                }
            }
        }

        else if (entity == "Borrow") {
            string memid, isbn;
            cin >> memid >> isbn;
            lib.borrowBook(memid, isbn);
        }

        else if (entity == "Return") {
            string memid, isbn;
            cin >> memid >> isbn;
            lib.returnBook(memid, isbn);
        }

        else if (entity == "PrintBook") {
            string isbn;
            cin >> isbn;
            vector<Book>& vecbook = lib.getvecbook();
            for (auto& book : vecbook) {
                if (book.getisbn() == isbn) {
                    book.printDetails();
                }
            }
        }

        else if (entity == "PrintMember") {
            string memid;
            cin >> memid;
            vector<Member>& vecmem = lib.getvecmem();
            for (auto& member : vecmem) {
                if (memid == member.getmemid()) {
                    member.printDetails();
                }
            }
        }

        else if (entity == "PrintLibrary") {
            lib.printLibraryDetails();
        }
    }
    return 0;
}
