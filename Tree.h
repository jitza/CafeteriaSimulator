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


// Definition of template class Tree
#ifndef TREE_H
#define TREE_H

#include <iostream>
using std::cout;
using std::cin;
using std::cerr;

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::ios;

#include<string>
using std::string;
#include<stdlib.h>
#include <assert.h>

#include "TREENODE.h"


template< class NODETYPE >

class Tree {
public:
   Tree();
   void insertNode(  NODETYPE & );
   void preOrderTraversal() const;
   void inOrderTraversal() const;
   void postOrderTraversal() const;
   void deleteNode(  NODETYPE & );
   TreeNode< NODETYPE > *binarySearch( NODETYPE & ) const;
   int getDepth() const;

protected:
   TreeNode< NODETYPE > *rootPtr;
private:
   // utility functions
   void insertNodeHelper(
           TreeNode< NODETYPE > **,  NODETYPE & );
   void preOrderHelper( TreeNode< NODETYPE > * ) const;
   void inOrderHelper( TreeNode< NODETYPE > * ) const;
   void postOrderHelper( TreeNode< NODETYPE > * ) const;
   void DeleteHelper( TreeNode< NODETYPE > **,  NODETYPE & );
   void FindAndDeleteMax ( TreeNode< NODETYPE > **, TreeNode< NODETYPE > ** );
   TreeNode< NODETYPE > *binarySearchHelper( TreeNode< NODETYPE > *,
                                             NODETYPE & ) const;
   void determineDepth( TreeNode< NODETYPE > *, int *, int * ) const;

};

//------------------------------------FUNCTION DEFINITIONS------------------------------------------------


using namespace std;

//--------------------------------------------------------------------------------------------
template< class NODETYPE >
int Tree< NODETYPE >::getDepth() const
{
    int totalDepth = 0, currentDepth = 0;
    determineDepth(rootPtr, &totalDepth, &currentDepth);

    return totalDepth;
}



//--------------------------------------------------------------------------------------------
template< class NODETYPE >
void Tree< NODETYPE >::determineDepth( TreeNode< NODETYPE > *ptr,
                                        int *totPtr, int *currPtr ) const
{

    if(ptr != NULL)//ptr points to a node the body of the if executes
       {
           if(ptr->getLeftPtr() != NULL)//checks if the left pointer of the node is pointing to a treenode
           {
               *currPtr=*currPtr+1;
               determineDepth(ptr->getLeftPtr(),totPtr, currPtr);//call determineDepth
           }


           if(ptr->getRightPtr() != NULL)
           {
               *currPtr=*currPtr+1; //adds 1 to the value currPtr is pointing to
               determineDepth(ptr->getRightPtr(),totPtr,currPtr);
           }//end of if


           *currPtr=*currPtr-1;//decrement by 1 when both left and right subtree is traversed
           if(*currPtr > *totPtr)//set totPtr if the currPtr is greater
           {
               *totPtr=*currPtr;//set the new level
           }//end of if

       }//end of if


}




//--------------------------------------------------------------------------------------------
template< class NODETYPE >
TreeNode< NODETYPE > *Tree< NODETYPE >::binarySearch( NODETYPE & val ) const
{

    return binarySearchHelper(rootPtr,val);

}



//--------------------------------------------------------------------------------------------
template< class NODETYPE >
TreeNode< NODETYPE > *Tree< NODETYPE >::binarySearchHelper(
                           TreeNode< NODETYPE > *ptr, NODETYPE & value ) const
{

    //your code goes here
    TreeNode<NODETYPE> *nodeToFind=0;

        if ( ptr == 0 )
            cout<<"Value not  found. \n";

        else if ( value < ptr->getData()  )
            nodeToFind= binarySearchHelper( ptr->getLeftPtr(), value );

        else if ( value > ptr->getData() )
            nodeToFind=binarySearchHelper( ptr->getRightPtr(), value );

        else
        {
            return nodeToFind= ptr;    //returns the location of where the value is located
        }
        return nodeToFind;             //return location of value

}










//--------------------------------------------------------------------------------------------

template< class NODETYPE >
Tree< NODETYPE >::Tree() { rootPtr = 0; }



//--------------------------------------------------------------------------------------------
template< class NODETYPE >
void Tree< NODETYPE >::insertNode(  NODETYPE &value )
   { insertNodeHelper( &rootPtr, value ); }



//--------------------------------------------------------------------------------------------
// This function receives a pointer to a pointer so the
// pointer can be modified.
template< class NODETYPE >
void Tree< NODETYPE >::insertNodeHelper(
        TreeNode< NODETYPE > **ptr,  NODETYPE &value )
{
   if ( *ptr == 0 ) {                   // tree is empty
      *ptr = new TreeNode< NODETYPE >( value );
      assert( *ptr != 0 );
   }
   else                              // tree is not empty
      if ( value < ( *ptr )->data )
         insertNodeHelper( &( ( *ptr )->leftPtr ), value );
      else
      {
         if ( value > ( *ptr )->data )
            insertNodeHelper( &( ( *ptr )->rightPtr ), value );
         else
            cout << value << " dup" << endl;
      }
}




//--------------------------------------------------------------------------------------------
template< class NODETYPE >
void Tree< NODETYPE >::deleteNode( NODETYPE &value)
    { DeleteHelper( &rootPtr, value ); }



//--------------------------------------------------------------------------------------------
template< class NODETYPE >
void Tree< NODETYPE >::DeleteHelper(TreeNode< NODETYPE > **ptr,  NODETYPE &value)
{
    TreeNode< NODETYPE > *tempPtr;

    if ( *ptr == 0 )
        cout<<"Sorry, but that thing ain't in this tree";

    else if ( value < (*ptr)->data )
        DeleteHelper( &( ( *ptr )->leftPtr ), value );

    else if ( value > (*ptr)->data )
        DeleteHelper( &( ( *ptr )->rightPtr ), value );

    else
        {
        tempPtr = *ptr; 	//save to delete later

        if ( (*ptr)->rightPtr == 0 ) //has no children or one child
        {
            *ptr = (*ptr)->leftPtr;
            delete tempPtr;
        }

        else if ( (*ptr)->leftPtr == 0 ) //has one child
        {
            *ptr = (*ptr)->rightPtr;
            delete tempPtr;
        }

        else	//has two children
            FindAndDeleteMax ( &( ( *ptr )->leftPtr ), &tempPtr );
        }
}


//--------------------------------------------------------------------------------------------
template< class NODETYPE >
void Tree< NODETYPE >::FindAndDeleteMax( TreeNode< NODETYPE > **T, TreeNode< NODETYPE > **MaxPtr )
{
    if ( (*T)->rightPtr == 0 ) //Base case: maximum found
    {
        (*MaxPtr)->data = (*T)->data;
        TreeNode< NODETYPE > * tempPtr = *T;
        *T = (*T)->leftPtr;
        delete(tempPtr);
    }
    else	//General case: Look in right subtree
        FindAndDeleteMax( &( (*T)->rightPtr ), MaxPtr);

}


//--------------------------------------------------------------------------------------------
template< class NODETYPE >
void Tree< NODETYPE >::preOrderTraversal() const
   { preOrderHelper( rootPtr ); }

template< class NODETYPE >
void Tree< NODETYPE >::preOrderHelper(
                          TreeNode< NODETYPE > *ptr ) const
{
   if ( ptr != 0 ) {
      cout << ptr->data << ' ';
      preOrderHelper( ptr->leftPtr );
      preOrderHelper( ptr->rightPtr );
   }
}


//--------------------------------------------------------------------------------------------
template< class NODETYPE >
void Tree< NODETYPE >::inOrderTraversal() const
   { inOrderHelper( rootPtr ); }

template< class NODETYPE >
void Tree< NODETYPE >::inOrderHelper(
                          TreeNode< NODETYPE > *ptr ) const
{
   if ( ptr != 0 )
   {
      inOrderHelper( ptr->leftPtr );
      cout << ptr->data << ' ';
      inOrderHelper( ptr->rightPtr );
   }
}



//-------------------------------------------------------------------------------------------
template< class NODETYPE >
void Tree< NODETYPE >::postOrderTraversal() const
   { postOrderHelper( rootPtr ); }

template< class NODETYPE >
void Tree< NODETYPE >::postOrderHelper(
                          TreeNode< NODETYPE > *ptr ) const
{
   if ( ptr != 0 ) {
      postOrderHelper( ptr->leftPtr );
      postOrderHelper( ptr->rightPtr );
      cout << ptr->data << ' ';

   }
}



#endif


