#include <iostream>
using namespace std;

struct Budget
 {
    double studentLoan, grants, parentsSupport, job, savings, otherIncome;
    double rent, travel, insurance, carBills, utilityBills, mobilePhone, tvLicence, food;
    double courseMaterial, clothing, socialActivities;
};

double calculateIncome(Budget &budget) {
    cout << "\nEnter your income details:\n";
    cout << "Student Loan: "; cin >> budget.studentLoan;
    cout << "Grants/Sponsorship: "; cin >> budget.grants;
    cout << "Parents/Guardians Support: "; cin >> budget.parentsSupport;
    cout << "Job Income: "; cin >> budget.job;
    cout << "Savings: "; cin >> budget.savings;
    cout << "Other Income: "; cin >> budget.otherIncome;

    return budget.studentLoan + budget.grants + budget.parentsSupport + budget.job + budget.savings + budget.otherIncome;
}

double calculateEssentialCosts(Budget &budget) {
    cout << "\nEnter your essential expenses per week:\n";
    cout << "Rent: "; cin >> budget.rent;
    cout << "Travel: "; cin >> budget.travel;
    cout << "Insurance: "; cin >> budget.insurance;
    cout << "Car Bills: "; cin >> budget.carBills;
    cout << "Utility Bills: "; cin >> budget.utilityBills;
    cout << "Mobile Phone: "; cin >> budget.mobilePhone;
    cout << "TV Licence: "; cin >> budget.tvLicence;
    cout << "Food: "; cin >> budget.food;

    return budget.rent + budget.travel + budget.insurance + budget.carBills + budget.utilityBills + budget.mobilePhone + budget.tvLicence + budget.food;
}

double calculateOtherCosts(Budget &budget) {
    cout << "\nEnter your other expenses per week:\n";
    cout << "Course Material: "; cin >> budget.courseMaterial;
    cout << "Clothing: "; cin >> budget.clothing;
    cout << "Social Activities: "; cin >> budget.socialActivities;

    return budget.courseMaterial + budget.clothing + budget.socialActivities;
}

int main() {
    Budget budget = {}; 
    int weeks, choice;
    double totalIncome = 0, totalEssentials = 0, totalOtherCosts = 0, weeklyIncome, remainingBudget;
     
    cout << "Welcome to the Budget Calculator!\n";
    cout << "Enter amounts in dollars ($). If not applicable, enter 0.\n";

    while (true) {
        cout << "\nMenu:\n1. Calculate Budget\n2. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter the number of weeks you'll attend university: ";
                cin >> weeks;

                totalIncome = calculateIncome(budget);
                cout << "\nTotal yearly income: $" << totalIncome;

                weeklyIncome = totalIncome / weeks;
                cout << "\nWeekly income: $" << weeklyIncome;

                totalEssentials = calculateEssentialCosts(budget);
                remainingBudget = weeklyIncome - totalEssentials;
                cout << "\nEssential expenses: $" << totalEssentials;
                cout << "\nRemaining after essentials: $" << remainingBudget;

                totalOtherCosts = calculateOtherCosts(budget);
                remainingBudget -= totalOtherCosts;
                cout << "\nOther expenses: $" << totalOtherCosts;
                cout << "\nRemaining budget after all expenses: $" << remainingBudget << "\n";
                break;

            case 2:
                cout << "Exiting the program. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid option. Please try again.\n";
        }
    }
}

