#ifndef LIVRO_H
#define LIVRO_H

#include <iostream>
#include <string>

using namespace std;

class Livro {
    private:
        string titulo;
        string autor;
        int ISBN;
        bool disponivel;

    public:
        Livro() {}
        ~Livro() {}
        Livro(string t, string a, int isbn)
            : titulo(t), autor(a), ISBN(isbn), disponivel(true) {}

        bool isDisponivel() { return disponivel; }
        string getTitulo() { return titulo; }

        void emprestar() {
            if (disponivel) {
                disponivel = false;
                cout << "Livro '" << titulo << "' emprestado com sucesso!" << endl;
            } else {
                cout << "Erro: O livro '" << titulo << "' ja esta emprestado." << endl;
            }
        }

        void devolver() {
            disponivel = true;
            cout << "Livro '" << titulo << "' devolvido com sucesso!" << endl;
        }

        void exibirInformacoes() {
            cout << "Titulo: " << titulo
                 << " | Autor: " << autor
                 << " | ISBN: " << ISBN
                 << " | Status: " << (disponivel ? "Disponivel" : "Emprestado") << endl;
        }
};

#endif //LIVRO_H
