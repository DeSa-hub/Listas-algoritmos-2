/*11) Escreva um programa que contenha uma estrutura representando uma data válida.
Essa estrutura deve conter os campos dia, mês e ano. Em seguida, leia duas datas e
armazene nessa estrutura. Calcule e exiba o número de dias que decorreram entre as duas
datas*/

#include <stdio.h>

struct Data
  {
  int dia;
  int mes;
  int ano;
  };

long diasDesdeZero(struct Data d)
  {
  int diasMeses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  long total = d.ano * 365 + d.dia;
  int i;

  for (i = 0; i < d.mes - 1; i++)
    {
    total += diasMeses[i];
    }

  return total;
  }

int main()
  {
  struct Data data1, data2;
  long dias1, dias2, diferenca;

  printf("Digite a primeira data (dd mm aaaa): ");
  scanf("%d %d %d", &data1.dia, &data1.mes, &data1.ano);

  printf("Digite a segunda data (dd mm aaaa): ");
  scanf("%d %d %d", &data2.dia, &data2.mes, &data2.ano);

  dias1 = diasDesdeZero(data1);
  dias2 = diasDesdeZero(data2);

  if (dias1 > dias2)
    diferenca = dias1 - dias2;
  else
    diferenca = dias2 - dias1;

  printf("Dias decorridos entre as datas: %ld\n", diferenca);

  return 0;
  }
