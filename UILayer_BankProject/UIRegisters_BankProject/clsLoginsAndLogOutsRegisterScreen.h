#pragma once

#include "D:\Visual Studio 2022 Projects\ConsoleApp_MiniBankProject_OOP\UILayer_BankProject\UIAllMenues_BankProject/clsScreen.h";
#include "D:\Visual Studio 2022 Projects\ConsoleApp_MiniBankProject_OOP\LogicalLayer_BankProject/clsUser.h";


class clsLoginsAndLogOutsRegisterScreen : protected clsScreen
{
private:

	static void _PrintHeaderTaple()
	{
		cout << "\n\n------------------------------------------------------------------------------------------------------\n\n";
		cout << "| " << left << setw(25) << "Login: Date / Time ";
		cout << "| " << left << setw(25) << "LogOut: Date / Time ";
		cout << "| " << left << setw(15) << "UserName";
		cout << "| " << left << setw(15) << "PassWord";
		cout << "| " << left << setw(10) << "PerMissions";
		cout << "\n\n------------------------------------------------------------------------------------------------------\n\n";
	}

	static void _PrintUserLoginAndLogOutRegister(clsUser::stLoginsAndLogOutsRegister & User)
	{
		cout << "| " << left << setw(25) << User.LoginDateAndTime;
		cout << "| " << left << setw(25) << User.LogOutDateAndTime;
		cout << "| " << left << setw(15) << User.UserName;
		cout << "| " << left << setw(15) << User.PassWord;
		cout << "| " << left << setw(10) << User.Permissions;
	}

public:

	static void PrintLoginsAndLogOutsRegisterList()
	{
		system("cls");

		vector <clsUser::stLoginsAndLogOutsRegister> vUsers = clsUser::GetAllLoginsAndLogOutsRegister();

		string Title = "Login And LogOut Register List Screen";
		string SubTitle = "(" + to_string(vUsers.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		if (vUsers.size() == 0)
		{
			cout << "\n\n\n\n\t\t\tNo Logins And LogOuts Resiter Available In The System!\n\n";
		}
		else
		{
			_PrintHeaderTaple();

			for (clsUser::stLoginsAndLogOutsRegister& User : vUsers)
			{
				_PrintUserLoginAndLogOutRegister(User);
				cout << endl;
			}
			cout << "\n\n------------------------------------------------------------------------------------------------------\n\n";

		}

	}

};

