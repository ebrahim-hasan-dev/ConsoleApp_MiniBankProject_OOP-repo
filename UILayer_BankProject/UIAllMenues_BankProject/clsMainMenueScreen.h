#pragma once


#include "../UIClients_BankProject/clsClientsListScreen.h";
#include "../UIClients_BankProject/clsUpdataClientScreen.h";
#include "../UIClients_BankProject/clsFindClientScreen.h";
#include "../UITransactions_BankProject/clsTransactionsScreen.h";
#include "clsManageUsersMenueScreen.h";
#include "../../LogicalLayer_BankProject/CurrentUser.h";
#include "../../LogicalLayer_BankProject/ClsUser.h";
#include "../UIRegisters_BankProject/clsLoginsRegisterScreen.h";
#include "../UIRegisters_BankProject/clsLoginsAndLogOutsRegisterScreen.h";
#include "../UICurrencies_BankProject/clsCurrencyExchangeMenueScreen.h"



class clsMainMenueScreen : protected clsScreen
{
private:

	enum enMainMenue {
		ShowClientsList = 1, AddClient, DeleteClient, UpdataClient, FindClient, Transactions,
		ManageUsers, LoginMoveMentRecording, LoginAndLogOutMoveMentRecording, enCurrencyExchange, LogOut
	};

	static void _PressAnyKeyToBackMainMenue(string Massege)
	{
		cout << Massege;
		system("pause > 0");
	}

	static void _GoBackToMainMenue()
	{
		_PressAnyKeyToBackMainMenue("\n\nPress any key to go back to Main Menue...");

		PrintMainMenueScreen();
	}

	static void _ClientsListScreen()
	{
		clsClientsListScreen::PrintClientsList();
	}

	static void _UpdataClientScreen()
	{
		clsUpdataClientScreen::PrintUpdataScreen();
	}

	static void _AddNewClientScreen()
	{
		clsAddNewClientScreen::AddNewClientScreen();
	}

	static void _DeleteClientScreen()
	{
		clsDeleteClientScreen::PrintDeleteScreen();
	}
	
	static void _FindClientScreen()
	{
		clsFindClientScreen::FindClientScreen();
	}
	
	static void _TransactionsScreen()
	{
		clsTransactionsScreen::PrintTransactionsMenue();
	}

	static void _ManageUsersMenue()
	{
		clsManageUsersMenueScreen::PrintManageUsersMenue();
	}

	static void _LoginsRegister()
	{
		clsLoginsRegisterScreen::PrintLoginsRegisterList();
	}

	static void _LoginsAndLogOutsRegister()
	{
		clsLoginsAndLogOutsRegisterScreen::PrintLoginsAndLogOutsRegisterList();
	}

	static void _CurrencyExchange()
	{
		clsCurrencyExchangeMenueScreen::PrintCurrencyExchangeMenue();
	}

	static short _ReadChooseFromMainMenueOption(string MassageWhatToDo)
	{
		cout << "\n" << setw(37) << left << "";
		short choice = clsInput<short>::ReadNumberBetween(1, 11, MassageWhatToDo);

		return choice;
	}

	static void PrintAccessDeniedMassage()
	{
		system("cls");

		cout << "\n\n---------------------------------------------\n\n";
		cout << "Access Denied,\n";
		cout << "You don't have permission to do this,\n";
		cout << "Please Contact Your Admin.";
		cout << "\n\n---------------------------------------------";

		_GoBackToMainMenue();
	}

	static void _PerformMainMenueOption()
	{

		short choice = 0;

		choice = (enMainMenue) _ReadChooseFromMainMenueOption("Choose what do you want to do [1 to 11] ?  ");
			
			switch(choice)
			{
			case enMainMenue::ShowClientsList:
			{
				if (CurrentUser.CheckAccessPermission(clsUser::enMainMenuePermissions::pClientsList))
				{
					_ClientsListScreen();
					_GoBackToMainMenue();
				}
				else
				{
					PrintAccessDeniedMassage();
				}
				break;
			}
			case enMainMenue::AddClient:
			{
				if (CurrentUser.CheckAccessPermission(clsUser::enMainMenuePermissions::pAddClient))
				{
					_AddNewClientScreen();
					_GoBackToMainMenue();
				}
				else
				{
					PrintAccessDeniedMassage();
				}
				break;
			}
			case enMainMenue::DeleteClient:
			{
				if (CurrentUser.CheckAccessPermission(clsUser::enMainMenuePermissions::pDeleteClient))
				{
					_DeleteClientScreen();
					_GoBackToMainMenue();
				}
				else
				{
					PrintAccessDeniedMassage();
				}
				break;
			}
			case enMainMenue::UpdataClient:
			{
				if (CurrentUser.CheckAccessPermission(clsUser::enMainMenuePermissions::pUpdateClient))
				{
					_UpdataClientScreen();
					_GoBackToMainMenue();
				}
				else
				{
					PrintAccessDeniedMassage();
				}
				break;
			}
			case enMainMenue::FindClient:
			{
				if (CurrentUser.CheckAccessPermission(clsUser::enMainMenuePermissions::pFindClient))
				{
					_FindClientScreen();
					_GoBackToMainMenue();
				}
				else
				{
					PrintAccessDeniedMassage();
				}
				break;
			}
			case enMainMenue::Transactions:
			{
				if (CurrentUser.CheckAccessPermission(clsUser::enMainMenuePermissions::pTransactions))
				{
					_TransactionsScreen();
					PrintMainMenueScreen();
				}
				else
				{
					PrintAccessDeniedMassage();
				}
				break;
			}
			case enMainMenue::ManageUsers:
			{
				if (CurrentUser.CheckAccessPermission(clsUser::enMainMenuePermissions::pManageUsers))
				{
					_ManageUsersMenue();
					PrintMainMenueScreen();
				}
				else
				{
					PrintAccessDeniedMassage();
				}
				break;
			}
			case enMainMenue::LoginMoveMentRecording:
			{
				if (CurrentUser.CheckAccessPermission(clsUser::enMainMenuePermissions::pLoginsRegister))
				{
					_LoginsRegister();
					_GoBackToMainMenue();
				}
				else
				{
					PrintAccessDeniedMassage();
				}
				break;
			}
			case enMainMenue::LoginAndLogOutMoveMentRecording:
			{
				if (CurrentUser.CheckAccessPermission(clsUser::enMainMenuePermissions::pLoginsAndLogOutsRegister))
				{
					_LoginsAndLogOutsRegister();
					_GoBackToMainMenue();
				}
				else
				{
					PrintAccessDeniedMassage();
				}
				break;
			}
			case enMainMenue::enCurrencyExchange:
			{
				if (CurrentUser.CheckAccessPermission(clsUser::enMainMenuePermissions::pCurrencyExchange))
				{
					_CurrencyExchange();
					PrintMainMenueScreen();
				}
				else
				{
					PrintAccessDeniedMassage();
				}
				break;
			}
			case enMainMenue::LogOut:
			{
				return;
			}


			}
		
	}


public:


	static void PrintMainMenueScreen()
	{
		system("cls");

		_DrawScreenHeader("Main Menue Screen");

		cout << setw(37) << left << "" << "-----------------------------------------------\n\n";
		cout << setw(37) << left << "" << "[1] Show Clients List.\n";
		cout << setw(37) << left << "" << "[2] Add New Client.\n";
		cout << setw(37) << left << "" << "[3] Delete Client.\n";
		cout << setw(37) << left << "" << "[4] Updata Client.\n";
		cout << setw(37) << left << "" << "[5] Find Client.\n";
		cout << setw(37) << left << "" << "[6] Transactions.\n";
		cout << setw(37) << left << "" << "[7] Manage Users.\n";
		cout << setw(37) << left << "" << "[8] Logins Register.\n";
		cout << setw(37) << left << "" << "[9] Logins And LogOuts Register.\n";
		cout << setw(36) << left << "" << "[10] Currency Exchange.\n";
		cout << setw(36) << left << "" << "[11] LogOut.\n\n";
		cout << setw(37) << left << "" << "-----------------------------------------------\n\n";

		_PerformMainMenueOption();
	}


};

