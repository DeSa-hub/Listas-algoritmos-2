/*10) Usando a estrutura “atleta” do exercício anterior, escreva um programa que leia os
dados de cinco atletas e os exiba por ordem de idade, do mais velho para o mais novo.*/

#include <stdio.h>
#include <string.h>

struct Atleta
  {
  char nome[100];
  char esporte[100];
  int idade;
  float altura;
  };
void trocar(struct Atleta *a, struct Atleta *b)
  {
  struct Atleta temp = *a;
  *a = *b;
  *b = temp;
  }
int main()
  {
  struct Atleta atletas[5];
  strcpy(atletas[0].nome, "Jose");
  strcpy(atletas[0].esporte, "Futebol");
  atletas[0].idade = 24;
  atletas[0].altura = 1.75;
  strcpy(atletas[1].nome, "Gustavo");
  strcpy(atletas[1].esporte, "Volei");
  atletas[1].idade = 22;
  atletas[1].altura = 1.65;
  strcpy(atletas[2].nome, "Ricardo");
  strcpy(atletas[2].esporte, "Natacao");
  atletas[2].idade = 28;
  atletas[2].altura = 1.78;
  strcpy(atletas[3].nome, "Eduardo");
  strcpy(atletas[3].esporte, "Basquete");
  atletas[3].idade = 20;
  atletas[3].altura = 1.80;
  strcpy(atletas[4].nome, "Bruno");
  strcpy(atletas[4].esporte, "Tenis");
  atletas[4].idade = 30;
  atletas[4].altura = 1.76;
  int i, j;
  for (i = 0; i < 4; i++)
    {
    for (j = i + 1; j < 5; j++)
      {
      if (atletas[i].idade < atletas[j].idade)
        {
        trocar(&atletas[i], &atletas[j]);
        }
      }
    }
  printf("Atletas em ordem de idade (mais velho para mais novo):\n\n");
  for (i = 0; i < 5; i++)
    {
    printf("Nome: %s\n", atletas[i].nome);
    printf("Esporte: %s\n", atletas[i].esporte);
    printf("Idade: %d\n", atletas[i].idade);
    printf("Altura: %.2f m\n\n", atletas[i].altura);
    }

  return 0;
  }
