#include <stdio.h>
#include <stdlib.h>

struct Lista {
    int val;
    struct Lista *next;
};

struct Lista *creaNodo(int n);
struct Lista *popolaLista(struct Lista *head, int n, const int l);

struct Lista *invertiLista(struct Lista *head);

void stampaLista(struct Lista *head);

int main(void) {
    struct Lista *l = NULL;

    printf("Test;");

    l = popolaLista(l, 1, 4);

    stampaLista(l);

    l = invertiLista(l);

    stampaLista(l);

    return 0;
}

struct Lista *creaNodo(int n) {
    struct Lista *nodo = (struct Lista *) malloc(sizeof(struct Lista));

    nodo->val = n;
    nodo->next = NULL;

    return nodo;
}

struct Lista *popolaLista(struct Lista *head, int n, const int l) {
    if (head == NULL && n <= l) {
        head = creaNodo(n);

        head->next = popolaLista(head->next, ++n, l);
    }

    return head;
}

struct Lista *invertiLista(struct Lista *head) {
   struct Lista *prev = NULL;
   struct Lista *curr = head;
   struct Lista *next = NULL;

   while (curr != NULL) {
       next = curr->next;
       curr->next = prev;
       prev = curr;
       curr = next;
   }

   return prev;
}

void stampaLista(struct Lista *head) {
    printf("\n");
    while (head != NULL) {
        printf("%d -> ", head->val);

        head = head->next;
    }
    printf("NULL;\n");

    return;
}
