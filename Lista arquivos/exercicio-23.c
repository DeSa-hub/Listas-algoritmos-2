/*23 – Faça um programa para consultar todos os produtos com nomes
começados por uma letra digitada pelo usuário e com preços entre dois
valores também fornecidos pelo usuário.*/

#include <stdio.h>
#include <stdlib.h>

char para_maiuscula(char ch)
  {
  if (ch >= 'a' && ch <= 'z')
    return ch - ('a' - 'A');
  return ch;
  }

int main()
  {
  FILE* arq = fopen("PRODUTOS.txt", "r");
  if (arq == NULL)
    {
    printf("Erro ao abrir arquivo\n");
    return 1;
    }

  char inicial;
  float limite_min, limite_max;
  int id;
  char nome[100];
  float valor;
  int achou = 0;

  printf("Digite a letra inicial do nome dos itens: ");
  scanf(" %c", &inicial);
  inicial = para_maiuscula(inicial);

  printf("Digite o valor minimo: ");
  scanf("%f", &limite_min);
  printf("Digite o valor maximo: ");
  scanf("%f", &limite_max);

  printf("Itens iniciando com '%c' e valor entre %.2f e %.2f:\n",
         inicial, limite_min, limite_max);

  while (fscanf(arq, "%d,%99[^,],%f\n", &id, nome, &valor) == 3)
    {
    if (para_maiuscula(nome[0]) == inicial && valor >= limite_min && valor <= limite_max)
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
