#pragma once


#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"



class clsCurrencyExchangeMenueScreen : protected clsScreen
{
private:

	enum enCurrencyExchange { enListCurrencies = 1, enFindCurrency, enUpdateRate, enCurrencyCalculator, enMainMenue };

	static void _PressAnyKeyToBackCurrrencyExchangeMenue(string Massege)
	{
		cout << Massege;
		system("pause > 0");
	}

	static void _GoBackToCurrrencyExchangeMenue()
	{
		_PressAnyKeyToBackCurrrencyExchangeMenue("\n\nPress any key to go back to Currrency Exchange Menue...");

		PrintCurrencyExchangeMenue();
	}

	static void _ListCurrenciesScreen()
	{
		clsListCurrenciesScreen::PrintCurrenciesList();
	}

	static void _FindCurrencyScreen()
	{
		clsFindCurrencyScreen::FindCurrencyScreen();
	}

	static void _UpdateRateScreen()
	{
		clsUpdateRateScreen::PrintUpdataRateScreen();
	}

	static void _CurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::PrintCurrencyCalculatorScreen();
	}

	static short _ReadChooseFromCurrrencyExchangeMenueOpetion(string MassageWhatToDo)
	{
		cout << "\n" << setw(37) << left << "";
		short choice = clsInput<short>::ReadNumberBetween(1, 5, MassageWhatToDo);

		return choice;
	}



	static void _PerformCurrencyExchangeMenueOption()
	{
		short choice = (enCurrencyExchange) _ReadChooseFromCurrrencyExchangeMenueOpetion("Choose what do you want to do [1 to 5] ?  ");

		switch (choice)
		{
		case enCurrencyExchange::enListCurrencies:
		{
			_ListCurrenciesScreen();
			_GoBackToCurrrencyExchangeMenue();
			break;
		}
		case enCurrencyExchange::enFindCurrency:
		{
			_FindCurrencyScreen();
			_GoBackToCurrrencyExchangeMenue();
			break;
		}
		case enCurrencyExchange::enUpdateRate:
		{
			_UpdateRateScreen();
			_GoBackToCurrrencyExchangeMenue();
			break;
		}
		case enCurrencyExchange::enCurrencyCalculator:
		{
			_CurrencyCalculatorScreen();
			_GoBackToCurrrencyExchangeMenue();
			break;
		}
		case enCurrencyExchange::enMainMenue:
		{
			return;
		}

		}

	}


public:

	static void PrintCurrencyExchangeMenue()
	{
		system("cls");

		_DrawScreenHeader("Currency Exchange Menue Screen");

		cout << setw(37) << left << "" << "---------------------\n\n";
		cout << setw(37) << left << "" << "[1] List Currencies.\n";
		cout << setw(37) << left << "" << "[2] Find Currency.\n";
		cout << setw(37) << left << "" << "[3] Update Rate.\n";
		cout << setw(37) << left << "" << "[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "[5] Main Menue.\n\n";
		cout << setw(37) << left << "" << "---------------------\n\n";

		_PerformCurrencyExchangeMenueOption();

	}

};

