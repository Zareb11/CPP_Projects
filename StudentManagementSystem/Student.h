
#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

class Student {
    public:
        string Name;
        int StudentNo;
        string DegreeMajor;
        list<string> Subjects;
        map<string, list<float>> SubjectMarks;

        void print_subjects(){
            for(auto subject:Subjects)
            {
                cout << subject << "\n";
            }
        }
        Student(string name, int studentNo, string degreeMajor, list<string> subjects, map<string, list<float>> subjectMarks)
        {
            Name = name;
            StudentNo = studentNo;
            DegreeMajor = degreeMajor;
            Subjects = subjects;
            SubjectMarks = subjectMarks;
        }
        void calculate_ave_subjects(){
            
            for(auto subject: SubjectMarks)
            {   
                float mark_ave = 0;
                cout << subject.first;
                for(auto mark: subject.second)
                {
                    mark_ave = mark_ave + mark;
                }
                cout << " - " << mark_ave/subject.second.size() << endl;
            }
            //cout << "-------------------" << endl;
        }
        string getName(){
            return Name;
        }
        int getStudentNo(){
            return StudentNo;
        }
        string getDegreeMajor(){
            return DegreeMajor;
        }
        list<string> getSubjects(){
            return Subjects;
        }
        
};