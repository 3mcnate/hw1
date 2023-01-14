/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <iostream>
#include <cassert>

/* Add a prototype for a helper function here if you need */
void move_node(Node*& list, Node*& item);

void split(Node*& in, Node*& odds, Node*& evens)
{
  // base case if in is null
  if (in != nullptr) { 
    
    // create temporary next_node variable so we can change current 
    // node (in) to point at null, allowing us to safely add to the 
    // end of the appropriate list 
    Node* next_node = in->next;
    in->next = nullptr; 

    // then add the node to the correct list and 
    // call split recursively

    // even case
    if (in->value % 2 == 0) { 
      if (evens == nullptr) { // even list empty
        evens = in;
        split(next_node, odds, evens);
      }
      else {
        evens->next = in;
        split(next_node, odds, evens->next);
      }
    }
    
    // odd case
    else {
      if (odds == nullptr) { // odds list empty
        odds = in;
        split(next_node, odds, evens);
      }
      else {
        odds->next = in;
        split(next_node, odds->next, evens);
      }
    }

    in = nullptr;
  }
}


/* If you needed a helper function, write it here */

// void move_node(Node*& list, Node*& item)
// {
//   item->next = nullptr;

//   // base case 1: list is empty
//   if (list == nullptr) {
//     list = item;
//   }

//   // base case 2: list not empty
//   else if (list->next == nullptr) {
//     list->next = item;
//   }

//   // recursive case
//   else {
//     move_node(list->next, item);
//   }
// }
