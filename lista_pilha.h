
#define TRUE 1
#define FALSE 0

typedef struct Node {
    int linha;
    int coluna;
    struct Node* next;
} Node;

// Definição da estrutura da pilha
typedef struct {
    Node* top;
} SLList;

// SLList *SLLCreate();
// int SLLDestroy(SLList *l);
// int SLLAddNode(SLList *l, void *data);
// void *SLLRemoveNode(SLList *l);
// void *SLLFirstNode(SLList *l);


SLList* createSLList();
void SLLAddNode(SLList* sllist, int linha, int coluna) ;
int isSLListEmpty(SLList* sllist) ;
void SLLRemoveNode(SLList* sllist);
Node* SLLFirstNode(SLList *l) ;
void destroySLList(SLList* sllist);
