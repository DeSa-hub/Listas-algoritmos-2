/*11 - Faça uma função que recebe a média final de um aluno por parâmetro e
retorna o seu conceito, conforme a tabela abaixo:

Nota              Conceito
de 0,0 a 4,9      D
de 5,0 a 6,9      C
de 7,0 a 8,9      B
de 9,0 a 10,0     A
*/

#include <stdio.h>

char obterConceito(float media)
  {
  if (media >= 0.0 && media <= 4.9)
    {
    return 'D';
    }
  else if (media >= 5.0 && media <= 6.9)
    {
    return 'C';
    }
  else if (media >= 7.0 && media <= 8.9)
    {
    return 'B';
    }
  else if (media >= 9.0 && media <= 10.0)
    {
    return 'A';
    }
  else
    {
    return 'X'; // Valor invalido
    }
  }

int main()
  {
  float media;
  char conceito;

  printf("Digite a media final do aluno: ");
  scanf("%f", &media);

  conceito = obterConceito(media);

  if (conceito == 'X')
    {
    printf("Media invalida.\n");
    }
  else
    {
    printf("Conceito: %c\n", conceito);
    }

  return 0;
  }
