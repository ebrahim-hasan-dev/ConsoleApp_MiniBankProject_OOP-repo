#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


class clsGetData
{
private:

	

public:


	static vector <string> LoadDataFromFileToVector(string FileName)
	{
		vector <string> vAllDate;

		fstream myfile;
		myfile.open(FileName, ios::in);

		if (myfile.is_open())
		{
			string line = "";

			while (getline(myfile, line))
			{
				vAllDate.push_back(line);
			}
		}

		myfile.close();

		return vAllDate;
	}

	
	

};
