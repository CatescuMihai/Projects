#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool LogIn() {

	string username, password, un, pw;

	cout << "Enter Username: ";
	cin >> username;
	cout << "Enter Password: ";
	cin >> password;

	ifstream read("D:\\" + username + ".txt");
	getline(read, un);
	getline(read, pw);

	if (un == username && pw == password) {

		return true;
	}
	else
	{
		return false;
	}

}

void change() {

	string username, un, pw;

	cout << "Enter Username: ";
	cin >> username;
	cout << endl;

	ifstream read("D:\\" + username + ".txt");
	getline(read, un);

	if (un == username) 
	{
	
		getline(read, pw);
		cout << "We found your password: ";
		cout << pw << endl << endl;

	
	}
	else
	{
	
		cout << "This username doesn't exist try again" <<endl << endl;
		change();
	
	}

}

int main() {

	int choice;
	cout << endl << "*#*#*#*#*#*#*#*#*#*#*        LOG IN MENU        *#*#*#*#*#*#*#*#*#*#*" << endl << endl;
	cout << "1: I want to Register " << endl;
	cout << "2: I want to log in" << endl;
	cout << "3: I forgot my password" << endl <<endl;
	cout << "Your choice: ";
	cin >> choice;
	cout << endl << endl;

	if (choice == 1)
	{

		string username, password;

		cout << "select a username: ";
		cin >> username;
		cout << "select a password: ";
		cin >> password;

		ofstream file;
		file.open("D:\\" + username + ".txt");
		file << username << endl << password;
		file.close();

		main();

	}
	else if (choice == 2)
	{
	
		bool status = LogIn();

		if (!status)
		{

			cout << endl << "Wrong Password/Username. Try again." << endl;
			
			main();


		}
		else
		{

			cout << endl << "Succesfuly logged in." << endl << endl;

			string choice2;

			cout << "Do you want ot log in again with a different account? (yes/no)" << endl << endl;
			cout << "Your choice: ";
			cin >> choice2;

			if (choice2 == "yes") 
				main();

		}

	}
	else if (choice == 3)
	{

		change();
		main();

	}
	else
	{

		cout << "This choice doesn't exist. Try again.";
		main();

	}
}