#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

struct Call_911
{
	int id;
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

void inserirNovoRegistro(int posicaoInsercao, Call_911 New)
{
    //331740
    //330000

    fstream paste;
	paste.open("paste.bin",fstream::in | fstream::out | fstream::binary);

    paste.seekg(0, paste.end);
    int tam = paste.tellg();
    paste.seekg(0, paste.beg);
    int numero_registros = tam / sizeof(Call_911);

    Call_911 *registros = new Call_911[1];

	for ( int i = numero_registros - 1; i >= posicaoInsercao; i-- )
	{
		paste.seekg(i * sizeof(Call_911), paste.beg);
		paste.read((char*)(&registros[0]), sizeof(Call_911));
		registros[0].id += 1;
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
		paste.seekp((i + 1) * sizeof(Call_911), paste.beg);
		paste.write((const char *) (&registros[0]), sizeof(Call_911));
	}
	New.id = posicaoInsercao;
	paste.seekp(posicaoInsercao * sizeof(Call_911), paste.beg);
	paste.write((const char *) (&New), sizeof(Call_911));

	paste.close();
}


int main()
{

    int posicaoInsercao,i = 0;
	string palavra;
	Call_911 New;

	cin >> posicaoInsercao;

	cin >> New.lat;
	cin >> New.lgn;
	cin.ignore();
	getline(cin,palavra);
	while(i < sizeof(palavra))
	{
		New.desc[i] = palavra[i];
		i++; 
	}
	cin >> New.zip;
	//cin >> New.title;
	//cin >> New.timeStamp;
	//cin >> New.twp;
	//cin >> New.addr;
	cin >> New.e;
	New.flag = true;

	cout << endl;
    inserirNovoRegistro(posicaoInsercao, New);

    return 0;
}
