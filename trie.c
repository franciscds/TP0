#include "trie.h"

TrieNo* criaNo(){

    TrieNo *pNo = NULL;
    int cont=0;

    pNo = (TrieNo*)malloc(sizeof(TrieNo));
    if(pNo == NULL){ fprintf(stderr,"Falha ao alocar Memoria");
    }
        else{
                pNo->ePalavra = false;
                pNo->freq = 0;
                for(cont = 0; cont < TAM_ALFABETO; cont++ ){//Faz todos os indices apontarem para NULL
                    pNo->filho[cont] = NULL;
                }
    }

    return pNo;
}
TrieNo* insereDicionario(Dict* Dicionario,int nPalavras){

    int contador = 0;

    TrieNo* raiz = criaNo();

    while( contador < nPalavras ){//passa palavra por palavra para inserir na Trie

          inserePalavra(raiz,Dicionario[contador].String);
            contador++;

    }
    return raiz;

}

void inserePalavra( TrieNo *raiz, char *palavra){

    int cont = 0;
    short int index=0;

    TrieNo *pNo = raiz;

    int tam = strlen(palavra);

    for( cont = 0; cont < tam; cont++){//Itera ate inserir palavra inteira

        index = getIndex(palavra[cont]);

        if( pNo->filho[index] == NULL){// caso prefico nao exista, criar novo filho

            pNo->filho[index] = criaNo();
            pNo = pNo->filho[index];
            pNo->freq = 0;

        if( cont == (tam - 1)){
                pNo->ePalavra = true;// se novo filho e a ultima letra da palavra, marcar como folha
        }

    }
            else
            {
                if( cont == (tam-1)){// caso o sufixo ja exista( caso Carro�a -> carro, marcar como folha da palavra carro e fazer apontar pro proximo
                pNo->filho[index]->ePalavra = true;
                }
                pNo = pNo->filho[index];
            }
    }
}


void buscaPalavra( TrieNo* raiz,char* palavra){

    int tamanho = strlen(palavra);
    int contador = 0;
    short int index=0;
    TrieNo* pNo = raiz;

    for( contador = 0; contador < tamanho; contador++ ){//itera todas as letras da palavra

        index = getIndex(palavra[contador]);

        if( pNo->filho[index] == NULL ){
            break;
        }
        else{

            if( pNo->filho[index]->ePalavra == true && contador == (tamanho-1) ){  // Caso a letra seja um sufixo incrementa frequencia e faz apontar pro proximo
                pNo->filho[index]->freq +=1;
                pNo = pNo->filho[index];

            }
            else{ pNo = pNo->filho[index];//Caso nao seja um sufixo, aponta para o proximo
            }

        }
    }

}

void freeTrie(TrieNo *raiz){
    int i=0;
    if(raiz == NULL) return; //Caso a Trie esteja vazia retorna vazio

    for( i = 0; i < TAM_ALFABETO; i++ ){

        freeTrie(raiz->filho[i]);//caminha em cada filho[i] diferente de null
    }
    free(raiz);

}
