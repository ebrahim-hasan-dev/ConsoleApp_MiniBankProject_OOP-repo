#pragma once


#include <string>
#include "../UIAllMenues_BankProject\clsScreen.h";
#include "../../LogicalLayer_BankProject\clsUser.h";
#include "../../MyLibrary\clsInput.h";
#include "../../MyLibrary\clsValidate.h";


class clsAddNewUserScreen : clsScreen
{
private:

	static void _ReadUserInfo(clsUser& User)
	{
		User.UserName = clsInput<string>::Readstring("\n\nEnter UserName        : ");
		
		MakeSureUserNameNotExist(User);

		User.FirstName = clsInput<string>::Readstring("Enter First Name      : ");
		User.LastName  = clsInput<string>::Readstring("Enter last Name       : ");
		User.Email     = clsInput<string>::Readstring("Enter Email           : ");
		
		User.Phone = clsInput<string>::Readstring("Enter Phone           : ");

		while (!clsValidate<string>::ItIsPhoneNumber(User.Phone))
		{
			User.Phone = clsInput<string>::Readstring("InValide Phone, Enter Valide One : ");
		}

		User.PassWord = clsInput<string>::Readstring("Enter PassWord        : ");

		ReadPermissions(User);

	}

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

	static void _AddNewUser()
	{
		clsUser User;

		char AddAgaine = 'y';

		while (tolower(AddAgaine) == 'y')
		{
			_ReadUserInfo(User);

			User.ModeAdd();

			clsUser::enSaveResult SaveResult = User.Save();

			PrintSaveResult(SaveResult, "Added");

			_PrintUser(User);

			cout << "\n\nDo you want to add more Users (y, n) ?  ";
			cin >> AddAgaine;
			CheckIsValidAnswer(AddAgaine);
		}
	}

public:

	static void MakeSureUserNameNotExist(clsUser& User)
	{
		while (clsUser::IsUserExist(User.UserName))
		{
			cout << "\n\nUser with UserName [" << User.UserName << "] already exist,";
			User.UserName = clsInput<string>::Readstring("\n\nEnter another UserName : ");
			cout << "\n";
		}
	}

	static void ReadPermissions(clsUser& User)
	{
		char Answer = 'n';

		cout << "\nEnter Permissions:\n\n";
		cout << "Do you want to give full access (y/ n) ? ";
		cin >> Answer;
		CheckIsValidAnswer(Answer);
		if (tolower(Answer) == 'y')
		{
			User.GivePermissiontoDoEveryThing();
			return;
		}
		else
		{
			User.CancelAllPermissionts();
		}


		cout << "\n\nDo you want to give access to:\n\n";


		cout << "Show Client List (y, n) ? ";
		cin >> Answer;
		CheckIsValidAnswer(Answer);
		if (tolower(Answer) == 'y')
		{
			User.GivePermissiontoShowClientsList();
		}


		cout << "Add New Client (y, n) ? ";
		cin >> Answer;
		CheckIsValidAnswer(Answer);
		if (tolower(Answer) == 'y')
		{
			User.GivePermissiontoAddClient();
		}
		

		cout << "Delete Client (y, n) ? ";
		cin >> Answer;
		CheckIsValidAnswer(Answer);
		if (tolower(Answer) == 'y')
		{
			User.GivePermissiontoDeleteClient();
		}
		

		cout << "Update Client (y, n) ? ";
		cin >> Answer;
		CheckIsValidAnswer(Answer);
		if (tolower(Answer) == 'y')
		{
			User.GivePermissiontoUdateClient();
		}
		

		cout << "Find Client (y, n) ? ";
		cin >> Answer;
		CheckIsValidAnswer(Answer);
		if (tolower(Answer) == 'y')
		{
			User.GivePermissiontoFindClient();
		}


		cout << "Transactions (y, n) ? ";
		cin >> Answer;
		CheckIsValidAnswer(Answer);
		if (tolower(Answer) == 'y')
		{
			User.GivePermissiontoTransactions();
		}
		

		cout << "Manage Users (y, n) ? ";
		cin >> Answer;
		CheckIsValidAnswer(Answer);
		if (tolower(Answer) == 'y')
		{
			User.GivePermissiontoManageUsers();
		}

		cout << "Logins Register (y, n) ? ";
		cin >> Answer;
		CheckIsValidAnswer(Answer);
		if (tolower(Answer) == 'y')
		{
			User.GivePermissiontoLoginsRegister();
		}

		cout << "Logins And LogOuts Register (y, n) ? ";
		cin >> Answer;
		CheckIsValidAnswer(Answer);
		if (tolower(Answer) == 'y')
		{
			User.GivePermissiontoLoginsAndLogOutsRegister();
		}

		cout << "Transfers History (y, n) ? ";
		cin >> Answer;
		CheckIsValidAnswer(Answer);
		if (tolower(Answer) == 'y')
		{
			User.GivePermissiontoTransfersHistory();
		}
		
		cout << "Currency Exchange (y, n) ? ";
		cin >> Answer;
		CheckIsValidAnswer(Answer);
		if (tolower(Answer) == 'y')
		{
			User.GivePermissiontoCurrencyExchange();
		}


	}

	static void CheckIsValidAnswer(char& Answer)
	{

		while (tolower(Answer) != 'y' && tolower(Answer) != 'n')
		{
			cout << "\nInvalid Answer!\n";
			cout << "\nPlease Answer (y, n) ? ";
			cin >> Answer;
		}
	}

	static void PrintSaveResult(clsUser::enSaveResult SaveResult, string MassegeWhatDo)
	{
		switch (SaveResult)
		{
		case clsUser::enSaveResult::Succeeded:
		{
			cout << "\n\nUser " << MassegeWhatDo << " Successfully :-)\n";
			break;
		}
		case clsUser::enSaveResult::FailedEmpty:
		{
			cout << "\n\nUser don't Saved because it's empty.\n";
			break;
		}

		}
	}

	static void PrintAddNewUserScreen()
	{
		system("cls");

		_DrawScreenHeader("Add New User Screen");

		_AddNewUser();
	}



};

