#include <iostream>

//Time complexity O(n^2)  if a[i] > a[i+1], switch up
void
Bubble(
  int a[],
  int n
)
{
  int i,j,temp;

  std::cout<<"After Bubble:"<<std::endl;

  for(i = n-1;i>0;i--)
  {
    for(j = 0;j<i;j++)
    {
      if(a[j] > a[j+1])
      {
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }
  return;
}

int main(
  int argc,
  char* argv[]
)
{
  int a[10] = {2,5,1,4,3,6,8,14,15,0};
  Bubble(a,10);
  for(int i = 0;i<10;i++)
    std::cout<<a[i]<<" ";
  
  std::cin.get();
  std::cin.get();
  return 0;
}