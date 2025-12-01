/*18 – Faça um programa para alterar os preços de todos os produtos em 15%*/

#include <stdio.h>
#include <stdlib.h>

int main()
  {
  FILE* arqOrig = fopen("PRODUTOS.txt", "r");
  FILE* arqTemp = fopen("temp.txt", "w");
  if (arqOrig == NULL || arqTemp == NULL)
    {
    printf("Erro ao abrir arquivo\n");
    if (arqOrig) fclose(arqOrig);
    if (arqTemp) fclose(arqTemp);
    return 1;
    }

  int id;
  char nome[100];
  float valor;

  while (fscanf(arqOrig, "%d,%99[^,],%f\n", &id, nome, &valor) == 3)
    {
    valor = valor * 1.15f;
    fprintf(arqTemp, "%d,%s,%.2f\n", id, nome, valor);
    }

  fclose(arqOrig);
  fclose(arqTemp);

  remove("PRODUTOS.txt");
  rename("temp.txt", "PRODUTOS.txt");

  printf("Valores atualizados com aumento de 15%%\n");

  return 0;
  }
