#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

// Forward declarations.

class IServicoAutenticacao;
class IServicoParticipante;
class IServicoPeca;

// Declarações das interfaces da camada de apresentação.

class IApresentacaoAutenticacao {
    public:
        virtual bool autenticar(Matricula*) = 0;
        //virtual bool autenticar(Senha*) = 0;
        virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
        virtual ~IApresentacaoAutenticacao(){}
};

class IApresentacaoParticipante {
    public:
        virtual void executar(Matricula) = 0;
        virtual void cadastrar() = 0;
        virtual void editar() = 0;
        virtual void excluir() = 0;
        virtual void setCntrServicoParticipante(IServicoParticipante*) = 0;
        virtual ~IApresentacaoParticipante(){}
};

class IApresentacaoPeca {
    public:
        virtual void executar() = 0;
        virtual void executar(Matricula) = 0;
        virtual void exibir(Peca,Sessao,Sala) = 0;
        virtual void setCntrServicoPeca(IServicoPeca*) = 0;
        virtual ~IApresentacaoPeca(){}
};

//--------------------------------------------------------------------------------------------
// Declarações das interfaces da camada de serviço.

class IServicoAutenticacao {
    public:
        virtual bool autenticar(Matricula, Senha) = 0;
        virtual ~IServicoAutenticacao(){}
};

class IServicoParticipante {
public:
        virtual bool cadastrarParticipante(Participante) = 0;
        virtual ~IServicoParticipante(){}
};

class IServicoPeca {
public:
        virtual bool cadastrarPeca(Peca) = 0;
        virtual bool consultarPeca(Peca*) = 0;
        virtual bool excluirPeca(Peca) = 0;
        virtual bool cadastrarSessao(Sessao) = 0;
        virtual bool consultarSessao(Sessao*) = 0;
        virtual bool excluirSessao(Sessao) = 0;
        virtual bool cadastrarSala(Sala) = 0;
        virtual bool consultarSala(Sala*) = 0;
        virtual bool excluirSala(Sala) = 0;
        virtual ~IServicoPeca(){}
};

#endif // INTERFACES_H_INCLUDED

