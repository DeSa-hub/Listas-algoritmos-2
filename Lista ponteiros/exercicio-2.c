/*2) Escreva um programa que contenha duas variaveis inteiras. Leia essas variaveis do
teclado. Em seguida, compare seus endereços e exiba o conteudo do maior endereço.
*/

#include <stdio.h>

int main()
  {
  int a = 10;
  int *pa;
  pa = &a;
  int b = 15;
  int *pb;
  pb = &b;
  if( pa > pb)
    {
    printf("variavel do maior endereco e: %d\n", a);
    }
  if(pa < pb)
    {
    printf("variavel do maior endereco e : %d", b);
    }
  return 0;
  }