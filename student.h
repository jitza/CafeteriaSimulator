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

#ifndef FINAL_PROJECT_STUDENT_H
#define FINAL_PROJECT_STUDENT_H


#include <iostream>
#include<iomanip>
using namespace std;
#include <fstream>
#include<string>

//Jenny/Nain

class Student {

public:

    Student(char*,char*,int,char*,char*);
    Student();
    Student(const Student&);
    ~Student();

    Student SetStudentName(char*);
    char* getStudentName();
    void SetSchoolName(const char*);
    char* getSchoolName();
    void SetOuncesSalad(int);
    int getOuncesSalad();
    void SetEntreeName(char*);
    char* getEntreeName();
    void SetDessertName(char*);
    char* getDessertName();

    //Overloading operators
    friend ostream& operator << (ostream& out, const Student& );//cout
    friend istream& operator >> (istream& in,  Student& );//cin
    friend fstream& operator >> (fstream& Fin, Student& s);
    Student& operator =(const Student&s);
    bool operator <(const Student& s); //had to remove Student::
    bool operator >(const Student& s);
    bool operator ==(const Student& s);


private:


    char StudentName[35];
    char SchoolName[30];
    int OuncesSalad;
    char EntreeName[15];
    char DessertName[20];
};





//------------------------------------FUNCTION DEFINITIONS------------------------------------------------


#include <string.h>



Student::Student(char * StudentNPtr, char * SchoolNPtr, int OuncesPtr, char * EntreePtr, char * DessertPtr) {

    SetStudentName(StudentNPtr);
    SetSchoolName(SchoolNPtr);
    SetOuncesSalad(OuncesPtr);
    SetEntreeName(EntreePtr);
    SetDessertName(DessertPtr);
}



//--------------------------------------------------------------------------------------------
Student::Student() {

}



//--------------------------------------------------------------------------------------------
Student::Student(const Student & stuObj) {

 strcpy(StudentName,stuObj.StudentName);
 strcpy(StudentName,stuObj.SchoolName);
 OuncesSalad = stuObj.OuncesSalad;
 strcpy(StudentName,stuObj.EntreeName);
 strcpy(StudentName,stuObj.DessertName);

}


//--------------------------------------------------------------------------------------------
Student::~Student() {

}



//--------------------------------------------------------------------------------------------
Student Student::SetStudentName(char * StuName) {

    strcpy(StudentName,StuName); //Copies string into the array
}


//--------------------------------------------------------------------------------------------
char *Student::getStudentName() {

     return StudentName;
}


//--------------------------------------------------------------------------------------------
void Student::SetSchoolName(const char * schoName) {

    strcpy(SchoolName,schoName);//Copies string into the array

}


//--------------------------------------------------------------------------------------------
char *Student::getSchoolName() {
    return SchoolName;
}


//--------------------------------------------------------------------------------------------
void Student::SetOuncesSalad(int ounces) {
    OuncesSalad=ounces; //Assigning the value to another variable

}


//--------------------------------------------------------------------------------------------
int Student::getOuncesSalad() {
    return OuncesSalad;
}


//--------------------------------------------------------------------------------------------
void Student::SetEntreeName(char * entreeName) {

    strcpy(EntreeName,entreeName); //Copies string into the array
}


//--------------------------------------------------------------------------------------------
char *Student::getEntreeName() {
    return EntreeName;
}


//--------------------------------------------------------------------------------------------
void Student::SetDessertName(char * dessertName) {

    strcpy(DessertName,dessertName); //Copies string into the array
}


//--------------------------------------------------------------------------------------------
char *Student::getDessertName() {
    return DessertName;
}




//--------------------------------------------------------------------------------------------
//overloaded operarator for when you try to print the class object
ostream &operator<<(ostream &out, const Student & student) {
    //Printing all class member variables all at once.
    // The left operand is the std::cout object and the right operand is the class object.

      float bill;
      bill = student.OuncesSalad * 1.50;

      if (strcmp(student.EntreeName, "Chicken") ==0)
          bill += 4.75;
      else if (strcmp(student.EntreeName, "Fishsticks") ==0)
          bill += 4.00;
      else if (strcmp(student.EntreeName, "Lasagna") ==0)
          bill += 3.75;

      if (strcmp(student.DessertName, "Pudding") ==0)
          bill += 1.25;
      else if (strcmp(student.DessertName, "Cheesecake") ==0)
          bill += 2.50;



    out<<student.StudentName<<": $"
      <<fixed<<setprecision(2)<<bill<<endl;
    return out;
}




//--------------------------------------------------------------------------------------------
istream &operator>>(istream &in, Student & student) {
    //Accepting user's input and assigning it to the class member variables
    char Student, School,Entree,Dessert;
    int ounce = 0;

    cout<<"Enter full name : ";
    in>>Student;
    cout<<endl;
    cout<<"Enter School Name : ";
    in>>School;
    cout<<endl;
    cout<<"Enter Entree Name : ";
    in>>Entree;
    cout<<endl;
    cout<<" Enter Dessert Name : ";
    in>>Dessert;
    cout<<endl;
    cout<<" Enter Ounce of salad : ";
    in>>ounce;
    cout<<endl;

    student.SetStudentName(reinterpret_cast<char *>(Student)); //convert to char pointer
    student.SetSchoolName(reinterpret_cast<const char *>(School));
    student.SetEntreeName(reinterpret_cast<char *>(Entree));
    student.SetDessertName(reinterpret_cast<char *>(Dessert));
    student.SetOuncesSalad(ounce);

    return in;

}




//--------------------------------------------------------------------------------------------
fstream &operator>>(fstream &Fin, Student &s) {

    Fin >>s.StudentName>>s.SchoolName>>
           s.OuncesSalad >>s.EntreeName>>s.DessertName;
       return Fin;
}




//--------------------------------------------------------------------------------------------
//overloaded operator for assigning/initializing the object
Student &Student::operator=(const Student & s) {

    //    char * pt = (char*)(s.StudentName);
    this->SetStudentName((char*)(s.StudentName));
    this->SetSchoolName(s.SchoolName);
    this->SetEntreeName((char*)(s.EntreeName));
    this->SetDessertName((char*)(s.DessertName));
    this->SetOuncesSalad(s.OuncesSalad);

    return *this;

}




//--------------------------------------------------------------------------------------------
//overloaded operator for performing less than(<) operation on the object
bool Student::operator<(const Student &s) {
    //comparing the variables
    if( StudentName < s.StudentName )
        return true;
    else
        return false;
}




//--------------------------------------------------------------------------------------------
//overloaded operator for performing a greater than(>) operation on the object
bool Student::operator>(const Student &s) {
    if( StudentName > s.StudentName )
        return true;
    return false;
}




//--------------------------------------------------------------------------------------------
//overloaded operator for performing equal to(==) operations on the object
bool Student::operator==(const Student &s) {
    if( StudentName == s.StudentName)
        return true;
    return false;
}




#endif //FINAL_PROJECT_STUDENT_H
