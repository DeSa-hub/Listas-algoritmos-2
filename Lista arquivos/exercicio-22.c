/*22 – Faça um programa para consultar os produtos com preços inferiores a
R$ 15,00.*/

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

  int id;
  char nome[100];
  float valor;
  int achou = 0;

  printf("Itens com valor abaixo de R$ 15,00:\n");

  while (fscanf(arq, "%d,%99[^,],%f\n", &id, nome, &valor) == 3)
    {
    if (valor < 15.0)
      {
      printf("%d - %s - R$ %.2f\n", id, nome, valor);
      achou = 1;
      }
    }

  if (!achou)
    printf("Nenhum item encontrado\n");

  fclose(arq);
  return 0;
  }
