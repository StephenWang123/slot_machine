#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void printResults(char first, char second, char third);
void printOptions();

void menu(char first, char second, char third, int credits)
{
	cout << "\n\n\n***SLOT MACHINE SIMULATOR***\n" << endl;
	cout << "Credits: " << credits << "\n" << endl;
	cout << first << " " << second << " " << third << "\n" << endl;
	printResults(first, second, third);
	printOptions();
}

void printOptions()
{
	cout << "1. Spin! (Or just press enter)\t2. View Prizes\t3. Exit" << endl;
	cout << "Option: ";
}

void printPrizes()
{
	cout << "\n\n\n***A A A: Win 50 credits***\n" << endl;
	cout << "**B B B: Win 5 credits**\n" << endl;
	cout << "*C C C: Win 3 credits*\n" << endl;
}

void printResults(char first, char second, char third)
{
	if ((first == 'A'&& second == 'A' && third == 'A'))
		cout << "--> You won 50!\n" << endl;
	else if((first == 'B'&& second == 'B' && third == 'B'))
		cout << "--> You won 5!\n" << endl;
	else if ((first == 'C'&& second == 'C' && third == 'C'))
		cout << "--> You won 3!\n" << endl;
	else
		cout << "--> You lose.\n" << endl;	
}

void roll(char& first, char& second, char& third, int& credits)
{
	int masking = rand()%1000;
 	int wrong1;
	int wrong2;
	int wrong3;

	credits--;

	if (masking == 999)
		{first = 'A'; second = 'A'; third = 'A'; credits += 50;}
	else if (masking < 999 && masking >= 950)
		{first = 'B'; second = 'B'; third = 'B'; credits += 5;}
	else if (masking < 950 && masking >= 851)
		{first = 'C'; second = 'C'; third = 'C'; credits += 3;}
	else{
		label:
		wrong1 = rand()%999;
		wrong2 = rand()%999;
		wrong3 = rand()%999;
		if (wrong1 <= 333)
			first = 'A';
		else if (wrong1 > 333 && wrong1 <= 666)
			first = 'B';
		else if (wrong1 > 666)
			first = 'C';

		if (wrong2 <= 333)
			second = 'A';
		else if (wrong2 > 333 && wrong1 <= 666)
			second = 'B';
		else if (wrong2 > 666)
			second = 'C';
		
		if (wrong3 <= 333)
			third = 'A';
		else if (wrong3 > 333 && wrong1 <= 666)
			third = 'B';
		else if (wrong3 > 666)
			third = 'C';

		if (first == second && second == third){
			goto label;	
		}
		
	
	}
		
}

int run()
{
	string choice;
	getline(cin, choice);
	if (choice == "1" || choice.empty())
		return 1;
	else if (choice == "2")
		return 2;
	else if (choice == "3")
		return 0;
	else
		return 0;
	
}

int main()
{
	string tempCredits;
	ifstream getCredits("credits.txt");
	getline(getCredits, tempCredits);
	
	int credits = stoi(tempCredits); 
	int choice = 0;

	char firstSlot = 'A';
	char secondSlot = 'B';
	char thirdSlot = 'C';
	
	do
	{
		if (choice == 1)
			roll(firstSlot, secondSlot, thirdSlot, credits);
		if (choice == 2)
			printPrizes();
		menu(firstSlot, secondSlot, thirdSlot, credits);
	}
	while((choice = run()));
	
	ofstream outPut;
        outPut.open("credits.txt");
	outPut << credits;
	outPut.close();

}
