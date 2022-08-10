#pragma once
#include "degree.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;


class Student
{
    string id;
    string fName;
    string lName;
    string email;
    int age = 0;
    int daysLeft[3] = { 0, 0, 0 };
    DegreeProgram degreeprogram;
public:
    //Constructor Header
    Student();
    // Accessors Headers
    string get_id() const;
    string get_firstName();
    string get_lastName();
    string get_email();
    int get_age();
    int get_daysLeft(int x);
    DegreeProgram get_degProgram();
    // Mutators Headers
    void set_id(string newID);
    void set_firstName(string newfirstName);
    void set_lastName(string newlastName);
    void set_email(string newemail);
    void set_age(int newage);
    void set_daysleft(int x, int newdaysLeft);
    void set_degProgram(DegreeProgram newdegree);
    //print functions
    string emuntostring(DegreeProgram degreeVariable);
    void print();
};