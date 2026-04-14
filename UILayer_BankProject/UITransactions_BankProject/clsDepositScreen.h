#pragma once


#include "../UIClients_BankProject\clsDeleteClientScreen.h";
#include "../UIUsers_BankProject\clsAddNewUserScreen.h";


class clsDepositScreen : protected clsScreen
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

	static void _DepositTransaction()
	{
			string AccountNumber = clsInput<string>::Readstring("\nPlease Enter Account Number : ");

			clsBanckClient Client = clsBanckClient::GetAddNewClientObject(AccountNumber);

			clsDeleteClientScreen::MakeSureClientIsExist(Client);

			_PrintClientCard(Client);

			double DepositAmount = clsInput<double>::ReadPositiveNumber("\n\nPlease enter deposit amount ? ");

			char sure = 'y';
			cout << "\n\nAre you sure you want peform this transaction (y, n) ? ";
			cin >> sure;
			clsAddNewUserScreen::CheckIsValidAnswer(sure);

			if (tolower(sure) == 'y')
			{
				Client.Deposit(DepositAmount);

				cout << "\n\nDone Successfully.\n";
				cout << "New Balance is : " << Client.AccountBalance;
			}
			else
			{
				cout << "\n\nNo transactions happened, Operation was cancelled.";
			}

	}

public:

	static void PrintDepositScreen()
	{
		system("cls");

		_DrawScreenHeader("Deposit Screen");
	
		_DepositTransaction();
	}

	
};

