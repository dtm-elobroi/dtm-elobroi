#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void mainMenu();
void startGame();
void gameCredits();
void coreGame();
void winCondition();
void loseCondition();
void retryGame();
void resetHostNumber();
void introduction();

string mainMenuInput;
string retryInput;
string creditsInput;
string messageIndent = "               ";
string introductionMessage;
string mainMenu0, mainMenu1, mainMenu2, mainMenu3;
string startGame0, startGame1;
int playerGuessInput;
int correctAnswer;
float guessCounter = 0.0F;

int main() {

	introduction();

}

void introduction() {

	introductionMessage = "\n\n\n\n\n\n                  Welcome to Higher or Lower, the number guessing game!\n\n                               Made by dtm_elobroi!\n\n";
	int x1 = 0;
	while (introductionMessage[x1] != '\0')
	{
		cout << introductionMessage[x1];
		Sleep(50);
		x1++;
	};

	Sleep(500);

	cout << "\n                     ----- ----- ----- ----- ----- ----- -----\n\n" << endl;

	Sleep(500);

	mainMenu();

}

void mainMenu() {

	mainMenu0 = "\n                           What would you like to do?\n\n";
	mainMenu1 = "\n                         << 1 >>        Start a new game\n";
	mainMenu2 = "\n                         << 2 >>          Game Credits\n";
	mainMenu3 = "\n                         << 3 >>           Exit game\n\n";

	int x0 = 0;
	while (mainMenu0[x0] != '\0')
	{
		cout << mainMenu0[x0];
		Sleep(25);
		x0++;
	};

	int x1 = 0;
	while (mainMenu1[x1] != '\0')
	{
		cout << mainMenu1[x1];
		Sleep(25);
		x1++;
	};

	int x2 = 0;
	while (mainMenu2[x2] != '\0')
	{
		cout << mainMenu2[x2];
		Sleep(25);
		x2++;
	};

	int x3 = 0;
	while (mainMenu3[x3] != '\0')
	{
		cout << mainMenu3[x3];
		Sleep(25);
		x3++;
	};

	cin >> mainMenuInput;

	cin.clear();
	cin.ignore(10000, '\n');

	system("cls");

	if (mainMenuInput == "1") {

		startGame();

	}
	else if (mainMenuInput == "2") {

		gameCredits();

	}
	else if (mainMenuInput == "3") {

		exit(10);

	}
	else {
		
		cout << "\n\nThat was not one of the correct options! Please choose again!\n\n" << endl;

		mainMenu();

	}

}

void startGame() {

	startGame0 = "\n Your objective is to guess the number that the host has chosen!\n\n If your number is higher than the hosts number, then you will be told, and same goes for if your number is lower.\n\n You have a total of 5 guesses, and when you use them all up, you lose!\n\n If you do lose, you will be able to choose a new number, continue guessing, or go back to the menu!\n\n Good luck guessing!";

	int x0 = 0;
	while (startGame0[x0] != '\0')
	{
		cout << startGame0[x0];
		Sleep(30);
		x0++;
	};

	Sleep(1000);

	cout << "\n\n\n                     ----- ----- ----- ----- ----- ----- -----\n\n" << endl;

	Sleep(1000);

	cout << "\n The host has chosen a number ranging from 0 to 100.\n" << endl;

	resetHostNumber();

}

void resetHostNumber(){
    
    srand(static_cast<unsigned int>(time(0)));
    
    correctAnswer = (rand()% 100) +1;
    
    coreGame();
    
}

void coreGame() {

	playerGuessInput = 0;

	cout << "\n\n\n                     ----- ----- ----- ----- ----- ----- -----\n\n" << endl;

	cout << "Please make a guess!\n" << endl;

	cout << "This is how many guesses you have taken: " << guessCounter << endl;

	cout << "\n\n\n                     ----- ----- ----- ----- ----- ----- -----\n\n" << endl;

	cin >> playerGuessInput;

	cin.clear();
	cin.ignore(10000, '\n');

	system("cls");

	++guessCounter;

	if (guessCounter == 11) {

		cout << "\nYou have run out of available guesses!\n" << endl;

		loseCondition();

	}

	if (playerGuessInput == correctAnswer) {

		winCondition();

	}
    else if (playerGuessInput < 0 || playerGuessInput > 100) {
        
        --guessCounter;
        
        cout << "\nYour guess has to be any number from 0 to 100!\n\n Guess again!\n" << endl;
        
    }
	else if (playerGuessInput < correctAnswer) {

		cout << "\nYou guessed LOWER than the host's number!\n\n Guess again!\n" << endl;

		coreGame();

	}
	else if (playerGuessInput > correctAnswer) {

		cout << "\nYou guessed HIGHER than the host's number!\n\n Guess again!\n" << endl;

		coreGame();

	}

}

void winCondition() {

	cout << "\nCongrats! You have won!\n" << endl;

	retryGame();

}

void loseCondition() {

	cout << "\nYou lose! Boohoo!\n" << endl;

	retryGame();

}

void retryGame() {

	cout << "What would you like to do now?\n" << endl;

	cout << "<< 1 >> Continue guessing\n" << endl;

	cout << "<< 2 >> Guess a new number\n" << endl;

	cout << "<< 3 >> Quit to menu\n" << endl;

	cin >> retryInput;

	cin.clear();
	cin.ignore(10000, '\n');

	guessCounter = 0;

	if (retryInput == "1") {

		coreGame();

	}
	else if (retryInput == "2") {
        
        system("cls");

        cout << "The host has changed his number! Please begin to guess this new number!\n" << endl;
        
		resetHostNumber();

	}
	else if (retryInput == "3") {

		system("cls");

		mainMenu();

	}

}

void gameCredits() {
    
    system("cls");

	cout << "This was made by dtm_elobroi!\n" << endl;
    
    cout << "I am a twitch affiliate streamer, and plan on streaming a lot of my coding and programming on my twitch channel, \"dtm_elobroi\". I usually post to discord when I go live, and occasionally post to my twitter. If you would like to help teach me c++, ask me for c++ help, Watch me create games, or try out my games, consider coming by and watching my live-streams on twitch. My stream schedule often falls off track, but my stream schedule is Tuesdays and Thursdays starting at 7 pm Central Standard Time.\n" << endl;
    
    cout << "Check out my twitch channel!       https://twitch.tv/dtm_elobroi\n" << endl;

	cout << "Join my discord server!            https://discord.gg/tBXvBqv\n" << endl;     
    
    cout << "Follow me on twitter!              https://twitter.com/delobroi\n" << endl;
    
    cout << "Add me on snapchat!                \"elobroi\"\n" << endl;
    
    cout << "Subscibe to me on youtube!         https://youtube.com/channel/UCh04wn0G5B7fa21GiC4DxWw\n" << endl;

	cout << "\n----- ----- ----- ----- ----- ----- ----- ----- ----- -----\n" << endl;

	cout << "What would you like to do?\n" << endl;

	cout << "<< 1 >> Back to Menu\n" << endl;

	cout << "<< 2 >> Exit game\n" << endl;

	cout << "\n----- ----- ----- ----- ----- ----- ----- ----- ----- -----\n" << endl;

	cin >> creditsInput;

	if (creditsInput == "1") {

		system("cls");

		mainMenu();

	}
	else if (creditsInput == "2") {

		exit(15);

	}
	else {

		system("cls");

		cout << "Please do a input something vaugely like what it said to do." << endl;

		gameCredits();

	}

}
