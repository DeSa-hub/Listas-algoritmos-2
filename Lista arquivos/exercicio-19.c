/*19 – Faça um programa para alterar os preços dos produtos em R$ 10,00,
mas apenas os produtos que já custam mais de R$ 100,00.*/

#include <stdio.h>
#include <stdlib.h>

int main()
  {
  FILE* entrada = fopen("PRODUTOS.txt", "r");
  FILE* saida = fopen("temp.txt", "w");
  if (entrada == NULL || saida == NULL)
    {
    if (entrada) fclose(entrada);
    if (saida) fclose(saida);
    printf("Erro ao abrir arquivo\n");
    return 1;
    }

  int idProd;
  char nomeProd[100];
  float valorProd;

  while (fscanf(entrada, "%d,%99[^,],%f\n", &idProd, nomeProd, &valorProd) == 3)
    {
    if (valorProd > 100.0)
      valorProd += 10.0;

    fprintf(saida, "%d,%s,%.2f\n", idProd, nomeProd, valorProd);
    }

  fclose(entrada);
  fclose(saida);

  remove("PRODUTOS.txt");
  rename("temp.txt", "PRODUTOS.txt");

  printf("Valores atualizados (adicionado R$ 10,00 aos itens acima de R$ 100,00)\n");

  return 0;
  }
