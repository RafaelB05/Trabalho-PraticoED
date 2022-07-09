#include "funcoes.cpp"

using namespace std;

int main()
{
    char *file_name = "paste.bin";
    int p1,p2;
    char t;
    int posicaoInsercao;
    string palavra;
    Call_911 Novo;
    int i = 0;
    int pos0;

    cin >> t;
    if(t == 'a')
        lerRegistros();
    
    if(t == 'b')
    {
        cin >> p1 >> p2;
        lerPos(p1,p2);
    }

    if(t == 'c')
    {
        alterarPos(p1,p2);
    }
    if (t == 'd')
    {
        cin >> posicaoInsercao;
        cin >> Novo.lat;
        cin >> Novo.lgn;
        cin.ignore();
        getline(cin,palavra);
        while(i <= sizeof(Novo.desc))
        {
            Novo.desc[i] = palavra[i];
            i++; 
        }
        cin >> Novo.zip;
        cin.ignore();
        getline(cin,palavra);
        i = 0;
        while(i <= sizeof(Novo.title))
        {
            Novo.title[i] = palavra[i];
            i++; 
        }
        getline(cin,palavra);
        i = 0;
        while(i <= sizeof(Novo.timeStamp))
        {
            Novo.timeStamp[i] = palavra[i];
            i++; 
        }
        getline(cin,palavra);
        i = 0;
        while(i <= sizeof(Novo.twp))
        {
            Novo.twp[i] = palavra[i];
            i++; 
        }
        getline(cin,palavra);
        i = 0;
        while(i <= sizeof(Novo.addr))
        {
            Novo.addr[i] = palavra[i];
            i++; 
        }
        cin >> Novo.e;
        Novo.flag = true;

        inserirNovoRegistro(posicaoInsercao, Novo);

    }

    if (t == 'e')
    {

        cin >> pos0;

        cin >> Novo.lat;
        cin >> Novo.lgn;
        cin.ignore();
        getline(cin,palavra);
        while(i <= sizeof(Novo.desc))
        {
            Novo.desc[i] = palavra[i];
            i++; 
        }
        cin >> Novo.zip;
        cin.ignore();
        getline(cin,palavra);
        i = 0;
        while(i <= sizeof(Novo.title))
        {
            Novo.title[i] = palavra[i];
            i++; 
        }
        getline(cin,palavra);
        i = 0;
        while(i <= sizeof(Novo.timeStamp))
        {
            Novo.timeStamp[i] = palavra[i];
            i++; 
        }
        getline(cin,palavra);
        i = 0;
        while(i <= sizeof(Novo.twp))
        {
            Novo.twp[i] = palavra[i];
            i++; 
        }
        getline(cin,palavra);
        i = 0;
        while(i <= sizeof(Novo.addr))
        {
            Novo.addr[i] = palavra[i];
            i++; 
        }
        cin >> Novo.e;
        Novo.flag = true;

        alterarDados(file_name, pos0, Novo);
    }
    
    
    if(t == 'r')
        deletar(p1);

    return 0;
}
