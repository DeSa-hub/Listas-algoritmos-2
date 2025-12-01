/*3 - Faça um programa que inclua recebimentos no arquivo criado no
Exercício 1, devendo verificar se o cliente já se encontra cadastrado.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cliente_existe(int id_cli)
  {
  FILE* arq;
  int id_lido;
  char linha[256];

  arq = fopen("clientes.txt", "r");
  if (arq == NULL)
    {
    printf("Erro ao abrir o arquivo clientes\n");
    return 0;
    }

  while (fgets(linha, sizeof(linha), arq))
    {
    sscanf(linha, "%d,", &id_lido);
    if (id_lido == id_cli)
      {
      fclose(arq);
      return 1;
      }
    }

  fclose(arq);
  return 0;
  }

int main()
  {
  FILE* arq_rec;
  int i, qtd;

  arq_rec = fopen("recebimentos.txt", "a");
  if (arq_rec == NULL)
    {
    printf("Erro ao abrir o arquivo recebimentos\n");
    return 1;
    }

  printf("Quantos recebimentos deseja adicionar: ");
  scanf("%d", &qtd);

  for (i = 0; i < qtd; i++)
    {
    int doc_id;
    float valor;
    char data_emissao[11];
    char data_venc[11];
    int id_cli;

    printf("\nDocumento %d:\n", i + 1);
    printf("Numero do documento: ");
    scanf("%d", &doc_id);
    printf("Valor: ");
    scanf("%f", &valor);
    printf("Data de emissao (AAAA-MM-DD): ");
    scanf(" %[^\n]", data_emissao);
    printf("Data de vencimento (AAAA-MM-DD): ");
    scanf(" %[^\n]", data_venc);
    printf("ID do cliente: ");
    scanf("%d", &id_cli);

    if (!cliente_existe(id_cli))
      {
      printf("Cliente nao encontrado. Recebimento ignorado.\n");
      continue;
      }

    fprintf(arq_rec, "%d,%.2f,%s,%s,%d\n", doc_id, valor, data_emissao, data_venc, id_cli);
    }

  fclose(arq_rec);

  printf("Recebimentos registrados com sucesso\n");

  return 0;
  }