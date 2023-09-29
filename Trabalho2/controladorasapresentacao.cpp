#include "controladorasapresentacao.h"

//--------------------------------------------------------------------------------------------
// Implementações de métodos de classes controladoras.

void CntrApresentacaoControle::executar(){

    // Mensagens a serem apresentadas na tela inicial.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Acessar sistema.";
    char texto3[]="2 - Cadastrar participante.";
    char texto4[]="3 - Acessar dados sobre peça.";
    char texto5[]="4 - Encerrar execucao do sistema.";

    // Mensagens a serem apresentadas na tela de seleção de serviço.

    char texto6[]="Selecione um dos servicos : ";
    char texto7[]="1 - Selecionar servicos de participante.";
    char texto8[]="2 - Selecionar servicos relacionados a peças.";
    char texto9[]="3 - Encerrar sessao.";

    char texto10[]="Falha na autenticacao. Digite algo para continuar.";                        // Mensagem a ser apresentada.

    int campo;                                                                                  // Campo de entrada.

    bool apresentar = true;                                                                     // Controle de laço.

    while(apresentar){

        // Apresenta tela inicial.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto1 << endl;                                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                                                 // Imprime nome do campo.
        cout << texto3 << endl;                                                                 // Imprime nome do campo.
        cout << texto4 << endl;                                                                 // Imprime nome do campo.
        cout << texto5 << endl;                                                                 // Imprime nome do campo.

        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.

        switch(campo){
            case 1: if(cntrApresentacaoAutenticacao->autenticar(&matricula)){                         // Solicita autenticação.
                        bool apresentar = true;                                                 // Controle de laço.
                        while(apresentar){

                            // Apresenta tela de seleção de serviço.

                            CLR_SCR;                                                            // Limpa janela.

                            cout << texto6 << endl;                                             // Imprime nome do campo.
                            cout << texto7 << endl;                                             // Imprime nome do campo.
                            cout << texto8 << endl;                                             // Imprime nome do campo.
                            cout << texto9 << endl;                                             // Imprime nome do campo.

                            campo = getch() - 48;                                               // Leitura do campo de entrada e conversão de ASCII.

                            switch(campo){
                                case 1: cntrApresentacaoParticipante->executar(matricula);                 // Solicita serviço de pessoal.
                                        break;
                                case 2:   // Solicita serviço de produto financeiro.
                                        break;
                                case 3: apresentar = false;
                                        break;
                            }
                        }
                    }
                    else {
                        CLR_SCR;                                                                // Limpa janela.
                        cout << texto10 << endl;                                                // Imprime mensagem.
                        getch();                                                                // Leitura de caracter digitado.
                    }
                    break;
            case 2: cntrApresentacaoParticipante->cadastrar();
                    break;
            case 3: cntrApresentacaoPeca->executar();
                    break;
            case 4: apresentar = false;
                    break;
        }
    }
    return;
}

//--------------------------------------------------------------------------------------------

bool CntrApresentacaoAutenticacao::autenticar(Matricula *matricula){

    // Mensagens a serem apresentadas na tela de autenticação.

    char texto1[]="Digite o Matricula  : ";
    char texto2[]="Digite a senha: ";
    char texto3[]="Dado em formato incorreto. Digite algo.";

    // Campos de entrada.

    char campo1[80];
    char campo2[80];

    Senha senha;                                                                                // Instancia a classe Senha.

    while(true){

        // Apresenta tela de autenticação.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto1 << " ";                                                                  // Imprime nome do campo.
        cin >> campo1;                                                                          // Lê valor do campo.
        cout << texto2 << " ";                                                                  // Imprime nome do campo.
        cin >> campo2;                                                                          // Lê valor do campo.

        try{
            matricula->setValor(string(campo1));                                                      // Atribui valor ao CPF.
            senha.setValor(string(campo2));                                                     // Atribui Valor à senha.
            break;                                                                              // Abandona laço em caso de formatos corretos.
        }
        catch(invalid_argument &exp){                                                           // Captura exceção devido a formato incorreto.
            CLR_SCR;                                                                            // Limpa janela.
            cout << texto3 << endl;                                                             // Informa formato incorreto.
            getch();                                                                            // Lê caracter digitado.
        }
    }
    return (cntr->autenticar(*matricula, senha));                                                     // Solicita serviço de autenticação.
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoParticipante::executar(Matricula matricula){

    // Mensagens a serem apresentadas na tela de seleção de serviço..

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Consultar dados pessoais.";
    char texto3[]="2 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    bool apresentar = true;                                                                     // Controle de laço.

    while(apresentar){

        // Apresenta tela de selação de serviço.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto1 << endl;                                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                                                 // Imprime nome do campo.
        cout << texto3 << endl;                                                                 // Imprime nome do campo.

        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.

        switch(campo){
            case 1: cadastrar();
                    break;
            case 2: apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoParticipante::cadastrar(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Matrícula       :";
    char texto3[] ="Nome            :";
    char texto4[] ="Sobrenome       :";
    char texto5[] ="Email           :";
    char texto6[] ="Telefone        :";
    char texto7[] ="Senha           :";
    char texto8[] ="Cargo           :";

    char texto10[]="Dados em formato incorreto. Digite algo.";
    char texto11[]="Sucesso no cadastramento. Digite algo.";
    char texto12[]="Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80];                            // Cria campos para entrada dos dados.
    char campo6[80], campo7[80], campo8[80];                                                    // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Matricula matricula;
    Nome nome;
    Nome sobrenome;
    Email email;
    Telefone telefone;
    Senha senha;
    Cargo cargo;

    // Apresenta tela de cadastramento.

    CLR_SCR;                                                                                   // Limpa janela.

    cout << texto1 << endl;                                                                    // Imprime solicitação ao usuário.
    cout << texto2 << " ";                                                                     // Imprime nome do campo.
    cin.getline(campo1,sizeof(campo1));                                                        // Lê valor do campo composto.

    cout << "Valor lido" << campo1 << " ";

    cout << texto3 << " ";                                                                     // Imprime nome do campo.
    cin >> campo2;                                                                             // Lê valor do campo.
    cout << texto4 << " ";                                                                     // Imprime nome do campo.
    cin >> campo3;                                                                             // Lê valor do campo.
    cout << texto5 << " ";                                                                     // Imprime nome do campo.
    cin >> campo4;                                                                             // Lê valor do campo.
    cout << texto6 << " ";                                                                     // Imprime nome do campo.
    cin >> campo5;                                                                             // Lê valor do campo.
    cout << texto7 << " ";                                                                     // Imprime nome do campo.
    cin >> campo6;                                                                             // Lê valor do campo.
    cout << texto8 << " ";                                                                     // Imprime nome do campo.
    cin >> campo7;                                                                             // Lê valor do campo.
                                                                            // Lê valor do campo.

    try{
        matricula.setValor(string(campo1));
        nome.setValor(string(campo2));
        sobrenome.setValor(string(campo3));
        email.setValor(string(campo4));
        telefone.setValor(string(campo5));
        senha.setValor(string(campo6));
        cargo.setValor(string(campo7));
    }
    catch(invalid_argument &exp){
        cout << texto10 << endl;                                                                // Informa formato incorreto.
        getch();                                                                                // Leitura de caracter digitado.
        return;
    }

    Participante participante;

    participante.setMatricula(matricula);
    participante.setNome(nome);
    participante.setSobrenome(sobrenome);
    participante.setEmail(email);
    participante.setTelefone(telefone);
    participante.setSenha(senha);
    participante.setCargo(cargo);

    if(cntrServicoParticipante->cadastrarParticipante(participante)){
        cout << texto11 << endl;
        getch();
        return;
    }

    return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoParticipante::editar(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir código seguinte pela implementação do método.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas na tela de apresentação de dados pessoais.

    char texto[]="Servico nao implementado. Digite algo.";             // Mensagem a ser apresentada.
    CLR_SCR;                                                                                    // Limpa janela.
    cout << texto << endl;                                                      // Imprime nome do campo.
    getch();

}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoParticipante::excluir(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir código seguinte pela implementação do método.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas na tela de apresentação de dados pessoais.

    char texto[]="Servico nao implementado. Digite algo.";             // Mensagem a ser apresentada.
    CLR_SCR;                                                                                    // Limpa janela.
    cout << texto << endl;                                                      // Imprime nome do campo.
    getch();

}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPeca::executar(Matricula){

    // Mensagens a serem apresentadas tela completa de produtos financeiros.

    char texto1[] ="Selecione um dos servicos : ";
    char texto2[] ="1 - Consultar conta corrente.";
    char texto3[] ="2 - Cadastrar produto de investimento.";
    char texto4[] ="3 - Descadastrar produto de investimento.";
    char texto5[] ="4 - Consultar produto de investimento.";
    char texto6[] ="5 - Realizar aplicacao em produto de investimento.";
    char texto7[] ="6 - Listar aplicacoes em produto de investimento.";
    char texto8[] ="7 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    bool apresentar = true;                                                                     // Controle de laço.

    while(apresentar){

        // Apresenta tela completa de produtos financeiros.

        CLR_SCR;                                                                                // Limpa janela.

        cout << texto1 << endl;                                                                 // Imprime nome do campo.
        cout << texto2 << endl;                                                                 // Imprime nome do campo.
        cout << texto3 << endl;                                                                 // Imprime nome do campo.
        cout << texto4 << endl;                                                                 // Imprime nome do campo.
        cout << texto5 << endl;                                                                 // Imprime nome do campo.
        cout << texto6 << endl;                                                                 // Imprime nome do campo.
        cout << texto7 << endl;                                                                 // Imprime nome do campo.
        cout << texto8 << endl;                                                                 // Imprime nome do campo.

        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.

        switch(campo){
            case 1: consultarPeca();
                    break;
            case 2: cadastrarPeca();
                    break;
            case 3: descadastrarPeca();
                    break;
            case 4: listarPeca();
                    break;
            case 7: apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPeca::consultarPeca(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir código seguinte pela implementação do método.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    char texto[]="Servico consultar conta nao implementado. Digite algo.";                      // Mensagem a ser apresentada.

    CLR_SCR;                                                                                    // Limpa janela.
    cout << texto << endl;                                                                      // Imprime nome do campo.
    getch();
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPeca::cadastrarPeca(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir código seguinte pela implementação do método.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    char texto[]="Servico cadastrar produto investimento nao implementado. Digite algo.";       // Mensagem a ser apresentada.

    CLR_SCR;                                                                                    // Limpa janela.
    cout << texto << endl;                                                                      // Imprime nome do campo.
    getch();

}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPeca::descadastrarPeca(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir código seguinte pela implementação do método.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    char texto[]="Servico descadastrar produto investimento nao implementado. Digite algo.";    // Mensagem a ser apresentada.

    CLR_SCR;                                                                                    // Limpa janela.
    cout << texto << endl;                                                                      // Imprime nome do campo.
    getch();

}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoPeca::listarPeca(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir código seguinte pela implementação do método.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    char texto[]="Servico consultar produto investimento nao implementado. Digite algo.";       // Mensagem a ser apresentada.

    CLR_SCR;                                                                                    // Limpa janela.
    cout << texto << endl;                                                                      // Imprime nome do campo.
    getch();

}


//--------------------------------------------------------------------------------------------
