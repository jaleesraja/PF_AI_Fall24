#include <iostream>
#include <string>

using namespace std;
bool login()
{
	string useradmin, password;
	const string Useradmin = "Riphah";
	const string Password = "riphah";

	cout << "Enter admin: ";
	cin >> useradmin;
	cout << "Enter Password: ";
	cin >> password;

	if (Useradmin == useradmin && Password == password)
		{
			cout << "			Access granted" << endl;
			return true;
		}
	else
		{
			cout << "Invalid Choice, try later.";
			return false;
		}
}

void displaywelcomemessage() 
{
    cout << "WELCOME TO THE BANKING SYSTEM OF RIPHAH" << endl;
}

struct BankAccount 
{
    string accountHolder;
    int accountNumber;
    double balance;
};

const int MAX_ACCOUNTS = 100; 
BankAccount accounts[MAX_ACCOUNTS];
int currentAccountCount = 0; 

void createAccount() 
{
    if (currentAccountCount >= MAX_ACCOUNTS) 
    {
        cout << "Account limit reached. Cannot create more accounts.\n";
        return;
    }

    string name;
    int accountNumber;
    double initialBalance;

    cout << "Enter account holder's name: ";
    cin>>name; 
    
    cout << "Enter a unique account number of (10 digits): ";
    cin >> accountNumber;

    
    for (int i = 0; i < currentAccountCount; ++i) 
    {
        if (accounts[i].accountNumber == accountNumber) 
        {
            cout << "Account number already exists. Please enter a different account number.\n";
            return;
        }
    }

    cout << "Enter initial deposit amount: $";
    cin >> initialBalance;

    BankAccount newAccount = {name, accountNumber, initialBalance};
    accounts[currentAccountCount] = newAccount;
    currentAccountCount++;

    cout << "Account created successfully!\n";
}

BankAccount* findAccount(int accountNumber) 
{
    for (int i = 0; i < currentAccountCount; ++i) 
    {
        if (accounts[i].accountNumber == accountNumber) 
        {
            return &accounts[i];
        }
    }
    return NULL;  
}

void depositMoney(int accountNumber) 
{
    double amount;
    BankAccount* account = findAccount(accountNumber);
    if (account != NULL)  
    {
        cout << "Enter deposit amount: $";
        cin >> amount;
        if (amount > 0) 
        {
            account->balance += amount;
            cout << "Deposited: $" << amount << "\n";
        } 
        else 
        {
            cout << "Invalid deposit amount.\n";
        }
    } 
    else 
    {
        cout << "Account not found.\n";
    }
}

void withdrawMoney(int accountNumber) 
{
    double amount;
    BankAccount* account = findAccount(accountNumber);
    if (account != NULL)  
    {
        cout << "Enter withdrawal amount: $";
        cin >> amount;
        if (amount > 0 && amount <= account->balance) 
        {
            account->balance -= amount;
            cout << "Withdrawn: $" << amount << "\n";
           cout<<"Your Current Balance is : $"<<account->balance<< "\n";
        } 
        else 
        {
            cout << "Invalid withdrawal amount or insufficient funds.\n";
        }
    } 
    else 
    {
        cout << "Account not found.\n";
    }
}

void checkBalance(int accountNumber) 
{
    BankAccount* account = findAccount(accountNumber);
    if (account != NULL)  
    {
        cout << "Your Current balance is: $" << account->balance << "\n";
    } 
    else 
    {
        cout << "Account not found.\n";
    }
}

void displayAccountInfo(int accountNumber) 
{
    BankAccount* account = findAccount(accountNumber);
    if (account != NULL)  
    {
        cout << "Account Holder Name: " << account->accountHolder << "\n";
        cout << "Account Number: " << account->accountNumber << "\n";
        checkBalance(accountNumber);
    } 
    else 
    {
        cout << "Account not found.\n";
    }
}

void displayAllAccounts() 
{
    if (currentAccountCount == 0) 
    {
        cout << "No accounts available.\n";
    } 
    else 
    {
        for (int i = 0; i < currentAccountCount; ++i) 
        {
            cout << "Account Holder Name: " << accounts[i].accountHolder << "\n";
            cout << "Account Number: " << accounts[i].accountNumber << "\n";
            cout << "Balance: $" << accounts[i].balance << "\n";
            cout << "-------------------------\n";
        }
    }
}

int main()
{

int choice;
	if (!login())
		{
			return 1;
		} 

    char enter;
    displaywelcomemessage();
    cout << "Enter any key and press Enter to continue...";
    cin >> enter;
    
    int choices;

    while (true) 
    {
        cout << "\nBanking System Menu:\n";
        cout << "1. Create a new account\n";
        cout << "2. Deposit money\n";
        cout << "3. Withdraw money\n";
        cout << "4. Check balance\n";
        cout << "5. Display all accounts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choices;

        if (choices == 1) 
        {
            createAccount();
        } 
        else if (choices == 2) 
        {
            int accountNumber;
            cout << "Enter account number: ";
            cin >> accountNumber;
            depositMoney(accountNumber);
        } 
        else if (choices == 3) 
        {
            int accountNumber;
            cout << "Enter account number: ";
            cin >> accountNumber;
            withdrawMoney(accountNumber);
        }
        else if (choices == 4) 
        {
            int accountNumber;
            cout << "Enter account number: ";
            cin >> accountNumber;
            checkBalance(accountNumber);
        }
        else if (choices == 5) 
        {
            displayAllAccounts();
        } 
        else if (choices == 6) 
        {
            cout << "Exiting From the system...\n";
            break;
        } 
        else 
        {
            cout << "Invalid choice! Please try again.\n";
        }
    }
    cout<<"THANK YOU ";
    return 0;
}
