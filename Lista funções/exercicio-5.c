/*5 - Faça um procedimento que recebe por parâmetro o tempo de duração de
uma fábrica expressa em segundos e imprima esse tempo em horas, minutos
e segundos.*/

#include <stdio.h>

void tempo(float seg)
   {
   float min = seg / 60;
   float horas = min / 60;

   printf("horas: %.2f h\nminutos: %.2f min\nsegundos: %.2f s\n", horas, min, seg);
   }

int main()
  {
  tempo(1000);
  return 0;
  }
