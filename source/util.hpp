
/**
 * @file util.h
 * @brief Arquivo de cabeçalho com definições de estruturas utilizadas ao longo do programa
 */

#ifndef UTIL_H
#define UTIL_H

#include <iostream>
using namespace std;

/**
 * @struct Data
 * @brief Estrutura definida para representar uma data
 * 
 * @details Essa estrutura representa uma data por meio de campos para ano, mês e dia.
 */
typedef struct
{
    int ano; ///< Ano da data.
    int mes; ///< Mês da data.
    int dia; ///< Dia da data.
} Data ;

/**
 * @struct Endereco
 * @brief Estrutura definida para representar um endereço
 * 
 * @details Essa estrutura representa um endereço por meio de campos para cidade, bairro, rua, CEP e número.
 */
typedef struct 
{
    string cidade; ///< Cidade do endereço.
    string bairro; ///< Bairro do endereço.
    string rua; ///< Rua do endereço.
    string cep; ///< Cep do endereço.
    int numero; ///< Número do endereço.
} Endereco;


#endif