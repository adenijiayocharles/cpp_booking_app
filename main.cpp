// bookstore application
#include <iostream>
#include <fstream>
#include <filesystem>

using std::filesystem::current_path;
std::string currentDirectory = current_path();

class BookStore
{
private:
public:
    BookStore()
    {
        std::cout << "================================" << std::endl;
        std::cout << "Welcome to the Panache Bookstore" << std::endl;
        std::cout << "================================" << std::endl;
        std::cout << std::endl;
        showMenu();
    }

    void showMenu()
    {
        std::cout << "This is the menu options available to run this bookstore" << std::endl;
        std::cout << "Enter 1 to view all books" << std::endl;
        std::cout << "Enter 2 to add a new book to the store" << std::endl;
        std::cout << "Enter 3 to delete a book from the store" << std::endl;
        std::cout << "Enter 4 to update a book from the store" << std::endl;
        std::cout << "=======================================" << std::endl;
    }

    void showBook() {}
    void addBook()
    {
        std::cout << "=======================================" << std::endl;
        std::cout << "Enter the book details" << std::endl;

        std::string bookName;
        std::string bookAuthor;
        double bookPrice;
        int quantity;

        std::cout << "Enter the book name: ";
        std::getline(std::cin, bookName);

        std::cout << "Enter the author's name: ";
        std::getline(std::cin, bookAuthor);

        std::cout << "Enter the book's price: ";
        std::cin >> bookPrice;

        std::cout << "Enter the quantity: ";
        std::cin >> quantity;

        // store the book details in a file
        std::ofstream bookFile;
        std::string fileName = currentDirectory + "/books.txt";
        bookFile.open(fileName, std::ios::app);

        if (bookFile.is_open())
        {
            bookFile << "Title: " + bookName << std::endl;
            bookFile << "Author: " + bookAuthor << std::endl;
            bookFile << "Price: " + std::to_string(bookPrice) << std::endl;
            bookFile << "Quantity: " + std::to_string(quantity) << std::endl;
            bookFile << "========================" << std::endl;
        }
        else
        {
            std::cout << "Unable to open book" << std::endl;
        }

        bookFile.close();
    }
    void deleteBook() {}
    void updateBook() {}
};

int main()
{
    BookStore myBookStore;
    int option;

    myBookStore.addBook();

    return 0;
}