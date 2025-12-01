/*10 - Faça um programa que mostre todos os recebimentos com valor abaixo
de um valor dado pelo usuário.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
  {
  FILE* arq_rec;
  float limite_max, valor_lido;
  int id_doc, id_cli;
  char dt_emissao[11], dt_venc[11];
  char nome_cli[100], end_cli[100], tel_cli[20];
  int id_cli_arq, encontrou;
  FILE* arq_cli;

  printf("Digite o valor maximo para filtrar recebimentos: ");
  scanf("%f", &limite_max);

  arq_rec = fopen("recebimentos.txt", "r");
  if (arq_rec == NULL)
    {
    printf("Erro ao abrir arquivo recebimentos\n");
    return 1;
    }

  printf("Recebimentos com valor abaixo de %.2f:\n", limite_max);
  printf("Num_doc  Valor    Data_Emissao  Data_Vencimento  Cod_Cli  Nome_Cliente\n");

  while (fscanf(arq_rec, "%d,%f,%10[^,],%10[^,],%d\n", &id_doc, &valor_lido, dt_emissao, dt_venc, &id_cli_arq) == 5)
    {
    if (valor_lido < limite_max)
      {
      arq_cli = fopen("clientes.txt", "r");
      if (arq_cli == NULL)
        {
        printf("Erro ao abrir arquivo clientes\n");
        fclose(arq_rec);
        return 1;
        }

      encontrou = 0;
      while (fscanf(arq_cli, "%d,%99[^,],%99[^,],%19[^\n]\n", &id_cli, nome_cli, end_cli, tel_cli) == 4)
        {
        if (id_cli == id_cli_arq)
          {
          encontrou = 1;
          break;
          }
        }
      fclose(arq_cli);

      if (!encontrou)
        strcpy(nome_cli, "Cliente_Nao_Encontrado");

      printf("%-8d  %-7.2f  %-12s  %-15s  %-7d  %-20s\n",
             id_doc, valor_lido, dt_emissao, dt_venc, id_cli_arq, nome_cli);
      }
    }

  fclose(arq_rec);

  return 0;
  }