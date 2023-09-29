#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <string>
#include "dominios.h"
#include "interfaces.h"

using namespace std;

//--------------------------------------------------------------------------------------------
// Declarações de classes stub.

class StubServicoAutenticacao:public IServicoAutenticacao {
    private:
        static const string INVALIDO;
    public:
        bool autenticar(Matricula, Senha);
};

//--------------------------------------------------------------------------------------------

class StubServicoParticipante:public IServicoParticipante {
    private:
        static const string INVALIDO;
    public:
        bool cadastrarParticipante(Participante);
};

//--------------------------------------------------------------------------------------------

class StubServicoPeca:public IServicoPeca {
    private:
        static const string INVALIDO;
    public:
        bool cadastrarPeca(Peca);
        bool consultarPeca(Peca*);
        bool excluirPeca(Peca);
        bool cadastrarSessao(Sessao);
        bool consultarSessao(Sessao*);
        bool excluirSessao(Sessao);
        //bool cadastrarSala(Sala);
        //bool consultarSala(Sala*);
        //bool excluirSala(Sala);
};

#endif // STUBS_H_INCLUDED
