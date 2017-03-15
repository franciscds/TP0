#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define TAM_ALFABETO 27

typedef struct trie{

    bool ePalavra;
    int freq;
    struct trie *filho[TAM_ALFABETO];

}TrieNo;

typedef struct {

    char String[17];
    short int freq;

}Dict; //Estrutura para armazenar o dicionario

short int getIndex(char letra);
//Retorna numero para representar a letra
void inserePalavra( TrieNo *raiz, char *palavra);
//Recebe a raiz da Trie e uma palavra, insere letra por letra
TrieNo* insereDicionario(Dict* Dicionario,int nPalavras);
// Recebe todas as strings do dicionario e passa uma a uma para a funcao inserePalavra
void buscaPalavra( TrieNo* raiz,char* palavra);
//Pesquisa palavras do texto na arvore e incrementa frequencia em caso positivo
void freeTrie(TrieNo *raiz);
//libera todos os nos da arvore

#endif // TRIE_H_INCLUDED
