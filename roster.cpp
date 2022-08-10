#include "roster.h"
#include "student.h"


//add data to Roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
    Roster::classRosterArray[rosterCount]->set_id(studentID);
    Roster::classRosterArray[rosterCount]->set_firstName(firstName);
    Roster::classRosterArray[rosterCount]->set_lastName(lastName);
    Roster::classRosterArray[rosterCount]->set_email(emailAddress);
    Roster::classRosterArray[rosterCount]->set_age(age);
    Roster::classRosterArray[rosterCount]->set_daysleft(0, daysInCourse1);
    Roster::classRosterArray[rosterCount]->set_daysleft(1, daysInCourse2);
    Roster::classRosterArray[rosterCount]->set_daysleft(2, daysInCourse3);
    Roster::classRosterArray[rosterCount]->set_degProgram(degreeprogram);
    Roster::rosterCount = Roster::rosterCount + 1;

}



//constructor and  parse data

Roster::Roster() {
    Roster::rosterCount = 0;
    for (int hx = 0; hx < 10; hx++) {
       
    }
    string parsed_studentID, parsed_firstName, parsed_lastName, parsed_emailAddress, parsed_sage, parsed_sdaysInCourse1, parsed_sdaysInCourse2, parsed_sdaysInCourse3, parsed_sDegreeProgram;
    DegreeProgram parsed_DegreeProgram=DegreeProgram::NETWORK;
    int parsed_age, parsed_daysInCourse1, parsed_daysInCourse2, parsed_daysInCourse3;
    for (int z = 0; z <= numofdata - 1; z++) {
        istringstream ss(studentData[z]);
        //read each data field as a line seperated by commas into a string 
        getline(ss, parsed_studentID, ',');
        getline(ss, parsed_firstName, ',');
        getline(ss, parsed_lastName, ',');
        getline(ss, parsed_emailAddress, ',');
        getline(ss, parsed_sage, ',');
        getline(ss, parsed_sdaysInCourse1, ',');
        getline(ss, parsed_sdaysInCourse2, ',');
        getline(ss, parsed_sdaysInCourse3, ',');
        getline(ss, parsed_sDegreeProgram, ',');
        //convert strings into required integers
        stringstream ss1(parsed_sage);
        ss1 >> parsed_age;
        stringstream ss2(parsed_sdaysInCourse1);
        ss2 >> parsed_daysInCourse1;
        stringstream ss3(parsed_sdaysInCourse2);
        ss3 >> parsed_daysInCourse2;
        stringstream ss4(parsed_sdaysInCourse3);
        ss4 >> parsed_daysInCourse3;
        //set enum types to appropriate values
        if (parsed_sDegreeProgram == "SOFTWARE") parsed_DegreeProgram = DegreeProgram::SOFTWARE;
        else if (parsed_sDegreeProgram == "NETWORK") parsed_DegreeProgram = DegreeProgram::NETWORK;
        else if (parsed_sDegreeProgram == "SECURITY") parsed_DegreeProgram = DegreeProgram::SECURITY;
        //save this entry
        add(parsed_studentID, parsed_firstName, parsed_lastName, parsed_emailAddress, parsed_age, parsed_daysInCourse1, parsed_daysInCourse2, parsed_daysInCourse3, parsed_DegreeProgram);
    }

}
//destructor
Roster::~Roster() {
    int numofelements = sizeof(*classRosterArray) / sizeof(*classRosterArray[0]);
    for (int d = 0; d < numofelements; d++) {
        delete classRosterArray[d];
    }

}

//remove data from roster
void Roster::remove(string studentID) {
    //cout << studentID;
    bool found = false;
    for (int rx = 0; rx < Roster::rosterCount; rx++) {
        if (Roster::classRosterArray[rx]->get_id() == studentID) {
            for (int ry = rx; ry < Roster::rosterCount; ry++) {
                Roster::classRosterArray[ry] = Roster::classRosterArray[ry + 1];
            }
            cout << studentID << " has been removed." << endl;
            Roster::rosterCount = Roster::rosterCount - 1;
            found = true;
        }
        
    }
    if (!found) {
        cout << "No Record Found Found " << studentID << endl;
    }
}



//print all data from Roster
void Roster::printAll(){
    cout << "Print tab-separated list of student data :" << endl;
    for (int y = 0; y < Roster::rosterCount; y++) {
        Roster::classRosterArray[y]->print();
    }

}



//allow public roster access 
Student Roster::pclassRosterArray(int z) {
    return *classRosterArray[z];
};

//print the average days a student has remaining in their courses
void Roster::printAverageDaysInCourse(string studentID){
    int sum=0;
    double avg=0.0;
    for (int y = 0; y < Roster::rosterCount; y++) {
        if ( studentID == Roster::classRosterArray[y]->get_id() ){ 
            sum=Roster::classRosterArray[y]->get_daysLeft(0) + Roster::classRosterArray[y]->get_daysLeft(2) + Roster::classRosterArray[y]->get_daysLeft(3);
            avg = sum / 3.0;
        }
    }
    cout << setprecision(2) << avg <<" " ;
}

//print all invalid e-mails
void Roster::printInvalidEmails(){
    //Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
    cout << endl << "Print All invalid Emails: " << endl;
    for (int y = 0; y < Roster::rosterCount; y++) {
            bool found1 = Roster::classRosterArray[y]->get_email().find('@') < Roster::classRosterArray[y]->get_email().length();
            bool found2 = Roster::classRosterArray[y]->get_email().find('.') < Roster::classRosterArray[y]->get_email().length();
            bool found3 = Roster::classRosterArray[y]->get_email().find(' ') < Roster::classRosterArray[y]->get_email().length();

            if ( found1 && found2 &! found3 ) {
                //cout << " valid e-mail" << Roster::classRosterArray[y].get_email() <<endl;
            }
            else {
                cout << "Student " << Roster::classRosterArray[y]->get_id() << ": INVALID e-mail " << Roster::classRosterArray[y]->get_email() << endl;
            }
    }
}

//print student data in group of their degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
    string printvariable;
    cout << endl;
        switch (degreeProgram) {
        case DegreeProgram::NETWORK:
            printvariable = "Network";
        case DegreeProgram::SECURITY:
            printvariable = "Security";
        case DegreeProgram::SOFTWARE:
            printvariable = "Software";
        }
    cout << endl << "Output by Degree Program : " << printvariable << endl;
    for (int y = 0; y < Roster::rosterCount; y++) {
        if (degreeProgram == Roster::classRosterArray[y]->get_degProgram()) {
            Roster::classRosterArray[y]->print();
                    }
    }
    cout << endl;
}

//return the number of entries in the Roster
int Roster::get_count() { return Roster::rosterCount; }