#pragma once


#include "clsDeleteUserScreen.h";
#include "clsAddNewUserScreen.h";


class clsUpdateUserScreen : clsScreen
{

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\n\nUpdate User Info:\n";
		cout << "---------------------\n";

		User.FirstName  = clsInput<string>::Readstring("\n\nEnter First Name      : ");
		User.LastName   = clsInput<string>::Readstring("Enter last Name       : ");
		User.Email      = clsInput<string>::Readstring("Enter Email           : ");
		User.Phone      = clsInput<string>::Readstring("Enter Phone           : ");
		User.PassWord   = clsInput<string>::Readstring("Enter PassWord        : ");

		clsAddNewUserScreen::ReadPermissions(User);
	}

	static void _PrintUser(clsUser& User)
	{
		cout << "\n\nUpdate User Data:\n";
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

	static void _UpdateUser()
	{
		clsUser User;

		User.UserName = clsInput<string>::Readstring("\n\nPlease Enter UserName  : ");

		clsDeleteUserScreen::MakeSureUserIsExist(User);

		_PrintUser(User);

		char sure = 'y';
		cout << "\n\nAre you sure you want to update this User (y, n) ? ";
		cin >> sure;
		clsAddNewUserScreen::CheckIsValidAnswer(sure);

		if (tolower(sure) == 'y')
		{
			_ReadUserInfo(User);
			
			clsUser::enSaveResult SaveResult = User.Save();

			clsAddNewUserScreen::PrintSaveResult(SaveResult, "updated");
		}
		else
		{
			cout << "\n\nUser don't updated.\n";
		}

		_PrintUser(User);

	}

public:

	static void PrintUpdateScreen()
	{
		system("cls");

		_DrawScreenHeader("Update User Screen");

		_UpdateUser();
	}






};

