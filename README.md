# Simulador de Loja Virtual

Este projeto implementa um simulador de loja virtual em linguagem C. Ele permite adicionar produtos ao catálogo, gerenciar um carrinho de compras e finalizar a compra com um sistema de descontos.

## Funcionalidades

- **Adicionar Produtos ao Catálogo**: Permite adicionar novos produtos com nome, preço e quantidade.
- **Listar Produtos**: Exibe todos os produtos disponíveis no catálogo.
- **Adicionar ao Carrinho**: Permite adicionar produtos do catálogo ao carrinho de compras.
- **Remover do Carrinho**: Remove produtos do carrinho.
- **Listar Carrinho**: Exibe todos os itens no carrinho de compras.
- **Checkout**: Calcula o total da compra, aplica descontos e finaliza a compra.

## Estrutura do Projeto

- **Catálogo de Produtos**:
  - Array de produtos (`struct Loja`).
  - Funções: `adicionar`, `listar`.

- **Carrinho de Compras**:
  - Array de itens no carrinho (`struct ItemCarrinho`).
  - Funções: `adicionarCarrinho`, `remover`, `listarCarrinho`.

- **Checkout**:
  - Função: `checkout`.
