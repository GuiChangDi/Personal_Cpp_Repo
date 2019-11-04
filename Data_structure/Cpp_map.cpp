#include <iostream>
#include "Header/Cpp_map.h"
#include "Header/Cpp_que.h"
using namespace std;

template <typename Tv, typename Te>//BFS algorithm global
void
Graph<Tv, Te>::bfs(int s){//assert: 0 <= s < n
  reset();
  int clock = 0;
  int v = s;
  do //check all vertex
    if (UNDISCOVERED == status(v))
      BFS(v, clock);
  while (s != (v = (++v %n)));
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::BFS(int v, int& clock) {
  Queue<int> Q;//import support queue
  status(v) = DISCOVERED;
  Q.enqueue(v);
  while (!Q.empty()) {
    int v = Q.dequeue();
    dTime = ++clock;
    for (int u = firstNbr(v); - 1 < u; u = nextNbr(v, u))//traverse every border vertex
      if (UNDISCOVERED == status(u)) { //if vertex not discovered
        status(u) = DISCOVERED;
        Q.enqueue(U); //push vertex to queue
        //import support tree, every BFS visit like traverse a tree
        status(v,u) = TREE;
        parent(u) = v;
      } else {
        status(v, u) = CROSS;
      }
    status(v) = VISITED;
  }
}

template <typename Tv, typename Te> //DFS global
void
Graph<Tv, Te>::dfs(int s){
  reset();
  int clock = 0;
  int v = s;
  do
    if (UNDISCOVERED == status(v))
      DFS(v, clock);
  while (s != (v = (++v % n)));
}

template <typename Tv, typename Te> //DFS, 单个连通域
void
Graph<Tv, Te>::DFS(int v, int& clock){ //assert: 0 <= v < n
  dTime(v) = ++clock;
  status(v) = DISCOVERED;
  for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u))
    switch( status(u)) {
      case UNDISCOVERED:
        status(v,u) = TREE; parent(u) = v; DFS(u,clock); break;
      case DISCOVERED:
        status(v,u) = BACKWARD; break;
      default:
        status(v,u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS; break;
    }
  status(v) = VISITED;
  fTime(v) = ++clock;
}