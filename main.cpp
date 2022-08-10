#include "roster.h"
using namespace std;

int main() {
    cout << "-------------------------------------------------------------- " << endl;
    cout << "Course Title : Scripting and Programming - Applications - C867 " << endl;
    cout << "Language Used: C++" << endl;
    cout << "Student ID   : 000430387 " << endl;
    cout << "Student Name : Chad Self " << endl;
    cout << "-------------------------------------------------------------- " << endl;

    Roster classRoster;
    classRoster.printAll();
    classRoster.printInvalidEmails();

    cout << endl << "Student Id: Average days left " << endl;
    for (int z = 0; z < classRoster.get_count(); z++) {
        cout << classRoster.pclassRosterArray(z).get_id() << ": ";
        classRoster.printAverageDaysInCourse(classRoster.pclassRosterArray(z).get_id());
    }

    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}

