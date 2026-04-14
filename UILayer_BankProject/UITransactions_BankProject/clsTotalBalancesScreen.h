#pragma once


#include "../UIAllMenues_BankProject\clsScreen.h";
#include "../../LogicalLayer_BankProject\clsBanckClient.h";
#include "../../MyLibrary\clsUtil.h";



class clsTotalBalancesScreen : protected clsScreen
{
private:

	static void _PrintHeaderTapleOfBalances()
	{
		cout << "--------------------------------------------------------------------------------------\n\n";
		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(20) << "Balance";
		cout << "\n\n--------------------------------------------------------------------------------------\n\n";
	}

	static void _PrintClientBalanceinList(clsBanckClient& ClientData)
	{
		cout << "| " << left << setw(15) << ClientData.GetAccountNumber();
		cout << "| " << left << setw(20) << ClientData.GetFullName();
		cout << "| " << left << setw(20) << ClientData.AccountBalance;
	}

public:

	static void TotalBalancesScreen()
	{
		system("cls");

		vector <clsBanckClient> vClients = clsBanckClient::GetAllClients();

		string Title = "Balances List Screen";
		string SubTitle = "(" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		if (vClients.size() == 0)
		{
			cout << "\n\n\n\n\t\t\t\tNo Clients Available In The System!\n\n";
		}
		else
		{
			_PrintHeaderTapleOfBalances();

			for (clsBanckClient& Client : vClients)
			{
				_PrintClientBalanceinList(Client);
				cout << endl;
			}
			cout << "\n\n--------------------------------------------------------------------------------------\n\n";

			double BalancesSum = clsBanckClient::GetTotalBalances();

			cout << "\t\t\t\tTotal Balances = " << BalancesSum << "\n\n";

			cout << "\t\t\t    (" << clsUtil<string>::ConvertNumberToText(BalancesSum) << ")\n\n";
		}

	}





};

