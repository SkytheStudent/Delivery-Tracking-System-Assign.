#pragma once
#include <string>
#include <fstream>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "Order.h"
#include "Item.h"


using namespace std;

class Menu : public ItemList
{
public:

    void load(string filename)
    {
       
        string testline;


        

        fstream file;
        file.open(filename);

        if (file.is_open())
        {
            
            string segment;
            int tests = 0;
            while (getline(file, testline)) {

                vector<string> result;
                string segment;
                int x = 0;


                stringstream s_stream(testline);
                while (s_stream.good())
                {
                    string substr;
                    getline(s_stream, substr, ',');
                    // cout << substr; 
                    result.push_back(substr);


                }
                tests += 1;
 
                if (result[0] == "a")
                {
                    Appetiser* ptr = new Appetiser{ (result[0]).front(), result[1], stod(result[2]), stoi(result[3]), result[4], result[5] };
                    items.push_back(ptr);

                }
                else if (result[0] == "m")
                {
                    MainCourse* ptr = new MainCourse{ (result[0]).front(), result[1], stod(result[2]), stoi(result[3]) };
                    items.push_back(ptr);

                }
                else if (result[0] == "b")
                {

                    Beverages* ptr = new Beverages{ (result[0]).front(), result[1], stod(result[2]), stoi(result[3]), stoi(result[6]), stod(result[7]) };
                    items.push_back(ptr);

                }
                else
                {
                    cout << "I have no idea why this isnt working";
                }



            }
        }

    }
    void toString()
    {

        vector<int> Appetisers_list;
        vector<int> Main_list;
        vector<int> Beverages_list;
        vector<vector<int>> List1;



        for (int z = 0; z <= items.size() - 1; z++)
        {

            if (items[z]->type == 'a')
            {
                Appetisers_list.push_back(z);
            }
            else if (items[z]->type == 'm')
            {
                Main_list.push_back(z);
            }
            else if (items[z]->type == 'b')
            {
                Beverages_list.push_back(z);
            }
            else
            {
                cout << "unknown";
            }

        }

        List1.push_back(Appetisers_list);
        List1.push_back(Main_list);
        List1.push_back(Beverages_list);

        int step = 0;
        int thevalue = 1;
        vector <string> attempts;
        attempts.push_back("Appetisers");
        attempts.push_back("Main Dishes");
        attempts.push_back("Beverages");

        for (auto& it : List1)
        {
            vector<int> val = it;
            cout << "----------------" + attempts[step] + "------------------" + "\n";


            for (auto& lt : val)
            {
                int vat = lt;
                string twenty = items[vat]->name;
                // cout << twenty + "\n";

                cout << "(" << thevalue << ")" << " " << items[vat]->name + ": " ; cout << items[vat]->price << ", " << items[vat]->calories << " " << "cal  ";
                thevalue += 1;

                if (step == 0)
                {

                    if (static_cast<Appetiser*>(items[vat])->shareable == "y")
                    {
                        cout << "(Shareable)" << "\n";
                    }
                    else if (static_cast<Appetiser*>(items[vat])->twoForOne == "y")
                    {
                        cout << "(2-4-1)" << "\n";
                    }
                }
                else if (step == 1)
                {
                    cout << "\n";
                }
                else if (step == 2)
                {
                    if (static_cast<Beverages*>(items[vat])->abv != 0.00)
                    {
                        cout << "(" << static_cast<Beverages*>(items[vat])->volume << "ml" << ", " << static_cast<Beverages*>(items[vat])->abv << "%" << ")" << "\n";
                    }
                    else
                    {
                        cout << "(" << static_cast<Beverages*>(items[vat])->volume << "ml" << ")" << "\n";
                    }

                }
            }
            step += 1;
        }
    }


};