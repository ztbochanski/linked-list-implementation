// Zachary Bochanski
// Linked list implementation

#include "llist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node *node_alloc(int value)
{
  // 1. create a memory block to store the new node,
  //    malloc returns a void pointer and gets converted
  //    to the type of the variable
  struct node *new_node = malloc(sizeof(struct node *));

  // 2. assign value to an address within the block
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

void node_free(struct node *n)
{
  free(n);
  n = NULL;
}

void llist_print(struct node *head)
{
  if (head == NULL)
  {
    printf("[empty]\n");
    return;
  }
  while (head != NULL)
  {
    if (head->next == NULL)
    {
      printf("%d", head->value);
      head = head->next;
    }
    else
    {
      printf("%d -> ", head->value);
      head = head->next;
    }
  }
  printf("\n");
  fflush(stdout);
}

void llist_insert_head(struct node **head, struct node *n)
{
  n->next = *head;
  *head = n;
}

void llist_insert_tail(struct node **head, struct node *n)
{
  if (*head == NULL)
  {
    *head = n;
  }
  else
  {
    struct node *temp = *head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = n;
  }
}

struct node *llist_delete_head(struct node **head)
{
  struct node *temp = *head;
  if (*head == NULL)
  {
    return *head;
  }
  else
  {
    *head = temp->next;
    return *head;
  }
}

void llist_free(struct node **head)
{
  struct node *temp = *head;
}

int main(int argc, char *argv[])
{
  struct node *head = NULL;
  struct node *n1 = node_alloc(10);
  struct node *n2 = node_alloc(20);
  struct node *n3 = node_alloc(30);
  llist_insert_tail(&head, n1);
  llist_insert_tail(&head, n2);
  llist_insert_tail(&head, n3);
  llist_delete_head(&head);
  llist_print(head);
  node_free(n1);
  node_free(n2);
  node_free(n3);
  //  parse the command line
  //  for (int arg_counter = 1; arg_counter < argc; arg_counter++)
  //  {
  //    int value;
  //    if (arg_counter < argc - 1)
  //    {
  //      value = atoi(argv[arg_counter + 1]);
  //    }
  //    if (0 == strcmp(argv[arg_counter], "ih"))
  //    {
  //      printf("%d: command => %s, value: %d\n", arg_counter, argv[arg_counter], value);
  //    }
  //    else if (0 == strcmp(argv[arg_counter], "it"))
  //    {
  //      printf("%d: command => %s, value: %d\n", arg_counter, argv[arg_counter], value);
  //    }
  //    else if (0 == strcmp(argv[arg_counter], "dh"))
  //    {
  //      /* code */
  //    }
  //    else if (0 == strcmp(argv[arg_counter], "f"))
  //    {
  //      /* code */
  //    }
  //    else if (0 == strcmp(argv[arg_counter], "p"))
  //    {
  //      /* code */
  //    }
  //  }
}
