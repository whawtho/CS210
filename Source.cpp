// Zeb Hawthorne | 11-24-2023 | Project Two
 
#include<iostream>
#include<cmath>
#include "Investment.h"
#include <iomanip>//for setw, setfill
#include <stdlib.h> //for system("CLS")
#include <string>

using namespace std;

void displayMenu() {
	double initialInvestment = 0, monthlyDeposit = 0, rate = 0, time = 0; //intializes variables
	char answer = 'Y'; //variable for maintaining loop
	double earnedInterest = 0;
	unsigned int yearCount;
	string asterik_fill_34(34, '*');
	string equal_fill_60(60, '=');
	string dash_fill_60(60, '-');

	Investment i;
	i.setinitialInvestment(initialInvestment);
	i.setmonthlyDeposit(monthlyDeposit);
	i.setrate(rate);
	i.settime(time);


	do {


		system("CLS");
		//first menu disply while empty of values
		cout << asterik_fill_34 << endl << "***********" << "Data Input" << "*************" << endl;
		cout << "Initial Investment Amount :\n";
		cout << "Monthly Deposit: \n";
		cout << "Annual Interest: \n";
		cout << "Number of Years: \n";
		system("pause");


		cout << asterik_fill_34 << endl << "***********" << "Data Input" << "*************" << endl;
		cout << "Initial Investment Amount : ";
		while (!(cin >> initialInvestment) || (initialInvestment < 0)) {
			cout << "Input must be a positive number. Please re-enter a valid number: "; //explains error
		cin.clear(); //clear previous input
		cin.ignore(numeric_limits<int>::max(), '\n'); //discards previous input up to newline
	}
		cout << "Monthly Deposit: ";
		while (!(cin >> monthlyDeposit) || (monthlyDeposit < 0)) {
			cout << "Input must be a positive number. Please re-enter a valid number: "; //explains error
			cin.clear(); //clear previous input
			cin.ignore(numeric_limits<int>::max(), '\n'); //discards previous input up to newline
		}
		cout << "Annual Interest: %";
		while (!(cin >> rate) || (rate < 0)) {
			cout << "Input must be a positive number. Please re-enter a valid number: "; //explains error
			cin.clear(); //clear previous input
			cin.ignore(numeric_limits<int>::max(), '\n'); //discards previous input up to newline
		}
		cout << "Number of Years: ";
		while (!(cin >> time) || (time < 0)) {
			cout << "Input must be a positive number. Please re-enter a valid number: "; //explains error
			cin.clear(); //clear previous input
			cin.ignore(numeric_limits<int>::max(), '\n'); //discards previous input up to newline
		}
		system("pause");

		//compoundInterest = (initialInvestment + ((monthlyDeposit * 12) * time)) * pow((1 + rate / 100), time) <--forumla for compound interest

		string interestLng = to_string(earnedInterest); //converts earnedInterest to string
		int spacing = interestLng.length(); //counts length of string
		string balanceLng = to_string(initialInvestment); // converts initialInvestment to string
		int balSpacing = balanceLng.length() + spacing; //sets length of initialInvestment + earnedInterest
		int space1 = 35 - balSpacing; 
		int space2 = 40 -spacing;

		
		cout << "\nBalance & Interest Without Additional Monthly Deposits\n" <<equal_fill_60 << endl << "Year        Year End Balance        Year End Earned Interest\n" << dash_fill_60 << endl;
		for (yearCount = 1; yearCount <= time; yearCount++) {
			earnedInterest = (initialInvestment)*pow((1 + rate / 100), yearCount); //formula without monthly deposits

			cout << fixed << setprecision(2); //sets display of two decimal points throughout
			cout << setfill(' ') << left << setw(space1) << yearCount;
			cout << "$" << left << setw(space2) << (initialInvestment + earnedInterest);
			cout << "$" << earnedInterest << endl << endl;;
			
		}
		system("pause");

		cout << "\nBalance & Interest With Additional Monthly Deposits\n" << equal_fill_60 << endl << "Year        Year End Balance        Year End Earned Interest\n" << dash_fill_60 << endl;
		for (yearCount = 1; yearCount <= time; yearCount++) {
			earnedInterest = (initialInvestment + ((monthlyDeposit * 12) * time))*pow((1 + rate / 100), yearCount); //formula with monthly deposits

			cout << fixed << setprecision(2);
			cout << setfill(' ') << left << setw(space1) << yearCount;
			cout << "$" << left << setw(space2) << (initialInvestment + earnedInterest);
			cout << "$" << earnedInterest << endl << endl;

		}
		system("pause");

		cout << "Do you wish to evaluate another investment? Enter 'Y' to continue or any other key to exit... " << endl;
		cin >> answer;

		if ((answer == 'Y') || (answer == 'y')) { //added if and or to exit with either case
			answer = 'Y';
		}
		else {
			answer = 'n';
			cout << "Program Finished. Thank you!";
		}
	}
	while (answer == 'Y');

}

int main() {
	displayMenu();
}
