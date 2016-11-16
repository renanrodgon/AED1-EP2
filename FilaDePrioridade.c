#include "FilaDePrioridade.h"

PFILA criarFila(int max){
  PFILA res = (PFILA) malloc(sizeof(FILADEPRIORIDADE));
  res->maxRegistros = max;
  res->arranjo = (PONT*) malloc(sizeof(PONT)*max);
  res->heap = (PONT*) malloc(sizeof(PONT)*max);
  int i;
  for (i=0;i<max;i++) {
    res->arranjo[i] = NULL;
    res->heap[i] = NULL;
  }
  res->elementosNoHeap = 0;
  return res;
}

bool exibirLog(PFILA f){
  printf("Log [elementos: %i]\n", f->elementosNoHeap);
  PONT atual;
  int i;
  for (i=0;i<f->elementosNoHeap;i++){
    atual = f->heap[i];
    printf("[%i;%f;%i] ", atual->id, atual->prioridade, atual->posicao);
  }
  printf("\n\n");
}

void testaTamanho(int tam){
	printf("O tamanho e: %d\n", tam);
}

int tamanho(PFILA f){
  return f->elementosNoHeap;
}

bool inserirElemento(PFILA f, int id, float prioridade){
  if(id<0 || id>= f->maxRegistros ) return false;//id inválido
  if(f->arranjo[id]) return false;//já existe um registro com esse id
  PONT novo = (PONT) malloc(sizeof(PONT));//aloca memória para novo Registro
  novo->id = id;//atribui valor de id
  novo->prioridade = prioridade;// atribui valor de prioridade
  f->arranjo[id] = novo;//arranjo recebe o endereço de novo
  if(f->elementosNoHeap == 0){// se novo for o primeiro registro do heap
	  novo->posicao = f->elementosNoHeap;//a posição é definida com valor 0 (primeira posição)
	  f->heap[novo->posicao] = novo;//heap recebe em seu índice novo na posicao adequada
	  f->elementosNoHeap++;//o número de elementos no heap é incrementado
	  return true;
  }
  if(f->elementosNoHeap > 0){
	  novo->posicao = f->elementosNoHeap;
	  f->heap[novo->posicao] = novo;
  }


  return false;
}

bool aumentarPrioridade(PFILA f, int id, float novaPrioridade){
  /* completar */
  return false;
}

bool reduzirPrioridade(PFILA f, int id, float novaPrioridade){
  /* completar */
  return false;
}

PONT removerElemento(PFILA f){
  /* completar */
  return NULL;
}

bool consultarPrioridade(PFILA f, int id, float* resposta){
  /* completar */
  return false;
}

