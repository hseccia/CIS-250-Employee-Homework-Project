#include "stdafx.h"
#include "info.h"
#include <fstream>



info::info()
{
}


info::~info()
{
}



void info::setAllInfo(info *people, int counter, ifstream &infile, int rowCount)
{
	infile.open("EmployeeList.txt");

	for (counter = 0; counter < rowCount; counter++)
	{
		string tempAge;
		string tempDeptID;
		string tempBuildingFlr;

		getline(infile, people[counter].ssn, ',');	//the first box indicates which person (row of data)
		getline(infile, people[counter].fName, ',');
		getline(infile, people[counter].lName, ',');
		getline(infile, people[counter].middleIniti, ',');
		getline(infile, people[counter].city, ',');
		getline(infile, people[counter].state, ',');
		getline(infile, tempAge, ',');	//get number data in a temporary tempInfo string instance
		getline(infile, people[counter].gender, ',');
		getline(infile, tempDeptID, ','); //get number data in a temporary tempInfo string instance
		getline(infile, people[counter].deptName, ',');
		getline(infile, people[counter].buildingLet, ',');
		getline(infile, tempBuildingFlr, ','); //get number data in a temporary tempInfo string instance
		getline(infile, people[counter].phoneNum, '\n');		// since the phone number is the last column, go to next row if needed


		people[counter].age = atoi(tempAge.c_str());						//convert the tempstring into a C-string (character array), so that can be converted into an integer
																			//https://stackoverflow.com/questions/27640333/how-do-i-use-atoi-function-with-strings-in-c/27640361
		people[counter].deptID = atoi(tempDeptID.c_str());
		people[counter].buildingFlr = atoi(tempBuildingFlr.c_str());
	}

	infile.close();
}

void info::getAllInfo(info *people, int counter)
{
	cout << "Employee " << counter + 1 << "'s information\n";
	cout << "======================================\n";
	cout << "SSN			:" << people[counter].ssn << endl;
	cout << "First Name		:" << people[counter].fName << endl;
	cout << "Last Name		:" << people[counter].lName << endl;
	cout << "Middle Initial		:" << people[counter].middleIniti << endl;
	cout << "City			:" << people[counter].city << endl;
	cout << "State			:" << people[counter].state << endl;
	cout << "Age			:" << people[counter].age << endl;
	cout << "Department ID		:" << people[counter].deptID << endl;
	cout << "Department Name		:" << people[counter].deptName << endl;
	cout << "Building Letter		:" << people[counter].buildingLet << endl;
	cout << "Building Floor		:" << people[counter].buildingFlr << endl;
	cout << "Phone Number		:" << people[counter].phoneNum << endl;
	cout << "\n";
}

string info::getSSN(info *people, int counter)
{
	return people[counter].ssn;
}

string info::getfName(info *people, int counter)
{
	return people[counter].fName;
}

string info::getlName(info *people, int counter)
{
	return people[counter].lName;
}

string info::getMiddleInit(info *people, int counter)
{
	return people[counter].middleIniti;
}

int info::getAge(info *people, int counter)
{
	return people[counter].age;
}

string info::getCity(info *people, int counter)
{
	return people[counter].city;
}

string info::getState(info *people, int counter)
{
	return people[counter].state;
}

int info::getDeptID(info *people, int counter)
{
	return people[counter].deptID;
}

string info::getBuildingLet(info *people, int counter)
{
	return people[counter].buildingLet;
}

string info::getDeptName(info *people, int counter)
{
	return people[counter].deptName;
}

int info::getBuildingFlr(info *people, int counter)
{
	return people[counter].buildingFlr;
}

string info::getPhoneNum(info *people, int counter)
{
	return people[counter].phoneNum;
}