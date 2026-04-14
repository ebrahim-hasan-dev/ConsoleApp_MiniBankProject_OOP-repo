#pragma once

#include "../../MyLibrary/clsInput.h"
#include "../../LogicalLayer_BankProject/clsCurrency.h";
#include "../../UILayer_BankProject\UIAllMenues_BankProject/clsScreen.h";
#include "../../UILayer_BankProject\UIUsers_BankProject/clsAddNewUserScreen.h"
#include "../../UILayer_BankProject\UICurrencies_BankProject/clsFindCurrencyScreen.h"


class clsUpdateRateScreen : protected clsScreen
{
private:

	static void _ReadNewRate(clsCurrency& CurrencyObject)
	{
		cout << "\n\nUpdate Currency Rate:\n";
		cout << "--------------------------\n\n";

		float NewRate = clsInput<float>::ReadPositiveNumber("\nEnter New Rate : ");

		CurrencyObject.UpdateRate(NewRate);

	}

	static void _UpdataCurrency()
	{
		string CurrencyCode = clsInput<string>::Readstring("\nPlease Enter Currency Code : ");

		clsCurrency CurrencyObject = clsCurrency::Find(CurrencyCode);

		if (!CurrencyObject.IsEmpty())
		{
			clsFindCurrencyScreen::PrintAllCountriesThatUseThisCurrency(CurrencyObject);

			char sure = 'y';
			cout << "\n\nAre you sure you want to update the rate of this Currency (y, n) ? ";
			cin >> sure;
			clsAddNewUserScreen::CheckIsValidAnswer(sure);

			if (tolower(sure) == 'y')
			{
				_ReadNewRate(CurrencyObject);

				cout << "\n\nCurrency Rate Updated Successfully :-)\n";
			}
			else
			{
				cout << "\n\nCurrency don't updated.\n";
			}

			clsFindCurrencyScreen::PrintAllCountriesThatUseThisCurrency(CurrencyObject);

		}
		else
		{
			cout << "\n\nCurrency Was not Found :-(\n\n";
		}

		

	}

public:

	static void PrintUpdataRateScreen()
	{
		system("cls");

		_DrawScreenHeader("Updata Currency Screen");

		_UpdataCurrency();
	}

};

