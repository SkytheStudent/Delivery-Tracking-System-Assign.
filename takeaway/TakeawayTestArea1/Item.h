#pragma once
#include <string>
using namespace std; 

#include "Menu.h"
#include "Order.h"



class Item
{
public:
    char type;
    int calories;
    string name;
    double price;

    virtual string toString() = 0;

};

class MainCourse : public Item
{
public:

    MainCourse(char Type, string Name, double Price, int Calories)
    {
        type = Type;
        calories = Calories;
        name = Name;
        price = Price;

    }

    // m.name = result[1];
     //m.calories = stoi(result[3]);
     //m.price = stod(result[2]);
     //m.type = 'm';



    string toString() {
        string returnVariable = "";

        returnVariable += name;
        returnVariable += price;

        return returnVariable;

    }
};

class Appetiser : public Item
{
public:
    string shareable;  //change this to char later, when you have time to figure it out
    string  twoForOne;

    string toString() {
        string returnVariable = "";

        returnVariable += name;
        //returnVariable += price;

        return returnVariable;
    }

    Appetiser(char Type, string Name, double Price, int Calories, string Shareable, string TwoforOne)
    {
        type = Type;
        calories = Calories;
        name = Name;
        price = Price;
        shareable = Shareable;
        twoForOne = TwoforOne;
    }

};

class Beverages : public Item
{
public:
    double abv;
    int volume;

    string toString() {
        string returnVariable = "";

        returnVariable += name;
        returnVariable += price;

        return returnVariable;
    }

    Beverages(char Type, string Name, double Price, int Calories, int Volume, double Abv)
    {
        type = Type;
        calories = Calories;
        name = Name;
        price = Price;
        volume = Volume;
        abv = Abv;

    }

};