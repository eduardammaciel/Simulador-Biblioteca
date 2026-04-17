#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Usuario.h"

using namespace std;

class Professor : public Usuario {
    private:
        string departamento;

    public:
        Professor() {}
        ~Professor() {}
        Professor(string n, int i, string d) : Usuario(n, i), departamento(d) {}

        void exibirTipoUsuario() {
            cout << nome << " (Professor do departamento: " << departamento << ")";
        }
};

#endif //PROFESSOR_H
