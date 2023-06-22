#ifndef ASG_H
#define ASG_H

#include <string>
#include "pessoa.hpp"
#include "funcionario.hpp"

class Asg : public Pessoa, public Funcionario
{
private:
    float adicionalInsalubridade = 0.05;
public:
    Asg() {}
    Asg(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal,
    string estadoCivil, int qtdFilhos, string salario, string matricula,
    Data ingressoEmpresa, int diasFaltas, float adicionalInsalubridade);

    // Getter e setter para adicionalInsalubridade
    float getAdicionalInsalubridade() const;
    void setAdicionalInsalubridade(float adicionalInsalubridade);

    // Implementação dos métodos abstratos da classe Funcionario
    float calcularSalario() override;
    float calcularRecisao(Data desligamento) override;

};


#endif