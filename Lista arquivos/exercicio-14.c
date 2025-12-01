/*14 - Faça um programa que apresente o seguinte menu de opções:
1. Criar
2. Incluir
3. Sair
Digite a opção desejada
Na opcão 1: criar um arquivo com os campos: numero, nome, nota1 e nota2.
Na opção 2: incluir todos os dados digitados, podendo haver repetição. No
final da inclusão após pressionar ENTER o programa deve mostrar todos os
registros cadastrados, calcular e mostrar a média das notas de cada registro.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
  {
  int id;
  char aluno[100];
  float nota_a;
  float nota_b;
  } Entrada;

void novoArquivo()
  {
  FILE* arq = fopen("dados.txt", "w");
  if (arq == NULL)
    {
    printf("Erro ao criar arquivo\n");
    return;
    }
  fclose(arq);
  printf("Arquivo criado com sucesso\n");
  }

void adicionarEntradas()
  {
  FILE* arq = fopen("dados.txt", "a+");
  if (arq == NULL)
    {
    printf("Erro ao abrir arquivo\n");
    return;
    }

  Entrada e;
  char buffer[200];

  while (1)
    {
    printf("Digite numero (ou ENTER para sair): ");
    fgets(buffer, sizeof(buffer), stdin);
    if (buffer[0] == '\n')
      break;

    e.id = atoi(buffer);

    printf("Digite nome: ");
    fgets(e.aluno, sizeof(e.aluno), stdin);
    e.aluno[strcspn(e.aluno, "\n")] = 0;

    printf("Digite nota1: ");
    fgets(buffer, sizeof(buffer), stdin);
    e.nota_a = atof(buffer);

    printf("Digite nota2: ");
    fgets(buffer, sizeof(buffer), stdin);
    e.nota_b = atof(buffer);

    fprintf(arq, "%d,%s,%.2f,%.2f\n", e.id, e.aluno, e.nota_a, e.nota_b);
    }

  rewind(arq);

  printf("\nRegistros cadastrados:\n");
  printf("Codigo  Nome                     Nota1  Nota2  Media\n");

  while (fscanf(arq, "%d,%99[^,],%f,%f\n", &e.id, e.aluno, &e.nota_a, &e.nota_b) == 4)
    {
    float media = (e.nota_a + e.nota_b) / 2.0;
    printf("%-7d %-25s %-6.2f %-6.2f %.2f\n", e.id, e.aluno, e.nota_a, e.nota_b, media);
    }

  fclose(arq);
  }

int main()
  {
  int escolha;

  while (1)
    {
    printf("\nMenu:\n");
    printf("1. Criar\n");
    printf("2. Incluir\n");
    printf("3. Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &escolha);
    getchar();

    if (escolha == 1)
      novoArquivo();
    else if (escolha == 2)
      adicionarEntradas();
    else if (escolha == 3)
      break;
    else
      printf("Opcao invalida\n");
    }

  return 0;
  }
