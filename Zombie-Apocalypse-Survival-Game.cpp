// Ahsan
#include <iostream>
#include <string>
using namespace std;

void startGame();
void peopleRunning();
void accident();
void findfamily();
void ontheRoad();
void fightingZombie();
void escapeCity();
void anotherCity();
void Scene3();
void train();


int main()
{
	startGame();
	train();
	Scene3();
	system("pause");
	return 0;
}




void startGame()
{
	string choice;
	cout << "Welcome to the survival game!" << endl;
	cout << "You are taking your family to the park. Do you want to take a right or left?" << endl;
	cout << "Type 'right' or 'left' to choose a path: ";
	cin >> choice;
	if (choice == "right")
	{
		peopleRunning();
	}
	else if (choice == "left")
	{
		accident();
	}
	else
	{
		cout << "Invalid choice. Please restart the game." << endl;
	}
}

void peopleRunning()
{
	string choice;
	cout << "You chose right." << endl;
	cout << "You see people running toward your car." << endl;
	cout << "You get out of your car to check." << endl;
	cout << "You see some people biting others. Do you want to investigate or get in the car?" << endl;
	cout << "Type 'investigate' or 'car': ";
	cin >> choice;

	if (choice == "investigate")
	{
		cout << "You decided to investigate. As you get close, a zombie bites you: Game over." << endl;
	}
	else if (choice == "car")
	{
		cout << "You quickly get back in the car and drive away." << endl;
		findfamily();
	}
	else
	{
		cout << "Invalid choice. Please restart the game." << endl;
	}
}

void accident()
{
	string choice;
	cout << "You chose left." << endl;
	cout << "As you turn left, a car crashes into yours." << endl;
	cout << "You lose consciousness." << endl;
	cout << "You wake up in a house, and your family is not with you. Do you want to 'call' or 'check their location'?" << endl;
	cout << "Type 'call' or 'location': ";
	cin >> choice;

	if (choice == "call")
	{
		cout << "Due to no reception, you can't call them." << endl;
	}
	else if (choice == "location")
	{
		cout << "You found out your family is safe but far from this town." << endl;
		findfamily();
	}
	else
	{
		cout << "Invalid choice. Please restart the game." << endl;
	}
}

void findfamily()
{
	string choice;
	cout << "You know where your family is and decide to track their location." << endl;
	cout << "You gather supplies and have two choices: travel by car or on foot." << endl;
	cout << "Type 'car' or 'foot': ";
	cin >> choice;

	if (choice == "car")
	{
		cout << "The car attracted too much attention, and zombies rushed to your car. Game over." << endl;
	}
	else if (choice == "foot")
	{
		cout << "You hit the road on foot to find your family." << endl;
		ontheRoad();
	}
	else
	{
		cout << "Invalid choice. Please restart the game." << endl;
	}
}

void ontheRoad()
{
	string choice;
	cout << "You are surviving well on supplies and have been traveling for 10 days." << endl;
	cout << "Night falls, and you hear zombies running toward you. You see a village nearby." << endl;
	cout << "Do you want to fight or flee to the village?" << endl;
	cout << "Type 'fight' or 'village': ";
	cin >> choice;

	if (choice == "fight")
	{
		cout << "You tried to fight, but there were too many zombies. Game over." << endl;
	}
	else if (choice == "village")
	{
		cout << "You successfully escaped to the village." << endl;
		fightingZombie();
	}
	else
	{
		cout << "Invalid choice. Please restart the game." << endl;
	}
}

void fightingZombie()
{
	string choice;
	cout << "You safely arrived at the village." << endl;
	cout << "The villagers are preparing to fight the zombies." << endl;
	cout << "Do you throw a grenade or dig a trench?" << endl;
	cout << "Type 'grenade' or 'trench': ";
	cin >> choice;

	if (choice == "trench")
	{
		cout << "The trench wasn't deep enough, and zombies entered the village. Game over." << endl;
	}
	else if (choice == "grenade")
	{
		cout << "You threw grenades and killed all the zombies." << endl;
		escapeCity();
	}
	else
	{
		cout << "Invalid choice. Please restart the game." << endl;
	}
}

void escapeCity()
{
	string choice;
	cout << "You successfully fought off the zombies." << endl;
	cout << "To leave the city, you can either build a raft or take a bike." << endl;
	cout << "Type 'raft' or 'bike': ";
	cin >> choice;

	if (choice == "raft")
	{
		cout << "You chose a raft and escaped the city." << endl;
		anotherCity();
	}
	else if (choice == "bike")
	{
		cout << "You chose a bike, but it ran out of fuel. Game over." << endl;
	}
	else
	{
		cout << "Invalid choice. Please restart the game." << endl;
	}
}

void anotherCity()
{
	cout << "You reached another city safely and are closer to reuniting with your family. Congratulations!" << endl;
}




// Afaq


void train() {



	struct Game

	{
		void start()
		{
			cout << endl << endl;
			cout << "Welcome to the Zombie Apocalypse Train Game!" << endl;
			cout << "You are on a train, and you don't know that a zombie apocalypse is happening." << endl;
			mainLoop();
		}
		void mainLoop()
		{
			string action;

			cout << "John decides to go to the back cabin. Type 'go' to continue:" << endl;
			cin >> action;

			switch (action[0])
			{
			case 'g':
				discoverZombies();
				break;
			default:
				cout << "Invalid action. Game over." << endl;
				break;
			}
		}

		void discoverZombies()
		{
			string weapon;

			cout << "John finds zombies in the back cabin!" << endl;
			cout << "He rush back to inform others" << endl;
			cout << "they need to find something to kill zombie." << endl;
			cout << "Type 'find' to search for a weapon:" << endl;
			cin >> weapon;

			switch (weapon[0])
			{
			case 'f':
				cout << "John finds a crowbar!" << endl;
				cout << "Alex finds a axe" << endl;
				cout << "Happy finds a hammer" << endl;
				escapeTrain();
				break;
			default:
				cout << "Invalid action. Game over." << endl;
				break;
			}
		}

		void escapeTrain()
		{
			string decision;

			cout << "At the next station, John and the others try to leave the train." << endl;
			cout << "But there are more zombies at the station!" << endl;
			cout << "They kill some zombie but there are to many so they decide to go back " << endl;
			cout << "Type 'back' to return to the train cabin for safety:" << endl;
			cin >> decision;

			switch (decision[0])
			{
			case 'b':
				cout << "They safely return to the train cabin." << endl;
				trainEscape();
				break;
			default:
				cout << "Invalid action. Game over." << endl;
				break;
			}
		}
		void trainEscape()
		{
			string go;

			cout << "The train reaches the next station." << endl;
			cout << "A zombie bites one of the passengers!" << endl;
			cout << "The remaining passengers fight back and run towards the train." << endl;
			cout << "Unfortunately, everyone except John, his daughter, and another woman is infected." << endl;
			cout << "John, who is bitten, locks himself and the other zombies in the train." << endl;
			cout << "He tells his daughter and the woman to leave the train for their safety." << endl;
			cout << "John and the others are trapped in the train." << endl;
			cout << "Type 'continues' to further: " << endl;
			cin >> go;

			switch (go[0])
			{
			case 'c':
				cout << "The game continues." << endl;
				break;
			default:
				cout << "Invalid action. Game over." << endl;
				break;
			}
		}
	};


	Game game;
	game.start();

}









// Affan


void Scene3()
{
	cout << endl << endl;
	int mainChoice;
	// Scenario 3
	cout << "Scene 3:\n" << endl;
	cout << "Find the cure and save your family.\n\n" << endl;
	cout << "In a world shattered by a zombie apocalypse, your mission is clear: Find the cure and save your family. The air is thick with the stench of decay, and the distant groans of the undead remind you of the risks that lie ahead. With steely resolve, you stand at a crucial decision point.\n\n" << endl;

	do
	{
		cout << "What will you do next? Here are your options:" << endl;
		cout << endl;
		cout << "1. Infiltrate the Zombie Nest - Attempt to gather supplies and information from the heart of the zombie-infested area." << endl;
		cout << "2. Join Forces with Survivors - Seek out other survivors to form a temporary alliance in your quest for safety." << endl;
		cout << "3. Search for a Safe Haven - Venture into the wilderness in search of a rumored safe location away from the chaos." << endl;
		cout << endl;
		cout << "Enter your option: ";
		cin >> mainChoice;
		system("cls");

		if (mainChoice < 1 || mainChoice > 3)
		{
			cout << "Invalid Option. Please try again." << endl;
		}

	} while (mainChoice < 1 || mainChoice > 3);

	// Clear Screen
	system("cls");

	// Outer Switch
	switch (mainChoice)
	{
		// Option 1
	case 1:
	{
		int subChoice;
		cout << "You chose to Infiltrate the Zombie Nest.\n" << endl;
		cout << "You decide to Infiltrate the Zombie Nest, believing that valuable supplies or information could be hidden within.\n\n" << endl;

		do
		{
			cout << "What will you do next? Here are your options:\n" << endl;
			cout << "1. Create a distraction to lure zombies away." << endl;
			cout << "2. Sneak in quietly and attempt to grab supplies. (Risk of being overwhelmed by zombies?possible death!)\n" << endl;
			cout << "Enter your option: ";
			cin >> subChoice;
			system("cls");

			if (mainChoice < 1 || mainChoice > 3)
			{
				cout << "Invalid Option. Please try again." << endl;
			}

		} while (mainChoice < 1 || mainChoice > 3);

		system("cls");

		// Inner Switch 1
		switch (subChoice)
		{

			// Option 1.1
		case 1:
		{
			cout << "You chose to create a distraction to lure zombies away.\n" << endl;
			cout << "You grab some cans and start making noise, allowing you to slip into the nest as the zombies shuffle away. Inside, you spot a medical kit and, to your delight, a vial labeled \"Cure\". \n" << endl;
			cout << "You?ve successfully found the cure!" << endl;
			cout << "\n\n\n\nConclusion:\n" << endl;
			cout << "The choices you made led to different paths, each with its own outcome. In the end, you successfully found the cure and saved your family through specific choices, while others choices led to unfortunate demise.\n" << endl;
			cout << "Whether you emerged victorious or fell to the horrors of the apocalypse, your journey is a testament to the struggle for survival amidst chaos.\n\n" << endl;
			break;
		}
		// Option 1.2
		case 2:
		{
			cout << "You tiptoe into the nest, but a loose floorboard creaks under your weight. The zombies notice you immediately and swarm you. You fight valiantly, but the overwhelming numbers prove too much.\n\n" << endl;
			cout << "Outcome: You are overrun and succumb to the horde.\n" << endl;
			cout << "Mission Failed: Please try again.\n" << endl;
			Scene3();
		}
		}
		break;
	}

	// Option 2
	case 2:
	{
		int subChoice;
		cout << "You chose to Join Forces with Survivors\n" << endl;
		cout << "Realizing the importance of numbers, you choose to Join Forces with Survivors." << endl;

		do
		{
			cout << "What will you do next? Here are your options:\n" << endl;
			cout << "1. Approach a group cautiously and offer your skills. (Potential to be betrayed?possible death!)" << endl;
			cout << "2. Attempt to trade supplies but risk confrontation with a hostile group.\n" << endl;
			cout << "Enter your option: ";
			cin >> subChoice;

			system("cls");

			if (mainChoice < 1 || mainChoice > 3)
			{
				cout << "Invalid Option. Please try again." << endl;
			}

		} while (mainChoice < 1 || mainChoice > 3);

		// Inner Switch 2
		switch (subChoice)
		{
			// Option 2.1
		case 1:
		{
			cout << "You chose to approach a group cautiously and offer your skills." << endl;
			cout << "You approach a wary group and offer your hunting skills. They agree to let you join, and together, you hunt for supplies. After some successful foraging, you stumble upon documents that detail a lab where the cure is being developed.\n\n" << endl;
			cout << "Mission Successful: You?ve found the location of the cure!" << endl;
			cout << "\n\n\n\nConclusion:\n" << endl;
			cout << "The choices you made led to different paths, each with its own outcome. In the end, you successfully found the cure and saved your family through specific choices, while others choices led to unfortunate demise.\n" << endl;
			cout << "Whether you emerged victorious or fell to the horrors of the apocalypse, your journey is a testament to the struggle for survival amidst chaos.\n\n" << endl;
			break;
		}
		// Option 2.2
		case 2:
		{
			cout << "You chose to attempt to trade supplies but risk confrontation with a hostile group." << endl;
			cout << "You approach a hostile group to trade supplies, but they turn aggressive. You find yourself in a desperate fight, and despite your best efforts, you?re outnumbered and fall in battle.\n\n" << endl;
			cout << "Outcome: Your attempt at negotiation leads to your demise.\n" << endl;
			cout << "Mission Failed: Please try again.\n" << endl;
			Scene3();
		}
		}
		break;
	}

	// Option 3
	case 3:
	{
		int subChoice;
		cout << "You choose to Search for a Safe Haven, hoping to find refuge and possibly the cure.\n" << endl;

		do
		{
			cout << "What will you do next? Here are your options:\n" << endl;
			cout << "1. Follow a dangerous trail rumored to lead to safety. (High chance of encountering a zombie horde?possible death!)" << endl;
			cout << "2. Set up camp in a known safe area but risk being discovered by roaming zombies.\n" << endl;
			cout << "Enter your option: ";
			cin >> subChoice;

			system("cls");

			if (mainChoice < 1 || mainChoice > 3)
			{
				cout << "Invalid Option. Please try again." << endl;
			}

		} while (mainChoice < 1 || mainChoice > 3);

		// Inner Switch 3
		switch (subChoice)
		{
			// Option 3.1
		case 1:
		{
			cout << "You chose to follow a dangerous trail rumored to lead to safety.\n" << endl;
			cout << "You take the perilous trail, facing numerous undead along the way. Just when you think you?re finished, you find a hidden stash of medical supplies, including the cure!\n\n" << endl;
			cout << "Mission Successful: You have successfully found the cure in the wilderness!" << endl;
			cout << "\n\n\n\nConclusion:\n" << endl;
			cout << "The choices you made led to different paths, each with its own outcome. In the end, you successfully found the cure and saved your family through specific choices, while others choices led to unfortunate demise.\n" << endl;
			cout << "Whether you emerged victorious or fell to the horrors of the apocalypse, your journey is a testament to the struggle for survival amidst chaos.\n\n" << endl;
			break;
		}
		// Option 3.2
		case 2:
		{
			cout << "You chose to Set up camp in a known safe area but risk being discovered by roaming zombies.\n" << endl;
			cout << "You set up camp in a supposedly safe area, but your location is soon discovered by a roaming horde. You fight to defend your camp, but there are too many, and you are overwhelmed.\n\n" << endl;
			cout << "Outcome: The zombies find you, and you face a grim end.\n" << endl;
			cout << "Mission Failed: Please try again.\n" << endl;
			Scene3();
		}
		}
		break;
	}
	}

}
