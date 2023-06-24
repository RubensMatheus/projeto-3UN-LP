#include "empresa.hpp"

// Construtor parametrizado
Empresa::Empresa(string nomeEmpresa, string cnpj, float faturamentoMensal)
    : nomeEmpresa(nomeEmpresa), cnpj(cnpj), faturamentoMensal(faturamentoMensal) {}

// Getters e setters
float Empresa::getFaturamentoMensal() const {
  return faturamentoMensal;
}

void Empresa::setFaturamentoMensal(float faturamentoMensal) {
  this->faturamentoMensal = faturamentoMensal;
}

string Empresa::getNomeEmpresa() const {
  return nomeEmpresa;
}

void Empresa::setNomeEmpresa(string nomeEmpresa) {
  this->nomeEmpresa = nomeEmpresa;
}

string Empresa::getCnpj() const {
  return cnpj;
}

void Empresa::setCnpj(string cnpj) {
  this->cnpj = cnpj;
}

const Pessoa& Empresa::getDono() const {
  return dono;
}

const vector<Asg>& Empresa::getAsgs() const {
  return asgs;
}

const vector<Vendedor>& Empresa::getVendedores() const {
  return vendedores;
}

const vector<Gerente>& Empresa::getGerentes() const {
  return gerentes;
}

// Restante dos métodos

void Empresa::carregaFuncoes() {
    try {
        fstream funcoes;
        funcoes.open("leitura/funcoes.txt", ios::in);
        if (!funcoes.is_open()) {
            throw runtime_error("Ocorreu falha ao tentar abrir o arquivo");
        }

        string linha;
        vector<string> vetor;

        // Lê todas as linhas do arquivo e salva cada linha em um vector
        while (getline(funcoes, linha)) {
            vetor.push_back(linha);
        }
        funcoes.close();

        for (size_t i = 0; i < vetor.size(); i++) {
        if (vetor[i] == "carregarEmpresa()") { carregarEmpresa(); }
        else if (vetor[i] == "carregarAsg()") { carregarAsg(); }
        else if (vetor[i] == "carregarVendedor()") { carregarVendedor(); }
        else if (vetor[i] == "carregarGerente()") { carregarGerente(); }
        else if (vetor[i] == "carregaDono()") { carregaDono(); }
        else if (vetor[i] == "imprimeAsgs()") { imprimeAsgs(); }
        else if (vetor[i] == "imprimeVendedores()") { imprimeVendedores(); }
        else if (vetor[i] == "imprimeGerentes()") { imprimeGerentes(); }
        else if (vetor[i] == "imprimeDono()") { imprimeDono(); }
        else if (vetor[i] == "buscaFuncionario()") { buscaFuncionario(vetor[i+1]); }
        else if (vetor[i] == "calculaSalarioFuncionario()") { calculaSalarioFuncionario(vetor[i+1]); }
        else if (vetor[i] == "calculaTodoOsSalarios()") { calculaTodoOsSalarios(); }
       /* else if (vetor[i] == "calcularRecisao()") { 
            Data temp;
            temp.ano = stoi(vetor[i+2]);
            temp.mes = stoi(vetor[i+3]);
            temp.dia = stoi(vetor[i+4]);
            calcularRecisao(vetor[i+1], temp); }*/
    else if(vetor[i] == "demitirFuncionario()") {
        string matricula = vetor[i+1];
        Data temp;
        temp.ano = stoi(vetor[i+2]);
        temp.mes = stoi(vetor[i+3]);
        temp.dia = stoi(vetor[i+4]);
        demitirFuncionario(matricula, temp);
    }
    else if(vetor[i] == "contratarFuncionario()") { contratarFuncionario(); }
    }
    } catch (const exception& e) {
        cout << "Ocorreu uma exceção: " << e.what() << endl;
    }

}

void Empresa::carregarEmpresa() {
    try {
        fstream empresaArq;
        empresaArq.open("leitura/empresa.txt", ios::in);
        if (!empresaArq.is_open()) {
            throw runtime_error("Ocorreu falha ao tentar abrir o arquivo");
        }

        string linha;
        vector<string> vetor;

        while (getline(empresaArq, linha)) {
            vetor.push_back(linha);
        }
        empresaArq.close();

        nomeEmpresa = vetor[2];
        cnpj = vetor[3];
        faturamentoMensal = stof(vetor[4]);

        Empresa empresa(nomeEmpresa, cnpj, faturamentoMensal);
    } catch (const exception& e) {
        cout << "Ocorreu uma exceção: " << e.what() << endl;
    }
}

void Empresa::carregarAsg() {
    try {
        fstream asgArq;
        asgArq.open("leitura/asg.txt", ios::in);
        if (!asgArq.is_open()) {
            throw runtime_error("Ocorreu falha ao tentar abrir o arquivo");
        }

        string linha;
        vector<string> vetor;

        while (getline(asgArq, linha)) {
            vetor.push_back(linha);
        }
        asgArq.close();

        for (size_t i = 0; i < vetor.size(); i+=26){
            if (vetor[i] == "#########################################################"){
                Data aux;
                aux.ano = stoi(vetor[i+14]);
                aux.mes = stoi(vetor[i+15]);
                aux.dia = stoi(vetor[i+16]);

                Endereco end;
                end.cidade = vetor[i+8];
                end.cep = vetor[i+9];
                end.bairro = vetor[i+10];
                end.rua = vetor[i+11];
                end.numero = stoi(vetor[i+12]);

                Data ingresso;
                ingresso.ano = stoi(vetor[i+23]);
                ingresso.mes = stoi(vetor[i+24]);
                ingresso.dia = stoi(vetor[i+25]);

                Asg temp(vetor[i+3], vetor[i+4], aux, end, vetor[i+6], stoi(vetor[i+5]), vetor[i+19],
                    vetor[i+18], ingresso, stoi(vetor[i+21]), stof(vetor[i+20]));
                
                asgs.push_back(temp);
            }   
        }
    } catch (const exception& e) {
        cout << "Ocorreu uma exceção: " << e.what() << endl;
    }
}

void Empresa::carregarVendedor() {
    try {
        fstream vendedorArq;
        vendedorArq.open("leitura/vendedor.txt", ios::in);
        if (!vendedorArq.is_open()) {
            throw runtime_error("Ocorreu falha ao tentar abrir o arquivo");
        }

        string linha;
        vector<string> vetor;

        while (getline(vendedorArq, linha)) {
            vetor.push_back(linha);
        }
        vendedorArq.close();

        for (size_t i = 0; i < vetor.size(); i+=26){
            if (vetor[i] == "#########################################################"){
                Data aux;
                aux.ano = stoi(vetor[i+14]);
                aux.mes = stoi(vetor[i+15]);
                aux.dia = stoi(vetor[i+16]);

                Endereco end;
                end.cidade = vetor[i+8];
                end.cep = vetor[i+9];
                end.bairro = vetor[i+10];
                end.rua = vetor[i+11];
                end.numero = stoi(vetor[i+12]);

                Data ingresso;
                ingresso.ano = stoi(vetor[i+23]);
                ingresso.mes = stoi(vetor[i+24]);
                ingresso.dia = stoi(vetor[i+25]);

                const char* charArray = vetor[i+20].c_str();

                Vendedor temp(vetor[i+3], vetor[i+4], aux, end, vetor[i+6], stoi(vetor[i+5]), vetor[i+19],
                    vetor[i+18], ingresso, stoi(vetor[i+21]), charArray[0]);
                
                vendedores.push_back(temp);
            }   
        }
    } catch (const exception& e) {
        cout << "Ocorreu uma exceção: " << e.what() << endl;
    }
}

void Empresa::carregarGerente() {
    try {
        fstream gerenteArq;
        gerenteArq.open("leitura/gerente.txt", ios::in);
        if (!gerenteArq.is_open()) {
            throw runtime_error("Ocorreu falha ao tentar abrir o arquivo");
        }

        string linha;
        vector<string> vetor;

        while (getline(gerenteArq, linha)) {
            vetor.push_back(linha);
        }
        gerenteArq.close();

        for (size_t i = 0; i < vetor.size(); i+=26){
            if (vetor[i] == "#########################################################"){
                Data aux;
                aux.ano = stoi(vetor[i+14]);
                aux.mes = stoi(vetor[i+15]);
                aux.dia = stoi(vetor[i+16]);

                Endereco end;
                end.cidade = vetor[i+8];
                end.cep = vetor[i+9];
                end.bairro = vetor[i+10];
                end.rua = vetor[i+11];
                end.numero = stoi(vetor[i+12]);

                Data ingresso;
                ingresso.ano = stoi(vetor[i+23]);
                ingresso.mes = stoi(vetor[i+24]);
                ingresso.dia = stoi(vetor[i+25]);

                Gerente temp(vetor[i+3], vetor[i+4], aux, end, vetor[i+6], stoi(vetor[i+5]), vetor[i+19],
                    vetor[i+18], ingresso, stoi(vetor[i+21]), stof(vetor[i+20]));
                
                gerentes.push_back(temp);
            }   
        }
    } catch (const exception& e) {
        cout << "Ocorreu uma exceção: " << e.what() << endl;
    }
}

void Empresa::carregaDono() {
    try {
        fstream donoArq;
        donoArq.open("leitura/dono.txt", ios::in);
        if (!donoArq.is_open()) {
            throw runtime_error("Ocorreu falha ao tentar abrir o arquivo");
        }

        string linha;
        vector<string> vetor;

        while (getline(donoArq, linha)) {
            vetor.push_back(linha);
        }
        donoArq.close();

        dono.setNome(vetor[2]);
        dono.setCPF(vetor[3]);
        dono.setQtdFilhos(stoi(vetor[4]));
        dono.setEstadoCivil(vetor[5]);

        Endereco endr;
        endr.cidade = vetor[6];
        endr.cep = vetor[7];
        endr.bairro = vetor[8];
        endr.rua = vetor[9];
        endr.numero = stoi(vetor[10]);

        dono.setEnderecoPessoal(endr);

        Data data;
        data.ano = stoi(vetor[11]);
        data.mes = stoi(vetor[12]);
        data.dia = stoi(vetor[13]);

        dono.setDataNascimento(data);
    } catch (const exception& e) {
        cout << "Ocorreu uma exceção: " << e.what() << endl;
    }
}

void Empresa::imprimeAsgs(){
    int cont = 0;
    cout << "\n\n\n";
    for (const auto& asg : asgs) {
        cout << "#########################################################" << endl;
        cout << "ASG Nº: " << cont << endl;

        cout << "##### DADOS PESSOAIS #####" << endl;
        cout << "Nome: " << asg.getNome() << endl;
        cout << "CPF: " << asg.getCPF() << endl;
        cout << "Qtd. Filhos: " << asg.getQtdFilhos() << endl;
        cout << "Estado Civil: " << asg.getEstadoCivil() << endl;

        cout << "***** Endereço ****" << endl;
        cout << "Cidade: " << asg.getEnderecoPessoal().cidade << endl;
        cout << "CEP: " << asg.getEnderecoPessoal().cep << endl;
        cout << "Bairro: " << asg.getEnderecoPessoal().bairro << endl;
        cout << "Rua: " << asg.getEnderecoPessoal().rua << endl;
        cout << "Número: " << asg.getEnderecoPessoal().numero << endl;

        cout << "***** Data de nascimento ****" << endl;
        cout << "Data de Nascimento: " << asg.getDataNascimento().ano << "/"
                << asg.getDataNascimento().mes << "/" << asg.getDataNascimento().dia << endl;

        cout << "##### DADOS FUNCIONAIS #####" << endl;
        cout << "Matrícula: " << asg.getMatricula() << endl;
        cout << "Cargo: Asg" << endl; 
        cout << "Salário: " << asg.getSalario() << endl;
        cout << "Adicional de Insalubridade: " << asg.getAdicionalInsalubridade() << endl;
        cout << "Dias de Faltas: " << asg.getDiasFaltas() << endl;
        cout << "***** Data de ingresso ****" << endl;
        cout << "Data de Ingresso: " << asg.getIngressoEmpresa().ano << "/"
                << asg.getIngressoEmpresa().mes << "/" << asg.getIngressoEmpresa().dia << endl;

        cout << "#########################################################" << endl;
        ++cont;
  }
}

void Empresa::imprimeVendedores() {
    int cont = 0;
    cout << "\n\n\n";
    for (const auto& vendedor : vendedores) {
        cout << "#########################################################" << endl;
        cout << "Vendedor Nº: " << cont << endl;

        cout << "##### DADOS PESSOAIS #####" << endl;
        cout << "Nome: " << vendedor.getNome() << endl;
        cout << "CPF: " << vendedor.getCPF() << endl;
        cout << "Qtd. Filhos: " << vendedor.getQtdFilhos() << endl;
        cout << "Estado Civil: " << vendedor.getEstadoCivil() << endl;

        cout << "***** Endereço ****" << endl;
        cout << "Cidade: " << vendedor.getEnderecoPessoal().cidade << endl;
        cout << "CEP: " << vendedor.getEnderecoPessoal().cep << endl;
        cout << "Bairro: " << vendedor.getEnderecoPessoal().bairro << endl;
        cout << "Rua: " << vendedor.getEnderecoPessoal().rua << endl;
        cout << "Número: " << vendedor.getEnderecoPessoal().numero << endl;

        cout << "***** Data de nascimento ****" << endl;
        cout << "Data de Nascimento: " << vendedor.getDataNascimento().ano << "/"
                << vendedor.getDataNascimento().mes << "/" << vendedor.getDataNascimento().dia << endl;

        cout << "##### DADOS FUNCIONAIS #####" << endl;
        cout << "Matrícula: " << vendedor.getMatricula() << endl;
        cout << "Cargo: Vendedor - Tipo: " << vendedor.getTipoVendedor() << endl; 
        cout << "Salário: " << vendedor.getSalario() << endl;
        cout << "Dias de Faltas: " << vendedor.getDiasFaltas() << endl;
        cout << "***** Data de ingresso ****" << endl;
        cout << "Data de Ingresso: " << vendedor.getIngressoEmpresa().ano << "/"
                << vendedor.getIngressoEmpresa().mes << "/" << vendedor.getIngressoEmpresa().dia << endl;

        cout << "#########################################################" << endl;
        ++cont;
    }
}

void Empresa::imprimeGerentes() {
    int cont = 0;
    cout << "\n\n\n";
    for (const auto& gerente : gerentes) {
        cout << "#########################################################" << endl;
        cout << "Gerente Nº: " << cont << endl;

        cout << "##### DADOS PESSOAIS #####" << endl;
        cout << "Nome: " << gerente.getNome() << endl;
        cout << "CPF: " << gerente.getCPF() << endl;
        cout << "Qtd. Filhos: " << gerente.getQtdFilhos() << endl;
        cout << "Estado Civil: " << gerente.getEstadoCivil() << endl;

        cout << "***** Endereço ****" << endl;
        cout << "Cidade: " << gerente.getEnderecoPessoal().cidade << endl;
        cout << "CEP: " << gerente.getEnderecoPessoal().cep << endl;
        cout << "Bairro: " << gerente.getEnderecoPessoal().bairro << endl;
        cout << "Rua: " << gerente.getEnderecoPessoal().rua << endl;
        cout << "Número: " << gerente.getEnderecoPessoal().numero << endl;

        cout << "***** Data de nascimento ****" << endl;
        cout << "Data de Nascimento: " << gerente.getDataNascimento().ano << "/"
                  << gerente.getDataNascimento().mes << "/" << gerente.getDataNascimento().dia << endl;

        cout << "##### DADOS FUNCIONAIS #####" << endl;
        cout << "Matrícula: " << gerente.getMatricula() << endl;
        cout << "Cargo: Gerente" << endl; 
        cout << "Salário: " << gerente.getSalario() << endl;
        cout << "Participação nos Lucros: " << gerente.getParticipacaoLucros() << endl;
        cout << "Dias de Faltas: " << gerente.getDiasFaltas() << endl;

        cout << "***** Data de ingresso ****" << endl;
        cout << "Data de Ingresso: " << gerente.getIngressoEmpresa().ano << "/"
                  << gerente.getIngressoEmpresa().mes << "/" << gerente.getIngressoEmpresa().dia << endl;

        cout << "#########################################################" << endl;
        ++cont;
    }
}

void Empresa::imprimeDono() {
    cout << "\n\n\n";
    cout << "#########################################################" << endl;
    cout << "##### DADOS PESSOAIS DO DONO #####" << endl;
    cout << "Nome: " << dono.getNome() << endl;
    cout << "CPF: " << dono.getCPF() << endl;
    cout << "Qtd. Filhos: " << dono.getQtdFilhos() << endl;
    cout << "Estado Civil: " << dono.getEstadoCivil() << endl;

    cout << "***** Endereço ****" << endl;
    cout << "Cidade: " << dono.getEnderecoPessoal().cidade << endl;
    cout << "CEP: " << dono.getEnderecoPessoal().cep << endl;
    cout << "Bairro: " << dono.getEnderecoPessoal().bairro << endl;
    cout << "Rua: " << dono.getEnderecoPessoal().rua << endl;
    cout << "Número: " << dono.getEnderecoPessoal().numero << endl;

    cout << "***** Data de nascimento ****" << endl;
    cout << "Data de Nascimento: " << dono.getDataNascimento().ano << "/"
              << dono.getDataNascimento().mes << "/" << dono.getDataNascimento().dia << endl;

    cout << "#########################################################" << endl;
}

void Empresa::buscaFuncionario(string matricula) {
    int count;
     cout << "\n##########    Buscando funcionário    ##########" <<endl;
    for (auto asg : asgs){
        if (asg.getMatricula() == matricula){
            ++count;
            cout << "#########################################################" << endl;

            cout << "##### DADOS PESSOAIS #####" << endl;
            cout << "Nome: " << asg.getNome() << endl;
            cout << "CPF: " << asg.getCPF() << endl;
            cout << "Qtd. Filhos: " << asg.getQtdFilhos() << endl;
            cout << "Estado Civil: " << asg.getEstadoCivil() << endl;

            cout << "***** Endereço ****" << endl;
            cout << "Cidade: " << asg.getEnderecoPessoal().cidade << endl;
            cout << "CEP: " << asg.getEnderecoPessoal().cep << endl;
            cout << "Bairro: " << asg.getEnderecoPessoal().bairro << endl;
            cout << "Rua: " << asg.getEnderecoPessoal().rua << endl;
            cout << "Número: " << asg.getEnderecoPessoal().numero << endl;

            cout << "***** Data de nascimento ****" << endl;
            cout << "Data de Nascimento: " << asg.getDataNascimento().ano << "/"
                    << asg.getDataNascimento().mes << "/" << asg.getDataNascimento().dia << endl;

            cout << "##### DADOS FUNCIONAIS #####" << endl;
            cout << "Matrícula: " << asg.getMatricula() << endl;
            cout << "Cargo: Asg" << endl; 
            cout << "Salário: " << asg.getSalario() << endl;
            cout << "Adicional de Insalubridade: " << asg.getAdicionalInsalubridade() << endl;
            cout << "Dias de Faltas: " << asg.getDiasFaltas() << endl;
            cout << "***** Data de ingresso ****" << endl;
            cout << "Data de Ingresso: " << asg.getIngressoEmpresa().ano << "/"
                    << asg.getIngressoEmpresa().mes << "/" << asg.getIngressoEmpresa().dia << endl;

            cout << "#########################################################" << endl;
        
        }
    }


    for (auto vendedor : vendedores) {
        if (vendedor.getMatricula() == matricula){
            ++count;
            cout << "#########################################################" << endl;

            cout << "##### DADOS PESSOAIS #####" << endl;
            cout << "Nome: " << vendedor.getNome() << endl;
            cout << "CPF: " << vendedor.getCPF() << endl;
            cout << "Qtd. Filhos: " << vendedor.getQtdFilhos() << endl;
            cout << "Estado Civil: " << vendedor.getEstadoCivil() << endl;

            cout << "***** Endereço ****" << endl;
            cout << "Cidade: " << vendedor.getEnderecoPessoal().cidade << endl;
            cout << "CEP: " << vendedor.getEnderecoPessoal().cep << endl;
            cout << "Bairro: " << vendedor.getEnderecoPessoal().bairro << endl;
            cout << "Rua: " << vendedor.getEnderecoPessoal().rua << endl;
            cout << "Número: " << vendedor.getEnderecoPessoal().numero << endl;

            cout << "***** Data de nascimento ****" << endl;
            cout << "Data de Nascimento: " << vendedor.getDataNascimento().ano << "/"
                    << vendedor.getDataNascimento().mes << "/" << vendedor.getDataNascimento().dia << endl;

            cout << "##### DADOS FUNCIONAIS #####" << endl;
            cout << "Matrícula: " << vendedor.getMatricula() << endl;
            cout << "Cargo: Vendedor - Tipo: " << vendedor.getTipoVendedor() << endl; 
            cout << "Salário: " << vendedor.getSalario() << endl;
            cout << "Dias de Faltas: " << vendedor.getDiasFaltas() << endl;
            cout << "***** Data de ingresso ****" << endl;
            cout << "Data de Ingresso: " << vendedor.getIngressoEmpresa().ano << "/"
                    << vendedor.getIngressoEmpresa().mes << "/" << vendedor.getIngressoEmpresa().dia << endl;

            cout << "#########################################################" << endl;
        }
    }

    for (auto gerente : gerentes) {
        if (gerente.getMatricula() == matricula){
            ++count;
            cout << "#########################################################" << endl;

            cout << "##### DADOS PESSOAIS #####" << endl;
            cout << "Nome: " << gerente.getNome() << endl;
            cout << "CPF: " << gerente.getCPF() << endl;
            cout << "Qtd. Filhos: " << gerente.getQtdFilhos() << endl;
            cout << "Estado Civil: " << gerente.getEstadoCivil() << endl;

            cout << "***** Endereço ****" << endl;
            cout << "Cidade: " << gerente.getEnderecoPessoal().cidade << endl;
            cout << "CEP: " << gerente.getEnderecoPessoal().cep << endl;
            cout << "Bairro: " << gerente.getEnderecoPessoal().bairro << endl;
            cout << "Rua: " << gerente.getEnderecoPessoal().rua << endl;
            cout << "Número: " << gerente.getEnderecoPessoal().numero << endl;

            cout << "***** Data de nascimento ****" << endl;
            cout << "Data de Nascimento: " << gerente.getDataNascimento().ano << "/"
                    << gerente.getDataNascimento().mes << "/" << gerente.getDataNascimento().dia << endl;

            cout << "##### DADOS FUNCIONAIS #####" << endl;
            cout << "Matrícula: " << gerente.getMatricula() << endl;
            cout << "Cargo: Gerente" << endl; 
            cout << "Salário: " << gerente.getSalario() << endl;
            cout << "Participação nos Lucros: " << gerente.getParticipacaoLucros() << endl;
            cout << "Dias de Faltas: " << gerente.getDiasFaltas() << endl;

            cout << "***** Data de ingresso ****" << endl;
            cout << "Data de Ingresso: " << gerente.getIngressoEmpresa().ano << "/"
                    << gerente.getIngressoEmpresa().mes << "/" << gerente.getIngressoEmpresa().dia << endl;

            cout << "#########################################################" << endl;
            
        }
    }

    if (count == 0) { cout << "Funcionário não encontrado no sistema\n"; }
}

void Empresa::calculaSalarioFuncionario(string matricula){

     cout << "\n##########    Calculando Salário do Funcionário    ##########" <<endl;
    int count = 0;
    for (auto asg : asgs){
        if (asg.getMatricula() == matricula){
            cout << "O Salario final do asg " << asg.getNome() << " é " << asg.calcularSalario() << endl;
            ++count;
        }
    }

    if(!count) {
    for (auto vendedor : vendedores){
        if (vendedor.getMatricula() == matricula){
            cout << "O Salario final do vendedor " << vendedor.getNome() << " é " << vendedor.calcularSalario() << endl;
            ++count;
        }
    }
    }

    if(!count) {
    for (auto gerente : gerentes){
        if (gerente.getMatricula() == matricula){
            cout << "O Salario final do gerente " << gerente.getNome() << " é " << gerente.calcularSalario() << endl;
            ++count;
        }
    }
    }

    if (count == 0) { cout << "Funcionário não encontrado no sistema\n"; }
}

void Empresa::calculaTodoOsSalarios() {
    double salariosAsgs;
    double salariosVendedores;
    double salariosGerentes;

    fstream salarios;
    salarios.open("salarios.txt", ios::out );

     cout << "\n##########    Calculando todos os salários    ##########";

    for (auto asg : asgs){
        salarios << "#########################################################" << endl;
        salarios << "Nome: " <<asg.getNome() << endl;
        salarios << "Cargo: Asg" << endl;
        salarios << "Salario: " << asg.calcularSalario() << endl;
        salarios << "#########################################################" << endl;

        cout << "\n\n\n";
        cout << "#########################################################" << endl;
        cout << "Nome: " <<asg.getNome() << endl;
        cout << "Cargo: Asg" << endl;
        cout << "Salario: " << asg.calcularSalario() << endl;
        cout << "#########################################################" << endl;

        double aux = asg.calcularSalario();

        salariosAsgs += aux;
    }

    for (auto vendedor : vendedores){
        salarios << "#########################################################" << endl;
        salarios << "Nome: " <<vendedor.getNome() << endl;
        salarios << "Cargo: Vendedor - Tipo: " << vendedor.getTipoVendedor() << endl; 
        salarios << "Salario: " << vendedor.calcularSalario() << endl;
        salarios << "#########################################################" << endl;

        cout << "\n\n\n";
        cout << "#########################################################" << endl;
        cout << "Nome: " <<vendedor.getNome() << endl;
        cout << "Cargo: Vendedor - Tipo: " << vendedor.getTipoVendedor() << endl; 
        cout << "Salario: " << vendedor.calcularSalario() << endl;
        cout << "#########################################################" << endl;

        double aux = vendedor.calcularSalario() ;

        salariosVendedores += aux;
    }

    for (auto gerente : gerentes){
        salarios << "#########################################################" << endl;
        salarios << "Nome: " <<gerente.getNome() << endl;
        salarios << "Cargo: Gerente" << endl;
        salarios << "Salario: " << gerente.calcularSalario() << endl;
        salarios << "#########################################################" << endl;

        cout << "\n\n\n";
        cout << "#########################################################" << endl;
        cout << "Nome: " <<gerente.getNome() << endl;
        cout << "Cargo: Gerente" << endl;
        cout << "Salario: " << gerente.calcularSalario() << endl;
        cout << "#########################################################" << endl;

        double aux = gerente.calcularSalario();
        salariosGerentes += aux;
    }

    float salarioTT = salariosAsgs + salariosGerentes + salariosVendedores;

    salarios << "#########################################################" << endl;
    salarios << "Salario total dos Asgs: " << salariosAsgs << endl;
    salarios << "Salario total dos Vendedores " << salariosVendedores << endl;
    salarios << "Salario total dos Gerentes " << salariosGerentes << endl;
    salarios << "Salario total de todos os funcionarios " << salarioTT << endl;
    salarios << "#########################################################" << endl;

    salarios.close();

    cout << "\n\n\n";
    cout << "#########################################################" << endl;
    cout << "Salario total dos Asgs: " << salariosAsgs << endl;
    cout << "Salario total dos Vendedores " << salariosVendedores << endl;
    cout << "Salario total dos Gerentes " << salariosGerentes << endl;
    cout << "Salario total de todos os funcionarios " << salarioTT << endl;
    cout << "#########################################################" << endl;
}

void Empresa::calcularRecisao(string matricula, Data desligamento) {
    int count = 0;

     cout << "\n##########    Calculando recisão    ##########" <<endl;

    for (auto asg : asgs){
        if (asg.getMatricula() == matricula){
            ++count;
            cout << "A recisao do asg " << asg.getNome() << " é " << asg.calcularRecisao(desligamento) << endl;
        }
    }

    if(!count) {
    for (auto vendedor : vendedores){
        if (vendedor.getMatricula() == matricula){
            ++count;
            cout << "A recisao do vendedor " << vendedor.getNome() << " é " << vendedor.calcularRecisao(desligamento) << endl;
        }
    }
    }

    if(!count) {
    for (auto gerente : gerentes){
        if (gerente.getMatricula() == matricula){
            ++count;
            cout << "A recisao do gerente " << gerente.getNome() << " é " << gerente.calcularRecisao(desligamento) << endl;
        }
    }
    }

    if (count == 0) { cout << "Funcionário não encontrado no sistema\n"; }
}


void Empresa::atualizaAsgs() {
    fstream arquivo;
    arquivo.open("leitura/asg.txt", ios::out); //Apaga o arquivo original
    int i = 0;

    string linha;
    for (auto &asg : asgs) {
        // Grava cada atributo do ASG no arquivo, formatado da maneira correta
       arquivo << "#########################################################\n"
                << "ASG Nº: " << i << "\n"
                << "##### DADOS PESSOAIS #####\n"
                << asg.getNome() << "\n"
                << asg.getCPF() << "\n"
                << asg.getQtdFilhos() << "\n"
                << asg.getEstadoCivil() << "\n"
                << "***** Endereço (cidade, cep, bairro, rua e numero) ****\n"
                << asg.getEnderecoPessoal().cidade << "\n"
                << asg.getEnderecoPessoal().cep << "\n"
                << asg.getEnderecoPessoal().bairro << "\n"
                << asg.getEnderecoPessoal().rua << "\n"
                << asg.getEnderecoPessoal().numero << "\n"
                << "***** Data de nascimento (ano, mes, dia) ****\n"
                << asg.getDataNascimento().ano << "\n"
                << asg.getDataNascimento().mes << "\n"
                << asg.getDataNascimento().dia << "\n"
                << "##### DADOS FUNCIONAIS #####\n"
                << asg.getMatricula() << "\n"
                << asg.getSalario() << "\n"
                << asg.getAdicionalInsalubridade() << "\n"
                << asg.getDiasFaltas() << "\n"   
                << "***** Data de ingresso (ano, mes, dia) ****\n"
                << asg.getIngressoEmpresa().ano << "\n"
                << asg.getIngressoEmpresa().mes << "\n"
                << asg.getIngressoEmpresa().dia << "\n";
                ++i;
    }
    arquivo.close();
}

void Empresa::atualizaGerente() {
    fstream arquivo;
    arquivo.open("leitura/gerente.txt", ios::out); //Apaga o arquivo original
    int i = 0;

    string linha;
    for (auto &gerente : gerentes) {
        // Grava cada atributo do Gerente no arquivo , formatado da maneira correta
       arquivo << "#########################################################\n"
                << "GERENTE Nº: " << i << "\n"
                << "##### DADOS PESSOAIS #####\n"
                << gerente.getNome() << "\n"
                << gerente.getCPF() << "\n"
                << gerente.getQtdFilhos() << "\n"
                << gerente.getEstadoCivil() << "\n"
                << "***** Endereço (cidade, cep, bairro, rua e numero) ****\n"
                << gerente.getEnderecoPessoal().cidade << "\n"
                << gerente.getEnderecoPessoal().cep << "\n"
                << gerente.getEnderecoPessoal().bairro << "\n"
                << gerente.getEnderecoPessoal().rua << "\n"
                << gerente.getEnderecoPessoal().numero << "\n"
                << "***** Data de nascimento (ano, mes, dia) ****\n"
                << gerente.getDataNascimento().ano << "\n"
                << gerente.getDataNascimento().mes << "\n"
                << gerente.getDataNascimento().dia << "\n"
                << "##### DADOS FUNCIONAIS #####\n"
                << gerente.getMatricula() << "\n"
                << gerente.getSalario() << "\n"
                << gerente.getParticipacaoLucros() << "\n"
                << gerente.getDiasFaltas() << "\n"  
                << "***** Data de ingresso (ano, mes, dia) ****\n"
                << gerente.getIngressoEmpresa().ano << "\n"
                << gerente.getIngressoEmpresa().mes << "\n"
                << gerente.getIngressoEmpresa().dia << "\n";
                ++i;
    }
    arquivo.close();
}

void Empresa::atualizaVendedor() {
    fstream arquivo;
    arquivo.open("leitura/vendedor.txt", ios::out); //Apaga o arquivo original
    int i = 0;

    string linha;
    for (auto &vendedor : vendedores) {
        // Grava cada atributo do Vendedor no arquivo, formatado da maneira correta
       arquivo << "#########################################################\n"
                << "VENDEDOR Nº: " << i << "\n"
                << "##### DADOS PESSOAIS #####\n"
                << vendedor.getNome() << "\n"
                << vendedor.getCPF() << "\n"
                << vendedor.getQtdFilhos() << "\n"
                << vendedor.getEstadoCivil() << "\n"
                << "***** Endereço (cidade, cep, bairro, rua e numero) ****\n"
                << vendedor.getEnderecoPessoal().cidade << "\n"
                << vendedor.getEnderecoPessoal().cep << "\n"
                << vendedor.getEnderecoPessoal().bairro << "\n"
                << vendedor.getEnderecoPessoal().rua << "\n"
                << vendedor.getEnderecoPessoal().numero << "\n"
                << "***** Data de nascimento (ano, mes, dia) ****\n"
                << vendedor.getDataNascimento().ano << "\n"
                << vendedor.getDataNascimento().mes << "\n"
                << vendedor.getDataNascimento().dia << "\n"
                << "##### DADOS FUNCIONAIS #####\n"
                << vendedor.getMatricula() << "\n"
                << vendedor.getSalario() << "\n"
                << vendedor.getTipoVendedor() << "\n"
                << vendedor.getDiasFaltas() << "\n"   
                << "***** Data de ingresso (ano, mes, dia) ****\n"
                << vendedor.getIngressoEmpresa().ano << "\n"
                << vendedor.getIngressoEmpresa().mes << "\n"
                << vendedor.getIngressoEmpresa().dia << "\n";
                ++i;
    }
    arquivo.close();
}

void Empresa::demitirFuncionario(string matricula, Data desligamento) {
    fstream relatorio;
    relatorio.open("relatorioDemissional.txt", ios::out );

    cout << "\n##########    Relatório demissional    ##########" <<endl;

    bool asgContratado = false;
    bool vendedorContratado = false;
    bool gerenteContratado = false;

    for (auto it = asgs.begin(); it != asgs.end(); ++it){
        if (it->getMatricula() == matricula) {
            float rescisao = it->calcularRecisao(desligamento);
            // Salva os dados no arquivo relatorioDemissional
            relatorio << "#########################################################\n" 
                      << "Cargo: Auxiliar de Serviços Gerais\n"
                      << "Nome: " << it->getNome() << "\n"
                      << "CPF: " << it->getCPF() << "\n"
                      << "Matricula: " << it->getMatricula() << "\n"
                      << "Data de Ingresso: " << it->getIngressoEmpresa().dia  << "/" << it->getIngressoEmpresa().mes << "/" << it->getIngressoEmpresa().ano << "\n"
                      << "Data de Demissão: " << desligamento.dia  << "/" << desligamento.mes << "/" << desligamento.ano << "\n"
                      << "Tempo trabalhado: " << "\n"
                      << "Valor de rescisao: " << rescisao << "\n"
                      << "#########################################################\n"; 

            asgs.erase(it);

            asgContratado = true;
            break;
        }
    }

    if(!asgContratado) {
    for (auto it = vendedores.begin(); it != vendedores.end(); ++it){
        if (it->getMatricula() == matricula) {
            float rescisao = it->calcularRecisao(desligamento);
            // Salva os dados no arquivo relatorioDemissional
            relatorio << "#########################################################\n" 
                      << "Cargo: Vendedor\n"
                      << "Nome: " << it->getNome() << "\n"
                      << "CPF: " << it->getCPF() << "\n"
                      << "Matricula: " << it->getMatricula() << "\n"
                      << "Data de Ingresso: " << it->getIngressoEmpresa().dia  << "/" << it->getIngressoEmpresa().mes << "/" << it->getIngressoEmpresa().ano << "\n"
                      << "Data de Demissão: " << desligamento.dia  << "/" << desligamento.mes << "/" << desligamento.ano << "\n"
                      << "Tempo trabalhado: " << "\n"
                      << "Valor de rescisao: " << rescisao << "\n"
                      << "#########################################################\n"; 

            vendedores.erase(it);

            vendedorContratado = true;
            break;
        }
    }
    }


    if(!(vendedorContratado || asgContratado)){
    for (auto it = gerentes.begin(); it != gerentes.end(); ++it){
        if (it->getMatricula() == matricula) {
            float rescisao = it->calcularRecisao(desligamento);
            // Salva os dados no arquivo relatorioDemissional
            relatorio << "#########################################################\n"
                      << "Cargo: Gerente\n"
                      << "Nome: " << it->getNome() << "\n"
                      << "CPF: " << it->getCPF() << "\n"
                      << "Matricula: " << it->getMatricula() << "\n"
                      << "Data de Ingresso: " << it->getIngressoEmpresa().dia  << "/" << it->getIngressoEmpresa().mes << "/" << it->getIngressoEmpresa().ano << "\n"
                      << "Data de Demissão: " << desligamento.dia  << "/" << desligamento.mes << "/" << desligamento.ano << "\n"
                      << "Tempo trabalhado: " << "\n"  
                      << "Valor de rescisao: " << rescisao << "\n"
                      << "#########################################################\n"; 

            gerentes.erase(it);

            gerenteContratado = true;
            break;
        }
    }
    }

    relatorio.close();

    // Verifica se os dados foram salvos corretamente no arquivo relatorioDemissional
    if (!(asgContratado || vendedorContratado || gerenteContratado)) 
        cout << "Funcionário não encontrado no sistema\n"; 
    else {
        try {
            fstream relatorioTeste;
            relatorioTeste.open("relatorioDemissional.txt", ios::in);

            if (!relatorioTeste.is_open()) {
                throw runtime_error("Ocorreu falha ao tentar abrir o arquivo");
            }

            string linha;
            // Imprime cada linha do relatório
            while (getline(relatorioTeste, linha)){ 
                cout << linha << endl;
            }
            
            relatorioTeste.close();

        } catch (const exception& e) {
            cout << "Ocorreu uma exceção: " << e.what() << endl;
        }
    
        // Atualiza os arquivos de input
        if(asgContratado)
            atualizaAsgs();
        else if(gerenteContratado)
            atualizaGerente();
        else if(vendedorContratado)
            atualizaVendedor();
    }

}

void Empresa::contratarFuncionario(){
    try {
        fstream novofun;
        novofun.open("leitura/novoFuncionario.txt", ios::in);
        if (!novofun.is_open()) {
            throw runtime_error("Ocorreu falha ao tentar abrir o arquivo");
        }

        string linha;
        vector<string> vetor;

        while (getline(novofun, linha)) {
            vetor.push_back(linha);
        }
        novofun.close();

        bool asgContratado = false;
        bool vendedorContratado = false;
        bool gerenteContratado = false;

        cout << "\n##########    Funcionarios contratados    ##########\n\n" <<endl;

        for (size_t i = 0; i < vetor.size(); i+=25){
            if (vetor[i+0] == "ASG"){
                asgContratado = true;
                Data nascimento;
                nascimento.ano = stoi(vetor[i+13]);
                nascimento.mes = stoi(vetor[i+14]);
                nascimento.dia = stoi(vetor[i+15]);

                Endereco end;
                end.cidade = vetor[i+7];
                end.cep = vetor[i+8];
                end.bairro = vetor[i+9];
                end.rua = vetor[i+10];
                end.numero = stoi(vetor[i+11]);

                Data ingresso;
                ingresso.ano = stoi(vetor[i+22]);
                ingresso.mes = stoi(vetor[i+23]);
                ingresso.dia = stoi(vetor[i+24]);

                Asg temp(vetor[i+2], vetor[i+3], nascimento, end, vetor[i+5], stoi(vetor[i+4]), vetor[i+18],
                    vetor[i+17], ingresso, stoi(vetor[i+20]), stof(vetor[i+19]));

                cout << "#########################################################" << endl;

                cout << "##### DADOS PESSOAIS #####" << endl;
                cout << "Nome: " << temp.getNome() << endl;
                cout << "CPF: " << temp.getCPF() << endl;
                cout << "Qtd. Filhos: " << temp.getQtdFilhos() << endl;
                cout << "Estado Civil: " << temp.getEstadoCivil() << endl;

                cout << "***** Endereço ****" << endl;
                cout << "Cidade: " << temp.getEnderecoPessoal().cidade << endl;
                cout << "CEP: " << temp.getEnderecoPessoal().cep << endl;
                cout << "Bairro: " << temp.getEnderecoPessoal().bairro << endl;
                cout << "Rua: " << temp.getEnderecoPessoal().rua << endl;
                cout << "Número: " << temp.getEnderecoPessoal().numero << endl;

                cout << "***** Data de nascimento ****" << endl;
                cout << "Data de Nascimento: " << temp.getDataNascimento().ano << "/"
                        << temp.getDataNascimento().mes << "/" << temp.getDataNascimento().dia << endl;

                cout << "##### DADOS FUNCIONAIS #####" << endl;
                cout << "Matrícula: " << temp.getMatricula() << endl;
                cout << "Cargo: Asg" << endl; 
                cout << "Salário: " << temp.getSalario() << endl;
                cout << "Adicional de Insalubridade: " << temp.getAdicionalInsalubridade() << endl;
                cout << "Dias de Faltas: " << temp.getDiasFaltas() << endl;
                cout << "***** Data de ingresso ****" << endl;
                cout << "Data de Ingresso: " << temp.getIngressoEmpresa().ano << "/"
                        << temp.getIngressoEmpresa().mes << "/" << temp.getIngressoEmpresa().dia << endl;

                cout << "#########################################################" << endl;
                
                asgs.push_back(temp);
            } else if(vetor[i+0] == "VENDEDOR") {
                vendedorContratado = true;
                Data aux;
                aux.ano = stoi(vetor[i+13]);
                aux.mes = stoi(vetor[i+14]);
                aux.dia = stoi(vetor[i+15]);

                Endereco end;
                end.cidade = vetor[i+7];
                end.cep = vetor[i+8];
                end.bairro = vetor[i+9];
                end.rua = vetor[i+10];
                end.numero = stoi(vetor[i+11]);

                Data ingresso;
                ingresso.ano = stoi(vetor[i+22]);
                ingresso.mes = stoi(vetor[i+23]);
                ingresso.dia = stoi(vetor[i+24]);

                const char* charArray = vetor[i+19].c_str();

                Vendedor temp(vetor[i+2], vetor[i+3], aux, end, vetor[i+5], stoi(vetor[i+4]), vetor[i+18],
                    vetor[i+17], ingresso, stoi(vetor[i+20]), charArray[0]);
                
                cout << "#########################################################" << endl;

                cout << "##### DADOS PESSOAIS #####" << endl;
                cout << "Nome: " << temp.getNome() << endl;
                cout << "CPF: " << temp.getCPF() << endl;
                cout << "Qtd. Filhos: " << temp.getQtdFilhos() << endl;
                cout << "Estado Civil: " << temp.getEstadoCivil() << endl;

                cout << "***** Endereço ****" << endl;
                cout << "Cidade: " << temp.getEnderecoPessoal().cidade << endl;
                cout << "CEP: " << temp.getEnderecoPessoal().cep << endl;
                cout << "Bairro: " << temp.getEnderecoPessoal().bairro << endl;
                cout << "Rua: " << temp.getEnderecoPessoal().rua << endl;
                cout << "Número: " << temp.getEnderecoPessoal().numero << endl;

                cout << "***** Data de nascimento ****" << endl;
                cout << "Data de Nascimento: " << temp.getDataNascimento().ano << "/"
                        << temp.getDataNascimento().mes << "/" << temp.getDataNascimento().dia << endl;

                cout << "##### DADOS FUNCIONAIS #####" << endl;
                cout << "Matrícula: " << temp.getMatricula() << endl;
                cout << "Cargo: Vendedor - Tipo: " << temp.getTipoVendedor() << endl; 
                cout << "Salário: " << temp.getSalario() << endl;
                cout << "Dias de Faltas: " << temp.getDiasFaltas() << endl;
                cout << "***** Data de ingresso ****" << endl;
                cout << "Data de Ingresso: " << temp.getIngressoEmpresa().ano << "/"
                        << temp.getIngressoEmpresa().mes << "/" << temp.getIngressoEmpresa().dia << endl;

                cout << "#########################################################" << endl;

                vendedores.push_back(temp);
            }else if(vetor[i+0] == "GERENTE") {
                gerenteContratado = true;
                Data aux;
                aux.ano = stoi(vetor[i+13]);
                aux.mes = stoi(vetor[i+14]);
                aux.dia = stoi(vetor[i+15]);

                Endereco end;
                end.cidade = vetor[i+7];
                end.cep = vetor[i+8];
                end.bairro = vetor[i+9];
                end.rua = vetor[i+10];
                end.numero = stoi(vetor[i+11]);

                Data ingresso;
                ingresso.ano = stoi(vetor[i+22]);
                ingresso.mes = stoi(vetor[i+23]);
                ingresso.dia = stoi(vetor[i+24]);

                Gerente temp(vetor[i+2], vetor[i+3], aux, end, vetor[i+5], stoi(vetor[i+4]), vetor[i+18],
                    vetor[i+17], ingresso, stoi(vetor[i+20]), stof(vetor[i+19]));
                
                cout << "#########################################################" << endl;

                cout << "##### DADOS PESSOAIS #####" << endl;
                cout << "Nome: " << temp.getNome() << endl;
                cout << "CPF: " << temp.getCPF() << endl;
                cout << "Qtd. Filhos: " << temp.getQtdFilhos() << endl;
                cout << "Estado Civil: " << temp.getEstadoCivil() << endl;

                cout << "***** Endereço ****" << endl;
                cout << "Cidade: " << temp.getEnderecoPessoal().cidade << endl;
                cout << "CEP: " << temp.getEnderecoPessoal().cep << endl;
                cout << "Bairro: " << temp.getEnderecoPessoal().bairro << endl;
                cout << "Rua: " << temp.getEnderecoPessoal().rua << endl;
                cout << "Número: " << temp.getEnderecoPessoal().numero << endl;

                cout << "***** Data de nascimento ****" << endl;
                cout << "Data de Nascimento: " << temp.getDataNascimento().ano << "/"
                        << temp.getDataNascimento().mes << "/" << temp.getDataNascimento().dia << endl;

                cout << "##### DADOS FUNCIONAIS #####" << endl;
                cout << "Matrícula: " << temp.getMatricula() << endl;
                cout << "Cargo: Gerente" << endl; 
                cout << "Salário: " << temp.getSalario() << endl;
                cout << "Participação nos Lucros: " << temp.getParticipacaoLucros() << endl;
                cout << "Dias de Faltas: " << temp.getDiasFaltas() << endl;

                cout << "***** Data de ingresso ****" << endl;
                cout << "Data de Ingresso: " << temp.getIngressoEmpresa().ano << "/"
                        << temp.getIngressoEmpresa().mes << "/" << temp.getIngressoEmpresa().dia << endl;

                cout << "#########################################################" << endl;

                gerentes.push_back(temp);
            }
        }

        // Atualiza os arquivos de input
        if(asgContratado) { atualizaAsgs(); }
        if(vendedorContratado){ atualizaGerente(); }
        if(gerenteContratado) { atualizaVendedor(); }

    } catch (const exception& e) {
    cout << "Ocorreu uma exceção: " << e.what() << endl;
    }
}