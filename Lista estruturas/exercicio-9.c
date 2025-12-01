/*9) Crie uma estrutura representando um atleta. Essa estrutura deve conter o nome do
atleta, seu esporte, idade e altura. Agora, escreva um programa que leia os dados de cinco
atletas. Calcule e exiba os nomes do atleta mais alto e do mais velho.*/


#include <stdio.h>
#include <string.h>

struct Atleta
  {
  char nome[100];
  char esporte[100];
  int idade;
  float altura;
  };

int main()
  {
  struct Atleta atleta1, atleta2, atleta3, atleta4, atleta5;
  struct Atleta maisAlto, maisVelho;
  strcpy(atleta1.nome, "Jose");
  strcpy(atleta1.esporte, "Futebol");
  atleta1.idade = 24;
  atleta1.altura = 1.75;
  strcpy(atleta2.nome, "Gustavo");
  strcpy(atleta2.esporte, "Volei");
  atleta2.idade = 22;
  atleta2.altura = 1.65;
  strcpy(atleta3.nome, "Ricardo");
  strcpy(atleta3.esporte, "Natacao");
  atleta3.idade = 28;
  atleta3.altura = 1.78;
  strcpy(atleta4.nome, "Eduardo");
  strcpy(atleta4.esporte, "Basquete");
  atleta4.idade = 20;
  atleta4.altura = 1.80;
  strcpy(atleta5.nome, "Bruno");
  strcpy(atleta5.esporte, "Tenis");
  atleta5.idade = 30;
  atleta5.altura = 1.76;
  maisAlto = atleta1;
  maisVelho = atleta1;
  if (atleta2.altura > maisAlto.altura)
    maisAlto = atleta2;
  if (atleta3.altura > maisAlto.altura)
    maisAlto = atleta3;
  if (atleta4.altura > maisAlto.altura)
    maisAlto = atleta4;
  if (atleta5.altura > maisAlto.altura)
    maisAlto = atleta5;
  if (atleta2.idade > maisVelho.idade)
    maisVelho = atleta2;
  if (atleta3.idade > maisVelho.idade)
    maisVelho = atleta3;
  if (atleta4.idade > maisVelho.idade)
    maisVelho = atleta4;
  if (atleta5.idade > maisVelho.idade)
    maisVelho = atleta5;
  printf("Atleta mais alto: %s (%.2f m)\n", maisAlto.nome, maisAlto.altura);
  printf("Atleta mais velho: %s (%d anos)\n", maisVelho.nome, maisVelho.idade);

  return 0;
  }