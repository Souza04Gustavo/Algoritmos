#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void printarCarta(char naipes[10], int numero){
    
    printf("\n ___________");
    printf("\n |         |");
    printf("\n | %i       |", numero);
    printf("\n |         |");
    printf("\n    %s", naipes);
    printf("\n |         |");   
    printf("\n |      %i  |", numero);
    printf("\n |_________|");
}


int main()
{
    int pessoas, lin;
    
    char matriznomes[lin][100];
    
    printf("\nDigite o numero de pessoas que irão jogar:\n");
    scanf("%i", &pessoas);
    
   printf("\nInsira o nome dos %i jogadores:\n\n", pessoas);
  
    for(lin = 0; lin < pessoas; lin++){
        printf("Jogador %i: ", lin+1);
        fgets(matriznomes[lin], 100, stdin);
        getchar();
    }
    

   int naipes[pessoas];//numeros (de 1 a 4) que representam o naipe de cada jogador
   char matriznaipes[pessoas][50];//naipes salvos em string
   int cartas[pessoas];//numeros das cartas de cada jogador
   
   int i;
   time_t t;
   
   //Função que ira auxiliar na randomização
   srand((unsigned) time(&t));

   //Gerando o numero das cartas aleatoriamente e salvando em um vetor
   for( i = 0 ; i < pessoas ; i++ ) {
      cartas[i]= (rand() % 13) + 1;
   }
   
   //Gerando o numero para os naipes aleatoriamente e salvando em um vetor
   for( i = 0 ; i < pessoas ; i++ ) {
      naipes[i]= (rand() % 4) + 1;
   }

    //transformando de numero pra string
    for(i= 0; i < pessoas; i++){
        switch(naipes[i]){
            case 1:
          strcpy(matriznaipes[i], "Ouro");
          break;
          case 2:
          strcpy(matriznaipes[i], "Espadas");
          break;
          case 3:
          strcpy(matriznaipes[i], "Copas");
          break;
          case 4:
          strcpy(matriznaipes[i], "Paus");
          break;
            
        }
    }
   
    printf("\n -- Printando os vetores para comprovar --\n");
    printf("\nValores aleatorio das cartas:\n");
    for(int i =0; i< pessoas; i++){
        printf("\nJogador %i: Numero %i do naipe %i ( %s )", i+1, cartas[i], naipes[i], matriznaipes[i]);
    }
    
    //printando as cartas
    for(int i =0; i< pessoas; i++){
        printf("\n\n Jogador %i:\n", i+1);
        printarCarta(matriznaipes[i], cartas[i]);
    }
    
    int maiorcarta = cartas[0];
    int posicaomaior;
    
    //Analise das cartas para determinar o vencedor
    for(i = 0; i < pessoas; i++){
        if(maiorcarta < cartas[i]){
            maiorcarta = cartas[i];
            posicaomaior = i;
        } else if(maiorcarta == cartas[i]){//CASO TENHA CARTAS COM O MESMO NUMERO PRECISAMOS ANALISAR O NAIPE
            if(naipes[posicaomaior] < naipes[i]){//se o naipe das cartas forem diferentes
                maiorcarta = cartas[i];
                posicaomaior = i;
            }else{
                maiorcarta = maiorcarta;
        }
       }
    }
    
    
  printf("\n VENCEDOR: Jogador %i com a carta %i de %s\n", posicaomaior+1, cartas[posicaomaior], matriznaipes[posicaomaior]);
    
    return 0;
}