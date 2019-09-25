#pragma once
#include <iostream>
#include "Cpp_List.h"
template <typename T>
class Queue:public List<T>{
public:
  void enqueue(T const &e) { insertAsLast(e);}//in queue
  T dequeue() { return remove(first()); }//out queue
  T& front() { return first()->data; }//queue first data
};