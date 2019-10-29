// Title: Structured Employee Data
// Author: Hannah Seccia
// Date: Feb. 3, 2018

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "info.h"

using namespace std;

ifstream infile;

////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// N O N  -  M E N U    F U N C S /////////////////////////////////

void screenPseudoPause(string fillerCin)
{
	cout << "Press enter to continue...\n";
	cin.ignore();
	getline(cin, fillerCin);
}

void getRowCount(string templine, int &rowCount)
{
	infile.open("EmployeeList.txt");


	while (infile.peek() != EOF)							//EOF = constant flag for when the end of file is reached/read
															//infile.peek "peeks" at the next cover coming out

	{														//https://stackoverflow.com/questions/28105254/how-to-check-whether-ifstream-is-end-of-file-in-c
															//https://stackoverflow.com/questions/12463750/c-searching-text-file-for-a-particular-string-and-returning-the-line-number-wh

		getline(infile, templine, ',');						//line is only being used to go through file

		if (templine.find('\n') != -1)						//if a space is found in the data that templine stored
		{													//-1 = string::npos, which means not found
			rowCount++;
		}
	}

	infile.close();
}



/////////////////////////////////// E N D   O F   N O N - M E N U    F U N C S ////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void optionLoopFunc(bool &optionLoop, int &choice, bool &programEnd)
{
	while (optionLoop)
	{
		cout << "Enter your next selection (99 to return to menu, -999 to exit): ";
		cin >> choice;
		if (choice == -999)
		{
			optionLoop = false;
			programEnd = true;
		}
		if (choice == 99)
		{
			optionLoop = false;
		}

		if (choice != 99 && choice != -999)
		{
			cout << "That is not a valid selection. Try again\n";
		}
	}
}

void avgAgeMichEmployee(info *people, int &rowCount, bool &optionLoop, int &choice, bool &programEnd, int &counter)
{
	system("cls");
	int michEmployeeNum = 0;
	int avgHolder = 0;
	int realAvgAge = 0;


	for (counter = 0; counter < rowCount; counter++)					///////////////////////////////////////////////////////////////
	{
		if ((people[counter].getState(people, counter)) == "MI")
		{
			michEmployeeNum++;
			avgHolder += (people[counter].getAge(people, counter));

		}

	}

	realAvgAge = (avgHolder / michEmployeeNum);

	cout << "The average age for employees who live in Michigan is: " << realAvgAge << ".\n";

	optionLoopFunc(optionLoop, choice, programEnd);
}

void findEmployee(info *people, int &rowCount, bool &optionLoop, int &choice, bool &programEnd, int &counter)
{
	system("cls");
	string tempStringFind;
	bool searchSucc = false;

	cout << "Enter the social security number of the employee you wish to find (with dashes included): ";
	cin.ignore();
	getline(cin, tempStringFind);

	for (counter = 0; counter < rowCount; counter++)
	{
		if (tempStringFind == people[counter].getSSN(people, counter))
		{
			searchSucc = true;
			break;
		}
	}

	if (searchSucc)
	{
		cout << "Employee " << counter + 1 << "'s information\n";
		cout << "======================================\n";
		cout << "SSN			:" << people[counter].getSSN(people, counter) << endl;
		cout << "First Name		:" << people[counter].getfName(people, counter) << endl;
		cout << "Last Name		:" << people[counter].getlName(people, counter) << endl;
		cout << "Middle Initial		:" << people[counter].getMiddleInit(people, counter) << endl;
		cout << "City			:" << people[counter].getCity(people, counter) << endl;
		cout << "State			:" << people[counter].getState(people, counter) << endl;
		cout << "Age			:" << people[counter].getAge(people, counter) << endl;
		cout << "Department ID		:" << people[counter].getDeptID(people, counter) << endl;
		cout << "Department Name		:" << people[counter].getDeptName(people, counter) << endl;
		cout << "Building Letter		:" << people[counter].getBuildingLet(people, counter) << endl;
		cout << "Building Floor		:" << people[counter].getBuildingFlr(people, counter) << endl;
		cout << "Phone Number		:" << people[counter].getPhoneNum(people, counter) << endl;
		cout << "\n";
	}



	if (!searchSucc)
	{
		cout << "That is not a valid social security number. Go to the main menu and try again.\n";
	}

	optionLoopFunc(optionLoop, choice, programEnd);
}


void displayDeptsBldA(info *people, int &rowCount, bool &optionLoop, int &choice, bool &programEnd, int &counter)
{
	system("cls");
	int bldDeptNum = 0;									// how many people's department fit the building letter (regardless of duplicates)
	int duplicateCounter = 0;							// counter to help remove duplicates
	int duplicateCounter2 = 1;							// 2nd counter to help remove duplicates

	for (counter = 0; counter < rowCount; counter++)
	{
		if (people[counter].getBuildingLet(people, counter) == "A")
		{
			bldDeptNum++;
		}

	}

	string *deptNames = new string[bldDeptNum];			// create temp array to work specifically with department names

	for (counter = 0; counter < bldDeptNum; counter++)				// rowCount does not matter, since we're not using people array
	{
		if (people[counter].getBuildingLet(people, counter) == "A")
		{
			deptNames[counter] = people[counter].getDeptName(people, counter);		// if people's building letter is A, get their dept name
		}

	}



	for (int l = 0; l < bldDeptNum; l++)										// runs as many times as there is department name entries		
	{																			// (main big loop)
		for (int i = 0; i < bldDeptNum; i++)
		{
			if (duplicateCounter2 >= bldDeptNum)								// so that the counter doesn't read into array space that doesn't exist	
			{
				break;															// if the counter is about to do that, break back to the main loop
			}
			else
			{

				if (deptNames[duplicateCounter] == deptNames[duplicateCounter2]) // takes current string associated with counter 1 and
				{																 // compares it with the strings ahead of it in a straight row
																				 // (when l = 0 and i = 0, deptName[0] will be compared with deptName[1]
																				 //  when i = 1, deptName[0] will be compared with deptName[2], etc.)

					deptNames[duplicateCounter2] = "";							 // if a duplicate is found, the one nearest across will be deleted
				}

				duplicateCounter2++;											 // add to the second counter to compare across the row
			}

		}

		duplicateCounter++;														// when the second counter reaches the breakpoint (when it 
																				// equals the bldNum), go back to main loop, add one to the 
																				// first counter (now deptName[1] will be compared, next time
																				// it will be deptName[2], etc.)

		duplicateCounter2 = (duplicateCounter + 1);								// makes sure that the second counter is always one ahead of
	}																			// the first so that it isn't compared to previous strings or itself

	cout << "Building A Departments\n";
	cout << "======================\n";
	for (int i = 0; i < bldDeptNum; i++)
	{
		cout << deptNames[i] << endl;
	}

	delete[] deptNames;

	optionLoopFunc(optionLoop, choice, programEnd);
}

void displayCompBldFlr(info *people, int &rowCount, bool &optionLoop, int &choice, bool &programEnd, int &counter)
{
	system("cls");
	int personNumber2 = 0;

	for (counter = 0; counter < rowCount; counter++)
	{
		if ((people[counter].getDeptName(people, counter)) == "Computer Science")
		{
			personNumber2 = counter;
			break;
		}
	}

	cout << "Computer Science Employees' Building\n";
	cout << "====================================\n";
	cout << "Building: " << people[personNumber2].getBuildingLet(people, personNumber2)
		<< ", Floor: " << people[personNumber2].getBuildingFlr(people, counter) << endl;

	optionLoopFunc(optionLoop, choice, programEnd);

}

void oldestEmployee(info *people, int &rowCount, bool &optionLoop, int &choice, bool &programEnd, int &counter)
{
	//https://stackoverflow.com/questions/7719978/finding-max-value-in-an-array
	system("cls");

	int maxNum = 0;									// number for max age to be stored in
	int personNumber = 0;							// the number of the employee to be displayed


	for (counter = 0; counter < rowCount; counter++)
	{
		if (people[counter].getAge(people, counter) > maxNum)
		{
			maxNum = people[counter].getAge(people, counter);
			personNumber = counter;
		}

	}

	cout << "Oldest Employee in the Company\n";
	cout << "==============================\n";
	cout << people[personNumber].getlName(people, personNumber) << ", " << people[personNumber].getfName(people, personNumber)
		<< " " << people[personNumber].getMiddleInit(people, personNumber) << ". \n";
	cout << "Age: " << people[personNumber].getAge(people, personNumber);
	cout << "\n";

	optionLoopFunc(optionLoop, choice, programEnd);

}


void displayAllEmployees(info *people, int &rowCount, bool optionLoop, int &choice, bool &programEnd, int &counter)
{
	system("cls");

	for (counter = 0; counter < rowCount; counter++)
	{
		people[counter].getAllInfo(people, counter);
	}

	optionLoopFunc(optionLoop, choice, programEnd);
}



void optionDecide(info *people, int &rowCount, bool optionLoop, int &choice, string fillerCin, bool &programEnd, int &counter)
{
	if (choice == 1)
	{
		displayAllEmployees(people, rowCount, optionLoop, choice, programEnd, counter);
	}

	if (choice == 2)
	{
		oldestEmployee(people, rowCount, optionLoop, choice, programEnd, counter);
	}
	if (choice == 3)
	{
		displayCompBldFlr(people, rowCount, optionLoop, choice, programEnd, counter);
	}
	if (choice == 4)
	{
		displayDeptsBldA(people, rowCount, optionLoop, choice, programEnd, counter);
	}
	if (choice == 5)
	{
		findEmployee(people, rowCount, optionLoop, choice, programEnd, counter);
	}
	if (choice == 6)
	{
		avgAgeMichEmployee(people, rowCount, optionLoop, choice, programEnd, counter);
	}

	if (choice == -999)
	{
		programEnd = true;
	}

	if (choice < 1 || choice > 6)
	{
		if (choice != 99 && choice != -999)
		{
			system("cls");
			cout << "That selection is invalid.\n";
			screenPseudoPause(fillerCin);
		}
	}
}


void startMenu(info *people, int &rowCount, int &choice, string fillerCin, bool optionLoop, bool &programEnd, int &counter)
{
	while (!programEnd)
	{
		system("cls");
		cout << "EMPLOYEE INFORMATION: WHATEVER COMPANY INC.\n";
		cout << "==================================================\n";
		cout << "1. Display all employees\n";
		cout << "2. Display name of oldest employee\n";
		cout << "3. Display the building letter and floor for Computer Science department\n";
		cout << "4. Display department names who are in building A\n";
		cout << "5. Find an employee and display their information\n";
		cout << "6. Find the average age of all employees who live in Michigan\n";
		cout << "99. Return to menu\n";
		cout << "-999. Exit the program\n";
		cout << "Enter your selection: ";
		cin >> choice;
		optionDecide(people, rowCount, optionLoop, choice, fillerCin, programEnd, counter);
	}
}


int main()
{
	string templine;										// used to determine the row count
	string fillerCin;
	int rowCount = 1;										// text file will have at least one data row in default
	int choice = 0;
	int counter = 0;
	bool programEnd = false;
	bool optionLoop = true;

	getRowCount(templine, rowCount);

	info *people = new info[rowCount];						// dynamic array


	people[counter].setAllInfo(people, counter, infile, rowCount);


	startMenu(people, rowCount, choice, fillerCin, optionLoop, programEnd, counter);


	system("pause");
	return 0;
}

