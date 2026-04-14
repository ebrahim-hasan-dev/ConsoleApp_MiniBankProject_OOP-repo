#pragma once

#include "clsDepositScreen.h";
#include "clsWithdrawScreen.h";
#include "clsTotalBalancesScreen.h";
#include "../UITransfer_BankProject\clsTransferScreen.h"
#include "../UITransfer_BankProject\clsTransferHistoryScreen.h"


class clsTransactionsScreen : protected clsScreen
{
private:

	enum enTransactions { Deposit = 1, Withdraw, TotalBalances, Transfer, TransferHistory, MainMenue };

	static void _PressAnyKeyToBackTransactionsMenue(string Massege)
	{
		cout << Massege;
		system("pause > 0");
	}

	static void _GoBackToTransactionsMenue()
	{
		_PressAnyKeyToBackTransactionsMenue("\n\nPress any key to go back to Transactions Menue...");

		PrintTransactionsMenue();
	}

	static void _DepositScreen()
	{
		clsDepositScreen::PrintDepositScreen();
	}

	static void _WithdrawScreen()
	{
		clsWithdrawScreen::WithdrawScreen();
	}

	static void _TotalBalancesScreen()
	{
		clsTotalBalancesScreen::TotalBalancesScreen();
	}

	static void _TransferScreen()
	{
		clsTransferScreen::PrintTransferScreen();
	}

	static void _TransferHistoryScreen()
	{
		clsTransferHistoryScreen::PrintTransfersHistoryList();
	}

	static short _ReadChooseFromTransactionsMenueOpetion(string MassageWhatToDo)
	{
		cout << "\n" << setw(37) << left << "";
		short choice = clsInput<short>::ReadNumberBetween(1, 6, MassageWhatToDo);

		return choice;
	}

	static void _PerformTransactionsMenueOption() 
	{
		short choice = 0;
	
		choice = (enTransactions) _ReadChooseFromTransactionsMenueOpetion("Choose what do you want to do [1 to 6] ?  ");

		switch (choice)
		{
		case enTransactions::Deposit:
		{
			_DepositScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactions::Withdraw:
		{
			_WithdrawScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactions::TotalBalances:
		{
			_TotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactions::Transfer:
		{
			_TransferScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactions::TransferHistory:
		{
			_TransferHistoryScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactions::MainMenue:
		{
			return;
		}

		}

	}


public:

	static void PrintTransactionsMenue()
	{
		system("cls");

		_DrawScreenHeader("Transactions Menue Screen");

		cout << setw(37) << left << "" << "---------------------\n\n";
		cout << setw(37) << left << "" << "[1] Deposit.\n";
		cout << setw(37) << left << "" << "[2] Withdraw.\n";
		cout << setw(37) << left << "" << "[3] Total Balances.\n";
		cout << setw(37) << left << "" << "[4] Transfer.\n";
		cout << setw(37) << left << "" << "[5] Transfers History.\n";
		cout << setw(37) << left << "" << "[6] Main Menue.\n\n";
		cout << setw(37) << left << "" << "---------------------\n\n";

		_PerformTransactionsMenueOption();
	}




};

