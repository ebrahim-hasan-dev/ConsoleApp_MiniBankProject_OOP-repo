
#include <iostream>
using namespace std;

#include "../ConsoleApp_MiniBankProject_OOP-repo/UILayer_BankProject/UIRegisters_BankProject/clsLogInScreen.h";


int main()
{

	while (true)
	{
		if (!clsLogInScreen::PrintLogInScreen())
		{
			break;
		}
	}

	system("pause > 0");
	return 0;
}


