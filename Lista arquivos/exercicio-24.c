/*24 – Faça um programa para excluir todos os produtos com preço superior a
R$ 200,00.*/

#include <stdio.h>
#include <stdlib.h>

int main()
  {
  FILE* entrada = fopen("PRODUTOS.txt", "r");
  FILE* temporario = fopen("temp.txt", "w");
  int id;
  char nome[100];
  float valor;
  int removidos = 0;

  if (entrada == NULL || temporario == NULL)
    {
    if (entrada) fclose(entrada);
    if (temporario) fclose(temporario);
    printf("Erro ao abrir arquivo\n");
    return 1;
    }

  while (fscanf(entrada, "%d,%99[^,],%f\n", &id, nome, &valor) == 3)
    {
    if (valor > 200.0)
      {
      removidos++;
      continue;
      }
    fprintf(temporario, "%d,%s,%.2f\n", id, nome, valor);
    }

  fclose(entrada);
  fclose(temporario);

  remove("PRODUTOS.txt");
  rename("temp.txt", "PRODUTOS.txt");

  printf("Itens removidos: %d\n", removidos);

  return 0;
  }
