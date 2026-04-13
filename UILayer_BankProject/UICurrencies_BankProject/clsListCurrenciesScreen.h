#pragma once

#include "D:\Visual Studio 2022 Projects\ConsoleApp_MiniBankProject_OOP\UILayer_BankProject\UIAllMenues_BankProject/clsScreen.h";
#include "D:\Visual Studio 2022 Projects\ConsoleApp_MiniBankProject_OOP\LogicalLayer_BankProject/clsCurrency.h";




class clsListCurrenciesScreen : protected clsScreen
{
private:

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

	static void PrintCurrenciesList()
	{
		system("cls");

		vector <clsCurrency> vAllData = clsCurrency::GetAllDataOfCurrencies();

		string Title = "Currencies List Screen";
		string SubTitle = "(" + to_string(vAllData.size()) + ") Currency.";

		_DrawScreenHeader(Title, SubTitle);

		if (vAllData.size() == 0)
		{
			cout << "\n\n\n\n\t\t\tNo Currencies Available In The System!\n\n";
		}
		else
		{
			_PrintHeaderTaple();

			for (clsCurrency& Currency : vAllData)
			{
				_PrintCurrencyinList(Currency);
				cout << endl;
			}
			cout << "\n\n-----------------------------------------------------------------------------------------------------------------\n\n";

		}

	}


};

