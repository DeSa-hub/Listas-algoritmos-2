/*6 - Faça uma função que recebe a idade de uma pessoa em anos, meses e dias
e retorna essa idade expressa em dias.*/

#include <stdio.h>

int idadeEmDias(int anos, int meses, int dias) 
  {
  int total = anos * 365 + meses * 30 + dias;
  return total;
  }

int main() 
  {
  int anos, meses, dias;

  printf("Digite anos: ");
  scanf("%d", &anos);

  printf("Digite meses: ");
  scanf("%d", &meses);

  printf("Digite dias: ");
  scanf("%d", &dias);

  int total = idadeEmDias(anos, meses, dias);

  printf("Idade total em dias: %d\n", total);

  return 0;
  }
