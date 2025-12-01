/*11 - Faça um programa que mostre todos os recebimentos com valor entre
dois valores dados pelo usuário.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
  {
  FILE* arq_rec;
  float limite_inf, limite_sup, valor_atual;
  int doc_codigo, cli_codigo;
  char dt_emitido[11], dt_venc[11];
  char cli_nome[100], cli_end[100], cli_tel[20];
  int cli_lido, localizado;
  FILE* arq_cli;

  printf("Digite o valor minimo: ");
  scanf("%f", &limite_inf);
  printf("Digite o valor maximo: ");
  scanf("%f", &limite_sup);

  arq_rec = fopen("recebimentos.txt", "r");
  if (arq_rec == NULL)
    {
    printf("Erro ao abrir arquivo recebimentos\n");
    return 1;
    }

  printf("Recebimentos com valor entre %.2f e %.2f:\n", limite_inf, limite_sup);
  printf("Num_doc  Valor    Data_Emissao  Data_Vencimento  Cod_Cli  Nome_Cliente\n");

  while (fscanf(arq_rec, "%d,%f,%10[^,],%10[^,],%d\n", &doc_codigo, &valor_atual, dt_emitido, dt_venc, &cli_lido) == 5)
    {
    if (valor_atual >= limite_inf && valor_atual <= limite_sup)
      {
      arq_cli = fopen("clientes.txt", "r");
      if (arq_cli == NULL)
        {
        printf("Erro ao abrir arquivo clientes\n");
        fclose(arq_rec);
        return 1;
        }

      localizado = 0;
      while (fscanf(arq_cli, "%d,%99[^,],%99[^,],%19[^\n]\n", &cli_codigo, cli_nome, cli_end, cli_tel) == 4)
        {
        if (cli_codigo == cli_lido)
          {
          localizado = 1;
          break;
          }
        }
      fclose(arq_cli);

      if (!localizado)
        strcpy(cli_nome, "Cliente_Nao_Encontrado");

      printf("%-8d  %-7.2f  %-12s  %-15s  %-7d  %-20s\n",
             doc_codigo, valor_atual, dt_emitido, dt_venc, cli_lido, cli_nome);
      }
    }

  fclose(arq_rec);

  return 0;
  }
