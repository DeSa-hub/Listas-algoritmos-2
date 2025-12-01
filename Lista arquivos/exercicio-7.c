/*7 - Faça um programa que mostre todos os recebimentos com data de
vencimento dentro de um período qualquer. Não esqueça de mostrar também
o nome do cliente e o total de dias em atraso. Quando não houver atraso,
mostrar zero.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
  {
  int ano;
  int mes;
  int dia;
  } Data;

Data parseData(const char* entrada)
  {
  Data dt;
  sscanf(entrada, "%d-%d-%d", &dt.ano, &dt.mes, &dt.dia);
  return dt;
  }

int ehMaiorOuIgual(Data x, Data y)
  {
  if (x.ano > y.ano) return 1;
  if (x.ano < y.ano) return 0;
  if (x.mes > y.mes) return 1;
  if (x.mes < y.mes) return 0;
  return x.dia >= y.dia;
  }

int ehMenorOuIgual(Data x, Data y)
  {
  if (x.ano < y.ano) return 1;
  if (x.ano > y.ano) return 0;
  if (x.mes < y.mes) return 1;
  if (x.mes > y.mes) return 0;
  return x.dia <= y.dia;
  }

int diasEntreDatas(Data ini, Data fim)
  {
  int totalIni = ini.ano * 360 + ini.mes * 30 + ini.dia;
  int totalFim = fim.ano * 360 + fim.mes * 30 + fim.dia;
  return totalFim - totalIni;
  }

int main()
  {
  FILE* arqTitulos;
  FILE* arqPessoas;
  int idTitulo, idPessoa;
  float valorTitulo;
  char txtDataEmissao[11], txtDataVenc[11];
  char txtInicio[11], txtFinal[11];
  char nomePessoa[100], local[100], contato[20];
  int existe, atrasoDias;
  Data venc, ini, fim, dataAtual;

  printf("Informe a data inicial (AAAA-MM-DD): ");
  scanf("%10s", txtInicio);
  printf("Informe a data final (AAAA-MM-DD): ");
  scanf("%10s", txtFinal);

  char txtHoje[11];
  printf("Informe a data de hoje (AAAA-MM-DD): ");
  scanf("%10s", txtHoje);

  ini = parseData(txtInicio);
  fim = parseData(txtFinal);
  dataAtual = parseData(txtHoje);

  arqTitulos = fopen("recebimentos.txt", "r");
  if (arqTitulos == NULL)
    {
    printf("Falha ao abrir o arquivo de recebimentos\n");
    return 1;
    }

  printf("Titulos com vencimento entre %s e %s:\n", txtInicio, txtFinal);
  printf("ID       Valor    Emissao       Vencimento      Cliente  Nome                Dias em atraso\n");

  while (fscanf(arqTitulos, "%d,%f,%10[^,],%10[^,],%d\n", &idTitulo, &valorTitulo, txtDataEmissao, txtDataVenc, &idPessoa) == 5)
    {
    venc = parseData(txtDataVenc);

    if (ehMaiorOuIgual(venc, ini) && ehMenorOuIgual(venc, fim))
      {
      arqPessoas = fopen("clientes.txt", "r");
      if (arqPessoas == NULL)
        {
        printf("Falha ao abrir o arquivo de clientes\n");
        fclose(arqTitulos);
        return 1;
        }

      existe = 0;
      int idBuscado;
      while (fscanf(arqPessoas, "%d,%99[^,],%99[^,],%19[^\n]\n", &idBuscado, nomePessoa, local, contato) == 4)
        {
        if (idBuscado == idPessoa)
          {
          existe = 1;
          break;
          }
        }
      fclose(arqPessoas);

      if (!existe)
        strcpy(nomePessoa, "Nao_Identificado");

      atrasoDias = diasEntreDatas(venc, dataAtual);
      if (atrasoDias < 0)
        atrasoDias = 0;

      printf("%-8d  %-7.2f  %-12s  %-15s  %-8d  %-18s  %d\n",
             idTitulo, valorTitulo, txtDataEmissao, txtDataVenc, idPessoa, nomePessoa, atrasoDias);
      }
    }

  fclose(arqTitulos);

  return 0;
  }
