/*16 - Faça um programa para incluir produtos no arquivo criado no Exercício
15 lembrando que não podem existir dois produtos com o mesmo código.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int idExiste(int id)
  {
  FILE* arq = fopen("PRODUTOS.txt", "r");
  if (arq == NULL)
    return 0;

  int cod_tmp;
  char nome_tmp[100];
  float valor_tmp;

  while (fscanf(arq, "%d,%99[^,],%f\n", &cod_tmp, nome_tmp, &valor_tmp) == 3)
    {
    if (cod_tmp == id)
      {
      fclose(arq);
      return 1;
      }
    }
  fclose(arq);
  return 0;
  }

void adicionarItem()
  {
  FILE* arq = fopen("PRODUTOS.txt", "a");
  if (arq == NULL)
    {
    printf("Erro ao abrir arquivo\n");
    return;
    }

  int id_prod;
  char nome_prod[100];
  float preco_unit;

  printf("Codigo do item: ");
  scanf("%d", &id_prod);
  getchar();

  if (idExiste(id_prod))
    {
    printf("Codigo ja existe. Inclusao cancelada.\n");
    fclose(arq);
    return;
    }

  printf("Descricao do item: ");
  fgets(nome_prod, sizeof(nome_prod), stdin);
  nome_prod[strcspn(nome_prod, "\n")] = 0;

  printf("Preco do item: ");
  scanf("%f", &preco_unit);
  getchar();

  fprintf(arq, "%d,%s,%.2f\n", id_prod, nome_prod, preco_unit);

  fclose(arq);
  printf("Item adicionado com sucesso\n");
  }

int main()
  {
  adicionarItem();
  return 0;
  }
