// bookstore application
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

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

    void showBooks()
    {
        std::cout << std::endl;
        std::cout << "=======================================" << std::endl;
        std::cout << "Listing all books" << std::endl;
        std::cout << std::endl;
        std::string fileName = currentDirectory + "/books.txt";

        std::ifstream myFile;
        myFile.open(fileName);

        if (myFile.is_open())
        {
            std::string lineContent;
            while (getline(myFile, lineContent))
            {
                std::cout << lineContent << std::endl;
                if (lineContent == "========================")
                {
                    std::cout << std::endl;
                }
            }
        }
        else
        {
            std::cout << "Unable to open book file" << std::endl;
        }
    }
    void addBook()
    {
        std::cout << "=======================================" << std::endl;
        std::cout << "Enter the book details" << std::endl;

        std::string ISBN;
        std::string bookName;
        std::string bookAuthor;
        double bookPrice;
        int quantity;

        std::cout << "Enter the book name: ";
        std::getline(std::cin, bookName);

        std::cout << "Enter the book ISBN: ";
        std::getline(std::cin, ISBN);

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
            bookFile << "ISBN: " + ISBN << " - Title: " + bookName << " - Author: " + bookAuthor << " - Price: " + std::to_string(bookPrice) << " - Quantity: " + std::to_string(quantity) << std::endl;
        }
        else
        {
            std::cout << "Unable to open book" << std::endl;
        }

        bookFile.close();
    }
    void deleteBook()
    {
        std::string isbn;
        std::cout << "Enter the ISBN of the book to be deleted" << std::endl;
        std::cin >> isbn;

        std::vector<std::string> books;
        std::vector<std::string> newBooks;

        std::string fileName = currentDirectory + "/books.txt";
        std::ifstream myFile;
        myFile.open(fileName);

        if (myFile.is_open())
        {
            std::string lineContent;
            while (getline(myFile, lineContent))
            {
                books.push_back(lineContent);
            }

            for (std::string book : books)
            {
                if (book.find(isbn) == -1)
                {
                    newBooks.push_back(book);
                }
            }

            std::string fileName = currentDirectory + "/books.txt";
            std::ofstream myFile;
            myFile.open(fileName, std::ios::trunc);
            myFile.close();
            myFile.open(fileName, std::ios::app);
            for (std::string b : newBooks)
            {
                myFile << b;
            }
            myFile.close();

            std::cout << "Book has been deleted" << std::endl;
        }
        else
        {
            std::cout << "Unable to open book file" << std::endl;
        }
    }
};

int main()
{
    BookStore myBookStore;
    int option;

    // myBookStore.addBook();
    // myBookStore.showBooks();

    myBookStore.deleteBook();

    return 0;
}