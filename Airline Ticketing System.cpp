#include <iostream>
#include <string>
using namespace std;

class Flight {
public:
    string flightName;
    string destination;
    int totalSeats;
    int availableSeats;

    Flight(string name, string dest, int total) {
        flightName = name;
        destination = dest;
        totalSeats = total;
        availableSeats = total;
    }

    void displayFlightDetails() {
        cout << "Flight Name: " << flightName << endl;
        cout << "Destination: " << destination << endl;
        cout << "Available Seats: " << availableSeats << endl;
    }

    bool bookTicket(int numSeats) {
        if (numSeats <= availableSeats) {
            availableSeats -= numSeats;
            cout << numSeats << " ticket(s) booked successfully on " << flightName << endl;
            return true;
        } else {
            cout << "Not enough available seats." << endl;
            return false;
        }
    }

    void cancelTicket(int numSeats) {
        if (numSeats <= (totalSeats - availableSeats)) {
            availableSeats += numSeats;
            cout << numSeats << " ticket(s) cancelled successfully on " << flightName << endl;
        } else {
            cout << "No such booking to cancel." << endl;
        }
    }
};

class AirlineSystem {
private:
    Flight* flights[5];  
    int flightCount;

public:
    AirlineSystem() {
        flightCount = 0;
    }

    void addFlight(string name, string destination, int totalSeats) {
        if (flightCount < 5) {
            flights[flightCount] = new Flight(name, destination, totalSeats);
            flightCount++;
        } else {
            cout << "Cannot add more flights. Maximum limit reached." << endl;
        }
    }

    void displayFlights() {
        if (flightCount == 0) {
            cout << "No flights available." << endl;
        } else {
            for (int i = 0; i < flightCount; i++) {
                flights[i]->displayFlightDetails();
                cout << "---------------------------------" << endl;
            }
        }
    }

    void bookTicket() {
        string flightName;
        int numSeats;

        cout << "Enter Flight Name: ";
        cin >> flightName;
        cout << "Enter Number of Seats to Book: ";
        cin >> numSeats;

        bool flightFound = false;

        for (int i = 0; i < flightCount; i++) {
            if (flights[i]->flightName == flightName) {
                flightFound = true;
                flights[i]->bookTicket(numSeats);
                break;
            }
        }

        if (!flightFound) {
            cout << "Flight not found!" << endl;
        }
    }

    void cancelTicket() {
        string flightName;
        int numSeats;

        cout << "Enter Flight Name: ";
        cin >> flightName;
        cout << "Enter Number of Seats to Cancel: ";
        cin >> numSeats;

        bool flightFound = false;

        for (int i = 0; i < flightCount; i++) {
            if (flights[i]->flightName == flightName) {
                flightFound = true;
                flights[i]->cancelTicket(numSeats);
                break;
            }
        }

        if (!flightFound) {
            cout << "Flight not found!" << endl;
        }
    }

    ~AirlineSystem() {
        for (int i = 0; i < flightCount; i++) {
            delete flights[i];
        }
    }
};

int main() {
    AirlineSystem system;
    system.addFlight("EtihadAirways", "Frankfurt", 100);
    system.addFlight("TurkishAirlines", "Anatolia", 150);
    system.addFlight("EmiratesAirlines", "New York", 120);
    system.addFlight("QatarAirways", "Abu Dhabi", 200);
    system.addFlight("BrusselsAirlines", "Barcelona", 180);

    int choice;
    do {
        cout << "\nAirline Ticketing System Menu:" << endl;
        cout << "1. View Available Flights" << endl;
        cout << "2. Book a Ticket" << endl;
        cout << "3. Cancel a Ticket" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.displayFlights();
                break;
            case 2:
                system.bookTicket();
                break;
            case 3:
                system.cancelTicket();
                break;
            case 4:
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
