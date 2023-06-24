/**
 * @file main.cpp
 * @author Rubens Matheus Venancio (rubensmatheusvenancio@gmail.com), 
 *         Wisla Argolo (wisla.argolo.133@ufrn.edu.br ),
 *         Gabriel Ribeiro (gabriel.ribeiro.099@ufrn.edu.br).
 * 
 * @brief O projeto tem como objetivo desenvolver um sistema de RH para a empresa de calçados 
 * "Atacado dos Calçados". A empresa conta com três tipos de profissionais: gerentes, 
 * vendedores, ASGs (Auxiliares de Serviços Gerais) e o dono da empresa.
 * @version 0.1
 * @date 2023-06-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include "empresa.hpp"

using namespace std;

/**
 * @brief Função principal do programa.
 * @return 0 em caso de sucesso.
 */
int main (){

    Empresa *atacadoDosCalcado = new Empresa("Atacado dos Calcados", "40.101.588/0001-98", 156289.56 );
    atacadoDosCalcado->carregaFuncoes();
    
    return 0;
}