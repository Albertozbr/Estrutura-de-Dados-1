#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 20

typedef struct
{
    char nome[50];
    int idade;
} pessoa;
typedef struct
{
    int inicio, fim;
    pessoa noh[TAM];
} tipofila;

void inicializar(tipofila *fila)
{
    fila->inicio = 0;
    fila->fim = -1;
}

int cheia(tipofila *fila)
{
    if (fila->fim == TAM - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int vazia(tipofila *fila)
{
    if (fila->inicio > fila->fim)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int inserir(tipofila *fila, pessoa p)
{
    if (cheia(fila) == 1)
    {
        return -1;
    }
    else
    {
        fila->fim++;
        fila->noh[fila->fim] = p;
        return 1;
    }
}

pessoa remover(tipofila *fila)
{
    pessoa p;
    if (vazia(fila) == 1)
    {
        p.idade = -1;
        strcpy(p.nome, "erro");
        return p;
    }
    else
    {
        p = fila->noh[fila->inicio];
        fila->inicio++;
        return p;
    }
}

int contador(tipofila *fila)
{
    if (vazia(fila) == 1)
    {
        return 0;
    }
    else
    {
        return (fila->fim - fila->inicio) + 1;
    }
}

void primeiroDaFila(tipofila *fila)
{
    if (vazia(fila) == 1)
    {
        printf("\nFila Vazia\n");
    }
    else
    {
        printf("%s %d", fila->noh[fila->inicio].nome, fila->noh[fila->inicio].idade);
    }
}

int main()
{
    tipofila fila;
    tipofila prioritario;
    pessoa p;
    int op = -1;
    inicializar(&fila);
    inicializar(&prioritario);
    
    while (op != 0)
    {
        printf("\n1-Para inserir o paciente:\n");
        printf("2-Chamar o paciente:\n");
        printf("3-Verificar se cheia ou vazia:\n");
        printf("4-Total de pacientes\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Informe o nome:\n");
            scanf("%s", p.nome);
            printf("Informe a idade:\n");
            scanf("%d", &p.idade);
            if(p.idade >= 60){
                inserir(&prioritario, p);
            }else{
                inserir(&fila, p);
            }
            break;
        case 2:
            if(vazia(&prioritario)==0){
                p = remover(&prioritario);
            }else if(vazia(&fila)==0){
                p = remover(&fila);
            }
            break;
        case 3:
            if(vazia(&prioritario)==0){
                printf("Fila de prioritado:\n");
                primeiroDaFila(&prioritario);
            }else if(vazia(&fila)==0){
                printf("Fila Normal\n");
                primeiroDaFila(&fila);
            }else{
                printf("AS DUAS FILAS VAZIAS\n");
            }
            break;
        case 4:
            printf("%d", (contador(&fila) + contador(&prioritario)) );
            
        default:
            break;
        }
    }
}