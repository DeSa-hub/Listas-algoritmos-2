/*14 - Faça uma função que leia um número não determinado de valores
positivos e retorna a média aritmética dos mesmos.*/

#include <stdio.h>

float mediaValores()
  {
  float valor, soma = 0;
  int contador = 0;

  printf("Digite valores positivos (digite um valor negativo para encerrar):\n");

  while (1)
    {
    scanf("%f", &valor);
    if (valor < 0)
      {
      break;
      }
    soma += valor;
    contador++;
    }

  if (contador == 0)
    {
    return 0;
    }
  else
    {
    return soma / contador;
    }
  }

int main()
  {
  float media;

  media = mediaValores();

  if (media == 0)
    {
    printf("Nenhum valor positivo foi digitado\n");
    }
  else
    {
    printf("Media dos valores: %.2f\n", media);
    }

  return 0;
  }
