#include "Book.h"
#include "Library.h"

int main() {
    Library<Media> myLibrary(5);

    myLibrary.addItem(new Book(101, "The Little Prince", "Antoine de Saint-Exupery"));
    myLibrary.addItem(new Book(102, "Animal Farm", "George Orwell"));

    std::cout << "--- Library Inventory ---" << std::endl;
    myLibrary.listAll();

    myLibrary.saveToFile("inventory.txt");

    return 0;
}