#include <iostream> 
#include <string>
#include <ostream>
#include <istream>
#include "Header.h"
using namespace std;

istream & operator >> (istream & imp_stream, Contact_Structure & a_contact)
{
	cout << "Contact number: ";
	while (!(imp_stream >> a_contact.contact_number))
	{
		cout << endl;
		cout << "\n\t ********** WARNING ********** \n";
		cout << "Please enter a valid contact number: ";
		cin.clear();
		cin.ignore(10, '\n');
	}
	cout << "First Name: ";
	imp_stream >> a_contact.first_name;
	cout << "Family Name: ";
	imp_stream >> a_contact.last_name;
	cout << "Company Name: ";
	imp_stream >> a_contact.company_name;
	cout << "Contact Phone# (Please enter phone by format X XXX XXX XXXXXXX) : ";
	imp_stream >> a_contact.phone.international;
	imp_stream >> a_contact.phone.country;
	imp_stream >> a_contact.phone.regional;
	imp_stream >> a_contact.phone.home;
	cout << "Contact Address: " << endl;
	cout << "Street Number: ";
	imp_stream >> a_contact.address.street_number;
	cout << "Street Name: ";
	imp_stream >> a_contact.address.street_name;
	cout << "City: ";
	imp_stream >> a_contact.address.city;
	cout << "Province: ";
	imp_stream >> a_contact.address.province;
	cout << "Postal Code: ";
	imp_stream >> a_contact.address.postal_code;
	cout << "Country: ";
	imp_stream >> a_contact.address.country;
	cout << "Meeting Date (Please enter date by day/month/year) : ";
	imp_stream >> a_contact.date.day;
	imp_stream >> a_contact.date.month;
	imp_stream >> a_contact.date.year;
	system("cls");
	return imp_stream;
}
ostream & operator << (ostream & out_stream, Contact_Structure & b_contact)
{
	out_stream << "\nContact Number: " << b_contact.contact_number << "\nFirst Name: " << b_contact.first_name << "\nLast Name: " << b_contact.last_name <<
		"\nCompany Name : " << b_contact.company_name << "\nContact Phone #: " << b_contact.phone.international << " - " << b_contact.phone.country << " - "
		<< b_contact.phone.regional << " - " << b_contact.phone.home << "\nAddress: " << "\nStreet Number: " << b_contact.address.street_number << "\nStreet Name: " << b_contact.address.street_name <<
		"\nCity: " << b_contact.address.city << "\nProvince: " << b_contact.address.province << "\nPostal Code: " << b_contact.address.postal_code <<
		"\nCountry: " << b_contact.address.country << "\nMeeting date(day / month / year): " << b_contact.date.day << "/" << b_contact.date.month << "/" << b_contact.date.year << endl;
	return out_stream;
}
// Loading data to the array contact[], working with reference
void load_data(Contact_Structure contact[], int max)
{
	for (int i = 0; i < max; i++)
	{
		cin >> contact[i];
	}
}
// Displaying data that are stored in the array contact[], working with reference
void display_data(Contact_Structure contact[], int max)
{
	for (int i = 0; i < max; i++)
	{
		cout << contact[i];
	}
}
// Loading data to the array contact[], working with pointer
void load_data(Contact_Structure *pf, Contact_Structure *pl)
{
	for (Contact_Structure * ptr = pf; ptr <= pl; ptr++)
	{
		cout << "Contact number: ";
		while (!(cin >> ptr->contact_number))
		{
			cout << endl;
			cout << "\n\t ********** WARNING ********** \n";
			cout << "Enter a valid number of contact to add to the list: ";
			cin.clear();
			cin.ignore(10, '\n');
		}
		cout << "First Name: ";
		cin >> ptr->first_name;
		cout << "Family Name: ";
		cin >> ptr->last_name;
		cout << "Company Name: ";
		cin >> ptr->company_name;
		cout << "Contact Phone# (Please enter phone by format X XXX XXX XXXXXXX) : ";
		cin >> ptr->phone.international;
		cin >> ptr->phone.country;
		cin >> ptr->phone.regional;
		cin >> ptr->phone.home;
		cout << "Contact Address: " << endl;
		cout << "Street Number: ";
		cin >> ptr->address.street_number;
		cout << "Street Name: ";
		cin >> ptr->address.street_name;
		cout << "City: ";
		cin >> ptr->address.city;
		cout << "Province: ";
		cin >> ptr->address.province;
		cout << "Postal Code: ";
		cin >> ptr->address.postal_code;
		cout << "Country: ";
		cin >> ptr->address.country;
		cout << "Meeting Date (Please enter date by day/month/year) : ";
		cin >> ptr->date.day;
		cin >> ptr->date.month;
		cin >> ptr->date.year;
		cout << endl;
	}
}
// Displaying data that are stored in the array contact[], working with pointer
void display_data(Contact_Structure *pf, Contact_Structure *pl)
{
	for (Contact_Structure * ptr = pf; ptr <= pl; ptr++)
	{
		cout << "\nContact Number: " << ptr->contact_number << "\nFirst Name: " << ptr->first_name << "\nLast Name: " << ptr->last_name <<
			"\nCompany Name : " << ptr->company_name << "\nContact Phone #: " << ptr->phone.international << " - " << ptr->phone.country << " - "
			<< ptr->phone.regional << " - " << ptr->phone.home << "\nAddress: " << "\nStreet Number: " << ptr->address.street_number << "\nStreet Name: " << ptr->address.street_name <<
			"\nCity: " << ptr->address.city << "\nProvince: " << ptr->address.province << "\nPostal Code: " << ptr->address.postal_code <<
			"\nCountry: " << ptr->address.country << "\nMeeting date(day / month / year): " << ptr->date.day << "/" << ptr->date.month << "/" << ptr->date.year << endl;
	}
}
// Function to search a contact number, if the user enters a wrong contact number the program displays error
int search_number(Contact_Structure contact[], int number_used, int find_number)
{
	bool found = false;
	for (int i = 0; i < number_used; i++)
	{
		if (find_number == contact[i].contact_number)
		{

			cout << contact[i];
			found = true;
		}
	}
	if (!found)
	{
		cout << "\n\t\t Contact with ID: " << find_number << " Not Found" << endl;
		return -1;
	}
}
// Function to search a contact number, if the user enters a wrong contact number the program displays error
int search_number(Contact_Structure *pf, Contact_Structure *pl, int find_number)
{
	bool found = false;
	for (Contact_Structure * ptr = pf; ptr <= pl; ptr++)
	{
		if (find_number == ptr->contact_number)
		{
			
			cout << "\nContact Number: " << ptr->contact_number << "\nFirst Name: " << ptr->first_name << "\nLast Name: " << ptr->last_name <<
				"\nCompany Name : " << ptr->company_name << "\nContact Phone #: " << ptr->phone.international << " - " << ptr->phone.country << " - "
				<< ptr->phone.regional << " - " << ptr->phone.home << "\nAddress: " << "\nStreet Number: " << ptr->address.street_number << "\nStreet Name: " << ptr->address.street_name <<
				"\nCity: " << ptr->address.city << "\nProvince: " << ptr->address.province << "\nPostal Code: " << ptr->address.postal_code <<
				"\nCountry: " << ptr->address.country << "\nMeeting date(day / month / year): " << ptr->date.day << "/" << ptr->date.month << "/" << ptr->date.year << endl;
			found = true;
		}
	}
	if (!found)
	{
		cout << "\n\t\t Contact Number: " << find_number << " Not Found" << endl;
		return -1;
	}
}
int search_name(Contact_Structure contact[], int number_used, string find_name, string find_last)
{
	bool found = false;
	for (int i = 0; i < number_used; i++)
	{
		if ((find_name == contact[i].first_name)&&(find_last == contact[i].last_name))
		{

			cout << contact[i];
			found = true;			
		}
	}
	if (!found)
	{
		cout << "\n\t\t Contact First Name: " << find_name << " " << find_last << "Not Found" << endl;
		return -1;
	}
}
int search_name(Contact_Structure *pf, Contact_Structure *pl, string find_name, string find_last)
{
	bool found = false;
	for (Contact_Structure * ptr = pf; ptr <= pl; ptr++)
	{
		if ((find_name == ptr->first_name)&&(find_last == ptr->last_name))
		{

			cout << "\nContact Number: " << ptr->contact_number << "\nFirst Name: " << ptr->first_name << "\nLast Name: " << ptr->last_name <<
				"\nCompany Name : " << ptr->company_name << "\nContact Phone #: " << ptr->phone.international << " - " << ptr->phone.country << " - "
				<< ptr->phone.regional << " - " << ptr->phone.home << "\nAddress: " << "\nStreet Number: " << ptr->address.street_number << "\nStreet Name: " << ptr->address.street_name <<
				"\nCity: " << ptr->address.city << "\nProvince: " << ptr->address.province << "\nPostal Code: " << ptr->address.postal_code <<
				"\nCountry: " << ptr->address.country << "\nMeeting date(day / month / year): " << ptr->date.day << "/" << ptr->date.month << "/" << ptr->date.year << endl;
			found = true;
		}
	}
	if (!found)
	{
		cout << "\n\t\t Contact First Name: " << find_name << " " << find_last << " Not Found" << endl;
		return -1;
	}
}
//Fuction that sorts the array ordering by number
void sort_number(Contact_Structure contact[], int max)
{
	int start, min_index;

	for (start = 0; start < (max - 1); start++)
	{
		min_index = start;
		for (int index = start; index < max; index++)
		{
			if (contact[index].contact_number < contact[min_index].contact_number)
				min_index = index;
		}
		if (min_index != start)
		{
			Contact_Structure temp = contact[min_index];
			contact[min_index] = contact[start];
			contact[start] = temp;
		}
	}
}
//Fuction that sorts the array ordering by Company Name
void sort_companyname(Contact_Structure contact[], int max)
{
	int start, min;

	for (start = 0; start < (max - 1); start++)
	{
		min = start;
		for (int index = start; index < max; index++)
		{
			if (contact[index].company_name < contact[min].company_name)
				min = index;
		}
		if (min != start)
		{
			Contact_Structure temp = contact[min];
			contact[min] = contact[start];
			contact[start] = temp;
		}
	}
}
//Fuction that sorts the array ordering by number
void sort_number(Contact_Structure *pf, Contact_Structure *pl)
{
	for (Contact_Structure *ptr = pf; ptr <= pl; ptr++)
	{
		for (Contact_Structure *index = pf; index <= pl; index++)
		{
			if (ptr->contact_number < index->contact_number)
			{
				Contact_Structure temp = *ptr;
				*ptr = *index;
				*index = temp;
			}
		}
	}
}
//Fuction that sorts the array ordering by Company Name
void sort_companyname(Contact_Structure *pf, Contact_Structure *pl)
{
	for (Contact_Structure *ptr = pf; ptr <= pl; ptr++)
	{
		for (Contact_Structure *index = pf; index <= pl; index++)
		{
			if (ptr->company_name < index->company_name)
			{
				Contact_Structure temp = *ptr;
				*ptr = *index;
				*index = temp;
			}
		}
	}
}