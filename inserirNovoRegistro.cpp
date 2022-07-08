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
    ofstream paste;
    



}


int main(){

    int posicaoInsercao;

    cin >> posicaoInsercao;

    inserirNovoRegistro(posicaoInsercao);

    return 0;
}