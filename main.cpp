#include "funcoes.cpp"

using namespace std;

int main()
{
    int posInicio,posFim;
    int escolha;
    int posicaoInsercao;
    string palavra;
    Call_911 Novo;
    int posCharVet = 0;
    int pos0;

	cin >> escolha;
	
    switch (escolha)
    {
    case 1:
        lerRegistros();
        break;
    
    case 2:
        cin >> posInicio >> posFim;
        lerPos(posInicio,posFim);
    
    case 3:
        alterarPos(posInicio,posFim);

    case 4:
        cin >> posicaoInsercao;
        cin >> Novo.lat;
        cin >> Novo.lgn;
        cin.ignore();
        getline(cin,palavra);
        while(posCharVet <= int(sizeof(Novo.desc)))
        {
            Novo.desc[posCharVet] = palavra[posCharVet];
            posCharVet++; 
        }
        cin >> Novo.zip;
        cin.ignore();
        getline(cin,palavra);
        posCharVet = 0;
        while(posCharVet <= int(sizeof(Novo.title)))
        {
            Novo.title[posCharVet] = palavra[posCharVet];
            posCharVet++; 
        }
        getline(cin,palavra);
        posCharVet = 0;
        while(posCharVet <= int(sizeof(Novo.timeStamp)))
        {
            Novo.timeStamp[posCharVet] = palavra[posCharVet];
            posCharVet++; 
        }
        getline(cin,palavra);
        posCharVet = 0;
        while(posCharVet <= int(sizeof(Novo.twp)))
        {
            Novo.twp[posCharVet] = palavra[posCharVet];
            posCharVet++; 
        }
        getline(cin,palavra);
        posCharVet = 0;
        while(posCharVet <= int(sizeof(Novo.addr)))
        {
            Novo.addr[posCharVet] = palavra[posCharVet];
            posCharVet++; 
        }
        cin >> Novo.e;
        Novo.flag = true;

        inserirNovoRegistro(posicaoInsercao, Novo);
    case 5:
        cin >> pos0;

        cin >> Novo.lat;
        cin >> Novo.lgn;
        cin.ignore();
        getline(cin,palavra);
        while(posCharVet <= int(sizeof(Novo.desc)))
        {
            Novo.desc[posCharVet] = palavra[posCharVet];
            posCharVet++; 
        }
        cin >> Novo.zip;
        cin.ignore();
        getline(cin,palavra);
        posCharVet = 0;
        while(posCharVet <= int(sizeof(Novo.title)))
        {
            Novo.title[posCharVet] = palavra[posCharVet];
            posCharVet++; 
        }
        getline(cin,palavra);
        posCharVet = 0;
        while(posCharVet <= int(sizeof(Novo.timeStamp)))
        {
            Novo.timeStamp[posCharVet] = palavra[posCharVet];
            posCharVet++; 
        }
        getline(cin,palavra);
        posCharVet = 0;
        while(posCharVet <= int(sizeof(Novo.twp)))
        {
            Novo.twp[posCharVet] = palavra[posCharVet];
            posCharVet++; 
        }
        getline(cin,palavra);
        posCharVet = 0;
        while(posCharVet <= int(sizeof(Novo.addr)))
        {
            Novo.addr[posCharVet] = palavra[posCharVet];
            posCharVet++; 
        }
        cin >> Novo.e;
        Novo.flag = true;

        alterarDados(pos0, Novo);
    case 6:
        deletar(posInicio);

    default:
        break;
    }    

    return 0;
}
