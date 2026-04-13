#pragma once


#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/DataBaseLayer_BankProject/clsSaveData.h";
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/DataBaseLayer_BankProject/clsGetData.h";
#include "D:/Visual Studio 2022 Projects/ConsoleApp_MiniBankProject_OOP/MyLibrary/clsString.h";


class clsCurrency
{
private:

	static string _CurrenciesFileName;

	string _CurrencyCountry = "";
	string _CurrencyCode = "";
	string _CurrencyName = "";
	float _CurrencyRateTo_1_Dollar = 0;

	enum enMode { enEmpty, enUpdate };

	enMode _Mode;

	static clsCurrency _ConvertDataFromStringToObject(string line, string Seprator = "#//#")
	{

		vector <string> vec = clsString::SplitStringinVector(line, Seprator);

		if (vec.size() == 4)
		{
			return clsCurrency(enMode::enUpdate, vec.at(0), vec.at(1), vec.at(2), stof(vec.at(3)));
		}
	}

	static vector <clsCurrency> _GetAllDataOfCurrenciesAsObjects()
	{
		vector <string> vAllDataAsString = clsGetData::LoadDataFromFileToVector(_CurrenciesFileName);

		vector <clsCurrency> vAllDateAsObject;

		for (string& line : vAllDataAsString)
		{
			clsCurrency Client = _ConvertDataFromStringToObject(line);

			vAllDateAsObject.push_back(Client);
		}

		return vAllDateAsObject;

	}

	static string _ConvertDataFromObjectToString(clsCurrency& CurrencyObject, string Seprator = "#//#")
	{
		string line = "";

		line += CurrencyObject._CurrencyCountry + Seprator;
		line += CurrencyObject._CurrencyCode + Seprator;
		line += CurrencyObject._CurrencyName + Seprator;
		line += to_string(CurrencyObject._CurrencyRateTo_1_Dollar);

		return line;
	}

	static vector <string> _ConvertAllDataFromObjectToString(vector <clsCurrency>& vAllDateAsObject)
	{
		vector <string> vAllDataAsString;

		for (clsCurrency& Client : vAllDateAsObject)
		{
			string line = _ConvertDataFromObjectToString(Client);

			vAllDataAsString.push_back(line);
		}

		return vAllDataAsString;

	}

	static clsCurrency GetEmptyObject()
	{
		return clsCurrency(enMode::enEmpty, "", "", "", 0);
	}

	void _Update()
	{
		vector <clsCurrency> vAllDateAsObject = _GetAllDataOfCurrenciesAsObjects();

		for (clsCurrency& CurrencyObject : vAllDateAsObject)
		{
			if (CurrencyObject._CurrencyCode == clsString::ConvertionAllStringToUpper(this->_CurrencyCode))
			{
				CurrencyObject._CurrencyRateTo_1_Dollar = this->_CurrencyRateTo_1_Dollar;
			}
		}

		vector <string> vAllDataAsString = _ConvertAllDataFromObjectToString(vAllDateAsObject);

		clsSaveData::SaveVectorInFile(vAllDataAsString, _CurrenciesFileName);

	}

public:

	clsCurrency()
	{
		_CurrencyCountry = "";
		_CurrencyCode = "";
		_CurrencyName = "";
		_CurrencyRateTo_1_Dollar = 0;
	}

	clsCurrency(enMode Mode, string CurrencyCountry, string CurrencyCode, string CurrencyName, float CurrencyRateTo_1_Dollar)
	{
		_Mode = Mode;

		_CurrencyCountry = CurrencyCountry;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_CurrencyRateTo_1_Dollar = CurrencyRateTo_1_Dollar;
	}

	string GetCurrencyCountry()
	{
		return _CurrencyCountry;
	}

	string GetCurrencyCode()
	{
		return _CurrencyCode;
	}

	string GetCurrencyName()
	{
		return _CurrencyName;
	}

	float GetCurrencyRateTo_1_Dollar()
	{
		return _CurrencyRateTo_1_Dollar;
	}

	void UpdateRate(float NewRate)
	{
		_CurrencyRateTo_1_Dollar = NewRate;

		_Update();
	}
	
	bool IsEmpty()
	{
		return _Mode == enMode::enEmpty;
	}


	static clsCurrency Find(string SearchKey)
	{
		vector <clsCurrency> vAllDataAsObject = _GetAllDataOfCurrenciesAsObjects();

		for (clsCurrency& CurrencyObject : vAllDataAsObject)
		{
			if (clsString::ConvertionAllStringToUpper(CurrencyObject._CurrencyCountry) == clsString::ConvertionAllStringToUpper(SearchKey)
				|| CurrencyObject._CurrencyCode == clsString::ConvertionAllStringToUpper(SearchKey))
			{
				return CurrencyObject;
			}
		}

		return GetEmptyObject();
	}

	//static bool IsCurrencyExist(clsCurrency& Currency)
	//{
	//	if (Currency._CurrencyCountry != "" && Currency._CurrencyCode == "")
	//	{
	//		// because if not found function (Find) will return empty object, so we must do this because we need print CurrencyCountry
	//		string CurrencyCountry = Currency._CurrencyCountry;

	//		Currency = Find(Currency._CurrencyCountry);

	//		// because if not found function return (Find) will empty object, so we must do this because we need print CurrencyCountry
	//		Currency._CurrencyCountry = Currency.IsEmpty() ? CurrencyCountry : Currency._CurrencyCountry;

	//		// return Currency.IsEmpty() == true ? return false : return true; 
	//		return !Currency.IsEmpty();
	//	}

	//	if (Currency._CurrencyCountry == "" && Currency._CurrencyCode != "")
	//	{
	//		// because if not found function (Find) return will empty object, so we must do this because we need print CurrencyCode
	//		string CurrencyCode = Currency._CurrencyCode;

	//		Currency = Find(Currency._CurrencyCode);

	//		// because if not found function (Find) will return empty object, so we must do this because we need print CurrencyCode
	//		Currency._CurrencyCode = Currency.IsEmpty() ? CurrencyCode : Currency._CurrencyCode;

	//		// return Currency.IsEmpty() == true ? return false : return true; 
	//		return !Currency.IsEmpty();
	//	}

	//}


	static vector <clsCurrency> GetAllDataOfCurrencies()
	{
		return _GetAllDataOfCurrenciesAsObjects();
	}


	/*double ConvertFromDollarToAnyCurrency(double Amount, clsCurrency& CurrencyTo)
	{
		Amount = Amount * CurrencyTo._CurrencyRateTo_1_Dollar;

		return Amount;
	}*/

	//double ConvertFromAnyCurrencyToDollar(double Amount)
	//{
	//	// Amount = (1 / _CurrencyRateTo_1_Dollar) * Amount;

	//	 Amount = Amount / _CurrencyRateTo_1_Dollar;

	//	return Amount;
	//}

	double CurrencyCalculator(double Amount, clsCurrency& CurrencyTo)
	{
		// from dallar to any Currency
		if (_CurrencyCode == "USD")
		{
			// from dallar to any Currency
			Amount = Amount * CurrencyTo._CurrencyRateTo_1_Dollar;
		}
		else
		{
			// from any Currency to dollar
			//Amount = (1 / _CurrencyRateTo_1_Dollar) * Amount;

			// from any Currency to dollar
			Amount = Amount / _CurrencyRateTo_1_Dollar;

			if (CurrencyTo._CurrencyCode != "USD")
			{
				Amount = Amount * CurrencyTo._CurrencyRateTo_1_Dollar;
			}
		}
		
		return Amount;
	}

	static vector <clsCurrency> GetAllCountriesThatUseThisCurrency(string CurrencyCode)
	{
		vector <clsCurrency> vAllDataAsObject = _GetAllDataOfCurrenciesAsObjects();

		vector <clsCurrency> vAllCountries;

		for (clsCurrency CurrencyObject : vAllDataAsObject)
		{
			if (CurrencyObject._CurrencyCode == clsString::ConvertionAllStringToUpper(CurrencyCode))
			{
				vAllCountries.push_back(CurrencyObject);
			}
		}

		return vAllCountries;
	}


};

string clsCurrency::_CurrenciesFileName = "Currencies.txt";
