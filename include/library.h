// library.h
#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

// Global variables
extern char titles[MAX_BOOKS][MAX_TITLE_LENGTH];
extern char authors[MAX_BOOKS][MAX_AUTHOR_LENGTH];
extern float prices[MAX_BOOKS];
extern int quantities[MAX_BOOKS];
extern int bookCount;

// Function prototypes
void addBook();
void displayBooks();
void searchBook();
void updateQuantity();
void deleteBook();
void displayTotalBooks();

#endif // LIBRARY_H
