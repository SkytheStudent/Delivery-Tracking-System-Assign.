#pragma once
using namespace std;

#include "Menu.h"
#include "Item.h"

class ItemList
{
public:
    vector<Item*> items;

    virtual void toString() = 0;
 
};
class Order : public ItemList
{

public:

    // vector <Item*> lists; 
    double total;
    double total_saved;
    bool discount_applied;
    vector<Item*> Orderitems;
    string orderstring;



    void add(Item* theclass)
    {
        int length_before = Orderitems.size();
        Orderitems.push_back(theclass);

        if (Orderitems.size() == length_before + 1)
        {
            cout << theclass->name << " has been added to order!" << "\n";
        }
        else if (Orderitems.size() == length_before)
        {
            cout << theclass->name << " has not been added correctly to the order, please try again" << "\n";
        }



    }
    void remove(int Item_Removal)
    {
        int length_before = Orderitems.size();



        if (Orderitems.size() != 0) {

            string item = Orderitems[Item_Removal]->name;
            Orderitems.erase(Orderitems.begin() + Item_Removal);


            if (Orderitems.size() == length_before - 1)
            {
                cout << item << " Has been removed successfully from your order" << "\n";
            }
            else if (Orderitems.size() == length_before)
            {
                cout << item << " Has not been successfully been removed from your order, please try again" << "\n";
            }
        }
        else {

            cout << "There are no items to remove! Please add an item first!";

        }
    }
    void calculateTotal(string woo)
    { 
        double temp_total;
        double temp_total_saved;
        bool attempt = false;
        vector<int> saving_positions;

        int numOfAppetisers = 0;
        int cheapest_pos;
        int multiples;
        int desired_position;
        bool tests = false;


        if (woo == "y") {
            for (int t = 0; t <= Orderitems.size() - 1; t++)
            {
                if (Orderitems[t]->type == 'a' && static_cast<Appetiser*>(Orderitems[t])->twoForOne == "y")
                {
                    numOfAppetisers += 1;
                    saving_positions.push_back(t);
                    tests = true;

                   
                }
            }
            if (numOfAppetisers % 2 == 0 && tests == true)
            {

                for (int b = 0; b <= saving_positions.size() - 1; b++)
                {
                    desired_position = saving_positions[b];

                    if (attempt == true)
                    {
                        discount_applied = true;
                        double tank = Orderitems[desired_position]->price;
                        temp_total_saved = total_saved + tank;

                        attempt = false;
                        continue;
                    }
                    else
                    {
                        attempt = true;
                        continue;
                    }


                }
                total_saved = temp_total_saved;
                total = total - total_saved;


            }
            tests = false;
        }
        for (int a = 0; a <= Orderitems.size() - 1; a++)
        {
            temp_total = total + Orderitems[a]->price;
 
        }
        total = temp_total;

 




    }

    void toString()
    {
        orderstring = "";
        cout << "====== Checkout ======" << "\n";
        int order_item_num = 1;
        for (int g = 0; g <= Orderitems.size() - 1; g++)
        {
            orderstring.append("(" + to_string(order_item_num) + ") " + Orderitems[g]->name + ": " + to_string(Orderitems[g]->price) + ", " + to_string(Orderitems[g]->calories) + "cal ");

            if (Orderitems[g]->type == 'a')
            {
                if (static_cast<Appetiser*>(Orderitems[g])->shareable == "y")
                {
                    orderstring.append("( Shareable )\n");
                }
                else
                {
                    orderstring.append("(2-4-1) \n");
                }
            }
            if (Orderitems[g]->type == 'b')
            {
                if (static_cast<Beverages*>(Orderitems[g])->abv != 0.00)
                {
                    orderstring.append("(" + to_string(static_cast<Beverages*>(Orderitems[g])->volume) + "ml" + ", " + to_string(static_cast<Beverages*>(Orderitems[g])->abv) + "%" + ")" + "\n");
                }
                else
                {
                    orderstring.append("(" + to_string(static_cast<Beverages*>(Orderitems[g])->volume) + "ml" + ")" + "\n");
                }

            }
            else if (Orderitems[g]->type == 'm')
            {
 
                orderstring.append("\n");
            }



            order_item_num += 1;
        }
        cout << orderstring;
        cout << "---------------------------" << "\n";
        if (discount_applied == true)
        {
            cout << "2-4-1 Discount Applied!";

        }
        else
        {
            cout << "\n";
        }

        cout << "Savings: " << total_saved << "\n" << "Total: " << total << "\n";

        cout << "\n";
        cout << "Do you want to place your order?" << "\n" << "Type 'y' to confirm, or 'n' to go back and modify it" << "\n";




    }
    void printReciept()
    {
        cout << total;

        ofstream MyFile("reciept.txt");


        MyFile << orderstring;
        MyFile << "\nTotal: " + to_string(total) + "\n" + "Savings: " + to_string(total_saved);
        cout << "... A reciept has been printed for you, thank you for your business!";
        MyFile.close();


    }

};