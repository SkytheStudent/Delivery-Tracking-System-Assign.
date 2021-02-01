// TakeawayTestArea1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS



#include "Menu.h"
#include "Order.h"
#include "Item.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;






int main()
{
    Menu menu = Menu(); 
   
    string userCommand; 
    vector <string> parameters;
    
    Order order = Order();
    menu.load("menu.csv");
    while (userCommand != "exit")
    {
        cout << "What would you like to do? :" << "\n";

        int ourval; 
        int sourval; 
        char Order_item_char_val;
        char Order_item_char_val_s;
        int Order_item_int;


       
        getline(cin, userCommand);
        char* cstr = new char[userCommand.length() + 1];
        strcpy(cstr, userCommand.c_str());
        

        char* token;      
        token = strtok(cstr, " ");
     

        int found; 
        found = userCommand.find(' '); 
        

        if (found + 3 == userCommand.length())
        {
            ourval = found + 1; 
            sourval = found + 2; 

            Order_item_char_val = userCommand[ourval];
            Order_item_char_val_s = userCommand[sourval];
            Order_item_int = stoi(string(1, Order_item_char_val) + Order_item_char_val_s); 

        }
        else {

            ourval = found + 1; 
            Order_item_char_val = userCommand[ourval];
            Order_item_int = Order_item_char_val - '0';
        }
        
        

        while (token != NULL)
        {
            parameters.push_back(token);
            token = strtok(NULL, " ");
        }

        
        string command = parameters[0];

        if (command.compare("menu") == 0) {
            menu.toString();
        }
        else if (command.compare("help") == 0)
        {
            cout << " " << "Available Options:" << "\n";
            cout << "menu - displays the menu" << "\n";
            cout << "add [INDEX] - adds an item to your order, the index being which menu item you would wish to add" << "\n";
            cout << "remove [INDEX] - removes an item from your order, the index being the menu item you wish to remove" << "\n";
            cout << "checkout - display the items in your order, the price, and discount savings" << "\n";
            cout << "help - displays a help menu with the available options" << "\n";
            cout << "exit - terminates the program" << "\n";

        }
        else if (command.compare("remove") == 0)
        {
            Order_item_int = Order_item_int - 1;
            order.remove(Order_item_int);
        }
        else if (command.compare("add") == 0)
        {
            Item* choice;
            Order_item_int = Order_item_int - 1;
            if (Order_item_int < menu.items.size())
            {
               
                
                choice = menu.items[Order_item_int];
                order.add(choice);
                
                string fuck;
                if (menu.items[Order_item_int]->type == 'a') {

                    fuck = static_cast<Appetiser*>(menu.items[Order_item_int])->twoForOne;
                }
                else {
                    fuck = "";
                }
                
                order.calculateTotal(fuck);
               
            }

            else
            {
                cout << "This option is not available on the menu, please try again"; 
                continue; 
            }
        };
        if (command.compare("checkout") == 0)
        {
            order.toString();
            getline(cin, userCommand);
            if (userCommand == "y")
            {
                ofstream MyFile("reciept.txt");
                order.printReciept();
                break;
            }
            else {
                userCommand = "";
                
            }
        }


        parameters.clear();

    }
    cout << "Press any key to quit...";
    std::getchar();
    
    
    
}

