// LAB ASSIGNMENT - 5
// Name: Nikita Giare
// Roll No: 1024150376

#include <iostream>
#include <string>
using namespace std;

// Q1: Simple base and derived class

class Animal {
public:
    void eat() {
        cout << "Animal is eating food." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking." << endl;
    }
};

void q1() {

    Animal a;
    a.eat();

    Dog d;
    d.eat();
    d.bark();
}


// Q2: Protected access specifier

class Base {
protected:
    int protectedVar = 42;
};

class Derived : public Base {
public:
    void show() {
        cout << "Protected variable from Base class = "
             << protectedVar << endl;
    }
};

void q2() {

    Derived d;
    d.show();
}


// Q3: Public, Protected and Private inheritance

class Person {
public:
    string publicName = "Public";

protected:
    string protectedName = "Protected";

private:
    string privateName = "Private";
};

class PublicDerived : public Person {
public:
    void display() {
        cout << "Public: " << publicName
             << ", Protected: " << protectedName << endl;
    }
};

class ProtectedDerived : protected Person {
public:
    void display() {
        cout << "Using protected inheritance -> "
             << publicName << endl;
    }
};

class PrivateDerived : private Person {
public:
    void display() {
        cout << "Using private inheritance -> "
             << publicName << endl;
    }
};

void q3() {

    PublicDerived pd;
    pd.display();

    ProtectedDerived prd;
    prd.display();

    PrivateDerived pvd;
    pvd.display();
}


// Q4: Different types of inheritance

// Single inheritance
class Shape {
public:
    void draw() {
        cout << "Drawing shape." << endl;
    }
};

class Circle : public Shape {
public:
    void area() {
        cout << "Calculating area of circle." << endl;
    }
};


// Multiple inheritance
class Engine {
public:
    void start() {
        cout << "Engine started." << endl;
    }
};

class Wheels {
public:
    void rotate() {
        cout << "Wheels are rotating." << endl;
    }
};

class Car : public Engine, public Wheels {};


// Hierarchical inheritance
class Vehicle {
public:
    void move() {
        cout << "Vehicle is moving." << endl;
    }
};

class Bus : public Vehicle {
public:
    void passengers() {
        cout << "Bus carries passengers." << endl;
    }
};

class Bike : public Vehicle {
public:
    void ride() {
        cout << "Bike is being ridden." << endl;
    }
};


// Multilevel inheritance
class LivingBeing {
public:
    void breathe() {
        cout << "Breathing..." << endl;
    }
};

class Mammal : public LivingBeing {
public:
    void feed() {
        cout << "Mammal feeds its young ones." << endl;
    }
};

class Human : public Mammal {
public:
    void speak() {
        cout << "Human can speak." << endl;
    }
};


// Hybrid inheritance
class A {
public:
    void showA() {
        cout << "Class A" << endl;
    }
};

class B : public A {
public:
    void showB() {
        cout << "Class B" << endl;
    }
};

class C : public A {
public:
    void showC() {
        cout << "Class C" << endl;
    }
};

class D : public B, public C {
public:
    void showD() {
        cout << "Class D using hybrid inheritance." << endl;
    }
};

void q4() {

    cout << "--- Single Inheritance ---" << endl;

    Circle c;
    c.draw();
    c.area();

    cout << "\n--- Multiple Inheritance ---" << endl;

    Car car;
    car.start();
    car.rotate();

    cout << "\n--- Hierarchical Inheritance ---" << endl;

    Bus b;
    b.move();
    b.passengers();

    Bike bk;
    bk.move();
    bk.ride();

    cout << "\n--- Multilevel Inheritance ---" << endl;

    Human h;
    h.breathe();
    h.feed();
    h.speak();

    cout << "\n--- Hybrid Inheritance ---" << endl;

    D d;
    d.showB();
    d.showC();
    d.showD();
}


// Q5: Constructors and Destructors in inheritance

class BaseCD {
public:

    BaseCD() {
        cout << "Base class constructor called." << endl;
    }

    ~BaseCD() {
        cout << "Base class destructor called." << endl;
    }
};

class DerivedCD : public BaseCD {
public:

    DerivedCD() {
        cout << "Derived class constructor called." << endl;
    }

    ~DerivedCD() {
        cout << "Derived class destructor called." << endl;
    }
};

void q5() {

    DerivedCD d;
}


// Q6: Book and Textbook

class Book {
protected:
    string title, author;
    float price;

public:

    Book(string t, string a, float p) {
        title = t;
        author = a;
        price = p;
    }

    void display() {
        cout << "Title: " << title
             << "\nAuthor: " << author
             << "\nPrice: " << price << endl;
    }
};

class Textbook : public Book {
private:
    string subject;

public:

    Textbook(string t, string a, float p, string s)
        : Book(t, a, p) {

        subject = s;
    }

    void display() {

        Book::display();

        cout << "Subject: " << subject << endl;
    }
};

void q6() {

    Book b("Novel", "Author A", 299);
    b.display();

    cout << endl;

    Textbook tb("C++ Programming", "Bjarne Stroustrup", 599, "Computer Science");
    tb.display();
}


// Q7: Car dashboard

class Speedometer {
protected:
    int speed = 80;

public:
    void showSpeed() {
        cout << "Speed = " << speed << " km/h" << endl;
    }
};

class FuelGauge {
protected:
    int fuel = 60;

public:
    void showFuel() {
        cout << "Fuel Level = " << fuel << "%" << endl;
    }
};

class Thermometer {
protected:
    int temp = 90;

public:
    void showTemp() {
        cout << "Temperature = " << temp << " degree Celsius" << endl;
    }
};

class CarDashboard : public Speedometer,
                     public FuelGauge,
                     public Thermometer {

public:
    void display() {
        showSpeed();
        showFuel();
        showTemp();
    }
};

void q7() {

    CarDashboard dashboard;
    dashboard.display();
}


// Q8: Library User System

class LibraryUser {
protected:
    string name, id, contact;

public:

    LibraryUser(string n, string i, string c) {
        name = n;
        id = i;
        contact = c;
    }

    void display() {
        cout << "Name: " << name
             << "\nID: " << id
             << "\nContact: " << contact << endl;
    }
};

class Student8 : public LibraryUser {
private:
    string grade;

public:

    Student8(string n, string i, string c, string g)
        : LibraryUser(n, i, c) {

        grade = g;
    }

    void display() {

        LibraryUser::display();

        cout << "Grade: " << grade << endl;
    }
};

class Teacher : public LibraryUser {
private:
    string department;

public:

    Teacher(string n, string i, string c, string d)
        : LibraryUser(n, i, c) {

        department = d;
    }

    void display() {

        LibraryUser::display();

        cout << "Department: " << department << endl;
    }
};

void q8() {

    Student8 s("Nikita", "S001", "9999", "3rd Year");
    s.display();

    cout << endl;

    Teacher t("Dr. Sharma", "T001", "8888", "CSE");
    t.display();
}


// Q9: Multilevel inheritance example

class Vehicle9 {
protected:
    string make, model;
    int year;

public:

    Vehicle9(string mk, string mo, int y) {
        make = mk;
        model = mo;
        year = y;
    }

    void display() {
        cout << make << " " << model
             << " (" << year << ")" << endl;
    }
};

class Truck : public Vehicle9 {
protected:
    float load_capacity;

public:

    Truck(string mk, string mo, int y, float lc)
        : Vehicle9(mk, mo, y) {

        load_capacity = lc;
    }

    void display() {

        Vehicle9::display();

        cout << "Load Capacity = "
             << load_capacity << " tons" << endl;
    }
};

class RefrigeratedTruck : public Truck {
private:
    float temperature_control;

public:

    RefrigeratedTruck(string mk, string mo, int y,
                      float lc, float tc)

        : Truck(mk, mo, y, lc) {

        temperature_control = tc;
    }

    void display() {

        Truck::display();

        cout << "Temperature Control = "
             << temperature_control
             << " degree Celsius" << endl;
    }
};

void q9() {

    RefrigeratedTruck rt("Volvo", "FH16", 2022, 20, -18);

    rt.display();
}


// Q10: Hybrid inheritance example

class Person10 {
protected:
    string name, address;

public:

    Person10(string n = "", string a = "") {
        name = n;
        address = a;
    }

    void display() {
        cout << "Name: " << name
             << "\nAddress: " << address << endl;
    }
};

class Staff : virtual public Person10 {
protected:
    string emp_id, dept;

public:

    Staff(string n = "", string a = "",
          string e = "", string d = "")

        : Person10(n, a) {

        emp_id = e;
        dept = d;
    }
};

class Student10 : virtual public Person10 {
protected:
    string stu_id, grade;

public:

    Student10(string n = "", string a = "",
              string s = "", string g = "")

        : Person10(n, a) {

        stu_id = s;
        grade = g;
    }
};

class TeachingAssistant : public Staff,
                          public Student10 {

public:

    TeachingAssistant(string n, string a,
                      string e, string d,
                      string s, string g)

        : Person10(n, a),
          Staff(n, a, e, d),
          Student10(n, a, s, g) {}

    void display() {

        Person10::display();

        cout << "Employee ID: " << emp_id
             << "\nDepartment: " << dept << endl;

        cout << "Student ID: " << stu_id
             << "\nGrade: " << grade << endl;
    }
};

void q10() {

    TeachingAssistant ta(
        "Nikita",
        "LPU",
        "E101",
        "CSE",
        "S202",
        "A"
    );

    ta.display();
}


int main() {

    cout << "===== Q1: Single Inheritance =====" << endl;
    q1();

    cout << "\n===== Q2: Protected Access Specifier =====" << endl;
    q2();

    cout << "\n===== Q3: Inheritance Modes =====" << endl;
    q3();

    cout << "\n===== Q4: Types of Inheritance =====" << endl;
    q4();

    cout << "\n===== Q5: Constructor and Destructor =====" << endl;
    q5();

    cout << "\n===== Q6: Book and Textbook =====" << endl;
    q6();

    cout << "\n===== Q7: Car Dashboard =====" << endl;
    q7();

    cout << "\n===== Q8: Library User System =====" << endl;
    q8();

    cout << "\n===== Q9: Multilevel Inheritance =====" << endl;
    q9();

    cout << "\n===== Q10: Hybrid Inheritance =====" << endl;
    q10();

    return 0;
}
