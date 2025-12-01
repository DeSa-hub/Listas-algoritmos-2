/*21 – Faça um programa para excluir produtos do arquivo criado no Exercício
15.*/

#include <stdio.h>
#include <stdlib.h>

int main()
  {
  FILE* arq = fopen("PRODUTOS.txt", "r");
  FILE* arqTemp = fopen("temp.txt", "w");
  int id, id_remover;
  char nome[100];
  float valor;
  int achou = 0;

  if (arq == NULL || arqTemp == NULL)
    {
    if (arq) fclose(arq);
    if (arqTemp) fclose(arqTemp);
    printf("Erro ao abrir arquivo\n");
    return 1;
    }

  printf("Digite o codigo do item para remover: ");
  scanf("%d", &id_remover);

  while (fscanf(arq, "%d,%99[^,],%f\n", &id, nome, &valor) == 3)
    {
    if (id == id_remover)
      {
      achou = 1;
      continue;
      }
    fprintf(arqTemp, "%d,%s,%.2f\n", id, nome, valor);
    }

  fclose(arq);
  fclose(arqTemp);

  if (!achou)
    {
    printf("Item com codigo %d nao encontrado\n", id_remover);
    remove("temp.txt");
    }
  else
    {
    remove("PRODUTOS.txt");
    rename("temp.txt", "PRODUTOS.txt");
    printf("Item removido com sucesso\n");
    }

  return 0;
  }
