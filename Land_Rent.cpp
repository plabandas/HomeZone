#include <iostream>
#include <bits/stdc++.h>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

#include "Land_Rent.cpp"

using namespace std;

class Card_view_Adding
{
    char line[600];
    int N = 800;
public:
    void added_to_cart(int flag,string what_file)
    {
        int counter=0,c_ter=0;
        ifstream fout;
        fout.open(what_file);

        if(flag >= 22)
        {
            counter = flag + 11;
        }
        else if(flag >=19)
        {
            counter = flag + 10;
        }
        else if(flag >=16)
        {
            counter = flag + 9;
        }
        else if(flag >=13)
        {
            counter = flag + 8;
        }
        else if(flag >=10)
        {
            counter = flag + 7;
        }
        else if(flag >=7)
        {
            counter = flag + 6;
        }
        else if(flag >=4)
        {
            counter = flag + 5;
        }
        else if(flag >=1)
        {
            counter = flag + 4;
        }


        while (fout)
        {


            c_ter++;
            fout.getline(line, N);
            if(c_ter==counter)
            {
                ofstream card_view("card_view.txt",ios::app);

                card_view<<line<<endl;

                cout << line << endl;
                cout << endl << "Item is added to Cart Successfully" << endl;
            }

        }

        cout << endl << "Do you want to stay more time ?? (1 for YES, 0 for NO)" <<endl;
        cout << "Give input :: " ;
        int a;
        cin >> a;
        if(a==1)
        {

            cout << endl << endl;
            cout << "What do you want ?? "<< endl;
            cout << "1. Do you want to buy land ?" << endl;
            cout << "2. OR !! Do you want to rent a house ?" << endl;
            cout << "Give your choice :: ";
            int flag;
            cin >> flag;

            if(flag==1)
            {
                Buying_Land land;
                land.choose_country_Buying_Land();
            }
            else if(flag == 2)
            {
                House_Rent land;
                land.choose_country_House_Rent();
            }
            else
            {
                cout << "Wrong Input " << endl;
            }



        }
        else if(a==0)
        {
            exit(-1);

        }
        else
        {
            cout << "Wrong Input " << endl;
        }


    }
};


class DashBoard
{

    char line[600];
    int N = 800;
public:

    virtual void choose_city(int flag) = 0; // Pure virtual function used

    void choose_country()
    {
        ifstream fin_country;
        fin_country.open("country.txt");
        while (fin_country)
        {
            fin_country.getline(line, N);
            cout << line << endl;
        }
        cout << "Choose Country :: ";
        int flag;
        cin >> flag;
        switch(flag)
        {
        case 1:
            cout << "**********************"<<"Bangladesh"<< "**********************" << endl;
            choose_city(flag);
            break;
        case 2:
            cout << "**********************"<<"USA"<< "**********************" << endl;
            choose_city(flag);
            break;
        case 3:
            cout << "**********************"<<"Canada"<< "**********************" << endl;
            choose_city(flag);
            break;
        }

    }
};


class Buying_Land : public DashBoard // Inheritance Used
{
    char line[800];
    int N=1000;
    int city_pos;

public:
    void choose_country_Buying_Land()
    {
        choose_country();
    }

    void choose_city(int flag)
    {
        ifstream fout;

        if(flag==1)
        {
            fout.open("bangladesh_city_land.txt");

            while (fout)
            {
                fout.getline(line, N);
                cout << line << endl;
            }
            cout << "Choose City :: ";

            cin >> city_pos;

            Card_view_Adding card_view;
            card_view.added_to_cart(city_pos,"bangladesh_city_land.txt");

            fout.close();

        }
        else if(flag == 2)
        {
            fout.open("usa_city_land.txt");

            while (fout)
            {
                fout.getline(line, N);
                cout << line << endl;
            }
            cout << "Choose City :: ";

            cin >> city_pos;

            Card_view_Adding card_view;
            card_view.added_to_cart(city_pos,"usa_city_land.txt");

            fout.close();
        }
        else if(flag == 3)
        {
            fout.open("canada_city_land.txt");

            while (fout)
            {
                fout.getline(line, N);
                cout << line << endl;
            }
            cout << "Choose City :: ";

            cin >> city_pos;

            Card_view_Adding card_view;
            card_view.added_to_cart(city_pos,"canada_city_land.txt");

            fout.close();
        }
        else
        {
            cout << endl << "Wrong option is choosed !!" << endl;
        }


    }

};

class House_Rent : public DashBoard
{
    char line[600];
    int N = 800;
    int city_pos;
public:
    void choose_country_House_Rent()
    {
        choose_country();
    }

    void choose_city(int flag)
    {
        ifstream fout;

        if(flag ==1 )
        {

            fout.open("bangladesh_city_rent.txt");

            while (fout)
            {
                fout.getline(line, N);
                cout << line << endl;
            }
            cout << "Choose your House :: ";

            cin >> city_pos;

            Card_view_Adding card_view;
            card_view.added_to_cart(city_pos,"bangladesh_city_rent.txt");

            fout.close();
        }
        else if(flag == 2)
        {

            fout.open("usa_city_rent.txt");

            while (fout)
            {
                fout.getline(line, N);
                cout << line << endl;
            }
            cout << "Choose City :: ";

            cin >> city_pos;

            Card_view_Adding card_view;
            card_view.added_to_cart(city_pos,"usa_city_rent.txt");

            fout.close();
        }
        else if(flag ==3)
        {

            fout.open("canada_city_rent.txt");

            while (fout)
            {
                fout.getline(line, N);
                cout << line << endl;
            }
            cout << "Choose City :: ";

            cin >> city_pos;

            Card_view_Adding card_view;
            card_view.added_to_cart(city_pos,"canada_city_rent.txt");

            fout.close();

        }

    }



};

