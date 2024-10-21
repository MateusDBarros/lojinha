#include <stdio.h>

//Estruturas
struct Loja {
    char nome[25];
    float preco;
    int quantidade;
};
struct Loja itens[100];
int numItens = 0;

struct ItemCarrinho {
    char nome[50];
    float preco;
    int quantidade;
};
struct ItemCarrinho carrinho[100];
int numItensCarrinho = 0;

//Funções
void adicionar(struct Loja itens[100], int *numItens);
void listar(struct Loja itens[100], int *numItens);
int adicionarCarrinho(struct Loja itens[100], int *numItens);
int remover(struct Loja itens[100], int *numItens);
void listarCarrinho(struct Loja itens[100], int *numItens);
void checkout(struct Loja itens[100], int *numItens);

int main(void)
{   
    int escolha;
    do
    {
        printf("1. Adicionar Produto.\n");
        printf("2. Listar Produtos.\n");
        printf("3. Adicionar no Carrinho.\n");
        printf("4. Remover do Carrinho.\n");
        printf("5. Listar Carrinho.\n");
        printf("6. Checkout.\n");
        printf("7. Sair.\n");
        printf("O que faremos hoje? ");

        switch (escolha)
        {
        case 1:
            adicionar(itens, numItens);
            break;
        case 2:
            listar(itens, numItens);
            break;
        case 3:
            adicionarCarrinho(itens, numItens);
            break;
        case 4:
            remover(itens, numItens);
            break;
        case 5:
            listarCarrinho(itens, numItens);
            break;
        case 6:
            checkout(itens, numItens);
            break;
        case 7:
            printf("Encerrando o programa...\n");
            return 0;
            break;
        
        default:
            printf("Escolha invalida! selecione uma das opcoes!\n");
            break;
        }

    } while (7 != escolha);
    
}

void adicionar(struct Loja itens[100], int *numItens) {
    printf("Insira o nome do produto: ");
    scanf("%s", itens[*numItens].nome);
    printf("Insira o preco do produto: ");
    scanf("%f", &itens[*numItens].preco);
    printf("Insira a quantidade que deseja adicionar: ");
    scanf("%d", &itens[*numItens].quantidade);
    printf("\nProduto Adicionado com sucesso!\n");
    (*numItens)++;
}