#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>
#include <process.h> //para usar o _beginthread()
#include <string.h>
#include<time.h>//pra usar data
#include <ctype.h>

//STRUCTS
typedef struct{
    char usuario[10];
    char senha[10];
    char nome[50];
    int ativo;
    int numero_de_compras;
    int assinatura;//1 =GOLD ; 2= PLATINUM; 0= SEM VIP
    int dia;
	int mes;
	int ano;


}TUsuario;
typedef struct{
    char nome[200];
    char telefone[14];
    char endereco[200];
    float salario;
    int dia_a,mes_a,ano_a;//data de admissao
    int ativo;

    char usuario[10];
    char senha[10];
}TFuncionario;
typedef struct{
    char nome[50];
    float preco;
    char genero[20];
    int ano_lancamento;
    char categoria[20];
    char descricao[200];
    char classificacao_indicativa[20];
    int ativo;
    int quantidade_comprado;
}TProduto;
typedef struct{
    int mes;
    int dia;
    float lucro;
    float entrada;
    float saida;
}TRelatorio;

//efeitos sonoros/ Beeps
void Musica_opcao()
{
    Beep(380,300);
}
void Musica(){
     //musica do salto do jogo
    Beep(860,500);
}

//UTILIDADES * MUDAR COR DO TEXTO/COR DO PLANO DE FUNDO, FUN��O DE COORDENADAS, FUN��O PRA DESENHAR A BORDA DA JANELA,
//E FUN��O PRA DESENHAR OS BOTOES
void gotoxy(int x,int y)
{	//pra posicionar com coordenadas
    COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}
void textcolor(int newcolor)
{   //pra mudar a cor da letra
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
      (csbi.wAttributes & 0xf0) | newcolor);

}
void textbackground(int newcolor)
{   //pra mudar a cor de fundo da letra
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
      (csbi.wAttributes & 0x0f) | (newcolor << 4));

}
void Janela()
{   //desenho da borda da janela
    int i,j;
    for(i=1;i<27;i++)
    {
        gotoxy(0,i);
        printf("%c",186);
    }
    gotoxy(0,27);
    printf("%c",200);
    gotoxy(0,0);
    printf("%c",201);
    for(i=1;i<121;i++)
    {
        gotoxy(i,0);
        printf("%c",205);
    }
    for(i=1;i<121;i++)
    {
        gotoxy(i,27);
        printf("%c",205);
    }

    gotoxy(121,27);
    printf("%c",188);

    gotoxy(121,0);
    printf("%c",187);
    for(i=1;i<27;i++)
    {
        gotoxy(121,i);
        printf("%c",186);
    }

}
void Quadro_colorido(int cor,int x_comeco,int x,int y_comeco, int y)
{
    int i,j;

    textbackground(cor);
    for(i=y_comeco;i<y;i++)
    {
        for(j=x_comeco;j<x;j++)
        {
            gotoxy(j,i);
            printf(" ");
        }

    }
}

//DESENHOS
void Logo(int j, int i)
{      //int j=50,i=1;
        gotoxy(j,i);i++;
        printf("         _\n");
        gotoxy(j,i);i++;
        printf("       _/\\      _-'\n");
        gotoxy(j,i);i++;
        printf("      _/| \\-''- _ /\n");
        gotoxy(j,i);i++;
        printf("__-'  { |         \\\n");
        gotoxy(j,i);i++;
        printf("     /             \\\n");
        gotoxy(j,i);i++;
        printf("     /      ''o. |o }\n");
        gotoxy(j,i);i++;
        printf("     |           \\  ;\n");
        gotoxy(j,i);i++;
        printf("                   ',\n");
        gotoxy(j,i);i++;
        printf("       \\_         __ \\\n");
        gotoxy(j,i);i++;
        printf("          ''-_    \\.//\n");
        gotoxy(j,i);i++;
        printf("            / '-____'\n");
        gotoxy(j,i);i++;
        printf("           /\n");
        gotoxy(j,i);i++;
        printf("         _'\n");
        gotoxy(j,i);i++;
        printf("       _-'\n");

}
void Cadeado_Fechado()
{
    int i=3,j=38;
    gotoxy(j,i);i++;
    printf("               ");
    gotoxy(j,i);i++;
    printf("                  ");
    gotoxy(j,i);i++;
    printf("     .--------.");
    gotoxy(j,i);i++;
    printf("    / .------. \\ ");
    gotoxy(j,i);i++;
    printf("   / /        \\ \\");
    gotoxy(j,i);i++;
    printf("   | |        | |");
    gotoxy(j,i);i++;
    printf("  _| |________| |_");
    gotoxy(j,i);i++;
    printf(".' |_|        |_| '.");
    gotoxy(j,i);i++;
    printf("'._____ ____ _____.'");
    gotoxy(j,i);i++;
    printf("|     .'____'.     |");
    gotoxy(j,i);i++;
    printf("'.__.'.'    '.'.__.'");
    gotoxy(j,i);i++;
    printf("'.__  |STEAM |  __.'");
    gotoxy(j,i);i++;
    printf("|   '.'.____.'.'   |");
    gotoxy(j,i);i++;
    printf("'.____'.____.'____.'");
    gotoxy(j,i);i++;
    printf("'.________________.'");

}
void Cadeado_abrindo()
{
    int i=3,j=38;

    gotoxy(j,i);i++;
    printf("               ");
    gotoxy(j,i);i++;
    printf("                  ");
    gotoxy(j,i);i++;
    printf("     .--------.");
    gotoxy(j,i);i++;
    printf("    / .------. \\ ");
    gotoxy(j,i);i++;
    printf("   / /        \\ \\");
    gotoxy(j,i);i++;
    printf("   | |        | |");
    gotoxy(j,i);i++;
    printf("  _| |________| |_");
    gotoxy(j,i);i++;
    printf(".' |_|        |_| '.");
    gotoxy(j,i);i++;
    printf("'._____ ____ _____.'");
    gotoxy(j,i);i++;
    printf("|     .'____'.     |");
    gotoxy(j,i);i++;
    printf("'.__.'.'    '.'.__.'");
    gotoxy(j,i);i++;
    printf("'.__  |STEAM |  __.'");
    gotoxy(j,i);i++;
    printf("|   '.'.____.'.'   |");
    gotoxy(j,i);i++;
    printf("'.____'.____.'____.'");
    gotoxy(j,i);i++;
    printf("'.________________.'");

    Sleep(500);

     i=3,j=38;


    gotoxy(j,i);i++;
    printf("               ");
    gotoxy(j,i);i++;
    printf("                  ");
    gotoxy(j,i);i++;
    printf("                     ");
    gotoxy(j,i);i++;
    printf("                 ");
    gotoxy(j,i);i++;
    printf("                  ");
    gotoxy(j,i);i++;
    printf("                    ");
    gotoxy(j,i);i++;
    printf("                    ");
    gotoxy(j,i);i++;
    printf("                    ");
    gotoxy(j,i);i++;
    printf("                    ");
    gotoxy(j,i);i++;
    printf("                    ");
    gotoxy(j,i);i++;
    printf("                    ");
    gotoxy(j,i);i++;
    printf("                    ");
    gotoxy(j,i);i++;
    printf("                    ");

     i=3,j=38;

    gotoxy(j,i);i++;
    printf("     .--------.");
    gotoxy(j,i);i++;
    printf("    / .------. \\ ");
    gotoxy(j,i);i++;
    printf("   / /        \\ \\");
    gotoxy(j,i);i++;
    printf("   | |        | |");
    gotoxy(j,i);i++;
    printf("   | |        |_|");
    gotoxy(j,i);i++;
    printf("   | |            ");
    gotoxy(j,i);i++;
    printf("  _| |____________");
    gotoxy(j,i);i++;
    printf(".' |_|            '.");
    gotoxy(j,i);i++;
    printf("'._____ ____ _____.'");
    gotoxy(j,i);i++;
    printf("|     .'____'.     |");
    gotoxy(j,i);i++;
    printf("'.__.'.'    '.'.__.'");
    gotoxy(j,i);i++;
    printf("'.__  |STEAM |  __.'");
    gotoxy(j,i);i++;
    printf("|   '.'.____.'.'   |");
    gotoxy(j,i);i++;
    printf("'.____'.____.'____.'");
    gotoxy(j,i);i++;
    printf("'.________________.'");


    Sleep(500);
}

//JANELAS
void Login()
{
    system("cls");
    FILE*p;
    fpos_t Byte;

    TFuncionario funcionario;
    char usuario[10];
    char senha[10];

    Janela();
    system("color 3F");
    //Janela do usuario e senha
    {
        int i;

    gotoxy(9,11);
    printf("%c",186);

    gotoxy(9,12);
    printf("%c",204);
    gotoxy(9,10);
    printf("%c",201);
    for(i=10;i<35;i++)
    {
        gotoxy(i,10);
        printf("%c",205);
    }
    for(i=10;i<35;i++)
    {
        gotoxy(i,12);
        printf("%c",205);
    }

    gotoxy(35,12);
    printf("%c",185);

    gotoxy(35,10);
    printf("%c",187);

    gotoxy(35,11);
    printf("%c",186);

    //Janela senha
    for(i=10;i<35;i++)
    {
        gotoxy(i,14);
        printf("%c",205);
    }

    gotoxy(35,14);
    printf("%c",188);

    gotoxy(35,13);
    printf("%c",186);

    gotoxy(9,13);
    printf("%c",186);

    gotoxy(9,14);
    printf("%c",200);

    }



    gotoxy(10,11);
    printf("Usuario:");
    gotoxy(10,13);
    printf("Senha:");

    Cadeado_Fechado();

    int cont_senha=0,cont_usuario=0,i,j,achou=0;

    do
    {
        cont_senha=0;

        for(i=0;i<10;i++)
        {
           senha[i]=' ';
           usuario[i]=' ';
        }
        //USUARIO
        gotoxy(19,11);
        gets(usuario);
        //SENHA
        j=17;
        for(i=0;i<10;i++)
        {

            gotoxy(j,13);
            senha[i]=getch();

            if(senha[i]==13)
            {
                break;
            }
            else if(senha[i]==8)
            {
                if(i>0)
                {
                    senha[i]=' ';
                    gotoxy(j-1,13);
                    printf(" ");
                    j--;
                    i-=2;
                    cont_senha--;
                }
                else
                {
                    i--;
                }

            }

            else
            {
                cont_senha++;
                j++;
               printf("*");
            }
            if(j<17)
            {
                j=17;
            }

        }


        p=fopen("Funcionario","rb");
        fread(&funcionario,sizeof(funcionario),1,p);
        while(!feof(p)&&achou==0)
        {
            if(strcmp(funcionario.usuario,usuario)==0)
            {   j=0;
                for(i=0;i<cont_senha;i++)
                {
                    if(funcionario.senha[i]!=senha[i])
                    {
                        j++;
                    }
                }
                if(j==0)
                {
                    achou=1;
                    Cadeado_abrindo();
                    break;
                }
            }
            fread(&funcionario,sizeof(funcionario),1,p);
        }
            fclose(p);

        if(achou==0)
        {
            gotoxy(10,15);
            printf("Usuario ou senha incorretos.");
            gotoxy(10,16);
            printf("Tente novamente\n\n\n\n\n\n");

            Sleep(1000);
            //Para apagar as linhas
            gotoxy(19,11);
            printf("              ");
            gotoxy(17,13);
            printf("               ");
            gotoxy(10,15);
            printf("                            ");
            gotoxy(10,16);
            printf("               ");
        }
    }while(achou==0);
}
void Jogo()
{
    char opcao;


    textcolor(0);

    system("color 3F");

    bool fecha=true;
    int i,j,correcao_coluna=30,posicao_placar_vida=30+correcao_coluna;

        //desenho da grama
        textbackground(15);
        textcolor(2);
        gotoxy(9+correcao_coluna,23);
        for(i=9+correcao_coluna;i<52+correcao_coluna;i++)
        {
            gotoxy(i,23);
            printf("%c",178);
        }
        int x=55,var=0,num=0,points=0, erro=0,vida=3, mais_coracao=200,coracao_posi=51+correcao_coluna,ativar_vida,erro_C=0;

do
{



    while(!kbhit())
    {



        //vidas

            gotoxy(posicao_placar_vida,19);
            printf("     ");

        for(i=0;i<vida;i++)
        {
            textcolor(4);
            gotoxy(posicao_placar_vida,19);
            printf("%c",3);

            posicao_placar_vida+=2;
        }
        textcolor(15);
        posicao_placar_vida=30+correcao_coluna;

        //pontua��o
        textbackground(3);
        textcolor(15);
        gotoxy(18+correcao_coluna,19);
        printf("            ",points);
        gotoxy(18+correcao_coluna,19);
        printf("Points:%i",points);

        if(vida>0)
        {

        //Boneco pulando
        if(opcao==' ')
        {


            gotoxy(10+correcao_coluna,21);
            printf(" ");
            gotoxy(11+correcao_coluna,21);
            printf(" ");
            gotoxy(12+correcao_coluna,21);
            printf(" ");
            gotoxy(10+correcao_coluna,22);
            printf(" ");
            gotoxy(12+correcao_coluna,22);
            printf(" ");

            textcolor(15);
            gotoxy(11+correcao_coluna,19);
            printf("%c",1);
            gotoxy(10+correcao_coluna,19);
            printf("\\");
            gotoxy(12+correcao_coluna,19);
            printf("/");
            gotoxy(10+correcao_coluna,20);
            printf("_");
            gotoxy(11+correcao_coluna,20);
            printf("|");
            gotoxy(12+correcao_coluna,20);
            printf("_");

            if(x==11+correcao_coluna)
            {
                points++;
            }



        }//Boneco normal
        else
        {
            gotoxy(11+correcao_coluna,19);
            printf(" ");
            gotoxy(10+correcao_coluna,19);
            printf(" ");
            gotoxy(12+correcao_coluna,19);
            printf(" ");
            gotoxy(10+correcao_coluna,20);
            printf(" ");
            gotoxy(12+correcao_coluna,20);
            printf(" ");

            textcolor(15);
            gotoxy(11+correcao_coluna,20);
            printf("%c",1);
            gotoxy(10+correcao_coluna,21);
            printf("/");
            gotoxy(11+correcao_coluna,21);
            printf("|");
            gotoxy(12+correcao_coluna,21);
            printf("\\");
            gotoxy(10+correcao_coluna,22);
            printf("/");
            gotoxy(12+correcao_coluna,22);
            printf("\\");

            if(erro==0)
            {
                if(x==11+correcao_coluna||x==10+correcao_coluna||x==12+correcao_coluna)
                {
                        gotoxy(18+correcao_coluna,20);
                        printf("You hit the block. -2pts.");
                        points-=2;
                        vida--;

                    erro++;
                }
            }
            if(erro_C==0)
            {
                if(coracao_posi==11+correcao_coluna||coracao_posi==10+correcao_coluna||coracao_posi==12+correcao_coluna)
                {
                    if(vida<3)
                    {
                        gotoxy(18+correcao_coluna,21);
                        textcolor(4);
                        printf("%c++",3);
                        textcolor(15);
                        vida++;

                        erro_C++;
                    }
                }
            }


        }
        if(x<10+correcao_coluna)
        {
            erro=0;
        }
        if(x==16+correcao_coluna)
        {
            gotoxy(18+correcao_coluna,20);
            printf("                         ");

            gotoxy(18+correcao_coluna,21);
            printf("    ");
        }


        if(x>correcao_coluna)
        {
          x--; gotoxy(x,22); printf("^");
          gotoxy(x+1,22); printf(" ");
        }
        if(x==8+correcao_coluna)
        {   gotoxy(x,22);
            printf(" ");
            x=51+correcao_coluna;
        }
        //A variavel var vai fazer com que o boneco passe um tempo no ar quando pula
        if(var==5)
        {
            var=0;
            opcao='a';
        }
        var++;
        mais_coracao--;

        if(mais_coracao==0)
        {
            mais_coracao=200;
            ativar_vida=1;
            erro_C=0;

        }


        if(coracao_posi>correcao_coluna&&ativar_vida==1)
        {
          coracao_posi--; gotoxy(coracao_posi,22); textcolor(4);printf("%c",3);textcolor(15);
          gotoxy(coracao_posi+1,22); printf(" ");
        }
        if(coracao_posi==8+correcao_coluna)
        {   gotoxy(coracao_posi,22);
            printf(" ");
            coracao_posi=51+correcao_coluna;
            ativar_vida=0;
        }

        }
        else
        {
            gotoxy(20+correcao_coluna,21);
            textcolor(4);
            printf("Voce morreu! Deseja jogar novamente?(S/N)");
            textcolor(15);
        }

        Sleep(50);


    }

        opcao=getch();

        if(opcao=='s'||opcao=='S'||vida>0)
        {
            var=0;

            _beginthread(Musica,0,NULL);
            if(vida==0)
            {
                gotoxy(20+correcao_coluna,21);
                printf("                                         ");
                gotoxy(x,22);
                printf(" ");
                x=51+correcao_coluna;
                points=0;
                erro=0;
                vida=3;
                erro_C=0;
            }

        }

        if(opcao=='x'||opcao=='X'||opcao=='n'||opcao=='N')
        {
            fecha=false;
            break;
        }





}while(fecha);

}
void Tela_de_Carregamento()
{

    char opcao;
    int i,j,x=55,var=0, percentual=45,num=0,p=0,points=0, erro=0;
    bool fecha=true;
    textcolor(0);
    //Cor_do_BG(15);
    system("color 3F");
    Janela();
    Logo(50,1);

    int correcao_coluna=30,vida=3,posicao_placar_vida=30+correcao_coluna;

    //DESENHO DA BORDA DO CARREGAMENTO
    {for(i=15+correcao_coluna;i<42+correcao_coluna;i++)
            {
                gotoxy(i,15);
                printf("%c",205);
            }
            gotoxy(14+correcao_coluna,15);
            printf("%c",201);


            gotoxy(42+correcao_coluna,15);
            printf("%c",187);

            gotoxy(14+correcao_coluna,16);
            printf("%c",186);

            for(i=15+correcao_coluna;i<42+correcao_coluna;i++)
            {
                gotoxy(i,17);
                printf("%c",205);
            }

            gotoxy(42+correcao_coluna,17);
            printf("%c",188);

            gotoxy(14+correcao_coluna,17);
            printf("%c",200);

            gotoxy(42+correcao_coluna,16);
            printf("%c",186);
    }

        //desenho da grama
        textbackground(15);
        textcolor(2);
        gotoxy(9+correcao_coluna,23);
        for(i=9+correcao_coluna;i<52+correcao_coluna;i++)
        {
            gotoxy(i,23);
            printf("%c",178);
        }

do
{


    while(!kbhit()&&num<=100)
    {

        //carregamento
        if(num<=100)
        {
            textbackground(7);
            textcolor(7);
            gotoxy(percentual,16);
            printf("%c",219);
            textcolor(15);
            textbackground(3);
            gotoxy(44+correcao_coluna,16);
            printf("%i%%",num);

            num++;
            if(num%3==0)
            {
               p++;
            }

            if(p%4==0)
            {
                percentual++;
            }


        }


        //vidas

            gotoxy(posicao_placar_vida,19);
            printf("     ");

        for(i=0;i<vida;i++)
        {
            textcolor(4);
            gotoxy(posicao_placar_vida,19);
            printf("%c",3);

            posicao_placar_vida+=2;
        }
        textcolor(15);
        posicao_placar_vida=30+correcao_coluna;


        //pontua��o
        textbackground(3);
        textcolor(15);
        gotoxy(18+correcao_coluna,19);
        printf("            ",points);
        gotoxy(18+correcao_coluna,19);
        printf("Points:%i",points);
        if(vida>0)
        {




        //Boneco pulando
        if(opcao==' ')
        {


            gotoxy(10+correcao_coluna,21);
            printf(" ");
            gotoxy(11+correcao_coluna,21);
            printf(" ");
            gotoxy(12+correcao_coluna,21);
            printf(" ");
            gotoxy(10+correcao_coluna,22);
            printf(" ");
            gotoxy(12+correcao_coluna,22);
            printf(" ");

            textcolor(15);
            gotoxy(11+correcao_coluna,19);
            printf("%c",1);
            gotoxy(10+correcao_coluna,19);
            printf("\\");
            gotoxy(12+correcao_coluna,19);
            printf("/");
            gotoxy(10+correcao_coluna,20);
            printf("_");
            gotoxy(11+correcao_coluna,20);
            printf("|");
            gotoxy(12+correcao_coluna,20);
            printf("_");

            if(x==11+correcao_coluna)
            {
                points++;
            }



        }//Boneco normal
        else
        {
            gotoxy(11+correcao_coluna,19);
            printf(" ");
            gotoxy(10+correcao_coluna,19);
            printf(" ");
            gotoxy(12+correcao_coluna,19);
            printf(" ");
            gotoxy(10+correcao_coluna,20);
            printf(" ");
            gotoxy(12+correcao_coluna,20);
            printf(" ");

            textcolor(15);
            gotoxy(11+correcao_coluna,20);
            printf("%c",1);
            gotoxy(10+correcao_coluna,21);
            printf("/");
            gotoxy(11+correcao_coluna,21);
            printf("|");
            gotoxy(12+correcao_coluna,21);
            printf("\\");
            gotoxy(10+correcao_coluna,22);
            printf("/");
            gotoxy(12+correcao_coluna,22);
            printf("\\");

            if(erro==0)
            {
                if(x==11+correcao_coluna||x==10+correcao_coluna||x==12+correcao_coluna)
                {
                        gotoxy(18+correcao_coluna,20);
                        printf("You hit the block. -2pts.");
                        points-=2;
                        vida--;

                    erro++;
                }
            }


        }
        if(x<10+correcao_coluna)
        {
            erro=0;
        }
        if(x==16+correcao_coluna)
        {
            gotoxy(18+correcao_coluna,20);
            printf("                         ");
        }


        if(x>correcao_coluna)
        {
          x--; gotoxy(x,22); printf("^");
          gotoxy(x+1,22); printf(" ");
        }
        if(x==8+correcao_coluna)
        {   gotoxy(x,22);
            printf(" ");
            x=51+correcao_coluna;
        }
        //A variavel var vai fazer com que o boneco passe um tempo no ar quando pula
        if(var==5)
        {
            var=0;
            opcao='a';
        }
        var++;
        }
        else
        {
            gotoxy(30+correcao_coluna,21);
            textcolor(4);
            printf("Voce morreu!");
            textcolor(15);
        }

        Sleep(50);


    }
    if(num<100&&vida>0)
    {
        opcao=getch();
        var=0;
        _beginthread(Musica,0,NULL);
    }


}while(num<100);

    gotoxy(14+correcao_coluna,18);
    printf("O CARREGAMENTO FOI FINALIZADO.");
    gotoxy(18+correcao_coluna,20);
    printf("DESEJA CONTINUAR A JOGAR?(S/N)");
    do
    {
        opcao=getch();


        if(opcao=='s'||opcao=='S')
        {
            system("cls");

            p=0;
            percentual=45;


        //DESENHO DA BORDA DO CARREGAMENTO
    {for(i=15+correcao_coluna;i<42+correcao_coluna;i++)
            {
                gotoxy(i,15);
                printf("%c",205);
            }
            gotoxy(14+correcao_coluna,15);
            printf("%c",201);


            gotoxy(42+correcao_coluna,15);
            printf("%c",187);

            gotoxy(14+correcao_coluna,16);
            printf("%c",186);

            for(i=15+correcao_coluna;i<42+correcao_coluna;i++)
            {
                gotoxy(i,17);
                printf("%c",205);
            }

            gotoxy(42+correcao_coluna,17);
            printf("%c",188);

            gotoxy(14+correcao_coluna,17);
            printf("%c",200);

            gotoxy(42+correcao_coluna,16);
            printf("%c",186);
    }

            for(percentual=45;percentual<72;percentual++)
            {       textbackground(7);
                    textcolor(7);
                    gotoxy(percentual,16);
                    printf("%c",219);

            }
            textbackground(3);
            textcolor(15);
            num=100;
            gotoxy(44+correcao_coluna,16);
            printf("%i%%",num);
            gotoxy(15+correcao_coluna,25);
        printf("Para parar de jogar aperte X");

        Logo(50,1);
        Jogo();
        fecha=false;


    }
    else if(opcao=='n'||opcao=='N')
    {
        fecha=false;
    }

    }while(fecha);

}
void Area_de_Trabalho()
{   //area que tem os menus

    system("cls");
    Janela();
    system("Color 3F");
    Logo(50,12);

    POINT Coordenadas;
    int ativou=0,att1=0,att2=0,att3=0,att4=0,att5=0,x_antigo,y_antigo;

    //as variaveis att sao pra o menu n ficar piscando, ai so imprime uma vez e pronto e as variaveis com o nome entra tbm sao


    int movimento=0,movimentosubir=0,auxiliar,x,y,i,j;
    bool fecha=true,entra1=true,entra2=true;
    char resp;

                    Quadro_colorido(7,1,121,3,6);

					gotoxy(6,4);
					printf("%c",175);
					x=10;

			do
            {
                    textcolor(15);



                    GetCursorPos(&Coordenadas);

                    textbackground(7);
                    //FUNCIONARIOS
                    if((Coordenadas.x>=60&&Coordenadas.x<=270 && Coordenadas.y<=166&&Coordenadas.y>=100))
                    {   att1=0;


                            Quadro_colorido(8,5,25,3,10);
                            gotoxy(10,4);
                            printf("FUNCIONARIOS");
                            do
                            {
                                if(kbhit())
                                {
                                    resp=getch();
                                }

                                    x_antigo=Coordenadas.x;
                                    y_antigo=Coordenadas.y;
                                    GetCursorPos(&Coordenadas);


                                                    textbackground(8);
                                                 if((Coordenadas.x>=60&&Coordenadas.x<=270 && Coordenadas.y<=210&&Coordenadas.y>=170))
                                                 {
                                                     y=6;
                                                    ativou++;
                                                    if(ativou==1)
                                                    {
                                                        _beginthread(Musica_opcao,0,NULL);
                                                        textbackground(7);
                                                        Quadro_colorido(7,5,25,6,8);
                                                        gotoxy(10,6);
                                                        printf("CADASTRAR");
                                                        textbackground(8);
                                                    }

                                                    if(resp==13)
                                                    {
                                                        //so pra testar
                                                        Aba_Cadastro(1);
                                                        resp=' ';
                                                        Area_de_Trabalho();
                                                        break;
                                                    }


                                                 }
                                                 else if(x_antigo>=60&&x_antigo<=270 && y_antigo<=210&&y_antigo>=170)
                                                 {
                                                    ativou=0;
                                                    Quadro_colorido(8,5,25,6,8);
                                                    gotoxy(10,6);
                                                    printf("CADASTRAR");
                                                 }
                                                 else if(entra1)
                                                 {
                                                    entra1=false;
                                                    gotoxy(10,6);
                                                    printf("CADASTRAR");
                                                 }


                                                if((Coordenadas.x>=60&&Coordenadas.x<=270 && Coordenadas.y<=260&&Coordenadas.y>=210))
                                                 {
                                                    y=8;
                                                    ativou++;
                                                    if(ativou==1)
                                                    {
                                                        _beginthread(Musica_opcao,0,NULL);
                                                        textbackground(7);
                                                        Quadro_colorido(7,5,25,8,10);
                                                        gotoxy(10,8);
                                                        printf("CONSULTAR");
                                                        textbackground(8);
                                                    }
                                                    if(resp==13)
                                                    {
                                                        //so pra testar
                                                        Aba_Consulta(1);
                                                        resp=' ';
                                                        Area_de_Trabalho();
                                                        break;
                                                    }



                                                 }
                                                 else if(x_antigo>=60&&x_antigo<=270 && y_antigo<=260&&y_antigo>=210)
                                                 {
                                                    ativou=0;
                                                    Quadro_colorido(8,5,25,8,10);
                                                    gotoxy(10,8);
                                                    printf("CONSULTAR");
                                                 }
                                                 else if(entra2)
                                                 {
                                                     entra2=false;
                                                    gotoxy(10,8);
                                                    printf("CONSULTAR");
                                                 }


                    }while((Coordenadas.x>=60&&Coordenadas.x<=278 && Coordenadas.y<=260&&Coordenadas.y>=100));

                    Quadro_colorido(7,5,25,3,6);
                    Quadro_colorido(3,5,25,6,10);

                    entra1=true;entra2=true;

                    textbackground(7);

                    gotoxy(10,4);
                    printf("FUNCIONARIOS");
                    att1++;
                    }
                    else if(att1==0)
                    {
                        textbackground(7);
                        att1++;
                        gotoxy(10,4);
                        printf("FUNCIONARIOS");

                    }

                    //USUARIOS
                    if((Coordenadas.x>=270&&Coordenadas.x<=480 && Coordenadas.y<=166&&Coordenadas.y>=100))
                    {   att2=0;


                            Quadro_colorido(8,25,45,3,10);
                            gotoxy(30,4);
                            printf("USUARIOS");
                            do
                            {

                                    x_antigo=Coordenadas.x;
                                    y_antigo=Coordenadas.y;
                                    GetCursorPos(&Coordenadas);

                                                    textbackground(8);
                                                 if((Coordenadas.x>=270&&Coordenadas.x<=480 && Coordenadas.y<=210&&Coordenadas.y>=170))
                                                 {
                                                     y=6;
                                                    ativou++;
                                                    if(ativou==1)
                                                    {
                                                        _beginthread(Musica_opcao,0,NULL);
                                                        textbackground(7);
                                                        Quadro_colorido(7,25,45,6,8);
                                                        gotoxy(30,6);
                                                        printf("CADASTRAR");
                                                        textbackground(8);
                                                    }


                                                 }
                                                 else if(x_antigo>=270&&x_antigo<=480 && y_antigo<=210&&y_antigo>=170)
                                                 {
                                                    ativou=0;
                                                    Quadro_colorido(8,25,45,6,8);
                                                    gotoxy(30,6);
                                                    printf("CADASTRAR");
                                                 }
                                                 else if(entra1)
                                                 {
                                                     entra1=false;
                                                    gotoxy(30,6);
                                                    printf("CADASTRAR");
                                                 }


                                                if((Coordenadas.x>=270&&Coordenadas.x<=480 && Coordenadas.y<=260&&Coordenadas.y>=210))
                                                 {
                                                    y=8;
                                                    ativou++;
                                                    if(ativou==1)
                                                    {
                                                        _beginthread(Musica_opcao,0,NULL);
                                                        textbackground(7);
                                                        Quadro_colorido(7,25,45,8,10);
                                                        gotoxy(30,8);
                                                        printf("CONSULTAR");
                                                        textbackground(8);
                                                    }



                                                 }
                                                 else if(x_antigo>=270&&x_antigo<=480 && y_antigo<=260&&y_antigo>=210)
                                                 {
                                                    ativou=0;
                                                    Quadro_colorido(8,25,45,8,10);
                                                    gotoxy(30,8);
                                                    printf("CONSULTAR");
                                                 }
                                                 else if(entra2)
                                                 {
                                                     entra2=false;
                                                    gotoxy(30,8);
                                                    printf("CONSULTAR");
                                                 }



                                                gotoxy(0,25);
                                                if(kbhit())
                                                {
                                                    resp=getch();
                                                }



                                                  if(resp==13)
                                                {
                                                    switch(y)
                                                    {
                                                    case 6:
                                                        {
                                                        	Aba_Cadastro(2);
                                                        	resp=' ';
                                                        	Area_de_Trabalho();
                                                           break;
                                                        }
                                                    case 8:
                                                        {
                                                            Aba_Consulta(2);
                                                        	resp=' ';
                                                        	Area_de_Trabalho();
                                                            break;
                                                        }

                                                    }
                                                }
                    }while((Coordenadas.x>=270&&Coordenadas.x<=488 && Coordenadas.y<=260&&Coordenadas.y>=100));

                    Quadro_colorido(7,25,45,3,6);
                    Quadro_colorido(3,25,45,6,10);

                    entra1=entra2=true;

                        textbackground(7);
                        att2++;
                        gotoxy(30,4);
                        printf("USUARIOS");

                    }
                    else if(att2==0)
                    {
                        textbackground(7);
                        att2++;
                        gotoxy(30,4);
                        printf("USUARIOS");

                    }

                    //PRODUTOS
                    if((Coordenadas.x>=480&&Coordenadas.x<=690 && Coordenadas.y<=166&&Coordenadas.y>=100))
                    {   att3=0;


                            Quadro_colorido(8,45,65,3,10);
                            gotoxy(50,4);
                            printf("PRODUTOS");
                            do
                            {

                                    x_antigo=Coordenadas.x;
                                    y_antigo=Coordenadas.y;
                                    GetCursorPos(&Coordenadas);


                                                    textbackground(8);
                                                 if((Coordenadas.x>=480&&Coordenadas.x<=690 && Coordenadas.y<=210&&Coordenadas.y>=170))
                                                 {
                                                     y=6;
                                                    ativou++;
                                                    if(ativou==1)
                                                    {
                                                        _beginthread(Musica_opcao,0,NULL);
                                                        textbackground(7);
                                                        Quadro_colorido(7,45,65,6,8);
                                                        gotoxy(50,6);
                                                        printf("CADASTRAR");
                                                        textbackground(8);
                                                    }


                                                 }
                                                 else if(x_antigo>=480&&x_antigo<=690 && y_antigo<=210&&y_antigo>=170)
                                                 {
                                                    ativou=0;
                                                    Quadro_colorido(8,45,65,6,8);
                                                    gotoxy(50,6);
                                                    printf("CADASTRAR");
                                                 }
                                                 else if(entra1)
                                                 {
                                                     entra1=false;
                                                    gotoxy(50,6);
                                                    printf("CADASTRAR");
                                                 }


                                                if((Coordenadas.x>=480&&Coordenadas.x<=690 && Coordenadas.y<=260&&Coordenadas.y>=210))
                                                 {
                                                    y=8;
                                                    ativou++;
                                                    if(ativou==1)
                                                    {
                                                        _beginthread(Musica_opcao,0,NULL);
                                                        textbackground(7);
                                                        Quadro_colorido(7,45,65,8,10);
                                                        gotoxy(50,8);
                                                        printf("CONSULTAR");
                                                        textbackground(8);
                                                    }



                                                 }
                                                 else if(x_antigo>=480&&x_antigo<=690 && y_antigo<=260&&y_antigo>=210)
                                                 {
                                                    ativou=0;
                                                    Quadro_colorido(8,45,65,8,10);
                                                    gotoxy(50,8);
                                                    printf("CONSULTAR");
                                                 }
                                                 else if(entra2)
                                                 {
                                                     entra2=false;
                                                    gotoxy(50,8);
                                                    printf("CONSULTAR");
                                                 }



                                                gotoxy(0,25);
                                                if(kbhit())
                                                {
                                                    resp=getch();
                                                }



                                                if(resp==13)
                                                {
                                                    switch(y)
                                                    {
                                                    case 6:
                                                        {
                                                            Aba_Cadastro(3);
                                                        	resp=' ';
                                                        	Area_de_Trabalho();
                                                           break;
                                                        }
                                                    case 8:
                                                        {
                                                            Aba_Consulta(3);
                                                        	resp=' ';
                                                        	Area_de_Trabalho();
                                                            break;
                                                        }

                                                    }
                                                }

                    }while((Coordenadas.x>=488&&Coordenadas.x<=699 && Coordenadas.y<=260&&Coordenadas.y>=100));

                    Quadro_colorido(7,45,65,3,6);
                    Quadro_colorido(3,45,65,6,10);

                    entra1=entra2=true;

                        textbackground(7);
                        att3++;
                        gotoxy(50,4);
                        printf("PRODUTOS");

                    }
                    else if(att3==0)
                    {
                        textbackground(7);
                        att3++;
                        gotoxy(50,4);
                        printf("PRODUTOS");

                    }

                    //FINANCEIRO
                    if((Coordenadas.x>=700&&Coordenadas.x<=910 && Coordenadas.y<=166&&Coordenadas.y>=100))
                    {att4=0;

                            if(resp==13)
                            {
                                FINANCEIRO();
                                Area_de_Trabalho();
                                break;
                            }
                            if(entra2)
                            {
                                Quadro_colorido(8,65,85,3,6);
                                gotoxy(70,4);
                                printf("FINANCEIRO");
                                entra2=false;
                            }




                    }
                    else if(att4==0)
                    {
                        textbackground(7);
                        Quadro_colorido(7,65,85,3,6);
                        att4++;
                        gotoxy(70,4);
                        printf("FINANCEIRO");
                        entra2=true;
                    }

                    //SAIR
                    if((Coordenadas.x>=910&&Coordenadas.x<=1150 && Coordenadas.y<=166&&Coordenadas.y>=100))
                    {   att5=0;
                            if(entra1)
                            {
                                Quadro_colorido(8,85,105,3,6);
                                gotoxy(90,4);
                                printf("SAIR");
                                entra1=false;
                            }


                            if(resp==13)
                            {
                                if(MessageBox(0,"Deseja sair mesmo?","",4)==6)
                                {
                                    exit(0);
                                    fecha=false;
                                }
                            }
                    }
                    else if(att5==0)
                    {

                            att5++;
                            Quadro_colorido(7,85,105,3,6);
                            gotoxy(90,4);
                            printf("SAIR");
                            entra1=true;
                    }

                            gotoxy(0,26);
                            if(kbhit())
                            {
                                resp=getch();
                            }

				}while(fecha);

}

//ABAS DE CONSULTA
int Consulta_funcionario(char procura[200])
{
    FILE *p;
    int achou=0;
    TFuncionario consulta;
    p=fopen("Funcionario","rb");
    fpos_t Byte;

    fread(&consulta,sizeof(consulta),1,p);
    while(!feof(p)&&achou==0)
    {
        if(strcmp(consulta.nome,procura)==0)
        {
            achou=1;
            fgetpos(p,&Byte);
            fclose(p);
            return(Byte);
        }
        fread(&consulta,sizeof(consulta),1,p);
    }
    if(achou==0)
    {

        fclose(p);
        return(0);
    }
}
int Consulta_user(char pesquisa[200])
{

	FILE* pesquisar;
	TUsuario usuario;
	int resultado;
	int find=0;
	fpos_t Byte;

	pesquisar=fopen("Usuario","rb");
	fread(&usuario,sizeof(usuario),1,pesquisar);

    while(!feof(pesquisar)&&find==0)
	{

		if(strcmp(usuario.nome,pesquisa)==0)
		{

			find=1;
			fgetpos(pesquisar,&Byte);
			fclose(pesquisar);
			return (Byte);
		}
		fread(&usuario,sizeof(usuario),1,pesquisar);
	}
	if(find==0)
    {
        fclose(pesquisar);
        return(0);
    }

}
int Consulta_produto(char search[200])
{
    FILE *p;
    TProduto consultar;
    int encontrou=0;
    p=fopen("Produto","rb");
    fpos_t Byte;
    fread(&consultar,sizeof(consultar),1,p);

    while(!feof(p)&&encontrou==0)
    {
        if(strcmp(consultar.nome,search)==0)
        {
            encontrou=1;
            fgetpos(p,&Byte);
            fclose(p);
            return(Byte);
        }
        fread(&consultar,sizeof(consultar),1,p);
    }
    if(encontrou==0)
    {
        fclose(p);
        return(0);
    }
}
int Consulta_produto_ativo(char search[200])
{
    FILE *p;
    TProduto consultar;
    int encontrou=0;
    p=fopen("Produto","rb");
    fpos_t Byte;
    fread(&consultar,sizeof(consultar),1,p);

    while(!feof(p)&&encontrou==0)
    {
        if(strcmp(consultar.nome,search)==0&&consultar.ativo==1)
        {
            encontrou=1;
            fgetpos(p,&Byte);
            fclose(p);
            return(Byte);
        }
        fread(&consultar,sizeof(consultar),1,p);
    }
    if(encontrou==0)
    {
        fclose(p);
        return(0);
    }
}
int Aba_Consulta(int arquivo ,fpos_t ByteUsuario/*1 - funcionarios ; 2- usuarios; 3- produtos*/)
{
    POINT Coordenadas;
    bool entra=true;
    int ativou=0;
    char resp;
    system("cls");
    system("Color 3F");
    Logo(50,1);
    Janela();
    //Borda
    {
     int i,j;

        gotoxy(34,17);
        printf("%c",186);

    gotoxy(34,18);
    printf("%c",200);
    gotoxy(34,16);
    printf("%c",201);
    for(i=35;i<85;i++)
    {
        gotoxy(i,16);
        printf("%c",205);
        gotoxy(i,18);
        printf("%c",205);
    }

    gotoxy(85,18);
    printf("%c",188);

    gotoxy(85,16);
    printf("%c",187);

        gotoxy(85,17);
        printf("%c",186);

    }
    textbackground(15);
    int i;

    for(i=35;i<85;i++)
    {
        gotoxy(i,17);
        printf(" ");
    }


    do
    {
        if(kbhit())
        {
            resp=getch();

            if(resp==13 && Coordenadas.x<940 &&Coordenadas.x>388 &&Coordenadas.y<470 && Coordenadas.y>423)
            {
                textbackground(15);
                textcolor(8);
                char procura[200];
                gotoxy(35,17);
                gets(procura);
                fflush(stdin);
                resp=' ';

                fpos_t Byte;


                if(arquivo==1)
                {
                    Byte=Consulta_funcionario(procura);
                }
                 if(arquivo==2)
                {
                    Byte=Consulta_user(procura);

                }
                if(arquivo==3)
                {
                    Byte=Consulta_produto(procura);
                }
                if(arquivo==4)
                {
                    Byte=Consulta_produto_ativo(procura);
                }

                    if(Byte!=0)
                    {
                        return(Aba_Resultado(Byte,arquivo,ByteUsuario));
                        break;
                    }
                    else
                    {
                        gotoxy(40,18);
                        printf("Resultado Nao encontrado");
                        Sleep(1000);
                        Aba_Consulta(arquivo,ByteUsuario);
                        break;
                    }

            }
        }


        textbackground(3);
        GetCursorPos(&Coordenadas);
        if(Coordenadas.x<775 &&Coordenadas.x>555 &&Coordenadas.y<580 && Coordenadas.y>510)
        {
            if(ativou==0)
            {   textcolor(15);
                Quadro_colorido(8,50,70,20,23);
                gotoxy(56,21);
                printf("RETORNAR");
            }
            entra=true;
            ativou++;
            if(resp==13)
            {
                resp=' ';
                break;
            }

        }
        else if(entra)
        {
            Quadro_colorido(7,50,70,20,23);
            textcolor(8);
            gotoxy(56,21);
            printf("RETORNAR");
            entra=false;
            ativou=0;
        }

    }while(1);



}

//ABAS RESULTADO
void Resultado_Funcionario(fpos_t Byte)
{
    FILE*p;
    TFuncionario funcionario;
    p=fopen("Funcionario","rb");
    Byte=Byte-sizeof(funcionario);
    fsetpos(p,&Byte);
    fread(&funcionario,sizeof(funcionario),1,p);

    gotoxy(40,5);
    printf("NOME: %s",funcionario.nome);

    gotoxy(40,7);
    printf("TELEFONE: %s",funcionario.telefone);

    gotoxy(40,9);
    printf("ENDERECO: %s ",funcionario.endereco);

    gotoxy(40,11);
    printf("SALARIO: R$%.2f ",funcionario.salario);

    gotoxy(40,13);
    printf("USUARIO: %s",funcionario.usuario);

    gotoxy(40,15);
    printf("SENHA: %s",funcionario.senha);

    gotoxy(40,17);
    printf("DATA DE ADMISSAO: %i/%i/%i",funcionario.dia_a,funcionario.mes_a,funcionario.ano_a);



    if(funcionario.ativo==1)
    {
        gotoxy(40,19);
        printf("FUNCIONARIO ATIVO");

    }
    else
    {
        gotoxy(40,19);
        printf("FUNCIONARIO DESATIVADO");
    }



    fclose(p);


}
void Resultado_Usuario(fpos_t Byte)
{
	FILE* pesquisar;
    TUsuario usuario;
    pesquisar=fopen("Usuario","rb");
    Byte=Byte-sizeof(usuario);
    fsetpos(pesquisar,&Byte);
    fread(&usuario,sizeof(usuario),1,pesquisar);

    gotoxy(40,6);
    printf("NOME: %s",usuario.nome);

    gotoxy(40,8);
    printf("USUARIO: %s",usuario.usuario);


    gotoxy(40,10);
    if(usuario.ativo==1)
    {
        printf("USUARIO ATIVO");
    }
    else
    {
        printf("USUARIO DESATIVO");
    }

 		 if(usuario.assinatura==1)
		    {

    			gotoxy(40,14);
    			printf("VIP GOLD");

			}
			else if(usuario.assinatura==2)
			{
    			gotoxy(40,14);
    			printf("VIP PLATINUM");
			}

    gotoxy(40,12);

    printf("COMPRAS REALIZADAS: %i",usuario.numero_de_compras);


    fclose(pesquisar);

}
void Resultado_Produto(fpos_t Byte)
{
	FILE *p;
    TProduto produto;
    p=fopen("Produto","rb");
    Byte=Byte-sizeof(produto);
    fsetpos(p,&Byte);
    fread(&produto,sizeof(produto),1,p);

    gotoxy(40,6);
    printf("NOME DO PRODUTO: %s", produto.nome);

    gotoxy(40,8);
    printf("CATEGORIA: %s", produto.categoria);

    gotoxy(40,10);
    printf("GENERO: %s", produto.genero);

    gotoxy(40,12);
    printf("ANO DE LANCAMENTO: %i", produto.ano_lancamento);

    gotoxy(40,14);
    printf("CLASSIFICACAO INDICATIVA: %s", produto.classificacao_indicativa);

    gotoxy(40,16);
    printf("PRECO: RS %.2f", produto.preco);

    gotoxy(40,18);
    printf("DESCRICAO: %s", produto.descricao);
    gotoxy(40,10);
    if(produto.ativo==1)
    {
        printf("PRODUTO ATIVO");
    }
    else
    {
        printf("PRODUTO DESATIVO");
    }

    gotoxy(40,12);
    printf("QUANTIDADE ADQUIRIDA: %i", produto.quantidade_comprado);

    fclose(p);
}
void Resultado_Produto_compra(fpos_t Byte)
{
	FILE *p;
    TProduto produto;
    p=fopen("Produto","rb");
    Byte=Byte-sizeof(produto);
    fsetpos(p,&Byte);
    fread(&produto,sizeof(produto),1,p);

    gotoxy(40,6);
    printf("NOME DO PRODUTO: %s", produto.nome);

    gotoxy(40,8);
    printf("CATEGORIA: %s", produto.categoria);

    gotoxy(40,10);
    printf("GENERO: %s", produto.genero);

    gotoxy(40,12);
    printf("ANO DE LANCAMENTO: %i", produto.ano_lancamento);

    gotoxy(40,14);
    printf("CLASSIFICACAO INDICATIVA: %s", produto.classificacao_indicativa);

    gotoxy(40,16);
    printf("PRECO: RS %.2f", produto.preco);

    gotoxy(40,18);
    printf("DESCRICAO: %s", produto.descricao);

    gotoxy(40,10);
    if(produto.ativo==1)
    {
        printf("PRODUTO ATIVO");
    }
    else
    {
        printf("PRODUTO DESATIVO");
    }


    fclose(p);
}
int Aba_Resultado(fpos_t Byte,int arquivo,fpos_t ByteUsuario /*1 - funcionarios ; 2- usuarios; 3- produtos; 4-realizar compra*/)
{
    system("cls");
    Janela();
    system("Color 3F");

    POINT Coordenadas;
    bool button1=true,button2=true,button3=true,button4=true;
    int ativado=0;

    Logo(4,1);
    Quadro_colorido(15,38,90,4,25);

    textcolor(3);

    //desenho da borda da janela
    {
    int i,j;
    for(i=5;i<25;i++)
    {
        gotoxy(38,i);
        printf("%c",186);
    }
    gotoxy(38,25);
    printf("%c",200);
    gotoxy(38,4);
    printf("%c",201);
    for(i=39;i<90;i++)
    {
        gotoxy(i,4);
        printf("%c",205);
    }
    for(i=39;i<90;i++)
    {
        gotoxy(i,25);
        printf("%c",205);
    }

    gotoxy(90,25);
    printf("%c",188);

    gotoxy(90,4);
    printf("%c",187);
    for(i=5;i<25;i++)
    {
        gotoxy(90,i);
        printf("%c",186);
    }
}

    if(arquivo==1)
    {   textbackground(3);
        textcolor(15);
        gotoxy(58,2);
        printf("FUNCIONARIO");
        textcolor(8);
        textbackground(15);
        Resultado_Funcionario(Byte);
    }
    if(arquivo==2)
    {   textbackground(3);
        textcolor(15);
        gotoxy(58,2);
        printf("USUARIO");
        textcolor(8);
        textbackground(15);
        Resultado_Usuario(Byte);
    }
    if(arquivo==3)
    {   textbackground(3);
        textcolor(15);
        gotoxy(58,2);
        printf("PRODUTO");
        textcolor(8);
        textbackground(15);
        Resultado_Produto(Byte);
    }
    if(arquivo==4)
    {   textbackground(3);
        textcolor(15);
        gotoxy(58,2);
        printf("PRODUTO");
        textcolor(8);
        textbackground(15);
        Resultado_Produto_compra(Byte);
    }

    char resp;
    do
    {
        if(kbhit())
        {
            resp=getch();
        }

        GetCursorPos(&Coordenadas);

        if(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>150&&Coordenadas.y<220)
        {
            if(ativado==0)
            {
                Quadro_colorido(8,95,118,5,8);

                textcolor(15);
                if(arquivo!=4)
                {
                    gotoxy(103,6);
                    printf("EDITAR");
                }
                else
                {
                    gotoxy(102,6);
                    printf("COMPRAR");
                }

            }
            button1=true;
            ativado++;
            if(resp==13)
            {
                if(arquivo==1)
                {
                   Editar_Funcionario(Byte);
                }
                else if(arquivo==2)
                {
                    Editar_Usuario(Byte);
                }
                else if(arquivo==3)
                {
                    Editar_Produto(Byte);
                }
                else if(arquivo==4)
                {
                    Comprar_produto(Byte,ByteUsuario);
                    return(1);
                }

                resp=' ';
                break;
            }

        }
        else if(button1)
        {
            button1=false;
            Quadro_colorido(7,95,118,5,8);
            gotoxy(103,6);
            textcolor(8);
            if(arquivo!=4)
                {
                    gotoxy(103,6);
                    printf("EDITAR");
                }
                else
                {
                    gotoxy(102,6);
                    printf("COMPRAR");
                }
            ativado=0;
        }

        if(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>270&&Coordenadas.y<340)
        {
            if(ativado==0)
            {
                Quadro_colorido(8,95,118,10,13);

                textcolor(15);
                if(arquivo!=2)
                {   gotoxy(102,11);
                    printf("RETORNAR");
                }
                else
                {   gotoxy(100,11);
                    printf("REALIZAR COMPRA");
                }

            }
            button2=true;
            ativado++;

            if(resp==13)
            {
                if(arquivo!=2)
                {
                    Aba_Consulta(arquivo,ByteUsuario);
                }
                else if(arquivo==2 && Aba_Consulta(4,Byte)==1)
                {
                    Compra_Usuario(Byte);
                }
                resp=' ';
                break;
            }

        }
        else if(button2)
        {
            button2=false;
            Quadro_colorido(7,95,118,10,13);
            gotoxy(102,11);
            textcolor(8);
            if(arquivo!=2)
                {   gotoxy(102,11);
                    printf("RETORNAR");
                }
                else
                {   gotoxy(100,11);
                    printf("REALIZAR COMPRA");
                }
            ativado=0;
        }

        if(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>390&&Coordenadas.y<450)
        {
            if(ativado==0)
            {
                Quadro_colorido(8,95,118,15,18);
                gotoxy(100,16);
                textcolor(15);
                if(arquivo!=2)
                {   gotoxy(100,16);
                    printf("MENU PRINCIPAL");

                }
                else
                {   gotoxy(102,16);
                    printf("RETORNAR");
                }

            }
            button3=true;
            ativado++;
            if(resp==13)
            {
                if(arquivo==2)
                {
                    Aba_Consulta(arquivo,ByteUsuario);
                }
                resp=' ';
                break;
            }

        }
        else if(button3)
        {
            button3=false;
            Quadro_colorido(7,95,118,15,18);
            gotoxy(100,16);
            textcolor(8);
            if(arquivo!=2)
                {   gotoxy(100,16);
                    printf("MENU PRINCIPAL");

                }
                else
                {   gotoxy(102,16);
                    printf("RETORNAR");
                }
            ativado=0;
        }

        if(arquivo==2)
        {
            if(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>510&&Coordenadas.y<580)
            {
                if(ativado==0)
                {
                    Quadro_colorido(8,95,118,20,23);
                    gotoxy(100,21);
                    textcolor(15);
                    printf("MENU PRINCIPAL");
                }
                button4=true;
                ativado++;
                if(resp==13)
                {
                    resp=' ';
                    break;
                }

            }
            else if(button4)
            {
                button4=false;
                Quadro_colorido(7,95,118,20,23);
                gotoxy(100,21);
                textcolor(8);
                printf("MENU PRINCIPAL");
                ativado=0;
            }
        }



    }while(1);

}


//ABAS CADASTRO
void Aba_Cadastro(int arquivo /*1-Funcionario; 2-usuarios 3- produtos*/)
{
    system("cls");
    Janela();
    system("Color 3F");

    Logo(4,1);
    Quadro_colorido(15,38,90,4,25);

    textcolor(3);

    //desenho da borda da janela
    {
    int i,j;
    for(i=5;i<25;i++)
    {
        gotoxy(38,i);
        printf("%c",186);
    }
    gotoxy(38,25);
    printf("%c",200);
    gotoxy(38,4);
    printf("%c",201);
    for(i=39;i<90;i++)
    {
        gotoxy(i,4);
        printf("%c",205);
    }
    for(i=39;i<90;i++)
    {
        gotoxy(i,25);
        printf("%c",205);
    }

    gotoxy(90,25);
    printf("%c",188);

    gotoxy(90,4);
    printf("%c",187);
    for(i=5;i<25;i++)
    {
        gotoxy(90,i);
        printf("%c",186);
    }
}

    if(arquivo==1)
    {
        gotoxy(50,2);
        textbackground(3);
        textcolor(15);
        printf("CADASTRAR FUNCIONARIO");
        textcolor(8);
        textbackground(15);
        if(Cadastro_funcionario()==1)
        {
            MessageBox(0,"CADASTRO REALIZADO COM SUCESSO!","CADASTRO DE FUNCIONARIO",0);
        }
        else
        {
            Aba_Cadastro(arquivo);
        }
    }
    if(arquivo==2)
    {
        if(Cadastro_usuario()==2)
        {
            MessageBox(0,"CADASTRO REALIZADO COM SUCESSO!","CADASTRO DE USUARIO",0);
        }
        else
        {
            Aba_Cadastro(arquivo);
        }
    }
    if(arquivo==3)
    {
        if(Cadastro_produto()==3)
        {
            MessageBox(0,"CADASTRO REALIZADO COM SUCESSO!","CADASTRO DE PRODUTO",0);
        }
        else
        {
            Aba_Cadastro(arquivo);
        }
    }


}
int Cadastro_funcionario()
{
    TFuncionario funcionario;
    int error=0;

    FILE* p;
    p=fopen("Funcionario","rb");

    if(p==NULL)
    {
        p=fopen("Funcionario","wb");

    }

    gotoxy(40,5);
    printf("NOME:");

    gotoxy(40,7);
    printf("TELEFONE:");

    gotoxy(40,9);
    printf("ENDERECO:");

    gotoxy(40,11);
    printf("SALARIO:");

    gotoxy(40,13);
    printf("USUARIO:");

    gotoxy(40,15);
    printf("SENHA:");

    p=fopen("Funcionario","ab+");

    gotoxy(45,5);
    gets(funcionario.nome);

    if(Consulta_funcionario(funcionario.nome)!=0)
    {
        gotoxy(45,6);
        textcolor(4);
        printf("Funcionario ja cadastrado!");
        textcolor(0);

        Sleep(1000);
        fclose(p);
        return(0);
    }
    else
    {
        funcionario.ativo=1;

           int i,j,x=0;
            do
            {
                if(x>0)
                {
                    gotoxy(49,7);
                    printf("             ");
                }
            //TELEFONE
            j=50;
            for(i=0;i<13;i++)
            {   gotoxy(j,7);
                if(i==0)
                {
                    funcionario.telefone[i]='(';
                }
                else if(i==3)
                {
                    funcionario.telefone[i]=')';
                }
                else
                {

                    funcionario.telefone[i]=getch();
                    if(funcionario.telefone>= 'a' && funcionario.telefone<='Z')
					{
						error++;
					}
                    if(funcionario.telefone[i]==13)
                    {
                        break;
                    }
                    else if(funcionario.telefone[i]==8)
                    {
                        if(i>0)
                        {
                            funcionario.telefone[i]=' ';
                            gotoxy(j,7);
                            printf("%c",funcionario.telefone[i]);
                            i--;
                            if(i==0||i==3)
                            {
                                i--;
                                j--;

                            }
                            funcionario.telefone[i]=' ';
                            gotoxy(j-1,7);
                            printf("%c",funcionario.telefone[i]);

                            i--;
                            j-=2;
                        }
                        else
                        {
                            i--;
                        }
                    }
                    /*else if(funcionario.telefone[i]<30 ||funcionario.telefone[i]>39)
                    {
                        funcionario.telefone[i]=' ';
                        i--;
                        j--;
                    }*/
                }

                if(j>=50)
                {
                    gotoxy(j,7);
                    printf("%c",funcionario.telefone[i]);
                }

                if(j<50)
                {
                    j=50;
                }
                if(i>=0)
                {
                    j++;

                }
                }
                x++;
            }while(!(isdigit(funcionario.telefone[1])&&isdigit(funcionario.telefone[2])
                   &&isdigit(funcionario.telefone[4])&&isdigit(funcionario.telefone[5])&&
                   isdigit(funcionario.telefone[6])&&isdigit(funcionario.telefone[7])&&
                   isdigit(funcionario.telefone[8])&&isdigit(funcionario.telefone[9])&&
                   isdigit(funcionario.telefone[10])&&isdigit(funcionario.telefone[11])&&
                   isdigit(funcionario.telefone[12])));


            fflush(stdin);
            //ENDERE�O
            gotoxy(50,9);
            gets(funcionario.endereco);
            fflush(stdin);

            //SALARIO
            gotoxy(49,11);
            printf("R$");
            gotoxy(51,11);
            char sal_int[5];
            char sal_fl,sal_fl2;

            do
            {
                fflush(stdin);

                gotoxy(51,11);
                printf("             ");

                gotoxy(51,11);

                for(i=0;i<5;i++)
                {
                    sal_int[i]=getch();
                    gotoxy(51+i,11);
                    printf("%c",sal_int[i]);
                }

                gotoxy(56,11);
                printf(".");

                    fflush(stdin);
                    sal_fl=getch();
                    gotoxy(57,11);
                    printf("%c",sal_fl);
                    fflush(stdin);

                    sal_fl2=getch();
                    gotoxy(58,11);
                    printf("%c",sal_fl2);

            }while(!(isdigit(sal_int[0])&&isdigit(sal_int[1])&&
                   isdigit(sal_int[2])&&isdigit(sal_int[3])&&
                   isdigit(sal_int[4])&&isdigit(sal_fl)&&isdigit(sal_fl2)));


                      int inte[5];
                      for(i=0;i<5;i++)
                      {
                          inte[i]=sal_int[i]-48;
                      }
                       int f1=sal_fl-48;
                       int f2=sal_fl2-48;

                   funcionario.salario=inte[0]*10000+inte[1]*1000+inte[2]*100+inte[3]*10+inte[4]+f1*0.1+f2*0.01;

            fflush(stdin);

            //USUARIO
            gotoxy(49,13);
            gets(funcionario.usuario);

            fflush(stdin);

            //SENHA
            gotoxy(49,15);
            gets(funcionario.senha);

            //data de admissao
            funcionario.dia_a=Dia();
            funcionario.mes_a=Mes();
            funcionario.ano_a=Ano();

            fwrite(&funcionario,sizeof(funcionario),1,p);
            fclose(p);

            return(1);
    }


}
int Cadastro_usuario()
{
	TUsuario usuario;
	usuario.dia=Dia();
	usuario.mes=Mes();
	usuario.ano=Ano();
	FILE *p;
	p = fopen("Usuario", "rb");
	if (p == NULL)
	{
		p = fopen("Usuario", "wb");
	}
	gotoxy(40,5);
    printf("NOME:");

    gotoxy(40,7);
    printf("USUARIO:");

    gotoxy(40,9);
    printf("SENHA:");

    gotoxy(40,11);
    printf("PLANOS VIP:");
    gotoxy(40,12);
    printf("[ 1 ] GOLD");
    gotoxy(40,13);
    printf("[ 2 ] PLATINUM");

	p=fopen("Usuario","ab+");


    gotoxy(45,5);
	fflush(stdin);
    gets(usuario.nome);


    if(Consulta_user(usuario.nome)!=0)
    {
        gotoxy(45,6);
        textcolor(4);
        printf("Usuario ja cadastrado!");
        textcolor(0);

        Sleep(1000);
        fclose(p);
        return(0);
    }
    else
	{

            //USUARIO
            gotoxy(49,7);
			fflush(stdin);
		    gets(usuario.usuario);

            //SENHA
            gotoxy(49,9);
			fflush(stdin);
		    gets(usuario.senha);

		    //PLANO

		    do
            {
                gotoxy(52,11);
                printf("     ");
                fflush(stdin);
                gotoxy(52,11);
                scanf("%i",&usuario.assinatura);

            }while(usuario.assinatura!=1&&usuario.assinatura!=2);

		    if(usuario.assinatura==1)
		    {
		    	gotoxy(40,12);
    			printf("          ");
    			gotoxy(40,12);
    			printf("[ X ] GOLD");
    			gotoxy(40,13);
    			printf("[ 2 ] PLATINUM");

			}
			else if(usuario.assinatura==2)
			{

    			gotoxy(40,12);
    			printf("[ 1 ] GOLD");
    			gotoxy(40,13);
    			printf("          ");
    			gotoxy(40,13);
    			printf("[ X ] PLATINUM");

			}


		    usuario.ativo=1;
		    usuario.numero_de_compras=0;

            fwrite(&usuario,sizeof(usuario),1,p);
            fclose(p);
            return(2);
    }
}
int Cadastro_produto()
{
	TProduto produto;
	FILE *p;
	p = fopen("Produto", "rb");
	if (p == NULL)
	{
		p = fopen("Produto", "wb");
	}
	gotoxy(40,5);
    printf("NOME DO PRODUTO:");

    gotoxy(40,7);
    printf("PRECO:");

    gotoxy(40,9);
    printf("GENERO:");

    gotoxy(40,11);
    printf("ANO DE LANCAMENTO:");

    gotoxy(40,13);
    printf("CATEGORIA:");

    gotoxy(40,15);
    printf("CLASSIFICACAO INDICATIVA:");

    gotoxy(40,17);
    printf("DESCRICAO:");

	p=fopen("Produto","ab+");

    gotoxy(57,5);
	fflush(stdin);
    gets(produto.nome);

    if(Consulta_produto(produto.nome)!=0)
    {
        gotoxy(45,6);
        textcolor(4);
        printf("Produto ja cadastrado!");
        textcolor(0);

        Sleep(1000);
        fclose(p);
        return(0);
    }
    else
	{
        gotoxy(48,7);
        fflush(stdin);
        scanf("%f", &produto.preco);

        gotoxy(48,9);
        fflush(stdin);
        gets(produto.genero);

        gotoxy(60,11);
        fflush(stdin);
        scanf("%i", &produto.ano_lancamento);

        gotoxy(52,13);
        fflush(stdin);
        gets(produto.categoria);

        gotoxy(67,15);
        fflush(stdin);
        gets(produto.classificacao_indicativa);

        gotoxy(52,17);
        gets(produto.descricao);
        fflush(stdin);

        produto.quantidade_comprado=0;
        produto.ativo=1;


        fwrite(&produto,sizeof(produto),1,p);
        fclose(p);
        return(3);
	}
}

//ABAS EDITAR
void Editar_Funcionario(fpos_t Byte)
{
    FILE* p;
    TFuncionario funcionario,ativo;
    Byte=Byte-sizeof(funcionario);

    bool button1=true,button2=true,button3=true,button4=true,entra=false;
    int ativado=0;


    POINT Coordenadas;
    char resp;
    int i,j;
    int y=5;
    textbackground(15);
    textcolor(8);
    gotoxy(39,y);
    printf("%c",175);
    int error=0;
    p=fopen("Funcionario","rb+");
    fsetpos(p,&Byte);
    fread(&funcionario,sizeof(funcionario),1,p);
    do
    {
        GetCursorPos(&Coordenadas);
        if(kbhit())
        {
            resp=getch();

            textbackground(15);

            if(resp==72)
            {
                gotoxy(39,y);
                printf(" ");
                y-=2;
                if(y<5)
                {
                    y=15;
                }

            }
            else if(resp==80)
            {
                gotoxy(39,y);
                printf(" ");
                y+=2;
                if(y>15)
                {
                    y=5;
                }
            }

            gotoxy(39,y);
            printf("%c",175);

        }



        if(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>150&&Coordenadas.y<220)
        {
            if(ativado==0)
            {
                Quadro_colorido(8,95,118,5,8);
                gotoxy(99,6);
                textcolor(15);
                printf("DESATIVAR/ATIVAR");
            }
            button1=true;
            ativado++;
            if(resp==13)
            {
                textbackground(15);
                textcolor(8);

                if(funcionario.ativo==1)
                {

                    funcionario.ativo=0;


                    gotoxy(52,21);
                    printf("DESATIVO");
                }
                else
                {
                    funcionario.ativo=1;
                    gotoxy(52,21);
                    printf("           ");
                    gotoxy(52,21);
                    printf("ATIVO");
                }
                resp=' ';

            }

        }
        else if(button1)
        {
            button1=false;
            Quadro_colorido(7,95,118,5,8);
            gotoxy(99,6);
            textcolor(8);
            printf("DESATIVAR/ATIVAR");
            ativado=0;
        }
        if(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>270&&Coordenadas.y<340)
        {
            if(ativado==0)
            {
                Quadro_colorido(8,95,118,10,13);
                gotoxy(102,11);
                textcolor(15);
                printf("SALVAR");
            }
            button2=true;
            ativado++;

            if(resp==13)
            {
                entra=true;
                resp=' ';
                break;
            }

        }
        else if(button2)
        {
            button2=false;
            Quadro_colorido(7,95,118,10,13);
            gotoxy(102,11);
            textcolor(8);
            printf("SALVAR");
            ativado=0;
        }

        if(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>390&&Coordenadas.y<450)
        {
            if(ativado==0)
            {
                Quadro_colorido(8,95,118,15,18);
                gotoxy(102,16);
                textcolor(15);
                printf("RETORNAR");

            }
            button3=true;
            ativado++;
            if(resp==13)
            {
                Aba_Resultado(Byte,1,Byte);
                resp=' ';
                break;
            }

        }
        else if(button3)
        {
            button3=false;
            Quadro_colorido(7,95,118,15,18);
            gotoxy(102,16);
            textcolor(8);
            printf("RETORNAR");
            ativado=0;
        }

        if(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>510&&Coordenadas.y<580)
        {
            if(ativado==0)
            {
                Quadro_colorido(8,95,118,20,23);
                gotoxy(100,21);
                textcolor(15);
                printf("MENU PRINCIPAL");
            }
            button4=true;
            ativado++;
            if(resp==13)
            {
                resp=' ';
                Area_de_Trabalho();
                break;
            }

        }
        else if(button4)
        {
            button4=false;
            Quadro_colorido(7,95,118,20,23);
            gotoxy(100,21);
            textcolor(8);
            printf("MENU PRINCIPAL");
            ativado=0;
        }


    if(resp==13)
    {
        if(y==5)
        {
            gotoxy(45,5);
            gets(funcionario.nome);
        }
        else if(y==7)
        {
             //TELEFONE
            j=50;
            for(i=0;i<13;i++)
            {   gotoxy(j,7);
                if(i==0)
                {
                    funcionario.telefone[i]='(';
                }
                else if(i==3)
                {
                    funcionario.telefone[i]=')';
                }
                else
                {

                    funcionario.telefone[i]=getch();
                    if(funcionario.telefone>= 'a' && funcionario.telefone<='Z')
					{
						error++;
					}
                    if(funcionario.telefone[i]==13)
                    {
                        break;
                    }
                    else if(funcionario.telefone[i]==8)
                    {
                        if(i>0)
                        {
                            funcionario.telefone[i]=' ';
                            gotoxy(j,7);
                            printf("%c",funcionario.telefone[i]);
                            i--;
                            if(i==0||i==3)
                            {
                                i--;
                                j--;

                            }
                            funcionario.telefone[i]=' ';
                            gotoxy(j-1,7);
                            printf("%c",funcionario.telefone[i]);

                            i--;
                            j-=2;
                        }
                        else
                        {
                            i--;
                        }
                    }
                    /*else if(funcionario.telefone[i]<30 ||funcionario.telefone[i]>39)
                    {
                        funcionario.telefone[i]=' ';
                        i--;
                        j--;
                    }*/
                }

                if(j>=50)
                {
                    gotoxy(j,7);
                    printf("%c",funcionario.telefone[i]);
                }

                if(j<50)
                {
                    j=50;
                }
                if(i>=0)
                {
                    j++;

                }
                }


            fflush(stdin);

        }

        else if(y==9)
        {   //ENDERE�O
            gotoxy(50,9);
            gets(funcionario.endereco);
            fflush(stdin);

        }
        else if(y==11)
        {
             //SALARIO
            gotoxy(49,11);
            printf("R$");
            gotoxy(51,11);
            scanf("%f",&funcionario.salario);
            fflush(stdin);
        }

        else if(y==13)
        {
             //USUARIO
            gotoxy(49,13);
            gets(funcionario.usuario);

            fflush(stdin);
        }

        else if(y==15)
        {
            //SENHA
            gotoxy(49,15);
            gets(funcionario.senha);
        }
    }


        resp=' ';
    }while(1);

    if(entra)
    {
        fsetpos(p,&Byte);
        fwrite(&funcionario,sizeof(funcionario),1,p);
    }
    fclose(p);

}
void Editar_Usuario(fpos_t Byte)
{
    FILE* p;
    TUsuario usuario;
    Byte=Byte-sizeof(usuario);

    bool button1=true,button2=true,button3=true,button4=true,entra=false;
    int ativado=0;


    POINT Coordenadas;
    char resp;
    int i,j;
    int y=6;

    Quadro_colorido(15,40,90,10,16);
    textcolor(8);

    gotoxy(39,y);
    printf("%c",175);

    p=fopen("Usuario","rb+");
    fsetpos(p,&Byte);
    fread(&usuario,sizeof(usuario),1,p);


    gotoxy(40,10);
    printf("SENHA: %s",usuario.senha);

    gotoxy(40,15);
    if(usuario.ativo==1)
    {
        printf("USUARIO ATIVO");
    }
    else
    {
        printf("USUARIO DESATIVO");
    }
    int renovar;
    renovar=usuario.assinatura;
    if(usuario.ano>=usuario.ano+1)
    {
    	renovar=0;
	}
    gotoxy(40,12);
    printf("PLANOS VIP:");
    gotoxy(40,13);
    printf("[ 1 ] GOLD");
    gotoxy(40,14);
    printf("[ 2 ] PLATINUM");


    do
    {
        GetCursorPos(&Coordenadas);
        if(kbhit())
        {
            resp=getch();
            textbackground(15);

            if(resp==72)
            {
                gotoxy(39,y);
                printf(" ");
                y-=2;
                if(y<6)
                {
                    y=12;
                }

            }
            else if(resp==80)
            {
                gotoxy(39,y);
                printf(" ");
                y+=2;
                if(y>12)
                {
                    y=6;
                }
            }

            gotoxy(39,y);
            printf("%c",175);
        }




        if(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>150&&Coordenadas.y<220)
        {
            if(ativado==0)
            {
                Quadro_colorido(8,95,118,5,8);
                gotoxy(99,6);
                textcolor(15);
                printf("DESATIVAR/ATIVAR");
            }
            button1=true;
            ativado++;
            if(resp==13)
            {
                textbackground(15);
                textcolor(8);

                if(usuario.ativo==1)
                {
                    usuario.ativo=0;


                    gotoxy(40,15);
                    printf("USUARIO DESATIVO");
                }
                else
                {
                    usuario.ativo=1;
                    gotoxy(40,15);
                    printf("                ");
                    gotoxy(40,15);
                    printf("USUARIO ATIVO");
                }
                resp=' ';

            }



        }
        else if(button1)
        {
            button1=false;
            Quadro_colorido(7,95,118,5,8);
            gotoxy(99,6);
            textcolor(8);
            printf("DESATIVAR/ATIVAR");
            ativado=0;
        }
        if(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>270&&Coordenadas.y<340)
        {
            if(ativado==0)
            {
                Quadro_colorido(8,95,118,10,13);
                gotoxy(102,11);
                textcolor(15);
                printf("SALVAR");
            }
            button2=true;
            ativado++;

            if(resp==13)
            {
                entra=true;
                resp=' ';
                break;
            }

        }
        else if(button2)
        {
            button2=false;
            Quadro_colorido(7,95,118,10,13);
            gotoxy(102,11);
            textcolor(8);
            printf("SALVAR");
            ativado=0;
        }

        if(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>390&&Coordenadas.y<450)
        {
            if(ativado==0)
            {
                Quadro_colorido(8,95,118,15,18);
                gotoxy(102,16);
                textcolor(15);
                printf("RETORNAR");

            }
            button3=true;
            ativado++;
            if(resp==13)
            {
                Aba_Resultado(Byte,1,Byte);
                resp=' ';
                break;
            }

        }
        else if(button3)
        {
            button3=false;
            Quadro_colorido(7,95,118,15,18);
            gotoxy(102,16);
            textcolor(8);
            printf("RETORNAR");
            ativado=0;
        }

       if(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>510&&Coordenadas.y<580)
        {
            if(ativado==0)
            {
                Quadro_colorido(8,95,118,20,23);
                gotoxy(100,21);
                textcolor(15);
                printf("MENU PRINCIPAL");
            }
            button4=true;
            ativado++;
            if(resp==13)
            {
                resp=' ';
                Area_de_Trabalho();
                break;
            }

        }
        else if(button4)
        {
            button4=false;
            Quadro_colorido(7,95,118,20,23);
            gotoxy(100,21);
            textcolor(8);
            printf("MENU PRINCIPAL");
            ativado=0;
        }

        if(resp==13 &&(!(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>150&&Coordenadas.y<220)&&
                       !(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>270&&Coordenadas.y<340)&&
                       !(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>390&&Coordenadas.y<450)&&
                       !(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>510&&Coordenadas.y<580)))
        {
            if(y==6)
            {
                gotoxy(46,y);
                gets(usuario.nome);
            }
            else if(y==8)
            {
                gotoxy(49,y);
                gets(usuario.usuario);
            }
            else if(y==10)
            {
                gotoxy(47,y);
                gets(usuario.senha);
            }
            else if(y==12)
            {
            	gotoxy(52,12);
				fflush(stdin);
				scanf("%i",&usuario.assinatura);

				    if(usuario.assinatura==1)
				    {
				    	gotoxy(40,13);
		    			printf("          ");
		    			gotoxy(40,13);
		    			printf("[ X ] GOLD");
		    			gotoxy(40,14);
		    			printf("[ 2 ] PLATINUM");
					}
					else if(usuario.assinatura==2)
					{

		    			gotoxy(40,13);
		    			printf("[ 1 ] GOLD");
		    			gotoxy(40,14);
		    			printf("          ");
		    			gotoxy(40,14);
		    			printf("[ X ] PLATINUM");
						}

				}


        }

        resp=' ';
    }while(1);

    if(entra)
    {
        fsetpos(p,&Byte);
        fwrite(&usuario,sizeof(usuario),1,p);
    }
    fclose(p);
}
void Editar_Produto(fpos_t Byte)
{
    FILE* p;
    TProduto produto;
    Byte=Byte-sizeof(produto);

    bool button1=true,button2=true,button3=true,button4=true,entra=false;
    int ativado=0;


    POINT Coordenadas;
    char resp;
    int i,j;
    int y=6;

    textcolor(8);

    gotoxy(39,y);
    printf("%c",175);

    p=fopen("Produto","rb+");
    fsetpos(p,&Byte);
    fread(&produto,sizeof(produto),1,p);



    do
    {
        GetCursorPos(&Coordenadas);
        if(kbhit())
        {
            resp=getch();
            textbackground(15);

            if(resp==72)
            {
                gotoxy(39,y);
                printf(" ");
                y-=2;
                if(y<6)
                {
                    y=18;
                }

            }
            else if(resp==80)
            {
                gotoxy(39,y);
                printf(" ");
                y+=2;
                if(y>18)
                {
                    y=6;
                }
            }

            gotoxy(39,y);
            printf("%c",175);
        }




        if(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>150&&Coordenadas.y<220)
        {
            if(ativado==0)
            {
                Quadro_colorido(8,95,118,5,8);
                gotoxy(99,6);
                textcolor(15);
                printf("DESATIVAR/ATIVAR");
            }
            button1=true;
            ativado++;
            if(resp==13)
            {
                textbackground(15);
                textcolor(8);

                if(produto.ativo==1)
                {
                    produto.ativo=0;


                    gotoxy(40,10);
                    printf("PRODUTO DESATIVO");
                }
                else
                {
                    produto.ativo=1;
                    gotoxy(40,10);
                    printf("                ");
                    gotoxy(40,10);
                    printf("PRODUTO ATIVO");
                }
                resp=' ';

            }



        }
        else if(button1)
        {
            button1=false;
            Quadro_colorido(7,95,118,5,8);
            gotoxy(99,6);
            textcolor(8);
            printf("DESATIVAR/ATIVAR");
            ativado=0;
        }
        if(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>270&&Coordenadas.y<340)
        {
            if(ativado==0)
            {
                Quadro_colorido(8,95,118,10,13);
                gotoxy(102,11);
                textcolor(15);
                printf("SALVAR");
            }
            button2=true;
            ativado++;

            if(resp==13)
            {
                entra=true;
                resp=' ';
                break;
            }

        }
        else if(button2)
        {
            button2=false;
            Quadro_colorido(7,95,118,10,13);
            gotoxy(102,11);
            textcolor(8);
            printf("SALVAR");
            ativado=0;
        }

        if(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>390&&Coordenadas.y<450)
        {
            if(ativado==0)
            {
                Quadro_colorido(8,95,118,15,18);
                gotoxy(102,16);
                textcolor(15);
                printf("RETORNAR");

            }
            button3=true;
            ativado++;
            if(resp==13)
            {
                Aba_Resultado(Byte,1,Byte);
                resp=' ';
                break;
            }

        }
        else if(button3)
        {
            button3=false;
            Quadro_colorido(7,95,118,15,18);
            gotoxy(102,16);
            textcolor(8);
            printf("RETORNAR");
            ativado=0;
        }

        if(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>510&&Coordenadas.y<580)
        {
            if(ativado==0)
            {
                Quadro_colorido(8,95,118,20,23);
                gotoxy(100,21);
                textcolor(15);
                printf("MENU PRINCIPAL");
            }
            button4=true;
            ativado++;
            if(resp==13)
            {
                resp=' ';
                Area_de_Trabalho();
                break;
            }

        }
        else if(button4)
        {
            button4=false;
            Quadro_colorido(7,95,118,20,23);
            gotoxy(100,21);
            textcolor(8);
            printf("MENU PRINCIPAL");
            ativado=0;
        }

        if(resp==13 &&(!(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>150&&Coordenadas.y<220)&&
                       !(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>270&&Coordenadas.y<340)&&
                       !(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>390&&Coordenadas.y<450)&&
                       !(Coordenadas.x>1050&&Coordenadas.x<1300 &&Coordenadas.y>510&&Coordenadas.y<580)))
        {
                 if(y==6)
            {
                gotoxy(57,y);
                gets(produto.nome);
            }
            else if(y==8)
            {
                gotoxy(49,y);
                scanf("%f",&produto.preco);
            }

              else if(y==8)
            {
                gotoxy(49,y);
                gets(produto.categoria);
            }

              else if(y==10)
            {
                gotoxy(49,y);
                gets( produto.genero);
            }

              else if(y==12)
            {
                gotoxy(49,y);
                scanf("%i",& produto.ano_lancamento);
            }

              else if(y==14)
            {
                gotoxy(49,y);
                gets(produto.classificacao_indicativa);
            }
              else if(y==16)
            {
                gotoxy(49,y);
                scanf("%f",&produto.preco);
            }
              else if(y==18)
            {
                gotoxy(49,y);
                gets(produto.descricao);
            }


        }

        resp=' ';
    }while(1);

    if(entra)
    {
        fsetpos(p,&Byte);
        fwrite(&produto,sizeof(produto),1,p);
    }
    fclose(p);
}
void Compra_Usuario(fpos_t Byte)
{
    FILE* p;
    TUsuario usuario;
    Byte=Byte-sizeof(usuario);

    p=fopen("Usuario", "rb+");

    fsetpos(p,&Byte);
    fread(&usuario,sizeof(usuario),1,p);

    usuario.numero_de_compras++;

    fsetpos(p,&Byte);
    fwrite(&usuario,sizeof(usuario),1,p);
    fclose(p);
}
int Comprar_produto(fpos_t Byte, fpos_t ByteUsuario)
{
    FILE* p;//produto
    TProduto produto;
	//produto
    Byte=Byte-sizeof(produto);
    p=fopen("Produto","rb+");
    fsetpos(p,&Byte);
    fread(&produto,sizeof(produto),1,p);
    produto.quantidade_comprado++;
	float compra = produto.preco;

    //desconto//usuario
    FILE* p1;//usuario
    TUsuario usuario;
   	float desconto=0.0;//usuario
	ByteUsuario=ByteUsuario-sizeof(usuario);
    p1=fopen("Usuario", "rb");
    fsetpos(p1,&ByteUsuario);
    fread(&usuario,sizeof(usuario),1,p1);
	if(usuario.assinatura==1)
	{
		desconto=compra*0.25;
		compra-=desconto;
	}
	else if(usuario.assinatura==2)
	{

		desconto=compra*0.50;
		compra-=desconto;
	}
	//produto
    Financeiro_entrada(&compra);
    Byte=Byte-sizeof(produto);
    fsetpos(p,&Byte);

    fwrite(&produto,sizeof(produto),1,p);
    fclose(p);
    fclose(p1);

}

//FINANCEIRO
void FINANCEIRO()
{
    system("cls");
    Janela();
    system("Color 3F");
    Logo(5,4);
    gotoxy(60,2);
    printf("FINANCEIRO");

    textcolor(8);

    int i,j=15,x=2;

    Financeiro_lucro();
    //grafico
    {
    Quadro_colorido(15,32,97,4,18);
    gotoxy(32,4);
    printf("LUCRO");
    for(i=0;i<=1000;i=i+100)
    {   gotoxy(32,j);
        printf("%i",i);
        gotoxy(36,j--);
        printf("|");
    }
    i=1;

    for(j=37;j<=95;j++)
    {

        x++;
        if(x==5)
        {
            gotoxy(j,16);
            printf("%i",i++);
            x=0;
        }
        gotoxy(j,15);
        printf("_");


    }

        Grafico();

        gotoxy(62,17);
        printf("MESES");
    }

    //RESUMO DO M�S
    {
        Quadro_colorido(15,99,117,4,18);
        gotoxy(101,4);
        printf("RESUMO DO MES");
        Resumo_do_Mes();
    }

    //itens mais vendidos
    {
        Quadro_colorido(15,32,58,19,26);
        gotoxy(35,19);
        printf("ITENS MAIS VENDIDOS");
        Itens_mais_vendidos();
    }
    //assinaturas mais populares
    {
        Quadro_colorido(15,60,90,19,26);
        gotoxy(62,19);
        printf("ASSINATURAS POPULARES");
        Top_Assinatura();
    }
    //CLIENTES VIP
    {
        Quadro_colorido(15,92,117,19,26);
        gotoxy(98,19);
        printf("CLIENTES VIP");
        Clientes_VIP();
    }

//BOTAO PARA RETORNAO AO MENU PRINCIPAL
    bool fecha=true,ativo=true;
    char resp;

    POINT Coordenadas;
    do
    {
        GetCursorPos(&Coordenadas);

        if(kbhit())
        {
            resp=getch();
        }

        if(Coordenadas.x>60 &&Coordenadas.x<333 &&Coordenadas.y>534&&Coordenadas.y<603)
        {
            if(!ativo)
            {
                Quadro_colorido(8,5,30,21,24);
                textcolor(15);
                gotoxy(13,22);
                printf("RETORNAR");
                ativo=true;
            }
            if(resp==13)
            {
                resp=' ';
                fecha=false;
                break;
            }


        }
        else if(ativo)
        {//botao retornar
            Quadro_colorido(7,5,30,21,24);
            textcolor(8);
            gotoxy(13,22);
            printf("RETORNAR");
            ativo=false;

        }
        resp=' ';
    }while(fecha);





    gotoxy(0,0);
}
void Itens_mais_vendidos()
{
    FILE* p,*t;
    TProduto produto,vendidos;
    p=fopen("Produto","rb");

    fpos_t Byte,Reg;

    int maior1=0,maior2=0,maior3=0, Reg1=0,Reg2=0;
    if(p!=NULL)
    {
        while(!feof(p))
        {
            fread(&produto,sizeof(produto),1,p);
            if(produto.ativo==1&&produto.quantidade_comprado>maior1)
            {
                maior1=produto.quantidade_comprado;
                fgetpos(p,&Byte);

            }
        }

        if(maior1>0)
        {
            Reg1=Byte=Byte-sizeof(produto);
            fsetpos(p,&Byte);
            fread(&produto,sizeof(produto),1,p);

            gotoxy(33,21);
            printf("1- %s",produto.nome);

                rewind(p);
                while(!feof(p))
                {
                    fread(&produto,sizeof(produto),1,p);
                    if(produto.ativo==1&&produto.quantidade_comprado>maior2)
                    {
                        fgetpos(p,&Reg);
                        Reg=Reg-sizeof(produto);

                        if(Reg!=Reg1)
                        {
                            maior2=produto.quantidade_comprado;
                            fgetpos(p,&Byte);
                            Reg2=Byte=Byte-sizeof(produto);
                        }

                    }

                }

            if(maior2>0)
            {
                fsetpos(p,&Byte);
                fread(&produto,sizeof(produto),1,p);
                gotoxy(33,23);
                printf("2- %s",produto.nome);

                    rewind(p);
                    while(!feof(p))
                    {
                        fread(&produto,sizeof(produto),1,p);
                        if(produto.ativo==1&&produto.quantidade_comprado>maior3)
                        {
                            fgetpos(p,&Reg);
                            Reg=Reg-sizeof(produto);

                            if(Reg!=Reg1 &&Reg!=Reg2)
                            {
                                maior3=produto.quantidade_comprado;
                                fgetpos(p,&Byte);
                            }
                        }
                    }
                    if(maior3>0)
                    {
                        Byte=Byte-sizeof(produto);
                        fsetpos(p,&Byte);
                        fread(&produto,sizeof(produto),1,p);

                        gotoxy(33,25);
                        printf("3- %s",produto.nome);
                    }

                }
        }

    }
    else
    {
        gotoxy(33,21);
        printf("Nenhum item vendido");
    }
fclose(p);

}
void Clientes_VIP()
{
    FILE* p;
    fpos_t Byte,Reg;
    int maior1=0,maior2=0,maior3=0,Reg1,Reg2;

    TUsuario cliente;

    p=fopen("Usuario","rb");
    if(p!=NULL)
    {
        while(!feof(p))
        {
            fread(&cliente, sizeof(cliente),1,p);
            if(cliente.ativo==1&&cliente.numero_de_compras>maior1)
            {
                maior1=cliente.numero_de_compras;
                fgetpos(p,&Byte);
                Reg1=Byte=Byte-sizeof(cliente);
            }
        }

            if(maior1>0)
            {
                fsetpos(p,&Byte);
                fread(&cliente,sizeof(cliente),1,p);

                gotoxy(95,21);
                printf("1- %s",cliente.nome);


                rewind(p);
                while(!feof(p))
                {
                    fread(&cliente, sizeof(cliente),1,p);
                    if(cliente.ativo==1&&cliente.numero_de_compras>maior2)
                    {
                        fgetpos(p,&Reg);
                        Reg=Reg-sizeof(cliente);

                        if(Reg!=Reg1)
                        {
                            maior2=cliente.numero_de_compras;
                            fgetpos(p,&Byte);
                            Reg2=Byte=Byte-sizeof(cliente);
                        }

                    }
                }

                if(maior2>0)
                {
                    fsetpos(p,&Byte);
                    fread(&cliente,sizeof(cliente),1,p);

                    gotoxy(95,23);
                    printf("2- %s",cliente.nome);


                    rewind(p);
                    while(!feof(p))
                    {
                        fread(&cliente, sizeof(cliente),1,p);
                        if(cliente.ativo==1&&cliente.numero_de_compras>maior3)
                        {
                            fgetpos(p,&Reg);
                            Reg=Reg-sizeof(cliente);

                            if(Reg!=Reg1 && Reg!=Reg2)
                            {
                                maior3=cliente.numero_de_compras;
                                fgetpos(p,&Byte);
                                Byte=Byte-sizeof(cliente);
                            }

                        }
                    }

                    if(maior3>0)
                    {
                        fsetpos(p,&Byte);
                        fread(&cliente,sizeof(cliente),1,p);

                        gotoxy(95,25);
                        printf("3- %s",cliente.nome);
                    }
                }
            }
            else
            {
                gotoxy(95,21);
                printf("Nao ha clientes VIP");
            }
    }
    fclose(p);
}
void Financeiro_entrada(float *compra)
{

    FILE *p;
    fpos_t Byte;
    TRelatorio relatorio;

    int ano=Ano();
    char year[4];
    itoa(ano,year,10);



    p=fopen(year,"rb+");
    fseek(p, -sizeof(relatorio), SEEK_END);

    fread(&relatorio,sizeof(relatorio),1,p);
    gotoxy(40,2);

    relatorio.entrada=relatorio.entrada+*compra;

    fseek(p, -sizeof(relatorio), SEEK_END);
    fwrite(&relatorio,sizeof(relatorio),1,p);
    fclose(p);
}
void Financeiro_saida_entrada_mensal()
{
    FILE *p,*t;
    fpos_t Byte;
    TRelatorio relatorio;
    TFuncionario funcionario;
    TUsuario usuario;
    int ano=Ano();
    char year[4];
    itoa(ano,year,10);


    p=fopen(year,"rb+");

    fseek(p,-sizeof(relatorio), SEEK_END);
    fread(&relatorio,sizeof(relatorio),1,p);

    if(relatorio.dia<1)
            {
               t=fopen("Funcionario","rb");
                while(!feof(t))
                {
                    fread(&funcionario,sizeof(funcionario),1,t);
                    if(funcionario.ativo==1)
                    {
                        relatorio.saida+=funcionario.salario;
                    }
                }
                relatorio.saida=relatorio.saida/2;
                relatorio.dia++;
                fclose(t);

                t=fopen("Usuario","rb");
                while(!feof(t))
                {
                    fread(&usuario,sizeof(usuario),1,t);
                    if(usuario.ativo==1&&usuario.assinatura==1)
                    {
                        relatorio.entrada+=70;
                    }
                    if(usuario.ativo==1&&usuario.assinatura==2)
                    {
                        relatorio.entrada+=120;
                    }
                }
                relatorio.entrada=relatorio.entrada/2;

                fclose(t);

                fseek(p, -sizeof(relatorio), SEEK_END);
                fwrite(&relatorio,sizeof(relatorio),1,p);
            }

    fclose(p);
}
void Resumo_do_Mes()
{
    FILE*p;
    TRelatorio relatorio;
    int ano=Ano();
    char year[4];
    itoa(ano,year,10);


    p=fopen(year,"rb");
        fseek(p,-sizeof(relatorio),SEEK_END);
        fread(&relatorio,sizeof(relatorio),1,p);
        textcolor(8);
            gotoxy(100,6);
            printf("ENTRADA");
            gotoxy(100,8);
            printf("R$%.2f",relatorio.entrada);
            gotoxy(100,10);
            printf("SAIDA");
            gotoxy(100,12);
            printf("R$%.2f",relatorio.saida);
            gotoxy(100,14);
            printf("LUCRO");
            gotoxy(100,16);
            printf("R$%.2f",relatorio.lucro);

    fclose(p);

}
void Grafico()
{
    FILE*p;
    TRelatorio relatorio;
    int ano=Ano();
    char year[4];
    itoa(ano,year,10);

    int j,i=39,x;

    p=fopen(year,"rb");
    while(!feof(p))
    {
        fread(&relatorio,sizeof(relatorio),1,p);
        if(relatorio.lucro>0)
        {
            x=15-(relatorio.lucro/100);

            if(x<5)
            {
                x=5;
            }
            for(j=15;j>=x;j--)
            {
                gotoxy(i,j);
                printf("%c",219);
            }
        }

        i+=5;

    }
    fclose(p);
}
void Financeiro_lucro()
{
    FILE *p,*t;
    fpos_t Byte;
    TRelatorio relatorio;
    int ano=Ano();
    char year[4];
    itoa(ano,year,10);


    p=fopen(year,"rb+");

    fseek(p, -sizeof(relatorio), SEEK_END);
    fread(&relatorio,sizeof(relatorio),1,p);
    relatorio.lucro=relatorio.entrada-relatorio.saida;
                if(relatorio.lucro<0)
                {
                    relatorio.lucro=0;
                }
                fgetpos(p,&Byte);
                Byte-=sizeof(relatorio);
                fsetpos(p,&Byte);
                fwrite(&relatorio,sizeof(relatorio),1,p);
    /*while(!feof(p))
    {
        fread(&relatorio,sizeof(relatorio),1,p);
            if(relatorio.mes==Mes())
            {
                relatorio.lucro=relatorio.entrada-relatorio.saida;
                if(relatorio.lucro<0)
                {
                    relatorio.lucro=0;
                }
                fgetpos(p,&Byte);
                Byte-=sizeof(relatorio);
                fsetpos(p,&Byte);
                fwrite(&relatorio,sizeof(relatorio),1,p);
            }
    }*/


    fclose(p);
}
void Top_Assinatura()
{
	FILE* p;
    fpos_t Byte,Reg;
    TUsuario usuario;

    int Gold=0,Platinum=0;

    p=fopen("Usuario","rb");
    if(p!=NULL)
    {
        while(!feof(p))
        {
            fread(&usuario,sizeof(usuario),1,p);
            if(usuario.ativo==1 &&usuario.assinatura==1)
            {
                Gold++;

            } if(usuario.ativo==1 &&usuario.assinatura==2)
            {
                Platinum++;

            }
        }
            if(Gold>Platinum)
            {
                gotoxy(62,21);
                printf("1- GOLD");
                gotoxy(62,22);
                printf("2- PLATINUM");

            }
            else if(Gold<Platinum)
            {
                gotoxy(62,21);
                printf("1- PLATINUM");
                gotoxy(62,22);
                printf("2- GOLD");
            }
            else
            {
            	gotoxy(62,21);
            	printf("1- GOLDINUM(GOLD/PLATINUM)");

			}
    }
    fclose(p);
}
//Define o tamanho da tela com chamada do sistema
void redefine(void){
    system("color 3F"); //Padroniza a cor do sistema.
    system("MODE con cols=123 lines=28"); //Redimensiona a tela
    system("title STEAM - by: LGMT"); //D� t�tulo a tela
    {//MAXIMIXA A TELA ( APERTA NO TECLADO O ALT+ESPACO+X)
    keybd_event ( VK_MENU, 0x38, 0, 0 );
    keybd_event ( VK_SPACE, 0x39, 0, 0 );
    keybd_event(0x58,0,0,0);
    keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );
    keybd_event ( VK_SPACE, 0x39, KEYEVENTF_KEYUP, 0 );
    keybd_event(0x58,0,KEYEVENTF_KEYUP,0);
    }
}
//PEGA O DIA MES E ANO EM QUE O USUARIO
void Data(){

   int dia,mes,ano1;
   struct tm *local;
   time_t t;

   t = time(NULL);
   local = localtime(&t);

   dia = local -> tm_mday;
   mes = local -> tm_mon + 1;
   ano1 = local -> tm_year + 1900;

   //criar o arquivo do ano pra usar no relatorio mensal
   FILE *p,*n;
   TRelatorio relatorio,novo;

    char ano[4];
// convert int to string
    itoa(ano1, ano, 10);

   p=fopen(ano,"rb");
   if(p==NULL)
   {

       p=fopen(ano,"wb");

       int i=1,year;


            char year1[4];
            year=ano1-1;
            itoa(year,year1,10);

            fpos_t Byte;

            n=fopen(year1,"rb");
            if(n!=NULL)
            {
                fseek(n, -sizeof(relatorio), SEEK_END);
                fread(&relatorio,sizeof(relatorio),1,n);
                for(i=1;i<=mes;i++)
                {
                    novo.mes=i;
                    novo.dia=0;
                    novo.lucro=novo.entrada=0;
                    novo.saida=relatorio.saida;

                    fwrite(&novo,sizeof(novo),1,p);
                }
            }
            else
            {
                while(i<=Mes())
                {
                    novo.mes=i;
                    novo.dia=0;
                    novo.lucro=novo.entrada=0;
                    novo.saida=0;
                    fwrite(&novo,sizeof(novo),1,p);
                    i++;
                }
            }
            fclose(n);
            fclose(p);

   }
   else
   {
       //procura no arquivo se ja existe dados salvos do mes em q o usuario est� entrando
       p=fopen(ano,"rb");
       bool achou=false;

        fseek(p, -sizeof(relatorio), SEEK_END);
        fread(&relatorio,sizeof(relatorio),1,p);
       if(relatorio.mes==Mes())
           {
               achou=true;
           }

       if(!achou)
       {
               p=fopen(ano,"ab+");

               int diferenca,i;

               diferenca=Mes()-relatorio.mes;

               for(i=1;i<=diferenca;i++)
               {
                   novo.mes=relatorio.mes+i;
                   novo.lucro=novo.entrada=0;
                   novo.saida=relatorio.saida;
                   novo.dia=0;

                   fwrite(&novo,sizeof(novo),1,p);
               }
       }
       fclose(p);
   }
}
int Mes(void){

   int dia,mes,ano1;
   struct tm *local;
   time_t t;

   t = time(NULL);
   local = localtime(&t);

   dia = local -> tm_mday;
   mes = local -> tm_mon + 1;
   ano1 = local -> tm_year + 1900;

   return(mes);
}
int Ano(void){

   int dia,mes,ano;
   struct tm *local;
   time_t t;

   t = time(NULL);
   local = localtime(&t);

   dia = local -> tm_mday;
   mes = local -> tm_mon + 1;
   ano = local -> tm_year + 1900;

   return(ano);
}
int Dia(void){

   int dia,mes,ano;
   struct tm *local;
   time_t t;

   t = time(NULL);
   local = localtime(&t);

   dia = local -> tm_mday;
   mes = local -> tm_mon + 1;
   ano = local -> tm_year + 1900;

   return(dia);
}

int main()
{
    redefine();

    FILE*p;
    p=fopen("Funcionario","rb");
    fclose(p);
    if(p==NULL)
    {
        if(MessageBox(0,"\t\t               BEM VINDO AO PROGRAMA!\n\nAntes de come�ar a utiliza-lo � necessario que leia atentamente e aceite os termos abaixo.\n"
                      "\n1-Para utilizar o programa � necess�rio que o cmd esteja configurado com a fonte consolas tamanho 24 e esteja em janela maximizada posicionada no topo esquerdo da tela;"
"\n\n2-Para navegar no menu principal faz-se necess�rio o uso do mouse e a tecla <ENTER> para escolher a op��o desejada, no menu de edi��o � utilizado tamb�m as setas direcionais do teclado;"
"\n\n3-Ao aceitar os termos de uso ser� necess�rio o cadastro para prosseguir com a utiliza��o;"
		"\n\t   Ao aceitar, voc� concorda com todos os termos acima.","TERMOS DE USO",4)==6)
        {   //pra cadastrar o admin quando usa pela primeira vez
            Aba_Cadastro(1);
            p = fopen("Usuario", "wb");
            main();
        }
        else
        {
            exit(0);
        }
    }
    else
    {
       // Tela_de_Carregamento();

        //Login();
     //   Data();
        //Financeiro_saida_entrada_mensal();
        Area_de_Trabalho();

        char *test = "12.11";
 double temp = strtod(test,NULL);
 float ftemp = atof(test);
 printf("price: %f, %f",temp,ftemp);
    }

}
