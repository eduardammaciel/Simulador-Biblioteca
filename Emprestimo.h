#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include <iostream>
#include <string>
#include "Aluno.h"
#include "Professor.h"
#include "Livro.h"

using namespace std;

class Emprestimo {
    private:
        Usuario* usuario;
        Livro*   livro;
        string   dataEmprestimo;
        string   dataDevolucao;

    public:
        Emprestimo() {}
        ~Emprestimo() {}
        Emprestimo(Usuario* u, Livro* l, string data)
            : usuario(u), livro(l), dataEmprestimo(data), dataDevolucao("Pendente") {
            l->emprestar();
        }

        void registrarDevolucao(string data) {
            dataDevolucao = data;
            livro->devolver();
        }

        void exibirResumoEmprestimo() {
            cout << "\n--- Resumo do Emprestimo ---" << endl;
            cout << "Livro: "               << livro->getTitulo() << endl;
            cout << "Usuario: ";
            usuario->exibirTipoUsuario();
            cout << "\nData do Emprestimo: " << dataEmprestimo << endl;
            cout << "Data de Devolucao:  "  << dataDevolucao   << endl;
            cout << "----------------------------\n";
        }
};

#endif //EMPRESTIMO_H
