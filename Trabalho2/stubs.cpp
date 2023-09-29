#include "stubs.h"

//--------------------------------------------------------------------------------------------
// Valores usados como gatilhos de erros.

const string StubServicoAutenticacao::INVALIDO = "12345";
const string StubServicoParticipante::INVALIDO = "01123";
const string StubServicoPeca::INVALIDO = "12345";

//--------------------------------------------------------------------------------------------
// Implementa��es dos m�todos de classes stub.

bool StubServicoAutenticacao::autenticar(Matricula matricula, Senha senha){
    if(matricula.getValor() == INVALIDO)
        return false;
    return true;
}

bool StubServicoParticipante::cadastrarParticipante(Participante participante){
    if(participante.getMatricula().getValor() == INVALIDO)
        return false;
    return true;
}

bool StubServicoPeca::cadastrarPeca(Peca peca){
    if(peca.getIdentificador().getValor() == INVALIDO)
        return false;
    return true;
}

bool StubServicoPeca::consultarPeca(Peca *peca){
    if(peca->getIdentificador().getValor() == INVALIDO)
        return false;

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Implementar c�digo que atribui valores ao objeto identificado por conta.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    return true;
}

bool StubServicoPeca::excluirPeca(Peca peca){
    if(peca.getIdentificador().getValor() == INVALIDO)
        return false;
    return true;
}

bool StubServicoPeca::cadastrarSessao(Sessao sessao){
    if(sessao.getIdentificador().getValor() == INVALIDO)
        return false;
    return true;
}

bool StubServicoPeca::consultarSessao(Sessao *sessao){
    if(sessao->getIdentificador().getValor() == INVALIDO)
        return false;

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Implementar c�digo que atribui valores ao objeto identificado por conta.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    return true;
}

bool StubServicoPeca::excluirSessao(Sessao sessao){
    if(sessao.getIdentificador().getValor() == INVALIDO)
        return false;
    return true;
}


