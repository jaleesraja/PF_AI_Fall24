#include <iostream>
#include <cstdlib> // for rand()
using namespace std;
int main()
{
 // Variables 
 string choices[3] = {"Rock", "Paper", "Scissors"};
int playerChoice, botChoice;
int playerWins, botWins;
char playAgain;
 // random number generator
 do
{

 playerWins = 0;
 botWins = 0;
 cout << "Welcome to Rock, Paper, Scissors Game!" << endl;
cout << "Enter your choice: 0 for Rock, 1 for Paper, 2 for Scissors" << endl;
 // Play 3 rounds
while (playerWins < 2 && botWins < 2) 
{
cout << "\nRound " << (playerWins + botWins + 1) << "!" << endl;
 cout << "Your choice: ";
cin >> playerChoice;
 if (playerChoice < 0 || playerChoice > 2)
  {
cout << "Invalid choice! Please choose a number between 0 and 2." << endl;
 continue;// Restart the loop if input is invalid
 }
 botChoice = rand() % 3; // Random choice for bot
cout << "You choose: " << choices[playerChoice] << endl;
cout << "Bot chooses: " << choices[botChoice] << endl;
 if (playerChoice == botChoice) 
 {
cout << "It's a draw!" << endl;
} else if ((playerChoice == 0 && botChoice == 2) ||
(playerChoice == 1 && botChoice == 0) ||
(playerChoice == 2 && botChoice == 1))
 {
cout << "You win this round!" << endl;
playerWins++;
 }
else {
 cout << "Bot wins this round!" << endl;
botWins++;
 }
 // Display current score after each round
cout << "Current Score - You: " << playerWins << " | Bot: " << botWins << endl;
 }
 // Check who won the game
 if (playerWins == 2) 
 {
cout << "\nYou win the game!" << endl;
 } else {
 cout << "\nBot wins the game!" << endl;
 }
 // Ask if the player wants to play again
cout << "\nDo you want to play again? (Y/N): ";
cin >> playAgain;
 } while (playAgain == 'Y' || playAgain == 'y'); // Continue if the user wants to play again
cout << "Thanks for playing! Goodbye!" << endl;
return 0;
}
