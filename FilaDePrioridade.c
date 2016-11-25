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

int tamanho(PFILA f){
  return f->elementosNoHeap;
}

int pai(int i){
	return (i-1)/2;
}

int esquerda(int i){
	return 2*i+1;
}

int direita(int i){
	return 2*i+2;
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
  else{
	  novo->posicao = f->elementosNoHeap;
	  f->heap[novo->posicao] = novo;
	  f->elementosNoHeap++;
  }
  //se filho for maior que o pai ele trocarará até que seja menor que um pai ou até se tornar raiz
  if(novo->prioridade > f->heap[pai(novo->posicao)]->prioridade){
	  while(novo->posicao != 0 || novo->prioridade > f->heap[pai(novo->posicao)]->prioridade){
		  int idaux = novo->id;//guardando o id de novo em uma var temp
		  int prioridadeaux = novo->prioridade;//guardando a prioridade de novo em uma var temp
		  novo->id = f->heap[pai(novo->posicao)]->id;//o filho recebe o id do pai
		  novo->prioridade = f->heap[pai(novo->posicao)]->prioridade;//o filho recebe a prioridade do pai
		  f->arranjo[novo->id] = novo;//ajustando o arranjo para o filho
		  f->heap[pai(novo->posicao)]->id = idaux;//o pai recebe o id do filho
		  f->heap[pai(novo->posicao)]->prioridade = prioridadeaux;//o pai recebe a prioridade do filho
		  novo = f->heap[pai(novo->posicao)];// o pai se torna filho e o filho se torna pai
		  f->arranjo[novo->id] = novo;// ajustando o arranjo para o pai
	  }
  }
  return true;
}

bool aumentarPrioridade(PFILA f, int id, float novaPrioridade){
	if(id<0 || id>= f->maxRegistros ) return false;//id inválido
	if(f->arranjo[id] == NULL) return false;//se não existe um registro com esse id
	if(f->arranjo[id]->prioridade >= novaPrioridade) return false;//se a prioridade já maior ou igual a nova
	f->arranjo[id]->prioridade = novaPrioridade;//nova prioridade recebida
	if(f->arranjo[id] == f->heap[0]) return true;// se for o primeiro elemento do heap
	PONT aumentado = f->arranjo[id];
	//se filho for maior que o pai ele trocarará até que seja menor que um pai ou até se tornar raiz
	if(aumentado->prioridade > f->heap[pai(aumentado->posicao)]->prioridade){
		while(aumentado->posicao != 0 || aumentado->prioridade > f->heap[pai(aumentado->posicao)]->prioridade){
			int idaux = aumentado->id;//guardando o id de novo em uma var temp
			int prioridadeaux = aumentado->prioridade;//guardando a prioridade de novo em uma var temp
			aumentado->id = f->heap[pai(aumentado->posicao)]->id;//o filho recebe o id do pai
			aumentado->prioridade = f->heap[pai(aumentado->posicao)]->prioridade;//o filho recebe a prioridade do pai
			f->arranjo[aumentado->id] = aumentado;//ajustando o arranjo para o filho
			f->heap[pai(aumentado->posicao)]->id = idaux;//o pai recebe o id do filho
			f->heap[pai(aumentado->posicao)]->prioridade = prioridadeaux;//o pai recebe a prioridade do filho
			aumentado = f->heap[pai(aumentado->posicao)];// o pai se torna filho e o filho se torna pai
			f->arranjo[aumentado->id] = aumentado;// ajustando o arranjo para o pai
		}
	}
	return true;
}

bool reduzirPrioridade(PFILA f, int id, float novaPrioridade){
	if(id<0 || id>= f->maxRegistros ) return false;//id inválido
	if(f->arranjo[id] == NULL) return false;//se não existe um registro com esse id
	if(f->arranjo[id]->prioridade <= novaPrioridade) return false;//se a prioridade já maior ou igual a nova
	f->arranjo[id]->prioridade = novaPrioridade;//nova prioridade recebida
	PONT reduzido = f->arranjo[id];// criação de ponteiro para o registro reduzido
	//teste para saber se o registro reduzido era uma folha do heap
	if(f->heap[esquerda(reduzido->posicao)] == NULL && f->heap[direita(reduzido->posicao)] == NULL) return true;
	//falta implementar o teste de quando o pai permanece sendo maior que ambos os filhos
}

PONT removerElemento(PFILA f){
  /* completar */
  return NULL;
}

bool consultarPrioridade(PFILA f, int id, float* resposta){
  /* completar */
  return false;
}

