#ifndef Funcionario_H
#define Funcionario_H

#include "util.hpp"
#include <string>
#include <iostream>

class Funcionario
{
private:
    string salario;
    string matricula;
    Data ingressoEmpresa;
    int diasFaltas;
public:
    Funcionario(){}
    Funcionario(string salario, string matricula, Data ingressoEmpresa, int diasFaltas);

    // Getters e setters  
    string getSalario() const;
    void setSalario(std::string salario);

    void setMatricula(string matricula);
    string getMatricula() const;

    Data getIngressoEmpresa() const;
    void setIngressoEmpresa(Data ingressoEmpresa);

    int getDiasFaltas() const;
    void setDiasFaltas(int diasFaltas);

    // Métodos virtuais puros
    virtual float calcularSalario() = 0;
    virtual float calcularRecisao(Data desligamento) = 0;
};



#endif