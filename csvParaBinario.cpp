#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
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

int main()
{

    string a;
	char delimitador = ',';
	int cont = 0;
	Call_911 paste;

    ifstream csv("call911_2.csv");
	ofstream arq;
	arq.open("paste.bin", std::ios::binary);
    
	getline(csv,a); // Pega e remove a primeira linha do csv

	while(getline(csv,a,delimitador))
	{
		if (cont < 10)	
			cont++;
		
		switch (cont)
		{
		case 1:
			paste.id = stoi(a);
			break;
		case 2:
			paste.lat = stof(a);
			break;
		case 3:
			paste.lgn = stof(a);
			break;
		case 4:
			strcpy(paste.desc, a.c_str());
			break;
		case 5:
			paste.zip = stof(a);
			break;
		case 6:
			strcpy(paste.title, a.c_str());
			break;
		case 7:
			strcpy(paste.timeStamp, a.c_str());
			break;
		case 8:
			strcpy(paste.twp, a.c_str());
			break;
		case 9:
			strcpy(paste.addr, a.c_str());
			delimitador = '\n';
			break;
		case 10:
			paste.e = stoi(a);
			paste.flag = true;
			arq.write((const char *) (&paste), sizeof(Call_911));
			delimitador = ',';
			cont = 0;
			break;
		default:
			break;
		}
	}

    csv.close();
	arq.close();
	
	/*ifstream arq2("paste_copy.bin");
	
	if(arq2)
	{
		arq2.seekg(0, arq2.end);
		int tamArq = arq2.tellg();
		arq2.seekg(0, arq2.beg);
		int tam = tamArq/sizeof(Call_911);
		//cout << tamArq << endl;
		//cout << tam << endl;
		Call_911 paste[tam];
		arq2.read((char *) (&paste), tamArq);
		for(int i=0; i<tam; i++)
		{
			cout << paste[i].id << endl;
			cout << paste[i].lat << endl;
			cout << paste[i].lgn << endl;
			cout << paste[i].desc << endl;
			cout << paste[i].zip << endl;
			cout << paste[i].title << endl;
			cout << paste[i].timeStamp << endl;
			cout << paste[i].twp << endl;
			cout << paste[i].addr << endl;
			cout << paste[i].e << endl;
			cout << "- - - - - - - - - - - - " << endl;
		}
		arq2.close();
	}
    //system("pause");*/

	cout << "Sucesso";
    return 0;
}
