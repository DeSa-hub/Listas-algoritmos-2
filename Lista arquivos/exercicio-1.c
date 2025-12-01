/*1 - Faça um programa para criar os arquivos a seguir:
Clientes: Cod_Cli, Nome, Endereco, Fone
Recebimentos: Num_doc, Valor_doc, Data_Emissao, Data_Vencimento,
Cod_Cli.*/

#include <stdio.h>
#include <stdlib.h>

int main()
  {
    FILE* arq_clientes;
    FILE* arq_docs;
    int qtd, i;

    arq_clientes = fopen("clientes.txt", "w");
    if (arq_clientes == NULL)
      {
      printf("Erro ao abrir o arquivo de clientes\n");
      return 1;
      }

    printf("Digite a quantidade de clientes: ");
    scanf("%d", &qtd);

    for (i = 0; i < qtd; i++)
      {
      int id_cliente;
      char nome_cli[100];
      char endereco_cli[100];
      char tel_cli[20];
      printf("\nCliente %d:\n", i + 1);
      printf("ID: ");
      scanf("%d", &id_cliente);
      printf("Nome: ");
      scanf(" %[^\n]", nome_cli);
      printf("Endereco: ");
      scanf(" %[^\n]", endereco_cli);
      printf("Telefone: ");
      scanf(" %[^\n]", tel_cli);

      fprintf(arq_clientes, "%d,%s,%s,%s\n", id_cliente, nome_cli, endereco_cli, tel_cli);
      }

    fclose(arq_clientes);

    arq_docs = fopen("recebimentos.txt", "w");
    if (arq_docs == NULL)
      {
      printf("Erro ao abrir o arquivo de recebimentos\n");
      return 1;
      }

    printf("\nDigite a quantidade de recebimentos: ");
    scanf("%d", &qtd);

    for (i = 0; i < qtd; i++)
      {
      int doc_num;
      float valor_doc;
      char data_emissao[11];
      char data_venc[11];
      int cliente_ref;

      printf("\nRecebimento %d:\n", i + 1);
      printf("Numero do documento: ");
      scanf("%d", &doc_num);
      printf("Valor: ");
      scanf("%f", &valor_doc);
      printf("Data de emissao (AAAA-MM-DD): ");
      scanf(" %[^\n]", data_emissao);
      printf("Data de vencimento (AAAA-MM-DD): ");
      scanf(" %[^\n]", data_venc);
      printf("ID do cliente: ");
      scanf("%d", &cliente_ref);
      fprintf(arq_docs, "%d,%.2f,%s,%s,%d\n", doc_num, valor_doc, data_emissao, data_venc, cliente_ref);
      }

  fclose(arq_docs);

  printf("\nArquivos gravados com sucesso\n");

  return 0;
  }