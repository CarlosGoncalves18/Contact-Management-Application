#include <iostream> 
#include <string>
using namespace std;

struct Phone_Number
{
	char international[1];
	char country[2];
	char regional[3];
	char home[7];
};
struct Address_Info
{
	string street_number;
	string street_name;
	string city;
	string province;
	string postal_code;
	string country;
};
struct Meeting_Date
{
	string month;
	string day;
	string year;
};
struct Contact_Structure
{
	int contact_number;
	string first_name;
	string last_name;
	string company_name;
	Phone_Number phone;
	Address_Info address;
	Meeting_Date date;
};

void load_data(Contact_Structure[], int);
void load_data(Contact_Structure *, Contact_Structure*);
void display_data(Contact_Structure[], int);
void display_data(Contact_Structure *, Contact_Structure*);
int search_number(Contact_Structure[], int, int);
int search_name(Contact_Structure[], int, string, string);
int search_number(Contact_Structure *, Contact_Structure *, int);
int search_name(Contact_Structure *, Contact_Structure *, string, string);
void sort_number(Contact_Structure[], int);
void sort_companyname(Contact_Structure[], int);
void sort_number(Contact_Structure *, Contact_Structure *);
void sort_companyname(Contact_Structure *, Contact_Structure *);