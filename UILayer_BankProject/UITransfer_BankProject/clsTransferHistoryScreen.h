#pragma once

#include "D:\Visual Studio 2022 Projects\ConsoleApp_MiniBankProject_OOP\UILayer_BankProject\UIAllMenues_BankProject\clsScreen.h"
#include "D:\Visual Studio 2022 Projects\ConsoleApp_MiniBankProject_OOP\LogicalLayer_BankProject\clsBanckClient.h"


class clsTransferHistoryScreen : protected clsScreen
{
private:

	static void _PrintHeaderTaple()
	{
		cout << "\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "| " << left << setw(25) << "Date / Time ";
		cout << "| " << left << setw(25) << "Source Account Number";
		cout << "| " << left << setw(28) << "Destination Account Number";
		cout << "| " << left << setw(17) << "Transfer Amount";
		cout << "| " << left << setw(25) << "Source Account Balance";
		cout << "| " << left << setw(30) << "Destination Account Balance";
		cout << "| " << left << setw(10) << "User";
		cout << "\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	}

	static void _PrintTransferRegister(clsBanckClient::stTransferHistoryRegister& TransferHistoryRegister)
	{
		cout << "| " << left << setw(25) << TransferHistoryRegister.DateAndTime;
		cout << "| " << left << setw(25) << TransferHistoryRegister.SourceAccountNumber;
		cout << "| " << left << setw(28) << TransferHistoryRegister.DestinationAccountNumber;
		cout << "| " << left << setw(17) << TransferHistoryRegister.TransferAmount;
		cout << "| " << left << setw(25) << TransferHistoryRegister.SourceAccountBalanceAfter;
		cout << "| " << left << setw(30) << TransferHistoryRegister.DestinationAccountBalanceAfter;
		cout << "| " << left << setw(10) << TransferHistoryRegister.UserName;
	}

public:

	static void PrintTransfersHistoryList()
	{
		system("cls");

		vector <clsBanckClient::stTransferHistoryRegister> vTransfers = clsBanckClient::GetAllTransfersHistoryAsStruct();

		string Title = "Transfers History List Screen";
		string SubTitle = "(" + to_string(vTransfers.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		if (vTransfers.size() == 0)
		{
			cout << "\n\n\n\n\t\t\tNo Transfers History Available In The System!\n\n";
		}
		else
		{
			_PrintHeaderTaple();

			for (clsBanckClient::stTransferHistoryRegister& Transfer : vTransfers)
			{
				_PrintTransferRegister(Transfer);
				cout << endl;
			}
			cout << "\n\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";

		}

	}

};

