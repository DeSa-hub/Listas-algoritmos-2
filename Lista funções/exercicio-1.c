/*1 - Faça uma função que não receba parâmetros e escreva na tela 
(print) o texto “OI”.*/

#include <stdio.h>

char texto()
  {
   char a = 'o';
   char b = 'i';
   char resultado;
   resultado = printf("%c%c", a, b);
   return resultado;
  }
int main()
  {
  return texto();
  }