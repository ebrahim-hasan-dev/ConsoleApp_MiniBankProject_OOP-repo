#pragma once

#include <iostream>
#include <iomanip>
using namespace std;
#include "../../LogicalLayer_BankProject/CurrentUser.h";
#include "../../MyLibrary/clsDate.h";

#pragma warning(disable : 4996)

class clsScreen
{

	static void _PrintUserName()
	{
		if(!CurrentUser.IsEmpty())
		{
			cout << setw(37) << left << "" << "User: " << CurrentUser.UserName << "\n\n";
		}
	}

	static void _PrintCurrentDate()
	{
		
		
		clsDate CurrentDate = clsDate::GetCurrentDate();

		cout << setw(37) << left << "" << "Date: " << CurrentDate.NameOfDay() << "  " << CurrentDate.Day << "/" << CurrentDate.Month << "/" << CurrentDate.Year << "\n";
		
	}

	static void _TheTime()
	{
	
			time_t t = time(0);

			tm* d = localtime(&t);

			short h = d->tm_hour;

			if (h < 12)
			{
				h = h == 0 ? 12 : h;

				cout << setw(37) << left << "" << "Time: " << h << ":" << d->tm_min << " AM" << "\n";
			}
			else
			{
				h = h > 12 ? h -= 12 : h;

				cout << setw(37) << left << "" << "Time: " << h << ":" << d->tm_min << " PM" << "\n";
			}
	}

protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\n" << setw(10) << left << "" << "==============================================================================================\n\n";
		
		cout << setw(47) << left << "" << Title;
		
		if (SubTitle != "")
		{
			cout << "\n" << setw(50) << left << "" << SubTitle;
		}

		cout << "\n\n" << setw(10) << left << "" << "==============================================================================================\n\n";
		
		_TheTime();
		_PrintCurrentDate();
		_PrintUserName();

	}

	


};

