
#include <iostream>
using namespace std;
#include "D:\Visual Studio 2022 Projects\ConsoleApp_MiniBankProject_OOP\UILayer_BankProject\UIRegisters_BankProject\clsLogInScreen.h";


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


