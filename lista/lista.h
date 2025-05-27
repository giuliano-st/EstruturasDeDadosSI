typedef struct no {
    int dado;
    struct no *prox;
} Lista;

void exibir(Lista *lista){
    Lista *p;
    for (p = lista; p; p = p->prox) {
        cout << p->dado << " ";
    }
}

void exibirComuns(Lista *listaA, Lista *listaB){ //1
    Lista *p;
    Lista *q;
    for (p = listaA; p; p = p->prox) {
        for (q = listaB; q; q = q->prox)
        {
            if (p->dado == q->dado)
            {
                cout << p->dado << " ";
                break;
            }
        }
    }
}

Lista* excluirPares(Lista* lista) { //2
    Lista *p = NULL;
 
    for (Lista* novo = lista; novo != NULL; ) {
        if (novo->dado % 2 == 0) {
            Lista* temp = novo->prox;
            if (p == NULL) {
                lista = temp;
            } else {
                p->prox = temp;
            }
            free(novo);
            novo = temp;
        } else {
            p = novo;
            novo = novo->prox;
        }
    }
 
    return lista;
}

Lista *inserir(int valor, Lista *lista) {
    //alocar memoria
    Lista *novo;
    novo = (Lista*)malloc(sizeof(Lista));

    //depositar valores
    novo->dado = valor;
    novo->prox = NULL;

    //engatar novo na sua posicao
    Lista *p, *pR;
    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) {
        if (valor == p->dado) {
            free(novo);
            return lista;
        }
        if (valor < p->dado) { //Ordenateur
            //achei a posicao
            break;
        }
    }
    //inserir na primeira posicao
    if (p == lista) {
        novo->prox = p;
        return novo;
    }
    //inserir na ultima posicao
    if (!p) {
        pR->prox = novo;
        return lista;
    }
    //inserir em alguma posicao do meio
    pR->prox = novo;
    novo->prox = p;
    return lista;
}

Lista *inserirDesordenado(int valor, Lista *lista) {
    //alocar memoria
    Lista *novo;
    novo = (Lista*)malloc(sizeof(Lista));

    //depositar valores
    novo->dado = valor;
    novo->prox = NULL;

    //engatar novo na sua posicao
    Lista *p, *pR;
    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) {
        if (valor == p->dado) {
            free(novo);
            return lista;
        }
    }
    //inserir na primeira posicao
    if (p == lista) {
        novo->prox = p;
        return novo;
    }
    //inserir na ultima posicao
    if (!p) {
        pR->prox = novo;
        return lista;
    }
    //inserir em alguma posicao do meio
    pR->prox = novo;
    novo->prox = p;
    return lista;
}

Lista* unirListas(Lista* listaA, Lista* listaB) { //3
    Lista* listaC = NULL;
    Lista* p;
 
    // Copiar todos os elementos da listaA para listaC
    for (p = listaA; p != NULL; p = p->prox) {
        // Usa a funcao inserir (no final)
        listaC = inserirDesordenado(p->dado, listaC);
    }
 
    // Copiar todos os elementos da listaB para listaC
    for (p = listaB; p != NULL; p = p->prox) {
        listaC = inserirDesordenado(p->dado, listaC);
    }
 
    return listaC;
}

Lista *ordenarBolha(Lista *lista) { //4
    bool houveTroca;
    do {
        houveTroca = false;
        for (Lista *p = lista; p != NULL && p->prox != NULL; p = p->prox) {
            if (p->dado > p->prox->dado) {
                int tmp = p->dado;
                p->dado = p->prox->dado;
                p->prox->dado = tmp;
                houveTroca = true;
            }
        }
    } while (houveTroca);
    return lista;
}

Lista* deletarLista(Lista* lista) { //5
    Lista* p = lista;
    while (p != NULL) {
        Lista* temp = p;
        p = p->prox;
        free(temp);
    }
    lista = NULL;
    return NULL;
}