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
	bool flag;
};

void deletar(char *file_name, int p_delete)
{
    fstream paste;
	paste.open("paste.bin",fstream::in | fstream::out | fstream::binary);

    if ( paste )
    {
        paste.seekg(0, paste.end);
        int tam = paste.tellg();
        paste.seekg(0, paste.beg);

        int numero_registros = tam / sizeof(Call_911);

        Call_911 *registros = new Call_911[1];

		paste.seekg(p_delete, paste.beg);

        paste.seekg(p_delete * sizeof(Call_911), paste.beg);
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

            registros[0].flag = false;
        paste.seekp(p_delete * sizeof(Call_911), paste.beg);
        paste.write((const char *)(&registros), sizeof(Call_911));
    }
    else
    {
        cout << "Erro na leitura do arquivo!";
    }
    cout << "sucesso" << endl;
    paste.close();
    return;
}

int main()
{
	char *file_name = "paste.bin";
    int p_delete;
    cout << "INSIRA A POSICAO QUE DESEJA DELETAR: ";
    cin >> p_delete;
    deletar(file_name, p_delete);
    return 0;
}
