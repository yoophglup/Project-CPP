#pragma once
#include "student.h"

const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Chad,Self,cself3@wgu.edu,40,12,13,30,SOFTWARE" };
const int numofdata = sizeof(studentData) / sizeof(studentData[0]);



class Roster
{
	int rosterCount = 0;
	//Create an array of pointers, classRosterArray
	Student* classRosterArray[numofdata+1] = { new Student,new Student,new Student,new Student,new Student,new Student };
public:
	Roster();
	~Roster();
	Student pclassRosterArray(int z);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	int get_count();
};
