#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

#include "pessoa.hpp"
#include "asg.hpp"
#include "vendedor.hpp"
#include "gerente.hpp"

/**
 * @class Empresa
 * @brief Classe para representar uma empresa
 * 
 * @details uma empresa tem atributos como: faturamentoMensal, nomeEmpresa, cnpj, ASG, 
 * vendedores e gerentes
 * 
 */
class Empresa {
private:
    float faturamentoMensal; ///> Faturamento Mensal da Empresa
    string nomeEmpresa; ///> Nome da Empresa
    string cnpj; ///> CNPJ da Empresa
    Pessoa dono; ///> Dono (Tipo Pessoa) da empresa
    vector<Asg> asgs; ///> Vector com os funcionarios de tipo asg
    vector<Vendedor> vendedores; ///> Vector com os vendedores
    vector<Gerente> gerentes; ///> Vector com os gerentes

    /**
     * @brief Método responsável por atualizar os conteudos de asg.txt caso haja alguma 
     * modificação, contratação ou demissão, no quadro de ASG
     */
    void atualizaAsgs(); 

    /**
     * @brief Método responsável por atualizar os conteudos de gerente.txt caso haja alguma 
     * modificação, contratação ou demissão, no quadro de Gerente
     */
    void atualizaGerente();

    /**
     * @brief Método responsável por atualizar os conteudos de vendedor.txt caso haja 
     * alguma modificação, contratação ou demissão, do quadro de vendedores
     */
    void atualizaVendedor();

public:
    /**
     * @brief Construtor vazio
     * @details Construtor que inicializa uma empresa com atributos vazios.
     * 
     */
    Empresa() {}

    /**
     * @brief Construtor parametrizado
     * 
     * @details Construtor que inicializa empresa com valores para cada atributo
     * 
     * @param nomeEmpresa Nome da empresa
     * @param cnpj CNPJ da empresa
     * @param faturamentoMensal Faturamento mensal da empresa
     */
    Empresa(string nomeEmpresa, string cnpj, float faturamentoMensal);

    // Getters e setters

    /**
     * @brief Getter para FaturamentoMensal
     * 
     *  @details Permite acessar o faturamento mensal da empresa, o método é const e não 
     * pode modificar atributos de classe
     * 
     * @return O faturamento mensal (float) 
     */
    float getFaturamentoMensal() const;

    /**
     * @brief Setter para faturamentoMensal
     * 
     * @details Determina o faturamento mensal da empresa
     * 
     * @param faturamentoMensal Valor a ser atribuido ao faturamento mensal
     */
    void setFaturamentoMensal(float faturamentoMensal);

    /**
     * @brief Getter para nomeEmpresa
     * 
     *  @details Permite acessar nome da empresa, o método é const e não 
     * pode modificar atributos de classe
     * 
     * @return O nome da empresa (string)
     */
    string getNomeEmpresa() const;

    /**
     * @brief Setter para nomeEmpresa
     * 
     * @details Determina o nome da empresa
     * 
     * @param nomeEmpresa Parametro a ser atribuido a nomeEmpresa
     */
    void setNomeEmpresa(string nomeEmpresa);

    /**
     * @brief Getter para CNPJ
     * 
     *  @details Permite acessar o cnpj, o método é const e não 
     * pode modificar atributos de classe
     * 
     * @return O cnpj da empresa (string)
     */
    string getCnpj() const;

    /**
     * @brief Setter para CNPJ
     * 
     * @details Determina o cnpj da empresa
     * 
     * @param cnpj Parametro a ser atribuido a cnpj
     */
    void setCnpj(string cnpj);

    /**
     * @brief Getter para o dono da empresa
     * 
     * @return Retorna os atributos do dono da empresa
     */
    const Pessoa& getDono() const;

    /**
     * @brief Getter para o vector de asg
     * 
     * @return Retorna os atributos de asg
     */
    const vector<Asg>& getAsgs() const;

    /**
     * @brief Getter para o vector de vendedores
     * 
     * @return Retorna os atributos de vendedor
     */
    const vector<Vendedor>& getVendedores() const;

    /**
     * @brief Getter para o vector de gerentes
     * 
     * @return Retorna os atributos de gerentes
     */
    const vector<Gerente>& getGerentes() const;

    /**
     * @brief Método responsável por carregar as funções
     * 
     * @details Carrega as funções presentes no arquivo funcoes.txt, chamando-as
     * 
     */
    void carregaFuncoes();

    /**
     * @brief Método responsável por carregar empresa
     * 
     * @details Carrega os dados presentes no arquivo empresa.txt no objeto de tipo 
     * empresa, assim criando-a
     * 
     */
    void carregarEmpresa();

    /**
     * @brief Método responsável por carregar o vector de asgs
     * 
     * @details Carrega os dados presentes no arquivo asg.txt nos objetos asg e os coloca nos vetor asgs, assim preenchendo-o
     * 
     */
    void carregarAsg();

    /**
     * @brief Método responsável por carregar o vector de vendedors
     * 
     * @details Carrega os dados presentes no arquivo vendedor.txt nos objetos vendedor e os coloca nos vetor vendedores, assim preenchendo-o
     * 
     */
    void carregarVendedor();

    /**
     * @brief Método responsável por carregar o vector de gerentes
     * 
     * @details Carrega os dados presentes no arquivo gerente.txt nos objetos gerente e os coloca nos vetor gerentes, assim preenchendo-o
     * 
     */
    void carregarGerente();

    /**
     * @brief Método responsável por carregar o dono (Pessoa)
     * 
     * @details Carrega os dados presentes no arquivo dono.txt em seu respectivo objeto
     * 
     */
    void carregaDono();

    /**
     * @brief Imprime todos os dados de todos asg no terminal
     * 
     */
    void imprimeAsgs();

     /**
     * @brief Imprime todos os dados de todos vendedores no terminal
     * 
     */
    void imprimeVendedores();

     /**
     * @brief Imprime todos os dados de todos gerentes no terminal
     * 
     */
    void imprimeGerentes();

     /**
     * @brief Imprime todos os dados do dono no terminal
     * 
     */
    void imprimeDono();

    /**
     * @brief método responsável por buscar um funcionario
     * 
     * @details Busca um funcionario, a partir de sua matricula, nos arquivos de leitura 
     * vetores de funcionarios
     * 
     * @param matricula Matricula do funcionario buscado
     */
    void buscaFuncionario(string matricula);

    /**
     * @brief método responsável por calcular os salário de um funcionario
     * 
     * @details A busca acontece por meio da matricula e o calculo acontece por meio dos 
     * bonus e as faltas que esse funcionario tem
     * 
     * @param matricula Matricula do funcionario no qual o salário será calculado
     */
    void calculaSalarioFuncionario(string matricula);

    /**
     * @brief Método responsável por somar todos os salários
     * 
     * @details Nesse método é criado/alterado o arquivo salarios.txt, nesse consta a soma 
     * de todos os salários pagos pela empresa. Também é criado o relatorioFinanceiro.txt, 
     * nesse além de todos os salários também aparece o faturamento mensal, custo com 
     * pessoal, quanto cada categoria de funcionario representa no custo mensal da empresa 
     * e se essa está no lucro ou prejuizo.
     * 
     */
    void calculaTodoOsSalarios();

    /**
     * @brief Calcula a recisão que um funcionario recebe ao ser demitido
     * 
     * @details O calculo da recisão ocorre a partir do tempo de serviço, calculado a 
     * partir da dataDesligamento - dataIngresso, para cada ano servido o funcionario 
     * receberá um salário
     * 
     * @param matricula Matricula do funcionario a ser demitido
     * @param desligamento Data de desligamento desse funcionario
     */
    void calcularRecisao(string matricula, Data desligamento);

    /**
     * @brief Demite um funcionario
     * 
     * @details A partir da matricula do funcionario é realizada uma busca nos arquivos de 
     * leitura, ao ser encontrado será gerado o relatorioDemissional, no qual constará 
     * informações pessoas e o valor da recisão a ser paga, após essa parte o trecho onde 
     * esse funcionario está armazenado no arquivo será excluido 
     * 
     * @param matricula Matricula do funcionario demitido
     * @param desligamento Data de desligamento da empresa do funcionario demitido
     */
    void demitirFuncionario(string matricula, Data desligamento);

    /**
     * @brief Adiciona um novo funcionario
     * 
     * @details Após ler o arquivo novoFuncionario.txt é criado o novo funcionario, esse é 
     * inserido no vector de seu respectivo tipo e seus informações são adicionadas aos 
     * arquivos de leitura de seu tipo
     * 
     */
    void contratarFuncionario();
};

#endif