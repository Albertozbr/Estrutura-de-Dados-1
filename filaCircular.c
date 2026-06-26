#include <stdio.h>
#include <string.h>
#define TAM 4

typedef struct
{
    int vetor[TAM];
    int inicio, fim;
} fila;

void inicializar(fila *f)
{
    f->inicio = 0;
    f->fim = -1;
}

int cheia(fila *f)
{
    if ((f->fim+1)%4==f->inicio)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int vazia(fila *f)
{
    if (f->fim == -1 || f->inicio > f->fim)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int inserir(fila *f, int valor)
{
    if(f->fim==-1 || f->fim!=f->inicio){

        if (cheia(f) == 1)
        {
            return -1;
        }
        else 
        {
            f->fim++;
            f->vetor[f->fim] = valor;
            return f->fim;
        }
    }
}
int remover(fila *f)
{
    if (vazia(f) == 1)
    {
        return -1;
    }
    else
    {
        f->inicio++;
        return f->inicio;
    }
}