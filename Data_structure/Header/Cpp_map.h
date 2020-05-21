#include "Cpp_stack.h"
#include "Cpp_array_vector.h"

typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus;//顶点状态 vertex status
typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD} EStatus;//边状态 edge status

template <typename Tv, typename Te> //vertex type, edge type
class Graph{
private:
  void reset() {//reset all vertex, edge 's support Info
    for (int i = 0; i < n; i++) {//all vertex
      status(i) = UNDISCOVERED;
      dTime(T) = fTime(i) = -1;//status, time label
      parent(i) = -1;
      priority(i) = INT_MAX;//(In recursive tree) parent node, priority num.
      for (int j  = 0; j < n; j++)//all edge
        if (exists(i,j)) status(i,j) = UNDETERMINED;//status
    }
  }
  void BFS(int, int &);//(connected domain)BFS algorithm
  void DFS(int, int &);//(connected domain)DFS algorithm
  void BCC(int, int &, Stack<int> &);//(connected domain)基于DFS的双连通分量分解算法
  bool TSort(int, int &, Stack<Tv> *);//(connected domain)基于DFS的拓扑排序算法
  template <typename PU> void PFS(int, PU);//(connected domain)优先级搜索框架
public:
  //vertex
  int n; //vertex number
  virtual int insert(Tv const&) = 0; //Insert vertex,return number
  virtual Tv remove(int n) = 0; //delete vertex and its relate edge,return vertex data
  virtual Tv& vertex(int n) = 0; //vertex data
  virtual int inDegree(int n) = 0; //vertex 入度in-degree
  virtual int outDegree(int n) = 0; //vertex 出度out-degree
  virtual int firstNbr(int) = 0; //vertex V's first border node顶点V的第一个邻接顶点
  virtual int nextNbr(int, int) = 0; //vertex V's(相当于顶点J的)下一个邻接顶点
  virtual VStatus& status(int) = 0; //vertex V's status
  virtual int& dTime(int) = 0; //vertex V's Time label dTime
  virtual int& fTime(int) = 0; //vertex V's Time Label fTime
  virtual int& parent(int) = 0; //vertex V's parent in traverse tree
  virtual int& priority(int) = 0; //vertex V's priority num in traverse tree
  //edge 约定，无向边均同一转化为方向互逆的一对有向边，从而将无向图视作有向图的特例
  int e; //edge number
  virtual bool exists(int v, int u) = 0; //edge(v,u) whether exists
  virtual void insert(Te const&, int, int, int) = 0; //Insert edge e(weight w) between vertex v and u
  virtual EStatus& status(int v, int u); //edge(v,u) 's status
  virtual Te& edge(int v, int u) = 0; // edge(v,u) 's data
  virtual int& weight(int v, int u) = 0; //edge(v,u) 's weight
  //algorithm
  void bfs(int); //BFS
  void dfs(int); //DFS
  void bcc(int); //基于DFS的双连通分量分解算法
  Stack<Tv>* tSort(int); //topo sort algorithm base on DFS
  void prim(int); //最小支撑树Prim算法
  void dijkstra(int); //最短路径Dijkstra算法
  template <typename PU> void pfs(int, PU); //优先级搜索框架
};

template <typename Tv> struct Vertex { //Vertex
  Tv data; //data
  int inDegree,outDegree; //入度, 出度
  VStatus status; //状态
  int dTime, fTime; //Time label
  int parent; //vertex V's parent in traverse tree
  int priority; //在遍历树中的优先级数
  Vertex(Tv const& d = (Tv) 0): //create new vertex
    data(d), inDegree(0), outDegree(0), status(UNDISCOVERED),
    dTime(-1), fTime(-1), parent(-1), priority(INT_MAX) {}
};

template <typename Te> struct Edge {
  Te data; //data
  int weight; //weight
  EStatus status; //status
  Edge(Te const& d, int w) : data(d), weight(w), status(UNDETERMINED) {} //create new edge
};

template <typename Tv, typename Te> //Vertex type, Edge type
class GraphMatrix : public Graph<Tv, Te> {
private:
  Vector<Vertex<Tv>> V; //Vertex Group
  Vector<Vector<Edge<Te>*>> E; //Edge Group(adjacency matrix)邻接矩阵 两维矩阵
public:
  GraphMatrix() { n = e = 0; } //constructor
  ~GraphMatrix() { //destructor
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        delete E[i][j];
  }
  //Vertex 's basic operate
  virtual Tv& vertex(int i) { return V[i].data; } //Vertex i's data
  virtual int inDegree(int i) { return V[i].inDegree; } //Vertex i's inDegree
  virtual int outDegree(int i) { return V[i].outDegree; } //Vertex i's outDegree
  virtual int firstNbr(int i) { return V[nextNbr(i, n); } //first border Vertex
  virtual int nextNbr(int i, int j) //next border Vertex on Vertex j
  { while ((-1 < j) && (!exists(i, --j))); return j; } //逆向线性试探
  virtual VStatus& status(int i）{ return V[i].status; } //status
  virtual int& dTime(int i) { return V[i].dTime; } //dTime label
  virtual int& fTime(int i) { return V[i].fTime; } //fTime label
  virtual int& parent(int i) { return V[i].parent; } //vertex V's parent in traverse tree
  virtual int& priority(int i) { return V[i].priority; } //vertex V's priority in traverse tree
  //Vertex 's dynamic operate
  virtual int insert(Tv const& vertex) { //插入顶点，返回编号
    for (int j = 0; j < n; j++) E[j].insert(NULL); n++; //各顶点预留一条潜在的关联边
    E.insert(Vector<Edge<Te>*>(n, n, (Edge<Te>*) NULL)); //创建新顶点对应的边向量
    return V.insert(Vertex<Tv>(vertex)); //顶点向量增加一个顶点
  }

  virtual Tv remove(int i) { //删除第i个顶点及其关联边(0 <= i < n)
    for (int j = 0; j < n; j++) //all out Edge
      if (exists(i,j)) { delete E[i][j]; V[j].inDegree--; } //Delete every edge
    E.remove(i); n--; //delete i line
    for (int j = 0; j < n; j++) //all out Edge
      if (exists(j,i)) { delete E[j].remove(i); V[j].outDegree--; } //Delete every edge
    Tv vBak = vertex(i); //delete Vertex i
    V.remove(i);
    return vBak; //return delete vertex's data
  }
  //Edge's confirm operate
  virtual bool exists(int i, int j) //Edge(i, j) whether exist
  { return (0 <= i) && (i < n) && (0 <= j) && (j < n) && E[i][j] != NULL; }
  //Edge's basic operate : check 顶点i与j之间的联边(0 <= i,j < n且exists(i, j))
  virtual EStatus& status(int i, int j) { return E[i][j]->status; } //Edge(i, j) 's status
  virtual Te& edge(int i, int j) { return E[i][j]->data; } //Edge(i, j) 's data
  virtual int& weight(int i, int j) { return E[i][j]->weight; } //Edge(i,j) 's weight
  //Edge's dynamic operate
  virtual void insert(Te const& edge, int w, int i, int j) { //insert Edge e = (i, j) weight w
    if（exists(i, j)) return; //make sure edge doesn't exists
    E[i][j] = new Edge<T>(edge，w); //create new edge
    //Update edge number and Degree
    e++;
    V[i].outDegree++;
    V[j].inDegree++;
    }
  virtual Te remove(int i, int j) {
    Te eBak = edge(i, j); //store edge's data
    delete E[i][j]; //delete edge
    E[i][j] = NULL;
    //Update edge number and Degree
    e--;
    V[i].outDegree--;
    V[j].inDegree--;
    return eBak;
  }
};