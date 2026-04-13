#pragma once

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


class clsSaveData
{
private:




public:

	// & vClientsDate Pass By ref because fast only 
	static void SaveVectorInFile(vector<string>& vData, string FileName)
	{
		fstream myfile;
		myfile.open(FileName, ios::out);

		if (myfile.is_open())
		{
			for (string& ClientAsString : vData)
			{
				myfile << ClientAsString << endl;
			}

			myfile.close();
		}

	}

	static void AppendToFile(string& line, string FileName)
	{
		fstream myfile;
		myfile.open(FileName, ios::app);

		if (myfile.is_open())
		{
			myfile << line << endl;
		}

		myfile.close();
	}



};

