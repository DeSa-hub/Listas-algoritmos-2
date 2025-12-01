/*7)Crie uma estrutura representando uma hora. Essa estrutura deve conter os campos hora,
minuto e segundo. Agora, escreva um programa que leia um vetor de cinco posi��es dessa
estrutura e imprima a maior hora.*/

#include <stdio.h>
struct Hora
  {
  int hora;
  int minuto;
  int segundo;
  };
int horaMaior(struct Hora h1, struct Hora h2)
  {
  if (h1.hora > h2.hora)
    return 1;
  else if (h1.hora < h2.hora)
    return 0;
  else if (h1.minuto > h2.minuto)
    return 1;
  else if (h1.minuto < h2.minuto)
    return 0;
  else if (h1.segundo > h2.segundo)
    return 1;
  else
    return 0;
  }

int main()
  {
  struct Hora horas[5];
  int i;
  for (i = 0; i < 5; i++)
    {
    printf("Digite a hora %d (hh mm ss): ", i + 1);
    scanf("%d %d %d", &horas[i].hora, &horas[i].minuto, &horas[i].segundo);
    }
  struct Hora maior = horas[0];
  for (i = 1; i < 5; i++)
    {
    if (horaMaior(horas[i], maior))
      maior = horas[i];
    }
  printf("A maior hora digitada foi: %02d:%02d:%02d\n", maior.hora, maior.minuto, maior.segundo);
  return 0;
  }