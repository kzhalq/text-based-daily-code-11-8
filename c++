#include<iostream>
using namespace std;
//global variable
string inventory[10];// declare an array
int gold = 100;
void shop();// function declaration

void ItemDropper();/// function decleration

int main() {
	
	for (int i = 0; i < 10; i++) // initialize with empty spaces
		inventory[i] = " ";

	cout << "welcome to the text based game!" << endl;


	char input = 'a';
	int room = 1;
	while (input != 'q') {// game loop

		//print inventory
		cout << "your inventory:" << endl;
		for (int i = 0; i < 10; i++)
			cout << inventory[i] << " ";
		cout << endl;

		switch (room) {
		case 1:
			ItemDropper();
			cout << "youre in room 1, you can go (s)outh. you see a (k)ey on the floor." << endl;
			//only print that it's there if you haven't picked it up
			if (inventory[0] != "key")
				cout << "you see a shiny (k)ey on the floor" << endl;
			cin >> input;
			if (input == 's')
				room = 2;
			//get the item
			if (input == 'k')
				inventory[0] = "key";
			break;
		case 2:
			cout << "you're in room 2, you can go (n)orth or (s)outh" << endl;
			cout << "Theres a (t)reasure box in the corner." << endl;
			cin >> input;
			if (input == 'n')
				room = 1;
			if (input == 's')
				room = 3;
			if (input == 't')
				ItemDropper();
				if (inventory[0] == "key") {
					cout << "you unlock the door with the key!" << endl;
					inventory[0] = " ";
					room = 3;
				}
				else
					cout << "the door is locked." << endl;
			break;
		case 3:
			cout << "you're in room 3, you can go (n)orth" << endl;
			cout << "there's a (s)hop in the corner." << endl;
			cin >> input;
			if (input == 'n')
				room = 2;
			if (input == 's')
				shop();//call the shop
			break;
		}//end of switch
	}//end of game loop
}// end of main


// function!
void shop() {
	int input = 'a';
	while (input != 0)
		cout << "-----------------------------------------------" << endl;
	cout << "welcome to the shop!" << endl;
	cout << "iteams for sale:" << endl;
	cout << "1) cupcake: $5" << endl;
	cout << "2) dirty sock: $10" << endl;
	cout << "3) key: $50" << endl;

	//print inventory
	cout << "your inventory:" << endl;
	for (int i = 0; i < 10; i++)
		cout << inventory[i] << " ";
	cout << endl << endl;

	cout << "what would you like to purchase?" << endl;
	cin >> input;

	//purchaese cupcake 
	if (input == 1) {
		if (gold >= 5) {
			cout << "you bought the cupcake!" << endl;
			inventory[1] = "cupcake";
			gold -= 5;
		}
		else
			cout << "you don't have enough gold!" << endl;
	}

	//purchase the sock
	if (input == 2) {
		if (gold >= 5) {
			cout << "you bought the dirty sock!" << endl;
			inventory[2] = "sock!";
			gold -= 10;
		}
		else
			cout << "you don't have enough gold!" << endl;

	}

	//purchase the key
	if (input == 3) {
		if (gold >= 50) {
			cout << "you bought the key!" << endl;
			inventory[0] = "key";
			gold -= 50;
		}
		else
			cout << "You dont have enough!" << endl;
	}

	else if (input == 0)
		cout << "goodbye!" << endl;
	else {
		cout << "That's not an option, dummy" << endl;
	}
}// end of mini game loop

//function definition
void ItemDropper() {
	int num = rand() % 100; //0-99
	if (num < 20) {
		cout << "You got a dirty sock!" << endl;
		inventory[2] = "sock";
	}
	else if (num < 50) {
		cout << "you got a cupcake!" << endl;
		inventory[3] = "cupcake";
	}
	else if (num < 75) {
		cout << "you got a smol frog" << endl;
		inventory[4] = "frog";
	}
	else {
		cout << "you got nothing!" << endl;
	}


}   
