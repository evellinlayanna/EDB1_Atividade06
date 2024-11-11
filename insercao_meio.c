// // Função de inserção em uma posição intermediária da lista.
// void insercao_no_meio_da_lsl(No **cabeca, int valor, int posicao) {
//   if (posicao == 0) {
//     insercao_no_inicio_da_lsl(cabeca, valor);
//     return;
//   }

//   No *anterior = NULL;
//   No *atual = *cabeca;
//   int i = 0;

//   while (atual != NULL && i < posicao) {
//     anterior = atual;
//     atual = atual->proximo;
//     i++;
//   }

//   if (atual == NULL) {
//     printf("Posição inválida!\n");
//     return;
//   }

//   No *novo_no = malloc(sizeof(No));
//   novo_no->valor = valor;
//   novo_no->proximo = atual;

//   if (anterior != NULL) {
//     anterior->proximo = novo_no;
//   } else {
//     *cabeca = novo_no;
//   }
// }