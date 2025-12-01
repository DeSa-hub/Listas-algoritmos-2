/*1) Escreva um programa que contenha duas variaveis inteiras. Compare seus endereços e
exiba o maior endereço.*/

#include <stdio.h>
int main()
  {
  int a = 5;
  int *pa;
  pa = &a;
  printf("endereco de memoria: %p \n", &pa);
  int b = 4;
  int *pb;
  pb = &b;
  printf("endereco e memoria: %p \n ", &pb);
  if( pa > pb)
    {
    printf("o endereco pa e o maior");
    }
  if(pb > pa)
    {
    printf("o endereco pb e o maior");
    }
  return 0;
  }