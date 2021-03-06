#include <stdio.h>
#define MAX_STUD 10
#define MAX_ESAMI 10

struct Studente {
    int matricola;
    char nome[32];
    char cognome[32];
    int nEsami;
    int votiEsami[MAX_ESAMI];
};

int maggioreDiK(struct Studente V[], int dimV, int k) {
    int media = 0;
    int i;
    int j;
    
    for (i = 0; i < dimV; i++) {
        media = calcolaMedia(V[i].votiEsami, V[i].nEsami);
        
        if (media > k) {
            for (j = i; j < dimV; j++) {
                V[i] = V[j];
                dimV--;
            }
            
            printf("Studente con media %d eliminato.\n", media);
        }
        
        media = 0;
    }
    
    return dimV;
}

int calcolaMedia(int val[], int n) {
    int i;
    int somma = 0;
    
    for (i = 0; i < n; i++) {
        somma += val[i];
    }
    
    return somma / n;
}

struct Studente inserisciStudente() {
    int i;
    
    struct Studente s;
    
    printf("\nInserimento studente:\n\n");
    
    printf("\tMatricola: ");
    scanf("%d", &s.matricola);
    
    printf("\tNome: ");
    scanf("%s", s.nome);
    
    printf("\tCognome: ");
    scanf("%s", s.cognome);
    
    printf("\tNumero degli esami conseguiti (max. %d): ", MAX_ESAMI);
    scanf("%d", &s.nEsami);
    
    printf("\tInserimento esami:\n\n");
    for (i = 0; i < s.nEsami; i++) {
        printf("\t\tVoto dell'esame n.%d: ", (i + 1));
        scanf("%d", &s.votiEsami[i]);
        printf("\n");
    }
    
    printf("\nInserimento dello studente completato.\n");
    
    system("pause");
    system("cls");
    
    return s;
}

int main(void) {
    struct Studente stud[MAX_STUD];
    int n;
    int i;
    
    printf("Digitare il numero degli studenti da inserire (max. %d): ", MAX_STUD);
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        stud[i] = inserisciStudente();
    }
    
    n = maggioreDiK(stud, n, 25);
    printf("%d\n", n);
    
    system("pause");
    return 0;
}
