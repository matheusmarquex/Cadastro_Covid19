#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Paciente
{
    char nome[50];
    char cpf[20];
    char telefone[15];
    char rua[40];
    char numerocasa[10];
    char bairro[40];
    char cidade[40];
    char estado[15];
    char cep[20];
    char email[70];
    char comorbidade[50];
    char diag[20];
    int dia, mes, ano, sn, idade;

};
void AddPaciente();

void LstPaciente();

void GravarDados (struct Paciente pac );

void GavarDadosSaude(struct Paciente pac);


int main()
{
    setlocale(LC_ALL, "portuguese");
    int opcao, opcao2;
    char login[20], senha[20], nome[20]; //dados a serem gravados no arquivo txt
    char login_in[20], senha_in[20]; //dados de entrada login e senha

    FILE *dados;
    dados = fopen ("dados.txt","w");
    printf("\n\n       -----------------------------------------------------------\n\n");
    printf("\t\t\t  ********************");
    printf("\n\t\t\t  *       IIII       *\n");
    printf("\t\t\t  *       IIII       *\n");
    printf("\t\t\t  *   IIIIIIIIIIII   *\n");
    printf("\t\t\t  *   IIIIIIIIIIII   *\n");
    printf("\t\t\t  *       IIII       *\n");
    printf("\t\t\t  *       IIII       *\n");
    printf("\t\t\t  ********************\n\n");

    printf("\n\n       -----------------------------------------------------------\n\n");


    printf("              BEM-VINDO AO CADASTRO DE PACIENTES COM COVID-19                  \n");
    printf("\n\n--------------------------------------------------------------------\n\n");
    printf("DIGITE O C�DIGO DE ACESSO: ");
    scanf("%d",&opcao);

    if(opcao==2020)
    {


        do
        {
            system("cls");
            system("color F4");
            printf("\n\n       -----------------------------------------------------------\n\n");
            printf("\t\t\t  ********************");
            printf("\n\t\t\t  *       IIII       *\n");
            printf("\t\t\t  *       IIII       *\n");
            printf("\t\t\t  *   IIIIIIIIIIII   *\n");
            printf("\t\t\t  *   IIIIIIIIIIII   *\n");
            printf("\t\t\t  *       IIII       *\n");
            printf("\t\t\t  *       IIII       *\n");
            printf("\t\t\t  ********************\n\n");
            printf("\n\n       -----------------------------------------------------------\n");
            printf("\n       - � POSS�VEL REALIZAR APENAS UM CADASTRO DE PROFISSIONAL\n");
            printf("\n       - O PROGRAMA ZERA O CADASTRO SEMPRE QUE INICIADO\n");
            printf("\n       -----------------------------------------------------------\n\n");

            printf("\n\t  #--------------------------------------------------#\n");
            printf("\t  |   OP��ES:                                        |\n");
            printf("\t  |   1 - CADASTRAR PROFISSIONAL                     |\n");
            printf("\t  |   2 - �REA DO PROFISSIONAL                       |\n");
            printf("\t  |   0 - SAIR                                       |");
            printf("\n\t  #--------------------------------------------------#\n");
            printf("\n\n\n");
            printf(">>> ESCOLHA UMA OP��O: ");
            scanf("%d",&opcao2);


            switch (opcao2)
            {
            case 1:
                //teste se o arquivo foi criando

                if (dados == NULL)
                {
                    printf("Erro na abertura do arquivo\n\n");
                    return 1;
                }
                else
                {
                    system("cls");
                    printf("CADASTRO PROFISSIONAL\n");
                    printf("LOGIN: ");
                    fflush(stdin);
                    gets(login);

                    printf("\nSENHA: ");
                    fflush(stdin);
                    gets(senha);

                    //usando fprintf para armazenar a string no arquivo
                    fprintf(dados, "%s\n", login);
                    fprintf(dados, "%s\n", senha);
                    //usando fclose para fechar o arquivo

                    fclose(dados);
                    system("cls");

                    printf("\n\n\t\tPROFISSIONAL DA SA�DE CADASTRADO COM SUCESSO!");
                    getch();

                }
                break;

            case 2:
                do
                {
                    system("cls");
                    printf("FA�A LOGIN PARA PROSSEGUIR\n");
                    printf("\n>>> SEU NOME: ");
                    fflush(stdin);
                    gets(nome);
                    printf("\n>>> LOGIN: ");
                    fflush(stdin);
                    gets(login_in);
                    printf("\n>>> SENHA: ");
                    fflush(stdin);
                    gets(senha_in);

                    if(strcmp(login, login_in) == 0 && strcmp(senha, senha_in)== 0)
                    {
                        int op_paci;
                        system("cls");
                        printf("\n\nACESSO AUTORIZADO!\n\n>>> Ol� %s! <<<",nome);
                        getch();
                        system("cls");
                        printf("\n\n===================================================================\n\n");
                        printf("\t\t�REA DO PROFISSIONAL DA SA�DE");
                        printf("\n\n===================================================================\n\n");
                        do
                        {
                            system("cls");
                            printf("\n  #---------------       OP��ES        ------------#\n");
                            printf("  |   1 - CADASTRAR PACIENTE                       |\n");
                            printf("  |   2 - CONSULTAR PACIENTE                       |\n");
                            printf("  |   3 - SAIR                                     |");
                            printf("\n  #------------------------------------------------#\n");
                            printf(">>> ESCOLHA UMA OP��O: ");
                            scanf("%d",&op_paci);

                            switch(op_paci)
                            {
                            case 1:
                                AddPaciente();
                                break;
                            case 2:
                                LstPaciente();
                                break;
                            case 3:
                                exit(1);
                            }
                        }
                        while(op_paci!=3);
                    }
                    else
                    {
                        system("cls");
                        printf("\n\t\t>>>>>>ACESSO NEGADO!<<<<<<");
                        printf("\n\t>>>>>>PRESSIONE QUALQUER TECLA!<<<<<<");
                        getch();
                    }
                }
                while(strcmp(login, login_in) == 0 && strcmp(senha, senha_in)== 0);
                break;
            case 0:
                printf("SAINDO...");
                getch();
                exit(1);
                break;
            default:
                system("cls");
                printf("\n\n OP��O INV�LIDA! PRESSIONE QUALQUER TECLA;\n\n\n");
                getch();
                break;
            }


        }
        while(opcao2!=0);  //fim do while



    }//fim if
    else
    {
        system("cls");
        printf("\n\t\t>>>>>>ACESSO NEGADO!<<<<<<");
        printf("\n\t>>>>>>PRESSIONE QUALQUER TECLA!<<<<<<");
        getch();
        system("exit");
    }//fim else



    return 0;
} //fim main





void AddPaciente()
{

    system("cls");
    struct Paciente pac;
    printf("\n\n       -----------------------------------------------------------\n\n");
    printf("\n\n\t                        CADASTRO PACIENTE                 \n\n");
    printf("\n\n       -----------------------------------------------------------\n\n");

    fflush(stdin);
    printf("\nDigite o NOME do paciente:");
    fflush(stdin);
    gets(pac.nome);

    printf("\nDigite o CPF do paciente [FORMATO: 123.456.789-10]: ");
    fflush(stdin);
    gets(pac.cpf);

    printf("\nDigite o TELEFONE do paciente [FORMATO: (11) 99999-9999 OU (11) 9999-9999]: ");
    fflush(stdin);
    gets(pac.telefone);
    system("cls");

    printf("\t\tENDERE�O");
    printf("\n\n       -----------------------------------------------------------\n\n");
    printf("\nDigite a RUA do paciente: ");
    fflush(stdin);
    gets(pac.rua);
    printf("\nDigite o N�MERO DA CASA do paciente: ");
    fflush(stdin);
    gets(pac.numerocasa);
    printf("\nDigite a BAIRRO do paciente: ");
    fflush(stdin);
    gets(pac.bairro);
    printf("\nDigite a CIDADE do paciente: ");
    fflush(stdin);
    gets(pac.cidade);
    printf("\nDigite a ESTADO do paciente: ");
    fflush(stdin);
    gets(pac.estado);
    printf("\nDigite o CEP do paciente [FORMATO 12.345-678]: ");
    fflush(stdin);
    gets(pac.cep);

    system("cls");

    printf("\nDigite o email do paciente: ");
    fflush(stdin);
    gets(pac.email);
    system("cls");

    printf("DATA DE NASCIMENTO: \n");
    printf("DIA: ");
    scanf("%d",&pac.dia);
    printf("M�S: ");
    scanf("%d",&pac.mes);
    printf("ANO: ");
    scanf("%d",&pac.ano);
    pac.idade = pac.ano - 2020;

    system("cls");

    printf("DATA DO DIAGN�STICO: \n");
    fflush(stdin);
    gets(pac.diag);

    printf("PACIENTE POSSUI ALGUMA COMORBIDADE? [1-SIM / 2-N�O]: ");
    fflush(stdin);
    scanf("%d",&pac.sn);
    printf("\n");
    switch (pac.sn)
    {
    case 1:
        system("cls");
        printf("DIGITE A COMORBIDADE: ");
        fflush(stdin);
        gets(pac.comorbidade);
        system("cls");
        printf("PACIENTE EST� NO GRUPO DE RISCO! ");
        getch();
        system("cls");
        printf("\n\n       -----------------------------------------------------------\n\n");
        printf("\n\n\t                PACIENTE CADASTRADO COM SUCESSO                 \n\n");
        printf("\n\n       -----------------------------------------------------------\n\n");
        getch();
        system("pause");
        GravarDados (pac);
        GravarDadosSaude();
        break;

    case 2:

        if (pac.idade >= 65)
        {
            system("cls");
            printf("PACIENTE EST� NO GRUPO DE RISCO!\n Maior de 65 anos!");
            getch();
            system("cls");
            printf("\n\n       -----------------------------------------------------------\n\n");
            printf("\n\n\t                PACIENTE CADASTRADO COM SUCESSO                 \n\n");
            printf("\n\n       -----------------------------------------------------------\n\n");
            getch();
            GravarDadosSaude();
            GravarDados(pac);
        }
        else
        {
            system("cls");
            printf("\n\n       -----------------------------------------------------------\n\n");
            printf("\n\n\t                PACIENTE CADASTRADO COM SUCESSO                 \n\n");
            printf("\n\n       -----------------------------------------------------------\n\n");
            getch();
            GravarDados(pac);
            GravarDadosSaude();
        }
        break;
    }

}

void GravarDados (struct Paciente pac)
{
    FILE *cad_paciente;

    if ((cad_paciente = fopen("cadastro_paciente.txt","a+")) == NULL)
        printf("Erro ao abrir o arquivo!");

    fwrite (&pac, sizeof(struct Paciente), 1, cad_paciente);
    fclose(cad_paciente);
}
void LstPaciente ()
{
    system("cls");
    struct Paciente paci;

    FILE *cad_paciente;
    if ((cad_paciente = fopen("cadastro_paciente.txt","a+")) == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }
    else
    {
        do
        {
            printf("NOME ======> %s\n", paci.nome);
            printf("CPF ======> %s\n", paci.cpf);
            printf("TELEFONE ======> %s\n", paci.telefone);
            printf("RUA ======> %s\n", paci.rua);
            printf("N�MERO DA CASA ======> %s\n", paci.numerocasa);
            printf("BAIRRO ======> %s\n", paci.bairro);
            printf("CIDADE ======>  %s\n", paci.cidade);
            printf("ESTADO ======>  %s\n", paci.estado);
            printf("CEP ======> %s\n", paci.cep);
            printf("EMAIL ======>  %s\n", paci.email);
            printf("DATA DE NASCIMENTO ======> %d/%d/%d\n", paci.dia, paci.mes, paci.ano);
            printf("POSSUI COMORBIDADE ======>  %s ",paci.comorbidade);
            printf("\n---------------------------------------------\n");
        }
        while (fread(&paci, sizeof(struct Paciente), 1, cad_paciente)== 1);

        fclose (cad_paciente);
        printf("PRESSIONE QUALQUER TECLA");
        getch();

    }

}

void GravarDadosSaude(struct Paciente pac)
{
    FILE* dados_paciente_enviar;
    if ((dados_paciente_enviar = fopen("dados_paciente_enviar.txt","a")) == NULL)
    {
        printf("Erro ao abrir o arquivo!");
    }
    else
    {
        fprintf(dados_paciente_enviar, "CEP: %s\n", pac.cep);
        fprintf(dados_paciente_enviar, "IDADE: %d\n\n", pac.idade);

        fclose(dados_paciente_enviar);
    }


}


