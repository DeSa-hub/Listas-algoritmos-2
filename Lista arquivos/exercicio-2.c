/*2 - Faça um programa para cadastrar clientes no arquivo criado no
Exercício1.*/

#include <stdio.h>
#include <stdlib.h>

int main()
  {
  FILE* arq_clientes;
  int contador, total;

  arq_clientes = fopen("clientes.txt", "a");
  if (arq_clientes == NULL)
    {
    printf("Erro ao abrir o arquivo clientes\n");
    return 1;
    }

  printf("Quantos registros de clientes deseja inserir: ");
  scanf("%d", &total);

  for (contador = 0; contador < total; contador++)
    {
    int id_cliente;
    char nome_cliente[100];
    char rua_cliente[100];
    char tel_cliente[20];

    printf("\nID do cliente: ");
    scanf("%d", &id_cliente);
    printf("Nome: ");
    scanf(" %[^\n]", nome_cliente);
    printf("Endereco: ");
    scanf(" %[^\n]", rua_cliente);
    printf("Telefone: ");
    scanf(" %[^\n]", tel_cliente);

    fprintf(arq_clientes, "%d,%s,%s,%s\n", id_cliente, nome_cliente, rua_cliente, tel_cliente);
    }

  fclose(arq_clientes);

  printf("Clientes inseridos com sucesso\n");

  return 0;
  }