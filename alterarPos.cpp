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

void alterarPos(int p1, int p2)
{

    fstream paste;
	paste.open("paste.bin", fstream::in | fstream::out | fstream::binary);

    paste.seekg(0, paste.end);
    int tam = paste.tellg();
    paste.seekg(0, paste.beg);
    int numero_registros = tam / sizeof(Call_911);

    Call_911 *registros = new Call_911[1];
    Call_911 *registros0 = new Call_911[1];

    paste.seekg(p1 * sizeof(Call_911), paste.beg);
    paste.read((char*)(&registros[0]), sizeof(Call_911));
    paste.seekg(p2 * sizeof(Call_911), paste.beg);
    paste.read((char*)(&registros0[0]), sizeof(Call_911));

    registros[0].id = p2;
    paste.seekp(p2 * sizeof(Call_911), paste.beg);
    paste.write((const char *) (&registros[0]), sizeof(Call_911));

    registros0[0].id = p1;
    paste.seekp(p1 * sizeof(Call_911), paste.beg);
    paste.write((const char *) (&registros0[0]), sizeof(Call_911));
    

        cout << "TROCANDO" << endl;

        cout << "- - - - - - - - - - - - " << endl;
        cout << p1 << endl;
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

        cout << "COM" << endl;

        cout << "- - - - - - - - - - - - " << endl;
        cout << p2 << endl;
		cout << registros0[0].lat << endl;
		cout << registros0[0].lgn << endl;
		cout << registros0[0].desc << endl;
		cout << registros0[0].zip << endl;
		cout << registros0[0].title << endl;
		cout << registros0[0].timeStamp << endl;
		cout << registros0[0].twp << endl;
		cout << registros0[0].addr << endl;
		cout << registros0[0].e << endl;
		cout << "- - - - - - - - - - - - " << endl;

	paste.close();
}


int main()
{
    int pos1, pos2;

	cin >> pos1;
    cin >> pos2;

	cout << endl;
    alterarPos(pos1, pos2);

    return 0;
}
