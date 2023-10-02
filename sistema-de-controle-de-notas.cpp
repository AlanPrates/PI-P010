#include <iostream>
#include <vector>
#include <string>

void bubbleSort(std::vector<std::string>& nomes) {
    int n = nomes.size();
    bool trocou;

    do {
        trocou = false;
        for (int j = 0; j < n - 1; j++) {
            if (nomes[j] > nomes[j + 1]) {
                std::swap(nomes[j], nomes[j + 1]);
                trocou = true;
            }
        }
        n--;
    } while (trocou);
}

void incluirAluno(std::vector<std::string>& nomes, std::vector<float>& notas) {
    std::string nome;
    float nota1, nota2;

    std::cout << "Digite o nome do novo aluno: ";
    std::cin >> nome;

    std::cout << "Digite a primeira nota: ";
    std::cin >> nota1;

    std::cout << "Digite a segunda nota: ";
    std::cin >> nota2;

    nomes.push_back(nome);
    notas.push_back((nota1 + nota2) / 2);
}

void excluirAluno(std::vector<std::string>& nomes, std::vector<float>& notas) {
    std::string nome;
    std::cout << "Digite o nome do aluno a ser excluído: ";
    std::cin >> nome;

    int index = -1;

    for (size_t i = 0; i < nomes.size(); i++) {
        if (nomes[i] == nome) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        nomes.erase(nomes.begin() + index);
        notas.erase(notas.begin() + index);
        std::cout << "Aluno excluído com sucesso!" << std::endl;
    } else {
        std::cout << "Aluno não encontrado." << std::endl;
    }
}

void alterarNota(std::vector<std::string>& nomes, std::vector<float>& notas) {
    std::string nome;
    std::cout << "Digite o nome do aluno cuja nota vai ser alterada: ";
    std::cin >> nome;

    int index = -1;

    for (size_t i = 0; i < nomes.size(); i++) {
        if (nomes[i] == nome) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        std::cout << "Notas atuais de " << nomes[index] << ": " << notas[index] << std::endl;
        std::cout << "Digite a nova nota: ";
        float novaNota;
        std::cin >> novaNota;
        notas[index] = novaNota;
        std::cout << "Nota alterada com sucesso!" << std::endl;
    } else {
        std::cout << "Aluno não encontrado." << std::endl;
    }
}

void listarResultados(const std::vector<std::string>& nomes, const std::vector<float>& notas) {
    for (unsigned int i = 0; i < nomes.size(); i++) {
        std::cout << "Aluno: " << nomes[i] << ", Nota: " << notas[i] << ", Situacao: ";
        if (notas[i] >= 7) {
            std::cout << "Aprovado" << std::endl;
        } else {
            std::cout << "Reprovado" << std::endl;
        }
    }
}

int main() {
    std::vector<std::string> nomes;
    std::vector<float> notas;

    char opcao;
    do {
        std::cout << "\nEscolha uma opção:\n"
                     "1. Incluir novo aluno\n"
                     "2. Excluir aluno\n"
                     "3. Alterar nota\n"
                     "4. Listar resultados\n"
                     "0. Sair\n"
                     "Opção: ";
        std::cin >> opcao;

        switch(opcao) {
            case '1':
                incluirAluno(nomes, notas);
                break;
            case '2':
                excluirAluno(nomes, notas);
                break;
            case '3':
                alterarNota(nomes, notas);
                break;
            case '4':
                listarResultados(nomes, notas);
                break;
            case '0':
                break;
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
    } while (opcao != '0');

    return 0;
}
