/*15 - Faça um programa para criar um arquivo chamado PRODUTOS.txt,
onde cada registro será composto pelos seguintes campos: codigo, descricao
e preco.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
  {
  FILE* arq_prod = fopen("PRODUTOS.txt", "w");
  int total, i;

  if (arq_prod == NULL)
    {
    printf("Erro ao criar arquivo\n");
    return 1;
    }

  printf("Quantos itens deseja registrar: ");
  scanf("%d", &total);
  getchar();

  for (i = 0; i < total; i++)
    {
    int id_item;
    char nome_item[100];
    float valor;

    printf("Codigo do item: ");
    scanf("%d", &id_item);
    getchar();

    printf("Descricao do item: ");
    fgets(nome_item, sizeof(nome_item), stdin);
    nome_item[strcspn(nome_item, "\n")] = 0;

    printf("Valor do item: ");
    scanf("%f", &valor);
    getchar();

    fprintf(arq_prod, "%d,%s,%.2f\n", id_item, nome_item, valor);
    }

  fclose(arq_prod);
  printf("Arquivo PRODUTOS.txt gerado com sucesso\n");

  return 0;
  }
