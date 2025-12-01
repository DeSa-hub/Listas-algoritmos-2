/*7) Elabore uma função que receba duas strings como parâmetros e verifique se a segunda
string ocorre dentro da primeira. Use aritmética de ponteiros para acessar os caracteres
das strings*/

#include <stdio.h>

void verifica_ocorrencia(const char *texto, const char *texto1)
  {
  const char *p1 = texto;
  const char *p2;
  const char *temp;

  while (*p1 != '\0')
    {
    temp = p1;
    p2 = texto1;

    while (*temp == *p2 && *p2 != '\0')
      {
      temp++;
      p2++;
      }

    if (*p2 == '\0')
      {
      printf("A segunda string ocorre dentro da primeira.\n");
      return;
      }

    p1++;
    }

  printf("A segunda string nao ocorre dentro da primeira.\n");
  }

int main()
  {
  verifica_ocorrencia("oioioi", "oi");
  verifica_ocorrencia("oioioi", "ah");
  return 0;
  }
