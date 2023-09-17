#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <Windows.h>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;
using namespace this_thread;



struct info1  //Struct that contains all information of the database
{
	string first_name; // First name
	string last_name; // Last name
	string birthdate; // Birthdate
	string crime;  // Crime
	string status;//Status
	string date_of_arrest; //Day of Arrest
	string ID; //Criminal's ID
	string assigned_cases; //Assign case to officer

};
void welcomescreen() {
	cout << "\n\n\n\n\n\n\n\t\t\t\tThis Project is done by: " << endl;
	cout << "\t\t\t\t\tYoussef Mohamed Salah " << endl;
	cout << "\t\t\t\t\tSalma Mohamed" << endl;
	cout << "\t\t\t\t\tAlaa Yasser" << endl;
	cout << "\t\t\t\t\tRahaf Alhussein" << endl;
	cout << "\t\t\t\t\tHussein Serageldin" << endl;
	sleep_for(seconds(5));

}
void CallExit() { //EXIT FUNCTION
	system("cls");
	cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tPress any key to exit the program\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	exit(0);

}
void repeat(info1 information[], int array_size); //when the user fails to enter the correct


int login(info1 information[], int array_size)  //Login Menu 
{
	system("cls");
	char* username;
	username = new char[20];
	char* password;
	password = new char[20];
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------Welcome to our criminal database---------------------------------------------------" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

	cout << "\n \n \t \t  Please Enter your username :";
	cin.getline(username, 20);
	cout << "\n \n \t \t Please Enter your password :";
	cin.getline(password, 20);
	if (strcmp(username, "admin") == 0 && strcmp(password, "pass") == 0)
	{

		return 1; // Access admin menu
	}
	if (strcmp(username, "ADMIN") == 0 && strcmp(password, "PASS") == 0)
	{

		return 1; // Access admin menu
	}
	if (strcmp(username, "officer") == 0 && strcmp(password, "pass") == 0)
	{

		return 0; //Acess Officer Menu
	}
	if (strcmp(username, "OFFICER") == 0 && strcmp(password, "PASS") == 0)
	{

		return 0; //Acess Officer Menu
	}
	else //wrong input
	{
		return 2;
	}
	delete[] username;
	delete[] password;
}
void admin_menu(info1 information[], int array_size);
void add(info1 information[], int array_size) //ADD CRIMINAL FUNCTION
{

	system("cls");
	char x = -1;
	for (int i = 0; i < array_size; i++)
	{
		if (information[i].ID == "")  //CHECK IF INDEX IS EMPTY TO ADD
		{
			cin.ignore(1, '\n');
			cout << "Enter the criminal's firstname: ";
			getline(cin, information[i].first_name);
			while (information[i].first_name >= "0" && information[i].first_name <= "9") {
				cout << "Invalid Input , Please try again!" << endl;
				cout << "Enter criminal's firstname: ";
				getline(cin, information[i].first_name);
			}
			cout << endl;
			cout << "Enter criminal's lastname: ";
			getline(cin, information[i].last_name);
			while (information[i ].last_name >= "0" && information[i ].last_name <= "9") {
				cout << "Invalid Input , Please try again!" << endl;
				cout << "Enter criminal's lastname: ";
				getline(cin, information[i ].last_name);
			}
			cout << endl;
			cout << "Enter criminal's birthdate: ";
			getline(cin, information[i].birthdate);
			cout << endl;
			cout << "Enter crime: ";
			getline(cin, information[i].crime);
			while (information[i].crime >= "0" && information[i].crime <= "9") {
				cout << "Invalid Input , Please try again!" << endl;
				cout << "Enter criminal's crime: ";
				getline(cin, information[i].crime);
			}
			cout << endl;
			cout << "Enter criminal's status: ";
			getline(cin, information[i].status);
			cout << endl;
			cout << "Enter date of arrest: ";
			getline(cin, information[i].date_of_arrest);
			cout << endl;
			cout << "Enter criminal's ID: ";
			getline(cin, information[i].ID);
			while (information[i ].ID < "0" || information[i ].ID > "9") {
				cout << "Invalid Input , Please try again!" << endl;
				cout << "Enter criminal's ID: ";
				getline(cin, information[i ].ID);

			}
			cout << endl;
			cout << "Enter 1 if assigned to officer, or 0 if not assigned " << endl;
			getline(cin, information[i].assigned_cases);
			cout << endl;
			while (information[i].assigned_cases != "1" && information[i].assigned_cases != "0") {
				cout << "PLEASE CHOOSE  1 OR 0" << endl;
				getline(cin, information[i].assigned_cases);
				cout << endl;
			}
			break;
		}
		else {
			if (information[i + 1].ID == "") //IF PREVIOUS INDEX IS OCCUPIED, ADD ON THE NEXT INDEX
			{
				cin.ignore(1, '\n');
				cout << "Enter criminal's firstname: ";
				getline(cin, information[i + 1].first_name);
				while (information[i + 1].first_name >= "0" && information[i + 1].first_name <= "9") {
					cout << "Invalid Input , Please try again!" << endl;
					cout << "Enter criminal's firstname: ";
					getline(cin, information[i + 1].first_name);
				}
				cout << endl;


				cout << "Enter criminal's lastname: ";
				getline(cin, information[i + 1].last_name);
				while (information[i + 1].last_name >= "0" && information[i + 1].last_name <= "9") {
					cout << "Invalid Input , Please try again!" << endl;
					cout << "Enter criminal's lastname: ";
					getline(cin, information[i + 1].last_name);
				}


				cout << endl;
				cout << "Enter criminal's birthdate: ";
				getline(cin, information[i + 1].birthdate);
				cout << endl;


				cout << "Enter crime: ";
				getline(cin, information[i + 1].crime);
				while (information[i + 1].crime >= "0" && information[i + 1].crime <= "9")
				{
					cout << "Invalid Input , Please try again!" << endl;
					cout << "Enter crime: ";
					getline(cin, information[i + 1].crime);



				}
				cout << endl;
				cout << "Enter criminal's status: ";
				getline(cin, information[i + 1].status);

				cout << endl;
				cout << "Enter date of arrest: ";
				getline(cin, information[i + 1].date_of_arrest);
				cout << endl;

				cout << "Enter criminal's ID: ";
				getline(cin, information[i + 1].ID);
				while (information[i + 1].ID < "0" || information[i + 1].ID > "9") {
					cout << "Invalid Input , Please try again!" << endl;
					cout << "Enter criminal's ID: ";
					getline(cin, information[i + 1].ID);

				}
				cout << endl;
				cout << "Enter 1 if assigned to officer, or 0 if not assigned " << endl;
				getline(cin, information[i + 1].assigned_cases);
				cout << endl;
				while (information[i + 1].assigned_cases != "1" && information[i + 1].assigned_cases != "0") {
					cout << "PLEASE CHOOSE  1 OR 0" << endl;
					
					getline(cin, information[i + 1].assigned_cases);
					cout << endl;
				}
				break;
			}
		}
	}
	cout << "Enter 1 to return to menu, or 0 to exit" << endl; //Return to menu option
	while (x >= -1) {
		cin >> x;
		switch (x)
		{
		case '0':
			CallExit();
			break;
		case '1':
			admin_menu(information, array_size);
			break;
		}
		if (x != '1' && x != '0') {
			cout << "PLEASE CHOOSE  1 OR 0" << endl;
		}
	}
}

void display(info1 information[], int array_size) //Search FUNCTION
{
	system("cls");
	string id;
	char x = 0;

	cout << "Enter the ID you wish to display" << endl;
	for (int i = 0; i < array_size; i++) {
		if (information[i].ID != "") {
			cout << information[i].ID << endl;
		}
	}
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cin >> id;
	for (int i = 0; i < array_size; i++)
	{
		if (information[i].ID == id)
		{
			cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "criminal's firstname: ";
			cout << information[i].first_name << endl << endl;
			cout << "criminal's lastname: ";
			cout << information[i].last_name << endl << endl;
			cout << "criminal's birthdate: ";
			cout << information[i].birthdate << endl << endl;
			cout << "crime: ";
			cout << information[i].crime << endl << endl;
			cout << "criminal's status: ";
			cout << information[i].status << endl << endl;
			cout << "date of arrest: ";
			cout << information[i].date_of_arrest << endl << endl;
			cout << "criminal's ID: ";
			cout << information[i].ID << endl << endl;

		}

	}


	cout << "Enter 1 to return to menu, or Enter 2 to continue searching" << endl;
	while (x >= 0) {
		cin >> x;
		switch (x)
		{
		case '1':
			admin_menu(information, array_size);
			break;
		case '2':
			display(information, array_size);
			break;
		}
		if (x != '1' && x != '2') {
			cout << "PLEASE CHOOSE A 1 OR 2" << endl;
		}
	}
}



void remove(info1 information[], int array_size) //REMOVE CRIMINAL

{
	system("cls");
	int j = 1;
	string id;
	char x = -1;

	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Enter the ID you wish to delete" << endl;
	cin >> id;
	cout << "\n";
	for (int i = 0; i < array_size; i++)
	{
		if (information[i].ID == id && information[i].ID != "")
		{
			information[i].first_name = "";
			information[i].last_name = "";
			information[i].birthdate = "";
			information[i].crime = "";
			information[i].status = "";
			information[i].date_of_arrest = "";
			information[i].ID = "";
			information[i].assigned_cases = "";
			cout << "DELETED" << endl;
			j = 0;
			break;
		}

	}
	if (j == 1) {
		cout << "NO ID FOUND, PLEASE RETURN TO MENU AND TRY AGAIN" << endl;
		j = 0;
	}


	cout << "Enter 1 to return to menu, or 0 to exit" << endl;
	while (x >= -1) {
		cin >> x;
		switch (x)
		{
		case '0':
			CallExit();
			break;
		case '1':
			admin_menu(information, array_size);
			break;
		}
		if (x != '1' && x != '0') {
			cout << "PLEASE CHOOSE  1 OR 0" << endl;
		}
	}
}
void modify_menu(info1 information[], int array_size);
void modify(info1 information[], int array_size) //to edit the data of a criminal you entered by mistake
{
	system("cls");
	char x = -1;
	int j = 1;
	string id;

	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Enter the ID you wish to modify" << endl;
	cin >> id;
	cout << "\n";
	for (int i = 0; i < array_size; i++) {
		if (id == information[i].ID) {
			modify_menu(information, array_size);
			j = 2;
		}
		if (j == 1) {
			cout << "NO ID FOUND, PLEASE RETURN TO MENU AND TRY AGAIN" << endl;
			j = 0;
		}
	}
	if (j == 2) {
		cout << "\n";
		cout << "MODIFIED" << endl << endl;
		cout << "Enter 1 to return to admin menu, or 2 to continue modifying" << endl << endl;
		while (x >= -1) {
			cin >> x;
			switch (x)
			{
			case '1':
				admin_menu(information, array_size);
				break;
			case '2':
				modify_menu(information, array_size);
				cout << "\n";
				cout << "MODIFIED" << endl << endl;
				cout << "Enter 1 to return to admin menu, or 2 to continue modifying" << endl;
				break;
			}
			if (x != '1' && x != '2') {
				cout << "PLEASE CHOOSE  1 OR 2" << endl;
			}
		}
	}
	if (j == 0) {
		cout << "Enter 1 to return to admin menu" << endl;
		while (x >= -1) {
			cin >> x;
			switch (x)
			{
			case '1':
				admin_menu(information, array_size);
				break;
			}
			if (x != '1') {
				cout << "PLEASE CHOOSE  1" << endl;
			}
		}
	}
}

void display_all(info1 information[], int array_size) //Displays the database that has all the criminals.
{
	system("cls");
	char x = -1;

	for (int i = 0; i < array_size; i++)
	{
		if (information[i].ID != "") {
			cout << "criminal's firstname: ";
			cout << information[i].first_name << endl << endl;
			cout << "criminal's lastname: ";
			cout << information[i].last_name << endl << endl;
			cout << "criminal's birthdate: ";
			cout << information[i].birthdate << endl << endl;
			cout << "crime: ";
			cout << information[i].crime << endl << endl;
			cout << "criminal's status: ";
			cout << information[i].status << endl << endl;
			cout << "date of arrest: ";
			cout << information[i].date_of_arrest << endl << endl;
			cout << "criminal's ID: ";
			cout << information[i].ID << endl << endl;
			cout << "-----------------------------------------------------------------------------------------------------------------------" << endl << endl;
		}
	}
	cout << "Enter 1 to return to menu, or 0 to exit" << endl;
	while (x >= -1) {
		cin >> x;
		switch (x)
		{
		case '0':
			CallExit();
			break;
		case '1':
			admin_menu(information, array_size);
			break;
		}
		if (x != '1' && x != '0') {
			cout << "PLEASE CHOOSE  1 OR 0" << endl;
		}
	}

}
void officer_menu(info1 information[], int array_size);
void display_all1(info1 information[], int array_size)//Displays assigned casses for the officer that are assigned from the admin
{
	system("cls");
	char x = -1;

	for (int i = 0; i < array_size; i++)
	{
		if (information[i].ID != "") {
			cout << "criminal's firstname: ";
			cout << information[i].first_name << endl << endl;
			cout << "criminal's lastname: ";
			cout << information[i].last_name << endl << endl;
			cout << "criminal's birthdate: ";
			cout << information[i].birthdate << endl << endl;
			cout << "crime: ";
			cout << information[i].crime << endl << endl;
			cout << "criminal's status: ";
			cout << information[i].status << endl << endl;
			cout << "date of arrest: ";
			cout << information[i].date_of_arrest << endl << endl;
			cout << "criminal's ID: ";
			cout << information[i].ID << endl << endl;
		}
	}
	cout << "Enter 1 to return to menu, or 0 to exit" << endl;
	while (x >= -1) {
		cin >> x;
		switch (x)
		{
		case '0':
			CallExit();
			break;
		case '1':
			officer_menu(information, array_size);
			break;
		}
		if (x != '1' && x != '0') {
			cout << "PLEASE CHOOSE  1 OR 0" << endl;
		}
	}

}
void assigned_casses(info1 information[], int array_size)//Displays assigned casses for the officer that are assigned from the database
{
	system("cls");
	char x = -1;
	string id;
	cout << "\n";
	for (int i = 0; i < array_size; i++)
	{
		if (information[i].assigned_cases == "1")
		{
			cout << "criminal's firstname: ";
			cout << information[i].first_name << endl << endl;
			cout << "criminal's lastname: ";
			cout << information[i].last_name << endl << endl;
			cout << "criminal's birthdate: ";
			cout << information[i].birthdate << endl << endl;
			cout << "crime: ";
			cout << information[i].crime << endl << endl;
			cout << "criminal's status: ";
			cout << information[i].status << endl << endl;
			cout << "date of arrest: ";
			cout << information[i].date_of_arrest << endl << endl;
			cout << "criminal's ID: ";
			cout << information[i].ID << endl << endl;
			cout << "-----------------------------------------------------------------------------------------------------------------------" << endl << endl;
		}
	}
	cout << "Enter 0 to exit" << endl;
	while (x >= -1) {
		cin >> x;
		switch (x)
		{
		case '0':
			CallExit();
			break;

		}
		if (x != '0') {
			cout << "PLEASE CHOOSE 0" << endl;
		}
	}
}


int main()
{
	const int array_size = 50;
	info1* information = new info1[array_size];    //Array of structs that includes the database
	int res;
	information[0].first_name = "Salma";
	information[0].last_name = "Youssef";
	information[0].birthdate = "11/5/2002";
	information[0].crime = "murder";
	information[0].status = "15 years of prison";
	information[0].date_of_arrest = "21/8/2021";
	information[0].ID = "1";
	information[0].assigned_cases = "1";

	information[1].first_name = "Alaa";
	information[1].last_name = "Serag";
	information[1].birthdate = "18/10/2003";
	information[1].crime = "theft";
	information[1].status = "3 years of prison";
	information[1].date_of_arrest = "12/7/2022";
	information[1].ID = "2";
	information[1].assigned_cases = "0";

	information[2].first_name = "Youssef";
	information[2].last_name = "Salah";
	information[2].birthdate = "31/7/2003";
	information[2].crime = "Drug Dealer";
	information[2].status = "25 years of prison";
	information[2].date_of_arrest = "31/7/2015";
	information[2].ID = "3";
	information[2].assigned_cases = "1";

	welcomescreen();
	res = login(information, array_size);
	if (res == 1)
	{

		cout << "\n \n \n" << endl;

		for (int i = 3; i >= 0; i--) {

			sleep_for(seconds(1));
			cout << "Accessing in " << i << " seconds" << endl;;
		}
		admin_menu(information, array_size);
	}
	else if (res == 0)
	{
		cout << "\n \n \n" << endl;

		for (int i = 3; i >= 0; i--) {

			sleep_for(seconds(1));
			cout << "Accessing in " << i << " seconds" << endl;;
		}
		officer_menu(information, array_size);
	}
	else if (res == 2)
	{
		repeat(information, array_size);

	}
	delete[] information;
}

void admin_menu(info1 information[], int array_size)//admin menu
{
	char choose;
	system("cls");
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
	cout << setw(70) << " Please choose your preferred option" << endl << endl;
	cout << " 1. ADD CRIMINAL" << endl << endl;
	cout << " 2. DELETE CRIMINAL" << endl << endl;
	cout << " 3. SEARCH FOR A CRIMINAL" << endl << endl;
	cout << " 4. MODIFY CRIMINAL" << endl << endl;
	cout << " 5. DISPLAY ALL CRIMINALS" << endl << endl;
	cout << " 6. ACCESS OFFICER'S PAGE" << endl << endl;

	cin >> choose;
	switch (choose) {
	case '1':add(information, array_size);
		break;

	case '2':remove(information, array_size);
		break;

	case '3':display(information, array_size);
		break;

	case '4':modify(information, array_size);
		break;

	case '5':display_all(information, array_size);
		break;


	case '6':officer_menu(information, array_size);
		break;


	default:
		cout << "Please enter a number from 1-6!" << endl;
		sleep_for(seconds(2));
		admin_menu(information, array_size);
		break;
	}


}

void modify_menu(info1 information[], int array_size)
{
	char choose;
	system("cls");
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
	cout << " Please choose what you wish to modify" << endl << endl;
	cout << " 1. CRIMINAL'S FIRSTNAME" << endl << endl;
	cout << " 2. CRIMINAL'S LASTNAME" << endl << endl;
	cout << " 3. CRIMINAL'S BIRTHDATE" << endl << endl;
	cout << " 4. CRIME" << endl << endl;
	cout << " 5. CRIMINAL'S STATUS" << endl << endl;
	cout << " 6. DATE OF ARREST" << endl << endl;

	cin >> choose;
	switch (choose) {
	case '1':
		for (int i = 0; i < array_size; i++)
		{
			cout << "Enter criminal's firstname: ";
			cin.ignore(1, '\n');
			getline(cin, information[i].first_name);
			while (information[i].first_name >= "0" && information[i].first_name <= "9") {
				cout << "Invalid Input , Please try again!" << endl;
				cout << "Enter criminal's firstname: ";
				getline(cin, information[i].first_name);
			}
			break;
		}
		break;
	case '2':
		for (int i = 0; i < array_size; i++)
		{
			cout << "Enter criminal's lastname: ";
			cin.ignore(1, '\n');
			getline(cin, information[i].last_name);
			while (information[i].last_name >= "0" && information[i].last_name <= "9") {
				cout << "Invalid Input , Please try again!" << endl;
				cout << "Enter criminal's lastname: ";
				getline(cin, information[i].last_name);
			}
			break;
		}
		break;
	case '3':
		for (int i = 0; i < array_size; i++)
		{
			cout << "Enter criminal's birthdate: ";
			cin.ignore(1, '\n');
			getline(cin, information[i].birthdate);
			break;
		}
		break;
	case '4':
		for (int i = 0; i < array_size; i++)
		{
			cout << "Enter crime: ";
			cin.ignore(1, '\n');
			getline(cin, information[i].crime);
			while (information[i].crime >= "0" && information[i].crime <= "9") {
				cout << "Invalid Input , Please try again!" << endl;
				cout << "Enter criminal's crime: ";
				getline(cin, information[i].crime);
			}
			break;
		}
		break;
	case '5':
		for (int i = 0; i < array_size; i++)
		{
			cout << "Enter criminal's status: ";
			cin.ignore(1, '\n');
			getline(cin, information[i].crime);
			break;
		}
		break;
	case '6':
		for (int i = 0; i < array_size; i++)
		{
			cout << "Enter date of arrest: ";
			cin.ignore(1, '\n');
			getline(cin, information[i].date_of_arrest);
			break;
		}
		break;
	default:
		cout << "Please enter a number from 1-6!" << endl;
		sleep_for(seconds(2));
		modify_menu(information, array_size);
		break;

	}
}

void officer_menu(info1 information[], int array_size)//Officer menu
{
	char choose;
	system("cls");
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
	cout << " WELCOME TO OFFICER'S PAGE" << endl << endl;
	cout << " ENTER 1 TO DISPLAY ASSIGNED CASES" << endl << endl;



	cin >> choose;
	switch (choose)
	{
	case '1':
		assigned_casses(information, array_size);
		break;

	default:
		cout << "Please enter 1" << endl;
		sleep_for(seconds(2));
		officer_menu(information, array_size);
		break;
	}

}

void repeat(info1 information[], int array_size) //when the user fails to enter the correct
{
	char* username;
	username = new char[20];
	char* password;
	password = new char[20];
	int i = 3;
	cout << "You have " << i << " trials left" << endl;
	for (int i = 3; i > 0; i--) {
		system("cls");
		char username[20];
		char password[20];
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "------------------------------------Welcome to our criminal database---------------------------------------------------" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "You have " << i << " trials left" << endl;
		cout << "\n \n \t \t  Please Enter your username :";
		cin.getline(username, 10);
		cout << "\n \n \t \t Please Enter your password :";
		cin.getline(password, 10);
		if (strcmp(username, "admin") == 0 && strcmp(password, "pass") == 0) {
			admin_menu(information, array_size);
		}
		else if (strcmp(username, "ADMIN") == 0 && strcmp(password, "PASS") == 0) {
			admin_menu(information, array_size);
		}
		else if (strcmp(username, "officer") == 0 && strcmp(password, "pass") == 0) {
			officer_menu(information, array_size);
		}
		else if (strcmp(username, "OFFICER") == 0 && strcmp(password, "PASS") == 0) {
			officer_menu(information, array_size);
		}
		else {
			cout << "You have " << i - 1 << " trials left" << endl;
		}
		if (i == 1) {
			CallExit();

		}
	}
	delete[] username;
	delete[] password;
}