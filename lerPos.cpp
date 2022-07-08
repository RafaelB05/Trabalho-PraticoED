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

void lerPos(char *file_name, int p1, int p2)
{
    ifstream paste;
    paste.open(file_name, ios::binary);

    if ( paste )
    {
        paste.seekg(0, paste.end);
        int tam = paste.tellg();
        paste.seekg(0, paste.beg);

        int numero_registros = tam / sizeof(Call_911);

        Call_911 *registros = new Call_911[1];

		paste.seekg(p1, paste.beg);

		for ( int i = p1; i < p2 + 1; i++ )
		{
			paste.seekg(i * sizeof(Call_911), paste.beg);
			paste.read((char*)(&registros[0]), sizeof(Call_911));         
			
			cout << registros[0].id << endl;
			cout << registros[0].lat << endl;
			cout << registros[0].lgn << endl;
			cout << registros[0].desc << endl;
			cout << registros[0].zip << endl;
			cout << registros[0].title << endl;
			cout << registros[0].timeStamp << endl;
			cout << registros[0].twp << endl;
			cout << registros[0].addr << endl;
			cout << registros[0].e << endl;
			cout << "- - - - - - - - - - - - " << endl;
		}
    }
    else
    {
        cout << "Erro na leitura do arquivo!";
    }

    return;
}

int main()
{
	char *file_name = "paste.bin";
    int p1;
    int p2;
    cout << "INSIRA A POSICAO INICIAL: ";
    cin >> p1;
    cout << "INSIRA A POSICAO FINAL: ";
    cin >> p2;
    lerPos(file_name, p1, p2);
    return 0;
}
