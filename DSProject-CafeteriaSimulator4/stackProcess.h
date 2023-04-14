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


#ifndef GROUP_4_EXAM_FINAL_PROJECT_QUEUE_H
#define GROUP_4_EXAM_FINAL_PROJECT_QUEUE_H
#include "stack.h"
#include<queue>

class stackProcess
{
public:
    stackProcess();
    void traySelection(string school);
private:
    Stack st1_;
    Stack st2_;
};





//------------------------------------FUNCTION DEFINITIONS------------------------------------------------


stackProcess::stackProcess()
{

}


//--------------------------------------------------------------------------------------------
void stackProcess::traySelection(string school) {

    //-----------------------------------------------------------------------------------------------------
    if(school == "Eastville"){ //Eastville, whose colors are blue and yellow
        do { if (st1_.color() == "blue" || st1_.color() == "yellow") {
                st1_.pop();
                return;}
            else {
                st2_.push(st1_.color());
                st1_.pop();}
        }while(st1_.top != -1);

        do {if (st2_.color() == "blue" || st2_.color() == "yellow") {
                st2_.pop();
                return;}
            else {
                st1_.push(st2_.color());
                st2_.pop();}
        }while(st2_.top != -1);
        st1_.pop();
        return;
    }

    //-----------------------------------------------------------------------------------------------------
    else if(school == "Westburg"){ //Westburg, whose colors are red and green
        do { if (st1_.color() == "red" || st1_.color() == "green") {
            st1_.pop();
            return;}
            else {
                st2_.push(st1_.color());
                st1_.pop();}
        }while(st1_.top != -1);

        do {if (st2_.color() == "red" || st2_.color() == "green") {
            st2_.pop();
            return;}
            else {
                st1_.push(st2_.color());
                st2_.pop();}
        }while(st2_.top != -1);

        st1_.pop();
        return;
    }

    //-----------------------------------------------------------------------------------------------------
    else if(school == "Northton"){ //Northton, whose colors are orange and purple;
        do { if (st1_.color() == "orange" || st1_.color() == "purple") {
            st1_.pop();
            return;}
            else {
                st2_.push(st1_.color());
                st1_.pop();}
        }while(st1_.top != -1);

        do {if (st2_.color() == "orange" || st2_.color() == "purple") {
            st2_.pop();
            return;}
            else {
                st1_.push(st2_.color());
                st2_.pop();}
        }while(st2_.top != -1);

        st1_.pop();
        return;
    }

    //-----------------------------------------------------------------------------------------------------
    else if(school == "Southport"){ //Southport, whose colors are orange and blue;
        do { if (st1_.color() == "orange" || st1_.color() == "blue") {
            st1_.pop();
            return;}
            else {
                st2_.push(st1_.color());
                st1_.pop();}
        }while(st1_.top != -1);

        do {if (st2_.color() == "orange" || st2_.color() == "blue") {
            st2_.pop();
            return;}
            else {
                st1_.push(st2_.color());
                st2_.pop();}
        }while(st2_.top != -1);

        st1_.pop();
        return;
    }

    //-----------------------------------------------------------------------------------------------------
    if(school == "Jahunga"){ //Jahunga, whose colors are red and blue;
        do { if (st1_.color() == "red" || st1_.color() == "blue") {
            st1_.pop();
            return;}
            else {
                st2_.push(st1_.color());
                st1_.pop();}
        }while(st1_.top != -1);

        do {if (st2_.color() == "red" || st2_.color() == "blue") {
            st2_.pop();
            return;}
            else {
                st1_.push(st2_.color());
                st2_.pop();}
        }while(st2_.top != -1);

        st1_.pop();
        return;
    }

    //-----------------------------------------------------------------------------------------------------
    else if(school == "Aruba"){ //Aruba, whose colors are yellow and green.
        do { if (st1_.color() == "yellow" || st1_.color() == "green") {
            st1_.pop();
            return;}
            else {
                st2_.push(st1_.color());
                st1_.pop();}
        }while(st1_.top != -1);

        do {if (st2_.color() == "yellow" || st2_.color() == "green") {
            st2_.pop();
            return;}
            else {
                st1_.push(st2_.color());
                st2_.pop();}
        }while(st2_.top != -1);

        st1_.pop();
        return;
    }



}


#endif //GROUP_4_EXAM_FINAL_PROJECT_QUEUE_H

