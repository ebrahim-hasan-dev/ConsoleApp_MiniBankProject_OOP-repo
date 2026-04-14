#pragma once


#include "../UIAllMenues_BankProject/clsScreen.h";
#include "../UIUsers_BankProject/clsAddNewUserScreen.h"
#include "../UICurrencies_BankProject/clsFindCurrencyScreen.h"
#include "../../LogicalLayer_BankProject/clsCurrency.h";
#include "../../MyLibrary/clsInput.h";


class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

	static void _MakeSureCurrencyIsExist(clsCurrency& CurrencyObject)
	{
		while (CurrencyObject.IsEmpty())
		{
			cout << "\n\nCurrency Was not Found :-(";

			string CurrencyCode = clsInput<string>::Readstring("\n\nPlease Enter Currency1 Code : ");

			CurrencyObject = clsCurrency::Find(CurrencyCode);
		}
	}


	static clsCurrency _GetCurrency(string MSG)
	{
		string CurrencyCode = clsInput<string>::Readstring(MSG);

		clsCurrency CurrencyObject = clsCurrency::Find(CurrencyCode);

		_MakeSureCurrencyIsExist(CurrencyObject);

		return CurrencyObject;
	}

	static void _PrintCalculationResult(float Amount, clsCurrency& CurrencyObjectFrom, clsCurrency& CurrencyObjectTo)
	{
		cout << "\n\nCovert From";
		clsFindCurrencyScreen::PrintAllCountriesThatUseThisCurrency(CurrencyObjectFrom);

		cout << "\n\nCovert To";
		clsFindCurrencyScreen::PrintAllCountriesThatUseThisCurrency(CurrencyObjectTo);

		double AmountAfterConvert = CurrencyObjectFrom.CurrencyCalculator(Amount, CurrencyObjectTo);

		cout << "\n\n" << Amount << " " << CurrencyObjectFrom.GetCurrencyCode() << " = " <<
			AmountAfterConvert << " " << CurrencyObjectTo.GetCurrencyCode() << endl;

	}

public:

	static void PrintCurrencyCalculatorScreen()
	{
		char Again = 'y';

		while(Again == 'y')
		{
			system("cls");

			_DrawScreenHeader("Currency Calculator Screen");

			clsCurrency CurrencyObjectFrom = _GetCurrency("\nPlease Enter Currency1 Code : ");

			clsCurrency CurrencyObjectTo = _GetCurrency("\nPlease Enter Currency2 Code : ");

			if (CurrencyObjectFrom.GetCurrencyCode() == CurrencyObjectTo.GetCurrencyCode())
			{
				cout << "\n\nThe two Currencies are the same!\n\n";
				return;
			}

			double Amount = clsInput<double>::ReadPositiveNumber("\n\nEnter Amount to Exchange : ");

			_PrintCalculationResult(Amount, CurrencyObjectFrom, CurrencyObjectTo);

			cout << "\n\n\nDo you want to perform another calculation (y/ n) : ";
			cin >> Again;
			clsAddNewUserScreen::CheckIsValidAnswer(Again);

		}

	}

};

