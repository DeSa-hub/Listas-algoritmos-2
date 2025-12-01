/*5) Crie um programa que contenha um array de inteiros com cinco elementos. Utilizando
apenas aritmética de ponteiros, leia esse array do teclado e imprima o dobro de cada valor
lido.8*/
#include<stdio.h>

int main()
  {
  int vetor[5];
  int *p;
  p = vetor;
  for(int i = 0; i < 5; i++)
    {
    scanf("%d", &vetor[i]);
    printf("dobro: %d \n", *(p+i)*2);
    }
  return 0;
  }