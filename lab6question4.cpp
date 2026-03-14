#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
protected:
    int studentID;
    int gradeLevel;

public:
    Student(string n, int a, int id, int grade) : Person(n, a) {
        studentID = id;
        gradeLevel = grade;
    }

    void displayStudent() {
        cout << "Student ID: " << studentID << endl;
        cout << "Grade Level: " << gradeLevel << endl;
    }
};

class Teacher : public Person {
protected:
    string subject;
    int roomNumber;

public:
    Teacher(string n, int a, string sub, int room) : Person(n, a) {
        subject = sub;
        roomNumber = room;
    }

    void displayTeacher() {
        cout << "Subject: " << subject << endl;
        cout << "Room Number: " << roomNumber << endl;
    }
};

class GraduateStudent : public Student, public Teacher {
public:
    GraduateStudent(string n, int a, int id, int grade, string sub, int room)
        : Student(n, a, id, grade), Teacher(n, a, sub, room) {}

    void display() {
        cout << "Graduate Student Details:" << endl;
        Student::displayPerson();
        displayStudent();
        displayTeacher();
    }
};

int main() {
    GraduateStudent g("Ali", 24, 1023, 4, "Computer Science", 205);
    g.display();
    return 0;
}
