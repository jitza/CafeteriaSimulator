/*Programmers' Names: Aazan Iqbal, Nain Kevin Victorin, Talib Udeen Marin, Devan Treman Martinez
                      Jenny Emerita Itza, Alex Alonzo Guerra

  Date: November 29, 2021
  Course Code: CMPS2131
  Lecturer: Ms.La-Dene Forrester Lambey

Program Description: This program acts as simulator for the cafeteria of the University of Aruba
during lunch on a day where they are hosting a football tournament with other universities.
On this day the cafeteria is serving three different entrees, two different desserts, and salad.
The program receives the student's information and lunch choices through a file, stores them in a student
objrct, and runs them through 2 queues. They will chose the shortest line/queue if but are the same
size they choose one randomly. The student at the front of the queue will choose a tray from the 2 stacks
of trays. A student will check both stacks to get a tray that matches their one of their school colors.
If they are unable to they will choose one randomly. The student objects are then stored in a tree inside
of the school objects that represent their schools. Then the bills of the individual students and their
stundents are calculated and printed.
*/


#ifndef FINAL_PROJECT_SCHOOL_H
#define FINAL_PROJECT_SCHOOL_H


#include "Tree.h"
#include "Student.h"



class School {
public:
    School();
    School(char*);
    ~School();
    void addStudent(Student& );
    void printStudentBody();
    float getBill();
    friend ostream& operator <<(ostream&,  School& );
    char* getSchoolName();


private:
/* 	static data members belong to the class and not to a specific object of the class.  This means that there
    is only one static data member created per class, regardless of the number of objects created.
*/
    Tree<Student> studentTree;
    float totalBill;
    static const float fishsticks;
    static const float chicken;
    static const float lasagna;
    static const float cheesecake;
    static const float pudding;
    static const float salad;
    char schoolName[25];

};





//------------------------------------FUNCTION DEFINITIONS------------------------------------------------
#include <iostream>
#include <fstream>
#include<string.h>
using namespace  std;


//--------------------------------------------------------------------------------------------
School::School() {
    totalBill = 0.0;
    schoolName[0] = '\0';
}



//--------------------------------------------------------------------------------------------
School::School(char* school) {
    strcpy(schoolName,school);
}




//--------------------------------------------------------------------------------------------
School::~School() {

}




//--------------------------------------------------------------------------------------------
void School::addStudent(Student& S){

    //inserts the student into the school's student tree
    studentTree.insertNode(S);


    //calcultes the student's bill and adds it to the school's total bill
    float bill;
    bill = S.getOuncesSalad() * 1.50;

    if (strcmp(S.getEntreeName(), "Chicken") ==0)
        bill += 4.75;
    else if (strcmp(S.getEntreeName(), "Fishsticks") ==0)
        bill += 4.00;
    else if (strcmp(S.getEntreeName(), "Lasagna") ==0)
        bill += 3.75;

    if (strcmp(S.getDessertName(), "Pudding") ==0)
        bill += 1.25;
    else if (strcmp(S.getDessertName(), "Cheesecake") ==0)
        bill += 2.50;

    totalBill += bill;
}




//--------------------------------------------------------------------------------------------
void School::printStudentBody() {

    studentTree.inOrderTraversal();

}




//--------------------------------------------------------------------------------------------
float School::getBill() {

    return totalBill;
}





//--------------------------------------------------------------------------------------------
ostream &operator<<(ostream &out, School & S) {
    out<<S.schoolName;
    return out;
}





//--------------------------------------------------------------------------------------------
char *School::getSchoolName() {
    return schoolName;
}





#endif //FINAL_PROJECT_SCHOOL_H
