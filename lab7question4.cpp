#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
    string address;
    string phoneNumber;
    string email;

public:
    Person(string n, int i, string addr, string phone, string em) {
        name = n;
        id = i;
        address = addr;
        phoneNumber = phone;
        email = em;
    }

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }

    void updateInfo(string addr, string phone, string em) {
        address = addr;
        phoneNumber = phone;
        email = em;
    }
};

class Student : public Person {
protected:
    string coursesEnrolled;
    double GPA;
    int enrollmentYear;

public:
    Student(string n, int i, string addr, string phone, string em,
            string courses, double gpa, int year)
        : Person(n, i, addr, phone, em) {
        coursesEnrolled = courses;
        GPA = gpa;
        enrollmentYear = year;
    }

    void displayInfo() {
        Person::displayInfo();
        cout << "Courses Enrolled: " << coursesEnrolled << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Enrollment Year: " << enrollmentYear << endl;
    }
};

class Professor : public Person {
protected:
    string department;
    string coursesTaught;
    double salary;

public:
    Professor(string n, int i, string addr, string phone, string em,
              string dept, string courses, double sal)
        : Person(n, i, addr, phone, em) {
        department = dept;
        coursesTaught = courses;
        salary = sal;
    }

    void displayInfo() {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Courses Taught: " << coursesTaught << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Staff : public Person {
protected:
    string department;
    string position;
    double salary;

public:
    Staff(string n, int i, string addr, string phone, string em,
          string dept, string pos, double sal)
        : Person(n, i, addr, phone, em) {
        department = dept;
        position = pos;
        salary = sal;
    }

    void displayInfo() {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Course {
private:
    string courseId;
    string courseName;
    int credits;
    string instructor;
    string schedule;

public:
    Course(string id, string name, int cr, string instr, string sched) {
        courseId = id;
        courseName = name;
        credits = cr;
        instructor = instr;
        schedule = sched;
    }

    void registerStudent(Student &s) {
        cout << "Student registered in course: " << courseName << endl;
    }

    void calculateGrades() {
        cout << "Grades calculated for course: " << courseName << endl;
    }

    void displayCourse() {
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Schedule: " << schedule << endl;
    }
};

int main() {
    Student s("Ali Khan", 101, "Karachi", "03001234567", "ali@email.com",
              "OOP, Data Structures", 3.6, 2023);

    Professor p("Dr. Ahmed", 201, "Karachi", "03111234567", "ahmed@email.com",
                "Computer Science", "OOP", 120000);

    Staff st("Sara Malik", 301, "Karachi", "03221234567", "sara@email.com",
             "Administration", "Coordinator", 60000);

    Course c("CS201", "Object Oriented Programming", 3, "Dr. Ahmed", "Mon-Wed 10AM");

    s.displayInfo();
    cout << endl;

    p.displayInfo();
    cout << endl;

    st.displayInfo();
    cout << endl;

    c.displayCourse();
    c.registerStudent(s);
    c.calculateGrades();

    return 0;
}
