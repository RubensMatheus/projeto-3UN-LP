/**
 * @file Pessoa.hpp
 * @brief Arquivo de cabeçalho para a classe Pessoa
 */

#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include "util.hpp"
using namespace std;

/**
 * @class Pessoa
 * @brief Classe para representar uma Pessoa
 * 
 * @details Esta classe representa uma pessoa na empresa e seus atributos.
 */
class Pessoa
{
private:
    string nome; ///< Nome da pessoa.
    string cpf;  ///< CPF da pessoa.
    Data dataNascimento;  ///< Data de nascimento da pessoa.
    Endereco enderecoPessoal;  ///< Endereço da pessoa.
    string estadoCivil;  ///< Estado civil da pessoa.
    int qtdFilhos;  ///< Quantidade de filhos da pessoa.

public:

    /**
   * @brief Construtor padrão
   * 
   * @details Construtor que inicializa uma pessoa com atributos vazios.
   */
    Pessoa() {}

    /**
     * @brief Construtor parametrizado
     * 
     * @details Construtor que inicializa uma pessoa com valores para cada atributo.
     * 
     * @param nome Nome da pessoa.
     * @param cpf CPF da pessoa.
     * @param dataNascimento Data de nascimento da pessoa.
     * @param enderecoPessoal Endereço da pessoa.
     * @param estadoCivil Estado civil da pessoa.
     * @param qtdFilhos Quantidade de filhos da pessoa.
     */
    Pessoa(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal,string estadoCivil, int qtdFilhos);

     /**
     * @brief Destrutor
     * 
     * @details Destrutor padrão da classe Pessoa.
     */
    ~Pessoa() {}
    
    /**
     * @brief Getter para nome
     * 
     * @details Retorna o nome da pessoa. O método é const e não pode modificar atributos da classe.
     * 
     * @return string O nome da pessoa.
     */
    string getNome() const;

    /**
     * @brief Setter para nome
     * 
     * @details Determina o nome da pessoa.
     * 
     * @param nome Valor a ser atribuido ao nome da pessoa.
     */
    void setNome(string nome) ;

    /**
     * @brief Getter para CPF
     * 
     * @details Retorna o CPF da pessoa. O método é const e não pode modificar atributos da classe.
     * 
     * @return string O CPF da pessoa.
     */
    string getCPF() const ;

    /**
     * @brief Setter para CPF
     * 
     * @details Determina o CPF da pessoa.
     * 
     * @param cpf Valor a ser atribuito ao CPF da pessoa.
     */
    void setCPF(string cpf) ;

    /**
     * @brief Getter para dataNascimento
     * 
     * @details Retorna a data de nascimento da pessoa. O método é const e não pode modificar atributos da classe.
     * 
     * @return Data A data de nascimento da pessoa.
     */
    Data getDataNascimento() const ;

    /**
     * @brief Setter para dataNascimento
     * 
     * @details Determina a data de nascimento da pessoa.
     * 
     * @param dataNascimento A data de nascimento da pessoa.
     */
    void setDataNascimento(Data dataNascimento) ;


    /**
     * @brief Getter para enderecoPessoal
     * 
     * @details Retorna o endereço pessoal da pessoa. O método é const e não pode modificar atributos da classe.
     * 
     * @return Endereco Um tipo Endereço que representa o endereço pessoal da pessoa.
     */
    Endereco getEnderecoPessoal() const ;

    /**
     * @brief Setter para enderecoPessoal
     * 
     * @details Determina o endereço pessoal da pessoa.
     * 
     * @param enderecoPessoal O endereço pessoal da pessoa.
     */
    void setEnderecoPessoal(Endereco enderecoPessoal) ;


    /**
     * @brief Getter para estadoCivil
     * 
     * @details Retorna o estado civil da pessoa. O método é const e não pode modificar atributos da classe.
     * 
     * @return string O estado civil da pessoa.
     */
    string getEstadoCivil() const ;

     /**
     * @brief Setter para estadoCivil
     * 
     * @details Determina o estado civil da pessoa.
     * 
     * @param estadoCivil Estado civil da pessoa.
     */
    void setEstadoCivil(string estadoCivil) ;
    
    /**
     * @brief Getter para qtdFilhos
     * 
     * @details Retorna a quantidade de filhos da pessoa. O método é const e não pode modificar atributos da classe.
     * 
     * @return int a quantidade de filhos da pessoa.
     */
    int getQtdFilhos() const ;

    /**
     * @brief Setter para qtdFilhos
     * 
     * @details Determina a quantidade de filhos da pessoa.
     * 
     * @param qtdFilhos Quantidade de filhos da pessoa.
     */
    void setQtdFilhos(int qtdFilhos) ;
};

#endif