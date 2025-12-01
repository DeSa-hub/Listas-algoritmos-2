/*8) Crie uma estrutura capaz de armazenar o nome e a data de nascimento de uma pessoa.
Agora, escreva um programa que leia os dados de seis pessoas. Calcule e exiba os nomes
da pessoa mais nova e da mais velha.*/

#include <stdio.h>
#include <string.h>

struct Data
  {
  int dia;
  int mes;
  int ano;
  };

struct Pessoa
  {
  char nome[100];
  struct Data nascimento;
  };
int maisVelha(struct Data d1, struct Data d2)
  {
  if (d1.ano < d2.ano)
    return 1;
  else if (d1.ano > d2.ano)
    return 0;
  else if (d1.mes < d2.mes)
    return 1;
  else if (d1.mes > d2.mes)
    return 0;
  else if (d1.dia < d2.dia)
    return 1;
  else
    return 0;
  }
int maisNova(struct Data d1, struct Data d2)
  {
  if (d1.ano > d2.ano)
    return 1;
  else if (d1.ano < d2.ano)
    return 0;
  else if (d1.mes > d2.mes)
    return 1;
  else if (d1.mes < d2.mes)
    return 0;
  else if (d1.dia > d2.dia)
    return 1;
  else
    return 0;
  }

int main()
  {
  struct Pessoa pessoas[6];
  int i;
  for (i = 0; i < 6; i++)
    {
    printf("Digite o nome da pessoa %d: ", i + 1);
    scanf(" %[^\n]", pessoas[i].nome);
    printf("Digite a data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &pessoas[i].nascimento.dia, &pessoas[i].nascimento.mes, &pessoas[i].nascimento.ano);
    }
  struct Pessoa maisVelho = pessoas[0];
  struct Pessoa maisNovo = pessoas[0];
  for (i = 1; i < 6; i++)
    {
    if (maisVelha(pessoas[i].nascimento, maisVelho.nascimento))
      maisVelho = pessoas[i];
    if (maisNova(pessoas[i].nascimento, maisNovo.nascimento))
      maisNovo = pessoas[i];
    }
  printf("Pessoa mais velha: %s\n", maisVelho.nome);
  printf("Pessoa mais nova: %s\n", maisNovo.nome);

  return 0;
  }
