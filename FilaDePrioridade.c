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

int maior(PONT esquerda, PONT direita){
	if(esquerda->prioridade >= direita->prioridade) return esquerda->posicao;
	else return direita->posicao;
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
  if(f->elementosNoHeap == 0) return NULL;//caso a fila não possua elementos
  PONT removido = f->heap[0];//raiz removida tem endereço guardado em um ponteiro
  f->arranjo[removido->id] = NULL;//o elemento é removido do arranjo arranjo
  if(f->elementosNoHeap == 1){//caso exista apenas um elemento na fila
	f->heap[0] = NULL;//o elemento é removido do arranjo heap
	f->elementosNoHeap--;//número de elemento no heap é decrementado
	return removido;//elemento removido é retornado
  }
  PONT realocado = f->heap[f->elementosNoHeap-1];//é criado um ponteiro para o atual último elemento do heap
  f->heap[0] = realocado;//a raiz do heap recebe o último elemento
  f->heap[f->elementosNoHeap-1] = NULL;//o lugar onde o último elemento ficava está vazio agora
  /*realocado->posicao = 0;//o elemento realocado agora tem sua posição setada para a raiz do heap
  f->elementosNoHeap--;//número de elemento no heap é decrementado
  //teste para saber se o registro realocado é uma folha do heap
  if(f->heap[esquerda(realocado->posicao)] == NULL && f->heap[direita(realocado->posicao)] == NULL) return removido;
  //teste para saber se o registro realocado é menor que seus filhos
  if(f->heap[realocado->posicao]->prioridade < f->heap[esquerda(realocado->posicao)]->prioridade || f->heap[realocado->posicao]->prioridade < f->heap[direita(realocado->posicao)]->prioridade){
	  //esquanto o registro realocado não for folha ou enquanto for menor que seus filhos serão feitas trocas sucessivas
	  while((f->heap[esquerda(realocado->posicao)] != NULL && f->heap[realocado->posicao]->prioridade < f->heap[esquerda(realocado->posicao)]->prioridade)
			  || (f->heap[direita(realocado->posicao)] != NULL && f->heap[realocado->posicao]->prioridade < f->heap[direita(realocado->posicao)]->prioridade))
	  {
		  int idaux = realocado->id;//guardando o id de realocado em uma var temp
		  int prioridadeaux = realocado->prioridade;//guardando a prioridade de realocado em uma var temp
		  int posmaior = maior(f->heap[esquerda(realocado->posicao)], f->heap[direita(realocado->posicao)]);
		  realocado->id = f->heap[posmaior]->id;//realocado recebe o id do maior
		  realocado->prioridade = f->heap[posmaior]->prioridade;//realocado recebe o id do maior
		  f->arranjo[realocado->id] = realocado;//ajustando o arranjo para o realocado
		  f->heap[posmaior]->id = idaux;//o maior recebe o id de realocado
		  f->heap[posmaior]->prioridade = prioridadeaux;//o maior recebe a prioridade de realocado
		  realocado = f->heap[posmaior];// o realocado se torna o maior e o maior se torna o realocado
		  f->arranjo[realocado->id] = realocado;// ajustando o arranjo para o maior
	  }
  }*/
  return removido;
}

bool consultarPrioridade(PFILA f, int id, float* resposta){
  /* completar */
  return false;
}

