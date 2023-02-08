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

// TREENODE.H
// Definition of class TreeNode
#ifndef TREENODE_H
#define TREENODE_H

template< class T > class Tree;    // forward declaration

template< class NODETYPE >
class TreeNode {
   friend class Tree< NODETYPE >;
public:
   TreeNode( const NODETYPE & );  // constructor
   NODETYPE getData() const;      // return data
   TreeNode *getLeftPtr() const { return leftPtr; }
   TreeNode *getRightPtr() const { return rightPtr; }
   void setLeftPtr( TreeNode *ptr ) { leftPtr = ptr; }
   void setRightPtr( TreeNode *ptr ) { rightPtr = ptr; }
private:
   TreeNode *leftPtr;   // pointer to left subtree
   NODETYPE data;
   TreeNode *rightPtr;  // pointer to right subtree
};



//--------------------------------------------------------------------------------------------
// Constructor
template< class NODETYPE >
TreeNode< NODETYPE >::TreeNode( const NODETYPE &d )
{
   data = d;
   leftPtr = rightPtr = 0;
}



//--------------------------------------------------------------------------------------------
//Return a copy of the data value
template< class NODETYPE >
NODETYPE TreeNode< NODETYPE >::getData() const { return data; }



#endif
