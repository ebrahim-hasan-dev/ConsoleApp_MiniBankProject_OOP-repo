#pragma once



#include "clsDeleteClientScreen.h";
#include "D:\Visual Studio 2022 Projects\ConsoleApp_MiniBankProject_OOP\UILayer_BankProject\UIUsers_BankProject/clsAddNewUserScreen.h";



class clsUpdataClientScreen : protected clsScreen
{
private:

	static void _ReadClient(clsBanckClient& Client)
	{
		cout << "\n\nUpdate Client Info:\n";
		cout << "---------------------\n";

		Client.FirstName = clsInput<string>::Readstring("\nEnter First Name      : ");
		Client.LastName = clsInput<string>::Readstring("Enter last Name       : ");
		Client.Email = clsInput<string>::Readstring("Enter Email           : ");
		Client.Phone = clsInput<string>::Readstring("Enter Phone           : ");
		Client.PinCode = clsInput<string>::Readstring("Enter Pin Code        : ");
		Client.AccountBalance = clsInput<double>::ReadPositiveNumber("Enter Account Balance : ");
	}

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

	static void _UpdataClient()
	{
		string AccountNumber = clsInput<string>::Readstring("\nPlease Enter Account Number : ");

		clsBanckClient Client = clsBanckClient::GetAddNewClientObject(AccountNumber);

		clsDeleteClientScreen::MakeSureClientIsExist(Client);

		_PrintClientCard(Client);

		char sure = 'y';
		cout << "\n\nAre you sure you want to update this client (y, n) ? ";
		cin >> sure;
		clsAddNewUserScreen::CheckIsValidAnswer(sure);

		if (tolower(sure) == 'y')
		{
			_ReadClient(Client);

			clsBanckClient::enSaveResult SaveResult = Client.Save();

			clsAddNewClientScreen::PrintSaveResult(SaveResult, "updated");

		}
		else
		{
			cout << "\n\nClient don't updated.";
		}

		_PrintClientCard(Client);

	}

public:

	static void PrintUpdataScreen()
	{
		system("cls");

		_DrawScreenHeader("Updata Client Screen");
		
		_UpdataClient();
	}
	

};

