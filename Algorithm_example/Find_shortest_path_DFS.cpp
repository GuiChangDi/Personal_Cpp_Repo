#include <iostream>

//Using DFS logic to find the shortest path way
/** 
 This function use recursive to find the shortest step to the target.
 @param[in]   x     the current point x-style
 @param[in]   y     the current point y-style
 @param[in]   step  the path number currently
**/
//map[] record map data, book[51] record whether this point has been in the path.
int  map[5][4] = {
    {0,0,1,0},
    {0,0,0,0},
    {0,0,1,0},
    {0,1,0,0},
    {0,0,0,1}
  };
int book[5][4] = {
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
  };
int n,m,p,q,min = 999999999;

void
Find_shortest_path(
  int x,
  int y,
  int step
)
{
  //four direction to go,Right Down,Left,Right
  int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

  int tx,ty,k;
  //Judge whether get to the position
  if(x==p && y==q)
  {
    //update min
    if(step < min)
      min = step;
    return;
  }

  //enurate four direction
  for(k = 0;k<=3;k++)
  {
    //caculate the next point
    tx = x + next[k][0];
    ty = y + next[k][1];
    if(tx < 1 || tx > n || ty < 1 || ty > m)
      continue;
    //judge whether this point is obstacle or already in the path
    if(map[tx-1][ty-1] == 0 && book[tx-1][ty-1] == 0)
    {
      book[tx-1][ty-1] = 1;
      //start the next point
      Find_shortest_path(tx,ty,step+1);
      //Unmark the point,importan!
      book[tx-1][ty-1] = 0;
    }
  }
}

int main(
  int argc,
  char* argv[]
)
{
  int startx,starty;
  n = 5,m = 4;

  p = 4;
  q = 3;
  startx = 1;
  starty = 1;
  Find_shortest_path(startx,starty,0);

  std::cout<<min<<std::endl;
  std::cin.get();
  std::cin.get();
  return 0;
}