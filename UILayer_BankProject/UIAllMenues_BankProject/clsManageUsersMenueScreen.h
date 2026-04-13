#pragma once


#include <iostream>
#include "clsScreen.h";
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/MyLibrary/clsInput.h"
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/UILayer_BankProject/UIUsers_BankProject/clsUsersListScreen.h";
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/UILayer_BankProject/UIUsers_BankProject/clsAddNewUserScreen.h";
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/UILayer_BankProject/UIUsers_BankProject/clsDeleteUserScreen.h";
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/UILayer_BankProject/UIUsers_BankProject/clsUpdateUserScreen.h";
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/UILayer_BankProject/UIUsers_BankProject/clsFindUserScreen.h";
using namespace std;


class clsManageUsersMenueScreen : clsScreen
{
private:

	enum enManageUsersOption { enShowUsersList = 1, enAddUser, enDeleteUser, enUpdataUser, enFindUser, enMainMenue };

	static void _PressAnyKeyToBackManageUsersMenue(string Massege)
	{
		cout << Massege;
		system("pause > 0");
	}

	static void _GoBackToManageUsersMenue()
	{
		_PressAnyKeyToBackManageUsersMenue("\n\nPress any key to go back to Manage Users Menue...");

		PrintManageUsersMenue();
	}

	static void _ShowUsersList()
	{
		clsUsersListScreen::ManageUsersListScreen();
	}

	static void _AddNewUserScreen()
	{
		clsAddNewUserScreen::PrintAddNewUserScreen();
	}

	static void _DeleteUserScreen()
	{
		clsDeleteUserScreen::PrintDeleteScreen();
	}

	static void _UpdataUserScreen()
	{
		clsUpdateUserScreen::PrintUpdateScreen();
	}

	static void _FindUserScreen()
	{
		clsFindUserScreen::PrintFindUserScreen();
	}

	static short _ReadChooseFromManageUsersMenueOpetion(string MassageWhatToDo)
	{
		cout << "\n" << setw(37) << left << "";
		short choice = clsInput<short>::ReadNumberBetween(1, 6, MassageWhatToDo);

		return choice;
	}

	static void _PerformManageUsersMenueOption()
	{
		short choice = 0;

		choice = (enManageUsersOption) _ReadChooseFromManageUsersMenueOpetion("Choose what do you want to do [1 to 6] ?  ");

		switch (choice)
		{
		case enManageUsersOption::enShowUsersList:
		{
			_ShowUsersList();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersOption::enAddUser:
		{
			_AddNewUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersOption::enDeleteUser:
		{
			_DeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersOption::enUpdataUser:
		{
			_UpdataUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersOption::enFindUser:
		{
			_FindUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersOption::enMainMenue:
		{
			return;
		}

		}
	}


public:

	static void PrintManageUsersMenue()
	{
		system("cls");

		_DrawScreenHeader("Manage Users Menue Screen");

		cout << setw(37) << left << "" << "-------------------------\n\n";
		cout << setw(37) << left << "" << "[1] List Users.\n";
		cout << setw(37) << left << "" << "[2] Add New User.\n";
		cout << setw(37) << left << "" << "[3] Delete User.\n";
		cout << setw(37) << left << "" << "[4] Updata User.\n";
		cout << setw(37) << left << "" << "[5] Find User.\n";
		cout << setw(37) << left << "" << "[6] Main Menue.\n\n";
		cout << setw(37) << left << "" << "-------------------------\n\n";

		_PerformManageUsersMenueOption();

	}



};

