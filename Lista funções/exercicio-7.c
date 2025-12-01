/*7 - Faça uma função que verifique se um valor é perfeito ou não. Um valor
é dito perfeito quando ele é igual a soma dos seus divisores excetuando ele
próprio. (Ex: 6 é perfeito, 6 = 1 + 2 + 3, que são seus divisores). A função
deve retornar o valor inteiro 1 para verdadeiro e 0 caso contrário. */

#include <stdio.h>

int perfeito()
  {
  int somadiv = 0;
  int i = 1;
  int x;

  printf("Digite um numero: ");
  scanf("%d", &x);

  while( i < x)
    {
    if( x % i == 0)
      {
      somadiv = somadiv + i;
      }
    i++;
    }

  if(somadiv == x)
    {
    printf("e um numero perfeito");
    }
  else
    {
    printf("nao e um numero perfeito");
    }

  return(0);
  }

int main()
  {
  perfeito();
  return(0);
  }