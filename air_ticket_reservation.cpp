#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;
const int max_passenger = 100;
static int passenger_count = 0;
string Name[max_passenger], Address[max_passenger], Phone_number[max_passenger], Age[max_passenger], From[max_passenger], To[max_passenger], CODE[max_passenger];
string Flight_name[max_passenger], Time[max_passenger], Fare[max_passenger], Departure[max_passenger], Arrival[max_passenger], D_M[max_passenger],CLASS[max_passenger];
int seat[max_passenger];

// Fuction declaration 
void interface();
string ticket_code();
void Flight_Schedule_info();


class Seat
{
public:
  int seat_number; 
  int seat_status[100];

  Seat()
   {
        srand(time(0));
        for (int i = 0; i <100; i++) 
        {
            seat_status[i] = rand() % 2; 
        }
   }

   void availability(int CHOICE)
   {
        
        if (CHOICE==1)
        {
            cout << "Total number of seat : 25 \n";
            cout<<"The following number of seats are available now: ";

            for (int i = 0; i <25; i++) 
            {
                if(seat_status[i]==0)
                {
                    cout<<i<<",";
                }
            }


            cout<<"\n\nEnter seat number : ";
            cin>>seat_number;
            seat[passenger_count]=seat_number;

        }
    
        else if (CHOICE==2)
        {
            cout << "Total number of seat : 35 \n";
            cout<<"The following number of seats are available now: ";

            for (int i = 25; i <60; i++) 
            {
                if(seat_status[i]==0)
                {
                    cout<<i<<",";
                }
            }

            cout<<"\n\nEnter seat number : ";
            cin>>seat_number;
            seat[passenger_count]=seat_number;
        }

        else if(CHOICE==3)
        {
            cout << "Total number of seat : 40 \n";
            cout<<"The following number of seats are available now: ";
            for (int i = 60; i <100; i++) 
            {
                if(seat_status[i]==0)
                {
                    cout<<i<<",";
                }
            }

            cout<<"\n\nEnter seat number : ";
            cin>>seat_number;
            seat[passenger_count]=seat_number;
        }

   }

    virtual void Fare_cost(){}
};


class Economy_class : public Seat
{
public:

     void Fare_cost() override
     {
        cout << "\n----------ECONOMY CLASS----------\n \n";
        cout<<"Seat Position  "<<"-------"<<"  Fare"<<"\n\n";
        cout <<"1. Window Seat\t\t"<<"250$\t"<<endl;
        cout<< "2. Middle Seat\t\t"<<"200$"<< endl;   
        cout<< "3. Aisle Seat\t\t"<<"150$"<< endl;  

        cout<<"Press (1-3) to choice you seat : " ;
        int choice;
        cin>>choice;

        if(choice==1)
        {
            Fare[passenger_count]="250$";
            
        }
        else if (choice==1)
        {
             Fare[passenger_count]="200$";     
        }
        else
        {
             Fare[passenger_count]="150$";
        }

     }
};


class Business_class : public Seat
{
public:

     void Fare_cost() override
     {
        cout << "\n----------Business CLASS----------\n \n";
        cout<<"Seat Position  "<<"-------"<<"  Fare"<<"\n\n";
        cout <<"1. Window Seat\t\t"<<"550$\t"<<endl;
        cout<< "2. Middle Seat\t\t"<<"500$"<< endl;   
        cout<< "3. Aisle Seat\t\t"<<"450$"<< endl;   

        cout<<"Press (1-3) to choice you seat : " ;
        int choice;
        cin>>choice;

        if(choice==1)
        {
            Fare[passenger_count]="550$";
            
        }
        else if (choice==1)
        {
             Fare[passenger_count]="500$";     
        }
        else
        {
             Fare[passenger_count]="450$";
        }

     }
};


class First_class : public Seat
{
public:

     void Fare_cost() override
     {
        cout << "\n----------FIRST CLASS----------\n \n";
        cout<<"Seat Position  "<<"-------"<<"  Fare"<<"\n\n";
        cout <<"1. Window Seat\t\t"<<"950$\t"<<endl;
        cout<< "2. Middle Seat\t\t"<<"900$"<< endl;   
        cout<< "3. Aisle Seat\t\t"<<"850$"<< endl;  

        cout<<"Press (1-3) to choice you seat : " ;
        int choice;
        cin>>choice;

        if(choice==1)
        {
            Fare[passenger_count]="950$";
            
        }
        else if (choice==1)
        {
             Fare[passenger_count]="900$";     
        }
        else
        {
             Fare[passenger_count]="850$";
        } 
     }
};


// File Handling
void File(int passengerCount, string Name, string Address, string Age, string Phone_number, string CODE)
{

    ofstream file("Database.txt", ios::app);


    file << "\t_____________ SRH Domestic Air Line _______________\n"<< endl;
    file << left << setw(20) << "PASSENGER SERIAL : " << setw(30) << passengerCount + 1 << endl;
    file << left << setw(20) << "PASSENGER NAME :" << setw(30) << Name << "|\tTicket code: " << CODE << endl;
    file << left << setw(20) << "ADDRESS        :" << setw(30) << Address << "| " << endl;
    file << left << setw(20) << "AGE            :" << setw(30) << Age << "|" << endl;
    file << left << setw(20) << "PHONE NUMBER   :" << setw(30) << Phone_number << "|" << endl;
    file<< "\n";

    file.close();
}

// Auto string generate for ticket code
string ticket_code()

{
    string code = "";
    const char chars[] = "ASDFGHJKLPOIUYTR12345678901234567890123456789";
    srand(time(0));
    for (int i = 0; i < 5; ++i)
    {
        code += chars[rand() % (sizeof(chars) - 1)];
    }

    return code;
}


// Flight schedule information
void Flight_Schedule_info()
{
    string Num[] = {"1", "2", "3", "4", "5"};
    string Flight_name[] = {"Air Astra-3319", "Novo Air-1971", "US-Bangla-2441", "Nov oAir-300", "BD Airline-44"};
    string Departure[] = {"10:00 AM", "05:26 PM", "10:00 AM", "05:26 PM", "05:26 PM"};
    string Arrival[] = {"12:45 AM", "07:26 PM", "01:25 PM", "08:36 PM", "09:26 PM"};
    cout << "Serial\t\t" << "Avilavle Flights\t" << "Departure\t" << "\tArrival\t" << endl
         << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << Num[i] << "\t" << "\t";
        cout << Flight_name[i] << "\t" << "\t";
        cout << Departure[i] << "\t" << "\t";
        cout << Arrival[i] << "\t" << "\t"<<endl;   
    }
}

// Classs 1 for Flight schedule
class Flight_Schedule
{
    public:
    string from, to;
    void Schedule()
    {
        cout << "\t         Select your Destination\n\n";
        cout << "\t         From : ";
        cin >> from;
        cout << "\t         To : ";
        cin >> to;
        cout << "\n-----------------------------Flight Schedule-----------------------------\n";
        cout << "\n";
        Flight_Schedule_info();
    }

};

// Class 2 for Flight booking
class Book_Flight
{
    public:
    string store[3];


    // Selecting Flight
    void Book()
    {
        cout << "\t         Select your Destination\n\n";
        cout << "\t         From : ";
        cin >> From[passenger_count];
        cout << "\t         To : ";
        cin >> To[passenger_count];
        cout << "\t         Date and Month : ";
        cin.ignore();
        getline(cin, D_M[passenger_count]);
        cout << "\n-----------------------------Flight Schedule-----------------------------\n";
        cout << "\n";
        Flight_Schedule_info();

        cout << "\nSelect your flight schedule (1-5): ";
        int sl;
        cin >> sl;
        if (sl >= 1 && sl <= 5)
         {
            string flight_name[] = {"Air Astra-3319", "Novo Air-1971", "US-Bangla-2441", "Novo Air-300", "BD Airline-44"};
            string departure[] = {"10:00 AM", "05:26 PM", "10:00 AM", "05:26 PM", "05:26 PM"};
            string arrival[] = {"12:45 AM", "07:26 PM", "01:25 PM", "08:36 PM", "09:26 PM"};
            Flight_name[passenger_count] = flight_name[sl - 1];
            Time[passenger_count] = arrival[sl - 1];
            Departure[passenger_count] = departure[sl - 1];
            Arrival[passenger_count] = arrival[sl - 1];
           
         }

        else
         {
            cout << "Invalid Choice ! Back to the main menu\n";
            interface();
         }
        
        cout << "\n";
        cout << "\t         Choice Your Cabin\n\n";
        cout << "\t         1.First Class\n";
        cout << "\t         2.Business Class\n";
        cout << "\t         3.Economy Class\n";
        cout << "\t         ---------------------------\n\n";
        cout << "\t         Enter you Choice : ";

        // Cabin choice
        int choice;
        cin>>choice;


        if(choice==1)
         {
            First_class F;
            F.availability(1);
            F.Fare_cost();
            CLASS[passenger_count]="First Class";
            
         }
        else if (choice==2)
         {
           Business_class B;
           B.availability(2);
           B.Fare_cost();
           CLASS[passenger_count]="Business Class";

         }
        else
         {
           Economy_class E;
           E.availability(3);
           E.Fare_cost();
           CLASS[passenger_count]="Economy Class";
         }

    }

    // Passenger Information
    void passenger_info()
    {

        cout << "\n----------Give your personal information----------\n";
        cout << "\nEnter your name : ";
        cin.ignore();
        getline(cin, Name[passenger_count]);
        cout << "Enter your address : ";
        getline(cin, Address[passenger_count]);
        cout << "Enter your age : ";
        cin >> Age[passenger_count];
        cout << "Enter phone number : ";
        cin >> Phone_number[passenger_count];
        CODE[passenger_count] = ticket_code();
        cout << "\nYou reserve a seat successfully \n";
        cout << "\nYou ticket code is : " << CODE[passenger_count];

        cout << "\n---------- *** Please keep remember your ticket code for future reference  ----------\n";

        File(passenger_count, Name[passenger_count], Address[passenger_count], Age[passenger_count], Phone_number[passenger_count], CODE[passenger_count]);
        passenger_count++;
    }
};

// Checking ticket information class
class Check_Ticket_Information
{
public:
    string temp_code;
    int choice;
    void c_t_inf_()
    {
        if (passenger_count == 0)
        {
            cout << "\n\t         No reservation made yet !\n";
        }
        else
        {
            cout << "\t         Enter your ticket code : ";
            cin >> temp_code;
            for (int i = 0; i < passenger_count; i++)
            {
                if (CODE[i] == temp_code)
                {

                    cout << "\n\n\n\t_____________ SRH Domestic Air Line _______________\n"
                         << endl;
                    cout << left << setw(20) << "FLIGHT -------------" << setw(30) << " BOARDING TIME -------------- " << "|\tCLASS: "<<CLASS[i] << endl;
                    cout << left << setw(20) << Flight_name[i] << setw(30) << "  10:00 PM" << "|\t" << endl;
                    cout << left << setw(50) << " " << "|\t" << endl;
                    cout << left << setw(20) << "PASSENGER NAME :" << setw(30) << Name[i] << "|\tTicket code: " << CODE[i] << endl;
                    cout << left << setw(20) << "FROM           :" << setw(30) << From[i] << "|\tTO: " << To[i] << endl;
                    cout << left << setw(20) << "Departure      :" << setw(30) << Departure[i] << "|\tArrival: " << Arrival[i] << endl;
                    cout << left << setw(20) << "DATE           :" << setw(30) << D_M[i] << "|\tSeat number:" << seat[i] << endl;
                    //cout << left << setw(50) << " " << "|\tSeat number:" << seat[i]<<endl;
                    cout << "\n\n";
                    return;
                }
            }
            cout << "Invalid Ticket Code!\nPlease try again";
            c_t_inf_();
        }
    }

};

void interface()
{

    // some variable declaration
    int back, choice;

    // object declaration
    Flight_Schedule F;
    Book_Flight B;
    Check_Ticket_Information C;

    cout << "\n\n";
    cout << "\t         1.Flight Schedule \n";
    cout << "\t         2.Book Flight \n";
    cout << "\t         3.Check Ticket Information\n";
    cout << "\t         4.Exit the Program\n";
    cout << "\t         ---------------------------\n\n";
    cout << "\t         Enter you Choice : ";

    cin >> choice;
    switch (choice)
    {

        case 1:
        {
            F.Schedule();
            cout << "\n\t         Press 1.Back to main menu\n";
            cout << "\t         Press 2.Exit the program \n";
            cout << "\t         press :  ";
            cin >> back;
            if (back == 1)
            {
                interface();
            }
            else
            {
                break;
            }
            break;
        }

        case 2:
        {
            cout << "\n---------------------------Book Flight---------------------------\n";
            B.Book();
            B.passenger_info();
            cout << "\n\t         Press 1.Back to main menu\n";
            cout << "\t         Press 2.Exit the program \n";
            cout << "\n\t         press :  ";
            cin >> back;
            if (back == 1)
            {
                interface();
            }
            else
            {
                break;
            }
            break;
        }
        case 3:
        {
            C.c_t_inf_();
            cout << "\n\t         Press 1.Back to main menu\n";
            cout << "\t         Press 2.Exit the program \n";
            cout << "\t         press :  ";
            cin >> back;
            if (back == 1)
            {
                interface();
            }
            else
            {
                break;
            }
            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            cout << "\t         Invalid Choice! Please try again \n";
            interface();
        }
    }
}

int main()
{
    cout << "\n\n";
    cout << "\t          ><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><->< \n";
    cout << "\t           Welcome to SRH Domestic Airline Reservation system \n";
    cout << "\t          ><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><->< \n";
    interface();
    cout << "\t          -----Thank you for visiting our applicatiion-----\n";
}
