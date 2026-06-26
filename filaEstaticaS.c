#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct
{
    int inicio, fim;
    int noh[TAM];
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
int inserir(tipofila *fila, int valor)
{
    if (cheia(fila) == 1)
    {
        printf("\nFILA CHEIA\n");
        return 0;
    }
    else
    {
        fila->fim++;
        fila->noh[fila->fim] = valor;
    }
    return valor;
}
void remover(tipofila *fila)
{
    int aux = 0;
    if (vazia(fila) == 1)
    {
        printf("\nFILA VAZIA\n");
    }
    else
    {
        aux = fila->noh[fila->inicio];
        fila->inicio++;
    }
}

void exibir(tipofila *fila)
{
    int i = fila->inicio;
    if (vazia(fila) == 1)
    {
        printf("Vazia");
    }
    else
    {
        while (i <= fila->fim)
        {
            printf("%d", fila->noh[i]);
            i++;
        }
        printf("\n");
    }
}
int repetidos(tipofila *fila){
    int totalRepetidos = 0;
    int contados[TAM];
    int qtdcontados = 0;

    if(vazia(fila)==1){
        return 0;
    }
    for(int i = fila->inicio; i<=fila->fim;i++){
        int atual = fila->noh[i];
        int jacontei = 0;

        for(int c = 0; c<qtdcontados;i++){
            if(contados[i]==atual){
                jacontei = 1;
                break;
            }
            if(jacontei==0){
                for(int j=i+1;j<=fila->fim;j++){
                    if(fila->noh[j]==atual){
                        totalRepetidos++;
                        contados[qtdcontados]=atual;
                        qtdcontados++;
                        break;
                    }
                }
            }
        }
    }
    return totalRepetidos;
}

void main()
{
    tipofila filaA;
    tipofila filaB;
    int valor = 0;

    int op = -1;
    inicializar(&filaA);
    inicializar(&filaB);

    while (op != 0)
    {
        exibir(&filaA);
        exibir(&filaB);
        printf("\n1-Para inserir o paciente:\n");

        scanf("%d", &op);
        switch (op)
        {
        case 1:
            for (int i = 0; i < 20; i++)
            {
                printf("Informe o %d numero", i + 1);
                scanf("%d", &valor);

                if (valor % 2 == 0)
                {
                    inserir(&filaA, valor);
                }
                else
                {
                    inserir(&filaB, valor);
                }
            }

            break;
        }
    }
}
