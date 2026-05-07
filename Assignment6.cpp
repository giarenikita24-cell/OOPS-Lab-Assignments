// LAB ASSIGNMENT - 6
// Name: Nikita Giare
// Roll No: 1024150376

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// =====================================================
// Q1: Library Class using array of Book objects
// =====================================================

class Book {
public:
    string title;
    string author;
    string ISBN;

    Book(string t = "", string a = "", string i = "") {
        title = t;
        author = a;
        ISBN = i;
    }
};

class Library {

private:
    Book books[100];
    int count = 0;

public:

    bool addNewBook(string title, string author, string ISBN) {

        if(count >= 100) {
            return false;
        }

        books[count] = Book(title, author, ISBN);
        count++;

        return true;
    }

    bool removeBooks(string ISBN) {

        for(int i = 0; i < count; i++) {

            if(books[i].ISBN == ISBN) {

                for(int j = i; j < count - 1; j++) {
                    books[j] = books[j + 1];
                }

                count--;
                return true;
            }
        }

        return false;
    }

    void displayDetails() {

        cout << "\nBooks available in library:\n" << endl;

        for(int i = 0; i < count; i++) {

            cout << i + 1 << ". "
                 << books[i].title
                 << " by "
                 << books[i].author
                 << " (ISBN: "
                 << books[i].ISBN
                 << ")" << endl;
        }
    }
};

void q1() {

    Library lib;

    lib.addNewBook("C++ Primer", "Lippman", "ISBN001");
    lib.addNewBook("Clean Code", "Robert Martin", "ISBN002");
    lib.addNewBook("OOPS Concepts", "Balaguruswamy", "ISBN003");
    lib.addNewBook("Design Patterns", "Gang of Four", "ISBN004");
    lib.addNewBook("The Pragmatic Programmer", "Andrew Hunt", "ISBN005");

    lib.displayDetails();

    cout << "\nRemoving book with ISBN002..." << endl;

    lib.removeBooks("ISBN002");

    lib.displayDetails();
}


// =====================================================
// Q2: Book class with constructors and this pointer
// =====================================================

class Book2 {

private:
    string title;
    string author;
    string ISBN;

public:

    // Default constructor
    Book2() {
        this->title = "";
        this->author = "";
        this->ISBN = "";
    }

    // Parameterized constructor
    Book2(string title, string author, string ISBN) {

        this->title = title;
        this->author = author;
        this->ISBN = ISBN;
    }

    // Copy constructor
    Book2(const Book2 &b) {

        this->title = b.title;
        this->author = b.author;
        this->ISBN = b.ISBN;
    }

    void displayDetails() {

        cout << title
             << " | "
             << author
             << " | "
             << ISBN << endl;
    }
};

void q2() {

    Book2 arr1[3] = {

        Book2("C++ Primer", "Lippman", "A01"),
        Book2("Clean Code", "Martin", "A02"),
        Book2("OOPS Concepts", "Balaguruswamy", "A03")
    };

    cout << "\nBooks using initializer list:\n" << endl;

    for(int i = 0; i < 3; i++) {
        arr1[i].displayDetails();
    }


    Book2 *arr2 = new Book2[3];

    arr2[0] = Book2("Design Patterns", "GOF", "B01");
    arr2[1] = Book2("Refactoring", "Martin Fowler", "B02");
    arr2[2] = Book2("The Pragmatic Programmer", "Hunt", "B03");

    cout << "\nBooks using dynamic initialization:\n" << endl;

    for(int i = 0; i < 3; i++) {
        arr2[i].displayDetails();
    }

    delete[] arr2;
}


// =====================================================
// Q3: Account Class
// =====================================================

class Account {

private:
    const long accountNumber;

    long transactionID;
    string transactionType;
    double balance;

public:

    Account(long accNo, double initialBalance)
        : accountNumber(accNo),
          balance(initialBalance),
          transactionID(1000) {}

    long depositAmount(const long to,
                       const long from,
                       const double amount) {

        if(accountNumber == to) {

            balance += amount;
            transactionType = "Amount Credited";
        }

        transactionID++;

        cout << "Deposit Transaction ID: "
             << transactionID << endl;

        return transactionID;
    }

    long creditAmount(const long to,
                      const long from,
                      const double amount) {

        if(accountNumber == from) {

            balance -= amount;
            transactionType = "Amount Debited";
        }

        transactionID++;

        cout << "Debit Transaction ID: "
             << transactionID << endl;

        return transactionID;
    }

    void displayDetails() const {

        cout << "Account Number: "
             << accountNumber
             << "\nBalance: "
             << balance
             << "\nLast Transaction: "
             << transactionType
             << "\n" << endl;
    }
};

void q3() {

    Account accounts[5] = {

        Account(1001, 5000),
        Account(1002, 3000),
        Account(1003, 7000),
        Account(1004, 2000),
        Account(1005, 9000)
    };

    accounts[0].depositAmount(1001, 1002, 500);
    accounts[1].creditAmount(1001, 1002, 500);

    accounts[2].depositAmount(1003, 1004, 1500);

    cout << "\nAccount Details:\n" << endl;

    for(int i = 0; i < 5; i++) {
        accounts[i].displayDetails();
    }
}


// =====================================================
// Q4: Friend function using two classes
// =====================================================

class ClassP;

class ClassQ {

    int q;

public:

    ClassQ(int val) {
        q = val;
    }

    friend int addTwoClasses(ClassP, ClassQ);
};

class ClassP {

    int p;

public:

    ClassP(int val) {
        p = val;
    }

    friend int addTwoClasses(ClassP, ClassQ);
};

int addTwoClasses(ClassP a, ClassQ b) {

    return a.p + b.q;
}

void q4() {

    ClassP p(30);
    ClassQ q(70);

    cout << "Sum of two class objects = "
         << addTwoClasses(p, q) << endl;
}


// =====================================================
// Q5: Complex Number Class
// =====================================================

class Complex {

private:
    float real;
    float imaginary;

public:

    Complex(float r = 0, float i = 0) {

        real = r;
        imaginary = i;
    }

    // Copy constructor
    Complex(const Complex &c) {

        real = c.real;
        imaginary = c.imaginary;
    }

    void display() {

        if(imaginary >= 0) {

            cout << real
                 << " + "
                 << imaginary
                 << "i" << endl;
        }

        else {

            cout << real
                 << " - "
                 << abs(imaginary)
                 << "i" << endl;
        }
    }

    friend void sum(Complex c1, Complex c2);
};

void sum(Complex c1, Complex c2) {

    Complex result(
        c1.real + c2.real,
        c1.imaginary + c2.imaginary
    );

    cout << "Sum = ";
    result.display();
}

void q5() {

    Complex c1(3.5, 2.0);
    Complex c2(1.5, -1.0);

    cout << "Complex Number 1: ";
    c1.display();

    cout << "Complex Number 2: ";
    c2.display();

    sum(c1, c2);

    Complex c3(c1);

    cout << "Copied Complex Number: ";
    c3.display();
}


// =====================================================
// Main Function
// =====================================================

int main() {

    cout << "========== Q1: Library Class ==========" << endl;
    q1();

    cout << "\n========== Q2: Constructors and this Pointer ==========" << endl;
    q2();

    cout << "\n========== Q3: Account Class ==========" << endl;
    q3();

    cout << "\n========== Q4: Friend Function ==========" << endl;
    q4();

    cout << "\n========== Q5: Complex Number Class ==========" << endl;
    q5();

    return 0;
}
