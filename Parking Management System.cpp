#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <iomanip> // For setting precision in output

// Platform-specific includes
#ifdef _WIN32
#include <windows.h> // For Windows console text color
#endif

using namespace std;

// ANSI escape codes for Linux/macOS (Unix-based systems)
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

// Platform-specific functions to change text color
#ifdef _WIN32
void SetConsoleColor(int color) 
{
    // Change text color for Windows
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
#else
// No special function needed for Linux/macOS since ANSI escape codes are used
#define SetConsoleColor(color) // Empty macro, as it's not needed
#endif

// Structure that contains car details
struct CarDetails 
{
    string carNumber;
    int row;
    int column;
    time_t entryTime;
};

class ParkingManagementSystem 
{
private:
    map<string, CarDetails> parkingData; // Maps car number to details
    const int rows = 10;
    const int columns = 10;
    bool parkingLot[10][10] = { false }; // 10x10 parking lot grid

    // Function to calculate parking fee based on the time spent
    double calculateParkingFee(double duration) 
    {
        const double hourlyRate = 1.0; // $ per hour
        const double minimumFee = 1.0; // Minimum fee
        double fee = (duration / 3600) * hourlyRate; // Convert seconds to hours
        return (fee < minimumFee) ? minimumFee : fee;
    }

public:
    void parkCar(const string& carNumber, int row, int column) 
    {
        if (row < 0 || row >= rows || column < 0 || column >= columns) 
        {
            cout << "Invalid parking spot. Please choose a valid spot.\n";
            return;
        }

        if (parkingLot[row][column]) 
        {
            cout << "Spot already occupied. Please choose another spot.\n";
            return;
        }

        CarDetails car;
        car.carNumber = carNumber;
        car.row = row;
        car.column = column;
        car.entryTime = time(nullptr);

        parkingData[carNumber] = car;
        parkingLot[row][column] = true;

        cout << "Car " << carNumber << " parked at row " << row << " and column " << column << ".\n";
    }

    void retrieveCar(const string& carNumber) 
    {
        if (parkingData.find(carNumber) == parkingData.end()) 
        {
            cout << "Car with number " << carNumber << " not found.\n";
            return;
        }

        CarDetails car = parkingData[carNumber];
        time_t exitTime = time(nullptr);
        double timeSpent = difftime(exitTime, car.entryTime); // Time in seconds
        
         cout << "Car " << carNumber << " was parked at row " << car.row
             << " and column " << car.column << ".\n";
        cout << "Time spent in parking: " << timeSpent << " minutes.\n";

        // Calculate the parking fee
        double fee = calculateParkingFee(timeSpent);

        // Output parking details
        cout << "Car " << carNumber << " has been removed from the parking lot." << endl;
        cout << "Parked for: " << timeSpent / 3600 << " hours (" << timeSpent / 60 << " minutes)." << endl;
        cout << "Parking fee: $" << fixed << setprecision(2) << fee << endl;

        parkingLot[car.row][car.column] = false;
        parkingData.erase(carNumber);
    }

    void displayParkingLot() 
    {
        cout << "\nParking Lot Status:\n";
        for (int i = 0; i < rows; ++i) 
        {
            for (int j = 0; j < columns; ++j) 
            {
                // Color 'X' as red and 'O' as green based on the platform
                if (parkingLot[i][j]) 
                {
                    SetConsoleColor(12); // Red on Windows
                    cout << "X ";
                    SetConsoleColor(7);  // Reset color to default (White)
                } 
                else 
                {
                    SetConsoleColor(10); // Green on Windows
                    cout << "O ";
                    SetConsoleColor(7);  // Reset color to default (White)
                }
            }
            cout << "\n";
        }
    }
};

int main() 
{
    ParkingManagementSystem parkingSystem;

    int choice;
    string carNumber;
    int row, column;

    while (true) 
    {
        cout << "\nParking Management System" << endl;
        cout << "\n1. Park a car\n";
        cout << "2. Retrieve a car\n";
        cout << "3. Display parking lot\n";
        cout << "4. Exit\n" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "Enter car number: ";
            cin >> carNumber;
            cout << "Enter row and column to park (0-indexed): ";
            cin >> row >> column;
            parkingSystem.parkCar(carNumber, row, column);
            break;
        case 2:
            cout << "Enter car number to retrieve: ";
            cin >> carNumber;
            parkingSystem.retrieveCar(carNumber);
            break;
        case 3:
            parkingSystem.displayParkingLot();
            break;
        case 4:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}