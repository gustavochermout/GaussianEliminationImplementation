/*input
7 7
3 0 -9 6 9 4 -1 -0.108
-9 3 8 9 -12 6 3 26.24
1 -9 1 -3 1 -5 5 92.808
4 8 -10 8 -1 4 -4 53.91
-5 5 4 11 3 8 7 143.55
6 -2 9 -7 -5 -3 8 -6.048
8 7 2 5 2 1 -3 137.94
*/

#include<bits/stdc++.h>

using namespace std;

#define N_MAX 1001

double matriz[N_MAX][N_MAX + 1], resultado[N_MAX];
int N, M; 

void debug(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M + 1; j++)
	    	printf("%.1lf ", matriz[i][j]);

		printf(" \n");
	}

	printf("\n");
}

void transforma_em_um(int linha){
    double pivo = matriz[linha][linha];

    for(int i = linha; i < M + 1; i++)
    	matriz[linha][i] /= pivo;
}

void transforma_em_zero(int coluna){
	if(matriz[coluna][coluna] != 1)
		transforma_em_um(coluna);

	for(int i = coluna + 1; i < N; i++){
		double pivo = matriz[i][coluna];

		for(int j = coluna; j < M + 1; j++)
			matriz[i][j] -= pivo * matriz[coluna][j];
		
		debug();
	}
		
}

void gerar_resultado(){
    double sum;

    for (int i = M - 1; i > -1; i--){
    	sum = matriz[i][M];

    	for(int j = N - 1; j > i; j--)
    		sum -= matriz[i][j] * resultado[j];

    	resultado[i] = sum / matriz[i][i];
    }    	
}

int main(){
	
	double inf = numeric_limits<double>::infinity();
    bool infinito = false;
    
    printf("**** Sistemas Lineares *****\n");
    printf("*** Eliminacao Gaussiana ***\n");
	printf("** (Gaussian Elimination) **\n\n");
    printf("Digite a quantidade de linhas e colunas. (N x M): ");

	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; i++){

        printf("Digite a %da equacao sem operadores: ", i + 1);        

		for(int j = 0; j < M + 1; j++)
			scanf("%lf", &matriz[i][j]);
    }
			
	printf("\n");		

    printf("Sistema:\n");
    debug();

    printf("Escalonamento:\n");

    for(int i = 0; i < N - 1; i++)
    	transforma_em_zero(i);	

    gerar_resultado();
	
	for(int i = 0; i < M; i++){		
		if (abs(resultado[i]) == inf || abs(resultado[i]) == NAN){
		    infinito = true;
		    break;
		}	
	}
	    
	if (infinito)
        printf("Sistema impossivel!\n");
	else{
		for(int i = 0; i < M; i++)
	        printf("X%d = %.5lf\n", i + 1, resultado[i]);
	}		   

	system("pause");
	return 0;
}
