/*
Roll :: 2007111
Name :: Plaban Das
Department :: CSE
*/

////////////////////////////////////////////////////// Overview Video Link :: (( https://youtu.be/zoeeQwyyk_g  ))

#include <bits/stdc++.h>
#include <string.h>


using namespace std;
bool state_of_cart=true;
string Name_customer = "";
inline void function_for_some();

multiset<int> multi_st;


class Card_view_Adding
{
private:
    char line[600];
    int N = 800;
public:
    int added_to_cart(int flag,string what_file)
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


        if(flag != 0)
        {
            while (fout)
            {
                c_ter++;
                fout.getline(line, N);
                if(c_ter==counter)
                {
                    if(state_of_cart)
                    {
                        state_of_cart = false;         // New vabe cart toiri hoscca
                        ofstream card_view("card_view.txt",ios::out);
                        card_view<<line<<endl;
                    }
                    else
                    {
                        //Cart a append korcha
                        ofstream card_view("card_view.txt",ios::app);
                        card_view<<line<<endl;
                    }

                    system("cls");

                    cout << line << endl;
                    cout << endl << "Item is added to Cart Successfully" << endl;
                }
            }
        }
        else
        {
            return -1000; // Flow of control backing
        }




        if(flag != 0)
        {

            cout << endl << "Do you want to stay more time ?? (1 for YES, 0 for NO)" <<endl;
            cout << "Give input :: " ;
            int a;
            cin >> a;
            if(a==1)
            {
                system("cls");
                return a;
            }
            else if(a==0)
            {
                return a;
            }
            else
            {
                cout << "Wrong Input " << endl;
                return -199;
            }

        }
        else
        {
            int city_pos;
            cout << "Choose City :: ";
            cin >> city_pos;
            added_to_cart(city_pos,what_file);

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

            int state = card_view.added_to_cart(city_pos,"bangladesh_city_land.txt");
            if(state == 1)
                function_for_some();  // Again Launching

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
            int state = card_view.added_to_cart(city_pos,"usa_city_land.txt");
            if(state == 1)
                function_for_some();  // Again Launching

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
            int state = card_view.added_to_cart(city_pos,"canada_city_land.txt");
            if(state == 1)
                function_for_some();  // Again Launching

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
            int state = card_view.added_to_cart(city_pos,"bangladesh_city_rent.txt");
            if(state == 1)
                function_for_some();  // Again Launching

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
            int state = card_view.added_to_cart(city_pos,"usa_city_rent.txt");
            if(state == 1)
                function_for_some();  // Again Launching

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
            int state = card_view.added_to_cart(city_pos,"canada_city_rent.txt");
            if(state == 1)
                function_for_some();  // Again Launching

            fout.close();

        }
        else
        {
            cout << "Something went Wrong !!" << endl;
        }

    }



};


void calling_loging_class();


class Login_sign_UP            // Class Used
{
    int count;
    string user,pass,u,p;        // Encapsulation Used
public:

    void login()                  // Member Function Used
    {
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
            Name_customer = user;

            cout << endl << endl;
            function_for_some();

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
                system("cls");
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
                system("cls");
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
    cout<<"***********************************************************************\n\n";
    cout<<"                      Welcome to login page                               \n\n";
    cout<<"                         ** HomeZone **                                     \n\n";
    cout<<"***********************************************************************\n\n";
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

inline void function_for_some()
{

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
        cout << "Wrong Input !!!!"<< endl << "Want to Login Again ? ==> ";
        int k;
        cin >> k;
        if(k)
        {
            Login_sign_UP logs;
            logs.login();
        }
        else
        {
            exit(-1);
        }
    }
}

class Make_invoice
{
//    int product_id=0;
//    char line[800];
//    int N=1000;

    int product_id;
    char line[800];
    int N;

    char line1[800];
public:
    Make_invoice() {};
    Make_invoice(int id,int n)
    {
        product_id = id;
        N = n;
    }


    void make_invoice_ready(int flag)
    {
        ofstream out_invoice("invoice.txt");

        int counter=0;
        ifstream out;
        out.open("card_view.txt");
        while(out)
        {
            counter++;
            out.getline(line,N);
            if(counter == flag)
            {

                out_invoice << "*************************Welcome To HomeZone*************************" << endl;
                out_invoice << "*******************Our Dream to make your life EASY******************" << endl << endl;
                out_invoice << "***************Customer Name : "<< Name_customer << "***************" << endl;
                out_invoice << "Product Details :: " << line << endl;


                cout << endl << "Congratulations!! Your Invoice Is Ready...."<< endl;
                cout << "Text Document has been generated !!" << endl << endl;
                ifstream in_file;
                in_file.open("invoice.txt");
                while(in_file)
                {
                    in_file.getline(line1,N);
                    cout << line1 << endl;
                }


                return;
            }


        }
        out.close();
        out_invoice.close();

    }


    void make_final_card_list()
    {

        ifstream out_card;
        out_card.open("card_view.txt");
        cout << endl;
        while(out_card)
        {
            product_id++;
            out_card.getline(line,N);

            int k = (int)line[0] ;

            if( k != 0)     // Last item filtered
            {
                cout<< "Product ID: "<<product_id<< " Item :: "<< line << endl;
            }



        }
        cout << endl;
        out_card.close();
    }
    void callint_make_invoice_ready()
    {
        cout << "Select Your Final Item **With Product ID** :: ";
        int flag;
        cin >> flag;
        make_invoice_ready(flag);
    }

};

int items_count = 0;
static int total_cost_dollars = 0;

template<typename P>
void calculation_of_dolars(P a)
{
    total_cost_dollars =  total_cost_dollars + a;
}

template<typename R>
void calculation_of_items(R a)
{
    items_count =  items_count + a;
}


class cart_operation
{
    char line[800];
    int N = 1000;

public:
    void calculate_total_cost()
    {
        int counter = 1;
        ifstream input("card_view.txt");
        bool flag2 = false;
        string str;
        while(input >> str)
        {
            if(str == "USD")
            {
                flag2 = true;
            }
            else if(flag2 == true)
            {

                flag2 = false;
                int val = stoi(str);

                multi_st.insert(val);

                calculation_of_dolars(val); // using template
                calculation_of_items(counter); // using template
            }

        }
        input.close();
    }
    void sort_elements_with_money()
    {
        int counter =0;

        for (auto it = multi_st.begin(); it != multi_st.end(); it++)
        {
            int temp = *it ;

            string str;

            ifstream out_card;
            bool flag2 = false;
            out_card.open("card_view.txt");
            while(out_card)
            {
                out_card.getline(line,N);

                string got_line = line;
                if (got_line.find(to_string(temp)) != std::string::npos)
                {
                    counter ++;
                    cout << "Product Details: "<< counter << " -> "<< line << endl;
                }

            }
            out_card.close();
        }
    }
    int get_total_cost()
    {
        return total_cost_dollars;
    }
    int get_totoal_count()
    {
        return items_count;
    }

    friend ostream& operator<<(ostream &out,cart_operation &ob);
};


ostream& operator << (ostream &out, cart_operation &ob)
{
    cout << endl << "Your Total Items On Cart : " << ob.get_totoal_count() << endl;
    cout << "Your Value Of Those Items In USD : " << ob.get_total_cost() << " Dollars...." << endl;
}


int main()
{
    calling_loging_class();

    system("cls");

    cout << "Do you want to watch final cart items ? (1 for YES , 0 for Exit Program) :: " ;

    cart_operation object;
    object.calculate_total_cost();

    int flag;
    cin >> flag;
    if(flag == 1)
    {
        cout << object;      // Operator Overloading

        Make_invoice invoice(0,1000);         //constructor used
        invoice.make_final_card_list();

        cout << "Do you want items Sorted with Price ? (1 for yes, 0 for NO) :: ";
        int t;
        cin >> t;
        if(t==1)
        {
            cout << endl;
            object.sort_elements_with_money();
            cout << endl;
            cout << "Want Back to main Cart? (1 for yes, 0 for Exit Program) :: ";

            int flag;
            cin >> flag;
            if(flag == 1)
            {
                system("cls");
                cout << object;

                Make_invoice invoice(0,1000);         //constructor used
                invoice.make_final_card_list();

                invoice.callint_make_invoice_ready();
            }
            else
            {
                exit(-1);
            }



        }
        else
        {
            system("cls");
            cout << object;

            Make_invoice invoice(0,1000);
            invoice.make_final_card_list();
            invoice.callint_make_invoice_ready();
        }

    }
}
