#include <stdio.h>
#include <string.h>

//Estruturas
struct Loja {
    char nome[25];
    float preco;
    int quantidade;
};
struct Loja itens[100];
int numItens = 0;

struct ItemCarrinho {
    char nome[25];
    float preco;
    int quantidade;
};
struct ItemCarrinho carrinho[100];
int numItensCarrinho = 0;

//Funções
void adicionar(struct Loja itens[100], int *numItens);
void listar(struct Loja itens[100], int *numItens);
void adicionarCarrinho(struct Loja itens[100], struct ItemCarrinho carrinho[100], int *numItens, int *numItensCarrinho);
void remover(struct ItemCarrinho carrinho[100], int *numItensCarrinho);
void listarCarrinho(struct Loja itens[100], int *numItensCarrinho);
void checkout(struct ItemCarrinho carrinho[100] ,int *numItensCarrinho);

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
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            adicionar(itens, numItens);
            break;
        case 2:
            listar(itens, numItens);
            break;
        case 3:
            adicionarCarrinho(itens, carrinho, numItens, numItensCarrinho);
            break;
        case 4:
            remover(itens, numItensCarrinho);
            break;
        case 5:
            listarCarrinho(itens, numItens);
            break;
        case 6:
            checkout(itens, numItensCarrinho);
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

void listar(struct Loja itens[100], int *numItens) {
    if (*numItens == 0) {
        printf("Sem itens no catalogo!");
        return;
    }
    printf("| %-15s | %-5f | %-5d \n", "Nome", "Preco", "Quantidade");
    printf("---------------|--------|-----\n");
    for (int i = 0; i < *numItens; i++) {
        printf("| %-15s | %-5f | %-5d \n", itens[i].nome, itens[i].preco, itens[i].quantidade);
         printf("---------------|--------|-----\n");
    }
}

void adicionarCarrinho(struct Loja itens[100], struct ItemCarrinho carrinho[100], int *numItens, int *numItensCarrinho) {
    char nome[25];
    int quantidade;
    printf("Qual produto deseja adicionar ao carrinho? ");
    scanf("%s", nome);
    for (int i = 0; i < *numItens; i++) {
        if (strcmp(itens[i].nome, nome) == 0) {
            printf("Qual a quantidade deseja adicionar? ");
            scanf("%d", &quantidade);
            if (itens[i].quantidade >= quantidade){
                itens[i].quantidade -= quantidade;
                strcpy(carrinho[*numItensCarrinho].nome, itens[i].nome);
                carrinho[*numItensCarrinho].preco = itens[i].preco;
                carrinho[*numItensCarrinho].quantidade = quantidade;
                printf("Item adicionado ao carrinho.\n");
                (*numItensCarrinho)++;
                return;
            }
            else {
                printf("Quantidade indisponivel!\n");
                return;
            }
    }
    }
    printf("Produto nao encontrado!\n");
    return;
}

void remover(struct ItemCarrinho carrinho[100], int *numItensCarrinho) {
    if(*numItensCarrinho == 0) { //Se o carrinho não tiver itens, encerra a função
        printf("Carrinho vazio, volte as compras!\n");
        return;
    }
    char nome[25];
    printf("Qual item deseja remover do carrinho? ");
    scanf("%s", nome);
    for (int i = 0; i < *numItensCarrinho; i++) {
        if (strcmp(carrinho[i].nome, nome) == 0) {
            for (int j = i; j < *numItensCarrinho - 1; j++){ //Numero total ja corrigido para evitar que o loop acesse uma parte indevida da memoria
                carrinho[j].preco = carrinho[j + 1].preco;
                carrinho[j].quantidade = carrinho[j + 1].quantidade;
                strcpy(carrinho[j].nome, carrinho[j + 1].nome);
            }
            printf("Item removido com sucesso!\n");
            (*numItensCarrinho)--;
            return;
        }
    }
    printf("Item não encontrado!\n");
    return;
}

void listarCarrinho(struct Loja carrinho[100], int *numItensCarrinho) {
    if (*numItensCarrinho == 0) {
        printf("Sem itens no carrinho, Volte as compras!\n");
        return;
    }
    printf("| %-15s | %-5f | %-5d \n", "Nome", "Preco", "Quantidade");
    printf("---------------|--------|-----\n");
    for (int i = 0; i < *numItensCarrinho; i++) {
        printf("| %-15s | %-5f | %-5d \n", carrinho[i].nome, carrinho[i].preco, carrinho[i].quantidade);
         printf("---------------|--------|-----\n");
    }
}
