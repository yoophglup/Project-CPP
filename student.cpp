#include "student.h"

    //Constructor
    Student::Student()    {
        id="??";
        fName="????";
        lName="??????";
        email="?????????@?????.???";
	    age = -1;
	    daysLeft[0] = -1;
	    daysLeft[1] = -1;
	    daysLeft[2] = -1;
	    degreeprogram = DegreeProgram::SECURITY;
    }
    // Accessors
    string Student::get_id() const { return id; }
    string Student::get_firstName() { return fName; }
    string Student::get_lastName() { return lName; }
    string Student::get_email() { return email; }
    int Student::get_age() { return age; }
    int Student::get_daysLeft(int x) { return daysLeft[x]; }
    DegreeProgram Student::get_degProgram() { return  degreeprogram; }
    // Mutators
    void Student::set_id(string newID) { id = newID; }
    void Student::set_firstName(string newfirstName) { fName = newfirstName; }
    void Student::set_lastName(string newlastName) { lName = newlastName; }
    void Student::set_email(string newemail) { email = newemail; }
    void Student::set_age(int newage) { age = newage; }
    void Student::set_daysleft(int x, int newdaysLeft) { daysLeft[x] = newdaysLeft; }
    void Student::set_degProgram(DegreeProgram newdegree) { degreeprogram = newdegree; }
    //Print Functions
    string Student::emuntostring(DegreeProgram degreeVariable) {
        switch (degreeVariable) {
        case DegreeProgram::NETWORK:
            return "Network";
        case DegreeProgram::SECURITY:
            return "Security";
        case DegreeProgram::SOFTWARE:
            return "Software";
        }
        return "NULL";

    }
    void Student::print() {
        cout << id <<"\t" <<"First Name : " << fName << "\t" << "Last Name : " << lName << "\t" << "Age : " << age << "\t" << "daysInCourse : {" << daysLeft[0] << ", " << daysLeft[1] << ", " << daysLeft[2] << "} " << "Degree Program : " << emuntostring(degreeprogram) << endl;
    }


