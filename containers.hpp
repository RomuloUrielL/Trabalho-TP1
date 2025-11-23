#ifndef CONTAINERS_HPP_INCLUDED
#define CONTAINERS_HPP_INCLUDED

#include "entidades.hpp"
#include <map>
#include <string>
#include <vector>

using namespace std;
/**
@brief Classe responsável pela persistência em memória de objetos Hotel.
@details Esta classe implementa o design pattern Singleton, garantindo que
exista apenas uma instância do repositório de hotéis durante toda a execução
do programa. Utiliza a estrutura de dados map para o armazenamento ,
onde a chave é o código do hotel e o valor é o objeto Hotel.
*/
class ContainerHoteis{
    private:
        static ContainerHoteis* instancia;
        map<string, Hotel> container;
        ContainerHoteis(){}
    public:
        /**
        @brief Recupera a instância única do Container de Hotéis.
        @details Se a instância ainda não existir, ela é criada. Caso contrário,
        retorna a instância já existente.
        @return Ponteiro para o objeto singleton ContainerHoteis.
        */
        static ContainerHoteis* getInstancia();

        /**
        @brief Insere um novo hotel no sistema.
        @param hotel Objeto Hotel a ser armazenado.
        @return true se o hotel foi inserido com sucesso. false se já existir um
        hotel com o mesmo código (chave duplicada).
        */
        bool incluir(Hotel hotel);
        /**
        @brief Busca um hotel pelo seu código.
        @details Utiliza o código contido no objeto passado como parâmetro para
        buscar no mapa.
        @param hotel Ponteiro para um objeto Hotel. Na entrada, deve conter
        o código a ser buscado. Se encontrado, o objeto apontado será preenchido
        com os dados completos do hotel.
        @return true se o hotel foi encontrado. false se o código não existe no
        container.
        */
        bool pesquisar(Hotel* hotel);
        /**
        @brief Atualiza os dados de um hotel existente.
        @details Substitui o objeto Hotel armazenado pelo novo objeto fornecido.
        A busca é feita pelo código, que não pode ser alterado.
        @param hotel Objeto Hotel com os dados atualizados.
        @return true se a atualização foi realizada com sucesso.
        @return false se o hotel não foi encontrado para edição.
        */
        bool atualizar(Hotel hotel);
        /**
        @brief Remove um hotel do sistema.
        @param codigo String contendo o código do hotel a ser removido.
        @return true se o hotel foi removido com sucesso. false se o código não
        foi encontrado.
        */
        bool remover(string codigo);
        /**
        @brief Lista todos os hotéis cadastrados.
        @details Itera sobre todo o mapa e copia os objetos Hotel para o vetor
        fornecido.
        @param hoteis Vetor que receberá a lista de hotéis.
        @return true se a operação foi realizada com sucesso.
        */
        bool listar(vector<Hotel>& hoteis);
};

/**
@brief Classe responsável pela persistência em memória de objetos Reserva.
@details Esta classe implementa o design pattern Singleton, garantindo que
exista apenas uma instância do repositório de reservas durante toda a execução
do programa. Utiliza a estrutura de dados map para o armazenamento ,
onde a chave é o código da reserva e o valor é o objeto Reserva.
*/
class ContainerReservas{
    private:
        static ContainerReservas* instancia;
        map<string, Reserva> container;
        ContainerReservas(){}
    public:
        /**
        @brief Recupera a instância única do Container de Reservas.
        @details Se a instância ainda não existir, ela é criada. Caso contrário,
        retorna a instância já existente.
        @return Ponteiro para o objeto singleton ContainerReservas.
        */
        static ContainerReservas* getInstancia();

        /**
        @brief Insere uma nova reserva no sistema.
        @param reserva Objeto Reserva a ser armazenado.
        @return true se a reserva foi inserida com sucesso. false se já existir
         uma reserva com o mesmo código.
        */
        bool incluir(Reserva reserva);
        /**
        @brief Busca uma reserva pelo seu código.
        @details Utiliza o código contido no objeto passado como parâmetro para
        buscar no mapa.
        @param reserva Ponteiro para um objeto Reserva. Na entrada, deve conter
        o código a ser buscado. Se encontrado, o objeto apontado será preenchido
        com os dados completos da reserva.
        @return true se a reserva foi encontrada. false se o código não existe
        no container.
        */
        bool pesquisar(Reserva* reserva);
        /**
        @brief Atualiza os dados de uma reserva existente.
        @details Substitui o objeto Reserva armazenado pelo novo objeto
        fornecido.A busca é feita pelo código da reserva.
        @param reserva Objeto Reserva com os dados atualizados.
        @return true se a atualização foi realizada com sucesso. false se a
        reserva não foi encontrada para edição.
        */
        bool atualizar(Reserva reserva);
        /**
        @brief Remove uma reserva do sistema.
        @param codigo String contendo o código da reserva a ser removida.
        @return true se a reserva foi removida com sucesso. false se o código
        não foi encontrado.
        */
        bool remover(string codigo);
        /**
        @brief Lista todas as reservas associadas a um hotel específico.
        @details Percorre o mapa filtrando as reservas cujo código do hotel
        corresponda ao filtro fornecido.
        @param codigoHotelFiltro String com o código do hotel para filtragem.
        @param reservas Vetor que receberá a lista filtrada.
        @return true se a operação foi realizada com sucesso. false caso
        contrário.
        */
        bool listar(string codigoHotelFiltro, vector<Reserva>& reservas);
        /**
        @brief Lista todas as reservas cadastradas.
        @details Itera sobre todo o mapa e copia os objetos Reserva para o vetor
        fornecido.
        @param reservas Vetor que receberá a lista de reservas.
        @return true se a operação foi realizada com sucesso. false caso
        contrário.
        */
        bool listar(vector<Reserva>& reservas);
};

/**
@brief Classe responsável pela persistência em memória de objetos Hospede.
@details Esta classe implementa o design pattern Singleton, garantindo que
exista apenas uma instância do repositório de hóspedes durante toda a execução
do programa. Utiliza a estrutura de dados map para o armazenamento,
onde a chave é o email do hóspede e o valor é o objeto Hospede.
*/
class ContainerHospedes{
    private:
        static ContainerHospedes* instancia;
        map<string, Hospede> container;



        ContainerHospedes(){}
    public:
        /**
        @brief Recupera a instância única do Container de Hóspedes.
        @details Se a instância ainda não existir, ela é criada. Caso contrário,
        retorna a instância já existente.
        @return Ponteiro para o objeto singleton ContainerHospedes.
        */
        static ContainerHospedes* getInstancia();

        /**
        @brief Insere um novo hóspede no sistema.
        @param hospede Objeto Hospede a ser armazenado.
        @return true se o hóspede foi inserido com sucesso. false se já existir
        um hóspede com o mesmo email.
        */
        bool incluir(Hospede hospede);
        /**
        @brief Busca um hóspede pelo seu email.
        @details Utiliza o email contido no objeto passado como parâmetro para
        buscar no mapa.
        @param hospede Ponteiro para um objeto Hospede. Na entrada, deve conter
        o email a ser buscado. Se encontrado, o objeto apontado será preenchido
        com os dados completos do hóspede.
        @return true se o hóspede foi encontrado. false se o email não existe no
        container.
        */
        bool pesquisar(Hospede* hospede);
        /**
        @brief Atualiza os dados de um hóspede existente.
        @details Substitui o objeto Hospede armazenado pelo novo objeto
        fornecido.
        A busca é feita pelo email.
        @param hospede Objeto Hospede com os dados atualizados.
        @return true se a atualização foi realizada com sucesso. false se o
        hóspede não foi encontrado para edição.
        */
        bool atualizar(Hospede hospede);
        /**
        @brief Remove um hóspede do sistema.
        @param email String contendo o email do hóspede a ser removido.
        @return true se o hóspede foi removido com sucesso. false se o email não
        foi encontrado.
        */
        bool remover(string email);
        /**
        @brief Lista todos os hóspedes associados a um hotel específico.
        @details Percorre o mapa filtrando os hóspedes que possuem vínculo
        com o código do hotel fornecido.
        @param codigoHotelFiltro String com o código do hotel para filtragem.
        @param hospedes Vetor que receberá a lista filtrada.
        @return true se a operação foi realizada com sucesso. false caso
        contrário.
        */
        bool listar(string codigoHotelFiltro, vector<Hospede>& hospedes);
        /**
        @brief Lista todos os hóspedes cadastrados.
        @details Itera sobre todo o mapa e copia os objetos Hospede para o vetor
        fornecido.
        @param hospedes Vetor que receberá a lista de hóspedes.
        @return true se a operação foi realizada com sucesso. false caso
        contrário.
        */
        bool listar(vector<Hospede>& hospedes);
};

/**
@brief Classe responsável pela persistência em memória de objetos Quarto.
@details Esta classe implementa o design pattern Singleton, garantindo que
exista apenas uma instância do repositório de quartos durante toda a execução
do programa. Utiliza a estrutura de dados map para o armazenamento,
onde a chave é o número do quarto e o valor é o objeto Quarto.
*/
class ContainerQuartos{
    private:
        static ContainerQuartos* instancia;
        map<string, Quarto> container;
        ContainerQuartos(){}
    public:
        /**
        @brief Recupera a instância única do Container de Quartos.
        @details Se a instância ainda não existir, ela é criada. Caso contrário,
        retorna a instância já existente.
        @return Ponteiro para o objeto singleton ContainerQuartos.
        */
        static ContainerQuartos* getInstancia();

        /**
        @brief Insere um novo quarto no sistema.
        @param quarto Objeto Quarto a ser armazenado.
        @return true se o quarto foi inserido com sucesso. false se já existir
        um quarto com o mesmo número.
        */
        bool incluir(Quarto quarto);
        /**
        @brief Busca um quarto pelo seu número.
        @details Utiliza o número contido no objeto passado como parâmetro para
        buscar no mapa.
        @param quarto Ponteiro para um objeto Quarto. Na entrada, deve conter
        o número a ser buscado. Se encontrado, o objeto apontado será preenchido
        com os dados completos do quarto.
        @return true se o quarto foi encontrado. false se o número não existe no
        container.
        */
        bool pesquisar(Quarto* quarto);
        /**
        @brief Atualiza os dados de um quarto existente.
        @details Substitui o objeto Quarto armazenado pelo novo objeto
        fornecido.
        A busca é feita pelo número, que não pode ser alterado.
        @param quarto Objeto Quarto com os dados atualizados.
        @return true se a atualização foi realizada com sucesso. false se o
        quarto não foi encontrado para edição.
        */
        bool atualizar(Quarto quarto);
        /**
        @brief Remove um quarto do sistema.
        @param numero String contendo o número do quarto a ser removido.
        @return true se o quarto foi removido com sucesso. false se o número não
        foi encontrado.
        */
        bool remover(string numero);
        /**
        @brief Lista todos os quartos pertencentes a um hotel específico.
        @details Percorre o mapa filtrando os quartos cujo código do hotel
        corresponda ao filtro fornecido.
        @param codigoHotel String com o código do hotel para filtragem.
        @param quartos Vetor que receberá a lista filtrada.
        @return true se a operação foi realizada com sucesso. false caso
        contrário.
        */
        bool listar(string codigoHotelFiltro, vector<Quarto>& quartos);
        /**
        @brief Lista todos os quartos cadastrados.
        @details Itera sobre todo o mapa e copia os objetos Quarto para o vetor
        fornecido.
        @param quartos Vetor que receberá a lista de quartos.
        @return true se a operação foi realizada com sucesso. false caso
        contrário.
        */
        bool listar(vector<Quarto>& quarto);
};


/**
@brief Classe responsável pela persistência em memória de objetos Gerente.
@details Esta classe implementa o design pattern Singleton, garantindo que
exista apenas uma instância do repositório de gerentes durante toda a execução
do programa. Utiliza a estrutura de dados map para o armazenamento,
onde a chave é o email do gerente e o valor é o objeto Gerente.
*/
class ContainerGerentes{
    private:
        static ContainerGerentes* instancia;
        map<string, Gerente> container;
        ContainerGerentes(){}
    public:
        /**
        @brief Recupera a instância única do Container de Gerentes.
        @details Se a instância ainda não existir, ela é criada. Caso contrário,
        retorna a instância já existente.
        @return Ponteiro para o objeto singleton ContainerGerentes.
        */
        static ContainerGerentes* getInstancia();

        /**
        @brief Insere um novo gerente no sistema.
        @param gerente Objeto Gerente a ser armazenado.
        @return true se o gerente foi inserido com sucesso. false se já existir
        um gerente com o mesmo email.
        */
        bool incluir(Gerente gerente);
        /**
        @brief Busca um gerente pelo seu email.
        @details Utiliza o email contido no objeto passado como parâmetro para
        buscar no mapa.
        @param gerente Ponteiro para um objeto Gerente. Na entrada, deve conter
        o email a ser buscado. Se encontrado, o objeto apontado será preenchido
        com os dados completos do gerente.
        @return true se o gerente foi encontrado. false se o email não existe no
        container.
        */
        bool pesquisar(Gerente* gerente);
        /**
        @brief Atualiza os dados de um gerente existente.
        @details Substitui o objeto Gerente armazenado pelo novo objeto
        fornecido.
        A busca é feita pelo email, que não pode ser alterado.
        @param gerente Objeto Gerente com os dados atualizados.
        @return true se a atualização foi realizada com sucesso. false se o
        gerente não foi encontrado para edição.
        */
        bool atualizar(Gerente gerente);
        /**
        @brief Remove um gerente do sistema.
        @param email String contendo o email do gerente a ser removido.
        @return true se o gerente foi removido com sucesso. false se o email não
        foi encontrado.
        */
        bool remover(string email);
};

#endif // CONTAINERS_HPP_INCLUDED
