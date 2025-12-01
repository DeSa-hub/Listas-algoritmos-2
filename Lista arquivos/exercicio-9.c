/*9 - Faça um programa que mostre todos os recebimentos com valor acima de
um valor dado pelo usuário.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
  {
  FILE* arq_rec;
  float valor_filtro, valor_lido;
  int doc_num, cli_id;
  char dt_emit[11], dt_venc[11];
  char cli_nome[100], cli_end[100], cli_tel[20];
  int cli_arq_id, encontrou;
  FILE* arq_cli;

  printf("Digite o valor minimo para filtrar recebimentos: ");
  scanf("%f", &valor_filtro);

  arq_rec = fopen("recebimentos.txt", "r");
  if (arq_rec == NULL)
    {
    printf("Erro ao abrir arquivo recebimentos\n");
    return 1;
    }

  printf("Recebimentos com valor acima de %.2f:\n", valor_filtro);
  printf("Num_doc  Valor    Data_Emissao  Data_Vencimento  Cod_Cli  Nome_Cliente\n");

  while (fscanf(arq_rec, "%d,%f,%10[^,],%10[^,],%d\n", &doc_num, &valor_lido, dt_emit, dt_venc, &cli_arq_id) == 5)
    {
    if (valor_lido > valor_filtro)
      {
      arq_cli = fopen("clientes.txt", "r");
      if (arq_cli == NULL)
        {
        printf("Erro ao abrir arquivo clientes\n");
        fclose(arq_rec);
        return 1;
        }

      encontrou = 0;
      while (fscanf(arq_cli, "%d,%99[^,],%99[^,],%19[^\n]\n", &cli_id, cli_nome, cli_end, cli_tel) == 4)
        {
        if (cli_id == cli_arq_id)
          {
          encontrou = 1;
          break;
          }
        }
      fclose(arq_cli);

      if (!encontrou)
        strcpy(cli_nome, "Cliente_Nao_Encontrado");

      printf("%-8d  %-7.2f  %-12s  %-15s  %-7d  %-20s\n",
             doc_num, valor_lido, dt_emit, dt_venc, cli_arq_id, cli_nome);
      }
    }

  fclose(arq_rec);

  return 0;
  }
