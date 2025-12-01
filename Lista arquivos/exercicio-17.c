/*17 - Faça um programa para consultar a descrição de todos os produtos que
possuem preço superior a R$ 500,00.*/

#include <stdio.h>
#include <stdlib.h>

int main()
  {
  FILE* arq = fopen("PRODUTOS.txt", "r");
  if (arq == NULL)
    {
    printf("Erro ao abrir arquivo\n");
    return 1;
    }

  int cod;
  char nomeItem[100];
  float valor;
  int achou = 0;

  printf("Produtos com preco maior que R$ 500,00:\n");

  while (fscanf(arq, "%d,%99[^,],%f\n", &cod, nomeItem, &valor) == 3)
    {
    if (valor > 500.0)
      {
      printf("%s\n", nomeItem);
      achou = 1;
      }
    }

  if (!achou)
    printf("Nenhum produto encontrado\n");

  fclose(arq);
  return 0;
  }
