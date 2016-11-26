#include "FilaDePrioridade.h"

int main() {

	PFILA f = criarFila(10);
  //exibirLog(f);
  if(inserirElemento(f, 1, 1)) printf("ok\n");
  else printf("nok (1)\n");
  //exibirLog(f);
  if(inserirElemento(f, 3, 3)) printf("ok\n");
  else printf("nok (2)\n");
  //exibirLog(f);
  if(inserirElemento(f, 2, 2)) printf("ok\n");
  else printf("nok (3)\n");
  //exibirLog(f);
  if(inserirElemento(f, 0, 0)) printf("ok\n");
  else printf("nok (4)\n");
  //exibirLog(f);
  if(inserirElemento(f, 5, 5)) printf("ok\n");
  else printf("nok (5)\n");
  //exibirLog(f);
  if(aumentarPrioridade(f, 5, 10)) printf("ok\n");
  else printf("nok (6)\n");
  //exibirLog(f);
  if(aumentarPrioridade(f, 0, 15)) printf("ok\n");
  else printf("nok (7)\n");
  //exibirLog(f);
  if(aumentarPrioridade(f, 3, 4)) printf("ok\n");
  else printf("nok (8)\n");
  //exibirLog(f);
  if(aumentarPrioridade(f, 3, 4)) printf("ok\n");
  else printf("nok (9) - esperado, pois a nova prioridade nao eh maior\n");
  //exibirLog(f);
  if(aumentarPrioridade(f, 4, 4)) printf("ok\n");
  else printf("nok (10) - esperado, elemento com id=4 nao existe\n");
  exibirLog(f);

  // COMEÇO MEUS TESTES DE CONSULTAR

  /*float resposta = 0;

  if(consultarPrioridade(f, 15, &resposta)) printf("Esta errado! Nao deu pq o id e invalido\n");
  else printf("Esta certo! Nao deu pq o id e invalido\n");

  if(consultarPrioridade(f, -1, &resposta)) printf("Esta errado! Nao deu pq o id e invalido\n");
  else printf("Esta certo! Nao deu pq o id e invalido\n");

  if(consultarPrioridade(f, 4, &resposta)) printf("Esta errado! nao existe um id como esse no arranjo\n");
  else printf("Esta certo! nao existe um id como esse no arranjo\n");

  if(consultarPrioridade(f, 5, &resposta)) printf("Esta Certo! e a prioridade e: %f\n", resposta);
  else printf("Esta Errado! e a prioridade e: %f\n", resposta);*/

  // FIM MEUS TESTES DE CONSULTAR

  // COMEÇO MEUS TESTES DE REDUÇÃO

  /*if(reduzirPrioridade(f, 15, 0)) printf("Esta errado ! Nao deu pq o id e invalido\n");
  else printf("Esta certo ! Nao deu pq o id e invalido\n");
  exibirLog(f);

  if(reduzirPrioridade(f, -1, 0)) printf("Esta errado ! Nao deu pq o id e invalido\n");
  else printf("Esta certo ! Nao deu pq o id e invalido\n");
  exibirLog(f);

  if(reduzirPrioridade(f, 4, 0)) printf("Esta errado ! nao existe um id como esse no arranjo\n");
  else printf("Esta certo ! nao existe um id como esse no arranjo\n");
  exibirLog(f);

  if(reduzirPrioridade(f, 5, 10)) printf("Esta errado ! A prioridade desse id ja e igual a nova prioridade\n");
  else printf("Esta certo ! A prioridade desse id ja e igual a nova prioridade\n");
  exibirLog(f);

  if(reduzirPrioridade(f, 5, 11)) printf("Esta errado ! A prioridade desse id e maior que nova prioridade\n");
  else printf("Esta certo ! A prioridade desse id e maior que nova prioridade\n");
  exibirLog(f);

  if(reduzirPrioridade(f, 3, 0)) printf("Esta certo ! Era uma folha do heap\n");
  else printf("Esta errado ! Era uma folha do heap\n");
  exibirLog(f);

  if(reduzirPrioridade(f, 5, 9)) printf("Esta certo ! Continua maior que os filhos\n");
  else printf("Esta errado ! Continua maior que os filhos\n");
  exibirLog(f);

  if(reduzirPrioridade(f, 0, 9)) printf("Esta certo ! Se tornou menor que os filhos, mas nao folha\n");
  else printf("Esta errado ! Se tornou menor que os filhos, mas nao folha\n");
  exibirLog(f);

  if(reduzirPrioridade(f, 0, 0)) printf("Esta certo ! Se tornou menor que os filhos, e folha\n");
  else printf("Esta errado ! Se tornou menor que os filhos, e folha\n");
  exibirLog(f);

  if(reduzirPrioridade(f, 5, 4)) printf("Esta certo ! Se tornou igual ao filho maior e nao mudou\n");
  else printf("Esta errado ! Se tornou igual ao filho maior e nao mudou\n");
  exibirLog(f);

  if(reduzirPrioridade(f, 5, 1)) printf("Esta certo ! Se tornou igual ao filho menor e mudou\n");
  else printf("Esta errado ! Se tornou igual ao filho menor e mudou\n");
  exibirLog(f);

  if(aumentarPrioridade(f, 1, 4) && reduzirPrioridade(f, 5, 4)) printf("Esta certo ! Nao deveria mudar pois estao todos iguais\n");
  else printf("Esta errado ! Nao deveria mudar pois estao todos iguais\n");
  exibirLog(f);*/
  // FIM MEUS TESTES DE REDUÇÃO

  /*PONT prioritario;
  prioritario = removerElemento(f);
  if (prioritario) printf("Prioritario: %i, %f\n", prioritario->id, prioritario->prioridade);
  else printf("Fila vazia (1)\n");
  exibirLog(f);
  prioritario = removerElemento(f);
  if (prioritario) printf("Prioritario: %i, %f\n", prioritario->id, prioritario->prioridade);
  else printf("Fila vazia (2)\n");
  exibirLog(f);
  prioritario = removerElemento(f);
  if (prioritario) printf("Prioritario: %i, %f\n", prioritario->id, prioritario->prioridade);
  else printf("Fila vazia (3)\n");
  exibirLog(f);
  prioritario = removerElemento(f);
  if (prioritario) printf("Prioritario: %i, %f\n", prioritario->id, prioritario->prioridade);
  else printf("Fila vazia (4)\n");
  exibirLog(f);
  prioritario = removerElemento(f);
  if (prioritario) printf("Prioritario: %i, %f\n", prioritario->id, prioritario->prioridade);
  else printf("Fila vazia (5)\n");
  exibirLog(f);
  prioritario = removerElemento(f);
  if (prioritario) printf("Prioritario: %i, %f\n", prioritario->id, prioritario->prioridade);
  else printf("Fila vazia (6)\n");
  exibirLog(f);
  prioritario = removerElemento(f);
  if (prioritario) printf("Prioritario: %i, %f\n", prioritario->id, prioritario->prioridade);
  else printf("Fila vazia (7)\n");
  exibirLog(f);

  if(inserirElemento(f, 1, 1)) printf("ok\n");
  else printf("nok (10)\n");
  exibirLog(f);
  if(inserirElemento(f, 3, 3)) printf("ok\n");
  else printf("nok (11)\n");
  exibirLog(f);
  if(inserirElemento(f, 2, 2)) printf("ok\n");
  else printf("nok (12)\n");
  exibirLog(f);
  if(inserirElemento(f, 0, 0.5)) printf("ok\n");
  else printf("nok (13)\n");
  exibirLog(f);
  if(inserirElemento(f, 5, 5)) printf("ok\n");
  else printf("nok (14)\n");
  exibirLog(f);

  printf("\n\nReduzindo prioridade\n");


  if(reduzirPrioridade(f, 5, 0)) printf("ok\n");
  else printf("nok (15)\n");
  exibirLog(f);
  if(reduzirPrioridade(f, 0, 1)) printf("ok\n");
  else printf("nok (16) - esperado, nova prioridade eh maior\n");
  exibirLog(f);
  if(reduzirPrioridade(f, 3, 2)) printf("ok\n");
  else printf("nok (17)\n");
  exibirLog(f);
  if(reduzirPrioridade(f, 3, 1.5)) printf("ok\n");
  else printf("nok (18) - esperado, nova prioridade eh igual\n");
  exibirLog(f);
  if(reduzirPrioridade(f, 4, 1)) printf("ok\n");
  else printf("nok (19) - esperado, elemento com id=4 nao existe\n");
  exibirLog(f);*/



  return 0;
}
