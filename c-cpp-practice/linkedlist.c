#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
  int val;
  struct Node *next;
} Node;

void push_front(Node **head, int value) {
  Node *n = malloc(sizeof(*n));
  if (n == NULL) {
    return;
  }
  n->val = value;
  n->next = *head;
  *head = n;
}

void print_list(const Node *head) {
  while (head != NULL) {
    printf("%d -> ", head->val);
    head = head->next;
  }
  printf("NULL\n");
}

void free_list(Node **head) {
  while (*head != NULL) {
    Node *next = (*head)->next;
    free(*head);
    *head = next;
  }
}

void reverse(Node **head) {
  if (*head == NULL) {
    return;
  }
  Node *next = (*head)->next;
  (*head)->next = NULL;
  while (next != NULL) {
    Node *nextnext = next->next;
    next->next = *head;
    *head = next;
    next = nextnext;
  }
}

int delete_value(Node **head, int val) {
  if (*head == NULL) {
    return 0;
  }
  Node *walkr = *head;
  Node *walkrNext = walkr->next;
  if (walkr->val == val) {
    free(walkr);
    *head = walkrNext;
    return 1;
  }
  while (walkrNext != NULL) {
    if (walkrNext->val != val) {
      walkr = walkrNext;
      walkrNext = walkrNext->next;
      continue;
    }
    Node *walkrNextNext = walkrNext->next;
    free(walkrNext);
    walkr->next = walkrNextNext;
    return 1;
  }
  return 0;
}

int has_cycle(const Node *head) {
  if (head == NULL) {
    return 0;
  }
  const Node *slow = head;
  const Node *fast = head;
  while (1) {
    if (fast->next == NULL || fast->next->next == NULL) {
      return 0;
    } else {
      fast = fast->next->next;
      slow = slow->next;
      if (slow == fast) {
        return 1;
      }
    }
  }
}

// void copy_list(const Node *src, Node **dst) {
//   if (*dst != NULL) {
//     free_list(dst);
//   }
//   while (src != NULL) {
//     *dst = malloc(sizeof(**dst));
//     (*dst)->val = src->val;
//     (*dst)->
//   }
// }

int main(void) {
  Node *list = NULL;
  Node *empty = NULL;
  Node *cycle = NULL;
  push_front(&list, 11);
  push_front(&list, 10);
  push_front(&list, -3);
  push_front(&list, 7);
  push_front(&list, 8);
  push_front(&list, 10);

  push_front(&cycle, 100);
  push_front(&cycle, 200);
  cycle->next->next = cycle;

  if (list != NULL) {
    printf("%d\n", list->val);
  }
  print_list(empty);
  print_list(list);

  reverse(&empty);
  reverse(&list);
  print_list(list);

  delete_value(&empty, 0);
  delete_value(&list, 10);
  delete_value(&list, 0);
  delete_value(&list, 10);
  print_list(list);

  printf("%d\n", has_cycle(empty));
  printf("%d\n", has_cycle(list));
  printf("%d\n", has_cycle(cycle));

  free_list(&empty);
  free_list(&list);
  cycle->next->next = NULL;
  free_list(&cycle);
  return EXIT_SUCCESS;
}
