#ifndef GERENTE_HPP
#define GERENTE_HPP

#include <string>
#include "pessoa.hpp"
#include "funcionario.hpp"

class Gerente : public Pessoa, public Funcionario {
private:
  float participacaoLucros;

public:
  // Construtor vazio
  Gerente() {}

  // Construtor parametrizado
  Gerente(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal,
          string estadoCivil, int qtdFilhos, string salario, string matricula,
          Data ingressoEmpresa, int diasFaltas, float participacaoLucros);

  // Getters e setters
  float getParticipacaoLucros() const;
  void setParticipacaoLucros(float participacaoLucros);

  // Implementação dos métodos abstratos
  float calcularSalario() override;
  float calcularRecisao(Data desligamento) override;
};

#endif