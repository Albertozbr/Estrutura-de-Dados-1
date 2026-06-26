#include <stdio.h>
#include <stdlib.h>

typedef struct noh
{
    int chave;
    struct noh *proximo;
    struct noh *anterior;
} *tipoLista;

// 1. FUNÇÃO CRIAR ITEM
tipoLista criarItem(int valor)
{
    tipoLista novoItem = malloc(sizeof(struct noh));

    if (novoItem == NULL)
    {
        return NULL;
    }
    else
    {
        novoItem->chave = valor;
        novoItem->proximo = NULL;
        novoItem->anterior = NULL; 
        return novoItem;
    }
}

tipoLista inserirInicio(int valor, tipoLista lista)
{
    tipoLista novoNoh = criarItem(valor);
    if (lista == NULL)
    {
        return novoNoh;
    }
    else
    {
        lista->anterior = novoNoh;
        novoNoh->proximo = lista;
        return novoNoh;
    }
}

tipoLista inserirFinal(int valor, tipoLista lista)
{
    tipoLista novoNoh = criarItem(valor);

    if (lista == NULL)
    {
        return novoNoh;
    }
    else
    {
        tipoLista aux = lista;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = novoNoh;
        novoNoh->anterior = aux;
        return lista;
    }
}

tipoLista inserirMeio(int valor, tipoLista lista, int x)
{
    tipoLista novoNoh = criarItem(valor);
    tipoLista aux = lista;

    // Procura o valor x
    while (aux != NULL && aux->chave != x)
    {
        aux = aux->proximo;
    }

    // Se não encontrou o x, retorna a lista do jeito que estava
    if (aux == NULL)
    {
        printf("\nErro: Valor %d nao encontrado!\n", x);
        free(novoNoh); // Limpa o nó que não foi usado
        return lista;
    }

    // Fazendo a costura dos ponteiros duplos
    novoNoh->proximo = aux->proximo;
    novoNoh->anterior = aux;

    // CORREÇÃO: Proteção caso o aux seja o ÚLTIMO da lista
    if (aux->proximo != NULL)
    {
        aux->proximo->anterior = novoNoh;
    }
    aux->proximo = novoNoh;

    return lista;
}

tipoLista removerInicio(tipoLista lista)
{
    if (lista == NULL)
    {
        printf("Lista Vazia\n");
        return NULL;
    }
    else
    {
        tipoLista aux = lista;
        lista = lista->proximo; // A lista anda para frente

        if (lista != NULL)
        {
            lista->anterior = NULL; // Corta o laço com o nó que vai ser removido
        }

        free(aux); // Destrói o primeiro
        return lista;
    }
}
tipoLista removerFinal(tipoLista lista)
{
    tipoLista aux = lista;
    if (lista == NULL)
    {
        printf("Lista vazia");
        return lista;
    }
    // se a lista tiver apenas um elemento(o primeiro já é o ultimo)
    if (aux->proximo == NULL)
    {
        free(aux);
        return NULL;
    }

    while (aux->proximo != NULL)
    {
        aux = aux->proximo;
    }
    aux->anterior->proximo = NULL;
    free(aux);
    return lista;
}

tipoLista removerMeio(int valor, tipoLista lista)
{
    tipoLista aux = lista;
    if (lista == NULL)
    {
        return lista;
    }
   

    else
    {
        while (aux->chave != valor && aux != NULL)
        {
            aux = aux->proximo;
        }
        if (aux == NULL)
        {
            printf("\nValor na encontrado\n");
            return lista;
        }
        if (aux->anterior == NULL)
        {
            free(aux);//fire
            return lista;
        }
        if (aux->proximo == NULL)
        {
            free(aux);//fire
            return NULL;
        }
            aux->anterior->proximo = aux->proximo;
            aux->proximo->anterior = aux->anterior;

            free(aux); // fire
            return lista;
        }
    
}

void exibir(tipoLista lista)
{
    if (lista == NULL)
    {
        printf("Lista Vazia!\n");
        return;
    }

    tipoLista aux = lista;
    printf("\nMinha Lista: [ ");
    while (aux != NULL)
    {
        printf("%d ", aux->chave);
        aux = aux->proximo;
    }
    printf("]\n\n");
}

int qnt(tipoLista lista){
    if(lista == NULL){
        return 0;
    }else{
        printf("")
    }
}

int main()
{
    tipoLista lista = NULL;
    int op = -1;
    int valor, referencia;

    while (op != 0)
    {
        // Mostra a lista sempre que o menu recarregar
        exibir(lista);

        printf("========== MENU ==========\n");
        printf("1 - Inserir no Inicio\n");
        printf("2 - Inserir no Final\n");
        printf("3 - Inserir no Meio (Apos um valor especifico)\n");
        printf("4 - Remover do Inicio\n");
        printf("5 - Remover do Final\n");
        printf("6 - Remover um valor Especifico (Meio)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Digite o valor para inserir no INICIO: ");
            scanf("%d", &valor);
            lista = inserirInicio(valor, lista);
            break;

        case 2:
            printf("Digite o valor para inserir no FINAL: ");
            scanf("%d", &valor);
            lista = inserirFinal(valor, lista);
            break;

        case 3:
            printf("Digite o valor que deseja inserir: ");
            scanf("%d", &valor);
            printf("Inserir APOS qual valor existente na lista? ");
            scanf("%d", &referencia);
            lista = inserirMeio(valor, lista, referencia);
            break;

        case 4:
            lista = removerInicio(lista);
            break;

        case 5:
            lista = removerFinal(lista);
            break;

        case 6:
            printf("Digite o valor EXATO que deseja remover: ");
            scanf("%d", &valor);
            lista = removerMeio(valor, lista);
            break;

        case 0:
            printf("\nEncerrando o programa...\n");
            break;

        default:
            printf("\nOpcao invalida! Tente novamente.\n");
            break;
        }
    }

    return 0;
}