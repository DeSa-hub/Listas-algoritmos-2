/*12 - Faça um programa para criar os arquivos a seguir:
-Estilista (código do estilista, nome do estilista, salário)
-Roupa (código da roupa, descrição da roupa, código do estilista,
código da estação, ano)
-Estação (código da estação, nome da estação)*/

/* 12 - Faça um programa para criar os arquivos a seguir:
   - Estilista (código do estilista, nome do estilista, salário)
   - Roupa    (código da roupa, descrição, código do estilista, código da estação, ano)
   - Estação  (código da estação, nome da estação)
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* arq_est;
    FILE* arq_roupa;
    FILE* arq_temp;
    int qtde, i;

    arq_est = fopen("estilista.txt", "w");
    if (arq_est == NULL)
    {
        printf("Erro ao criar arquivo estilista\n");
        return 1;
    }

    printf("Quantos estilistas deseja cadastrar: ");
    scanf("%d", &qtde);

    for (i = 0; i < qtde; i++)
    {
        int id_est;
        char nome_est[100];
        float pagto;

        printf("Codigo do estilista: ");
        scanf("%d", &id_est);

        printf("Nome do estilista: ");
        scanf(" %[^\n]", nome_est);

        printf("Salario: ");
        scanf("%f", &pagto);

        fprintf(arq_est, "%d,%s,%.2f\n", id_est, nome_est, pagto);
    }

    fclose(arq_est);

    arq_temp = fopen("estacao.txt", "w");
    if (arq_temp == NULL)
    {
        printf("Erro ao criar arquivo estacao\n");
        return 1;
    }

    printf("Quantas estacoes deseja cadastrar: ");
    scanf("%d", &qtde);

    for (i = 0; i < qtde; i++)
    {
        int id_temp;
        char nome_temp[100];

        printf("Codigo da estacao: ");
        scanf("%d", &id_temp);

        printf("Nome da estacao: ");
        scanf(" %[^\n]", nome_temp);

        fprintf(arq_temp, "%d,%s\n", id_temp, nome_temp);
    }

    fclose(arq_temp);

    arq_roupa = fopen("roupa.txt", "w");
    if (arq_roupa == NULL)
    {
        printf("Erro ao criar arquivo roupa\n");
        return 1;
    }

    printf("Quantas roupas deseja cadastrar: ");
    scanf("%d", &qtde);

    for (i = 0; i < qtde; i++)
    {
        int id_roupa, id_est_ref, id_temp_ref, ano_ref;
        char desc[100];

        printf("Codigo da roupa: ");
        scanf("%d", &id_roupa);

        printf("Descricao da roupa: ");
        scanf(" %[^\n]", desc);

        printf("Codigo do estilista: ");
        scanf("%d", &id_est_ref);

        printf("Codigo da estacao: ");
        scanf("%d", &id_temp_ref);

        printf("Ano: ");
        scanf("%d", &ano_ref);

        fprintf(arq_roupa, "%d,%s,%d,%d,%d\n", 
                id_roupa, desc, id_est_ref, id_temp_ref, ano_ref);
    }

    fclose(arq_roupa);

    printf("Arquivos criados com sucesso\n");

    return 0;
}
