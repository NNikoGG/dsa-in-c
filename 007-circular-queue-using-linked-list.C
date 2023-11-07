#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

void enqueue (int d)			//Insert elements in Queue
{
  struct node *n;
  n = (struct node *) malloc (sizeof (struct node));
  n->data = d;
  n->next = NULL;
  if ((r == NULL) && (f == NULL))
    {
      f = r = n;
      r->next = f;
    }
  else
    {
      r->next = n;
      r = n;
      n->next = f;
    }
}

void dequeue ()			// Delete an element from Queue
{
  struct node *t;
  t = f;
  if ((f == NULL) && (r == NULL))
    printf ("\nQueue is Empty");
  else if (f == r)
    {
      f = r = NULL;
      free (t);
    }
  else
    {
      f = f->next;
      r->next = f;
      free (t);
    }


}

void display ()
{				// Print the elements of Queue
  struct node *t;
  t = f;
  if ((f == NULL) && (r == NULL))
    printf ("\nQueue is Empty");
  else
    {
      do
	{
	  printf (" %d", t->data);
	  t = t->next;
	}
      while (t != f);
    }
}

int main ()
{
  enqueue (34);
  enqueue (22);
  enqueue (75);
  enqueue (99);
  enqueue (27);
  printf ("Circular Queue: ");
  display ();
  printf ("\n");

  dequeue ();
  printf ("Circular Queue After dequeue: ");
  display ();
  return 0;
}




// INSERTION
// Step 1: IF (REAR+1)%MAX = FRONT
// Write " OVERFLOW "
// Goto step 4
// [End OF IF]

// Step 2: IF FRONT = -1 and REAR = -1
// SET FRONT = REAR = 0
// ELSE IF REAR = MAX - 1 and FRONT ! = 0
// SET REAR = 0
// ELSE
// SET REAR = (REAR + 1) % MAX
// [END OF IF]

// Step 3: SET QUEUE[REAR] = VAL

// Step 4: EXIT



// DELETION
// Step 1: IF FRONT = -1
// Write " UNDERFLOW "
// Goto Step 4
// [END of IF]

// Step 2: SET VAL = QUEUE[FRONT]

// Step 3: IF FRONT = REAR
// SET FRONT = REAR = -1
// ELSE
// IF FRONT = MAX -1
// SET FRONT = 0
// ELSE
// SET FRONT = FRONT + 1
// [END of IF]
// [END OF IF]

// Step 4: EXIT