#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int main()
{
	float a, b;
	double taxaDeLeitura = 0.0001;
	int i, qtdAtual, qtdDeCarbo;
    double qtdDeLeitura = 5000000;
	double carb[10] = {20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
	double glicemia[10] = {105, 115, 125, 135, 145, 155, 165, 175, 185, 195};    
	double gradienteA, gradienteB, previsao, erro, erroAtual, qtdGlicemia;
	int qtdDados = 10;
	
	
	printf("Iniciando Aprendizado...\n");
	system("pause");
	
	srand(time(NULL));
	a = (float)rand() / RAND_MAX;
	b = (float)rand() / RAND_MAX;
	
	for (qtdAtual = 0; qtdAtual < qtdDeLeitura; qtdAtual++)
	{
	    gradienteA = 0.0;
	    gradienteB = 0.0;
	    
	    for (i = 0; i < qtdDados; i++)
	    {
	        previsao = a * carb[i] + b;
	        erro = previsao - glicemia[i];
	        
	        gradienteA += erro * carb[i];
	        gradienteB += erro;
	    }
	    
	    gradienteA = (2.0/qtdDados) * gradienteA;
	    gradienteB = (2.0/qtdDados) * gradienteB;
	    
	    a = a - taxaDeLeitura * gradienteA;
	    b = b - taxaDeLeitura * gradienteB;
	    
	}
	
	printf("\nTreinamento Concluído!");
	printf("\nDigite quanto de carboidrato comeu na sua última refeição:\n");
	scanf("%d", &qtdDeCarbo);

	
	qtdGlicemia = a * qtdDeCarbo + b;
	
	printf("\nSeu pico de glicemia foi:   %.2f\n", qtdGlicemia);
	
	system("pause");
	
	return 0;
}