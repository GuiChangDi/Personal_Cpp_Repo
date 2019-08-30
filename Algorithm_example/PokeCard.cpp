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
  int data[10];
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

}
