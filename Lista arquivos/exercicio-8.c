/*8 - Faça um programa que mostre todos os recebimentos de um determinado
cliente.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
  {
  FILE* arq_cli;
  FILE* arq_rec;
  int cod_busca, cod_linha, cod_rec;
  char nome_cli[100], end_cli[100], tel_cli[20];
  int doc_id;
  float doc_valor;
  char data_emit[11], data_venc[11];
  int encontrou = 0;

  printf("Digite o codigo do cliente: ");
  scanf("%d", &cod_busca);

  arq_cli = fopen("clientes.txt", "r");
  if (arq_cli == NULL)
    {
    printf("Erro ao abrir arquivo clientes\n");
    return 1;
    }

  encontrou = 0;
  while (fscanf(arq_cli, "%d,%99[^,],%99[^,],%19[^\n]\n", &cod_linha, nome_cli, end_cli, tel_cli) == 4)
    {
    if (cod_linha == cod_busca)
      {
      encontrou = 1;
      break;
      }
    }
  fclose(arq_cli);

  if (!encontrou)
    {
    printf("Cliente nao encontrado\n");
    return 1;
    }

  printf("Recebimentos do cliente %d - %s:\n", cod_busca, nome_cli);
  printf("Num_doc  Valor    Data_Emissao  Data_Vencimento\n");

  arq_rec = fopen("recebimentos.txt", "r");
  if (arq_rec == NULL)
    {
    printf("Erro ao abrir arquivo recebimentos\n");
    return 1;
    }

  encontrou = 0;
  while (fscanf(arq_rec, "%d,%f,%10[^,],%10[^,],%d\n", &doc_id, &doc_valor, data_emit, data_venc, &cod_rec) == 5)
    {
    if (cod_rec == cod_busca)
      {
      encontrou = 1;
      printf("%-8d  %-7.2f  %-12s  %-15s\n", doc_id, doc_valor, data_emit, data_venc);
      }
    }

  fclose(arq_rec);

  if (!encontrou)
    printf("Nenhum recebimento encontrado para este cliente\n");

  return 0;
  }