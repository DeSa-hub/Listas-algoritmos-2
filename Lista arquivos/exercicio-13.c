/*13 - Faça um programa para:
-Cadastrar as estações climáticas, por exemplo, primavera-verão e
outono-inverno;
-Cadastrar os estilistas;
-Cadastrar as roupas. Lembre-se de que estilista e estação devem ter
sido previamente cadastrados;
-Mostrar um relatório de todas as roupas de uma determinada estação,
informando, inclusive, o nome do estilista que a desenhou.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int existeEstacao(int id)
{
    FILE* arq = fopen("estacao.txt", "r");
    int cod;
    char nome[100];

    if (!arq) return 0;

    while (fscanf(arq, "%d,%99[^\n]\n", &cod, nome) == 2)
    {
        if (cod == id)
        {
            fclose(arq);
            return 1;
        }
    }
    fclose(arq);
    return 0;
}

int existeEstilista(int id)
{
    FILE* arq = fopen("estilista.txt", "r");
    int cod;
    char nome[100];
    float valor;

    if (!arq) return 0;

    while (fscanf(arq, "%d,%99[^,],%f\n", &cod, nome, &valor) == 3)
    {
        if (cod == id)
        {
            fclose(arq);
            return 1;
        }
    }
    fclose(arq);
    return 0;
}

void inserirEstacoes()
{
    FILE* arq = fopen("estacao.txt", "a");
    int qtd, codigo;
    char nome[100];

    if (!arq)
    {
        printf("Erro ao abrir arquivo estacao\n");
        return;
    }

    printf("Quantas estacoes: ");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++)
    {
        printf("Codigo: ");
        scanf("%d", &codigo);
        printf("Nome: ");
        scanf(" %[^\n]", nome);
        fprintf(arq, "%d,%s\n", codigo, nome);
    }

    fclose(arq);
}

void inserirEstilistas()
{
    FILE* arq = fopen("estilista.txt", "a");
    int qtd, codigo;
    char nome[100];
    float valor;

    if (!arq)
    {
        printf("Erro ao abrir arquivo estilista\n");
        return;
    }

    printf("Quantos estilistas: ");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++)
    {
        printf("Codigo: ");
        scanf("%d", &codigo);
        printf("Nome: ");
        scanf(" %[^\n]", nome);
        printf("Salario: ");
        scanf("%f", &valor);
        fprintf(arq, "%d,%s,%.2f\n", codigo, nome, valor);
    }

    fclose(arq);
}

void inserirRoupas()
{
    FILE* arq = fopen("roupa.txt", "a");
    int qtd, id_roupa, id_estilista, id_estacao, ano;
    char texto[100];

    if (!arq)
    {
        printf("Erro ao abrir arquivo roupa\n");
        return;
    }

    printf("Quantas roupas: ");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++)
    {
        printf("Codigo roupa: ");
        scanf("%d", &id_roupa);

        printf("Descricao: ");
        scanf(" %[^\n]", texto);

        do
        {
            printf("Codigo estilista: ");
            scanf("%d", &id_estilista);
            if (!existeEstilista(id_estilista))
                printf("Estilista nao cadastrado\n");
        } while (!existeEstilista(id_estilista));

        do
        {
            printf("Codigo estacao: ");
            scanf("%d", &id_estacao);
            if (!existeEstacao(id_estacao))
                printf("Estacao nao cadastrada\n");
        } while (!existeEstacao(id_estacao));

        printf("Ano: ");
        scanf("%d", &ano);

        fprintf(arq, "%d,%s,%d,%d,%d\n", id_roupa, texto, id_estilista, id_estacao, ano);
    }

    fclose(arq);
}

void mostrarRoupasPorEstacao()
{
    int id_procurado;
    printf("Codigo da estacao: ");
    scanf("%d", &id_procurado);

    // Primeiro busca nome da estação
    FILE *arq_estacao = fopen("estacao.txt", "r");
    if (!arq_estacao)
    {
        printf("Erro ao abrir estacao.txt\n");
        return;
    }

    char nome_estacao[100];
    int id_estacao_lida;
    int achou = 0;

    while (fscanf(arq_estacao, "%d,%99[^\n]\n", &id_estacao_lida, nome_estacao) == 2)
    {
        if (id_estacao_lida == id_procurado)
        {
            achou = 1;
            break;
        }
    }
    fclose(arq_estacao);

    if (!achou)
    {
        printf("Estacao nao encontrada\n");
        return;
    }

    printf("Roupas da estacao %s:\n", nome_estacao);
    printf("Cod  Descricao                Cod Estilista  Nome Estilista           Ano\n");

    FILE* arq_roupa = fopen("roupa.txt", "r");
    if (!arq_roupa)
    {
        printf("Erro ao abrir roupa.txt\n");
        return;
    }

    int id_roupa, ano, id_estilista, id_estacao_roupa;
    char texto[100];

    while (fscanf(arq_roupa, "%d,%99[^,],%d,%d,%d\n",
                  &id_roupa, texto, &id_estilista, &id_estacao_roupa, &ano) == 5)
    {
        if (id_estacao_roupa == id_procurado)
        {
            // procurar nome do estilista
            FILE *arq_estilista = fopen("estilista.txt", "r");
            char nome_estilista[100];
            int id_estilista_lido;
            float sal;
            int ok = 0;

            while (fscanf(arq_estilista, "%d,%99[^,],%f\n",
                          &id_estilista_lido, nome_estilista, &sal) == 3)
            {
                if (id_estilista_lido == id_estilista)
                {
                    ok = 1;
                    break;
                }
            }
            fclose(arq_estilista);

            if (!ok) strcpy(nome_estilista, "Nao encontrado");

            printf("%-4d %-25s %-13d %-25s %d\n",
                   id_roupa, texto, id_estilista, nome_estilista, ano);
        }
    }

    fclose(arq_roupa);
}

int main()
{
    int escolha;

    do
    {
        printf("\nMenu:\n");
        printf("1 - Cadastrar estacoes\n");
        printf("2 - Cadastrar estilistas\n");
        printf("3 - Cadastrar roupas\n");
        printf("4 - Mostrar roupas por estacao\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
            case 1: inserirEstacoes(); break;
            case 2: inserirEstilistas(); break;
            case 3: inserirRoupas(); break;
            case 4: mostrarRoupasPorEstacao(); break;
            case 0: break;
            default: printf("Opcao invalida\n");
        }
    } while (escolha != 0);

    return 0;
}
