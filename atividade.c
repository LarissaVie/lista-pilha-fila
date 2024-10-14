#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/*Lista Estática*/
int lista[MAX];
int tamanho_lista = 0;

void adicionar_lista(int valor) {
    if (tamanho_lista < MAX) {
        lista[tamanho_lista++] = valor;
    } else {
        printf("Cheia\n");
    }
}

void remover_lista(int valor) {
    int i;
    for (i = 0; i < tamanho_lista; i++) {
        if (lista[i] == valor) {
            for (int j = i; j < tamanho_lista - 1; j++) {
                lista[j] = lista[j + 1];
            }
            tamanho_lista--;
            return;
        }
    }
    printf("Nao encontrado\n");
}

void buscar_lista(int valor) {
    for (int i = 0; i < tamanho_lista; i++) {
        if (lista[i] == valor) {
            printf("Elemento %d encontrado na posicao %d\n", valor, i);
            return;
        }
    }
    printf("Nao encontrado\n");
}

/*Pilha Estática*/
int pilha[MAX];
int topo = -1;

void empilhar(int valor) {
    if (topo < MAX - 1) {
        pilha[++topo] = valor;
    } else {
        printf("Cheia\n");
    }
}

void desempilhar() {
    if (topo >= 0) {
        printf("Elemento %d removido\n", pilha[topo--]);
    } else {
        printf("Vazia\n");
    }
}

/*Fila Estática*/
int fila[MAX];
int frente = 0, tras = -1, tamanho_fila = 0;

void enfileirar(int valor) {
    if (tamanho_fila < MAX) {
        tras = (tras + 1) % MAX;
        fila[tras] = valor;
        tamanho_fila++;
    } else {
        printf("Cheia\n");
    }
}

void desenfileirar() {
    if (tamanho_fila > 0) {
        printf("Elemento %d removido\n", fila[frente]);
        frente = (frente + 1) % MAX;
        tamanho_fila--;
    } else {
        printf("Vazia\n");
    }
}

/*Lista Dinâmica*/
typedef struct NodoLista {
    int valor;
    struct NodoLista *proximo;
} NodoLista;

NodoLista *inicio_lista = NULL;

void adicionar_lista_dinamica(int valor) {
    NodoLista *novo = (NodoLista *)malloc(sizeof(NodoLista));
    novo->valor = valor;
    novo->proximo = inicio_lista;
    inicio_lista = novo;
}

void remover_lista_dinamica(int valor) {
    NodoLista *atual = inicio_lista, *anterior = NULL;
    while (atual != NULL) {
        if (atual->valor == valor) {
            if (anterior == NULL) {
                inicio_lista = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Nao encontrado\n");
}

void buscar_lista_dinamica(int valor) {
    NodoLista *atual = inicio_lista;
    while (atual != NULL) {
        if (atual->valor == valor) {
            printf("Elemento %d encontrado\n", valor);
            return;
        }
        atual = atual->proximo;
    }
    printf("Nao encontrado\n");
}

/*Pilha Dinâmica*/
typedef struct NodoPilha {
    int valor;
    struct NodoPilha *proximo;
} NodoPilha;

NodoPilha *topo_pilha = NULL;

void empilhar_dinamica(int valor) {
    NodoPilha *novo = (NodoPilha *)malloc(sizeof(NodoPilha));
    novo->valor = valor;
    novo->proximo = topo_pilha;
    topo_pilha = novo;
}

void desempilhar_dinamica() {
    if (topo_pilha != NULL) {
        NodoPilha *temp = topo_pilha;
        printf("Elemento %d removido\n", topo_pilha->valor);
        topo_pilha = topo_pilha->proximo;
        free(temp);
    } else {
        printf("Vazia\n");
    }
}

/*Fila Dinâmica*/
typedef struct NodoFila {
    int valor;
    struct NodoFila *proximo;
} NodoFila;

NodoFila *frente_fila = NULL, *tras_fila = NULL;

void enfileirar_dinamica(int valor) {
    NodoFila *novo = (NodoFila *)malloc(sizeof(NodoFila));
    novo->valor = valor;
    novo->proximo = NULL;
    if (tras_fila == NULL) {
        frente_fila = tras_fila = novo;
    } else {
        tras_fila->proximo = novo;
        tras_fila = novo;
    }
}

void desenfileirar_dinamica() {
    if (frente_fila != NULL) {
        NodoFila *temp = frente_fila;
        printf("Elemento %d removido\n", frente_fila->valor);
        frente_fila = frente_fila->proximo;
        if (frente_fila == NULL) {
            tras_fila = NULL;
        }
        free(temp);
    } else {
        printf("Vazia\n");
    }
}

/*Programa principal*/
int main() {
    int opcao;
    printf("Escolha a estrutura de dados:\n1. Lista Estatica\n2. Pilha Estatica\n3. Fila Estatica\n4. Lista Dinamica\n5. Pilha Dinamica\n6. Fila Dinamica\n");
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            adicionar_lista(10);
            adicionar_lista(20);
            buscar_lista(10);
            remover_lista(20);
            break;
        case 2:
            empilhar(30);
            desempilhar();
            break;
        case 3:
            enfileirar(40);
            desenfileirar();
            break;
        case 4:
            adicionar_lista_dinamica(50);
            buscar_lista_dinamica(50);
            remover_lista_dinamica(50);
            break;
        case 5:
            empilhar_dinamica(60);
            desempilhar_dinamica();
            break;
        case 6:
            enfileirar_dinamica(70);
            desenfileirar_dinamica();
            break;
        default:
            printf("Opcao invalida\n");
    }
    return 0;
}