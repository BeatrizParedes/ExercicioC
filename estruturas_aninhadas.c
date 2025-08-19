typedef struct
{
    int dia;
    char mes[10];
    int ano;
}Data;

typedef struct
{
    int pecas;
    float preco;
    Data diaVenda; //variavel do tipo struct Data
}Venda;

int main(){
    Venda A={20,115, 0, {8,"Dezembro",2020}};

    std::cout<<"Pecas:\n"<<A.pecas;
    std::cout<<"Preco:\n"<<A.preco;
    std::cout<<"Data:"<<A.diaVenda.dia<<"de"<<
    A.diaVenda.mes<<"de"<<A.diaVenda.ano<<"\n";

    system("pause");
    return 0;
}