/*5 - Faça um programa que altere o cadastro de clientes do Exercício 1. O
usuário deve informar o código do cliente que será alterado.*/

#include <stdio.h>
#include <stdlib.h>

int main()
  {
  FILE* arq_cli;
  FILE* arq_cli_temp;
  int id_alterar, id_lido;
  char nome_cli[100], rua_cli[100], tel_cli[20];
  int encontrado = 0;

  printf("Digite o codigo do cliente para alterar: ");
  scanf("%d", &id_alterar);

  arq_cli = fopen("clientes.txt", "r");
  arq_cli_temp = fopen("clientes_temp.txt", "w");

  if (arq_cli == NULL || arq_cli_temp == NULL)
    {
    printf("Erro ao abrir arquivos de clientes\n");
    return 1;
    }

  while (fscanf(arq_cli, "%d,%[^,],%[^,],%[^\n]\n", &id_lido, nome_cli, rua_cli, tel_cli) == 4)
    {
    if (id_lido == id_alterar)
      {
      encontrado = 1;
      printf("Digite os novos dados:\n");
      printf("Nome: ");
      scanf(" %[^\n]", nome_cli);
      printf("Endereco: ");
      scanf(" %[^\n]", rua_cli);
      printf("Telefone: ");
      scanf(" %[^\n]", tel_cli);
      }

    fprintf(arq_cli_temp, "%d,%s,%s,%s\n", id_lido, nome_cli, rua_cli, tel_cli);
    }

  fclose(arq_cli);
  fclose(arq_cli_temp);

  if (!encontrado)
    {
    printf("Cliente nao encontrado\n");
    remove("clientes_temp.txt");
    return 1;
    }

  remove("clientes.txt");
  rename("clientes_temp.txt", "clientes.txt");

  printf("Cliente atualizado com sucesso\n");

  return 0;
  }
