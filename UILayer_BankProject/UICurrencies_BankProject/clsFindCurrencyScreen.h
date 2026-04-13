#pragma once


#include "D:\Visual Studio 2022 Projects\ConsoleApp_MiniBankProject_OOP\UILayer_BankProject\UIAllMenues_BankProject/clsScreen.h";
#include "D:\Visual Studio 2022 Projects\ConsoleApp_MiniBankProject_OOP\LogicalLayer_BankProject/clsCurrency.h";
#include "D:\Visual Studio 2022 Projects\ConsoleApp_MiniBankProject_OOP\MyLibrary/clsInput.h";




class clsFindCurrencyScreen : protected clsScreen
{
private:


	static void _PrintCurrencyCard(clsCurrency& CurrencyObject)
	{
		cout << "\n\nCurrency Card:\n";
		cout << "-----------------------------------------\n\n";
		cout << "Currency Country : " << CurrencyObject.GetCurrencyCountry() << endl;
		cout << "Currency Code    : " << CurrencyObject.GetCurrencyCode() << endl;
		cout << "Currency Name    : " << CurrencyObject.GetCurrencyName() << endl;
		cout << "Rate / (1$)      : " << CurrencyObject.GetCurrencyRateTo_1_Dollar() << endl;
		cout << "-----------------------------------------\n\n";

	}

	static void _PrintHeaderTaple()
	{
		cout << "\n\n-----------------------------------------------------------------------------------------------------------------\n\n";
		cout << "| " << left << setw(30) << "Currency Country";
		cout << "| " << left << setw(20) << "Currency Code";
		cout << "| " << left << setw(40) << "Currency Name";
		cout << "| " << left << setw(15) << "Rate / (1$)";
		cout << "\n\n-----------------------------------------------------------------------------------------------------------------\n\n";
	}

	static void _PrintCurrencyinList(clsCurrency& CurrencyObject)
	{
		cout << "| " << left << setw(30) << CurrencyObject.GetCurrencyCountry();
		cout << "| " << left << setw(20) << CurrencyObject.GetCurrencyCode();
		cout << "| " << left << setw(40) << CurrencyObject.GetCurrencyName();
		cout << "| " << left << setw(15) << CurrencyObject.GetCurrencyRateTo_1_Dollar();
	}

public:

	static void PrintAllCountriesThatUseThisCurrency(clsCurrency& CurrencyObject)
	{
		vector <clsCurrency> vCountries = clsCurrency::GetAllCountriesThatUseThisCurrency(CurrencyObject.GetCurrencyCode());
		
		cout << "\n\nThese Are All The Countries That Use " << CurrencyObject.GetCurrencyName() << ":\n";

		_PrintHeaderTaple();

		for (clsCurrency& Currency : vCountries)
		{
			_PrintCurrencyinList(Currency);
			cout << endl;
		}
		cout << "\n\n-----------------------------------------------------------------------------------------------------------------\n\n";

	}


	static void FindCurrencyScreen()
	{
		system("cls");

		_DrawScreenHeader("Find Currency Screen");

		short Choice = clsInput<short>::ReadNumberBetween(1, 2, "\n\nFind By: [1] Code or [2] Country : ");

		clsCurrency CurrencyObject;

		if (Choice == 1)
		{
			string CurrencyCode = clsInput<string>::Readstring("\n\nPlease Enter Currency Code : ");

			CurrencyObject = clsCurrency::Find(CurrencyCode);

			if (!CurrencyObject.IsEmpty())
			{
				PrintAllCountriesThatUseThisCurrency(CurrencyObject);
			}
			else
			{
				cout << "\n\nCurrency Was not Found :-(\n\n";
			}
		}
		else
		{
			string CurrencyCountry = clsInput<string>::Readstring("\n\nPlease Enter Currency Country : ");

			CurrencyObject = clsCurrency::Find (CurrencyCountry);

			if (!CurrencyObject.IsEmpty())
			{
				_PrintCurrencyCard(CurrencyObject);
			}
			else
			{
				cout << "\n\nCurrency Was not Found :-(\n\n";
			}
		}
		

	}



};

