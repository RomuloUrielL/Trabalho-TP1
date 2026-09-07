
# Trabalho Prático 1 (TP1) - Sistema Orientado a Objetos

## 🎯 Objetivo do Software
Este projeto é a base de um sistema de software estruturado, focado em aplicar os princípios fundamentais de Programação Orientada a Objetos (POO) e Engenharia de Software. O principal objetivo é garantir a validação de regras de negócio estritas no momento da instanciação, gerenciar o armazenamento temporário de dados (em memória) e demonstrar a comunicação eficiente e desacoplada entre as diferentes camadas da aplicação.

## 🏗️ Arquitetura do Código
O software foi desenvolvido utilizando uma **Arquitetura em Camadas** (Layered Architecture). Essa abordagem promove o baixo acoplamento e a alta coesão, separando as responsabilidades de forma clara e padronizada.

A estrutura do projeto está dividida nos seguintes módulos principais:
*   **Domínios (`dominios.cpp` / `dominios.hpp`):** Classes de base que representam tipos de dados fundamentais (ex: CPF, Senha, Matrícula). Toda regra de formatação e validação de limite/tamanho é executada no momento da atribuição destes valores.
*   **Entidades (`entidades.cpp` / `entidades.hpp`):** Classes que agregam um ou mais domínios para representar conceitos de negócio complexos do mundo real (ex: Usuário, Conta).
*   **Interfaces (`interfaces.hpp`):** Arquivos puramente virtuais (classes abstratas) que definem os contratos de comunicação entre a camada de apresentação e a camada de serviço/lógica de negócio, facilitando a Injeção de Dependência.
*   **Controladoras (`controladoras.cpp` / `controladoras.hpp`):** Orquestram o fluxo da aplicação, implementando as regras de negócio e chamando os métodos adequados para cada requisição do sistema.
*   **Containers (`containers.cpp` / `containers.hpp`):** Estruturas de dados em memória responsáveis pelo armazenamento provisório (persistência simulada) das instâncias de Entidades e gerenciamento de buscas.
*   **Testes Unitários e Stubs (`testes.cpp/hpp`, `stubs.cpp/hpp`):** Rotinas de verificação automatizada. Os *stubs* atuam como simuladores controlados (mocking) com retornos pré-definidos para permitir testes independentes de módulos inacabados, serviços externos ou bancos de dados reais.
*   **Ponto de Entrada (`main.cpp`):** O script principal que interliga as instâncias, injeta as dependências e executa o fluxo central do programa.

## 🛠️ Métodos e Tecnologias Utilizadas
*   **Linguagem:** C++
*   **Paradigma:** Programação Orientada a Objetos (Encapsulamento, Herança, Polimorfismo).
*   **Design Patterns Aplicados:** Injeção de Dependência, Mocking (Stubs) para testes.
*   **Ambiente/IDE Sugerido:** Code::Blocks (Projeto já configurado em `Teste_laboratorio1.cbp`) ou compiladores CLI (GCC/G++).

## 👥 Colaboradores
*   **Rômulo Uriel Liberal de Oliveira**
    *   **Função:** Desenvolvedor.
    *   **Atribuições:** Modelagem e implementação da arquitetura base, construção das classes de domínios, entidades e interfaces. Desenvolvimento dos módulos de controle e de persistência de dados em containers. Criação dos casos de teste unitários e scripts de stubbing para garantir a robustez do software.
*   **Arthur**
    *   **Função:** Desenvolvedor.
    *   **Atribuições:** Participação no planejamento estrutural, integração de módulos, auxílio na validação de regras de negócio e testes das funcionalidades do sistema.
*   **Augusto**
    *   **Função:** Desenvolvedor / Colaborador.
    *   **Atribuições:** Desenvolvimento e implementação das controladoras do Módulo de Pessoal na camada de Apresentação (`CntrIUPessoal`), estruturando o fluxo de interação com o usuário, menus e o gerenciamento de cadastros de gerentes.

## 🚀 Como Executar
1. Clone o repositório ou faça a extração dos arquivos de código-fonte em um diretório local.
2. **Via Code::Blocks:** Abra o arquivo de projeto `Teste_laboratorio1.cbp` na IDE, faça o build e execute a aplicação.
3. **Via Terminal (g++):** Acesse a pasta do projeto e compile os arquivos utilizando o compilador C++ de sua preferência:
   ```bash
   g++ main.cpp dominios.cpp entidades.cpp controladoras.cpp containers.cpp testes.cpp stubs.cpp -o executavel_tp1
   ./executavel_tp1
   ```
