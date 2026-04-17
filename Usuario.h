#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>

using namespace std;

class Usuario {
    protected:
        string nome;
        int id;

    public:
        Usuario() {}
        ~Usuario() {}
        Usuario(string n, int i) : nome(n), id(i) {}

        string getNome() { return nome; }
        int getId()      { return id; }

        virtual void exibirTipoUsuario() {
        }
};

#endif //USUARIO_H
