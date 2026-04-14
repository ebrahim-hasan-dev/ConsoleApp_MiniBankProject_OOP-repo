#pragma once


#include "../UIAllMenues_BankProject\clsScreen.h";
#include "../../LogicalLayer_BankProject\clsBanckClient.h";
#include "../../LogicalLayer_BankProject\clsUser.h";


class clsUsersListScreen : clsScreen
{
private:

	static void PrintHeaderTapleOfUsersList()
	{
		cout << "\n\n------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "| " << left << setw(15) << "UserName";
		cout << "| " << left << setw(10) << "PassWord";
		cout << "| " << left << setw(25) << "Full Name";
		cout << "| " << left << setw(25) << "Email";
		cout << "| " << left << setw(15) << "Phone";
		cout << "| " << left << setw(12) << "Permissions";
		cout << "\n\n------------------------------------------------------------------------------------------------------------------\n\n";
	}

	static void PrintUserDatainList(clsUser& User)
	{
		cout << "| " << left << setw(15) << User.UserName;
		cout << "| " << left << setw(10) << User.PassWord;
		cout << "| " << left << setw(25) << User.GetFullName();
		cout << "| " << left << setw(25) << User.Email;
		cout << "| " << left << setw(15) << User.Phone;
		cout << "| " << left << setw(12) << User.Permissions;
	}


public:

	
	static void ManageUsersListScreen() 
	{
		system("cls");

		vector <clsUser> vUsers = clsUser::GetAllUsers();

		string Title = "Users List Screen";
		string SubTitle = "(" + to_string(vUsers.size()) + ") User(s).";

		_DrawScreenHeader(Title, SubTitle);

		PrintHeaderTapleOfUsersList();

		for (clsUser& User : vUsers)
		{
			PrintUserDatainList(User);
			cout << endl;
		}
		cout << "\n\n------------------------------------------------------------------------------------------------------------------\n\n";

		
	}

};

