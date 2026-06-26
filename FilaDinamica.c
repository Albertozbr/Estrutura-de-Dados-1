#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char calango;
}calango;

typedef struct NOH{
    calango dados;
    struct NOH *proximo;
}*tipofila;

tipofila criarNoh(calango c){

    tipofila novoNoh = malloc(sizeof(struct NOH));

    if (novoNoh == NULL)
    {
        return NULL;
    }
    else
    {
        novoNoh->dados = c;
        novoNoh->proximo = NULL;

        return novoNoh;
    }
}

tipofila inserir(tipofila fila, calango a)
{
    tipofila novoNoh = criarNoh(a);

    if (fila == NULL)
    {
        return novoNoh;
    }
    else
    {
        tipofila aux = fila;

        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = novoNoh;
        return fila;
    }
}

tipofila remover(tipofila fila)
{
    if (fila == NULL)
    {
        return NULL;
    }
    else
    {
        tipofila aux = fila;
        fila = fila->proximo;

        free(aux);
        aux = NULL;
    }
    return fila;
}
int contador(tipofila fila)
{
    int qtd = 0;

    tipofila aux = fila;
    while (aux != NULL)
    {
        qtd++;
        aux = aux->proximo;
    }
    return qtd;
}

void verificar(tipofila fila, int dedos){
    while(contador(fila)>1){
        for(int i=0;i<dedos;i++){
            calango temp = fila->dados;
            fila = inserir(fila, temp);
            fila = remover(fila);
        }
        fila = remover(fila);
    }
    printf("\nVencedor%c\n", fila->dados.calango);
}

int main()
{
    tipofila filaJogo = NULL;
    calango c;

    printf("--- JOGO DOS CALANGOS ---\n\n");

    // 1. Cadastrando os 4 calangos (O, L, P, I)
    // (Pode ignorar o 'tamanho' da struct por enquanto)
    c.calango = 'O';
    filaJogo = inserir(filaJogo, c);

    c.calango = 'L';
    filaJogo = inserir(filaJogo, c);

    c.calango = 'P';
    filaJogo = inserir(filaJogo, c);

    c.calango = 'I';
    filaJogo = inserir(filaJogo, c);

    // 2. Iniciando o jogo com 3 dedos
    int dedos = 3;
    printf("Comecando a contar %d dedos...\n\n", dedos);
    verificar(filaJogo, dedos);

    return 0;
}