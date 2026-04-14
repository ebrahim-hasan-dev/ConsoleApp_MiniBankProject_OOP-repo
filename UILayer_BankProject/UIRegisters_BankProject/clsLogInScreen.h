#pragma once

#include "../../LogicalLayer_BankProject/clsUser.h";
#include "../../MyLibrary/clsInput.h";
#include "../../LogicalLayer_BankProject/CurrentUser.h";
#include "../UIAllMenues_BankProject/clsScreen.h";
#include "../UIAllMenues_BankProject\clsMainMenueScreen.h";



class clsLogInScreen : protected  clsScreen
{
private:


public:

	static bool PrintLogInScreen()
	{
		short trials = 3;
		bool LoginFail = false;

		do 
		{
			system("cls");

			_DrawScreenHeader("Login Screen");

			if (LoginFail)
			{
				cout << "\nInvalid UserName / PassWord!\n\n";
				trials--;
			}

			if (trials == 0)
			{
				cout << "\nYou are Locked!\n\n";
			
				return false;
				// other solution void PrintLogInScreen (), and here use function ( exit(0);)
				// or we use global varible in file CurrentUser 
			}

			cout << "\nYou Have " << trials << " Trial(s) to login.\n";

			CurrentUser.UserName = clsInput<string>::Readstring("\n\nEnter UserName : ");
			CurrentUser.PassWord = clsInput<string>::Readstring("\nEnter PassWord : ");

			// this mean clsUser::IsUserExist(CurrentUser) == false store in LoginFail-> true
			LoginFail = !clsUser::IsUserExist(CurrentUser);
			
		} while (LoginFail);
		
		CurrentUser.RegisterLogin();

		clsMainMenueScreen::PrintMainMenueScreen();

		CurrentUser.RegisterLoginAndLogOut();

		//PrintLogInScreen();

		return true;

	}



};

