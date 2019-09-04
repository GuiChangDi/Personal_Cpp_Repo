#include <iostream>
//DFS.cpp use DFS logic to implement serveral function.

//Using DFS to implement full permutation.

int *a = new int [10] ();
int *mark = new int [10] ();

void
permutation(
  int num,
  int n
)
{
  static int count = 0;

  if(num == n+1){
    count++;
    std::cout<<"The "<<count<<": ";
    for(int i = 1;i<=n;i++)
      std::cout<<a[i]<<" ";
    std::cout<<std::endl;
    return;
  }

  for(int i = 1;i<=n;i++){
    if(mark[i] == 0){
      a[num] = i;
      mark[i] = 1;

      permutation(num+1,n);
      mark[i] = 0;//Important,after one recursive ,withdraw
    }
  }
  return;
}

int main(
  int argc,
  char* argv[]
)
{
  permutation(1,5);
  std::cin.get();
  std::cin.get();
  return 0;
}