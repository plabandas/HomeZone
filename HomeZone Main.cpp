#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

void calling_loging_class();

class Login_sign_UP
{
public:

    void login()
    {
        int count;
        string user,pass,u,p;
        system("cls");
        cout<<"Please enter the following details ::"<<endl;
        cout<<"USERNAME : ";
        cin>>user;
        cout<<"PASSWORD :";
        cin>>pass;

        ifstream input("database.txt");
        while(input>>u>>p)
        {
            if(u==user && p==pass)

            {
                count=1;
                system("cls");
            }
        }
        input.close();
        if(count==1)
        {
            cout<<"**********Hello "<<user<<"*********\n*****LOGIN SUCESS*****\n***Thanks for logging in***\n";
            cin.get();
            cin.get();

            calling_loging_class();
        }
        else
        {
            cout<<"\n LOGIN ERROR \n Please check your username and password \n ";

            calling_loging_class();
        }

    }


    void registr()
    {

        string reguser,regpass,ru,rp;
        system("cls");
        cout<<"Enter the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;

        ofstream reg("database.txt",ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"\nRegistration Sucessful\n";

        calling_loging_class();
    }

    void forgot()
    {
        int ch;
        system("cls");
        cout<<"Forgotten ? Don't worry !!\n";
        cout<<"1.Search your id by username"<<endl;
        cout<<"2.Search your id by password"<<endl;
        cout<<"3.Main menu"<<endl;
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch)
        {
        case 1:
        {
            int count=0;
            string searchuser,su,sp;
            cout<<"\nEnter your remembered username :";
            cin>>searchuser;

            ifstream searchu("database.txt");
            while(searchu>>su>>sp)
            {
                if(su==searchuser)
                {
                    count=1;
                }
            }
            searchu.close();
            if(count==1)
            {
                cout<<"\n\Wow, account has been found\n";
                cout<<"\nYour password is "<<sp;
                cin.get();
                cin.get();
                system("cls");

                calling_loging_class();
            }
            else
            {
                cout<<"\nSorry, Your userID is not found in our database\n";
                cout<<"\nPlease kindly contact to Admin Of this App(Plaban Das -> 2007111)\n";
                cin.get();
                cin.get();

                calling_loging_class();
            }
            break;
        }
        case 2:
        {
            int count=0;
            string searchpass,su2,sp2;
            cout<<"\nEnter the remembered password :";
            cin>>searchpass;

            ifstream searchp("database.txt");
            while(searchp>>su2>>sp2)
            {
                if(sp2==searchpass)
                {
                    count=1;
                }
            }
            searchp.close();
            if(count==1)
            {
                cout<<"\nYour password is found in the database \n";
                cout<<"\nYour Id is : "<<su2;
                cin.get();
                cin.get();
                system("cls");

                calling_loging_class();
            }
            else
            {
                cout<<"Sorry, We cannot found your password in our database \n";
                cout<<"\nPlease kindly contact to Admin Of this App(Plaban Das -> 2007111)\n";
                cin.get();
                cin.get();

                calling_loging_class();
            }

            break;
        }

        case 3:
        {
            cin.get();

            calling_loging_class();
        }
        default:
            cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
            forgot();
        }
    }

};

void calling_loging_class()
{
    Login_sign_UP obj;

    int choice;
    cout<<"***********************************************************************\n\n\n";
    cout<<"                      Welcome to login page                               \n\n";
    cout<<"*******************        MENU        *******************************\n\n";
    cout<<"1.LOGIN"<<endl;
    cout<<"2.REGISTER"<<endl;
    cout<<"3.FORGOT PASSWORD (or) USERNAME"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"\nEnter your choice :";
    cin>>choice;
    cout<<endl;
    switch(choice)
    {
    case 1:
        obj.login();
        break;
    case 2:
        obj.registr();
        break;
    case 3:
        obj.forgot();
        break;
    case 4:

        cout<<"\nThanks for using our App. Created By : Plaban Das -> 2007111(CSE-20)\n";
        break;
    default:
        //system("cls");
        cout<<"You've made a mistake , give it a try again\n"<<endl;
        cout << "Want To Go Back ?? ::(1 for YES , 0 for NO) ::  ";
    }

}

main()
{
    calling_loging_class();

}
