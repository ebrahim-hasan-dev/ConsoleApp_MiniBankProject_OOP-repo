#pragma once

#include <iostream>
#include <vector>
using namespace std;
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/MyLibrary/clsString.h";
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/LogicalLayer_BankProject/clsPerson.h";
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/MyLibrary/clsDate.h";
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/MyLibrary/clsUtil.h";
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/DataBaseLayer_BankProject/clsSaveData.h";
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/DataBaseLayer_BankProject/clsGetData.h";


#pragma warning(disable : 4996)


class clsUser : public clsPerson
{
private:

	string _UserName = "";
	string _PassWord = "";
	short _Permissions = 0;

	enum enMode { enEmpty, enUpdate, enAdd };

	enMode _Mode;

	string _UserInformation = "";
	string _DateAndTimeLogIn = "";
	string _DateAndTimeLogOut = "";

	static string _UsersFileName;
	static string _LoginAndLogOutFileName;
	static string _LoginFileName;

	static clsUser _ConvertDataFromStringToObject(string line, string Seprator = "(//)")
	{
		vector <string> vec = clsString::SplitStringinVector(line, Seprator);

		if (vec.size() == 7)
		{
			vec.at(4) = clsUtil<string>::DecryptText(vec.at(4), 3);
			vec.at(5) = clsUtil<string>::DecryptText(vec.at(5), 5);

			return clsUser(enMode::enUpdate, vec.at(0), vec.at(1), vec.at(2), vec.at(3), vec.at(4), vec.at(5), stoi(vec.at(6)));
		}
	}

public:

	struct stLoginsAndLogOutsRegister
	{
		string LoginDateAndTime = "";
		string LogOutDateAndTime = "";
		string UserName = "";
		string PassWord = "";
		int Permissions = 0;
	};

private:

	static stLoginsAndLogOutsRegister _ConvertDataFromStringToStruct(string line, string Seprator = "(//)")
	{
		vector <string> vec = clsString::SplitStringinVector(line, Seprator);

		if (vec.size() == 5)
		{
			vec.at(2) = clsUtil<string>::DecryptText(vec.at(2), 3);
			vec.at(3) = clsUtil<string>::DecryptText(vec.at(3), 5);

			return stLoginsAndLogOutsRegister{ vec.at(0), vec.at(1), vec.at(2), vec.at(3), stoi(vec.at(4)) };
		}

		if (vec.size() == 4)
		{
			stLoginsAndLogOutsRegister RegisterLoginsAndLogOuts;

			vec.at(1) = clsUtil<string>::DecryptText(vec.at(1), 3);
			vec.at(2) = clsUtil<string>::DecryptText(vec.at(2), 5);

			RegisterLoginsAndLogOuts.LoginDateAndTime = vec.at(0);
			RegisterLoginsAndLogOuts.UserName = vec.at(1);
			RegisterLoginsAndLogOuts.PassWord = vec.at(2);
			RegisterLoginsAndLogOuts.Permissions = stoi(vec.at(3));

			return RegisterLoginsAndLogOuts;
		}
	}

	static string _ConvertDataFromObjectToString(clsUser& User, string Seprator = "(//)")
	{
		string line = "";

		line += User.FirstName + Seprator;
		line += User.LastName + Seprator;
		line += User.Email + Seprator;
		line += User.Phone + Seprator;
		line += clsUtil<string>::EncryptText(User.UserName, 3) + Seprator;
		line += clsUtil<string>::EncryptText(User.PassWord, 5) + Seprator;
		line += to_string(User._Permissions);

		return line;
	}

	static vector <clsUser> _GetAllDataOfUsersAsObjects()
	{
		vector <string> vAllDataAsString = clsGetData::LoadDataFromFileToVector(_UsersFileName);

		vector <clsUser> vAllDateAsObject;

		for (string& line : vAllDataAsString)
		{
			clsUser Client = _ConvertDataFromStringToObject(line);

			vAllDateAsObject.push_back(Client);
		}

		return vAllDateAsObject;

	}

	static vector <stLoginsAndLogOutsRegister> _GetAllDataAsStruct(string FileName)
	{
		vector <stLoginsAndLogOutsRegister> vAllDataAsStruct;

		vector <string> vAllDataAsString = clsGetData::LoadDataFromFileToVector(FileName);

		for (string& line : vAllDataAsString)
		{
			stLoginsAndLogOutsRegister Registers = _ConvertDataFromStringToStruct(line);

			vAllDataAsStruct.push_back(Registers);
		}

		return vAllDataAsStruct;
	}

	void _AddUser()
	{
		string line = _ConvertDataFromObjectToString(*this);

		clsSaveData::AppendToFile(line, _UsersFileName);
	}

	static vector <string> _ConvertAllDataFromObjectToString(vector <clsUser>& vAllDateAsObject)
	{
		vector <string> vAllDataAsString;

		for (clsUser& User : vAllDateAsObject)
		{
			if (!User.IsEmpty())
			{
				string line = _ConvertDataFromObjectToString(User);

				vAllDataAsString.push_back(line);
			}
		}

		return vAllDataAsString;

	}

	void _Update()
	{
		vector <clsUser> vAllDataAsObject = _GetAllDataOfUsersAsObjects();

		for (clsUser& User : vAllDataAsObject)
		{
			if (User._UserName == this->_UserName)
			{
				User = *this;
				break;
			}
		}

		vector <string> vAllDataAsString = _ConvertAllDataFromObjectToString(vAllDataAsObject);

		clsSaveData::SaveVectorInFile(vAllDataAsString, _UsersFileName);
	}

	string _GetUserLoginInformationAsString(string Seprator = "(//)")
	{
		_DateAndTimeLogIn = clsDate::GetCurrentDateAsString() + " - " + clsDate::GetCurrentTimeAsString();

		_UserInformation = clsUtil<string>::EncryptText(_UserName, 3) + Seprator +
			clsUtil<string>::EncryptText(_PassWord, 5) + Seprator + to_string(_Permissions);

		string UserLoginInformation = _DateAndTimeLogIn + Seprator + _UserInformation;

		return UserLoginInformation;
	}

	string _GetCurrentUserInformationAndDateAndTimeLoginAndLogOutAsString(string Seprator = "(//)")
	{
		string CurrentUserInformationAndDateAndTimeLoginAndLogOut = _DateAndTimeLogIn + Seprator + clsDate::GetCurrentDateAsString()
			+ " - " + clsDate::GetCurrentTimeAsString() + Seprator + _UserInformation;

		return CurrentUserInformationAndDateAndTimeLoginAndLogOut;
	}


public:

	enum enMainMenuePermissions {
		All = -1, pClientsList = 1, pAddClient = 2, pDeleteClient = 4,
		pUpdateClient = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64,
		pLoginsRegister = 128, pLoginsAndLogOutsRegister = 256, pTransferHistory = 512, pCurrencyExchange = 1024
	};


	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string PassWord, short Permission) : clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;

		_UserName = UserName;
		_PassWord = PassWord;
		_Permissions = Permission;
	}
	
	clsUser()
	{
		_UserName = "";
		_PassWord = "";
		_Permissions = 0;
	}

	string GetUserName()
	{
		return _UserName;
	}
	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	string GetPassWord()
	{
		return _PassWord;
	}
	void SetPassWord(string PassWord)
	{
		_PassWord = PassWord;
	}
	__declspec(property(get = GetPassWord, put = SetPassWord)) string PassWord;

	short GetPermission()
	{
		return _Permissions;
	}
	void SetPermission(short Permission)
	{
		_Permissions = Permission;
	}
	__declspec(property(get = GetPermission, put = SetPermission)) short Permissions;

	bool IsEmpty()
	{
		return _Mode == enMode::enEmpty;
	}

	static clsUser GetEmptyObject()
	{
		return clsUser(enMode::enEmpty, "", "", "", "", "", "", 0);
	}

	static clsUser Find(string UserName, string PassWord)
	{
		vector <clsUser> vAllDataAsObject = _GetAllDataOfUsersAsObjects();

		for (clsUser& User : vAllDataAsObject)
		{
			if (User._UserName == UserName && User._PassWord == PassWord)
			{
				return User;
			}
		}

		return GetEmptyObject();

	}

	static clsUser Find(string UserName)
	{
		vector <clsUser> vAllDataAsObject = _GetAllDataOfUsersAsObjects();

		for (clsUser& User : vAllDataAsObject)
		{
			if (User._UserName == UserName)
			{
				return User;
			}
		}

		return GetEmptyObject();

	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = Find(UserName);

		// return User.IsEmpty() == true ? return false : return true; 
		return !User.IsEmpty();

	}

	static bool IsUserExist(clsUser& User)
	{
		if (User._UserName != "" && User._PassWord == "")
		{
			// because if not found function (Find) will return empty object, so we must do this because we need print UserName
			string UserName = User._UserName;

			User = Find(User._UserName);

			// because if not found function (Find) will return empty object, so we must do this because we need print UserName
			User._UserName = UserName;

			// return User.IsEmpty() == true ? return false : return true; 
			return !User.IsEmpty();
		}

		if (User._UserName != "" && User._PassWord != "")
		{
			// because if not found function (Find) will return empty object, so we must do this because we need print UserName and PassWord
			string PassWord = User._PassWord;
			string UserName = User._UserName;

			User = Find(User._UserName, User._PassWord);

			// because if not found function (Find) will return empty object, so we must do this because we need print UserName and PassWord
			User._PassWord = PassWord;
			User._UserName = UserName;

			// return User.IsEmpty() == true ? return false : return true; 
			return !User.IsEmpty();
		}

	}


	enum enSaveResult { FailedEmpty, Succeeded };


	enSaveResult Save()
	{
		switch (_Mode)
		{

		case enMode::enEmpty:
		{
			return enSaveResult::FailedEmpty;
		}
		case enMode::enUpdate:
		{
			_Update();

			return enSaveResult::Succeeded;
		}
		case enMode::enAdd:
		{
			_AddUser();

			_Mode = clsUser::enMode::enUpdate;

			return enSaveResult::Succeeded;
		}

		}

	}

	bool Delete()
	{
		if (_UserName == "admin")
		{
			return false;
		}
		else
		{
			vector <clsUser> vUsers = _GetAllDataOfUsersAsObjects();

			for (clsUser& User : vUsers)
			{
				if (User._UserName == this->_UserName)
				{
					User = GetEmptyObject();
					*this = GetEmptyObject();
					break;
				}
			}

			vector <string> vAllDataAsString = _ConvertAllDataFromObjectToString(vUsers);

			clsSaveData::SaveVectorInFile(vAllDataAsString, _UsersFileName);

			return true;
		}
	}

	void ModeAdd()
	{
		_Mode = enMode::enAdd;
	}

	static vector <clsUser> GetAllUsers()
	{
		return _GetAllDataOfUsersAsObjects();
	}

	void GivePermissiontoDoEveryThing()
	{
		_Permissions = enMainMenuePermissions::All;
	}

	void GivePermissiontoAddClient()
	{
		_Permissions += enMainMenuePermissions::pAddClient;
	}

	void GivePermissiontoDeleteClient()
	{
		_Permissions += enMainMenuePermissions::pDeleteClient;
	}

	void GivePermissiontoUdateClient()
	{
		_Permissions += enMainMenuePermissions::pUpdateClient;
	}

	void GivePermissiontoFindClient()
	{
		_Permissions += enMainMenuePermissions::pFindClient;
	}

	void GivePermissiontoManageUsers()
	{
		_Permissions += enMainMenuePermissions::pManageUsers;
	}

	void GivePermissiontoShowClientsList()
	{
		_Permissions += enMainMenuePermissions::pClientsList;
	}

	void GivePermissiontoTransactions()
	{
		_Permissions += enMainMenuePermissions::pTransactions;
	}

	void GivePermissiontoLoginsRegister()
	{
		_Permissions += enMainMenuePermissions::pLoginsRegister;
	}

	void GivePermissiontoLoginsAndLogOutsRegister()
	{
		_Permissions += enMainMenuePermissions::pLoginsAndLogOutsRegister;
	}

	void GivePermissiontoTransfersHistory()
	{
		_Permissions += enMainMenuePermissions::pTransferHistory;
	}

	void GivePermissiontoCurrencyExchange()
	{
		_Permissions += enMainMenuePermissions::pCurrencyExchange;
	}

	void CancelAllPermissionts()
	{
		_Permissions = 0;
	}

	bool CheckAccessPermission(enMainMenuePermissions FunctionPermission)
	{

		if (this->_Permissions == enMainMenuePermissions::All)
		{
			return true;
		}

		if ((this->_Permissions & FunctionPermission) == FunctionPermission)
		{
			return true;
		}

		return false;
	}

	void RegisterLogin()
	{
		string UserLoginInformation = _GetUserLoginInformationAsString();

		clsSaveData::AppendToFile(UserLoginInformation, _LoginFileName);
	}

	void RegisterLoginAndLogOut()
	{
		string CurrentUserInformationAndDateAndTimeLoginAndLogOut = _GetCurrentUserInformationAndDateAndTimeLoginAndLogOutAsString();

		clsSaveData::AppendToFile(CurrentUserInformationAndDateAndTimeLoginAndLogOut, _LoginAndLogOutFileName);
	}

	static vector <stLoginsAndLogOutsRegister> GetAllLoginsAndLogOutsRegister()
	{
		return _GetAllDataAsStruct(_LoginAndLogOutFileName);
	}

	static vector <stLoginsAndLogOutsRegister> GetAllLoginsRegister()
	{
		return _GetAllDataAsStruct(_LoginFileName);
	}


};


string clsUser::_UsersFileName = "Users.txt";
string clsUser::_LoginAndLogOutFileName = "RegisterLoginAndLogOut.txt";
string clsUser::_LoginFileName = "RegisterLogin.txt";
