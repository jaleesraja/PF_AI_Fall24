#include <iostream>
#include <string> using namespace std; const int total_seats = 100;
void begin_system(); void book_tickets(); void cancel_tickets(); void display_booked_tickets();
bool login();
struct Ticket
{
string passenger_name;
int seat_num;
};
Ticket economyTickets[total_seats]; Ticket businessTickets[total_seats]; bool isEconomySeatBooked[total_seats]; bool business_seats_booked[total_seats]; int economyBookedCount = 0; int business_booked_cont = 0;
int main()
{
int choice; if (!login())
{
return 1;
}
begin_system();
do
{ cout << endl << “Railway Reservation System" << endl; cout << endl << "Enter '1' to Book Ticket." << endl; cout << "Enter '2' to Cancel Ticket." << endl; cout << "Enter '3' to Display Booked Tickets." << endl; cout << "Enter '4' to Exit." << endl;
cout << "Enter your choice: " << endl; cin >> choice;
switch (choice)
{
case 1: book_tickets(); break; case 2:
cancel_tickets(); break;
case 3: display_booked_tickets();
break; case 4:
cout << "Exiting..." << endl;
exit(0); default:
cout << "Invalid choice. Please try again." << endl;
}
}
while (choice != 4);
return 0;
}
bool login()
{
string useradmin, password; const string Useradmin = "Fawad";
const string Password = "12345";
cout << "Enter admin: "; cin >> useradmin; cout << "Enter Password: "; cin >> password;
cout<< "1st day free ticket for opening:";
if (Useradmin == useradmin && Password == password)
{
cout << " Access granted" << endl;
cout << "Welcome to Ticket reservation system." << endl;
return true;
} else
{
cout << "Invalid Choice, try later."; return false;
}
}
void begin_system()
{ for (int i = 0; i < total_seats; i++)
{
isEconomySeatBooked[i] = false;
business_seats_booked[i] = false;
}
}
void book_tickets()
{
char classtype;
cout << "Choose the class in which you want to book the seat." << endl; cout << "Enter 'B' for Business class ." << endl;
cout << "Enter 'E' for Economy class ." << endl;
cin >> classtype;
if ( (classtype != 'B') && (classtype != 'E'))
{
cout << "Invalid class type. Please try again." << endl;
return;
}
Ticket* ticket_storage; bool* seat_booked_storage;
int* bookedCountPtr;
if (classtype == 'B')
{
ticket_storage = businessTickets; seat_booked_storage = business_seats_booked;
bookedCountPtr = &business_booked_cont;
}
else {
ticket_storage = economyTickets; seat_booked_storage = isEconomySeatBooked;
bookedCountPtr = &economyBookedCount;
}
if (*bookedCountPtr >= total_seats)
{
cout << "All seats in the selected class are booked. No more tickets can be booked." << endl;
return;
}
string name;
int seat_num;
cout << "Enter passenger name: "; cin >> name;
cout << "Enter seat number (1-" << total_seats << "): "; cin >> seat_num; if (seat_num < 1 || seat_num > total_seats)
{
cout << "Invalid seat number. Please try again." << endl;
return;
}
if (seat_booked_storage[seat_num - 1])
{
cout << "Seat already booked. Please choose a different seat." << endl;
return;
}
ticket_storage[*bookedCountPtr].passenger_name = name; ticket_storage[*bookedCountPtr].seat_num = seat_num; seat_booked_storage[seat_num - 1] = true;
(*bookedCountPtr)++;
if (classtype == 'B')
{
cout << "Your ticket is booked successfully! You booked a business class ticket." << endl;
cout << " Thank you for using our service." << endl;
}
else
{
cout << "Your ticket is booked successfully! You booked an Economy class ticket." << endl;
cout << "Thank you for using our service." << endl;
}
}
void cancel_tickets()
{
int seat_num;
cout << "Enter seat number to cancel: ";
cin >> seat_num;
if (seat_num < 1 || seat_num > total_seats)
{
cout << "Invalid seat number. Please try again." << endl; return;
}
Ticket* ticket_storage; bool* seat_booked_storage; int* bookedCountPtr;
if (business_seats_booked[seat_num - 1])
{
ticket_storage = businessTickets;
seat_booked_storage = business_seats_booked;
bookedCountPtr = &business_booked_cont;
}
else if (isEconomySeatBooked[seat_num - 1])
{
ticket_storage = economyTickets; seat_booked_storage = isEconomySeatBooked;
bookedCountPtr = &economyBookedCount;
}
else
{
cout << "Invalid or unbooked seat number. Please try again." << endl;
return;
}
for (int i = 0; i < *bookedCountPtr; i++)
{
if (ticket_storage[i].seat_num == seat_num)
{
seat_booked_storage[seat_num - 1] = false;
for (int j = i; j < *bookedCountPtr - 1; j++)
{
ticket_storage[j] = ticket_storage[j + 1];
}
(*bookedCountPtr);
cout << "Ticket cancelled successfully!" << endl;
return;
}
}
cout << "Invalid or unbooked seat number. Please try again." << endl;
}
void display_booked_tickets()
{
bool isEmpty = true;
cout << "Booked Tickets:" << endl;
for (int i = 0; i < business_booked_cont; i++)
{
cout << "Business Class - Seat Number: " << businessTickets[i].seat_num << ",
Passenger Name: " << businessTickets[i].passenger_name << endl; isEmpty = false;
}
for (int i = 0; i < economyBookedCount; i++)
{
cout << "Economy Class - Seat Number: " << economyTickets[i].seat_num << ",
Passenger Name: " << economyTickets[i].passenger_name << endl;
isEmpty = false;
}
if (isEmpty)
{
cout << "No tickets booked." << endl;
}
}