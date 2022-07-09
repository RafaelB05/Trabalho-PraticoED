#include "funcoes.cpp"

using namespace std;

int main()
{
    char *file_name = "paste.bin";
    int p1,p2;
    char t;

    cin >> t;
    cin >> p1 >> p2;

    if(t == 'a')
        lerRegistros(file_name);
    
    if(t == 'b')
        lerPos(file_name,p1,p2);

    if(t == 'c')
    {
        alterarPos(p1,p2);
    }
    if(t == 'r')
        deletar(file_name,p1);

    return 0;
}
