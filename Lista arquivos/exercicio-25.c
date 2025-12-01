/*25 – Faça um programa para conceder um percentual de desconto dado pelo
usuário aos produtos cujos preços estão entre dois valores, também
fornecidos pelo usuário.*/

#include <stdio.h>
#include <stdlib.h>

int main()
  {
  FILE* arq = fopen("PRODUTOS.txt", "r");
  FILE* temp = fopen("temp.txt", "w");
  int id;
  char nome[100];
  float valor;
  float limite_inf, limite_sup, perc_desc;
  int atualizados = 0;

  if (arq == NULL || temp == NULL)
    {
    if (arq) fclose(arq);
    if (temp) fclose(temp);
    printf("Erro ao abrir arquivo\n");
    return 1;
    }

  printf("Digite o valor minimo: ");
  scanf("%f", &limite_inf);
  printf("Digite o valor maximo: ");
  scanf("%f", &limite_sup);
  printf("Digite o percentual de desconto (ex: 10 para 10%%): ");
  scanf("%f", &perc_desc);

  while (fscanf(arq, "%d,%99[^,],%f\n", &id, nome, &valor) == 3)
    {
    if (valor >= limite_inf && valor <= limite_sup)
      {
      valor = valor - (valor * perc_desc / 100.0f);
      atualizados++;
      }
    fprintf(temp, "%d,%s,%.2f\n", id, nome, valor);
    }

  fclose(arq);
  fclose(temp);

  remove("PRODUTOS.txt");
  rename("temp.txt", "PRODUTOS.txt");

  printf("Desconto aplicado em %d item(ns)\n", atualizados);

  return 0;
  }
