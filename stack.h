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


#ifndef GROUP_4_EXAM_FINAL_PROJECT_STACK_H
#define GROUP_4_EXAM_FINAL_PROJECT_STACK_H
#include "iostream"

using namespace std;


class Stack {
public:
    Stack();
    void push( string );
    void pop();
    string color();
    int top=0;

private:
    string tray_[60];

};




//------------------------------------FUNCTION DEFINITIONS------------------------------------------------

Stack::Stack() {
    for(; top < 5; top++){
        tray_[top] = "red";
    }
    for(; top < 10; top++) {
        tray_[top] = "green";
    }
    for(; top < 15; top++) {
        tray_[top] = "blue";
    }
    for(; top < 20; top++) {
        tray_[top] = "yellow";
    }
    for(; top < 25; top++) {
        tray_[top] = "orange";
    }
    for(; top < 30; top++) {
        tray_[top] = "purple";
    }

    for(int c = 0; c < 30; c++)
    {
        int r = rand() % 30; //creates a random number under 30
        string tem = tray_[c]; //stores the tray in location c in variable tem
        tray_[c] = tray_[r]; //takes a tray from a random position in the stack and puts in in position c
        tray_[r] = tem; //takes the tray that was originally in location c and puts it where the random tray was
    }
}




//--------------------------------------------------------------------------------------------
void Stack::push( string value) {
    if(top >= 60)
        cout <<"Tray Full"<<endl;
    else{
        top++;
        tray_[top] = value;
    }
}




//--------------------------------------------------------------------------------------------
void Stack::pop() {
    if(top <= -1)
        cout <<"Tray Empty"<<endl;
    else{
        tray_[top] = "";
        top--;
    }
}



//--------------------------------------------------------------------------------------------
string Stack::color() {
    return tray_[top];
}

#endif //GROUP_4_EXAM_FINAL_PROJECT_STACK_H
