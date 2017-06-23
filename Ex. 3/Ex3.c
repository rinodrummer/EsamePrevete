#include <stdio.h>
#include <stdlib.h>

enum MODE {WITH_RIP, NO_RIP};

#define DEFAULT_MODE 0

struct Lista {
    int x;
    int y;
    struct Lista *next;
};

struct Lista *creaNodo(int x, int y);
struct Lista *creaCoppieConRipetizioni(int n[], int c, int l, const int end);
struct Lista *creaCoppieSenzaRipetizioni(int A[], int n);

void stampaNodo(struct Lista *nodo);
void stampaLista(struct Lista *head, int l, enum MODE m);

int main(void) {
    struct Lista *l = NULL;

    int val[4] = {2, 8, 6, 10};
    int n = 4;

    unsigned short int c = 0;

    do {
        printf("0. Crea coppie con ripetizioni;\n");
        printf("1. Crea coppie senza ripetizioni;\n");

        printf("\nScegli una modalita' di visualizzazione: ");
        scanf("%hu", &c);
        printf("\n");

        if (c == 0) {
            l = creaCoppieConRipetizioni(val, 0, 0, n);
        }
        else if (c == 1) {
            l = creaCoppieSenzaRipetizioni(val, n);
        }
        else {
            printf("Indicare una scelta valida.\n\n");
        }
    }
    while(c > 1);

    stampaLista(l, n, (enum MODE) c);

    return 0;
}

struct Lista *creaNodo(int x, int y) {
    struct Lista *nodo = (struct Lista *) malloc(sizeof(struct Lista));

    nodo->x = x;
    nodo->y = y;
    nodo->next = NULL;

    return nodo;
}

struct Lista *creaCoppieConRipetizioni(int n[], int c, int l, const int end) {
    struct Lista *head = NULL;

    if (head == NULL && (c < end && l < end)) {
        head = creaNodo(n[c], n[l++]);

        if (l == end) {
            c++;
            l = 0;
        }

        head->next = creaCoppieConRipetizioni(n, c, l, end);
    }

    return head;
}

struct Lista *creaCoppieSenzaRipetizioni(int A[], int n) {
    struct Lista *head = NULL;

    if (n == 0) {
        return NULL;
    }
    else {
        int i = 0;

        head = creaNodo(A[0], A[i++]);

        struct Lista *prev = head;
        struct Lista *tmp = NULL;

        for (; i < n; i++) {
            tmp = creaNodo(A[0], A[i]);

            prev->next = tmp;
            prev = prev->next;
        }

        prev->next = creaCoppieSenzaRipetizioni(&A[1], --n);
    }

    return head;
}

void stampaNodo(struct Lista *nodo) {
    printf("\t(%d, %d);\n", nodo->x, nodo->y);

    return;
}

void stampaLista(struct Lista *head, int l, enum MODE m) {
    int n = 0;

    printf("\n");
    while (head != NULL) {
        printf("(%2d, %2d) -> ", head->x, head->y);
        n++;

        if (n == l) {
            if (m == NO_RIP) {
                l--;
            }

            printf("\n");
            n = 0;
        }

        head = head->next;
    }
    printf("NULL;\n");

    return;
}
