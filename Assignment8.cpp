// LAB ASSIGNMENT - 8
// Name: Nikita Giare
// Roll No: 1024150376

#include <iostream>
#include <string>

using namespace std;

// ==================================================
// Q1. Function Template to Swap Two Variables
// ==================================================

template <typename T>

void swapValues(T &a, T &b) {

    T temp = a;

    a = b;

    b = temp;
}

void question1() {

    cout << "\n===== Q1: Swap Function Template =====\n";

    int x = 10;
    int y = 20;

    cout << "Before Swap: x = "
         << x
         << ", y = "
         << y << endl;

    swapValues(x, y);

    cout << "After Swap: x = "
         << x
         << ", y = "
         << y << endl;
}


// ==================================================
// Q2. Function Template to Find Minimum Element
// ==================================================

template <typename T>

T findMinimum(T arr[], int size) {

    T minimum = arr[0];

    for(int i = 1; i < size; i++) {

        if(arr[i] < minimum) {
            minimum = arr[i];
        }
    }

    return minimum;
}

void question2() {

    cout << "\n===== Q2: Find Minimum =====\n";

    int arr[] = {5, 3, 8, 1, 9};

    cout << "Minimum Element = "
         << findMinimum(arr, 5)
         << endl;
}


// ==================================================
// Q3. Bubble Sort Template
// ==================================================

template <typename T>

void bubbleSort(T arr[], int size) {

    for(int i = 0; i < size - 1; i++) {

        for(int j = 0; j < size - i - 1; j++) {

            if(arr[j] > arr[j + 1]) {

                T temp = arr[j];

                arr[j] = arr[j + 1];

                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>

void printArray(T arr[], int size) {

    for(int i = 0; i < size; i++) {

        cout << arr[i] << " ";
    }

    cout << endl;
}

void question3() {

    cout << "\n===== Q3: Bubble Sort =====\n";

    int arr[] = {64, 34, 25, 12, 22};

    cout << "Before Sorting: ";

    printArray(arr, 5);

    bubbleSort(arr, 5);

    cout << "After Sorting: ";

    printArray(arr, 5);
}


// ==================================================
// Q4. Linear Search Template
// ==================================================

template <typename T>

int linearSearch(T arr[], int size, T key) {

    for(int i = 0; i < size; i++) {

        if(arr[i] == key) {
            return i;
        }
    }

    return -1;
}

void question4() {

    cout << "\n===== Q4: Linear Search =====\n";

    int arr[] = {10, 20, 30, 40, 50};

    int index = linearSearch(arr, 5, 30);

    if(index != -1) {

        cout << "Element Found at Index "
             << index << endl;
    }

    else {

        cout << "Element Not Found"
             << endl;
    }
}


// ==================================================
// Q5. Overloaded Function Templates
// ==================================================

template <typename T>

void process(T a) {

    cout << "Single Parameter: "
         << a << endl;
}

template <typename T>

void process(T a, T b) {

    cout << "Same Type Parameters: "
         << a
         << " and "
         << b << endl;
}

template <typename T1, typename T2>

void process(T1 a, T2 b) {

    cout << "Different Type Parameters: "
         << a
         << " and "
         << b << endl;
}

void question5() {

    cout << "\n===== Q5: Overloaded Templates =====\n";

    process(10);

    process(10, 20);

    process(10, 3.14);
}


// ==================================================
// Q6. Stack Class Template
// ==================================================

template <typename T>

class Stack {

    T arr[100];

    int top;

public:

    Stack() {

        top = -1;
    }

    void push(T value) {

        arr[++top] = value;
    }

    void pop() {

        cout << arr[top--]
             << " popped"
             << endl;
    }

    void display() {

        for(int i = top; i >= 0; i--) {

            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

void question6() {

    cout << "\n===== Q6: Stack Template =====\n";

    Stack<int> s;

    s.push(10);

    s.push(20);

    s.push(30);

    s.display();

    s.pop();

    s.display();
}


// ==================================================
// Q7. Queue Class Template
// ==================================================

template <typename T>

class Queue {

    T arr[100];

    int front, rear;

public:

    Queue() {

        front = 0;

        rear = -1;
    }

    void enqueue(T value) {

        arr[++rear] = value;
    }

    void dequeue() {

        cout << arr[front++]
             << " dequeued"
             << endl;
    }

    void display() {

        for(int i = front; i <= rear; i++) {

            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

void question7() {

    cout << "\n===== Q7: Queue Template =====\n";

    Queue<int> q;

    q.enqueue(10);

    q.enqueue(20);

    q.enqueue(30);

    q.display();

    q.dequeue();

    q.display();
}


// ==================================================
// Q8. Pair Class Template
// ==================================================

template <typename T1, typename T2>

class Pair {

    T1 first;

    T2 second;

public:

    Pair(T1 a, T2 b) {

        first = a;

        second = b;
    }

    void display() {

        cout << "("
             << first
             << ", "
             << second
             << ")"
             << endl;
    }
};

void question8() {

    cout << "\n===== Q8: Pair Template =====\n";

    Pair<int, int> p1(10, 20);

    p1.display();

    Pair<string, int> p2("Age", 21);

    p2.display();
}


// ==================================================
// Q9. Calculator Class Template
// ==================================================

template <typename T>

class Calculator {

    T a, b;

public:

    Calculator(T x, T y) {

        a = x;

        b = y;
    }

    void display() {

        cout << "Addition: "
             << a + b << endl;

        cout << "Subtraction: "
             << a - b << endl;

        cout << "Multiplication: "
             << a * b << endl;

        cout << "Division: "
             << a / b << endl;
    }
};

void question9() {

    cout << "\n===== Q9: Calculator Template =====\n";

    Calculator<int> c(10, 2);

    c.display();
}


// ==================================================
// Q10. Array Class Template
// ==================================================

template <typename T>

class Array {

    T arr[100];

    int size;

public:

    Array(int s) {

        size = s;
    }

    void input() {

        for(int i = 0; i < size; i++) {

            cin >> arr[i];
        }
    }

    void display() {

        for(int i = 0; i < size; i++) {

            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

void question10() {

    cout << "\n===== Q10: Array Template =====\n";

    Array<int> a(5);

    cout << "Enter 5 Elements:\n";

    a.input();

    cout << "Array Elements: ";

    a.display();
}


// ==================================================
// MAIN FUNCTION
// ==================================================

int main() {

    question1();

    question2();

    question3();

    question4();

    question5();

    question6();

    question7();

    question8();

    question9();

    question10();

    return 0;
}
