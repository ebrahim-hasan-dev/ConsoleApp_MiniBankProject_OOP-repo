#pragma once

#include "clsAddNewUserScreen.h";

class clsDeleteUserScreen : clsScreen
{
private:

	static void _PrintUser(clsUser& User)
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

	static void _DeleteUser()
	{
		clsUser User;

		User.UserName = clsInput<string>::Readstring("\n\nPlease Enter UserName  : ");

		MakeSureUserIsExist(User);

		_PrintUser(User);

		char sure = 'y';
		cout << "\n\nAre you sure you want to delete this User (y, n) ? ";
		cin >> sure;
		clsAddNewUserScreen::CheckIsValidAnswer(sure);

		if (tolower(sure) == 'y')
		{
			if (User.Delete())
			{
				cout << "\n\nUser deleted Successfully :-)\n";
			}
			else
			{
				cout << "\n\nYou cannot delete this user.\n";
				return;
			}
		}
		else
		{
			cout << "\n\nUser don't deleted.\n";
		}

		_PrintUser(User);

	}

public:

	static void MakeSureUserIsExist(clsUser& User)
	{
		while (!clsUser::IsUserExist(User))
		{
			cout << "\n\nUser with UserName [" << User.UserName << "] is not found,";
			User.UserName = clsInput<string>::Readstring("\n\nEnter another UserName : ");
		}
	}

	static void PrintDeleteScreen()
	{
		system("cls");

		_DrawScreenHeader("Delete User Screen");

		_DeleteUser();
	}





};

