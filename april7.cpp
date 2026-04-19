#include <iostream>
#define SIZE 20
using namespace std;

class Student{
public:
    string name;
    int rollno;
    string faculty;

    Student(string n, int r, string f){
        name = n;
        rollno = r;
        faculty = f;
    }

    void display(){
        cout << "Name: " << name
             << ", Roll No: " << rollno
             << ", Faculty: " << faculty << endl;
    }
};

class HashTable{
public:
    Student* s[SIZE];

    HashTable(){
        for(int i = 0; i < SIZE; i++){
            s[i] = NULL;
        }
    }

    int hashfxn(Student std){
        return std.rollno % SIZE;
    }

    void insert(Student std){
        int hash = hashfxn(std);
        if(s[hash] == NULL){
            s[hash] = &std;
        }else{
            cout << "Cannot insert new student as the location is already occupied .. ";
        }
    }
};
