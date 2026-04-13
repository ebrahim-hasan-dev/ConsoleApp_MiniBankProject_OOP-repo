#pragma once

#include "clsScreen.h";
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/MyLibrary/clsInput.h";
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/LogicalLayer_BankProject/clsBanckClient.h";
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/UILayer_BankProject/UIUsers_BankProject/clsAddNewUserScreen.h";
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/MyLibrary/clsValidate.h";


class clsAddNewClientScreen : protected clsScreen
{
private:

	static void _ReadClient(clsBanckClient& Client)
	{
		Client.FirstName = clsInput<string>::Readstring("Enter First Name      : ");
		Client.LastName = clsInput<string>::Readstring("Enter last Name       : ");
		Client.Email = clsInput<string>::Readstring("Enter Email           : ");
		
		Client.Phone = clsInput<string>::Readstring("Enter Phone           : ");

		while (!clsValidate<string>::ItIsPhoneNumber(Client.Phone))
		{
			Client.Phone = clsInput<string>::Readstring("InValide Phone, Enter Valide One : ");
		}
		
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

	static void _AddNewClient()
	{
		char AddAgaine = 'y';

		string AccountNumber = "";

		while (tolower(AddAgaine) == 'y')
		{
			AccountNumber = clsInput<string>::Readstring("\n\nPlease Enter Account Number  : ");

			MakeSureOfAccountNumberIsNotExist(AccountNumber);

			clsBanckClient Client = clsBanckClient::GetAddNewClientObject(AccountNumber);

			_ReadClient(Client);

			clsBanckClient::enSaveResult SaveResult = Client.Save();

			PrintSaveResult(SaveResult, "Added");

			_PrintClientCard(Client);

			cout << "\n\nDo you want to add more clients (y, n) ?  ";
			cin >> AddAgaine;
			clsAddNewUserScreen::CheckIsValidAnswer(AddAgaine);

		}

	}

public:

	static void MakeSureOfAccountNumberIsNotExist(string& AccountNumber)
	{
		while (clsBanckClient::IsClientExist(AccountNumber))
		{
			cout << "\n\nClient with [" << AccountNumber << "] already exists,\n\n";
			AccountNumber = clsInput<string>::Readstring("Enter another Account Number : ");
		}
		
	}

	static void PrintSaveResult(clsBanckClient::enSaveResult SaveResult, string MassegeWhatDo)
	{
		switch (SaveResult)
		{
		case clsBanckClient::enSaveResult::Succeeded:
		{
			cout << "\n\nClient " << MassegeWhatDo << " Successfully :-)\n";
			break;
		}
		case clsBanckClient::enSaveResult::FailedEmpty:
		{
			cout << "\n\nClient don't Saved because it's empty.\n";
			break;
		}

		}
	}

	static void AddNewClientScreen()
	{
		system("cls");

		_DrawScreenHeader("Add New Client Screen");

		_AddNewClient();

	}
	

};

