#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>

#define MAX 5

// Programa feito e rodado em VScode, sem bug encontrados!
// Rodando em Dev-C ++ apareceu um bug na hora de pesquisar aparecer uma pesquisa inexistente, nao consegui resolver em deve, porem em copilador do VScode, est� 100%.

//  Estruturas
struct fichaCadastro
{
    int codigo, status, ano;
    char nome[20], descricao[40], gerente[20];

    int setor, previsao;
    char objetivo[30];
};

//  Variaveis globais
struct fichaCadastro ficha[MAX];
int i = 0; // Variante que atribui o c�digo.
int j = 0; // Variante de pesquisas.
int cont = 0;
int noResult = 0;

//  Declara��o de fun��es/procedimentos
void mostrarMenu();
void cadastro();
void modificar();
void pesquisar();
void mostrarLista();
void pesquisarCodigo();
void pesquisarStatus();
void pesquisarSetor();

//  Main
int main()
{
    setlocale(LC_ALL, "portuguese");
    SetConsoleTitle("Atividade Mapa ALP II (52/2021) -- Carlos Italo RA: 21148217-5");
    mostrarMenu();

    return 0;
}

//  Implementa��o de fun��es/procedimentos
void mostrarMenu()
{
    int menu;
    char repeticao;

    do
    {
        system("cls");
        fflush(stdin);
        printf("|->  Digite o n�mero da op��o desejada:  <-|\n");
        printf("|------------------------------------------|\n");
        printf("|    1  -  Cadastrar novo projeto.         |\n");
        printf("|    2  -  Modificar projeto existente.    |\n");
        printf("|    3  -  Listar todos os projetos.       |\n");
        printf("|    4  -  Pesquisar projeto.              |\n");
        printf("|    0  -  Sair do programa.               |\n");
        printf("|------------------------------------------|\n\n");
        printf("Op��o: ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
        {
            j = i; // J recebe I para que possa continuar de onde parou os c�digos.
            repeticao = 'S';
            while ((ficha[i].codigo < MAX) && ((repeticao == 'S') || (repeticao == 's')))
            {
                i++;
                j++;
                ficha[i].codigo = i;

                system("cls");
                fflush(stdin);

                printf("|-> Cadastrar um novo Projeto: <-|\n");
                printf("|--------------------------------|\n\n");

                cadastro();

                printf("Deseja cadastrar um novo projeto? (S/n): \n");
                repeticao = getch();
            }
            if (ficha[i].codigo >= MAX)
            {
                printf("\n\tLimite de Projetos Atigindo (%d)!\n\n", ficha[i].codigo);
                getch();
            }
            break;
        }
        case 2:
        {
            system("cls");
            fflush(stdin);

            ficha[i].codigo = i;
            modificar();
            break;
        }
        case 3:
        {
            system("cls");
            fflush(stdin);

            mostrarLista();
            break;
        }
        case 4:
        {
            do
            {
                system("cls");
                fflush(stdin);
                printf("|->              Pesquisar             <-|\n");
                printf("|----------------------------------------|\n");
                printf("|                                        |\n");
                printf("|   Que tipo de Pesquisa deseja fazer:   |\n");
                printf("|                                        |\n");
                printf("|              1 - C�digo.               |\n");
                printf("|              2 - Status.               |\n");
                printf("|              3 - Setor.                |\n");
                printf("|              0 - Voltar.               |\n");
                printf("|----------------------------------------|\n\n");
                printf("\t Op��o: ");
                scanf("%d", &j);

                switch (j)
                {
                case 1:
                {
                    system("cls");
                    fflush(stdin);
                    pesquisarCodigo();
                    break;
                }
                case 2:
                {
                    system("cls");
                    fflush(stdin);
                    pesquisarStatus();
                    break;
                }
                case 3:
                {
                    system("cls");
                    fflush(stdin);
                    pesquisarSetor();
                    break;
                }
                case 0:
                {
                    system("cls");
                    fflush(stdin);
                    mostrarMenu();
                    break;
                }
                default:
                {
                    system("cls");
                    printf("\n\tOp��o digitada INVALIDA!\n\n");
                    system("pause");
                    break;
                }
                }
            } while (j != 0);
        }
        case 0:
        {
            system("cls");
            fflush(stdin);

            printf("\t|---------------------------------------------------------------------|\n");
            printf("\t|                        Faculdade: UniCesumar                        |\n");
            printf("\t|             Curso: An�lise e Desenvolvimento de Sistemas            |\n");
            printf("\t| Atividade: Mapa - Algor�tmos e L�gica de Programa��o II - (52/2021) |\n");
            printf("\t|        Nome do Aluno: Carlos �talo de Sousa    RA: 21148217-5       |\n");
            printf("\t|---------------------------------------------------------------------|\n\n");
            printf("Finalizando...");
            exit(0);
            break;
        }
        default:
        {
            puts("OP��O INEXISTENTE");
            getch();
            break;
        }
        }
    } while (menu != 0);
}
void cadastro()
{
    printf("C�digo do projeto: 2021-%d\n", ficha[j].codigo);
    fflush(stdin);

    printf("Digite o Nome do projeto:\n");
    gets(ficha[j].nome);
    fflush(stdin);

    printf("Digite a Descri��o do Projeto:\n");
    gets(ficha[j].descricao);
    fflush(stdin);

    printf("Digite o Ano do projeto:\n");
    scanf("%d", &ficha[j].ano);
    fflush(stdin);

    printf("Digite o Gerente respons�vel:\n");
    gets(ficha[j].gerente);
    fflush(stdin);

    printf("Digite o Setor respons�vel:\n");
    scanf("%d", &ficha[j].setor);
    fflush(stdin);

    printf("Digite o Ano de Previs�o de termino:\n");
    scanf("%d", &ficha[j].previsao);
    fflush(stdin);

    printf("Digite o Objetivo final:\n");
    gets(ficha[j].objetivo);
    fflush(stdin);

    do
    {
        printf("Digite em que estado o projeto se encontra: \nOp��es:\n\t 1 - A fazer\n\t 2 - Fazendo\n\t 3 - Conclu�do\nOp��o:");
        scanf("%d", &ficha[j].status);
        fflush(stdin);

        if ((ficha[j].status < 1) || (ficha[j].status > 3))
        {
            system("cls");
            printf("Op��o digitada INVALIDA!\n");
        }
    } while ((ficha[j].status < 1) || (ficha[j].status > 3));
    printf("\n\n Produto cadastrado !!!\n\n");
}
void modificar()
{
    do
    {
        system("cls");
        fflush(stdin);
        printf("|-> Modificar um projeto j� existente: <-|\n");
        printf("|----------------------------------------|\n\n");

        printf("Digite o codigo de qual projeto deseja editar: ");
        scanf("%d", &j);
        if ((j <= 0) || (j > MAX) || (ficha[j].codigo == 0))
        {
            printf("Op��o digitada INVALIDA ou n�o cadastrada!\n");
            getch();
        }
    } while ((j < 0) || (j > MAX));
    if (ficha[j].codigo != 0)
    {
        system("cls");
        fflush(stdin);

        printf("|-> Modificar projeto existente: <-|\n");
        printf("|----------------------------------|\n\n");

        cadastro();
    }
}
void pesquisar()
{
    printf("|--------------------------------------------------------|\n\n");
    printf("C�digo: 2021-%d \n", ficha[cont].codigo);
    printf("Setor: %d \t\tNome: %s\n", ficha[cont].setor, ficha[cont].nome);
    printf("Objetivo final: %s\n", ficha[cont].objetivo);
    printf("Ano: %d \t\tAno de termino: %d\n", ficha[cont].ano, ficha[cont].previsao);
    printf("Gerente respons�vel: %s \n", ficha[cont].gerente);
    if (ficha[cont].status == 1)
    {
        printf("Status: A fazer.\n");
    }
    if (ficha[cont].status == 2)
    {
        printf("Status: Fazendo.\n");
    }
    if (ficha[cont].status == 3)
    {
        printf("Status: Conclu�do.\n");
    }
    printf("Descri��o: %s \n\n", ficha[cont].descricao);
}
void mostrarLista()
{
    printf("|-> Lista de todos os projetos registrados no sistema: <-|\n");
    printf("|--------------------------------------------------------|\n\n");

    for (cont = 1; cont <= MAX; cont++)
    {
        if (ficha[cont].codigo != 0)
        {
            pesquisar();
        }
    }
    system("pause");
}
void pesquisarCodigo()
{
    noResult = 0;

    printf("|-> Pesquisar projeto por c�digo: <-|\n");
    printf("|-----------------------------------|\n\n");

    printf("Digite o numero do c�digo do projeto: \n2021-");
    scanf("%d", &cont);

    if (ficha[cont].codigo == cont)
    {
        pesquisar();
        printf("|--------------------------------------------------------|\n\n");
        noResult = 1;
    }
    if (noResult == 0)
    {
        printf("\n\tNENHUM RESULTADO ENCONTRADO!\n\n");
    }
    system("pause");
}
void pesquisarStatus()
{
    noResult = 0;

    printf("|-> Pesquisar projeto por Status: <-|\n");
    printf("|-----------------------------------|\n\n");

    printf("Digite o numero do Status do projeto: \n");
    printf("\t 1 - A fazer.\n\t 2 - Fazendo.\n\t 3 - Conclu�do.\n\nOp��o: ");
    scanf("%d", &j);

    fflush(stdin);
    for (cont = 1; cont <= MAX; cont++)
    {
        if (ficha[cont].status == j)
        {
            pesquisar();
            noResult = 1;
        }
    }
    if (noResult == 0)
    {
        printf("\n\tNENHUM RESULTADO ENCONTRADO!\n\n");
    }
    system("pause");
}
void pesquisarSetor()
{
    noResult = 0;

    printf("|-> Pesquisar projeto por Setor: <-|\n");
    printf("|----------------------------------|\n\n");

    printf("Digite o numero do Setor do projeto: ");
    scanf("%d", &j);

    fflush(stdin);
    for (cont = 1; cont <= MAX; cont++)
    {
        if (ficha[cont].setor == j)
        {
            pesquisar();
            noResult = 1;
        }
    }
    if (noResult == 0)
    {
        printf("\n\tNENHUM RESULTADO ENCONTRADO!\n\n");
    }
    system("pause");
}
