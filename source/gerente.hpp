/**
 * @file Gerente.hpp
 * @brief Arquivo de cabeçalho para a classe Gerente
 */

#ifndef GERENTE_HPP
#define GERENTE_HPP

#include <string>
#include "pessoa.hpp"
#include "funcionario.hpp"

/**
 * @class Gerente
 * @brief Classe para representar um Gerente
 * 
 * @details Essa classe é definida a partir das classes bases Pessoa e Funcionario e representa um gerente na empresa. 
 * Um gerente tem, além das propriedades de Pessoa e Funcionario, uma participação nos lucros da empresa.
 */
class Gerente : public Pessoa, public Funcionario {
private:
  float participacaoLucros; ///< Participação do Gerente nos lucros da empresa.

public:
  /**
   * @brief Construtor padrão
   * 
   * @details Construtor que inicializa um gerente com atributos vazios.
   */
  Gerente() {}

  /**
   * @brief Construtor parametrizado
   * 
   * @details Construtor que inicializa um gerente com valores para cada atributo.
   * 
   * @param nome Nome do gerente.
   * @param cpf CPF do gerente.
   * @param dataNascimento Data de nascimento do gerente.
   * @param enderecoPessoal Endereço residencial do gerente.
   * @param estadoCivil Estado civil do gerente.
   * @param qtdFilhos Número de filhos do gerente.
   * @param salario Salário do gerente.
   * @param matricula Matrícula do gerente na empresa.
   * @param ingressoEmpresa Data de ingresso do gerente na empresa.
   * @param diasFaltas Número de dias de falta do gerente.
   * @param participacaoLucros Participação nos lucros da empresa do gerente.
   */
  Gerente(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal,
          string estadoCivil, int qtdFilhos, string salario, string matricula,
          Data ingressoEmpresa, int diasFaltas, float participacaoLucros);

   /**
   * @brief Getter para participacaoLucros
   * 
   * @details Permite o acesso ao valor que corresponde a participação nos lucros do gerente. 
   * O método é const e não pode modificar atributos da classe.
   * 
   * @return float O valor relacionado a participação do gerente nos lucros.
   */
  float getParticipacaoLucros() const;

  /**
   * @brief Setter para participacaoLucros
   * 
   * @details Determina a participação nos lucros do gerente.
   * 
   * @param participacaoLucros Valor a ser atribuido a participação nos lucros do gerente.
   */
  void setParticipacaoLucros(float participacaoLucros);

  /**
   * @brief Calcula o salário do gerente.
   * 
   * @details Implementação do método abstrato de Funcionario para calcular o salário do gerente.
   * 
   * @return float O valor calculado do salário do gerente.
   */
  float calcularSalario() override;

  /**
   * @brief Calcula a rescisão do gerente em caso de desligamento.
   * 
   * @details Implementação do método abstrato de Funcionario para calcular a rescisão do gerente.
   * 
   * @param desligamento Data de desligamento do gerente.
   * @return float O valor calculado da rescisão do gerente.
   */
  float calcularRecisao(Data desligamento) override;
};

#endif