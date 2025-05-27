#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "lista.h"

int main() {
    Lista *listaA = NULL;
    Lista *listaB = NULL;
    Lista *listaC = NULL;
    int qtd = 25;
    int qtd2 = 25;
    srand(time(NULL));

    for (; qtd > 0; qtd--) {
        listaA = inserir(rand() % 100, listaA); //inserir elementos aleatorios na ListaA
    }
    cout << " " << endl;
    cout << "Lista A: "<< endl;
    exibir(listaA);
    cout << " " << endl;

    for (; qtd2 > 0; qtd2--) {
        listaB = inserir(rand() % 100, listaB); //inserir elementos aleatorios na ListaB
    }
    cout << "Lista B: " << endl;
    exibir(listaB);
    cout << " " << endl;

    cout << "\nElementos em comum entre Lista A e B: " << endl;
    exibirComuns(listaA, listaB);
    cout << " " << endl;

    cout << "\nRemovendo Pares: " << endl;
    cout << "\nLista A: " << endl;
    exibir(listaA); //exibir a ListaA sem alteração
    cout << "\nLista A com pares removidos" << endl;
    listaA = excluirPares(listaA); //remover os pares da ListaA
    exibir(listaA); //exibir a ListaA com alteração
    cout << " " << endl;

    cout << "\nUniao das Listas A e B: " << endl;
    cout << "\nLista C (Uniao das Listas A e B): " << endl;
    listaC = unirListas(listaA, listaB); //inserir elementos das Listas A e B na ListaC
    exibir(listaC);
    cout << " " << endl;

    cout << "\nLista C ordenada: " << endl;
    ordenarBolha(listaC); //ordernar a ListaC
    exibir(listaC);
    cout << " " << endl;

    cout << "\nRemovendo ListaC: " << endl;
    listaC = deletarLista(listaC); //remover elementos da ListaC

    if (listaC == NULL)
    {
        cout << "Removida com Sucesso!" << endl;
        exibir(listaC);
    } else {
        exibir(listaC);
    }
    return 1;
}