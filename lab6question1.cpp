#include <iostream>
#include <string>
using namespace std;


class Book {
protected:
    string title;
    string author;
    string publisher;

public:

    Book(string t, string a, string p) {
        title = t;
        author = a;
        publisher = p;
    }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
    }
};
class FictionBook : public Book {
private:
    string genre;
    string protagonist;

public:

    FictionBook(string t, string a, string p, string g, string pr)
        : Book(t, a, p) {   
        genre = g;
        protagonist = pr;
    }


    void display() {

        Book::display();
        cout << "Genre: " << genre << endl;
        cout << "Protagonist: " << protagonist << endl;
    }
};

int main() {
   
    FictionBook book1(
        "The Mystery of the Lost Code",
        "Alex Writer",
        "TechPress",
        "Mystery",
        "Detective Byte"
    );

    
    book1.display();

    return 0;
}
