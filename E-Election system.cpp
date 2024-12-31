#include <iostream> 
#include <map> 
#include <set> 
#include <string> 
using namespace std;

// Define Candidate and Area structs 
struct Candidate {
    string name;
    string party;
    int votes;
};

struct Area {
    Candidate candidates[4];
};

// Array to hold all areas 
Area areas[5];

// Set to track CNICs that have voted 
set<string> votedCNICs;

// Function to initialize candidate data 
void initializeCandidates() {
    areas[0].candidates[0] = { "Imran", "Party A", 0 };
    areas[0].candidates[1] = { "Nawaz", "Party B", 0 };
    areas[0].candidates[2] = { "Bilawal", "Party C", 0 };
    areas[0].candidates[3] = { "Naeem", "Party D", 0 };

    areas[1].candidates[0] = { "Imran", "Party A", 0 };
    areas[1].candidates[1] = { "Nawaz", "Party B", 0 };
    areas[1].candidates[2] = { "Bilawal", "Party C", 0 };
    areas[1].candidates[3] = { "Naeem", "Party D", 0 };


    areas[2].candidates[0] = { "Imran", "Party A", 0 };
    areas[2].candidates[1] = { "Nawaz", "Party B", 0 };
    areas[2].candidates[2] = { "Bilawal", "Party C", 0 };
    areas[2].candidates[3] = { "Naeem", "Party D", 0 };

    areas[3].candidates[0] = { "Imran", "Party A", 0 };
    areas[3].candidates[1] = { "Nawaz", "Party B", 0 };
    areas[3].candidates[2] = { "Bilawal", "Party C", 0 };
    areas[3].candidates[3] = { "Naeem", "Party D", 0 };

    areas[4].candidates[0] = { "Imran", "Party A", 0 };
    areas[4].candidates[1] = { "Nawaz", "Party B", 0 };
    areas[4].candidates[2] = { "Bilawal", "Party C", 0 };
    areas[4].candidates[3] = { "Naeem", "Party D", 0 };
}

// Function to get the area based on CNIC 
int getAreaByCNIC(string cnic) {
    int firstDigit = cnic[0] - '0';
    if (firstDigit == 1) return 0;  // Area 1 
    if (firstDigit == 2) return 1;  // Area 2 
    if (firstDigit == 3) return 2;  // Area 3 
    if (firstDigit == 4) return 3;  // Area 4 
    if (firstDigit == 5) return 4;  // Area 5 
    return -1; // Invalid CNIC 
}

// Function to display candidates in the selected area 
void displayCandidates(int areaIndex) {
    cout << "Candidates for this area:\n";
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". " << areas[areaIndex].candidates[i].name
            << " (" << areas[areaIndex].candidates[i].party << ")\n";
    }
}

// Function to handle voting 
void vote(int areaIndex, int candidateIndex) {
    areas[areaIndex].candidates[candidateIndex].votes++;
}

// Function to display election results 
void displayResults() {
    map<string, int> partyVotes;
    int areaWinner[5];

    // Count votes for each party 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            partyVotes[areas[i].candidates[j].party] +=
                areas[i].candidates[j].votes;
        }
    }

    // Find the winning party 
    string winningParty;
    int maxVotes = -1;
    for (auto& party : partyVotes)
    {
        if (party.second > maxVotes) {
            winningParty = party.first;
            maxVotes = party.second;
        }
    }

    cout << "\nThe winning party is: " << winningParty << " with " << maxVotes << " votes.\n"; 

        // Find the winning candidate in each area 
        for (int i = 0; i < 5; i++) {
            int areaMaxVotes = areas[i].candidates[0].votes;
            int areaWinnerIndex = 0;

            for (int j = 1; j < 4; j++) {
                if (areas[i].candidates[j].votes > areaMaxVotes) {
                    areaMaxVotes = areas[i].candidates[j].votes;
                    areaWinnerIndex = j;
                }
            }
            areaWinner[i] = areaWinnerIndex;
            cout << "In Area " << i + 1 << ", the winner is "
                << areas[i].candidates[areaWinnerIndex].name << " from "
                << areas[i].candidates[areaWinnerIndex].party << ".\n";
        }
}

// Main program logic 
int main() {
    int mode;
    string cnic, adminCode;
    bool electionRunning = true;

    // Initialize candidate data 
    initializeCandidates();

    // Main election loop 
    while (electionRunning) {
        cout << "\nSelect Mode: \n1. Citizen Mode\n2. Admin Mode\nEnter option(1 or 2): "; 
            cin >> mode;

        if (mode == 1) {
            // Citizen voting logic 
            cout << "Enter your CNIC (13 digits): ";
            cin >> cnic;

            if (cnic.length() == 13) {
                // Check if CNIC already voted 
                if (votedCNICs.find(cnic) != votedCNICs.end()) {
                    cout << "You have already voted!\n";
                    continue;
                }

                int areaIndex = getAreaByCNIC(cnic);
                if (areaIndex != -1) {
                    cout << "You are assigned to Area " << areaIndex + 1 << ".\n";
                    displayCandidates(areaIndex);

                    int candidateChoice;
                    cout << "Enter the candidate number to vote for (1-4): ";
                    cin >> candidateChoice;

                    if (candidateChoice >= 1 && candidateChoice <= 4) {
                        vote(areaIndex, candidateChoice - 1);
                        votedCNICs.insert(cnic);  // Mark CNIC as voted 
                        cout << "Thank you for voting!\n";
                    }
                    else {
                        cout << "Invalid choice. Please select a valid 
                            candidate.\n"; 
                    }
                }
                else {
                    cout << "Invalid CNIC. Please try again.\n";
                }
            }
            else {
                cout << "Invalid CNIC length. Please try again.\n";
            }
        }
        else if (mode == 2) {
            // Admin access logic 
            cout << "Enter Admin Code: ";
            cin >> adminCode;

            if (adminCode == "1122") {
                cout << "Admin access granted.\n";
                cout << "Ending the election and displaying results...\n";
                displayResults();
                electionRunning = false;
            }
            else {
                cout << "Incorrect admin code. Access denied.\n";
            }
        }
        else {
            cout << "Invalid mode selected. Please try again.\n";
        }
    }

    return 0;
}