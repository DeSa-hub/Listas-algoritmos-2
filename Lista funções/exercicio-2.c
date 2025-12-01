/*2 - Faça uma função que receba um texto por parâmetro e escreva-o na 
tela (print).*/

#include <stdio.h>

char texto(char nome[])
  {
  char resultado = printf("%s!\n",nome);
  return resultado;
  }
int main()
  {
  texto("eduardo");
  return(0);
  }