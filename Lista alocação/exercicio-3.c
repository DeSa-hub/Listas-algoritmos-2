/*3) Crie uma estrutura chamada Cadastro. Essa estrutura deve conter o nome, a idade e o
endereço de uma pessoa. Agora, escreva uma função que receba um inteiro positivo N e
retorne o ponteiro para um vetor de tamanho N, alocado dinamicamente, dessa estrutura.
Solicite também que o usuário digite os dados desse vetor dentro da função.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
  {
  char nome[100];
  int idade;
  char endereco[200];
  } Cadastro;

Cadastro* criarCadastros(int N)
  {
  Cadastro* vetor = (Cadastro*) malloc(N * sizeof(Cadastro));
  if (vetor == NULL)
    {
    printf("Erro ao alocar memória.\n");
    exit(1);
    }
  for (int i = 0; i < N; i++)
    {
    printf("Digite o nome da pessoa %d: ", i+1);
    fgets(vetor[i].nome, 100, stdin);
    strtok(vetor[i].nome, "\n");
    printf("Digite a idade da pessoa %d: ", i+1);
    scanf("%d", &vetor[i].idade);
    getchar();
    printf("Digite o endereco da pessoa %d: ", i+1);
    fgets(vetor[i].endereco, 200, stdin);
    strtok(vetor[i].endereco, "\n");
    }
  return vetor;
  }

int main()
  {
  int n;
  printf("Digite o número de cadastros: ");
  scanf("%d", &n);
  getchar();

  Cadastro* pessoas = criarCadastros(n);

  printf("\n--- Dados Cadastrados ---\n");
  for (int i = 0; i < n; i++)
    {
    printf("Pessoa %d:\n", i+1);
    printf("Nome: %s\n", pessoas[i].nome);
    printf("Idade: %d\n", pessoas[i].idade);
    printf("Endereco: %s\n\n", pessoas[i].endereco);
    }

  free(pessoas);
  return 0;
  }