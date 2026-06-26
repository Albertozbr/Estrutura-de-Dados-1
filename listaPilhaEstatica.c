/* 
Lista pilha estática
1)Dê o conceito de Pilha. R: o conceito de pilha vêm de empilhar tal coisa, sempre olhando do topo, podendo inserir mais itens e removelos.
2)) Qual é a analogia que pode-se utilizar como modelo para explicar uma pilha? R:Usaria a analogia da pilha de pratos que tem varios pratos um em cima do outro e olhando de cima, conseguimos ver apenas no topo da pilha.
3)Explique a disposição dos itens em uma pilha. R: Os elementos são postos um a cima do outro, o primeiro elemento posto na pilha será a base e o ultimo, chamaresmo de topo.
4) LIFO, last in firts out, sempre o ultimo que entrar, será o primeiro removido.
5)Descreva o conjunto de operações e suas finalidades. R: Criar pilha: declaramos o conjunto da pilha e declaramos uma variável para indicar o topo ex: um vetor P de tamanho 3, topo -1 pois o vetor começa com "0". Pilha Vazia: verificamos se existe elementos na pilha, para isso verificamos o topo, se o topo for NULL, então a pilha está vazia. Pilha Cheia: verificar o valor do tamanho da pilha, se estiver iguais, pilha cheia. Inserir: se a pilha estiver cheia nao tem é possivel inserir nenhum elemento, se não, recebe o novo valor incrementa no topo e insira o novo valor. Remover: se pilha estiver vazia nao tem como remover pois não há nenhuma elemento, se nao, decrementa o elemento do topo.
6)Comente sobre a implementação de Pilhas por meio de Arranjo. R: O arranjo serve para definirmos o tamanho da pilha, como é feito em um vetor então declaramos um numero maximo fixo, podendo assim, ter uma limiação na pilha, ocorrendo a famosa "pilha cheia"
7) Quais os dois itens observados para a estrutura de Pilhas com Arranjo? R:  Como já mencionado, para criar uma pilha estática precisamos do arranjo para declarar um conjunto de pilhas, e também precisamos de declarar a variável que indicará o topo da pilha.
Questão 8 e 9(códgigo).
Questão 10: letra B
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 3

typedef struct{
    int topo;
    int dados[TAM];
}tipopilha;

void inicializar(tipopilha *pilha){
    pilha->topo = -1;
}

int cheia(tipopilha *pilha){
    if(pilha->topo == TAM-1){
        return 1; //se a pilha estiver cheia ele retorna verdade, 1
    }else{
        return 0;//se nao retorna falso, 0
    }
}
int vazia(tipopilha *pilha){
    if(pilha->topo == -1){
        return 1;//mesma lógica
    }else{
        return 0;
    }
}  
void inserir(tipopilha *pilha, int valor){
    if(cheia(pilha)==1){
       printf("\nPilha cheia\n");
    }else{
        pilha->topo++; //posição do vetor(gaveta)
        pilha->dados[pilha->topo] = valor;// na posição 0 tem o valor x, pilha->dados[0] = x;
         printf("\n%d Inserido com sucesso!\n",valor);
    }
}
void remover(tipopilha *pilha){
    if(vazia(pilha)==1){
        printf("\nVazia\n");
    }
    else{
        printf("\n%d Removido!\n", pilha->dados[pilha->topo]);
        pilha->topo--;
    }
}

void exibir(tipopilha *pilha){
    int posicao = pilha->topo;
    printf("\n---Pilha atual---\n");
    if(vazia(pilha)==1){
        printf("\nVazia\n");
    }else{
        while(posicao != -1){
            printf("\t %d\n", pilha->dados[posicao]);
            posicao--;
        }
    }
}

void pesquisar(tipopilha *pilha, int valor){
    int posicao = pilha->topo;
    int contador = 0;

    if(vazia(pilha)==1){
        printf("\nPilha Vazia\n");
    }else{
        while(posicao!=-1){
            if(valor == pilha->dados[posicao]){
                contador++;
            }
            posicao--;
        }
        printf("Teve %d pesquisar do valor: %d", contador, valor);
    }
}

void exibirTopo(tipopilha *pilha){
    if(vazia(pilha)==1){
        printf("\nVazia\n");
    }else{
        printf("\n O valor do topo eh: %d\n", pilha->dados[pilha->topo]);
    }
}

void main(){
    tipopilha pilha;
    int op = -1;
    int valor = 0;

    inicializar(&pilha);

    while(op != 0){
    valor = 0;
    exibir(&pilha);
    printf("DIGITE 0 PARA SAIR\n");
    printf("1: Inserir\n");
    printf("2: Remover\n");
    printf("3: Visualizar topo\n");
    printf("4: Pesquisar\n");
    scanf("%d",&op);

    switch(op){
        case 1:
        printf("digite um valor\n");
        scanf("%d", &valor);
        inserir(&pilha, valor);
        break;

        case 2:
        remover(&pilha);
        break;

        case 3:
        exibirTopo(&pilha);
        break;

        case 4:
        printf("Informe um valor:\n");
        scanf("%d", &valor);
        pesquisar(&pilha, valor);
        break;

        case 0:
        printf("programa finalizado!\n");
        break;

        default:
        printf("Opcao invalida\n");
        break;
    }
    }
}