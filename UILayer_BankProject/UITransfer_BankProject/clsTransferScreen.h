#pragma once

#include "D:\Visual Studio 2022 Projects\ConsoleApp_MiniBankProject_OOP\UILayer_BankProject\UIAllMenues_BankProject\clsScreen.h"
#include "D:\Visual Studio 2022 Projects\ConsoleApp_MiniBankProject_OOP\LogicalLayer_BankProject\clsBanckClient.h"
#include "D:\Visual Studio 2022 Projects\ConsoleApp_MiniBankProject_OOP\MyLibrary\clsInput.h"
#include "D:\Visual Studio 2022 Projects\ConsoleApp_MiniBankProject_OOP\UILayer_BankProject\UIUsers_BankProject\clsAddNewUserScreen.h"
#include "D:\Visual Studio 2022 Projects\ConsoleApp_MiniBankProject_OOP\UILayer_BankProject\UIClients_BankProject\clsDeleteClientScreen.h"


class clsTransferScreen : protected clsScreen 
{
private:

	static void _PrintClientCard(clsBanckClient& Client)
	{

		cout << "\n\nClient Card:\n";
		cout << "----------------------------------------------\n\n";
		cout << "Full Name                 : " << Client.GetFullName() << endl;
		cout << "AccountNumber             : " << Client.GetAccountNumber() << endl;
		cout << "AccountBalance            : " << Client.AccountBalance << endl << endl;
		cout << "----------------------------------------------\n\n";

	}

	static void _TheTransfer()
	{
		string SourceClientAccountNumber = clsInput<string>::Readstring("\n\nPlease Enter Account Number to Transfer From : ");

		clsBanckClient SourceClient = clsBanckClient::GetAddNewClientObject(SourceClientAccountNumber);

		clsDeleteClientScreen::MakeSureClientIsExist(SourceClient);

		_PrintClientCard(SourceClient);


		string DestinationClientAccountNumber = clsInput<string>::Readstring("\n\nPlease Enter Account Number to Transfer To : ");

		clsBanckClient DestinationClient = clsBanckClient::GetAddNewClientObject(DestinationClientAccountNumber);

		clsDeleteClientScreen::MakeSureClientIsExist(DestinationClient);


		if (DestinationClient.GetAccountNumber() == SourceClient.GetAccountNumber())
		{
			cout << "\n\nThe Transaction Failed.\n\n";
			cout << "This Account Number Which Will be Transfer From!\n\n";
			return;
		}


		_PrintClientCard(DestinationClient);


		double TransferAmount = clsInput<double>::ReadPositiveNumber("\nEnter Transfer Amount : ");


		char sure = 'y';
		cout << "\n\nAre you sure you want peform this transaction (y, n) ? ";
		cin >> sure;
		clsAddNewUserScreen::CheckIsValidAnswer(sure);

		if (tolower(sure) == 'y')
		{
			if (SourceClient.Transfer(TransferAmount, DestinationClient))
			{
				cout << "\nTransfer done Successfully.\n";
			}
			else
			{
				cout << "\n\nCan not Transfer, Insuffecient Balance!";

				cout << "\n\nTransfer Amount is : " << TransferAmount;

				cout << "\nAccount Number to Transfer From is : " << SourceClient.AccountBalance;
			}
		}
		else
		{
			cout << "\n\nNo transactions happened, Operation was cancelled.\n";
		}

		_PrintClientCard(SourceClient);
		_PrintClientCard(DestinationClient);

	}

public:

	static void PrintTransferScreen()
	{
		system("cls");

		_DrawScreenHeader("Transfers Screen");

		_TheTransfer();
	}


};

