// 2012
// Author: Dare Kolawole

// A dummy main.

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "linked_list.h"

int main(int argc, char** argv) {  
  LinkedList<int> list;
  std::cout << "Adding... " << std::endl;
  for (int i = 1; i < 101; ++i) {
    list.Add(i);
  }
  std::cout << "Size: " << list.Size() << std::endl;
  std::cout << "Removing ";
  while (!list.Empty()) {
    std::cout << list.Remove() << ", ";
  }
  std::cout << std::endl;
  std::cout << "Size: " << list.Size() << std::endl;
  std::cout << "Adding... " << std::endl;
  for (int i = 1; i < 101; ++i) {
    list.Add(i);
  }
  std::cout << "Size: " << list.Size() << std::endl;
  std::cout << "Reverse..." << std::endl;
  list.Reverse();
  std::cout << "Removing ";
  while (!list.Empty()) {
    std::cout << list.Remove() << ", ";
  }
  std::cout << std::endl;
  return 0;
}
