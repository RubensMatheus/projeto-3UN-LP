#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <string>
#include "pessoa.hpp"
#include "funcionario.hpp"

/**
 * @class Vendedor
 * @brief Classe para representar um Vendedor.
 * 
 * @details Essa classe é definida a partir das classes bases Pessoa e Funcionario e representa um Vendedor na empresa.
 */
class Vendedor : public Pessoa, public Funcionario
{
private:
    char tipoVendedor; /**< Tipo de vendedor (A, B ou C). */

public:
    Vendedor() {}
    ~Vendedor() {}
    
    /**
     * @brief Construtor da classe Vendedor.
     * @param nome O nome do Vendedor.
     * @param cpf O CPF do Vendedor.
     * @param dataNascimento A data de nascimento do Vendedor.
     * @param enderecoPessoal O endereço pessoal do Vendedor.
     * @param estadoCivil O estado civil do Vendedor.
     * @param qtdFilhos A quantidade de filhos do Vendedor.
     * @param salario O salário do Vendedor.
     * @param matricula A matrícula do Vendedor.
     * @param ingressoEmpresa A data de ingresso do Vendedor na empresa.
     * @param diasFaltas A quantidade de dias de falta do Vendedor.
     * @param tipoVendedor O tipo de vendedor.
     */
    Vendedor(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal,
            string estadoCivil, int qtdFilhos, string salario, string matricula,
            Data ingressoEmpresa, int diasFaltas, char tipoVendedor);

    // Getters e setters

    /**
     * @brief Getter, obtém o tipo de vendedor.
     * @return O tipo de vendedor.
     */
    char getTipoVendedor() const;
    
    /**
     * @brief setter, define o tipo de vendedor.
     * @param tipoVendedor O tipo de vendedor a ser definido.
     */
    void setTipoVendedor(char tipoVendedor);

    // Implementação dos métodos abstratos

    /**
     * @brief Calcula o salário do Vendedor.
     * @return O salário do Vendedor.
     */
    float calcularSalario() override;
    
    /**
     * @brief Calcula a rescisão do Vendedor.
     * @param desligamento A data de desligamento do Vendedor.
     * @return O valor da rescisão do Vendedor.
     */
    float calcularRecisao(Data desligamento) override;
};


#endif
