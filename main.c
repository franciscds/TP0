//TRabalho AEDS 3
// Francis Carlos dos Santos
#include "trie.h"

void encontraFreq(TrieNo* raiz, Dict* dicionario,int nPalavras);
//Pesquisa frequencia das palavras existentes no dicionario e insere em dicionario para imprimir na saida
void imprimeSaida(Dict* dicionario, int nPalavras);
//Imprime todas as frequencias

int main(int argc, char *argv[])
{
    int m=0;
    int nPalavras= 0;
    int contador = 0;
    char temp[17];
    TrieNo* raiz = NULL;


    fscanf(stdin,"%d",&nPalavras);// Le numero de palavras que serao adicionadas no dicionario
    Dict* dicionario =(Dict*)malloc(nPalavras*sizeof(Dict));
    if( dicionario == NULL){ fprintf(stderr,"\nFalha ao alocar memoria"); exit(-1);}

        for( contador = 0; contador < nPalavras; contador++ ){

            fscanf(stdin,"%s",temp);
            strcpy(dicionario[contador].String,temp);// Copia string para estrutura
            }
            raiz = insereDicionario(dicionario,nPalavras);// armazena palavras do dicionario na Trie


        fscanf(stdin,"%d",&m); //Le numero de palavras do texto


        for( contador = 0; contador < m; contador++){ // Le cada palavra do texto e verifica se existe na arvore
                fscanf(stdin,"%s",temp);
                buscaPalavra(raiz,temp);
        }

        encontraFreq(raiz,dicionario,nPalavras);//Funcao que pesquisa frequencia das palavras do dicionario na arvore;

        imprimeSaida(dicionario,nPalavras);

    free(dicionario);
    freeTrie(raiz);
    raiz = NULL;
    dicionario = NULL;
    return 0;
}

void imprimeSaida(Dict* dicionario, int nPalavras){

        int i=0;
            for( i=0; i< nPalavras; i++){

                fprintf(stdout,"%d ",dicionario[i].freq);
            }
}
short int getIndex(char letra){

    //letra - 'a' = 97
    return (int)letra - (int)'a';

}


void encontraFreq(TrieNo* raiz, Dict* dicionario,int nPalavras){

    int cont=0;
    int contador = 0;
    int tamanho = 0;
    int index=0;
    TrieNo* pNo = raiz;

  while( cont < nPalavras ){

        tamanho = strlen(dicionario[cont].String); // tamanho da palavra na posicao cont
        char palavra[tamanho+1];
        strcpy(palavra,dicionario[cont].String);


      for( contador = 0; contador < tamanho; contador++ ){

            index = getIndex(palavra[contador]);

            if( pNo->filho[index] == NULL ){ //Se prefixo nao existir cancela, porque palavra do texto n esta no dicionario
                break;
            }
            else{

                    if( pNo->filho[index]->ePalavra == true ){//Se o prefixo esta no dicionario verifica se e o fim de uma palavra

                        dicionario[cont].freq = pNo->filho[index]->freq;

                        pNo = pNo->filho[index];

                    }
                    else{ pNo = pNo->filho[index]; //aponta para o proximo no
                    }
                }
            }
            pNo = raiz;
            cont++;
        }
}
