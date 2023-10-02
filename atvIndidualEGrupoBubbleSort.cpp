/*Pseudo código do algoritmo bubble sort 
//vetor possui os elementos a ordenar 
n = vetor.end()-1 
fazer { 
 trocou = falso 
 para (j = vetor.begin(); j < n; j++) { 
 se vetor(j) > vetor(j + 1) { 
 inverte as posições de vetor(j+1) e 
vetor(j) 
 trocou = verdadeiro; 
 } 
 } 
 n-- 
} enquanto (trocou*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Aluno {
    string nome;
    float nota1;
    float nota2;
};

// Função para calcular a média de um aluno
float calcularMedia(const Aluno& aluno) {
    return (aluno.nota1 + aluno.nota2) / 2.0;
}

// Função para verificar se um aluno está aprovado
bool estaAprovado(const Aluno& aluno) {
    return calcularMedia(aluno) >= 7.0;
}

// Função para ordenar os alunos pelo nome usando o Bubble Sort
void ordenarAlunos(vector<Aluno>& alunos) {
    bool trocou;

    do {
        trocou = false;
        for (auto it = alunos.begin(); it != alunos.end() - 1; ++it) {
            if (it->nome > (it + 1)->nome) {
                swap(*it, *(it + 1));
                trocou = true;
            }
        }
    } while (trocou);
}

int main() {
    int N;
    cout << "Informe o limite de alunos (N): ";
    cin >> N;

    vector<Aluno> alunos;

    char opcao;
    do {
        cout << "Deseja incluir mais alunos (s/n)? ";
        cin >> opcao;

        if (opcao == 's') {
            if (alunos.size() < N) {
                Aluno novoAluno;
                cout << "Nome do aluno: ";
                cin.ignore();
                getline(cin, novoAluno.nome);
                cout << "Nota 1: ";
                cin >> novoAluno.nota1;
                cout << "Nota 2: ";
                cin >> novoAluno.nota2;
                alunos.push_back(novoAluno);
                ordenarAlunos(alunos); // Ordenar os alunos após a inclusão
            } else {
                cout << "Limite de alunos atingido." << endl;
            }
        }

    } while (opcao == 's');

    do {
        cout << "Deseja excluir algum aluno (s/n)? ";
        cin >> opcao;

        if (opcao == 's') {
            string nomeExclusao;
            cout << "Nome do aluno a ser excluído: ";
            cin.ignore();
            getline(cin, nomeExclusao);
            
            auto it = find_if(alunos.begin(), alunos.end(), [&nomeExclusao](const Aluno& aluno) {
                return aluno.nome == nomeExclusao;
            });

            if (it != alunos.end()) {
                alunos.erase(it);
            } else {
                cout << "Aluno não encontrado." << endl;
            }
        }

    } while (opcao == 's');

    cout << "Lista de alunos:" << endl;
    for (const Aluno& aluno : alunos) {
        cout << "Nome: " << aluno.nome << ", Nota 1: " << aluno.nota1 << ", Nota 2: " << aluno.nota2
             << ", Média: " << calcularMedia(aluno) << ", Situação: " << (estaAprovado(aluno) ? "Aprovado" : "Reprovado") << endl;
    }

    char alterarNota;
    do {
        cout << "Deseja alterar alguma nota (s/n)? ";
        cin >> alterarNota;

        if (alterarNota == 's') {
            string nomeAluno;
            cout << "Nome do aluno: ";
            cin.ignore();
            getline(cin, nomeAluno);

            auto it = find_if(alunos.begin(), alunos.end(), [&nomeAluno](const Aluno& aluno) {
                return aluno.nome == nomeAluno;
            });

            if (it != alunos.end()) {
                cout << "Notas atuais de " << nomeAluno << ": Nota 1: " << it->nota1 << ", Nota 2: " << it->nota2 << endl;
                int opcaoNota;
                do {
                    cout << "Alterar a primeira nota (1), a segunda nota (2) ou nenhuma (0)? ";
                    cin >> opcaoNota;

                    if (opcaoNota == 1) {
                        cout << "Nova Nota 1: ";
                        cin >> it->nota1;
                    } else if (opcaoNota == 2) {
                        cout << "Nova Nota 2: ";
                        cin >> it->nota2;
                    }

                } while (opcaoNota != 0);
            } else {
                cout << "Aluno não encontrado." << endl;
            }
        }

    } while (alterarNota == 's');

    return 0;
}
