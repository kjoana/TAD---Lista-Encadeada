// ALUNO(A) : JOANA KUELVIA DE ARAUJO SILVA

#include "lista_pilha.h"
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

SLList* createSLList() {
    SLList* sllist = (SLList*)malloc(sizeof(SLList));
    sllist->top = NULL;
    return sllist;
}

// Função para verificar se está vazia
int isSLListEmpty(SLList* sllist) {
    return sllist->top == NULL;
}

void SLLAddNode(SLList* sllist, int linha, int coluna) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->linha = linha;
    newNode->coluna = coluna;
    newNode->next = sllist->top;
    sllist->top = newNode;
}

void SLLRemoveNode(SLList* sllist) {
    if (isSLListEmpty(sllist)) {
        printf("Erro: a pilha está vazia.\n");
        exit(1);
    }
    Node* topNode = sllist->top;
    sllist->top = topNode->next;
    free(topNode);
}

Node* SLLFirstNode(SLList *l)  {
    if (isSLListEmpty(l)) {
        printf("Erro: a pilha está vazia.\n");
        exit(1);
    }
    return l->top;
}

// Função para destruir a lista
void destroySLList(SLList* sllist) {
    Node* current = sllist->top;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(sllist);
}
