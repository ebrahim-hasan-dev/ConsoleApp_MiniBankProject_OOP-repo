#pragma once


#include "clsAddNewClientScreen.h";
#include "D:\Visual Studio 2022 Projects\ConsoleApp_MiniBankProject_OOP\UILayer_BankProject\UIUsers_BankProject/clsAddNewUserScreen.h";

class clsDeleteClientScreen : protected clsScreen
{
private:

	static void _PrintClientCard(clsBanckClient Client)
	{

		cout << "\n\nClient Card:\n";
		cout << "----------------------------------------------\n\n";
		cout << "First Name                : " << Client.FirstName << endl;
		cout << "Last Name                 : " << Client.LastName << endl;
		cout << "Full Name                 : " << Client.GetFullName() << endl;
		cout << "Email                     : " << Client.Email << endl;
		cout << "Phone                     : " << Client.Phone << endl;
		cout << "AccountNumber             : " << Client.GetAccountNumber() << endl;
		cout << "PinCode                   : " << Client.PinCode << endl;
		cout << "AccountBalance            : " << Client.AccountBalance << endl << endl;
		cout << "----------------------------------------------\n\n";

	}

	static void _DeleteClient()
	{
		string AccountNumber = clsInput<string>::Readstring("\n\nPlease Enter Account Number  : ");

		clsBanckClient Client = clsBanckClient::GetAddNewClientObject(AccountNumber);

		MakeSureClientIsExist(Client);

		_PrintClientCard(Client);

		char sure = 'y';
		cout << "\n\nAre you sure you want to delete this client (y, n) ? ";
		cin >> sure;
		clsAddNewUserScreen::CheckIsValidAnswer(sure);

		if (tolower(sure) == 'y')
		{
			Client.Delete();

			cout << "\n\nClient deleted Successfully :-)\n";
		}
		else
		{
			cout << "\n\nClient don't deleted.\n";
		}

		_PrintClientCard(Client);

	}

public:

	static void MakeSureClientIsExist(clsBanckClient& Client)
	{
		while (!clsBanckClient::IsClientExist(Client))
		{
			cout << "\n\nClient with Account Number [" << Client.GetAccountNumber() << "] is not found,";

			string AccountNumber = clsInput<string>::Readstring("\n\nEnter another Account Number : ");

			Client = clsBanckClient::GetAddNewClientObject(AccountNumber);
		}
	}

	static void PrintDeleteScreen()
	{
		system("cls");

		_DrawScreenHeader("Delete Client Screen");

		_DeleteClient();
	}

};

