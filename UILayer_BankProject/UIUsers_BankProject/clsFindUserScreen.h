#pragma once

#include "clsDeleteUserScreen.h";


class clsFindUserScreen : protected clsScreen
{
private:

	static void _PrintUser(clsUser User)
	{
		cout << "\n\nUser Data:\n";
		cout << "----------------------------------------------------\n";
		cout << "First Name                : " << User.FirstName << endl;
		cout << "Last Name                 : " << User.LastName << endl;
		cout << "Full Name                 : " << User.GetFullName() << endl;
		cout << "Email                     : " << User.Email << endl;
		cout << "Phone                     : " << User.Phone << endl;
		cout << "UserName                  : " << User.UserName << endl;
		cout << "PassWord                  : " << User.PassWord << endl;
		cout << "Permissions               : " << User.Permissions << endl;
		cout << "----------------------------------------------------\n\n";
	}

public:

	static void PrintFindUserScreen()
	{
		system("cls");

		_DrawScreenHeader("Find User Screen");

		clsUser User;

		User.UserName = clsInput<string>::Readstring("\n\nPlease Enter UserName : ");

		clsDeleteUserScreen::MakeSureUserIsExist(User);

		_PrintUser(User);
	}



};

