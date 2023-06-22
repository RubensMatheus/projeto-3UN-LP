#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <string>
#include "pessoa.hpp"
#include "funcionario.hpp"

class Vendedor : public Pessoa, public Funcionario
{
private:
    char tipoVendedor;

public:
    Vendedor() {}
    ~Vendedor() {}
    Vendedor(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal,
            string estadoCivil, int qtdFilhos, string salario, string matricula,
            Data ingressoEmpresa, int diasFaltas, char tipoVendedor);

    // Getters e setters
    char getTipoVendedor() const;
    void setTipoVendedor(char tipoVendedor);

    // Implementação dos métodos abstratos
    float calcularSalario() override;
    float calcularRecisao(Data desligamento) override;
};


#endif