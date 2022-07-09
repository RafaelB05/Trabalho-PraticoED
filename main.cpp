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
    bool controle;
    while(controle)
    {
        menu();

        cin >> escolha;
        
        switch (escolha)
        {
        case 1:
            lerRegistros();
            break;
        
        case 2:
            cout << "Insira a posicao de inicio e o final: ";
            cin >> posInicio >> posFim;
            lerPos(posInicio,posFim);
            break;
        case 3:                
            alterarPos(posInicio,posFim);
            break;
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
            break;
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
            break;
        case 6:
            deletar(posInicio);

        case 7:
            controle = false;
            break;

        default:
            cout << "Favor escolher uma opcao valida" << endl;
            break;
        }    
    }
    return 0;
}
