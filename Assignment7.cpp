// LAB ASSIGNMENT - 7
// Name: Nikita Giare
// Roll No: 1024150376

// ================= PROGRAM 1 =================
// Polygon, Rectangle and Triangle with Virtual Function

#include<iostream>
using namespace std;

class Polygon {
protected:
    int width, height;

public:
    void set_value(int w, int h) {
        width = w;
        height = h;
    }

    virtual float calculate_area() {
        return 0;
    }
};

class Rectangle1 : public Polygon {
public:
    float calculate_area() override {
        return width * height;
    }
};

class Triangle1 : public Polygon {
public:
    float calculate_area() override {
        return 0.5 * width * height;
    }
};

void program1() {
    Polygon* p;

    Rectangle1 rect;
    Triangle1 tri;

    p = &rect;
    p->set_value(10, 5);

    cout << "Rectangle Area: "
         << p->calculate_area() << endl;

    p = &tri;
    p->set_value(10, 5);

    cout << "Triangle Area: "
         << p->calculate_area() << endl;
}


// ================= PROGRAM 2 =================
// Abstract Shape Class

#include<cmath>

class Shape {
public:
    virtual float area() = 0;
    virtual void display() = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    float area() override {
        return 3.14159 * radius * radius;
    }

    void display() override {
        cout << "Circle | Radius: "
             << radius
             << " | Area: "
             << area() << endl;
    }
};

class Rectangle2 : public Shape {
    float length, breadth;

public:
    Rectangle2(float l, float b) {
        length = l;
        breadth = b;
    }

    float area() override {
        return length * breadth;
    }

    void display() override {
        cout << "Rectangle | Area: "
             << area() << endl;
    }
};

class Triangle2 : public Shape {
    float base, height;

public:
    Triangle2(float b, float h) {
        base = b;
        height = h;
    }

    float area() override {
        return 0.5 * base * height;
    }

    void display() override {
        cout << "Triangle | Area: "
             << area() << endl;
    }
};

void program2() {
    Shape* shapes[3];

    shapes[0] = new Circle(5);
    shapes[1] = new Rectangle2(4, 6);
    shapes[2] = new Triangle2(3, 8);

    for(int i = 0; i < 3; i++) {
        shapes[i]->display();
    }
}


// ================= PROGRAM 3 =================
// Triangle Area using Function Overloading

float area(float base, float height) {
    return 0.5 * base * height;
}

float area(float side) {
    return (sqrt(3) / 4) * side * side;
}

float area(float a, float b, char type) {

    float h = sqrt(a * a - (b / 2) * (b / 2));

    return 0.5 * b * h;
}

void program3() {

    cout << "Right Angle Triangle Area: "
         << area(6.0f, 4.0f) << endl;

    cout << "Equilateral Triangle Area: "
         << area(5.0f) << endl;

    cout << "Isosceles Triangle Area: "
         << area(5.0f, 6.0f, 'i') << endl;
}


// ================= PROGRAM 4 =================
// Abstract Student Class

#include<string>

class Student {
public:
    string name;

    virtual void display() = 0;
};

class Engineering : public Student {

public:
    Engineering(string n) {
        name = n;
    }

    void display() override {
        cout << "Engineering Student: "
             << name << endl;
    }
};

class Medicine : public Student {

public:
    Medicine(string n) {
        name = n;
    }

    void display() override {
        cout << "Medicine Student: "
             << name << endl;
    }
};

class Science : public Student {

public:
    Science(string n) {
        name = n;
    }

    void display() override {
        cout << "Science Student: "
             << name << endl;
    }
};

void program4() {

    Student* arr[3];

    arr[0] = new Engineering("Amit");
    arr[1] = new Medicine("Priya");
    arr[2] = new Science("Rahul");

    for(int i = 0; i < 3; i++) {
        arr[i]->display();
    }
}


// ================= PROGRAM 5 =================
// Time Class with + Operator Overloading

class Time {

    int h, m, s;

public:

    Time() {
        h = 0;
        m = 0;
        s = 0;
    }

    Time(int hr, int min, int sec) {
        h = hr;
        m = min;
        s = sec;
    }

    Time operator+(const Time& t) {

        int totalSec = s + t.s;

        int totalMin = m + t.m + totalSec / 60;

        int totalHr = h + t.h + totalMin / 60;

        return Time(totalHr,
                    totalMin % 60,
                    totalSec % 60);
    }

    void show() {

        cout << h << ":"
             << m << ":"
             << s << endl;
    }
};

void program5() {

    Time t1(5,15,34);
    Time t2(9,53,58);
    Time t3;

    t3 = t1 + t2;

    t3.show();
}


// ================= PROGRAM 6 =================
// STRING Class with == and + Overloading

#include<cstring>

class STRING {

    char str[100];

public:

    STRING() {
        str[0] = '\0';
    }

    STRING(const char* s) {
        strcpy(str, s);
    }

    bool operator==(const STRING& s) {

        return strcmp(str, s.str) == 0;
    }

    STRING operator+(const STRING& s) {

        STRING temp;

        strcpy(temp.str, str);

        strcat(temp.str, s.str);

        return temp;
    }

    void display() {

        cout << str << endl;
    }
};

void program6() {

    STRING s1("Hello ");
    STRING s2("World");
    STRING s3;

    s3 = s1 + s2;

    cout << "Concatenated String: ";

    s3.display();

    if(s1 == s2) {
        cout << "Strings are equal" << endl;
    }

    else {
        cout << "Strings are not equal" << endl;
    }
}


// ================= MAIN FUNCTION =================

int main() {

    cout << "\nPROGRAM 1\n";
    program1();

    cout << "\nPROGRAM 2\n";
    program2();

    cout << "\nPROGRAM 3\n";
    program3();

    cout << "\nPROGRAM 4\n";
    program4();

    cout << "\nPROGRAM 5\n";
    program5();

    cout << "\nPROGRAM 6\n";
    program6();

    return 0;
}
