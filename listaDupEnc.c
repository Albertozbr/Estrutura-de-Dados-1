#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int vit;
    int gols;
} selecao;

typedef struct noh
{
    selecao dados;
    struct noh *prox;
    struct noh *ant;
} *tipolista;

tipolista criarItem(selecao s)
{
    tipolista novoItem = malloc(sizeof(struct noh));

    if (novoItem == NULL)
    {
        return NULL;
    }
    else
    {
        novoItem->dados = s;
        novoItem->prox = NULL;
        novoItem->ant = NULL;
        return novoItem;
    }
}

tipolista inserirInic(tipolista lista, selecao s)
{
    tipolista novoItem = criarItem(s);
    if (lista == NULL)
    {
        return novoItem;
    }
    else
    {
        lista->ant = novoItem;
        novoItem->prox = lista;
        return novoItem;
    }
}

tipolista inserirFinal(tipolista lista, selecao s)
{
    tipolista novoItem = criarItem(s);
    if (lista == NULL)
    {
        return novoItem;
    }
    else
    {
        tipolista aux = lista;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novoItem;
        novoItem->ant = aux;
        return lista;
    }
}

tipolista inserirMeio(tipolista lista, selecao s, char *nome1)
{
    tipolista novoItem = criarItem(s);
    tipolista aux = lista;

    // CORREÇÃO: Usar aux != NULL para garantir que lê até o último
    while (aux != NULL && strcmp(aux->dados.nome, nome1) != 0)
    {
        aux = aux->prox;
    }

    if (aux == NULL)
    {
        printf("\nSelecao de referencia nao encontrada!\n");
        free(novoItem);
        return lista;
    }

    novoItem->prox = aux->prox;
    novoItem->ant = aux;

    if (aux->prox != NULL)
    {
        aux->prox->ant = novoItem;
    }

    // CORREÇÃO: Retirado um sinal de igual (=)
    aux->prox = novoItem;

    return lista;
}

tipolista removerInic(tipolista lista)
{
    if (lista == NULL)
    {
        printf("\nLista ja esta vazia!\n");
        return NULL;
    }
    else
    {
        tipolista aux = lista;
        lista = lista->prox;

        if (lista != NULL)
        {
            lista->ant = NULL;
        }
        free(aux);
        return lista;
    }
}

tipolista removerFim(tipolista lista)
{
    tipolista aux = lista;
    if (lista == NULL)
    {
        printf("\nLista ja esta vazia!\n");
        return NULL;
    }
    if (aux->prox == NULL)
    {
        free(aux);
        return NULL;
    }
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    aux->ant->prox = NULL;
    free(aux);
    return lista;
}

tipolista removerMeio(tipolista lista, char *nome1)
{
    tipolista aux = lista;
    if (lista == NULL)
    {
        printf("\nLista vazia!\n");
        return lista;
    }
    else
    {
        while (aux != NULL && (strcmp(aux->dados.nome, nome1) != 0))
        {
            aux = aux->prox;
        }
        if (aux == NULL)
        {
            printf("\nSelecao nao encontrada para remocao!\n");
            return lista;
        }

        // CORREÇÃO: Reutilizando as funções já prontas para evitar bugs
        if (aux->ant == NULL)
        {
            return removerInic(lista);
        }
        if (aux->prox == NULL)
        {
            return removerFim(lista);
        }

        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;

        free(aux);
        return lista;
    }
}

int contador(tipolista lista)
{
    int contador = 0;
    if (lista == NULL)
    {
        return -1;
    }
    else
    {
        tipolista aux = lista;
        while (aux != NULL)
        {
            contador++;
            aux = aux->prox;
        }
    }
    return contador;
}

tipolista procurar(tipolista lista, char *nome1)
{
    tipolista aux = lista;
    while (aux != NULL)
    {

        if (strcmp(aux->dados.nome, nome1) == 0)
        {
            printf("O nome do pais é %s, que tem %d vitorias e %d gols", aux->dados.nome, aux->dados.vit, aux->dados.gols);
            return aux;
        }
        aux = aux->prox;
    }

    printf("Selecao nao existe\n");
    return NULL;
}

tipolista removerPerdedor(tipolista lista)
{ // caso 9
    tipolista aux = lista;
    while (aux != NULL)
    {

        if (aux->dados.vit == 0)
        {
            lista = removerMeio(lista, aux->dados.nome);
        }
        aux = aux->prox;
    }
    return lista;
}

tipolista ordenar(tipolista lista) // PEGUEI DO GEMINI
{
    if (lista == NULL || lista->prox == NULL)
    {
        return lista; // Se a lista tiver 0 ou 1 elemento, já está ordenada
    }

    int trocou;
    tipolista aux;

    do
    {
        trocou = 0; // Assume que não houve troca nessa rodada
        aux = lista;

        while (aux->prox != NULL)
        {
            // Se o atual tem MENOS vitórias que o próximo, eles trocam! (Ordem Decrescente)
            if (aux->dados.vit < aux->prox->dados.vit)
            {
                selecao caixaTemporaria = aux->dados;
                aux->dados = aux->prox->dados;
                aux->prox->dados = caixaTemporaria;
                trocou = 1; // Marca que houve bagunça, vai precisar rodar de novo
            }
            aux = aux->prox;
        }
    } while (trocou == 1); // Fica repetindo até ninguém trocar de lugar

    printf("\nLista ordenada por vitorias (Decrescente)!\n");
    return lista;
}

//OQ EU TENTEI FAZER>>
/*tipolista ordenar(tipolista lista, selecao s)
{ // caso 10
    tipolista aux = lista;
    int maior = 0;
    if (lista == NULL)
    {
        return lista;
    }
    maior = lista->dados.vit;
    while (aux->prox != NULL)
    {
        if (lista->dados.vit > maior)

        {
            inserirInic(aux, s);
        }
    }
    return aux;
}*/

// FUNÇÃO PARA IMPRIMIR A LISTA
void exibir(tipolista lista)
{
    if (lista == NULL)
    {
        printf("\n--- LISTA DE SELECOES VAZIA ---\n");
        return;
    }

    tipolista aux = lista;
    printf("\n--- LISTA DE SELECOES ---\n");
    while (aux != NULL)
    {
        printf("[%s | Vit: %d | Gols: %d] <-> ", aux->dados.nome, aux->dados.vit, aux->dados.gols);
        aux = aux->prox;
    }
    printf("NULL\n");
}

int main()
{
    tipolista lista = NULL;
    selecao s;
    char referencia[50];
    int op = -1;
    int resultado = 0;

    while (op != 0)
    {
        exibir(lista);

        printf("\n========== MENU ==========\n");
        printf("1 - Inserir Selecao no Inicio\n");
        printf("2 - Inserir Selecao no Final\n");
        printf("3 - Inserir Selecao no Meio (Apos outra)\n");
        printf("4 - Remover Selecao do Inicio\n");
        printf("5 - Remover Selecao do Final\n");
        printf("6 - Remover Selecao Especifica\n");
        printf("7 - Verificar quantas selecoes tem na copa\n");
        printf("8 - Procure a selecao pelo o nome\n");
        printf("9 - Remover todos os perdedores\n");
        printf("10 - Ordernar selecoes por ordem decrescente\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Nome da selecao:\n");
            scanf("%s", s.nome);
            printf("Vitorias:\n");
            scanf("%d", &s.vit);
            printf("Gols:\n");
            scanf("%d", &s.gols);
            lista = inserirInic(lista, s);
            break;

        case 2:
            printf("Nome da selecao:\n");
            scanf("%s", s.nome);
            printf("Vitorias:\n");
            scanf("%d", &s.vit);
            printf("Gols:\n");
            scanf("%d", &s.gols);
            lista = inserirFinal(lista, s);
            break;

        case 3:
            printf("Nome da NOVA selecao:\n");
            scanf("%s", s.nome);
            printf("Vitorias:\n");
            scanf("%d", &s.vit);
            printf("Gols:\n");
            scanf("%d", &s.gols);
            printf("Inserir APOS qual selecao? (Digite o nome):\n");
            scanf("%s", referencia);
            lista = inserirMeio(lista, s, referencia);
            break;

        case 4:
            lista = removerInic(lista);
            break;

        case 5:
            lista = removerFim(lista);
            break;

        case 6:
            printf("Digite o nome da selecao que deseja remover: ");
            scanf("%s", referencia);
            lista = removerMeio(lista, referencia);
            break;
        case 7:
            resultado = contador(lista);
            printf("\n Tem %d selecao presentes no campeonato\n", resultado);
            break;
        case 8:
            printf("Informe o nome da selecao que deseja procurar\n");
            scanf("%s", referencia);
            tipolista achado = procurar(lista, referencia);
            break;
        case 9:
            lista = removerPerdedor(lista);
            break;
        case 10:
            lista = ordenar(lista);
            exibir(lista);
            break;
        case 11:

            break;
        case 0:
            printf("\nEncerrando sistema...\n");
            break;

        default:
            printf("\nOpcao invalida!\n");
            break;
        }
    }

    return 0;
}