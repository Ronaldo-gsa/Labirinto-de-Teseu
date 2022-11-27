#include <stdio.h>
int main(){
    //VARIAVEIS
    int linhas_lab,colunas_lab,invad=0;
    char lab[100][100];
    char personagem = '*';
    int pos_personagem_lin;
    int pos_personagem_col;
    int entrada_col; //coluna da entrada
    int saida_col; //coluna da saida
    char comando;
    int num_part,num_lab=1;
    int sair=0; //apertar o Q para sair

    scanf("%d",&num_part);
    setbuf(stdin,NULL);
    for(;num_lab<=num_part;num_lab++){
        invad = 0;
        sair = 0;
        //ESCANEANDO O LABIRINTO
        scanf("%d %d",&colunas_lab,&linhas_lab); //inverti a ordem da linha e coluna pq o corretor do prof lê primeiro o nº de colunas e depois de linhas
        getchar();
        for (int i=0;i<linhas_lab;i++){
            for (int j=0;j<colunas_lab;j++){
                scanf("%c",&lab[i][j]);
            }
            getchar();
        }
        
        //validando o labirinto
        for (int j = 0;j<colunas_lab;j++){
            if (lab[0][j]==' ') //verifica saida
                invad++;
            if (lab[linhas_lab-1][j]==' ') //verifica entrada
                invad++;
        }
        for (int i=0;i<linhas_lab;i++){
            if (lab[i][0]==' ') //verifica lateral esquerda
                invad++;
            if (lab[i][colunas_lab-1]==' ') //verifica lateral direita
                invad++;
        }
        if (linhas_lab>100 || linhas_lab<=10 || colunas_lab>100 || colunas_lab<=10)
            invad++;
        if (invad != 2){ //ele vai aumetar ate 2 na validacao de uma entrada e uma saida
            printf("\nLABIRINTO INVÁLIDO\n");
            invad=0;
        }
        else{
            //PRINTA O LABIRINTO
            for (entrada_col = 0;entrada_col<colunas_lab-1;entrada_col++){
                if (lab[linhas_lab-1][entrada_col]==' ')
                    break;
            }
            for (saida_col = 0;saida_col<colunas_lab-1;saida_col++){
                if (lab[0][saida_col]==' ')
                    break;
            }
            lab[linhas_lab-1][entrada_col] = personagem;
            pos_personagem_col = entrada_col;
            pos_personagem_lin = linhas_lab-1;

            printf("\nLABIRINTO %d:\n",num_lab);
            for (int i=0;i<linhas_lab;i++){
                for (int j=0;j<colunas_lab;j++){
                    printf("%c",lab[i][j]);
                }
            }

            do{
                comando = getchar();
                getchar();
                switch(comando){
                    case'w':
                    case'W':
                    if (lab[pos_personagem_lin-1][pos_personagem_col]=='#')
                                break;
                            lab[pos_personagem_lin][pos_personagem_col] = ' ';
                            lab[pos_personagem_lin-1][pos_personagem_col]='*';
                            pos_personagem_lin = pos_personagem_lin-1;
                            break;
                    case'S':
                    case's':if (lab[pos_personagem_lin+1][pos_personagem_col]=='#')
                                break;
                            lab[pos_personagem_lin][pos_personagem_col] = ' ';
                            lab[pos_personagem_lin+1][pos_personagem_col]='*';
                            pos_personagem_lin = pos_personagem_lin+1;
                            break;
                    case'A':
                    case'a':if (lab[pos_personagem_lin][pos_personagem_col-1]=='#')
                                break;
                            lab[pos_personagem_lin][pos_personagem_col] = ' ';
                            lab[pos_personagem_lin][pos_personagem_col-1]='*';
                            pos_personagem_col = pos_personagem_col-1;
                            break;
                    case'D':
                    case'd':if (lab[pos_personagem_lin][pos_personagem_col+1]=='#')
                                break;
                            lab[pos_personagem_lin][pos_personagem_col] = ' ';
                            lab[pos_personagem_lin][pos_personagem_col+1]='*';
                            pos_personagem_col = pos_personagem_col+1;
                            break;
                    case'Q':
                    case'q':sair = 1;
                            break;
                }
                if (sair == 1){
                    printf("VOCÊ CONTINUA PRESO NO LABIRINTO\n");
                    break;
                }
                if (lab[0][saida_col]=='*')
                    break;
                printf("\nLABIRINTO %d:\n",num_lab);
                for (int i=0;i<linhas_lab;i++){
                    for (int j=0;j<colunas_lab;j++){
                        printf("%c",lab[i][j]);
                    }
                    printf("\n");
                }
                //printf("\n");
            }while(lab[0][saida_col]==' ');
        if (lab[0][saida_col]=='*'){
                        printf("VOCÊ ESCAPOU\n");
                    }
        }
    }
    return 0;
}