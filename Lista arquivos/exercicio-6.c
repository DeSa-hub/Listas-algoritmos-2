/*6 - Faça um programa que altere um recebimento de um cliente, ou seja, o
usuário informa o número do documento e o número do cliente e faz as
alterações desejadas.*/

#include <stdio.h>
#include <stdlib.h>

int main()
  {
  FILE* arq_rec;
  FILE* arq_rec_temp;
  int doc_alvo, cli_alvo;
  int doc_lido, cli_lido;
  float valor;
  char data_emi[11], data_venc[11];
  int encontrado = 0;

  printf("Digite o numero do documento para alterar: ");
  scanf("%d", &doc_alvo);
  printf("Digite o codigo do cliente do recebimento: ");
  scanf("%d", &cli_alvo);

  arq_rec = fopen("recebimentos.txt", "r");
  arq_rec_temp = fopen("recebimentos_temp.txt", "w");

  if (arq_rec == NULL || arq_rec_temp == NULL)
    {
    printf("Erro ao abrir arquivos de recebimentos\n");
    return 1;
    }

  while (fscanf(arq_rec, "%d,%f,%[^,],%[^,],%d\n", &doc_lido, &valor, data_emi, data_venc, &cli_lido) == 5)
    {
    if (doc_lido == doc_alvo && cli_lido == cli_alvo)
      {
      encontrado = 1;
      printf("Digite os novos dados:\n");
      printf("Valor: ");
      scanf("%f", &valor);
      printf("Data de emissao (AAAA-MM-DD): ");
      scanf(" %[^\n]", data_emi);
      printf("Data de vencimento (AAAA-MM-DD): ");
      scanf(" %[^\n]", data_venc);
      }

    fprintf(arq_rec_temp, "%d,%.2f,%s,%s,%d\n", doc_lido, valor, data_emi, data_venc, cli_lido);
    }

  fclose(arq_rec);
  fclose(arq_rec_temp);

  if (!encontrado)
    {
    printf("Recebimento nao encontrado\n");
    remove("recebimentos_temp.txt");
    return 1;
    }

  remove("recebimentos.txt");
  rename("recebimentos_temp.txt", "recebimentos.txt");

  printf("Recebimento atualizado com sucesso\n");

  return 0;
  }