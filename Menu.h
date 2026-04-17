#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include "Emprestimo.h"

using namespace std;

const int MAX_LIVROS = 10;
const int MAX_USUARIOS = 10;
const int MAX_EMPRESTIMOS = 10;

struct SistemaBiblioteca {
    Livro livros[MAX_LIVROS];
    Usuario* usuarios[MAX_USUARIOS];
    Emprestimo emprestimos[MAX_EMPRESTIMOS];

    int qtdLivros = 0;
    int qtdUsuarios = 0;
    int qtdEmprestimos = 0;
};

void exibirMenuPrincipal() {
    cout << "\n========= SISTEMA DE BIBLIOTECA =========\n";
    cout << "1. Cadastrar Livro\n";
    cout << "2. Cadastrar Aluno\n";
    cout << "3. Cadastrar Professor\n";
    cout << "4. Realizar Emprestimo\n";
    cout << "5. Registrar Devolucao\n";
    cout << "6. Listar Livros\n";
    cout << "7. Listar Usuarios\n";
    cout << "8. Listar Emprestimos\n";
    cout << "0. Sair\n";
    cout << "Opcao: ";
}

void cadastrarLivro(SistemaBiblioteca& biblioteca) {
    if (biblioteca.qtdLivros >= MAX_LIVROS) {
        cout << "Limite de livros atingido.\n";
        return;
    }
    string titulo, autor;
    int isbn;
    cout << "\n-- Cadastrar Livro --\n";
    cout << "Titulo: ";
    cin.ignore();
    getline(cin, titulo);
    cout << "Autor: ";
    getline(cin, autor);
    cout << "ISBN: ";
    cin >> isbn;

    biblioteca.livros[biblioteca.qtdLivros++] = Livro(titulo, autor, isbn);
    cout << "Livro cadastrado com sucesso!\n";
}

void cadastrarAluno(SistemaBiblioteca& biblioteca) {
    if (biblioteca.qtdUsuarios >= MAX_USUARIOS) {
        cout << "Limite de usuarios atingido.\n";
        return;
    }
    string nome, curso;
    int id;
    cout << "\n-- Cadastrar Aluno --\n";
    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome);
    cout << "ID: ";
    cin >> id;
    cout << "Curso: ";
    cin.ignore();
    getline(cin, curso);

    biblioteca.usuarios[biblioteca.qtdUsuarios++] = new Aluno(nome, id, curso);
    cout << "Aluno cadastrado com sucesso!\n";
}

void cadastrarProfessor(SistemaBiblioteca& biblioteca) {
    if (biblioteca.qtdUsuarios >= MAX_USUARIOS) {
        cout << "Limite de usuarios atingido.\n";
        return;
    }
    string nome, depto;
    int id;
    cout << "\n-- Cadastrar Professor --\n";
    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome);
    cout << "ID: ";
    cin >> id;
    cout << "Departamento: ";
    cin.ignore();
    getline(cin, depto);

    biblioteca.usuarios[biblioteca.qtdUsuarios++] = new Professor(nome, id, depto);
    cout << "Professor cadastrado com sucesso!\n";
}

void realizarEmprestimo(SistemaBiblioteca& biblioteca) {
    if (biblioteca.qtdEmprestimos >= MAX_EMPRESTIMOS) {
        cout << "Limite de emprestimos atingido.\n";
        return;
    }
    if (biblioteca.qtdLivros == 0 || biblioteca.qtdUsuarios == 0) {
        cout << "Cadastre ao menos um livro e um usuario antes.\n";
        return;
    }

    cout << "\n-- Realizar Emprestimo --\n";

    cout << "Livros disponiveis:\n";
    for (int i = 0; i < biblioteca.qtdLivros; i++) {
        if (biblioteca.livros[i].isDisponivel()) {
            cout << "  [" << i << "] ";
            biblioteca.livros[i].exibirInformacoes();
        }
    }

    cout << "Usuarios cadastrados:\n";
    for (int i = 0; i < biblioteca.qtdUsuarios; i++) {
        cout << "  [" << i << "] ";
        biblioteca.usuarios[i]->exibirTipoUsuario();
        cout << "\n";
    }

    int idxLivro, idxUsuario;
    string data;
    cout << "Indice do livro: ";
    cin >> idxLivro;
    cout << "Indice do usuario: ";
    cin >> idxUsuario;
    cout << "Data do emprestimo (dd/mm/aaaa): ";
    cin >> data;

    if (idxLivro < 0 || idxLivro >= biblioteca.qtdLivros ||
        idxUsuario < 0 || idxUsuario >= biblioteca.qtdUsuarios) {
        cout << "Indices invalidos.\n";
        return;
    }
    if (!biblioteca.livros[idxLivro].isDisponivel()) {
        cout << "Este livro nao esta disponivel.\n";
        return;
    }

    biblioteca.emprestimos[biblioteca.qtdEmprestimos++] =
        Emprestimo(biblioteca.usuarios[idxUsuario], &biblioteca.livros[idxLivro], data);
}

void registrarDevolucao(SistemaBiblioteca& biblioteca) {
    if (biblioteca.qtdEmprestimos == 0) {
        cout << "Nenhum emprestimo registrado.\n";
        return;
    }

    cout << "\n-- Registrar Devolucao --\n";
    cout << "Emprestimos em aberto:\n";
    for (int i = 0; i < biblioteca.qtdEmprestimos; i++) {
        cout << "  [" << i << "] ";
        biblioteca.emprestimos[i].exibirResumoEmprestimo();
    }

    int idx;
    string data;
    cout << "Indice do emprestimo: ";
    cin >> idx;
    cout << "Data de devolucao (dd/mm/aaaa): ";
    cin >> data;

    if (idx < 0 || idx >= biblioteca.qtdEmprestimos) {
        cout << "Indice invalido.\n";
        return;
    }
    biblioteca.emprestimos[idx].registrarDevolucao(data);
}

void listarLivros(SistemaBiblioteca& biblioteca) {
    cout << "\n-- Livros Cadastrados --\n";
    if (biblioteca.qtdLivros == 0) { cout << "Nenhum livro cadastrado.\n"; return; }
    for (int i = 0; i < biblioteca.qtdLivros; i++) {
        cout << "[" << i << "] ";
        biblioteca.livros[i].exibirInformacoes();
    }
}

void listarUsuarios(SistemaBiblioteca& biblioteca) {
    cout << "\n-- Usuarios Cadastrados --\n";
    if (biblioteca.qtdUsuarios == 0) { cout << "Nenhum usuario cadastrado.\n"; return; }
    for (int i = 0; i < biblioteca.qtdUsuarios; i++) {
        cout << "[" << i << "] ";
        biblioteca.usuarios[i]->exibirTipoUsuario();
        cout << "\n";
    }
}

void listarEmprestimos(SistemaBiblioteca& biblioteca) {
    cout << "\n-- Emprestimos Registrados --\n";
    if (biblioteca.qtdEmprestimos == 0) { cout << "Nenhum emprestimo registrado.\n"; return; }
    for (int i = 0; i < biblioteca.qtdEmprestimos; i++) {
        cout << "[" << i << "]";
        biblioteca.emprestimos[i].exibirResumoEmprestimo();
    }
}

void liberarMemoria(SistemaBiblioteca& biblioteca) {
    for (int i = 0; i < biblioteca.qtdUsuarios; i++) {
        delete biblioteca.usuarios[i];
        biblioteca.usuarios[i] = nullptr;
    }
}

void executarMenu(SistemaBiblioteca& biblioteca) {
    int opcao;
    do {
        exibirMenuPrincipal();
        cin >> opcao;
        switch (opcao) {
            case 1: cadastrarLivro(biblioteca);       break;
            case 2: cadastrarAluno(biblioteca);       break;
            case 3: cadastrarProfessor(biblioteca);   break;
            case 4: realizarEmprestimo(biblioteca);   break;
            case 5: registrarDevolucao(biblioteca);   break;
            case 6: listarLivros(biblioteca);         break;
            case 7: listarUsuarios(biblioteca);       break;
            case 8: listarEmprestimos(biblioteca);    break;
            case 0: cout << "Encerrando...\n"; break;
            default: cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);
}

#endif //MENU_H
