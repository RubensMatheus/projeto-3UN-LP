#ifndef Funcionario_H
#define Funcionario_H

#include "util.hpp"
#include <string>
#include <iostream>

/**
 * @class Funcionario
 * @brief Classe para representar um Funcionario
 * 
 * @details um Funcionario tem como atributos salario, matricula, ingresso na Empresa e
 * quantidade de faltas
 */
class Funcionario
{
private:
    string salario; ///< Salário do Funcionario
    string matricula; ///< Matricula do Funcionario
    Data ingressoEmpresa; ///< Data de ingresso na empresa
    int diasFaltas; ///< Dias faltados pelo funcionario
public:

    /**
     * @brief Construtor padrão
     * 
     * @details Construtor que inicializa um funcionario com atributos vazios.
     * 
     */
    Funcionario(){}

    /**
     * @brief Construtor parametrizado
     * 
     * @details Construtor que inicializa um funcionario com valores para cada atributo.
     * 
     * @param salario Salario do Funcionario
     * @param matricula Matricula do Funcionario
     * @param ingressoEmpresa Data de ingresso na empresa
     * @param diasFaltas Dias faltados
     */
    Funcionario(string salario, string matricula, Data ingressoEmpresa, int diasFaltas);

    // Getters e setters 

    /**
     * @brief Getter para o salario
     * 
     * @details Permite acessar o salario do funcionario, o método é const e não pode 
     * modificar atributos de classe
     * 
     * @return o salario do funcionario
     */
    string getSalario() const;

    /**
     * @brief Setter para o salário
     * 
     * @details Determina o salário do funcionario
     * 
     * @param salario Valor a ser atribuido ao salário
     */
    void setSalario(std::string salario);

    /**
     * @brief Setter para a matricula
     * 
     * @details Determina a matricula do funcionario
     * 
     * @param matricula Valor a ser atribuido a matricula
     */
    void setMatricula(string matricula);

    /**
     * @brief Getter para a matricula
     * 
     * @details Permite acessar a matricula do funcionario, o método é const e não pode 
     * modificar atributos de classe
     * 
     * @return a matricula do funcionario
     */
    string getMatricula() const;

    /**
     * @brief Getter para ingresso
     * 
     * @details Permite acessar o ingresso do funcionario na empresa, o método é const e 
     * não pode modificar atributos de classe
     * 
     * @return a data de ingresso do funcionario na empresa
     */
    Data getIngressoEmpresa() const;

    /**
     * @brief Setter para ingressoEmpresa
     * 
     * @details Determina a data de ingresso do funcionario na empresa
     * 
     * @param ingressoEmpresa Valor a ser atribuido a ingressoEmpresa
     */
    void setIngressoEmpresa(Data ingressoEmpresa);

    /**
     * @brief Getter para diasFaltas
     * 
     * @details Permite acessar a quantidade de faltas de um funcionario, o método é const 
     * e não pode modificar atributos de classe
     * 
     * @return a quantidade de faltas do funcionario
     */
    int getDiasFaltas() const;

    /**
     * @brief Setter para dias faltas
     * 
     * @details Determina quantos dias um funcionario faltou
     * 
     * @param diasFaltas Valor a ser atribuido a dias falta
     */
    void setDiasFaltas(int diasFaltas);

    // Métodos virtuais puros

    /**
     * @brief Método virtual para calcular o salario do funcionario
     * 
     * @return o salario do funcionario
     */
    virtual float calcularSalario() = 0;

    /**
     * @brief Método virtual para calcular o valor da Recisão de um funcionario
     * 
     * @param desligamento data de desligamento da empresa
     * @return O valor da recisao a ser paga ao funcionario
     */
    virtual float calcularRecisao(Data desligamento) = 0;
};



#endif