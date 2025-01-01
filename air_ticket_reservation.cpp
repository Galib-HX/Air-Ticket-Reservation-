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
string Flight_name[max_passenger], Time[max_passenger], Fare[max_passenger], Departure[max_passenger], Arrival[max_passenger], D_M[max_passenger];

void info_txt();
void interface();
string ticket_code();
void Flight_Schedule_info();

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

// Classs 1 for Flight schedule
class Flight_Schedule
{

};

// Class 2 for Flight booking
class Book_Flight
{

};

// Checking ticket information class
class Check_Ticket_Information

{

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
