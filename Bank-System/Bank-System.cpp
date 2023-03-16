#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

int logInSystem(string userName, string password);
void newUser();
void deposit(string userName, int moneyAmmount);
int withDraw(string userName, int moneyAmmount);
int intGetDataByline(string userName, int line);
string stGetDataByline(string userName, int line);
int getLength(int number);
int checkValid(string userName, string pin);
void EditDatabyline(string userName, int place, string replace);
void deleteDatabyline(string place);
void deleteFile(string fileName, string path);
string stars(int size);
string equalShape(int size);
string space(int size);

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
time_t now = time(0);
//char* timeNow = ctime(&now);
string dataLocation = "\\Database";

int main()
{
	string userName, password, pin, phoneNumber;
	int userChoice, moneyAmmount;
	cout << "(01). Bank System" << endl;
	cout << "(02). ATM";
	cout << "\n\nSelect Your Option (1-2) ";
	cin >> userChoice;

	if (userChoice == 1)
	{
		cout << "\t\t\t\t\tpress enter to countinue";
		cin.ignore();
		system("cls");
		cout << stars(39) << endl;
		cout << stars(15) << " Welcome to the Bank " << stars(17) << endl;
		cout << stars(39) << endl << endl << endl;
		if (logInSystem(userName, password) == 0)
		{
			return 0;
		}
		cout << endl << endl << stars(2) << "Goodmorning Sir" << stars(2) << endl << endl;
		while (1)
		{
			cout << "\n\t(Main Menu)\n";
			cout << "\n(01). New Account";
			cout << "\n(02). Deposit Amount";
			cout << "\n(03). Withdraw Amount";
			cout << "\n(04). Transfer Money";
			cout << "\n(05). Statement Of Account";
			cout << "\n(06). All Account Holder List";
			cout << "\n(07). Close An Account";
			cout << "\n(08). Change PIN Code";
			cout << "\n(09). Exit";
			cout << "\n\nSelect Your Option (1-9) ";
			cin >> userChoice;

			if (userChoice == 1)
			{
				newUser();
				SetConsoleTextAttribute(h, 2);
				cout << "\nUser has been added succesfully...";
				SetConsoleTextAttribute(h, 7);

			}
			else if (userChoice == 2)
			{
				while (1)
				{
					cout << "\nPlease enter the full name   (Without space)\n";
					cin >> userName;
					cout << "Please enter the PIN number\n";
					cin >> pin;

					if (checkValid(userName, pin) == 1)
					{
						SetConsoleTextAttribute(h, 2);
						cout << "\nThe account has been founded!\n";
						SetConsoleTextAttribute(h, 7);
						cout << "\nPlease put the ammount that you want to deposit: ";
						cin >> moneyAmmount;

						deposit(userName, moneyAmmount);
						break;
					}
					else if (checkValid(userName, pin) == 0)
					{
						SetConsoleTextAttribute(h, 4);
						cout << "There is no record with this entery..!\n";
						SetConsoleTextAttribute(h, 7);
						cout << "Try again press (1)    Main menu press (0)\n";
						cin >> userChoice;
						if (userChoice == 0)
						{
							break;
						}
					}
					else
					{
						SetConsoleTextAttribute(h, 4);
						cout << "Wrong Input..!";
						SetConsoleTextAttribute(h, 7);

					}
				}

			}
			else if (userChoice == 3)
			{
				while (1)
				{
					cout << "\nPlease enter the full name   (Without space)\n";
					cin >> userName;
					cout << "Please enter the PIN number\n";
					cin >> pin;

					if (checkValid(userName, pin) == 1)
					{
						SetConsoleTextAttribute(h, 2);
						cout << "\nThe account has been founded!\n";
						SetConsoleTextAttribute(h, 7);
						cout << "\nPlease put the ammount that you want to take: ";
						cin >> moneyAmmount;

						if (intGetDataByline(userName, 4) < moneyAmmount)
						{
							SetConsoleTextAttribute(h, 4);
							cout << "\nThere is no enought balance at the account..!\n";
							SetConsoleTextAttribute(h, 7);
						}
						else
						{
							withDraw(userName, moneyAmmount);
							cout << "Proccess Sucessfully..!";
						}
						break;

					}
					else if (checkValid(userName, pin) == 0)
					{
						SetConsoleTextAttribute(h, 4);
						cout << "There is no record with this entery..!\n";
						SetConsoleTextAttribute(h, 7);
						cout << "Try again press (1)    Main menu press (0)\n";
						cin >> userChoice;
						if (userChoice == 0)
						{
							break;
						}
					}
					else
					{
						SetConsoleTextAttribute(h, 4);
						cout << "Wrong Input..!";
					}	SetConsoleTextAttribute(h, 7);
				}
			}
			else if (userChoice == 4)
			{
				string userName1;
				while (1)
				{
					cout << "\nPlease enter the full name   (Without space)\n";
					cin >> userName;
					cout << "Please enter the PIN number\n";
					cin >> pin;

					if (checkValid(userName, pin) == 1)
					{
						while (1)
						{
							SetConsoleTextAttribute(h, 2);
							cout << "\nThe account has been founded!\n";
							SetConsoleTextAttribute(h, 7);
							cout << "\nPlease put the other account full name   (Without space)\n";
							cin >> userName1;
							if (checkValid(userName1, userName1) == 1)
							{
								cout << "\nPut the ammount of money you want to transfer: ";
								cin >> moneyAmmount;
								if (withDraw(userName, moneyAmmount) == 0)
								{
									SetConsoleTextAttribute(h, 4);
									cout << "\nThere is no enought balance at the account..!\n";
									SetConsoleTextAttribute(h, 7);
								}
								else
								{
									withDraw(userName, moneyAmmount);
									deposit(userName1, moneyAmmount);

									SetConsoleTextAttribute(h, 2);
									cout << "\nMoney has transferred successfully..!\n";
									SetConsoleTextAttribute(h, 7);
									break;
								}

							}
							else if (checkValid(userName1, userName1) == 0)
							{
								SetConsoleTextAttribute(h, 4);
								cout << "There is no avalible records with this entery";
								SetConsoleTextAttribute(h, 7);
							}
						}

						break;
					}
					else if (checkValid(userName, pin) == 0)
					{
						SetConsoleTextAttribute(h, 4);
						cout << "There is no record with this entery..!\n";
						SetConsoleTextAttribute(h, 7);
						cout << "Try again press (1)    Main menu press (0)\n";
						cin >> userChoice;
						if (userChoice == 0)
						{
							break;
						}
					}
					else
					{
						SetConsoleTextAttribute(h, 4);
						cout << "Wrong Input..!";
						SetConsoleTextAttribute(h, 7);
					}
				}
			}
			else if (userChoice == 5)
			{
				while (1)
				{
					cout << "\nPlease enter the full name   (Without space)\n";
					cin >> userName;
					cout << "Please enter the PIN number\n";
					cin >> pin;

					if (checkValid(userName, pin) == 1)
					{
						SetConsoleTextAttribute(h, 2);
						cout << "\nThe account has been founded!\n";
						SetConsoleTextAttribute(h, 7);
						ifstream view;
						view.open(dataLocation + "logs\\" + userName + ".txt");
						string data;
						cout << endl << equalShape(15) << endl;
						cout << "  Monney Ammount" << space(5) << "Time" << endl;
						cout << equalShape(15) << endl << endl;
						while (getline(view, data))
						{
							cout << "\t" << data << setw(5) << endl;
						}
						break;
					}
					else if (checkValid(userName, pin) == 0)
					{
						SetConsoleTextAttribute(h, 4);
						cout << "There is no record with this entery..!\n";
						SetConsoleTextAttribute(h, 7);
						cout << "Try again press (1)    Main menu press (0)\n";
						cin >> userChoice;
						if (userChoice == 0)
						{
							break;
						}
					}
					else
					{
						SetConsoleTextAttribute(h, 4);
						cout << "\nWrong Input..!\n";
						SetConsoleTextAttribute(h, 7);
					}

				}
			}
			else if (userChoice == 6)
			{
				cout << endl << equalShape(33) << endl;
				cout << "  First Name" << space(5) << "Second Name" << space(5) << "Phone Number" << space(5) << "PIN Code" << space(5) << "Money Ammount" << endl;
				cout << equalShape(33) << endl << endl;
				ifstream get;
				string names;
				get.open("collectingUserNames.txt");
				if (!get)
				{
					cout << "There is no avalible data..";
				}
				else
				{
					while (getline(get, names))
					{
						cout << "    " << stGetDataByline(names, 0) << setw(22);
						cout << stGetDataByline(names, 1) << setw(23);
						cout << stGetDataByline(names, 2) << setw(16);
						cout << stGetDataByline(names, 3) << setw(20);
						cout << stGetDataByline(names, 4) << endl;

					}

					get.close();

				}
			}
			else if (userChoice == 7)
			{
				while (1)
				{
					cout << "\nPlease enter the full name   (Without space)\n";
					cin >> userName;
					cout << "Please enter the PIN number\n";
					cin >> pin;

					if (checkValid(userName, pin) == 1)
					{
						SetConsoleTextAttribute(h, 2);
						cout << "\nThe account has been founded!\n";
						SetConsoleTextAttribute(h, 7);
						cout << "Are you sure of Deleting the account!" << "(Yes: 1     No: 2)\n";
						cin >> userChoice;
						if (userChoice == 1)
						{
							string deleteFile = dataLocation + userName + ".txt";
							remove(deleteFile.c_str());
							deleteDatabyline(userName);
							SetConsoleTextAttribute(h, 2);
							cout << "The account has been deleted sucessfully..!\n";
							SetConsoleTextAttribute(h, 7);

						}
						else if (userChoice == 2)
						{
							break;

						}
						else
						{
							SetConsoleTextAttribute(h, 2);
							cout << "Wrong Input..!";
							SetConsoleTextAttribute(h, 7);
						}
						break;

					}
					else if (checkValid(userName, pin) == 0)
					{
						SetConsoleTextAttribute(h, 4);
						cout << "There is no record with this entery..!\n";
						SetConsoleTextAttribute(h, 7);
						cout << "Try again press (1)    Main menu press (0)\n";
						cin >> userChoice;
						if (userChoice == 0)
						{
							break;
						}
					}
					else
					{
						SetConsoleTextAttribute(h, 4);
						cout << "\nWrong Input..!\n";
						SetConsoleTextAttribute(h, 7);
					}
				}
			}
			else if (userChoice == 8)
			{
				while (1)
				{
					cout << "\nPlease enter the full name   (Without space)\n";
					cin >> userName;
					cout << "Please Put the phone number\n";
					cin >> phoneNumber;

					if (checkValid(userName, phoneNumber) == 1)
					{
						SetConsoleTextAttribute(h, 2);
						cout << "\nThe account has been founded!\n";
						SetConsoleTextAttribute(h, 7);
						int intPin, check;
						cout << "\n(PIN number consist of 4 digits)";
						cout << "\nPIN number: ";
						cin >> intPin;

						if (getLength(intPin) != 4)
						{
							while (getLength(intPin) != 4)
							{
								SetConsoleTextAttribute(h, 4);
								cout << "This is not the right format";
								SetConsoleTextAttribute(h, 7);
								cout << "\nPIN number: ";
								cin >> intPin;
							}
						}
						cout << "\nRe-enter PIN number: ";
						cin >> check;
						if (intPin != check)
						{
							while (intPin != check)
							{
								SetConsoleTextAttribute(h, 4);
								cout << "The format you entered is not the same!\n\n";
								SetConsoleTextAttribute(h, 7);
								cout << "\nPIN number: ";
								cin >> intPin;
								cout << "\nRe-enter PIN number: \n";
								cin >> check;
							}
						}
						pin = to_string(intPin);
						EditDatabyline(userName, 3, pin);
						SetConsoleTextAttribute(h, 2);
						cout << "\nThe PIN code has been changed successfully..!\n";
						SetConsoleTextAttribute(h, 7);
						break;
					}
					else if (checkValid(userName, phoneNumber) == 0)
					{
						SetConsoleTextAttribute(h, 4);
						cout << "There is no record with this entery..!\n";
						SetConsoleTextAttribute(h, 7);
						cout << "Try again press (1)    Main menu press (0)\n";
						cin >> userChoice;
						if (userChoice == 0)
						{
							break;
						}
					}
					else
					{
						SetConsoleTextAttribute(h, 4);
						cout << "Wrong Input..!";
						SetConsoleTextAttribute(h, 7);
					}
				}
			}
			else if (userChoice == 9)
			{
				cout << "\nGood bye and have a nice day...\n";
				return 0;
			}
			else
			{
				SetConsoleTextAttribute(h, 4);
				cout << "\nThere is no choice with this number..!\n\n";
				SetConsoleTextAttribute(h, 7);
			}

		}
	}
	else if (userChoice == 2)
	{
		cout << "\t\t\t\t\tpress enter to countinue";
		cin.ignore();
		system("cls");
		cout << stars(39) << endl;
		cout << stars(15) << " Welcome to the ATM " << stars(17) << endl;
		cout << stars(39) << endl << endl << endl;
		while (1)
		{
			cout << "\n\tWELCOME TO THE ATM SYSTEM" << endl;
			cout << "(01). For deposit" << endl;
			cout << "(02). For withdrawel" << endl;
			cout << "(03). To Transfer Money" << endl;
			cout << "(04). Statement Of Account";
			cout << "\n\nSelect Your Option (1-4) ";
			cin >> userChoice;

			if (userChoice == 1)
			{
				while (1)
				{
					cout << "\nPlease enter the full name   (Without space)\n";
					cin >> userName;
					cout << "Please Put the PIN number\n";
					cin >> pin;

					if (checkValid(userName, pin) == 1)
					{
						SetConsoleTextAttribute(h, 2);
						cout << "\nThe account has been founded!\n";
						SetConsoleTextAttribute(h, 7);
						cout << "(01). 200\t\t" << "(02). 400\t\t" << "(03). 800\t\t" << endl;
						cout << "(04). 1000\t\t" << "(05). 1500\t\t" << "(06). 2000\t\t" << endl;
						cout << "\n(07). Other Options";
						cin >> userChoice;
						if (userChoice == 1)
						{
							deposit(userName, 200);
							cout << "money has been added successfully";
							break;
						}
						else if (userChoice == 2)
						{
							deposit(userName, 400);
							cout << "money has been added successfully";
							break;
						}
						else if (userChoice == 3)
						{
							deposit(userName, 800);
							cout << "money has been added successfully";
							break;
						}
						else if (userChoice == 4)
						{
							deposit(userName, 1000);
							cout << "money has been added successfully";
							break;
						}
						else if (userChoice == 5)
						{
							deposit(userName, 1500);
							cout << "money has been added successfully";
							break;
						}
						else if (userChoice == 6)
						{
							deposit(userName, 2000);
							cout << "money has been added successfully";
							break;
						}
						else if (userChoice == 7)
						{
							cout << "Enter the ammount you want to deposit: ";
							cin >> moneyAmmount;
							deposit(userName, moneyAmmount);
							cout << "money has been added successfully";
							break;
						}

					}
					else if (checkValid(userName, pin) == 0)
					{
						SetConsoleTextAttribute(h, 4);
						cout << "There is no record with this entery..!\n";
						SetConsoleTextAttribute(h, 7);
						cout << "Try again press (1)    Exit (0)\n";
						cin >> userChoice;
						if (userChoice == 0)
						{
							return 0;
						}
					}
					else
					{
						SetConsoleTextAttribute(h, 4);
						cout << "Wrong Input..!";
						SetConsoleTextAttribute(h, 7);

					}

				}

			}
			else if (userChoice == 2)
			{
				while (1)
				{
					cout << "\nPlease enter the full name   (Without space)\n";
					cin >> userName;
					cout << "Please enter the PIN number\n";
					cin >> pin;

					if (checkValid(userName, pin) == 1)
					{

						cout << "\nThe account has been founded!\n";
						cout << "\nPlease put the ammount that you want to take: ";
						cin >> moneyAmmount;

						if (withDraw(userName, moneyAmmount) == 0)
						{
							cout << "\nThere is no enought balance at the account..!\n";
						}
						else
						{
							withDraw(userName, moneyAmmount);
							cout << "money has been taken successfully";
						}
						break;
					}
					else if (checkValid(userName, pin) == 0)
					{
						cout << "There is no record with this entery..!\n";
						cout << "Try again press (1)    Main menu press (0)\n";
						cin >> userChoice;
						if (userChoice == 0)
						{
							break;
						}
					}
					else
					{
						cout << "Wrong Input..!";
					}
				}
			}
			else if (userChoice == 3)
			{
				string userName1;
				while (1)
				{
					cout << "\nPlease enter the full name   (Without space)\n";
					cin >> userName;
					cout << "Please enter the PIN number\n";
					cin >> pin;

					if (checkValid(userName, pin) == 1)
					{
						while (1)
						{
							cout << "\nThe account has been founded!\n";
							cout << "\nPlease put the other account full name   (Without space)\n";
							cin >> userName1;
							if (checkValid(userName1, userName1) == 1)
							{
								cout << "\nPut the ammount of money you want to transfer: ";
								cin >> moneyAmmount;
								if (withDraw(userName, moneyAmmount) == 0)
								{
									cout << "\nThere is no enought balance at the account..!\n";

								}
								else
								{
									withDraw(userName, moneyAmmount);
									deposit(userName1, moneyAmmount);
									cout << "\nMoney has transferred successfully..!\n";
									break;
								}

							}
							else if (checkValid(userName1, userName1) == 0)
							{
								cout << "There is no avalible records with this entery";
							}
						}

						break;
					}
					else if (checkValid(userName, pin) == 0)
					{
						cout << "There is no record with this entery..!\n";
						cout << "Try again press (1)    Main menu press (0)\n";
						cin >> userChoice;
						if (userChoice == 0)
						{
							break;
						}
					}
					else
					{
						cout << "Wrong Input..!";
					}
				}
			}
			else if (userChoice == 4)
			{
				while (1)
				{
					cout << "\nPlease enter the full name   (Without space)\n";
					cin >> userName;
					cout << "Please enter the PIN number\n";
					cin >> pin;

					if (checkValid(userName, pin) == 1)
					{
						SetConsoleTextAttribute(h, 2);
						cout << "\nThe account has been founded!\n";
						SetConsoleTextAttribute(h, 7);
						ifstream view;
						view.open(dataLocation + "logs\\" + userName + ".txt");
						string data;
						cout << endl << equalShape(15) << endl;
						cout << "  Monney Ammount" << space(5) << "Time" << endl;
						cout << equalShape(15) << endl << endl;
						while (getline(view, data))
						{
							cout << "\t" << data << setw(5) << endl;
						}
						break;
					}
					else if (checkValid(userName, pin) == 0)
					{
						SetConsoleTextAttribute(h, 4);
						cout << "There is no record with this entery..!\n";
						SetConsoleTextAttribute(h, 7);
						cout << "Try again press (1)    Main menu press (0)\n";
						cin >> userChoice;
						if (userChoice == 0)
						{
							break;
						}
					}
					else
					{
						SetConsoleTextAttribute(h, 4);
						cout << "\nWrong Input..!\n";
						SetConsoleTextAttribute(h, 7);
					}

				}
			}
			cout << endl << "To back to the main menu press (1)    Exit (0)\n";
			cin >> userChoice;
			if (userChoice == 0)
			{
				break;
			}
		}
	}
}

int logInSystem(string userName, string password)
{
	cout << "(Please put your work account)\n";
	cout << "Username: ";
	cin >> userName;
	cout << endl;
	for (int i = 2; i > 0; i--)
	{

		if (userName != "1234")
		{
			SetConsoleTextAttribute(h, 4);
			cout << "(" << i << " Trials lefts)\n";
			SetConsoleTextAttribute(h, 7);
			cout << "Re-enter Username: ";
			cin >> userName;
			cout << endl;
		}

	}
	if (userName != "1234")
	{
		SetConsoleTextAttribute(h, 4);
		cout << "System has been blocked...";
		SetConsoleTextAttribute(h, 7);
		return 0;
	}

	cout << "Password: ";
	cin >> password;
	cout << endl;
	for (int i = 2; i > 0; i--)
	{

		if (password != "1234")
		{
			SetConsoleTextAttribute(h, 4);
			cout << i << " Trials lefts.\n";
			SetConsoleTextAttribute(h, 7);
			cout << "Re-enter Password: ";
			cin >> password;
		}

	}
	if (password != "1234")
	{
		SetConsoleTextAttribute(h, 4);
		cout << "System has been blocked...";
		SetConsoleTextAttribute(h, 7);
		return 0;
	}
}

void newUser()
{
	string name;
	string stUserData[2];//    [0] firstname, [1] lastname
	int intUserData[3], check, userChoice = 0, i = 0;//    [0] phonenumber, [1] pin, [2] Money Ammount
	intUserData[2] = { 0 };
	string stFileArrange[2] = { " << Firstname", " << Lastname" };

	cout << "(Please fill the upcomming fields)\n\n";
	cout << "Firstname: ";
	cin >> stUserData[0];


	cout << "\nLast name: ";
	cin >> stUserData[1];

	fstream putNames;
	putNames.open("collectingUserNames.txt", ios::out | ios::app);
	putNames << stUserData[0] + stUserData[1] << endl;
	putNames.close();

	cout << "\nPhone number: ";
	cin >> intUserData[0];

	if (getLength(intUserData[0]) != 10)
	{
		while (getLength(intUserData[0]) != 10)
		{
			SetConsoleTextAttribute(h, 4);
			cout << "\nThis Phone number format is wrong";
			SetConsoleTextAttribute(h, 7);
			cout << "\nRe-enter Phone number:";
			cin >> intUserData[0];
		}
	}


	cout << "\n(PIN number consist of 4 digits)";
	cout << "\nPIN number: ";
	cin >> intUserData[1];
	if (getLength(intUserData[1]) != 4)
	{
		while (getLength(intUserData[1]) != 4)
		{
			SetConsoleTextAttribute(h, 4);
			cout << "This is not the right format";
			SetConsoleTextAttribute(h, 7);
			cout << "\nPIN number: ";
			cin >> intUserData[1];
		}
	}
	cout << "\nRe-enter PIN number: ";
	cin >> check;
	if (intUserData[1] != check)
	{
		while (intUserData[1] != check)
		{
			SetConsoleTextAttribute(h, 4);
			cout << "The format you entered is not the same!\n\n";
			SetConsoleTextAttribute(h, 7);
			cout << "\nPIN number: ";
			cin >> intUserData[1];
			cout << "\nRe-enter PIN number: \n";
			cin >> check;
		}
	}
	cout << "\nHow much you want to deposit       (NOTE: Minimum charge is 1000)\n";
	cin >> intUserData[2];

	while (1)
	{
		if (intUserData[2] < 1000)
		{
			SetConsoleTextAttribute(h, 4);
			cout << "This is less than the required\n";
			SetConsoleTextAttribute(h, 7);
			cout << "How much you want to deposit       (NOTE: Minimum charge is 1000)\n";
			cin >> intUserData[2];

		}
		else if (intUserData[2] >= 1000)
		{
			SetConsoleTextAttribute(h, 2);
			cout << "Money has added successfully..!";
			SetConsoleTextAttribute(h, 7);
			break;

		}
	}



	ofstream write;
	write.open(dataLocation + stUserData[0] + stUserData[1] + ".txt");

	for (int i = 0; i < 2; i++)
	{
		write << stUserData[i] << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			write << 0 << intUserData[i] << endl;
		}
		else
		{
			write << intUserData[i] << endl;
		}

	}


	write.close();
}

void deposit(string userName, int moneyAmmount)
{
	int accAmmount = intGetDataByline(userName, 4);
	accAmmount += moneyAmmount;
	string stNumber = to_string(accAmmount);
	EditDatabyline(userName, 4, stNumber);
	ofstream write;
	write.open(dataLocation + "logs\\" + userName + ".txt", ios::out | ios::app);
	//write << "+ " << moneyAmmount << space(5) << timeNow << endl;
	write.close();
}

int withDraw(string userName, int moneyAmmount)
{
	int accAmmount = intGetDataByline(userName, 4);

	if (moneyAmmount > accAmmount)
	{
		return 0;
	}
	else
	{
		accAmmount -= moneyAmmount;
		string stNumber = to_string(accAmmount);
		EditDatabyline(userName, 4, stNumber);
		fstream write;
		write.open(dataLocation + "logs\\" + userName + ".txt", ios::out | ios::app);
		//write << "- " << moneyAmmount << space(5) << timeNow << endl;
		write.close();
	}

}

int intGetDataByline(string userName, int line)
{
	ifstream read;
	string stData[5];
	int intData;

	read.open(dataLocation + userName + ".txt");
	for (int i = 0; i < 5; i++)
	{
		getline(read, stData[i]);

	}

	intData = stoi(stData[line]);
	return intData;

	read.close();
}

string stGetDataByline(string userName, int line)
{
	string data, newData[5];

	ifstream view;
	view.open(dataLocation + userName + ".txt");

	for (int i = 0; i < 5; i++)
	{
		getline(view, newData[i]);
	}
	return newData[line];

	view.close();
}

int getLength(int number)
{
	int length = 0;
	while (number)
	{
		number /= 10;
		length++;
	}
	return length;
}

int checkValid(string userName, string dataToCheck)
{
	ifstream viewData;
	string data;

	viewData.open(dataLocation + userName + ".txt");


	if (viewData >> data)
	{
		if (stGetDataByline(userName, 3) == dataToCheck)
		{
			return 1;
		}
		else if (stGetDataByline(userName, 2) == dataToCheck)
		{
			return 1;
		}
		else if (stGetDataByline(userName, 0) + stGetDataByline(userName, 1) == dataToCheck)
		{
			return 1;
		}
	}

	viewData.close();
	return 0;
}

void EditDatabyline(string userName, int place, string replace)
{
	string newData[5];

	ifstream view;
	view.open(dataLocation + userName + ".txt");
	for (int i = 0; i < 5; i++)
	{
		getline(view, newData[i]);

	}
	newData[place] = replace;

	ofstream write;
	write.open(dataLocation + userName + ".txt");
	for (int i = 0; i < 5; i++)
	{
		write << newData[i] << endl;
	}
	write.close();
	view.close();
}

void deleteDatabyline(string place)
{
	string line[5];
	ifstream openFile;
	openFile.open("collectingUserNames.txt");
	ofstream temp;
	temp.open("temp.txt");

	for (int i = 0; i < 5; i++)
	{
		getline(openFile, line[i]);
		if (line[i] != place)
		{
			temp << line[i] << endl;
		}
	}


	temp.close();
	openFile.close();
	remove("collectingUserNames.txt");
	rename("temp.txt", "collectingUserNames.txt");
}

void deleteFile(string fileName, string path)
{
	ifstream openFile;
	string check;
	openFile.open(path + fileName + ".txt");

	openFile >> check;
	if (check == "")
	{
		string deleteFile = path + fileName + ".txt";
		remove(deleteFile.c_str());
	}

}

string stars(int size)
{
	string stars;
	for (int i = 0; i < size; i++)
	{
		stars += " * ";
	}
	return stars;
}

string equalShape(int size)
{
	string equalShape;
	for (int i = 0; i < size; i++)
	{
		equalShape += " = ";
	}
	return equalShape;
}

string space(int size)
{
	string space;
	for (int i = 0; i < size; i++)
	{
		space += "  ";
	}
	return space;
}
