#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(struct Node *node, int x) {
  node = (struct Node *)malloc(sizeof(struct Node));
  node->data = x;
  node->next = NULL;
  if (front == NULL) {
    front = node;
    rear = node;
  } else {
    rear->next = node;
    rear = rear->next;
  }
}

void dequeue(struct Node *node) {
  if (front == NULL)
    printf("Underflow!!!");
  else
    front = front->next;
}

void display(struct Node *node) {
  printf("\nFront-->");
  while (node != NULL) {
    printf("%d --> ", node->data);
    node = node->next;
  }
  printf("END\n");
}

void search(struct Node *node, int val) {
  int count = 0;
  if (front == NULL)
    printf("\nUnderflow");
  else {
    while (node != NULL) {
      if (node->data == val) {
        printf("\n%d found at %d", val, count + 1);
        break;
      }
      node = node->next;
      count += 1;
    }
    if (node == NULL)
      printf("\n%d not found\n", val);
  }
}

int main(void) {
  int ch, val;
  do {
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Search\n5.Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      printf("\nInserting an element");
      printf("\nEnter a value to be inserted: ");
      scanf("%d", &val);
      enqueue(front, val);
      display(front);
      break;
    case 2:
      printf("\nDeleting an element");
      dequeue(front);
      display(front);
      break;
    case 3:
      printf("\nDisplay all elements");
      display(front);
      break;
    case 4:
      printf("\nEnter a value to be searched: ");
      scanf("%d", &val);
      search(front, val);
      break;
    default:
      printf("\nEnter correct choice");
    }
  } while (ch < 5);
  return 0;
}