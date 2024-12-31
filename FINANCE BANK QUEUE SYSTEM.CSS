#include <iostream> 
#include <string> 
using namespace std; 
struct Client { 
string name; 
string service; 
Client* next; 
Client(const string& clientName, const string& clientService) 
: name(clientName), service(clientService), next(nullptr) {} 
}; 
class BankLine { 
private: 
Client* head; 
Client* tail; 
int count; 
public: 
BankLine() : head(nullptr), tail(nullptr), count(0) {} 
void addClient(const string& clientName, const string& 
serviceType) { 
Client* newClient = new Client(clientName, serviceType); 
if (tail) { 
tail->next = newClient; 
} else { 
head = newClient; 
} 
tail = newClient; 
count++; 
cout << "Added client '" << clientName << "' to the queue 
for " << serviceType << " service.\n"; 
} 
void processClient() { 
if (head) { 
Client* clientToProcess = head; 
head = head->next; 
if (!head) { 
tail = nullptr; 
} 
cout << "Processing client: '" << clientToProcess->name 
<< "' for " << clientToProcess->service << " service.\n"; 
delete clientToProcess; 
count--; 
} else { 
cout << "The queue is currently empty. No client to 
process.\n"; 
} 
} 
void displayQueue() { 
if (head) { 
cout << "Current clients in line:\n"; 
Client* temp = head; 
int position = 1; 
while (temp) { 
cout << position << ". " << temp->name << " (" << 
temp->service << ")\n"; 
temp = temp->next; 
position++; 
} 
} else { 
cout << "There are no clients in the queue.\n"; 
} 
} 
void showQueueCount() { 
cout << "There are currently " << count << " clients waiting 
in the queue.\n"; 
} 
void displayServiceStats() { 
if (head) { 
int depositCount = 0, withdrawalCount = 0, loanCount = 
0; 
Client* temp = head; 
while (temp) { 
if (temp->service == "Deposit") { 
depositCount++; 
} else if (temp->service == "Withdrawal") { 
withdrawalCount++; 
} else if (temp->service == "Loan") { 
loanCount++; 
} 
temp = temp->next; 
} 
cout << "Service statistics:\n"; 
cout << "Deposit: " << depositCount << " client(s)\n"; 
cout << "Withdrawal: " << withdrawalCount << " 
client(s)\n"; 
cout << "Loan: " << loanCount << " client(s)\n"; 
} else { 
cout << "No clients in the queue to gather statistics 
from.\n"; 
} 
} 
void clearLine() { 
while (head) { 
Client* temp = head; 
head = head->next; 
delete temp; 
} 
tail = nullptr; 
count = 0; 
cout << "The queue has been cleared.\n"; 
} 
~BankLine() { 
clearLine(); 
} 
}; 
void runBankLineSystem() { 
BankLine bankLine; 
int choice; 
do { 
cout << "\n--- Welcome to the Bank Queue System ---\n"; 
cout << "1. Add a client\n"; 
cout << "2. Process a client\n"; 
cout << "3. Show all clients in the queue\n"; 
cout << "4. Show the current queue size\n"; 
cout << "5. Show service statistics\n"; 
cout << "6. Clear the queue\n"; 
cout << "7. Exit\n"; 
cout << "Enter your choice: "; 
cin >> choice; 
cin.ignore(); // Ignore any leftover newline character 
switch (choice) { 
case 1: { 
string clientName, serviceType; 
cout << "Enter the client's name: "; 
char ch; 
clientName.clear(); 
while (true) { 
ch = cin.get(); 
if (ch == '\n') break; 
clientName += ch; 
} 
cout << "Enter the service type (Deposit, Withdrawal, 
Loan): "; 
serviceType.clear(); 
while (true) { 
ch = cin.get(); 
if (ch == '\n') break; 
serviceType += ch; 
} 
bankLine.addClient(clientName, serviceType); 
break; 
} 
case 2: 
bankLine.processClient(); 
break; 
case 3: 
bankLine.displayQueue(); 
break; 
case 4: 
bankLine.showQueueCount(); 
break; 
case 5: 
bankLine.displayServiceStats(); 
break; 
case 6: 
bankLine.clearLine(); 
break; 
case 7: 
cout << "Thank you for using the Bank Queue System. 
Goodbye!\n"; 
break; 
default: 
cout << "Invalid option. Please try again.\n"; 
} 
} while (choice != 7); 
} 
int main() { 
runBankLineSystem(); 
return 0; 
}
