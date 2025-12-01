/*9 - Faça uma função que recebe um valor inteiro e verifica se o valor é
positivo ou negativo. A função deve retornar um valor inteiro*/

#include <stdio.h>

int funcao(int valor)
  {
  if (valor < 0)
    {
    return 1;
    }
  if (valor > 0)
    {
    return 0;
    }

  return -1; /* caso valor seja zero */
  }

int main()
  {
  int valor;
  int resultado;

  printf("veja se o numero e positivo ou negativo: \n");
  printf("digite um numero\n");
  scanf("%d", &valor);

  resultado = funcao(valor);

  printf("%d\n", resultado);

  return(0);
  }
