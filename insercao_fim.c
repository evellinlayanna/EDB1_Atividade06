// // Função de inserção no fim da lista.
// void insercao_no_fim_da_lsl(No **cabeca, int valor) {
//   No *novo_no = malloc(sizeof(No));
//   novo_no->valor = valor;
//   novo_no->proximo = NULL;

//   if (*cabeca == NULL) {
//     *cabeca = novo_no;
//     return;
//   }

//   No *atual = *cabeca;

//   while (atual->proximo != NULL) {
//     atual = atual->proximo;
//   }

//   atual->proximo = novo_no;
// }