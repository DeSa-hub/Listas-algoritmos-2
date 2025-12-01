/*10 - Faça uma função que recebe um valor inteiro e verifica se o valor é par
ou ímpar. A função deve retornar um valor inteiro.*/

#include <stdio.h>

int parimpar(int valor)
  {
  if(valor % 2 == 0)
    {
    printf("par");
    return 0;
    }
  else
    {
    printf("impar");
    return 1;
    }
  }

int main()
  {
  int valor;
  printf("veja se o numero e impar ou par: \n");
  printf("digite um numero\n");
  scanf("%d", &valor);
  parimpar(valor);
  return 0;
  }
