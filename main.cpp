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


#include <iostream>
#include<iomanip>
#include<string>
#include <string.h>
#include<sstream>
#include <fstream>
#include<queue>

using namespace std;

#include "School.h"
#include "Student.h"
#include "stack.h"
#include"stackProcess.h"
#include"TREENODE.h"




int main()
{


    int nOfrec = 20;

    int seed;
    int ounces;
    char  name[ 20 ], university [ 20 ], entree [ 15 ], dessert[ 15 ];//used to store the data being read from the file
    Student * studL= new Student[nOfrec];//our student objects that we will fill with data from the file
    int i =0; //counter for our loop as well as for our array of student objects


    fstream inFile("Students.txt", ios::in);
    if(!inFile) {
        cout<<"Could not open the file."<<endl;
        exit(0);
    }
    else
    {   //putting the seed somewhere so it does not interfer with data collection
        inFile>>seed;
        // loop grabs the 20 records from our file and stores them in our student objects
        do
        {
            inFile >> name;
            inFile >> university;
            inFile >> ounces;
            inFile >> entree;
            inFile >> dessert;

//            cout<<name<<endl;
//            cout<<university<<endl;
//            cout<<ounces<<endl;
//            cout<<entree<<endl;
//            cout<<dessert<<endl;

            //putting the data we read from the file into our student objects
            studL[i].SetStudentName(name); studL[i].SetSchoolName(university);
            studL[i].SetOuncesSalad(ounces); studL[i].SetEntreeName(entree);
            studL[i].SetDessertName(dessert);

            ++i;

        }while(i< nOfrec );
    }
    inFile.close();
    cout<<endl<<"----------------------------------------------------------"<<endl<<endl;




   // Queue implementation

    //creating 2 queues
    queue<Student> Q1, Q2;

    //inserting student objects into the queue based on program description
    for(i=0; i < nOfrec ;i++)
    {
        if(Q1.empty() || Q1.size() < Q2.size())
            Q1.push(studL[i]);

        else if(Q2.empty() || Q2.size() < Q1.size())
            Q2.push(studL[i]);

        else
        {
            int r = rand() % 2;
            if(r == 0)
                Q1.push(studL[i]);
            else
                Q2.push(studL[i]);
        }
    }



    //creating 2 stackProcess functions for each of the queues to handle the processing for the stacks
    //stackProcess creates 2 stacks for each of the lines and contains the logic that determines how a
    //stundent chooses their tray
    stackProcess Queue1, Queue2;

    while(!Q1.empty()){

        string sn =""; //create an empty string
        sn.append(Q1.front().getSchoolName()); //append the student's school name onto it
        Queue1.traySelection(sn); //pass the school name to the tray selection function
        Q1.pop(); //remove student from queue after they have gotten their tray
    }

    while(!Q2.empty()){

        string sn =""; //create an empty string
        sn.append(Q2.front().getSchoolName()); //append the student's school name onto it
        Queue2.traySelection(sn); //pass the school name to the tray selection function
        Q2.pop(); //remove student from queue after they have gotten their tray
    }






    //School class implimentation
    //assigning the names of the schools to char arrays
    char East[] = "Eastville"; char West[]= "Westburg";
    char North[] = "Northton"; char South[]="Southport";
    char Jah[]= "Jahunga"; char Pod[] ="Podunk";

    //creating the school objects and passing the char arrays we previously created to initialize them
    School Eastville (East);
    School Westburg (West);
    School Northton (North);
    School Southport (South);
    School Jahunga (Jah);
    School Podunk(Pod);


    //inserting the student objects into their respective school objects this is done by comparing the
    //school name in the student object to the school name in the school object. If the name match
    //the student object is added to the school object's student tree
    for (i=0; i < nOfrec;i++)
    {
        if(strcmp(studL[i].getSchoolName(), Eastville.getSchoolName())==0)
            Eastville.addStudent(studL[i]);

        else if(strcmp(studL[i].getSchoolName(), Westburg.getSchoolName())==0)
            Westburg.addStudent(studL[i]);

        else if(strcmp(studL[i].getSchoolName(), Northton.getSchoolName())==0)
            Northton.addStudent(studL[i]);

        else if(strcmp(studL[i].getSchoolName(), Southport.getSchoolName())==0)
            Southport.addStudent(studL[i]);

        else if(strcmp(studL[i].getSchoolName(), Jahunga.getSchoolName())==0)
            Jahunga.addStudent(studL[i]);

        else if(strcmp(studL[i].getSchoolName(), Podunk.getSchoolName())==0)
            Podunk.addStudent(studL[i]);
    }



    //printing out the school name and the names of the individual students in alphabetical order
    //along with their individulal bills.

    cout<<"University of "<<Eastville.getSchoolName()<<endl;
    cout<<" "; Eastville.printStudentBody();
    cout<<"Total: "<<Eastville.getBill()<<endl<<endl<<endl; //prints the total bill of the school


    cout<<"University of "<<Jahunga.getSchoolName()<<endl;
    cout<<" "; Jahunga.printStudentBody();
    cout<<"Total: $"<<Jahunga.getBill()<<endl<<endl<<endl;

    cout<<"University of "<<Northton.getSchoolName()<<endl;
    cout<<" "; Northton.printStudentBody();
    cout<<"Total: $"<<Northton.getBill()<<endl<<endl<<endl;

    cout<<"University of "<<Podunk.getSchoolName()<<endl;
    cout<<" "; Podunk.printStudentBody();
    cout<<"Total: $"<<Podunk.getBill()<<endl<<endl<<endl;

    cout<<"University of "<<Southport.getSchoolName()<<endl;
    cout<<" "; Southport.printStudentBody();
    cout<<"Total: $"<<Southport.getBill()<<endl<<endl<<endl;

    cout<<"University of "<<Westburg.getSchoolName()<<endl;
    cout<<" "; Westburg.printStudentBody();
    cout<<"Total: $"<<Westburg.getBill()<<endl<<endl<<endl;



    return 0;
}
