#include <iostream>

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

struct note
{
  int x;//X style
  int y;//Y style
  int f;//the prior point
  int s;//step number
};

//Using BFS logic to find the shortest path way,use queue to storage point.
void
Find_shortest_path_BFS(
  int startx,
  int starty,
  int p,
  int q
)
{
  //Direction array,right,down,left,up
  int next[4][2] = {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
  };

  struct note que[2500];
  int head = 0,tail = 0;
  int tx,ty;
  bool flag = false;

  //Insert the start point to queue.
  que[tail].x = startx;
  que[tail].y = starty;
  que[tail].f = 0;
  que[tail].s = 0;
  tail++;
  book[startx][starty] = 1;//Mark this point

  while(head < tail)
  {
    //four direction
    for(int i = 0;i<4;i++)
    {
      tx = que[head].x + next[i][0];
      ty = que[head].y + next[i][1];

      //Judge whether out of border
      if(tx < 0 || tx > 5 || ty < 0 || ty > 4)
        continue;
      //Judge whether is obstcle or already in the path
      if(map[tx][ty] == 0 && book[tx][ty] == 0)
      {
        //Mark this point
        book[tx][ty] = 1;
        //Insert this point to que
        que[tail].x = tx;
        que[tail].y = ty;
        que[tail].f = head;//this point's last point is from head
        que[tail].s = que[head].s + 1;//step number +1
        tail++;
      }
      //Judge whether get to the desitination
      if(tx == p && ty == q)
      {
        flag = true;
        break;
      }
    }
    if(flag == true)
      break;
    head++;//when one point done,out of this point from que.
  }

  std::cout<<"The total step: "<<que[tail-1].s<<std::endl;
}

int main(
  int argc,
  char* argv[]
)
{
  Find_shortest_path_BFS(0,0,3,2);
  std::cin.get();
  std::cin.get();
  return 0;
}