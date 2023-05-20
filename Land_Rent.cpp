#include <iostream>
#include <bits/stdc++.h>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class DashBoard
{

    char line[60];
    int N = 80;
public:
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

    virtual void choose_city(int flag) = 0; // Pure virtual function used
};


class Buying_Land : public DashBoard // Inheritance Used
{
    char line[80];
    int N=100;
    int city_pos;

public:
    void choose_country_Buying_Land()
    {
        choose_country();
    }

    void choose_city(int flag)
    {
        ifstream fout;

        switch(flag)
        {
        case 1:

            fout.open("bangladesh_city_land.txt");

            while (fout)
            {
                fout.getline(line, N);
                cout << line << endl;
            }
            cout << "Choose City :: ";

            cin >> city_pos;
            fout.close();
            break;
        case 2:

            fout.open("usa_city_land.txt");

            while (fout)
            {
                fout.getline(line, N);
                cout << line << endl;
            }
            cout << "Choose City :: ";

            cin >> city_pos;

            fout.close();
            break;
        case 3:

            fout.open("canada_city_land.txt");

            while (fout)
            {
                fout.getline(line, N);
                cout << line << endl;
            }
            cout << "Choose City :: ";

            cin >> city_pos;
            fout.close();
            break;
        }

    }

};

class House_Rent : public DashBoard
{
    char line[60];
    int N = 80;
    int city_pos;
public:
    void choose_country_House_Rent()
    {
        choose_country();
    }

    void choose_city(int flag)
    {
        ifstream fout;

        switch(flag)
        {
        case 1:

            fout.open("bangladesh_city_rent.txt");

            while (fout)
            {
                fout.getline(line, N);
                cout << line << endl;
            }
            cout << "Choose City :: ";

            cin >> city_pos;
            fout.close();
            break;
        case 2:

            fout.open("usa_city_rent.txt");

            while (fout)
            {
                fout.getline(line, N);
                cout << line << endl;
            }
            cout << "Choose City :: ";

            cin >> city_pos;

            fout.close();
            break;
        case 3:

            fout.open("canada_city_rent.txt");

            while (fout)
            {
                fout.getline(line, N);
                cout << line << endl;
            }
            cout << "Choose City :: ";

            cin >> city_pos;
            fout.close();
            break;
        }

    }



};
