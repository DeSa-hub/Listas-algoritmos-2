/*6) Crie um programa que contenha um array com cinco elementos inteiros. Leia esse array
do teclado e imprima o endereço das posições contendo valores pares.*/

#include<stdio.h>

int main()
  {
  int v[5];

  for(int i = 0; i < 5; i++ )
    {
    scanf("%d", &v[i]);
    if( v[i] %2 == 0)
      {
      printf("elemento par detectado, endereco: %p \n",  &v[i]);
      }
    }
  return 0;
  }