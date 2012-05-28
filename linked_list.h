// 2012
// Author: Dare Kolawole

// A basic linked list.

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

struct Entry {
  void* data;
  Entry* next;

  Entry(void* _data) : data(_data), next(NULL) {}

  ~Entry() {
    // free?
    data = NULL;
  }
};

template <class T>
class LinkedList {
 public:
  LinkedList() : size_(0), head_(NULL), tail_(NULL) {
  }

  ~LinkedList() {
    while (head_ != NULL) {
      Entry* next = head_->next;
      delete head_;
      head_ = next;
    }
  }

  // Add an element to the list.
  void Add(const T& elem);

  // Remove an element from the list and return a ref.
  T Remove();

  // Reverse the list.
  void Reverse();

  // Return the size of the list.
  size_t Size() { return size_; }

  // Return true if the list is empty.
  bool Empty() { return size_ == 0; }

 private:
  size_t size_;
  Entry* head_;
  Entry* tail_;
};

template <class T>
void LinkedList<T>::Add(const T& elem) {
  Entry* new_entry = new Entry((void*)elem);
  if (head_ == NULL) {
    head_ = new_entry;
    tail_ = head_;
    tail_->next = NULL;
  } else {
    tail_->next = new_entry;
    tail_ = tail_->next;
  }
  ++size_;
}

template <class T>
T LinkedList<T>::Remove() {
  if (head_ != NULL) {
    T found = (T)head_->data;
    head_ = head_->next;
    --size_;
    return found;
  }
  return NULL;
}

template <class T>
void LinkedList<T>::Reverse() {
  Entry* prev = NULL;
  Entry* old_head = head_;
  while (head_->next != NULL) {
    Entry* temp = head_->next;
    head_->next = prev;
    prev = head_;
    head_ = temp;
  }
  head_->next = prev;
  tail_ = old_head;
}

#endif
