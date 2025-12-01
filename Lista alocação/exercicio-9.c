/*9) Crie uma função que receba uma string e retorne o ponteiro para essa string invertida.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inverter_string(const char *str)
  {
  int len = strlen(str);
  char *invertida = (char *) malloc((len + 1) * sizeof(char));
  if (invertida == NULL)
    {
    printf("Erro de alocacao!\n");
    return NULL;
    }

  for (int i = 0; i < len; i++)
    {
    invertida[i] = str[len - 1 - i];
    }
  invertida[len] = '\0';

  return invertida;
  }

int main()
  {
  char texto[100];
  char *invertida;

  printf("Digite uma string: ");
  fgets(texto, sizeof(texto), stdin);
  size_t len = strlen(texto);
  if (len > 0 && texto[len - 1] == '\n')
    {
    texto[len - 1] = '\0';
    }

  invertida = inverter_string(texto);
  if (invertida != NULL)
    {
    printf("String invertida: %s\n", invertida);
    free(invertida);
    }

  return 0;
  }
