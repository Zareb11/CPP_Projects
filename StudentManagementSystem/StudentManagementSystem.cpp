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
        }
};


class Node {
    public:
        Student* student;
        Node* next;
        Node* prev;
};


void preorderPrint(Node * head){
    Node* traverser =  head;
    while(traverser != nullptr)
    {   
        traverser->student->calculate_ave_subjects();
        traverser = traverser->next;
    }
}



int main()
{
    //---------------------------------------------------------------------------------------------
    list<string> subjects = {"Computer Science", "Physics", "Mathematics"};
    list<float> cs_marks { 47, 51, 67, 72, 87 };
    list<float> math_marks { 67, 70, 81, 44, 41 };
    list<float> phy_marks { 31, 61, 57, 79, 59 };
    map<string, list<float>> subject_marks;
    subject_marks.insert(pair<string, list<float>>("Computer Science", cs_marks));
    subject_marks.insert(pair<string, list<float>>("Mathematics", math_marks));
    subject_marks.insert(pair<string, list<float>>("Physics", phy_marks));

    Student student1 = Student("Jacob Witbooi", 3579072, "Computer Science", subjects, subject_marks);
    //student1.print_subjects();
    //student1.calculate_ave_subjects();
    //---------------------------------------------------------------------------------------------
    Node* head;
    Node* tail;
    Node* node = new Node();
    node->student = &student1;
    node->next = nullptr;
    node->prev = nullptr;
    head = node;
    tail = node;
    preorderPrint(head);



    return 0;
}