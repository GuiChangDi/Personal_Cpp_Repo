#include <iostream>
using namespace std;

int const MAX_VERTEX_NUM = 20;
int const NA = -1;
typedef enum{DG, UDG} GraphKind;//Graph type: DG:digraph UDG:undigraph

//Use adjacent matrix to store graph,graph right now just have DFS and BFS function
class Graph
{
private:
  GraphKind kind;//Graph type
  int vex_num;//Graph verx number
  int vexs[MAX_VERTEX_NUM];
  int arc_num;//Graph arc num
  int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//adjacent matrix
  bool is_trav[MAX_VERTEX_NUM];//Use to indicate whether this vex node have traveled.
public:
  Graph(GraphKind g);
  ~Graph();

  void CreateGraph();
  void BFSTraverse();
  void DFSTraverse();
private:
  void BFSFunction(int);
  void DFSFunction(int);
};

int
main(
  int argc,
  char* argv[]
)
{
  Graph G(UDG);

  cout<<endl;
}