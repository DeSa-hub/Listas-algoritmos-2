/*20 – Faça um programa para consultar todos os produtos cujos nomes
comecem pela letra M.*/

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

  printf("Itens com nome iniciando com a letra M:\n");

  while (fscanf(arq, "%d,%99[^,],%f\n", &id, nome, &valor) == 3)
    {
    if (nome[0] == 'M')
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
