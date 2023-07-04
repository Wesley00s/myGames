#include <stdio.h>

int main()
{

    printf("\nCAMPO MINADO\nDesafio: chegar aos 200 pontos\nErros custam 20pts\nAcertos somam 5pts\nPREPARADO? VOCÊ COMEÇA COM 100 VIDAS\n\n");
    printf("\n================== | VIDAS: 100 | ==================\n");

    printf("\n=    0    1    2    3    4    5    6    7    8    9\n");
    printf("\n 0  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]\n");
    printf("\n 1  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]\n");
    printf("\n 2  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]\n");
    printf("\n 3  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]\n");
    printf("\n 4  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]\n");
    printf("\n 5  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]\n");
    printf("\n 6  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]\n");
    printf("\n 7  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]\n");
    printf("\n 8  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]\n");
    printf("\n 9  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]  [ ]\n");

    printf("\n[O] = aberto\n[X] = minas abertas\n[ ] = disponíveis para abrir\n");

    int posicao[10][10] = {0}, escolhaLi = 0, escolhaCol = 0, pontos = 100;
    char opcao;

    posicao[0][5] = 1;
    posicao[1][1] = 1;
    posicao[1][7] = 1;
    posicao[2][0] = 1;
    posicao[2][2] = 1;
    posicao[2][4] = 1;
    posicao[2][9] = 1;
    posicao[4][2] = 1;
    posicao[4][6] = 1;
    posicao[4][8] = 1;
    posicao[5][0] = 1;
    posicao[6][3] = 1;
    posicao[7][1] = 1;
    posicao[7][2] = 1;
    posicao[7][5] = 1;
    posicao[7][7] = 1;
    posicao[8][2] = 1;
    posicao[8][9] = 1;
    posicao[9][6] = 1;
    posicao[9][0] = 1;

    do
    {
        printf("\nEscolha um opção (J para jogar ou E para encerrar): ");
        scanf(" %c", &opcao);

        switch (opcao)
        {
        case 'J':

            printf("\n\t\tVOCÊ ESCOLHEU JOGAR!\n\n");

            printf("\nEscolha uma posição (um par ordenado Linha e Coluna):\n");
            printf("\nLinha: ");
            scanf("%d", &escolhaLi);
            printf("\nColuna: ");
            scanf("%d", &escolhaCol);

            if (escolhaLi > 9 || escolhaCol > 9 || escolhaLi < 0 || escolhaCol < 0)
            {
                printf("\nPosição inválida, tente novamente!");
                break;
            }
            else if (posicao[escolhaLi][escolhaCol] == 0)
            {

                pontos += 5;
                if (pontos > 100 && pontos < 110)
                {
                    printf("\nÉ, nada mal pra quem estar começando.\n");
                }
                else if (pontos >= 110 && pontos < 130)
                {
                    printf("\nInteressante, acredito que você esteja se esforçando ao máximo...\n");
                }
                else if (pontos >= 130 && pontos < 150)
                {
                    printf("\nParece que você estar levando isso a sério... não sei por quanto tempo\n");
                }
                else if (pontos >= 150 && pontos < 170)
                {
                    printf("\nVocê está mesmo achando que vai conseguir? Veremos...\n");
                }
                else if (pontos >= 170 && pontos < 190)
                {
                    printf("\nComo assim? Ninguém nunca foi tão longe contra as minhas bombas!! Você não mais longe que isso!\n");
                }
                else
                {
                    printf("\nIMPOSSIBLE!! Você só pode ter olhado o código fonte...\n");
                }
                printf("\nPontuação + 5:\n");

                posicao[escolhaLi][escolhaCol] = -2;
            }
            else if (posicao[escolhaLi][escolhaCol] == 1)
            {
                printf("\nOps, Cuidado...\n");
                pontos -= 20;
                printf("\nPontuação -20:\n");

                posicao[escolhaLi][escolhaCol] = -3;
            }
            else if (posicao[escolhaLi][escolhaCol] < 0)
            {
                printf("\nPosição já escolhida!\n");
            }

            printf("\n\t\tMAPA DO JOGO!\n\n");
            printf("\n================== | VIDAS: %d | ==================\n", pontos);
            printf("\n=     0    1    2    3    4    5    6    7    8    9\n");
            for (int i = 0; i < 10; i++)
            {
                printf("\n%2d   ", i);
                for (int j = 0; j < 10; j++)
                {
                    if (posicao[i][j] == 0)
                    {
                        printf("[ ]  ");
                    }
                    else if (posicao[i][j] == -2)
                    {
                        printf("[O]  ");
                    }
                    else if (posicao[i][j] == -3)
                    {
                        printf("[X]  ");
                    }
                    else
                    {
                        printf("[ ]  ");
                    }
                }
                printf("\n");
            }
            printf("\n");

            break;

        case 'E':
            printf("\nEncerrando...\n");
            break;

        default:
            printf("\nSomente J ou E!\n");
            break;
        }
    } while (opcao != 'E' && pontos > 0 && pontos < 200);

    if (pontos <= 0)
    {
        printf("\nVocê não foi páreo para as minhas bombas dessa vez!\n");
    }
    else if (pontos > 0 && pontos < 200)
    {
        printf("\nVocê não conseguiu completar o desafio? Pathetic..\n");
    }
    else
    {
        printf("\nV-você conseguiu?? N-nâo pode ser possível... VOCÊ OLHOU O CÓDIGO FONTE??\n");
    }
    return 0;
}
