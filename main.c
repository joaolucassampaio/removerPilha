#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
  int info;
  struct node *next;
};

int main (int argc, char *argv[]){
  struct node *topo, *p, *q, *r, *z, *w, *pilhaAux;
  int count = 0;
  topo = NULL;
  pilhaAux = NULL;

  srand (time (NULL));

  //Empilhando
  while (count < 5){
	  p = malloc (sizeof (struct node));
	  p->info = rand () % 100;
	  p->next = topo;
	  topo = p;
	  count++;
	}

  //Imprimindo Pilha:
  r = topo;
  printf ("Pilha original:\n");
  while (r != NULL){
	  printf ("%d\n", r->info);
	  r = r->next;
	}

  //Encontrando terceiro no
  count = 0;
  q = topo;
  printf ("\nTerceiro no: ");
  while (count < 2){
	  q = q->next;
	  count++;
	}
  printf ("%d\n", q->info);

  //Desempilhando
  count = 0;
  while (count <= 2){
	  z = topo;
	  topo = topo->next;

	  if (count == 2)
		{
		  free (z);
		}
	  else
		{
		  z->next = pilhaAux;
		  pilhaAux = z;
		}
	  count++;
	}
    
    //Se eu printar isso aqui a pilha não funciona
    w = pilhaAux;
    // Imprimindo os nos colocados na pilha auxiliar
    printf ("\nNos na pilha auxiliar:\n");
    while (w != NULL){
	  printf ("%d\n", w->info);
	  w = w->next;
	}
    
    //Empilhando de volta
    while (pilhaAux != NULL){
        z = pilhaAux;
        pilhaAux = pilhaAux->next;
        z->next = topo; // Atualiza o próximo nó do elemento desempilhado para apontar para o topo da pilha principal
        topo = z; // Atualiza o topo da pilha principal para apontar para o elemento desempilhado
    }

  //Imprimindo pilha apos empilhar de volta
  printf ("\nPilha apos empilhar de volta:\n");
  z = topo;
  while (z != NULL){
	  printf ("%d\n", z->info);
	  z = z->next;
	}

  return 0;
}
