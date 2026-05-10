// LAB ASSIGNMENT - 9
// Name: Nikita Giare
// Roll No: 1024150376

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

// ==========================================================
// Q1: Write Numbers 1 to 200 in NUM.TXT
// ==========================================================

void Q1() {

    ofstream fout("NUM.TXT");

    if(!fout) {

        cout << "Error Opening File!"
             << endl;

        return;
    }

    for(int i = 1; i <= 200; i++) {

        fout << i << "\n";
    }

    fout.close();

    cout << "Numbers Written Successfully in NUM.TXT"
         << endl;
}


// ==========================================================
// Q2: Count Alphabets in NOTES.TXT
// ==========================================================

void countAlphabets(string filename) {

    ifstream fin(filename);

    if(!fin) {

        cout << "Error Opening File!"
             << endl;

        return;
    }

    char ch;

    int count = 0;

    while(fin.get(ch)) {

        if(isalpha(ch)) {

            count++;
        }
    }

    fin.close();

    cout << "Total Alphabets = "
         << count << endl;
}

void Q2() {

    ofstream fout("NOTES.TXT");

    fout << "Hello World! C++ Programming 123";

    fout.close();

    countAlphabets("NOTES.TXT");
}


// ==========================================================
// Q3: Copy Contents of One File to Another
// ==========================================================

void Q3() {

    ofstream fout("source.txt");

    fout << "This is source file.\n";
    fout << "File Handling Example.";

    fout.close();

    ifstream fin("source.txt");

    ofstream fdest("destination.txt");

    if(!fin || !fdest) {

        cout << "File Error!"
             << endl;

        return;
    }

    char ch;

    while(fin.get(ch)) {

        fdest.put(ch);
    }

    fin.close();

    fdest.close();

    cout << "File Copied Successfully."
         << endl;
}


// ==========================================================
// Q4: I/O Operations on Characters
// ==========================================================

void Q4() {

    char str[200];

    cout << "Enter a String: ";

    cin.getline(str, 200);

    int length = strlen(str);

    cout << "Length of String = "
         << length << endl;

    ofstream fout("chars.txt");

    fout << str;

    fout.close();

    ifstream fin("chars.txt");

    char ch;

    cout << "Characters from File: ";

    while(fin.get(ch)) {

        cout << ch;
    }

    fin.close();

    cout << endl;
}


// ==========================================================
// Q5: seekg(), seekp(), tellg()
// ==========================================================

void Q5() {

    ofstream fout("AZ.txt");

    for(char c = 'A'; c <= 'Z'; c++) {

        fout << c;
    }

    fout.close();

    // Read 10th Character

    ifstream fin("AZ.txt");

    fin.seekg(9);

    char ch;

    fin.get(ch);

    cout << "10th Character = "
         << ch << endl;

    fin.close();

    // Replace 5th Character

    fstream f("AZ.txt", ios::in | ios::out);

    f.seekp(4);

    f.put('*');

    f.close();

    cout << "5th Character Replaced with *"
         << endl;

    // File Size

    fin.open("AZ.txt");

    fin.seekg(0, ios::end);

    cout << "File Size = "
         << fin.tellg()
         << " bytes" << endl;

    fin.close();

    // Last Character

    fin.open("AZ.txt");

    fin.seekg(-1, ios::end);

    fin.get(ch);

    cout << "Last Character = "
         << ch << endl;

    fin.close();
}


// ==========================================================
// Q6: tellp() and Random Access
// ==========================================================

void Q6() {

    ofstream fout("hello.txt");

    char text[] = "Hello World";

    cout << "Writing Characters:"
         << endl;

    for(int i = 0; text[i] != '\0'; i++) {

        fout.put(text[i]);

        cout << text[i]
             << " -> tellp() = "
             << fout.tellp()
             << endl;
    }

    fout.close();

    // Replace World with C++

    fstream f("hello.txt", ios::in | ios::out);

    f.seekp(6);

    f << "C++  ";

    f.close();

    // Read Final Content

    ifstream fin("hello.txt");

    string result;

    getline(fin, result);

    cout << "\nFinal Content: "
         << result << endl;

    fin.close();
}


// ==========================================================
// MAIN FUNCTION
// Uncomment Any Question to Run
// ==========================================================

int main() {

    // Q1();

    // Q2();

    // Q3();

    // Q4();

    // Q5();

    // Q6();

    return 0;
}
