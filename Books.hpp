#ifndef _BOOKS_H_
#define _BOOKS_H_
#include <vector>
#include <string>

//list_books
//      * add_books
//      * Search_books
//      * review_books


class Books
{
private: 
//The attributes are being defined and initialised Here
    std::vector<std::string> title{" "};
    std::vector<std::string> author{" "};
    std::vector<int> copies {0};
    std::vector<double>price {0.00};
    std::vector<int> position{0};
    std::vector<std::string> publisher{" "};
    int total_num{0};
//    char option {};
      int quited {0};
    
public:
    void display_menu();
    void list_books();
    void add_books();
    void search_books();
    void review_books();
    int quit();
    void rerun(int &quited);
  
};
#endif // _BOOKS_H_


/*
 * List of books include:
 * Author
 * Title
 * Price
 * Publisher
 * Stock Position..
 * 
 * 
 * When a customer wants a book, the sales person inputs the title and author 
 * The code searches and displays if the book is available or not...
 *If it is not available, an appropriate message is displayed...
 * If it is, and the required copies are available
 * 
 * Use a class called books with suitable member functions and constructors
 * Also look at the possibility of using the new operator to create spaces for the books and deleting them when due.
 * *****************************************************************************************************************************************************************************************************************************************************************
 *                         <  Layout of the Program  >       
 *                                      HOME MENU
 * What would you like to do? Press the "Digit" of your choice
 * 
 * 1.  GET LIST OF ALL BOOKS AVAILABLE
            if you do this, all the BOOK TITLES in store will be outputed alongside their AUTHORS and how many COPIES of the books are available
    2.  ADD NEW STOCK
     *      if you do this, an interctive window then asks you for:
     *          a. The title all in capital letters
     *          b. The Author Surname first
     *          c. The publisher of the book
     *          d. How many books you would lke to add
     *          e. The selling price of the books
     3.   SEARCH FOR A BOOK
      *         This is to display if  a book is available or not...
                Here an interactive window opens and some information are requested from the user:
                 *      1. Title of the book "In Capital Letters"
                 *      2. Author of the book
                 *      3. How many copies of the book is required???
                 * 
                 * Then the program searches for the book and if the book is available, the program outputs 
                 * The Status:
                 * The Total Price of all the copies that are to be purchased...
     4.     ADD REVIEWS OF THE BOOKS. (If the book is available then add the review)>>>>>>>>>>>
     5.     QUIT 
      * 
      * 
      *                                                             HOW TO GO ABOUT THE PROGRAM
      * 
      * Use class called books with suitable member functions and constructors
      * 
      * STEPS
      * 1. Create The class called Books
      * ##Header FIle
      * attributes to be in Private:
      * The things in Private will be in form of vectors...
 *  Author
 * Title
 * Price
 * Publisher
 * Stock Position..
      * Method Prototypes to be included in Public....
      * Functions:
      * These functions and methods will be making use of the attributes in the private since they are members of the class...
      *     1. Add books
      *     2. Get List of all Books available
      *     3. Add Review
      *     4. Then The constructor That looks for a book............
      * 
      * ##Cpp File
      * Functions to be elaborated on in the Cpp file
      * 
      * list_books
      * add_books
      * Search_books
      * review_books
      * 
      * 
      * ##Main
      * 
      * 
 * */