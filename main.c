#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
	int info;
	struct node *next;
};

int main(int argc, char *argv[]) {
	struct node *pilha, *p, *pilhaAux, *temp, *atual;
	int count = 0;
	pilha = NULL;
	
	srand(time(NULL));
	
	printf("Pilha original:\n");
	do {
		p = malloc(sizeof(struct node));
		p->info = rand()%100;
		p->next = pilha;
		pilha = p;
		count++;
		printf("%d ", p->info);
	}while(count < 5);
	
	pilhaAux = pilha;
	
	printf("\n%d", pilhaAux->info);
	
	count = 0;
	//Tá removendo o nó da frente do nó selecionado aqui
	while(count < 1) {
	    pilhaAux = pilhaAux->next;
	    count++;
	}
	printf("\n%d", pilhaAux->info);
	
	//O problema deve estar aqui
	//Não quero quero que remova o nó da frente do selecionado, mas sim o nó selecionado acima
	temp = pilhaAux->next;
	pilhaAux->next = pilhaAux->next->next;
    free(temp);
    
	printf("\nPilha apos a remocao:\n");
	struct node *prev = NULL;
	while (pilha != NULL) {
	    struct node *nextNode = pilha->next;
	    pilha->next = prev;
	    prev = pilha;
	    pilha = nextNode;
	}
	
	atual = prev;
	while(atual != NULL) {
	    printf("%d ", atual->info);
	    atual = atual->next;    
	}

	
	return 0;
	
}
