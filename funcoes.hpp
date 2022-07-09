#ifndef FUNCOES_HPP

#define FUNCOES_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

struct Call_911
{
    public:
        unsigned int id;
        float lat;
        float lgn;
        char desc[120];
        float zip;
        char title[75];
        char timeStamp[75];
        char twp[40];
        char addr[75];
        int e;
        bool flag;
       
};

void lerRegistros(char *file_name);
void lerPos(char *file_name, int p1, int p2);
void alterarDados(char *file_name, int pos0,Call_911 New);
void alterarPos(int p1, int p2);
void inserirNovoRegistro(int posicaoInsercao, Call_911 New);
void deletar(int p_delete);



#endif
