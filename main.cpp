/*
 *                                                              ABOUT "THE BOOKSHOP APP"
 * 
 * This program uses OO programming to create a Bookshop App
 * 
 * Features of Version 1 of "The Bookshop App"
 * 
 * 1.  Have a digital Inventory of all books currently available in your store (the titles and the number)
 * 2.  Add reviews to each of the books to aid customers make a choice...
 * 
 * */
#include <iostream>
#include "Books.hpp"

using namespace std;

int main() {
        Books lakeside;
        cout<<"\t\t\t==============WELCOME TO LAKESIDE BOOKSHOP==============="<<endl;
       lakeside.display_menu();
    return 0;
}