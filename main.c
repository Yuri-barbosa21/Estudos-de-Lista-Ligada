#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no{//estrutura para criação de um nó para um lista ligadas
    char info; //Informação a ser guardada no nó.
    struct no *prox; //Ponteiro para tipo de dados NÓ (aponta para um eventual 
                     //edenreço de memoria de um novo NÓ)
}No;

typedef No *Lista;//Ponteiro Lista para um tipo de dados nó;

Lista novo_no(char c){
    Lista novo = malloc(sizeof(No)); //Cria um novo Nó e aloca memoria necessária para tal.
    novo->info = c;//Insere a informação no novo no.
    novo->prox = NULL;//Endereço que o novo nó aponta é NULL. Pois ele não aponta
                      //para nenhum nó na lista;
    return novo;//Retorno o novo nó criado na lista.
}

Lista insere_inicio(Lista inicio, char info){
    Lista novo = novo_no(info);

    novo->prox = inicio;

    return novo;
}

Lista insere_final(Lista inicio, char info){
    if(inicio == NULL){
        return novo_no(info);
    }

    Lista p;
    for(p = inicio; p->prox != NULL; p = p->prox);
    p->prox = novo_no(info);
    return inicio;
}

void imprime(Lista inicio){
    Lista p;
    for(p = inicio; p != NULL; p = p->prox){
        printf("%c", p->info);
    }
    printf("\n");
}

void libera(Lista inicio){
    if(inicio != NULL) return;
    libera(inicio->prox);
    free(inicio);
}

int busca(Lista lista, char alvo){
    Lista p;
    for(p = lista; p != NULL; p = p->prox){
        if(p->info == alvo){
            return true;
        }
    }
    return false;
}

int main(void){
    Lista lista = NULL;

    
    lista = insere_inicio(lista, 'A');
    lista = insere_inicio(lista, 'B');
    lista = insere_inicio(lista, 'C');
    lista = insere_inicio(lista, 'D');

    imprime(lista);
    
    lista = insere_final(lista, 'E');
    
    imprime(lista);

    printf("\nResultado da busca na lista: %d", busca(lista, 'A'));
    printf("\nResultado da busca na lista: %d", busca(lista, 'B'));
    printf("\nResultado da busca na lista: %d", busca(lista, 'g'));
    printf("\nResultado da busca na lista: %d", busca(lista, 'E'));
    printf("\nResultado da busca na lista: %d", busca(lista, 'F'));
    
    return 0;
}
