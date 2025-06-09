# Library-Management-System

A C++ project implementing a fully functional **Library Management System** using object-oriented principles such as classes, encapsulation, constructor overloading, and constraint enforcement.

---

## Objective

Design a system that:

- Manages books and members in a library.
- Prevents duplicate book entries (by ISBN) and member entries (by ID).
- Enforces borrow/return rules and borrowing limits.
- Simulates real-world library operations via command inputs.

---

## Class Definitions

### Class: `Book`

Represents a book in the library.

#### Attributes:
- `title` (public, `string`): Title of the book
- `author` (public, `string`): Author of the book
- `isbn` (private, `string`): Unique identifier for the book
- `copiesAvailable` (private, `int`): Number of available copies
- `totalCopies` (private, `int`): Total copies of the book in the library

#### Constructors:
1. Parameterized constructor for all attributes
2. Constructor with default arguments:
   ```cpp
   Book(string title = "UnknownTitle", string author = "UnknownAuthor", string isbn = "ISBN", int copiesAvailable = 0, int totalCopies = 5);
   ```
3. Copy constructor:
   ```cpp
   Book(const Book &other, string newIsbn);
   ```

#### Methods:
- Getters: `getIsbn()`, `getCopiesAvailable()`, `getTotalCopies()`
- `void updateCopies(int count)`  
  - Increases or decreases both available and total copies.
  - Prints: `"Invalid request! Count becomes negative"` if the result is invalid.
- `bool borrowBook()`  
  - Decreases `copiesAvailable` if > 0.  
  - Prints: `"Invalid request! Copy of book not available"` if no copies are available.
- `bool returnBook()`  
  - Increases `copiesAvailable` only if it doesn't exceed `totalCopies`.  
  - Prints: `"Invalid request! Copy of book exceeds total copies"` if exceeded.
- `void printDetails()`  
  - Prints: `title author`

#### Constraints:
- No two books can have the same ISBN.
- `copiesAvailable` must always be between `0` and `totalCopies`.

---

### Class: `Member`

Represents a registered member of the library.

#### Attributes:
- `memberID` (private, `string`)
- `name` (public, `string`)
- `borrowedBooks` (private, `map<string, int>`) — maps ISBN to borrowed count
- `borrowLimit` (private, `int`) — default: `3`

#### Constructors:
1. Parameterized constructor for all attributes
2. Constructor with default `borrowLimit` of 3

#### Methods:
- `bool borrowBook(string isbn)`  
  - Fails if borrow limit is reached.  
  - Prints: `"Invalid request! Borrow limit exceeded"` if violated.
- `bool returnBook(string isbn)`  
  - Fails if member never borrowed the book.  
  - Prints: `"Invalid request! Book not borrowed"` if violated.
- `void printDetails()`  
  - For each borrowed book:  
    `memberID name isbn numberOfBorrowedCopies`  
  - If no books borrowed: **print nothing**

#### Constraints:
- Cannot borrow more than `borrowLimit`
- Can borrow the same book multiple times (if available)

---

### 🏛️ Class: `Library`

Manages collections of books and members.

#### Attributes:
- `vector<Book>` books
- `vector<Member>` members

#### Methods:
- `bool addBook(Book&)`  
  - Adds book if ISBN is unique.  
  - Prints: `"Invalid request! Book with same isbn already exists"` if violated.
- `bool registerMember(Member&)`  
  - Registers member if ID is unique.  
  - Prints: `"Invalid request! Member with same id already exists"` if violated.
- `bool borrowBook(string memberID, string isbn)`  
  - Validates availability and borrow limit in this order.
- `bool returnBook(string memberID, string isbn)`  
  - Validates return won’t exceed total copies, and if the member borrowed it.
- `void printLibraryDetails()`  
  - First prints each book:  
    `title author copiesAvailable`  
  - Then each member:  
    `memberID name`

#### Constraints:
- Max books: 50
- Max members: 150
- Max copies per book: 15
- Max books borrowed by a member at a time: 15

---

## 📥 Input Format

```
Book
<Title> <Author> <ISBN> <CopiesAvailable> <TotalCopies>

Book
None

Book
ExistingBook <OldIsbn> <NewIsbn>

UpdateCopiesCount
<Isbn> <NewCount>

Member
<MemberID> <Name> <BorrowLimit>

Member
NoBorrowLimit <MemberID> <Name>

Borrow
<MemberID> <ISBN>

Return
<MemberID> <ISBN>

PrintBook
<ISBN>

PrintMember
<MemberID>

PrintLibrary

Done
```

---

## 📤 Output Format

- Borrow Error: `"Invalid request! Copy of book not available"`
- Borrow Limit Error: `"Invalid request! Borrow limit exceeded"`
- Return Error (exceeds total): `"Invalid request! Copy of book exceeds total copies"`
- Return Error (never borrowed): `"Invalid request! Book not borrowed"`
- Duplicate Book: `"Invalid request! Book with same isbn already exists"`
- Duplicate Member: `"Invalid request! Member with same id already exists"`
- Book Print:  
  `title author`
- Member Print:  
  `memberID name isbn numberOfBorrowedCopies`
- Library Print:
  ```
  title author copiesAvailable
  ...
  memberID name
  ...
  ```

---

