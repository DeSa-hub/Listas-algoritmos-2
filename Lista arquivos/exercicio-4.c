/*4 - Faça um programa que exclua clientes e, consequentemente, todos os seus
recebimentos, dos arquivos criados no Exercício l.*/

#include <stdio.h>
#include <stdlib.h>

int main()
  {
  FILE* arq_cli;
  FILE* arq_cli_temp;
  FILE* arq_rec;
  FILE* arq_rec_temp;
  int id_excluir, id_lido;
  char nome_cli[100], rua_cli[100], tel_cli[20];
  int doc_id;
  float valor;
  char data_emi[11], data_venc[11];
  int id_cli_doc;

  printf("Digite o codigo do cliente para excluir: ");
  scanf("%d", &id_excluir);

  arq_cli = fopen("clientes.txt", "r");
  arq_cli_temp = fopen("clientes_temp.txt", "w");

  if (arq_cli == NULL || arq_cli_temp == NULL)
    {
    printf("Erro ao abrir arquivos de clientes\n");
    return 1;
    }

  while (fscanf(arq_cli, "%d,%[^,],%[^,],%[^\n]\n", &id_lido, nome_cli, rua_cli, tel_cli) == 4)
    {
    if (id_lido != id_excluir)
      {
      fprintf(arq_cli_temp, "%d,%s,%s,%s\n", id_lido, nome_cli, rua_cli, tel_cli);
      }
    }

  fclose(arq_cli);
  fclose(arq_cli_temp);
  remove("clientes.txt");
  rename("clientes_temp.txt", "clientes.txt");

  arq_rec = fopen("recebimentos.txt", "r");
  arq_rec_temp = fopen("recebimentos_temp.txt", "w");

  if (arq_rec == NULL || arq_rec_temp == NULL)
    {
    printf("Erro ao abrir arquivos de recebimentos\n");
    return 1;
    }

  while (fscanf(arq_rec, "%d,%f,%[^,],%[^,],%d\n", &doc_id, &valor, data_emi, data_venc, &id_cli_doc) == 5)
    {
    if (id_cli_doc != id_excluir)
      {
      fprintf(arq_rec_temp, "%d,%.2f,%s,%s,%d\n", doc_id, valor, data_emi, data_venc, id_cli_doc);
      }
    }

  fclose(arq_rec);
  fclose(arq_rec_temp);
  remove("recebimentos.txt");
  rename("recebimentos_temp.txt", "recebimentos.txt");

  printf("Cliente e documentos removidos com sucesso\n");

  return 0;
  }