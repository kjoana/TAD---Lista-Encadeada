
// ALUNO(A) : JOANA KUELVIA DE ARAUJO SILVA

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista_pilha.h"


// Função para imprimir a matriz
void mostrarMatriz(int** matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para gerar uma matriz nxn com números aleatórios de 0 a 9
int** gerarMAtriz(int n) {
    int** matriz = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matriz[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            matriz[i][j] = rand() % 10;
        }
    }
    return matriz;
}

// Função para trocar o número da célula e seus vizinhos de mesmo valor
void trocarNumeros(int** matriz, int n, int linha, int coluna, int antigoNum, int novoNum, SLList* sllist) {
    if (linha >= 0 && linha < n && coluna >= 0 && coluna < n && matriz[linha][coluna] == antigoNum) {
        matriz[linha][coluna] = novoNum;
      // adiciona as coordenadas da posição na pilha
        SLLAddNode(sllist, linha , coluna);
      
    }
}

// Função para realizar a troca na matriz
void preenchimentoMatriz(int** matriz, int n, int linha, int coluna, int antigoNum, int novoNum) {
    SLList* l = createSLList();
    SLLAddNode(l, linha, coluna);

    while (!isSLListEmpty(l)) {
        Node* top = SLLFirstNode(l);
        int currentLinha = top->linha;
        int currentColuna = top->coluna;
        SLLRemoveNode(l);

        // Trocar número atual e verificar vizinhos
        trocarNumeros(matriz, n, currentLinha - 1, currentColuna, antigoNum, novoNum, l); // Vizinho acima
        trocarNumeros(matriz, n, currentLinha + 1, currentColuna, antigoNum, novoNum, l); // Vizinho abaixo
        trocarNumeros(matriz, n, currentLinha, currentColuna - 1, antigoNum, novoNum, l); // Vizinho esquerdo
        trocarNumeros(matriz, n, currentLinha, currentColuna + 1, antigoNum, novoNum, l); // Vizinho direito
    }

    destroySLList(l);
}

int **selecionarmatriz (int **m,int n) {
  for (int i=0;i<n;i++) {
    for (int j=0; j<n; j++) {
      printf("\n[%d][%d]: ",i,j);
      scanf("%d",&m[i][j]);
    }
  }
  return m;
}

int main() {

    srand(time(NULL));

    int n; // Tamanho da matriz
    printf("Digite o tamanho da matriz (n): ");
    scanf("%d", &n);
    printf ("");

    int** matriz = (int**) malloc(sizeof(int*)*n);

    for (int i=0;i<n;i++) {
        matriz[i] = (int *) malloc(sizeof(int)*n);
    }
    matriz = selecionarmatriz(matriz,n);

    printf("Matriz gerada:\n");
    mostrarMatriz(matriz, n);

    int linha, coluna; // Coordenadas da célula escolhida pelo usuário
    printf("Digite as coordenadas da celula de inicio (linha coluna): ");
    scanf("%d %d", &linha, &coluna);

    int antigoNum = matriz[linha][coluna]; // Número da célula escolhida
    int novoNum; // Novo número para troca
    printf("Digite o novo numero que deseja trocar: ");
    scanf("%d", &novoNum);

    preenchimentoMatriz(matriz, n, linha, coluna, antigoNum, novoNum);

    printf("Matriz Preenchida:\n");
    mostrarMatriz(matriz, n);

    // Liberação de memória
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}