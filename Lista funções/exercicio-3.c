/*3 - Faça uma função que receba um texto por parâmetro e escreva-o na tela 
(print), em seguida retorne “Ok”.*/

#include <stdio.h>

char texto(char nome[])
  {
  printf("%s\n",nome);
  char a[] = {'o','k'};
  char resultado = printf("%s",a);
  return resultado;
  }

int main()
  {
  texto("eduardo");
  return(0);
  }