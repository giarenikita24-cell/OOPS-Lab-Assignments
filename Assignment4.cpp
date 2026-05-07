// LAB ASSIGNMENT - 4
// Name: Nikita Giare
// Roll No: 1024150376

#include <iostream>
using namespace std;

// Q1: Rectangle class using different constructors

class Rectangle {
private:
    float length, breadth;

public:

    // Default constructor
    Rectangle() {
        length = 1;
        breadth = 1;
    }

    // Constructor with one argument
    Rectangle(float side) {
        length = side;
        breadth = side;
    }

    // Constructor with two arguments
    Rectangle(float l, float b) {
        length = l;
        breadth = b;
    }

    float calculateArea() {
        return length * breadth;
    }

    void showArea() {
        cout << "Area = " << calculateArea() << endl;
    }
};

void q1() {

    Rectangle r1;
    Rectangle r2(5);
    Rectangle r3(4, 6);

    cout << "Rectangle using default constructor: ";
    r1.showArea();

    cout << "Rectangle using one parameter: ";
    r2.showArea();

    cout << "Rectangle using two parameters: ";
    r3.showArea();
}


// Q2: Array of objects with default arguments and destructor

class RectArray {
private:
    float length, breadth;

public:

    RectArray(float l = 2, float b = 3) {
        length = l;
        breadth = b;

        cout << "Object created with length = "
             << length << " and breadth = "
             << breadth << endl;
    }

    ~RectArray() {
        cout << "Object destroyed with length = "
             << length << " and breadth = "
             << breadth << endl;
    }

    float area() {
        return length * breadth;
    }
};

void q2() {

    RectArray rect[3] = {
        RectArray(),
        RectArray(5),
        RectArray(4,7)
    };

    for(int i = 0; i < 3; i++) {
        cout << "Area of rectangle "
             << i + 1 << " = "
             << rect[i].area() << endl;
    }
}


// Q3: Destructor properties

class Demo {
private:
    int id;

public:

    Demo(int n) {
        id = n;
        cout << "Constructor called for object "
             << id << endl;
    }

    ~Demo() {
        cout << "Destructor called for object "
             << id << endl;
    }
};

void q3() {

    {
        Demo d1(1);
        Demo d2(2);
        Demo d3(3);

        cout << "Objects are inside the block." << endl;
    }

    cout << "Objects destroyed after block execution." << endl;
}


// Q4: Dynamic memory allocation

class Sample {
public:
    int value;

    Sample() {
        value = 0;
        cout << "Default object created." << endl;
    }

    Sample(int v) {
        value = v;
        cout << "Object created with value = "
             << value << endl;
    }

    ~Sample() {
        cout << "Object with value "
             << value << " destroyed." << endl;
    }
};

void q4() {

    // Dynamic integer
    int *ptrInt = new int(42);

    cout << "Dynamic integer value = "
         << *ptrInt << endl;

    delete ptrInt;


    // Dynamic float
    float *ptrFloat = new float(3.14);

    cout << "Dynamic float value = "
         << *ptrFloat << endl;

    delete ptrFloat;


    // Dynamic integer array
    int *arrInt = new int[4]{10,20,30,40};

    cout << "Integer array values: ";

    for(int i = 0; i < 4; i++) {
        cout << arrInt[i] << " ";
    }

    cout << endl;

    delete[] arrInt;


    // Dynamic float array
    float *arrFloat = new float[3]{1.1,2.2,3.3};

    cout << "Float array values: ";

    for(int i = 0; i < 3; i++) {
        cout << arrFloat[i] << " ";
    }

    cout << endl;

    delete[] arrFloat;


    // Dynamic object
    Sample *obj = new Sample(99);

    cout << "Object value = "
         << obj->value << endl;

    delete obj;


    // Array of objects
    Sample *objArray = new Sample[2];

    objArray[0].value = 10;
    objArray[1].value = 20;

    cout << "Values in object array = "
         << objArray[0].value << " and "
         << objArray[1].value << endl;

    delete[] objArray;
}


int main() {

    cout << "===== Q1: Constructors in Rectangle =====" << endl;
    q1();

    cout << "\n===== Q2: Array of Objects and Destructor =====" << endl;
    q2();

    cout << "\n===== Q3: Destructor Demonstration =====" << endl;
    q3();

    cout << "\n===== Q4: Dynamic Memory Allocation =====" << endl;
    q4();

    return 0;
}
