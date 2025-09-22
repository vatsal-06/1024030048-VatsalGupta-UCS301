#include <iostream>
using namespace std;

class Company {
    protected:
        string companyName;
        string location;

    public:
        Company(string companyName, string location) {
            companyName = companyName;
            location = location;
        }

        void displayCompany() {
            cout << "Company Name: " << companyName << endl;
            cout << "Location: " << location << endl;
        }
};

class Team : public Company {
    protected:
        string teamName;
        string project;

    public:
        Team(string companyName, string location, string tname, string proj) : Company(companyName, location) {
            teamName = tname;
            project = proj;
        }

        void displayTeam() {
            cout << "Team Name: " << teamName << endl;
            cout << "Project: " << project << endl;
        }
};

class Developer : public Team {
    private:
        string developerName;
        string programmingLanguage;

    public:
        Developer(string companyName, string location, string teamName, string project, string devName, string progLang) : Team(companyName, location, teamName, project) {
            developerName = devName;
            programmingLanguage = progLang;
        }

        void displayDeveloper() {
            cout << "Developer Name: " << developerName << endl;
            cout << "Programming Language: " << programmingLanguage << endl;
        }

        void displayAll() {
            cout << "----Company Details----" << endl;
            displayCompany();
            cout << "----Team Details----" << endl;
            displayTeam();
            cout << "----Developer Details----" << endl;
            displayDeveloper();
        }
};

int main() {
    Developer dev("TechCorp", "Agra", "PatialaPeg", "SIH2025", "Anshika Mangal", "Flutter/Dart");
    dev.displayAll();

    return 0;
}