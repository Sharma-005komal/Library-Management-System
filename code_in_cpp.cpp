#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    int year;

    Book(int id, string title, string author, int year)
        : id(id), title(title), author(author), year(year) {
    }
};

class LibraryManagementSystem {
private:
    vector<Book> books;

public:
    LibraryManagementSystem() {
        books = vector<Book>();
    }

    void addBook(Book book) {
        books.push_back(book);
    }

    void removeBook(int id) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].id == id) {
                books.erase(books.begin() + i);
                cout << "Book with ID " << id << " has been removed" << endl;
                break;
            }
        }
    }

    void showBooks() {
        cout << "ID\tTitle\tAuthor\tYear" << endl;
        for (Book b : books) {
            cout << b.id << "\t" << b.title << "\t" << b.author << "\t" << b.year << endl;
        }
    }
};

int main() {
    LibraryManagementSystem library = LibraryManagementSystem();
    int option = 0;

    while (option != 4) {
        cout << "1. Add book" << endl;
        cout << "2. Remove book" << endl;
        cout << "3. Show books" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter option: ";
        cin >> option;

        switch (option) {
            case 1: {
                int id;
                string title;
                string author;
                int year;

                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter year: ";
                cin >> year;

                library.addBook(Book(id, title, author, year));
                break;
            }
            case 2: {
                int id;
                cout << "Enter ID: ";
                cin >> id;
                library.removeBook(id);
                break;
            }
            case 3:
                library.showBooks();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option" << endl;
        }
    }

    return 0;
}
