/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include <iostream>
#include "split.h"

using namespace std;

// linked list manager functions
void push_front(Node*& head, int val);
void pop_front(Node*& head);
void print_list(Node*& head);
void delete_list(Node*& head);

int main(int argc, char* argv[])
{
  Node* mylist = new Node(12, nullptr);

  for (int i=10; i >= 0; i-=2) {
    push_front(mylist, i);
  }

  cout << "initialized list:" << endl;
  print_list(mylist);

  Node* evens = nullptr;
  Node* odds = nullptr;

  split(mylist, odds, evens);

  cout << "Odd list: " << endl;
  print_list(odds);

  cout << "Even list: " << endl;
  print_list(evens);

  cout << "Original list: " << endl;
  print_list(mylist);

  delete_list(mylist);
  delete_list(evens);
  delete_list(odds);

  return 0;
}

void push_front(Node*& head, int val) 
{
  Node* new_node = new Node(val, head);
  head = new_node;
}

void pop_front(Node*& head)
{
  if (head == nullptr) {
    // do nothing, list is empty
  }
  else {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}

void print_list(Node*& head)
{
  Node* temp = head;
  while (temp != nullptr) {
    std::cout << temp->value << " " << std::endl;
    temp = temp->next;
  }
}

void delete_list(Node*& head)
{
  while (head != nullptr) {
    pop_front(head);
  }
}