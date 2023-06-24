#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

#include "pessoa.hpp"
#include "asg.hpp"
#include "vendedor.hpp"
#include "gerente.hpp"

class Empresa {
private:
    float faturamentoMensal;
    string nomeEmpresa;
    string cnpj;
    Pessoa dono;
    vector<Asg> asgs;
    vector<Vendedor> vendedores;
    vector<Gerente> gerentes;

    void atualizaAsgs();
    void atualizaGerente();
    void atualizaVendedor();

public:
    // Construtor vazio
    Empresa() {}

    // Construtor parametrizado
    Empresa(string nomeEmpresa, string cnpj, float faturamentoMensal);

    // Getters e setters
    float getFaturamentoMensal() const;
    void setFaturamentoMensal(float faturamentoMensal);
    string getNomeEmpresa() const;
    void setNomeEmpresa(string nomeEmpresa);
    string getCnpj() const;
    void setCnpj(string cnpj);

    const Pessoa& getDono() const;

    const vector<Asg>& getAsgs() const;

    const vector<Vendedor>& getVendedores() const;

    const vector<Gerente>& getGerentes() const;

    void carregaFuncoes();
    void carregarEmpresa();
    void carregarAsg();
    void carregarVendedor();
    void carregarGerente();
    void carregaDono();
    void imprimeAsgs();
    void imprimeVendedores();
    void imprimeGerentes();
    void imprimeDono();
    void buscaFuncionario(string matricula);
    void calculaSalarioFuncionario(string matricula);
    void calculaTodoOsSalarios();
    void calcularRecisao(string matricula, Data desligamento);
    void demitirFuncionario(string matricula, Data desligamento);
    void contratarFuncionario();
};

#endif
