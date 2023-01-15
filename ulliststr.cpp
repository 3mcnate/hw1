#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{
  // case 1: empty
  if (empty()) {
    // allocate new Item struct and add val to the first index of 
    //  the array
    Item* node = new Item;
    node->val[0] = val;
    node->last = 1;

    head_ = node;
    tail_ = node;
  }

  // case 2: no space at the back of the last item
  // array is full (last - first == 10) or last == 10
  else if(tail_->last == ARRSIZE) {
    // allocate new Item struct and add val to the first index of the array
    Item* node = new Item;
    node->val[0] = val;
    node->last = 1;

    // insert new node into the back of the list, making sure to change all 3 
    //  necessary pointers
    node->prev = tail_;
    tail_->next = node;
    tail_ = node;
  }

  // case 3: there is space at the back of the last item
  else {
    tail_->val[tail_->last] = val;
    (tail_->last)++;
  }

  size_++;
}

void ULListStr::push_front(const std::string& val)
{
  // case 1: empty
  if (empty()) {
    // allocate new Item struct and add val to the last index of 
    // the array
    Item* node = new Item;
    node->val[ARRSIZE-1] = val;
    node->first = ARRSIZE-1;
    node->last = ARRSIZE;

    head_ = node;
    tail_ = node;
  }

  // case 2: no space at the front of the first item
  // array is full (last - first == 10) or first == 0
  else if(head_->first == 0) {
    // allocate new Item struct and add val to the last index of the array
    Item* node = new Item;
    node->val[ARRSIZE-1] = val;
    node->first = ARRSIZE-1;
    node->last = ARRSIZE;

    // insert new node into the front of the list, making sure to change all 3 
    //  necessary pointers
    node->next = head_;
    head_->prev = node;
    head_ = node;
  }

  // case 3: there is space at the front of the first item
  else {
    (head_->first)--;
    head_->val[head_->first] = val;
  }

  size_++;
}

void ULListStr::pop_back()
{
  // ensure list is not empty
  if (!empty()) {

    // case 1: only one value in the last Item struct
    if (tail_->size() == 1) {
      
      // subcase a: list only has one Item struct
      if (size_ == 1) {
        delete head_;
        head_ = nullptr;
        tail_ = nullptr;
      }

      // subcase b: list has more than one Item struct
      else {
        // Delete the last Item, making sure to change the 2 necessary pointers
        Item* temp = tail_;
        tail_ = tail_->prev;
        tail_->next = nullptr;
        delete temp;
      }
    }

    // case 2: last Item has more than one value
    else {
      (tail_->last)--;
    }

    size_--;
  }
}



void ULListStr::pop_front()
{
  if (!empty()) {

    // case 1: only one value in the first Item struct
    if (head_->size() == 1) {
      
      // subcase a: list only has one Item struct
      if (size_ == 1) {
        delete head_;
        head_ = nullptr;
        tail_ = nullptr;
      }

      // subcase b: list has more than one Item struct
      else {
        // Delete the first Item, making sure to change the 2 necessary pointers
        Item* temp = head_;
        head_ = head_->next;
        head_->prev = nullptr;
        delete temp;
      }
    }

    // case 2: last Item has more than one value
    else {
      (head_->first)++;
    }

    size_--;
  }
}

void ULListStr::print(char separator)
{
  Item* curr = head_;
  while (curr != nullptr) {
    for (size_t i = curr->first; i < curr->last; i++) {
      std::cout << curr->val[i] << separator;
    }
    curr = curr->next;
  }
}

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  // check if index is out of bounds
  if (loc < 0 || loc > size_-1) {
    return nullptr;
  }
  
  // determine which node the given index is in
  size_t offset = head_->first;
  size_t node_index = (loc + offset) / ARRSIZE;

  // walk the list until we reach the wanted node
  Item* curr = head_;
  for (size_t i=0; i < node_index; i++) {
    curr = curr->next;
  }

  // get the index of the item within the desired node
  // BUG FOUND: size_t val_index = loc % ARRSIZE + offset;
  size_t val_index = (loc + offset) % ARRSIZE;

  #ifdef DEBUG
    std::cout << "getVAlAtLoc() returns pointer to " << *(curr->val + val_index) << std::endl;
  #endif

  return curr->val + val_index;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
