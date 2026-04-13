#pragma once

#include <iostream>
#include <vector>
#include "clsPerson.h";
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/MyLibrary/clsString.h";
#include "CurrentUser.h";
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/MyLibrary/clsUtil.h";
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/DataBaseLayer_BankProject/clsGetData.h";
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/DataBaseLayer_BankProject/clsSaveData.h";
using namespace std;


class clsBanckClient : public clsPerson
{
private:

	static string _ClientsFileName;

	static string _TransferHistoryFileName;

	enum enMode {enEmpty, enUpdate, enAdd};

public:

	struct stTransferHistoryRegister
	{
		string DateAndTime = "";
		string SourceAccountNumber = "";
		string DestinationAccountNumber = "";
		double TransferAmount = 0;
		double SourceAccountBalanceAfter = 0;
		double DestinationAccountBalanceAfter = 0;
		string UserName = "";
	};

private:

	enMode _Mode;

	string _AccountNumber = "";
	string _PinCode = "";
	double _AccountBalance = 0;

	static clsBanckClient _ConvertDataFromStringToObject(string line, string Seprator = "(//)")
	{

		vector <string> vec = clsString::SplitStringinVector(line, Seprator);

		if (vec.size() == 7)
		{
			vec.at(4) = clsUtil<string>::DecryptText(vec.at(4), 5);
			vec.at(5) = clsUtil<string>::DecryptText(vec.at(5), 3);

			return clsBanckClient(enMode::enUpdate, vec.at(0), vec.at(1), vec.at(2), vec.at(3), vec.at(4), vec.at(5), stod(vec.at(6)));
		}
	}

	static vector <clsBanckClient> _GetAllDataOfClientsAsObjects()
	{
		vector <string> vAllDataAsString = clsGetData::LoadDataFromFileToVector(_ClientsFileName);

		vector <clsBanckClient> vAllDateAsObject;

		for (string& line : vAllDataAsString)
		{
			clsBanckClient Client = _ConvertDataFromStringToObject(line);

			vAllDateAsObject.push_back(Client);
		}

		return vAllDateAsObject;

	}

	static string _ConvertDataFromObjectToString(clsBanckClient& BanckClient, string Seprator = "(//)") 
	{
		string line = "";

		line += BanckClient.FirstName + Seprator;
		line += BanckClient.LastName + Seprator;
		line += BanckClient.Email + Seprator;
		line += BanckClient.Phone + Seprator;

		line += clsUtil<string>::EncryptText(BanckClient._PinCode, 5) + Seprator;
		line += clsUtil<string>::EncryptText(BanckClient._AccountNumber, 3) + Seprator;

		line += to_string(BanckClient._AccountBalance);

		return line;
	}

	static vector <string> _ConvertAllDataFromObjectToString(vector <clsBanckClient>& vAllDateAsObject)
	{
		vector <string> vAllDataAsString;

		for (clsBanckClient& Client : vAllDateAsObject)
		{
			if(!Client.IsEmpty())
			{
				string line = _ConvertDataFromObjectToString(Client);

				vAllDataAsString.push_back(line);
			}
		}

		return vAllDataAsString;

	}

	static stTransferHistoryRegister _CovertDataFromStringToStructOfstTransferHistoryRegister(string& line, string Seprator = "(//)")
	{
		vector <string> vec = clsString::SplitStringinVector(line, Seprator);

		if (vec.size() == 7)
		{
			vec.at(6) = clsUtil<string>::DecryptText(vec.at(6), 3);

			return stTransferHistoryRegister{ vec.at(0), vec.at(1), vec.at(2),
				stod(vec.at(3)), stod(vec.at(4)), stod(vec.at(5)), vec.at(6) };
		}
	}

	static clsBanckClient GetEmptyObject()
	{
		return clsBanckClient(enMode::enEmpty, "", "", "", "", "", "", 0);
	}

	void _Update()
	{
		vector <clsBanckClient> vAllDateAsObject = _GetAllDataOfClientsAsObjects();

		for (clsBanckClient& Client : vAllDateAsObject)
		{
			if (Client._AccountNumber == this->_AccountNumber)
			{
				Client = *this;
				break;
			}
		}

		vector <string> vAllDataAsString = _ConvertAllDataFromObjectToString(vAllDateAsObject);

		clsSaveData::SaveVectorInFile(vAllDataAsString, _ClientsFileName);

	}

	void _AddClient()
	{
		string ClientAsString = _ConvertDataFromObjectToString(*this);

		clsSaveData::AppendToFile(ClientAsString, _ClientsFileName);
	}

	string _GetTransferOperationInformationAsString(clsBanckClient& DestinationClient, double TransferAmount, string Seprator = "(//)")
	{
		string TransferOperationInformation = clsDate::GetCurrentDateAsString() + " - " + clsDate::GetCurrentTimeAsString() +
			Seprator + _AccountNumber + Seprator + DestinationClient._AccountNumber +
			Seprator + to_string(TransferAmount) + Seprator +
			to_string(_AccountBalance) + Seprator + to_string(DestinationClient._AccountBalance) +
			Seprator + clsUtil<string>::EncryptText(CurrentUser.UserName, 3);


		return TransferOperationInformation;
	}

	void _RegisterTransferOperations(clsBanckClient& DestinationClient, double TransferAmount, string Seprator = "(//)")
	{
		string TransferInformationAsString = _GetTransferOperationInformationAsString(DestinationClient, TransferAmount);

		clsSaveData::AppendToFile(TransferInformationAsString, _TransferHistoryFileName);
	}

public:

	clsBanckClient()
	{
		_AccountNumber = "";
		_PinCode = "";
		_AccountBalance = 0;
	}

	clsBanckClient(enMode Mode, string FirstName, string LastName, string Email, 
		string Phone, string PinCode, string AccountNumber, double AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;

		_PinCode = PinCode;
		_AccountNumber = AccountNumber;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return _Mode == enMode::enEmpty;
	}


	string GetPinCode()
	{
		return _PinCode;
	}
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;


	double GetAccountBalance()
	{
		return _AccountBalance;
	}
	void SetAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;


	string GetAccountNumber()
	{
		return _AccountNumber;
	}

	static clsBanckClient Find(string AccountNumber)
	{
		vector <clsBanckClient> vAllDataAsObject = _GetAllDataOfClientsAsObjects();

		for (clsBanckClient& Client : vAllDataAsObject)
		{
			if (Client._AccountNumber == AccountNumber)
			{
				return Client;
			}
		}

		return GetEmptyObject();
	}

	static clsBanckClient Find(string AccountNumber, string PinCode)
	{
		vector <clsBanckClient> vAllDataAsObject = _GetAllDataOfClientsAsObjects();

		for (clsBanckClient& Client : vAllDataAsObject)
		{
			if (Client._AccountNumber == AccountNumber && Client._PinCode == PinCode)
			{
				return Client;
			}
		}

		return GetEmptyObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBanckClient Client = Find(AccountNumber);

		return !Client.IsEmpty();
	}

	static bool IsClientExist(clsBanckClient& Client)
	{
		if (Client._AccountNumber != "" && Client._PinCode == "")
		{
			// because if not found function (Find) will return empty object, so we must do this because we need print account number
			string AccountNumber = Client._AccountNumber;

			Client = Find(Client._AccountNumber);

			// because if not found function return (Find) will empty object, so we must do this because we need print account number
			Client._AccountNumber = AccountNumber;

			// return Client.IsEmpty() == true ? return false : return true; 
			return !Client.IsEmpty();
		}

		if (Client._AccountNumber != "" && Client._PinCode != "")
		{
			// because if not found function (Find) return will empty object, so we must do this because we need print account number and PinCode
			string AccountNumber = Client._AccountNumber;
			string PinCode = Client._PinCode;

			Client = Find(Client._AccountNumber, Client._PinCode);

			// because if not found function (Find) will return empty object, so we must do this because we need print account number and PinCode
			Client._AccountNumber = AccountNumber;
			Client._PinCode = PinCode;

			// return Client.IsEmpty() == true ? return false : return true; 
			return !Client.IsEmpty();
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
			_AddClient();

			_Mode = clsBanckClient::enMode::enUpdate;

			return enSaveResult::Succeeded;
		}

		}
		
	}
	
	static clsBanckClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBanckClient(enMode::enAdd, "", "", "", "", "", AccountNumber, 0);
	}
	
	void Delete()
	{
		vector <clsBanckClient> vClientsDate = _GetAllDataOfClientsAsObjects();

		for (clsBanckClient& Client : vClientsDate)
		{
			if (Client._AccountNumber == this->_AccountNumber)
			{
				Client = GetEmptyObject();
				*this = GetEmptyObject();
				break;
			}
		}

		vector <string> vAllDataAsString = _ConvertAllDataFromObjectToString(vClientsDate);

		clsSaveData::SaveVectorInFile(vAllDataAsString, _ClientsFileName);
	}

	static vector <clsBanckClient> GetAllClients()
	{
		return _GetAllDataOfClientsAsObjects();
	}

	static double GetTotalBalances()
	{
		vector <clsBanckClient> vClients = _GetAllDataOfClientsAsObjects();

		double TotalBalances = 0;

		for (clsBanckClient& Client : vClients)
		{
			TotalBalances += Client.AccountBalance;
		}

		return TotalBalances;
	}

	bool Withdraw(double WithdrawAmount)
	{
		if (WithdrawAmount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= WithdrawAmount;

			Save();

			return true;
		}
	}

	void Deposit(double DepositAmount)
	{
		_AccountBalance += DepositAmount;

		Save();
	}

	bool Transfer(double TransferAmount, clsBanckClient& DestinationClient)
	{
		if (TransferAmount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= TransferAmount;

			Save();

			DestinationClient.Deposit(TransferAmount);

			_RegisterTransferOperations(DestinationClient, TransferAmount);

			return true;
		}
	}

	static vector <stTransferHistoryRegister> GetAllTransfersHistoryAsStruct()
	{
		vector <string> vAllDateAsString = clsGetData::LoadDataFromFileToVector(_TransferHistoryFileName);

		vector <stTransferHistoryRegister> vAllDataAsStruct;

		for (string& ClientAsString : vAllDateAsString)
		{
			stTransferHistoryRegister TransferHistoryRegister = _CovertDataFromStringToStructOfstTransferHistoryRegister(ClientAsString);
				
			vAllDataAsStruct.push_back(TransferHistoryRegister);
		}

		return vAllDataAsStruct;
	}




};


string clsBanckClient::_ClientsFileName = "Clients.txt";

string clsBanckClient::_TransferHistoryFileName = "TransferHistory.txt";
