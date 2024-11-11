// // Função de remoção no fim da lista.
// void remocao_no_fim_da_lsl(No **cabeca) {
//   if (*cabeca == NULL || (*cabeca)->proximo == NULL) {
//     remocao_no_inicio_da_lsl(cabeca);
//     return;
//   }

//   No *anterior = NULL;
//   No *atual = *cabeca;

//   while (atual->proximo != NULL) {
//     anterior = atual;
//     atual = atual->proximo;
//   }

//   anterior->proximo = NULL;

//   free(atual);
// }