#include "Books.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//All the methods that were defined in the public section are expounded upon here...
//This method is the key to the other methods and it displays the possible operations in the home screen anytime it is called
   void Books::display_menu(){
        
        cout<<"\na -- Add Books\nl -- Get List of books in stock\ns -- Search for a book\nq -- Quit Application\n";
        cout<<"Option: ";
        cin>>option;
        cout<<endl;
        
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

                default:
                {
                    cout<<"Please enter a valid option (In lower case)"<<endl;
                    display_menu();
//                     cin.ignore(1,'\n');
                }
            }
        }
        else{
         quit();
        }
    }

//THis method simpply gets a list of all the books currently in stock. It also states how many books are in stock
    void Books:: list_books(){
        int m {1};
        cout<<"There are currently "<<total_num<<" books titles in the store \n";
            for(int j{1}; j<=total_num; j++){
                cout<<endl<<m<<"----- "<<title.at(j)<<"--- by---  "<<author.at(j)<<" ---("<<copies.at(j)<<" copies in stock)"<<endl;
                m++;
            }
           display_menu();
    }
    
    //This method when called opens up to part of the code that allows you to add new books or more copies of already existing books to the collection
    void Books :: add_books(){
        int num{0}, copies_val{0},counts{0}, copies_to_add{0};
        double price_val{0.0};
        string title_val{},author_val{}, publisher_val{};
        size_t q{0};
        cout<<"How many books will you like to add:  ";
        cin>>num;
        cin.ignore(1, '\n');
        total_num+=num;
        //The first for loop enables the user the opportunity of num inputs...
                 for(int i {0}; i < num; i++){
                 bookline:cout<<"\n\t\tBook "<<i+1; 
                 cout<<endl;
                 cout<<"Title (Ensure complete and accurate input): ";
                 getline(cin,title_val);
                 title_val = capitalise(title_val);
               
  //If the book is already in stock, only the number of books to be added is taken from the user...
                  for(size_t r {0}; r <title.size(); r++){
                        if(title.at(r) == title_val){
                            counts++;
                            q = r;
                        }
                    }
                 
                if (counts > 0){
                     cout<<copies.at(q)<<" copies of "<<title_val<<" are in stock \nHow many copies would you like to add?: ";
                     cin>>copies_to_add;
                     copies.at(q)+=copies_to_add;
                     cout<<"Input Recorded!\n"; 
                     total_num-=1;
                     counts=0;
                     cin.ignore(1,'\n');
                     continue;
                }
                 else{
                            title.push_back(title_val);
                 }
                 
                 reviews.push_back("No reviews yet... ");

                 cout<<"Author (Surname first): ";
                getline(cin,author_val);
                author_val = capitalise(author_val);
                author.push_back(author_val);
            
                cout<<"Selling Price: N ";
                cin>>price_val;
                price.push_back(price_val);
                cin.ignore(1, '\n');
                
                
                cout<<"Publisher: ";
                getline(cin, publisher_val);
                publisher.push_back(publisher_val);

                
                cout<<"How many copies are you adding?: ";
                cin>>copies_val;
                copies.push_back(copies_val);
                cin.ignore(1, '\n');
                cout<<endl;
        }
       display_menu();
    }
    
    //This is the most elaborated method in this code, although it is subject to review in the second version...
    //In this section, you can buy a book, or even add reviews to books...
    void Books:: search_books(){
        string book_title{}, review{};
        int count {0};
        size_t p{0}, copys{0};
        double net_cost {0.0};
        cout<<"Enter Book title (ensure complete & accurate input): ";
        cin.ignore(1,'\n');
        getline(cin,book_title);
        book_title = capitalise(book_title);
        char choice{}, s_choice{}, buy_choice{};
        
    for(size_t r {0}; r <title.size(); r++){
        if(title.at(r) == book_title){
            count++;
            p = r;
        }
    }
    if (count > 0){
            cout<<book_title<<" is available \n";

// *      b. Add review to the book
// *                  Find a way so that the default review for all the books is "No Review has been added at the moment"
                cout<<"a -- Buy the book\nb -- Add review of the book\nc -- Read Review of the book\nOption: ";
                cin>>choice;
                cout<<endl;
                switch (choice){
                  buy: case 'a':
                    {
                            cout<<"How many copies? : ";
                            cin>>copys;
                            if (copies.at(p) == 0){
                                cout<<"Sorry, "<<title.at(p)<<" is out of stock "<<endl;
                            }
                            else if ( copys > copies.at(p)){
                                cout<<"Sorry, only "<<copies.at(p)<<" copies are available "<<endl;
                                display_menu();
                            }
                            else{
                                cout<<"Total Cost: N "<<copys*price.at(p)<<"\nDO you wish to continue this transaction? ";
                                cout<<"\n1 -- Yes\n2 -- No\nChoice: ";
                                cin>>buy_choice;
                                switch (buy_choice){
                                    case '1':
                                    {
                                        cout<<"Thank you for your patronage\n";
                                        copies.at(p)-=copys;
                                        display_menu();
                                    }
                                    break;
                                    case '2':
                                    {
                                        cout<<" Okay, Check out other books before you go!\n";
                                        display_menu();
                                    }
                                    break;
                                    default:
                                    {
                                        cout<<"Invalid Option entered! ";
                                        display_menu();
                                    }
                                }
                            }
                    }
                    break;
                    
                    case 'b':
                    {
                        cout<<"Kindly Input your review below:\n";
                        cin.ignore(1,'\n');
                        getline(cin,review);
                        reviews.at(p) = review;
                        cout<<"Thank you! Your review has been recorded!"<<endl;
                        display_menu();
                    }
                    break;
                    
                    case 'c':
                    {
                        cout<<"\nReview: "<<reviews.at(p)<<endl;
                        decision: cout<<"1 -- Buy the book\n2 -- Search for another book\n3 -- Return to the main menu\nOption: ";
                        cin>>s_choice;
                        switch(s_choice){
                            case '1':
                            {
                                goto buy;
                            }
                            break;
                            case '2':
                            {
                                search_books();
                            }
                            break;
                            case '3':
                            {
                                display_menu();
                            }
                            break;
                            default:
                            {
                                cout<<"Please input a valid option\n";
                                goto decision;
                            }
                        }
                    }
                    break;
                    
                    default:
                    {
                        cout<<"Please enter a valid option";
                        display_menu();
                    }
                }
        }
        else{
            cout<<book_title<<" is not available\n";
            display_menu();
        }
    }
    
    
    int Books::quit(){
        cout<<"GoodBye"<<endl;
        option = 'q';
    }
    
    string Books :: capitalise (string input){
        string reform{};
        for (auto letters : input){
            letters = toupper(letters);
            reform+=letters;
        }
        input = reform;
        return input;
    }
   
   
    /*
  *                                 THINGS TO IMPLEMENT IN THE NEXT VERSION OF "THE BOOKSHOP APP"
  * 1.  I can search for books using :the author-----the title--------the book number: and the same options of buying or reviewing 
  * the book come up
  * 2.  After i see that the number of books are not enough, the user can be given options to either
  *             Buy a different number of units
  *             Search for another book
  *             return to home
  * 3. Implement exception handling for all the places where the user has to enter input... And test all
  * 4. Extract a method called SEARCH  and have another method called BUY that have tailored and specific functions
  * 5. Expound on the buying  method keeping in mind that a cutomer can want to buy more than one book at once and this
  *     is often the case...
  * 6. Create a feature that alerts the librarian on the Books that are currently getting out of stock or that are out of stock completely...
  * 
  * */
