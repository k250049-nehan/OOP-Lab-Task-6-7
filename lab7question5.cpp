#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title;
    string publicationDate;
    int uniqueID;
    string publisher;

public:
    Media(string t, string pDate, int id, string pub) {
        title = t;
        publicationDate = pDate;
        uniqueID = id;
        publisher = pub;
    }

    virtual void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
    }

    void checkOut() {
        cout << title << " has been checked out." << endl;
    }

    void returnItem() {
        cout << title << " has been returned." << endl;
    }

    string getTitle() { return title; }
    string getPublicationDate() { return publicationDate; }
};

class Book : public Media {
private:
    string author;
    string ISBN;
    int numberOfPages;

public:
    Book(string t, string pDate, int id, string pub, string a, string isbn, int pages)
        : Media(t, pDate, id, pub) {
        author = a;
        ISBN = isbn;
        numberOfPages = pages;
    }

    string getAuthor() { return author; }

    void displayInfo() {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Pages: " << numberOfPages << endl;
    }
};

class DVD : public Media {
private:
    string director;
    int duration;
    string rating;

public:
    DVD(string t, string pDate, int id, string pub, string dir, int dur, string rate)
        : Media(t, pDate, id, pub) {
        director = dir;
        duration = dur;
        rating = rate;
    }

    void displayInfo() {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Rating: " << rating << endl;
    }
};

class CD : public Media {
private:
    string artist;
    int numberOfTracks;
    string genre;

public:
    CD(string t, string pDate, int id, string pub, string ar, int tracks, string g)
        : Media(t, pDate, id, pub) {
        artist = ar;
        numberOfTracks = tracks;
        genre = g;
    }

    void displayInfo() {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }
};

class Magazine : public Media {
private:
    int issueNumber;
    string category;

public:
    Magazine(string t, string pDate, int id, string pub, int issue, string cat)
        : Media(t, pDate, id, pub) {
        issueNumber = issue;
        category = cat;
    }

    void displayInfo() {
        Media::displayInfo();
        cout << "Issue Number: " << issueNumber << endl;
        cout << "Category: " << category << endl;
    }
};

class Library {
public:
    void searchMedia(Media items[], int size, string title) {
        for (int i = 0; i < size; i++) {
            if (items[i].getTitle() == title) {
                items[i].displayInfo();
            }
        }
    }

    void searchMedia(Book books[], int size, string author) {
        for (int i = 0; i < size; i++) {
            if (books[i].getAuthor() == author) {
                books[i].displayInfo();
            }
        }
    }

    void searchMedia(Media items[], int size, int year) {
        for (int i = 0; i < size; i++) {
            if (items[i].getPublicationDate().find(to_string(year)) != string::npos) {
                items[i].displayInfo();
            }
        }
    }
};

int main() {
    Book b("C++ Programming", "2020", 101, "TechPress", "Bjarne Stroustrup", "123456789", 900);
    DVD d("Inception", "2010", 201, "Warner Bros", "Christopher Nolan", 148, "PG-13");
    CD c("Thriller", "1982", 301, "Epic Records", "Michael Jackson", 9, "Pop");
    Magazine m("National Geographic", "2023", 401, "NatGeo", 12, "Science");

    b.displayInfo();
    cout << endl;
    d.displayInfo();
    cout << endl;
    c.displayInfo();
    cout << endl;
    m.displayInfo();
    cout << endl;

    b.checkOut();
    b.returnItem();

    return 0;
}
