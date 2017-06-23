#include <stdio.h>
#include <stdlib.h>

struct Lista {
    int x;
    int y;
    struct Lista *next;
};

struct Lista *creaNodo(int x, int y);
struct Lista *popolaLista(struct Lista *head, int n[], int c, int l, const int end);

void stampaNodo(struct Lista *nodo);
void stampaLista(struct Lista *head, int l);

int main(void) {
    struct Lista *l = NULL;
    int val[4] = {2, 8, 6, 10};
    int n = 4;

    l = popolaLista(l, val, 0, 0, n);

    stampaLista(l, n);

    return 0;
}

struct Lista *creaNodo(int x, int y) {
    struct Lista *nodo = (struct Lista *) malloc(sizeof(struct Lista));

    nodo->x = x;
    nodo->y = y;
    nodo->next = NULL;

    return nodo;
}

struct Lista *popolaLista(struct Lista *head, int n[], int c, int l, const int end) {
    if (head == NULL && (c < end && l < end)) {
        head = creaNodo(n[c], n[l++]);

        if (l == end) {
            c++;
            l = 0;
        }

        head->next = popolaLista(head->next, n, c, l, end);
    }

    return head;
}

void stampaNodo(struct Lista *nodo) {
    printf("\t\t(%d, %d);\n", nodo->x, nodo->y);

    return;
}

void stampaLista(struct Lista *head, int l) {
    int n = 0;

    printf("\n");
    while (head != NULL) {
        printf("(%2d, %2d) -> ", head->x, head->y);
        n++;

        if (n == l) {
            printf("\n");
            n = 0;
        }

        head = head->next;
    }
    printf("NULL;\n");

    return;
}
