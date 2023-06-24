#ifndef ASG_H
#define ASG_H

#include <string>
#include "pessoa.hpp"
#include "funcionario.hpp"

/**
 * @class Asg
 * @brief Classe para representar um ASG (Auxiliar de Serviços Gerais).
 * 
 * @details Essa classe é definida a partir das classes bases Pessoa e Funcionario e representa um ASG na empresa. 
 * Esse funcionário recebe um adicional por insalubridade no salário.
 */
class Asg : public Pessoa, public Funcionario
{
private:
    float adicionalInsalubridade = 0.05; /**< Adicional por insalubridade do ASG. */
public:
    Asg() {}
    
    /**
     * @brief Construtor da classe Asg.
     * @param nome O nome do ASG.
     * @param cpf O CPF do ASG.
     * @param dataNascimento A data de nascimento do ASG.
     * @param enderecoPessoal O endereço pessoal do ASG.
     * @param estadoCivil O estado civil do ASG.
     * @param qtdFilhos A quantidade de filhos do ASG.
     * @param salario O salário do ASG.
     * @param matricula A matrícula do ASG.
     * @param ingressoEmpresa A data de ingresso do ASG na empresa.
     * @param diasFaltas A quantidade de dias de falta do ASG.
     * @param adicionalInsalubridade O adicional por insalubridade do ASG.
     */
    Asg(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal,
        string estadoCivil, int qtdFilhos, string salario, string matricula,
        Data ingressoEmpresa, int diasFaltas, float adicionalInsalubridade);

    // Getter e setter para adicionalInsalubridade
    
    /**
     * @brief Getter, obtém o adicional por insalubridade do ASG.
     * @return O adicional por insalubridade do ASG.
     */
    float getAdicionalInsalubridade() const;
    
    /**
     * @brief Setter, define o adicional por insalubridade do ASG.
     * @param adicionalInsalubridade O adicional por insalubridade a ser definido.
     */
    void setAdicionalInsalubridade(float adicionalInsalubridade);

    // Implementação dos métodos abstratos da classe Funcionario

    /**
     * @brief Calcula o salário do ASG.
     * @return O salário do ASG.
     */
    float calcularSalario() override;
    
    /**
     * @brief Calcula a rescisão do ASG.
     * @param desligamento A data de desligamento do ASG.
     * @return O valor da rescisão do ASG.
     */
    float calcularRecisao(Data desligamento) override;

};

#endif
