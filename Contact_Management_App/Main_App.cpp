/*Contact_Management_App: : Defines the entry point for the console application.
420-P45-AS Data Structure: C++, Project 01
By: Carlos Goncalves
March 05, 2018
*/

#include <iostream> 
#include <string>
#include <ostream>
#include <istream>
#include "Header.h"
using namespace std;


int main()
{
	int choice, find_number, max, result;
	char ans, start;
	string find_name, find_last;

	cout << "_________________________________________________________________________________________________________________\n";
	cout << "--------------------------------------- Contact Management Application ----------------------------------------- \n";
	cout << "_________________________________________________________________________________________________________________\n";
	cout << endl;
	cout << "How many contact do you like to add to the list? ";
	while (!(cin >> max))
	{
		cout << endl;
		cout << "\n\t ********** WARNING ********** \n";
		cout << "Enter a valid number of contact to add to the list: ";
		cin.clear();
		cin.ignore(10, '\n');
	}
	Contact_Structure * contact = new Contact_Structure[max];
	Contact_Structure *pf, *pl;
	pf = &contact[0];
	pl = &contact[max - 1];
	cout << "\n1. To work with reference, please select option 1";
	cout << "\n2. To work with pointers, please select option 2";
	cout << endl;
	cout << "\n\t Please enter your choice : ";
	// This is a validation to make the user enters a number. This validation is used in every step that requires an integer imput 
	while (!(cin >> choice))
	{
		cout << endl;
		cout << "\n\t ********** WARNING ********** \n";
		cout << "Choise must be number 1 or 2: ";
		cin.clear();
		cin.ignore(10, '\n');
	}
	system("cls");
	switch (choice) {
	case 1:
		do
		{
			cout << "_________________________________________________________________________________________________________________\n";
			cout << "--------------------------------------- Contact Management Application ----------------------------------------- \n";
			cout << "_________________________________________________________________________________________________________________\n";
			cout << endl;
			cout << "=================================================================================================================\n";
			cout << " 1. Create a new Contact \n";
			cout << " 2. Display the Contact list \n";
			cout << " 3. Search a Contact by number \n";
			cout << " 4. Search a Contact by name \n";
			cout << " 5. Sorting Contact List by Contact Number \n";
			cout << " 6. Sorting Contact List by Contact Name \n";
			cout << " 7. Exit the application \n";
			cout << "=================================================================================================================\n";
			cout << endl;
			cout << "Please select your option: ";
			cout << endl;
			cin >> choice;
			system("cls");
			switch (choice)
			{
			case 1:
			{
				load_data(contact, max);
				system("cls");

			} break;

			case 2:
			{
				cout << "Displaying Contact List: ";
				cout << endl;
				display_data(contact, max);
			} break;
			case 3:
			{
				do
				{
					cout << endl;
					cout << "Enter a Contact Number to search for: ";
					// This is a validation to make the user enters a number. This validation is used in every step that requires an integer imput 
					while (!(cin >> find_number))
					{
						cout << endl;
						cout << "\n\t ********** WARNING ********** \n";
						cout << "Please enter a valid contact number: ";
						cin.clear();
						cin.ignore(10, '\n');
					}
					result = search_number(contact, max, find_number);
					cout << endl;
					cout << "Do you want to search again? (y/n followed by Return): ";
					cout << endl;
					cin >> ans;
					system("cls");
				} while ((ans != 'n') && (ans != 'N'));
				system("cls");
			} break;	
			case 4:
			{
				do
				{
					cout << endl;
					cout << "Enter a Contact First Name to search for: ";
					// This is a validation to make the user enters a number. This validation is used in every step that requires an integer imput 
					cin >> find_name;
					cin >> find_last;
					result = search_name(contact, max, find_name, find_last);
					cout << endl;
					cout << "Do you want to search again? (y/n followed by Return): ";
					cout << endl;
					cin >> ans;
					system("cls");
				} while ((ans != 'n') && (ans != 'N'));
				system("cls");
			} break;
			case 5:
			{
				sort_number(contact, max);
				display_data(contact, max);
			} break;

			case 6:
			{
				sort_companyname(contact, max);
				display_data(contact, max);
			} break;

			case 7:
			{
				return 0;
			} while (choice != 7);

			break;

			default:
				cout << "Wrong Selection, try again please..." << endl;
			}
			cout << endl;
			cout << " If you want to return to menu, please enter Y \n";
			cin >> start;
			system("cls");
		} while (start == 'y' || start == 'Y');
		system("pause");
		return 0;
		break;

	case 2:
		do
		{
			cout << "_________________________________________________________________________________________________________________\n";
			cout << "--------------------------------------- Contact Management Application ----------------------------------------- \n";
			cout << "_________________________________________________________________________________________________________________\n";
			cout << endl;
			cout << "=================================================================================================================\n";
			cout << " 1. Create a new Contact \n";
			cout << " 2. Display the Contact list \n";
			cout << " 3. Search a Contact by number \n";
			cout << " 4. Search a Contact by name \n";
			cout << " 5. Sorting Contact List by Contact Number \n";
			cout << " 6. Sorting Contact List by Company Name \n";
			cout << " 7. Exit the application \n";
			cout << "=================================================================================================================\n";
			cout << endl;
			cout << "Please select your option: ";
			cout << endl;
			cin >> choice;
			system("cls");
			switch (choice)
			{
			case 1:
			{
				load_data(pf, pl);
				system("cls");

			} break;

			case 2:
			{
				cout << "Displaying Contact List: ";
				cout << endl;
				display_data(pf, pl);
			} break;
			case 3:
			{
				do
				{
					cout << endl;
					cout << "Enter a Contact Number to search for: ";
					while (!(cin >> find_number))
					{
						cout << endl;
						cout << "\n\t ********** WARNING ********** \n";
						cout << "Please enter a valid contact number: ";
						cin.clear();
						cin.ignore(10, '\n');
					}
					result = search_number(pf, pl, find_number);
					cout << endl;
					cout << "Do you want to search again? (y/n followed by Return): ";
					cout << endl;
					cin >> ans;
					system("cls");
				} while ((ans != 'n') && (ans != 'N'));
				system("cls");
			} break;
			case 4:
			{
				do
				{
					cout << endl;
					cout << "Enter a Contact First Name to search for: ";				
					cin >> find_name;
					cin >> find_last;
					result = search_name(pf, pl, find_name, find_last);
					cout << endl;
					cout << "Do you want to search again? (y/n followed by Return): ";
					cout << endl;
					cin >> ans;
					system("cls");
				} while ((ans != 'n') && (ans != 'N'));
				system("cls");
			} break;
			case 5:
			{
				sort_number(pf, pl);
				display_data(pf, pl);
			} break;
			case 6:
			{
				sort_companyname(pf, pl);
				display_data(pf, pl);
			} break;
			case 7:
			{
				return 0;
			} while (choice != 7);

			break;

			default:
				cout << "Wrong Selection, try again please..." << endl;
			}
			cout << endl;
			cout << " If you want to return to menu, please enter Y \n";
			cin >> start;
			system("cls");
		} while (start == 'y' || start == 'Y');
		system("pause");
		return 0;
		break;
		break;
	}
}
