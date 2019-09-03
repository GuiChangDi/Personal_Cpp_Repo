#include <iostream>

/*
  1.The PokeCard function aim to determine the pokeCard game winner.
  2.PokeCards will be divied to two persons equally.
  3.Person A and Person B will play their card to the table one by one.
  4.If someone play the same card as a card on the table,he can take tow identical cards and all the cards they have in the middle to his cards' end.
  5.Set the game round limit to 1000.
*/

struct queue{
  int head;
  int tail;
  int data[1000];
};

//Using two queue and one stack to simulate the process.Queue A as person A's cards.Queue B as person's B.Stack as table's cards.
void PokeCard(
  int a[],
  int b[],
  int n
)
{
  int *table = new int[20] (); //initialize stack table
  int top = -1;   //stack indicate
  int temp1,temp2;
  int flag;
  int *mark = new int [10] (); //Mark array indicate current cards number on the table

  //initialize Person A cards
  queue *A = new queue ();
  A->head = A->tail = 0;

  //initialize Person B cards
  queue *B = new queue ();
  B->head = B->tail =  0;

  for(int i = 0;i<n;i++)
  {
    A->data[i] = a[i];
    B->data[i] = b[i];
    A->tail++;
    B->tail++;
  }

  uint16_t round = 0;//Game round

  //Game start
  while(A->head < A->tail && B->head < B->tail && round < 1000)
  {
    //Person A first draw
    temp1 = A->data[A->head];

    ////Check whether there is the same cards on the table.if found,take tow identical cards and all the cards they have in the middle to his cards' end.
    if(mark[temp1] == 1)
    {
      A->head++;
      A->data[A->tail++] = temp1;
      while(table[top] != temp1)
      {
        mark[table[top]] = 0; //Unmark card
        A->data[A->tail++] = table[top--];
      }
    }
    //If not found,take this card on the table.And mark this card
    else
    {
      A->head++;
      table[++top] = temp1;
      mark[temp1] = 1;
    }

    //Person B second draw
    temp2 = B->data[B->head];

    //if found,take tow identical cards and all the cards they have in the middle to his cards' end.
    if(mark[temp2] == 1)
    {
      B->head++;
      B->data[B->tail++] = temp2;
      while(table[top] != temp2)
      {
        mark[table[top]] = 0;
        B->data[B->tail++] = table[top--];
      }
    }
    //If not found,take this card on the table.
    else
    {
      B->head++;
      table[++top] = temp2;
      mark[temp2] = 1;
    }
    
    //After Person A and Person B draw cards,plus round num.
    round++;
  }

  std::cout<<"Game over"<<std::endl<<"Person A's Cards:";
  for(int i = A->head;i < A->tail; i++)
  {
    std::cout<<A->data[i]<<" ";
  }
  std::cout<<std::endl<<"Person B's Cards:";
  for(int i = B->head;i < B->tail; i++)
  {
    std::cout<<B->data[i]<<" ";
  }

  std::cout<<std::endl<<"Table Cards:";
  for(int i = 0;i <= top; i++)
  {
    std::cout<<table[i]<<" ";
  }

  std::cout<<std::endl<<"Game round: "<<round;
  delete [] A;
  delete [] B;

}

int main(
  int argc,
  char* argv[]
)
{
  int a[] = {2,4,1,2,5,6};
  int b[] = {3,1,3,5,6,4};
  PokeCard(a,b,6);

  std::cin.get();
  std::cin.get();
  return 0;
}
