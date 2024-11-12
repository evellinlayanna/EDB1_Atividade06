// // Função de remoção em uma posição intermediária da lista.
// void remocao_no_meio_da_lsl(No **cabeca, int valor) {
//   if (*cabeca == NULL) {
//     printf("Lista vazia!\n");
//     return;
//   }

//   No *anterior = NULL;
//   No *atual = *cabeca;

//   while (atual != NULL && atual->valor != valor) {
//     anterior = atual;
//     atual = atual->proximo;
//   }

//   if (atual == NULL) {
//     printf("Valor inexistente na lista!\n");
//     return;
//   }

//   if (anterior == NULL) {
//     *cabeca = atual->proximo;
//   } else {
//     anterior->proximo = atual->proximo;
//   }

//   free(atual);
// }