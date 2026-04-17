#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
using namespace std;

class Aluno : public Usuario {
    private:
        string curso;

    public:
        Aluno() {}
        Aluno(string n, int i, string c) : Usuario(n, i), curso(c) {}

        void exibirTipoUsuario() {
            cout << nome << " (Aluno do curso: " << curso << ")";
        }
};

#endif //ALUNO_H
