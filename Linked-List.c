#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} node;

typedef struct {
    struct node *first;
} list;

list *makelist(void) {
    list *l = (list *)malloc(sizeof(list));
    l->first = NULL;
    return l;
}

void creatlist(list *l, int v) {
    node *n = (node *)malloc(sizeof(node));
    n->info = v;
    n->next = NULL;
    if (l->first == NULL) {
        l->first = n;
    } else {
        node *p = l->first;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = n;
    }
}

void firstnode(list *l, int v) {
    node *n = (node *)malloc(sizeof(node));
    n->info = v;
    n->next = l->first;
    l->first = n;
}

void maddnode(list *l, int p, int v) {
    node *n = (node *)malloc(sizeof(node));
    n->info = v;
    node *t = l->first;
    while (t != NULL && t->info != p) {
        t = t->next;
    }
    if (t != NULL) {
        n->next = t->next;
        t->next = n;
    } else {
        printf("Previous node not found.\n");
        free(n);
    }
}

void laddnode(list *l, int v) {
    node *n = (node *)malloc(sizeof(node));
    n->info = v;
    n->next = NULL;
    if (l->first == NULL) {
        l->first = n;
    } else {
        node *p = l->first;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = n;
    }
}

void printlist(list *l) {
    node *t = l->first;
    while (t != NULL) {
        printf("%d -> ", t->info);
        t = t->next;
    }
    printf("NULL\n");
}

void dellist(list *l, int v) {
    node *t = l->first;
    node *s = NULL;
    while (t != NULL && t->info != v) {
        s = t;
        t = t->next;
    }
    if (t != NULL) {
        if (s != NULL) {
            s->next = t->next;
        } else {
            l->first = t->next; // Deleting the first node
        }
        free(t);
    } else {
        printf("Value not found in the list.\n");
    }
}

int main() {
    list *ls;
    int a, i, v, p;
    ls = makelist();
    printf("Enter values in list (5 values):\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &a);
        creatlist(ls, a);
    }
    printlist(ls);
    
    printf("Enter first node value in list: ");
    scanf("%d", &v);
    firstnode(ls, v);
    printlist(ls);}