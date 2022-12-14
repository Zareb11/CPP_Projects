#include <iostream>
#include <string>
#include <list>
#include <map>
#include "Student.h"

using namespace std;



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

void print_all_students_information(Node *head){
    Node* iterator = head;
    while(iterator != nullptr)
    {
        cout << "Name - " << iterator->student->Name << endl;
        cout << "Major - " << iterator->student->DegreeMajor << endl;
        cout << "Grade averages:  " << endl;
        iterator->student->calculate_ave_subjects();
        iterator = iterator->next;
        cout << "-------------" << endl;
    }
}



int main()
{
    list<string> subjects = {"Computer Science", "Physics", "Mathematics"};
    list<float> cs_marks { 47, 51, 67, 72, 87 };
    list<float> math_marks { 67, 70, 81, 44, 41 };
    list<float> phy_marks { 31, 61, 57, 79, 59 };
    map<string, list<float>> subject_marks;
    subject_marks.insert(pair<string, list<float>>("Computer Science", cs_marks));
    subject_marks.insert(pair<string, list<float>>("Mathematics", math_marks));
    subject_marks.insert(pair<string, list<float>>("Physics", phy_marks));
    Student student1 = Student("Jacob Witbooi", 3579072, "Computer Science", subjects, subject_marks);
    //---------------------------------------------------------------------------------------------
    list<string> subjects2 = {"Accounting", "Economics", "Commericial Law"};
    list<float> acc_marks { 77, 79, 67, 71, 74 };
    list<float> eco_marks { 67, 72, 81, 88, 80 };
    list<float> cl_marks { 64, 71, 63, 73, 61 };
    map<string, list<float>> subject_marks2;
    subject_marks2.insert(pair<string, list<float>>("Accounting", cs_marks));
    subject_marks2.insert(pair<string, list<float>>("Economics", math_marks));
    subject_marks2.insert(pair<string, list<float>>("Commericial Law", phy_marks));
    Student student2 = Student("Godwinn Isaacs", 3579072, "Accounting", subjects2, subject_marks2);
    Node* head = new Node();
    Node* tail = new Node();
    //---------------------------------------------------------------------------------------------
    Node* node = new Node();
    node->student = &student1;
    node->next = nullptr;
    node->prev = nullptr;
    head = node;
    tail = node;
    //preorderPrint(head);
    //---------------------------------------------------------------------------------------------
    node = new Node();
    node->student = &student2;
    node->next = nullptr;
    node->prev = tail;
    tail->next = node;
    tail = node;
    print_all_students_information(head);

    return 0;
}