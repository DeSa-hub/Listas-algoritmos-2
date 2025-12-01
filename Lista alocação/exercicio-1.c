/*1) Escreva um programa que mostre o tamanho em byte que cada tipo de dados ocupa na
memória: char, int, float, double.*/

#include <stdio.h>

int main()
  {
  printf("Tamanho do char: %lu bytes\n", (unsigned long)sizeof(char));
  printf("Tamanho do int: %lu bytes\n", (unsigned long)sizeof(int));
  printf("Tamanho do float: %lu bytes\n", (unsigned long)sizeof(float));
  printf("Tamanho do double: %lu bytes\n", (unsigned long)sizeof(double));
  return 0;
  }
