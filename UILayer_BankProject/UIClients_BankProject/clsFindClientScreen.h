#pragma once


#include "clsDeleteClientScreen.h";


class clsFindClientScreen : protected clsScreen
{
private:

	static void _PrintClientCard(clsBanckClient Client)
	{
		cout << "\n\nClient Found :-)\n";

		cout << "\n\nClient Card:\n";
		cout << "----------------------------------------------\n\n";
		cout << "First Name                : " << Client.FirstName << endl;
		cout << "Last Name                 : " << Client.LastName << endl;
		cout << "Full Name                 : " << Client.GetFullName() << endl;
		cout << "Email                     : " << Client.Email << endl;
		cout << "Phone                     : " << Client.Phone << endl;
		cout << "AccountNumber             : " << Client.GetAccountNumber() << endl;
		cout << "PinCode                   : " << Client.PinCode << endl;
		cout << "AccountBalance            : " << Client.AccountBalance << endl << endl;
		cout << "----------------------------------------------\n\n";

	}

public:

	static void FindClientScreen()
	{
		system("cls");

		_DrawScreenHeader("Find Client Screen");
		
		string AccountNumber = clsInput<string>::Readstring("\n\nPlease Enter Account Number : ");

		clsBanckClient Client = clsBanckClient::GetAddNewClientObject(AccountNumber);

		clsDeleteClientScreen::MakeSureClientIsExist(Client);

		_PrintClientCard(Client);

	}

};

