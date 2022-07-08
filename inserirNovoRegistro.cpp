#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

struct Call_911
{
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
};

void inserirNovoRegistro(int posicaoInsercao){
    
    ifstream paste;
    paste.open("paste.bin", std::ios::binary);
    paste.seekg(0, paste.end);
    int tam = paste.tellg();
    paste.seekg(0, paste.beg);
    int numero_registros = tam / sizeof(Call_911);

    Call_911 *registros = new Call_911[1];

    for(int i = numero_registros; i > posicaoInsercao;i--)
    {
        paste.seekg(i * sizeof(Call_911),paste.beg);
        paste.read((char*)(&registros[0]), sizeof(Call_911));
        cout << registros[0].id << endl;
        //paste.seekg(i*sizeof(Call_911),paste.beg);
        //paste.write((const char *)(&registros[0]),sizeof(Call_911)); 
    }
}


int main(){

    int posicaoInsercao;

    cin >> posicaoInsercao;
    inserirNovoRegistro(posicaoInsercao);

    return 0;
}