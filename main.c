#include <stdio.h>
#include <stdlib.h>

// Declaração da estrutura 'no'.
struct no {
  int valor;
  struct no *proximo;
};

// Definição do tipo 'No'.
typedef struct no No;

// Função de inserção no início da lista.
void insercao_no_inicio_da_lsl(No **cabeca, int valor) {
  No *novo_no = malloc(sizeof(No));
  novo_no->valor = valor;
  novo_no->proximo = *cabeca;
  *cabeca = novo_no;
}

// Função de inserção no fim da lista.
void insercao_no_fim_da_lsl(No **cabeca, int valor) {
  No *novo_no = malloc(sizeof(No));
  novo_no->valor = valor;
  novo_no->proximo = NULL;

  if (*cabeca == NULL) {
    *cabeca = novo_no;
    return;
  }

  No *atual = *cabeca;

  while (atual->proximo != NULL) {
    atual = atual->proximo;
  }

  atual->proximo = novo_no;
}

// Função de inserção em uma posição intermediária da lista.
void insercao_no_meio_da_lsl(No **cabeca, int valor, int posicao) {
  if (posicao == 0) {
    insercao_no_inicio_da_lsl(cabeca, valor);
    return;
  }

  No *anterior = NULL;
  No *atual = *cabeca;
  int i = 0;

  while (atual != NULL && i < posicao) {
    anterior = atual;
    atual = atual->proximo;
    i++;
  }

  if (atual == NULL) {
    printf("Posição inválida\n");
    return;
  }

  No *novo_no = malloc(sizeof(No));
  novo_no->valor = valor;
  novo_no->proximo = atual;

  if (anterior != NULL) {
    anterior->proximo = novo_no;
  } else {
    *cabeca = novo_no;
  }
}

// Função de remoção no início da lista.
void remocao_no_inicio_da_lsl(No **cabeca) {
  if (*cabeca == NULL) {
    printf("A lista está vazia\n");
    return;
  }

  No *temp = *cabeca;
  *cabeca = (*cabeca)->proximo;
  free(temp);
}

// Função de remoção no fim da lista.
void remocao_no_fim_da_lsl(No **cabeca) {
  if (*cabeca == NULL) {
    printf("A lista está vazia\n");
    return;
  }

  if ((*cabeca)->proximo == NULL) {
    free(*cabeca);
    *cabeca = NULL;
    return;
  }

  No *anterior = *cabeca;
  No *atual = (*cabeca)->proximo;

  while (atual->proximo != NULL) {
    anterior = atual;
    atual = atual->proximo;
  }

  anterior->proximo = NULL;
  free(atual);
}

// Função de remoção em uma posição intermediária da lista.
void remocao_no_meio_da_lsl(No **cabeca, int valor) {
  if (*cabeca == NULL) {
    printf("Lista vazia\n");
    return;
  }

  No *anterior = NULL;
  No *atual = *cabeca;

  while (atual != NULL && atual->valor != valor) {
    anterior = atual;
    atual = atual->proximo;
  }

  if (atual == NULL) {
    printf("Valor inexistente na lista\n");
    return;
  }

  if (anterior == NULL) {
    *cabeca = atual->proximo;
  } else {
    anterior->proximo = atual->proximo;
  }

  free(atual);
}

// Função de impressão de valores da lista.
void imprime_a_lsl(No *cabeca) {
  if (cabeca == NULL) {
    printf("Lista vazia\n");
    return;
  }

  No *atual = cabeca;

  while (atual != NULL) {
    printf("%d ", atual->valor);
    atual = atual->proximo;
  }
  printf("\n");
}

// Função de busca por valor na lista.
void busca_por_valor_na_lsl(No *cabeca, int valor) {
  No *atual = cabeca;

  while (atual != NULL && atual->valor != valor) {
    atual = atual->proximo;
  }

  if (atual != NULL)
    printf("\nValor %d encontrado\n", valor);
  else
    printf("\nValor %d não encontrado\n", valor);
}

// Função de varredura da lista.
void percorre_a_lsl(No *cabeca) {
  No *atual = cabeca;
  int total = 0;

  while (atual != NULL) {
    total = total + atual->valor;
    atual = atual->proximo;
  }
  printf("Total = %d.\n", total);
}

int main() {
  // Cria uma lista simplesmente ligada vazia.
  No *cabeca = NULL;

  // Insere elementos no início da lista.
  printf("Inserido 10 e 20 no início da lista"); // Adicionando 10 e 20 no início da lista
  insercao_no_inicio_da_lsl(&cabeca, 10);
  insercao_no_inicio_da_lsl(&cabeca, 20);

  // Imprime a lista.
  printf("\nLista após as inserções no início: "); // Imprimindo a lista após inserir 10 e 20
  imprime_a_lsl(cabeca);

  // Insere elementos no fim da lista.
  printf("\nInserindo 40 e 50 no fim da lista"); // Adicionando 40 e 50 ao fim da lista
  insercao_no_fim_da_lsl(&cabeca, 40);
  insercao_no_fim_da_lsl(&cabeca, 50);

  // Imprime a lista.
  printf("\nLista após as inserções no fim: "); // Imprimindo a lista após inserir 40 e 50
  imprime_a_lsl(cabeca);

  // Insere elemento em uma posição intermediária da lista.
  printf("\nInserindo 25 na posição 3 da lista"); // Inserindo 25 na posição 3 da lista
  insercao_no_meio_da_lsl(&cabeca, 25, 3);

  // Imprime a lista.
  printf("\nLista após a inserção no meio: "); // Imprimindo a lista após inserir 25 na posição 3
  imprime_a_lsl(cabeca);

  // Remove no início da lista.
  printf("\nRemovendo o elemento do início da lista"); // Removendo o elemento do início da lista
  remocao_no_inicio_da_lsl(&cabeca);

  // Imprime a lista.
  printf("\nLista após a remoção do início: "); // Imprimindo a lista após remover o elemento do início
  imprime_a_lsl(cabeca);

  // Remove no fim da lista.
  printf("\nRemovendo o elemento do fim da lista"); // Removendo o elemento do fim da lista
  remocao_no_fim_da_lsl(&cabeca);

  // Imprime a lista.
  printf("\nLista após a remoção do fim: "); // Imprimindo a lista após remover o elemento do fim
  imprime_a_lsl(cabeca);

  // Remove em uma posição intermediária na lista por valor.
  printf("\nRemovendo o elemento de valor 25 da lista"); // Removendo o elemento de valor 25 da lista
  remocao_no_meio_da_lsl(&cabeca, 25);

  // Imprime a lista.
  printf("\nLista após a remoção do meio (valor 25): "); // Imprimindo a lista após remover o elemento de valor 25
  imprime_a_lsl(cabeca);

  // Busca por um valor na lista.
  int valor_busca;
  printf("\nDigite o valor que deseja buscar: ");
  scanf("%d", &valor_busca);
  busca_por_valor_na_lsl(cabeca, valor_busca);

  // Varre a lista.
  printf("\nVarrendo a lista para somar os valores"); // Somando os valores da lista
  percorre_a_lsl(cabeca);

  return 0;
}