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

tipopilha copiaPilha(tipopilha pilha, tipopilha pilhaCopia){
    
}