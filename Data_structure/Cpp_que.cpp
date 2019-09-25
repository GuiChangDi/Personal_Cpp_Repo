#include "Header/Cpp_que.h"
#include <iostream>

//Queue example,use queue to implement bank service simulate
struct Customer { int window; unsigned int time; };//window assigning to customer, service time

//Find best time for customer
int
bestWindow(Queue<Customer> windows[], int nWin){
  int minSize = windows[0].size(), optiWin = 0;
  for ( int i = 1; i < nWin; i++)
    if (minSize > windows[i].size())
      { minSize = windows[i].size(); optiWin = i; }
  return optiWin;
}

//nWin: Window number
void
simulate(int nWin, int servTime){
  Queue<Customer> *windows = new Queue<Customer>[nWin];//Create queue for every window
  for ( int now = 0; now < servTime; now++){//work time
    if (rand() % (1 + nWin)) {//Customer arrive at nWin/(nWin+1) percent
      Customer C;
      C.time = 1 + rand() % 98;//Customer service time 
      C.window = bestWindow(windows, nWin);//choose the best service window for customer
      windows[C.window].enqueue(C);//Customer in Window serivce queue
    }
    for (int i = 0; i < nWin; i++){//check
      if (!windows[i].empty())//check no-empty window
        if (-- windows[i].front().time <= 0)//if customer time over, out queue
          windows[i].dequeue();
    }
  }
  delete [] windows;
}