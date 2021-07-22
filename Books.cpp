#include "Books.hpp"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
//      * list_books
//      * add_books 
//      * Search_books
//      * review_books
char option {};

   void Books::display_menu(){
        cout<<"a -- Add Books\nl -- Get List of books in stock\ns -- Search for a book\nr -- Add a review to a book\nq -- Quit Application\n";
        cin>>option;
        if (option != 'q'){
            switch (option){
                
                case 'l':
                {
                    list_books();
                    
                }
                break;
                
                case 'a':
                {
                    add_books();
                }
                break;
                
                case 's':
                {
                    search_books();
                }
                break;
                case 'r':
                {
                    cout<<"Relax, we are working on that feature... "<<endl;
                }
                break;
                
//                case 'q':
//                {
//                    quit();
//                }
//                break;

                default:
                {
                    cout<<"Please enter a valid option (In lower case)"<<endl;
                }
            }
        }
        else{
         quit();
        }
    }
    
    void Books:: list_books(){
        /*
         * Index number
         * Book Titles
         * Authors
         * No of Books Available
         * */
        int m {1};
        cout<<"There are currently "<<total_num<<" books titles in the store \n";
            for(int j{1}; j<=total_num; j++){
                cout<<endl<<m<<"----- "<<title.at(j)<<"--- by---  "<<author.at(j)<<" ---("<<copies.at(j)<<" copies in stock)"<<endl<<endl;
                m++;
            }
           display_menu();
    }
    
    void Books :: add_books(){
        int num{0}, copies_val{0};
        double price_val{0.0};
        string title_val{},author_val{}, publisher_val{};
        
        cout<<"How many books will you like to add:  ";
        cin>>num;
        cin.ignore(1, '\n');
        total_num+=num;
        //The first for loop enables the user the opportunity of num inputs...
        for(int i {0}; i < num; i++){
                
                cout<<endl;
                 cout<<"Title: ";
                 getline(cin,title_val);
                 title.push_back(title_val);
//                 title.at(i) = title_val; 
                 cout<<endl;
            
                 cout<<"Author (Surname first): ";
                getline(cin,author_val);
                author.push_back(author_val);
//                author.at(i) = author_val;
                cout<<endl;
            
                cout<<"Selling Price: N ";
                cin>>price_val;
                price.push_back(price_val);
//                price.at(i) = price_val;
                cin.ignore(1, '\n');
                
                
                cout<<"\nPublisher: ";
                getline(cin, publisher_val);
                publisher.push_back(publisher_val);
//                publisher.at(i) = publisher_val;
//                cin.ignore(1, '\n');
                
                cout<<"\nHow many copies are you adding?: ";
                cin>>copies_val;
                copies.push_back(copies_val);
//                copies.at(i) = copies_val;
                cin.ignore(1, '\n');
                
        }
       display_menu();
    }
    
    void Books:: search_books(){
        string book_title{};
        int count {0};
        cout<<"Enter Book title (In upper case): ";
        cin.ignore(1,'\n');
        getline(cin,book_title);
        
    for(size_t r {0}; r <title.size(); r++){
        if(title.at(r) == book_title){
            count++;
        }
    }
    if (count > 0){
            cout<<book_title<<" is available \n";
        }
    }
    
    void Books:: review_books(){
        
    }
    
    int Books::quit(){
        cout<<"GoodBye"<<endl;
        option = 'q';
    }
    
   


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
      * 
      * ##Main
      * 
      * 
 * */