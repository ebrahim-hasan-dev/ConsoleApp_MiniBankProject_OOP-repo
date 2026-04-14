#pragma once


#include "../UIAllMenues_BankProject/clsScreen.h";
#include "../../LogicalLayer_BankProject/clsBanckClient.h";




class clsClientsListScreen : protected clsScreen
{
private:

	static void _PrintHeaderTaple()
	{
		cout << "\n\n-----------------------------------------------------------------------------------------------------------------\n\n";
		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(25) << "Client Name";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(15) << "Phone";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(20) << "Account Balance";
		cout << "\n\n-----------------------------------------------------------------------------------------------------------------\n\n";
	}

	static void _PrintClientinList(clsBanckClient& Client)
	{
		cout << "| " << left << setw(15) << Client.GetAccountNumber();
		cout << "| " << left << setw(25) << Client.GetFullName();
		cout << "| " << left << setw(20) << Client.Email;
		cout << "| " << left << setw(15) << Client.Phone;
		cout << "| " << left << setw(10) << Client.PinCode;
		cout << "| " << left << setw(20) << Client.AccountBalance;
	}

public:

	static void PrintClientsList()
	{
		system("cls");

		vector <clsBanckClient> vClients = clsBanckClient::GetAllClients();

		string Title = "Clients List Screen";
		string SubTitle = "(" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		if (vClients.size() == 0)
		{
			cout << "\n\n\n\n\t\t\tNo Clients Available In The System!\n\n";
		}
		else
		{
			_PrintHeaderTaple();

			for (clsBanckClient& Client : vClients)
			{
				_PrintClientinList(Client);
				cout << endl;
			}
			cout << "\n\n-----------------------------------------------------------------------------------------------------------------\n\n";

		}

	}


};

