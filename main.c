#include <stdio.h>
#include <stdlib.h>

// Declaração da estrutura 'no'
struct no {
  int valor;
  struct no *proximo;
};

// Definição do tipo 'No'
typedef struct no No;

// Função de inserção no início da lista
void insercao_inicio_lista(No **cabeca, int valor) {
  No *novo_no = malloc(sizeof(No));
  novo_no->valor = valor;
  novo_no->proximo = *cabeca;
  *cabeca = novo_no;
}

// Função de inserção no fim da lista
void insercao_fim_lista(No **cabeca, int valor) {
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

// Função de inserção em uma posição intermediária da lista
void insercao_meio_lista(No **cabeca, int valor, int posicao) {
  if (posicao == 0) {
    (cabeca, valor);
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

// Função de remoção no início da lista
void remocao_inicio_lista(No **cabeca) {
  if (*cabeca == NULL) {
    printf("A lista está vazia\n");
    return;
  }

  No *temp = *cabeca;
  *cabeca = (*cabeca)->proximo;
  free(temp);
}

// Função de remoção no fim da lista
void remocao_fim_lista(No abeca) {
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

// Função de remoção em uma posição intermediária da lista
void remocao_meio_lista(No **cabeca, int valor) {
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

// Função de impressão de valores da lista
void imprime_lista(No *cabeca) {
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

// Função de busca por valor na lista
void busca_valor_lista(No *cabeca, int valor) {
  No *atual = cabeca;

  while (atual != NULL && atual->valor != valor) {
    atual = atual->proximo;
  }

  if (atual != NULL)
    printf("\nValor %d encontrado\n", valor);
  else
    printf("\nValor %d não encontrado\n", valor);
}

// Função de varredura da lista
void percorre_lista(No *cabeca) {
  No *atual = cabeca;
  int total = 0;

  while (atual != NULL) {
    total = total + atual->valor;
    atual = atual->proximo;
  }
  printf("Total = %d.\n", total);
}

int main() {
  // Cria uma lista simplesmente ligada e vazia
  No *cabeca = NULL;

  printf("Inserido 10 e 20 no início da lista");

  printf("\nLista após as inserções no início: ");
  imprime_lista(cabeca);

  printf("\nInserindo 40 e 50 no fim da lista");
  insercao_fim_lista(&cabeca, 40);
  insercao_fim_lista(&cabeca, 50);

  printf("\nLista após as inserções no fim: ");
  imprime_lista(cabeca);

  printf("\nInserindo 25 na posição 3 da lista");
  insercao_meio_lista(&cabeca, 25, 3);

  printf("\nLista após a inserção no meio: ");
  imprime_lista(cabeca);

  printf("\nRemovendo o elemento do início da lista");
  remocao_inicio_lista(&cabeca);

  printf("\nLista após a remoção do início: ");
  imprime_lista(cabeca);

  printf("\nRemovendo o elemento do fim da lista");
  remocao_fim_lista(&cabeca);

  printf("\nLista após a remoção do fim: ");
  imprime_lista(cabeca);

  printf("\nRemovendo o elemento de valor 25 da lista");
  remocao_meio_lista(&cabeca, 25);
  
  printf("\nLista após a remoção do meio (valor 25): ");
  imprime_lista(cabeca);
  int valor_busca;
  (&cabeca, 25);

  printf("\nLista após a remoção do meio (valor 25): ");
  imprime_lista(cabeca);

  // Busca por um valor na lista
  int valor_busca;
  printf("\nDigite o valor que deseja buscar: ");
  scanf("%d", &valor_busca);
  busca_valor_lista(cabeca, valor_busca);

  printf("\nVarrendo a lista para somar os valores");
  percorre_lista(cabeca);

  return 0;
}