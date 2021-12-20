#pragma once
#include <iostream>
#include <string>


using namespace std;



class info
{
private:
	string ssn, fName, lName, middleIniti;
	string city, state;
	int age;
	string gender;
	int deptID;
	string deptName, buildingLet;
	int buildingFlr;
	string phoneNum;
public:
	void setAllInfo(info *, int, ifstream &, int);
	void getAllInfo(info *, int);
	string getSSN(info *, int);
	string getfName(info *, int);
	string getlName(info *, int);
	string getMiddleInit(info *, int);
	int getAge(info *, int);
	string getCity(info *, int);
	string getState(info *, int);
	int getDeptID(info *, int);
	string getBuildingLet(info *, int);
	string getDeptName(info *, int);
	int getBuildingFlr(info *, int);
	string getPhoneNum(info *, int);
	info();
	~info();

};



