/*2) Crie uma estrutura representando um aluno de uma disciplina. Essa estrutura deve
conter o número de matrícula do aluno, seu nome e as notas de três provas. Escreva um
programa que mostre o tamanho em byte dessa estrutura.*/

#include <stdio.h>

struct Aluno {
    int matricula;
    char nome[100];
    float nota1;
    float nota2;
    float nota3;
};

int main() {
    printf("Tamanho da estrutura Aluno: %lu bytes\n",
           (unsigned long) sizeof(struct Aluno));

    return 0;
}
