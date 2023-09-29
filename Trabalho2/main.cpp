#include <string.h>
#include <stdexcept>
#include <iostream>

#include "dominios.h"
#include "interfaces.h"
#include "controladorasapresentacao.h"
#include "stubs.h"

using namespace std;

int main()
{
    // Instanciar controladoras de apresentação.

    CntrApresentacaoControle *cntrApresentacaoControle;
    CntrApresentacaoAutenticacao *cntrApresentacaoAutenticacao;

    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();

    // Instanciar stubs de serviço.

    IServicoAutenticacao *stubServicoAutenticacao;

    stubServicoAutenticacao = new StubServicoAutenticacao();

    // Interligar controladoras e stubs.

    cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);

    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(stubServicoAutenticacao);

    cntrApresentacaoControle->executar();                                           // Solicitar serviço apresentacao.

    return 0;
}
