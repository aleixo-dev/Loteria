#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>

void CartaoAposta()
{
	printf("----------------------------------------------\n");
	printf("	Cartão de Aposta				  \n");
	printf("----------------------------------------------\n");
}

void ResultadoAposta()
{
	printf("----------------------------------------------\n");
	printf("	Resultado da aposta				  \n");
	printf("----------------------------------------------\n");
}
void Exibir()
{
	printf("-------------------------------------------\n");
	printf("   CURSO: ANÁLISE E DESENV DE SISTEMAS 	   \n");
	printf("   ALGORITMOS E LÓGICA PARA PROGRAMAÇÃO    \n");
	printf("-------------------------------------------\n");
	printf("   -> Programa Loteria Mega Maluca <-      \n");
	printf("-------------------------------------------\n");
					
}

int qtdNumeros(int qtdNum)
{
	do
	{
		printf("-> Informe a qnt, de Nº que deseja jogar: ");
		scanf("%d", &qtdNum);
		if(qtdNum != 6)
		{
			printf("-> Quantidade de número a jogar é diferente de 6.\n");
		}
	}while(qtdNum !=6);
}
	
main() {
	// Seta Idioma
	setlocale(LC_ALL, "Portuguese");
	Exibir();
	//srand((unsigned)time(NULL));
	int numeros[6],sorteio[6] = {},vetor[6],aux = 1,a,cont,contnum = 1,qtdNum,opcao,acertos = 0,sort;
	bool status,ver; 
	
	int i,j,l,k,m,linhas,colunas,contador = 1;
	
	int tabela[6][10] = {{1,2,3,4,5,6,7,8,9,10},
						{11,12,13,14,15,16,17,18,19,20},
						{21,22,23,24,25,26,27,28,29,30},
						{31,32,33,34,35,36,37,38,39,40},
						{41,42,43,44,45,46,47,48,49,50},
				     	{51,52,53,54,55,56,57,58,59,60} };
						 
			
	//Recebe os números digitados pelo usuário no vetor numeros.
	//qtdNumeros(qtdNum); 	
	for(a = 0;a < 6; a++)
	{
		printf("-> Informe o %d Número: ",contador); 
		scanf("%d", &numeros[a]);
		contador++;
		
		if(numeros[a] > 60)
		{
			printf("Você digitou um número maior que 60.\n");
			system("PAUSE");
			exit(0);
		}
		else if(numeros[a] == 0)
		{
			printf("Você digitou número 0.\n");
			system("PAUSE");
			exit(0);	
		}
	}
	//Gera números para o sorteio.
	
	for(i = 0;i < 6;i++)
	{
		//Verifica se existe números repitidos.
		do
		{
			sorteio[i] = 1 + rand() % 60;
			status = true;
			for(j = 0;j < i;j++)
			{
				if(sorteio[i] == sorteio[j])
				{
					status = false;
				}
			}			
		}while(status == false);
	}
	
	//Ordena vetor em ordem crescente.
	for(i = 0;i < 6;i++)
	{
		for(j = i;j <6;j++)
		{
			if(numeros[i] > numeros[j]) 
			{
				aux = numeros[i];
				numeros[i] = numeros[j];
				numeros[j] = aux;
			}
		}
	}
	
	for(i = 0;i < 6;i++)
	{
		for(j = i;j <6;j++)
		{
			if(sorteio[i] > sorteio[j]) 
			{
				sort = sorteio[i];
				sorteio[i] = sorteio[j];
				sorteio[j] = sort;
			}
		}
	}
	//Cartão de Aposta
    // Substitui na tabela os números que forem selecionados pelo usuário por 0.

    int test = 0;
	for(linhas= 0; linhas < 6;linhas++)
	{
		for(colunas = 0;colunas < 10;colunas++)
		{                         
            if(tabela[linhas][colunas] == numeros[test])
            {
                tabela[linhas][colunas] = 0;
                test++;
            }  
		}
	}
	
	//Troca os 0 pelos números selecionados pelo usário.
	test = 0;
	for(linhas= 0; linhas < 6;linhas++)
	{
		for(colunas = 0;colunas < 10;colunas++)
		{                         
            if(tabela[linhas][colunas] == 0)
            {
                tabela[linhas][colunas] = numeros[test];
                test++;
            }
            else
            {
                tabela[linhas][colunas] = 0;
            }
		}	
	}
	
    //Exibir resultado final 
    CartaoAposta();
	for(linhas = 0;linhas < 6;linhas++)
	{
        for(colunas = 0;colunas < 10;colunas++)
        {
        	if(tabela[linhas][colunas] != 0 && tabela[linhas][colunas] <10)
        	{
        		printf(" 0%d ", tabela[linhas][colunas]);
			}
			else if(tabela[linhas][colunas] != 0 && tabela[linhas][colunas] >=10)
        	{
        		printf(" %d ", tabela[linhas][colunas]);
			}
			else
			{
				printf(" -- ",tabela[linhas][colunas]);
			}
        }
        
        printf("\n");
	}
	printf("-------------------------------------------------\n");
		
	// Sortear números.
	
	for(i = 0;i < 6;i++)
	{
		printf("-> informe o %d numero - sorteado %d\n",contnum,sorteio[i]);
		contnum++; 
	}
	ResultadoAposta();
	
	//Verifica acertos.
	for(l = 0;l < 6;l++)
	{
		for(i = 0;i < 6;i++)
		{
			if(sorteio[i] == numeros[l])
			{
				acertos++;
			}
		}
	}
	
	//Exibe resultados.
	printf("-> Números Sorteados: ");
	for(l = 0;l < 6;l++)
	{
		if(sorteio[l] < 10)
		{
			printf(" 0%d -",sorteio[l]);	
		}
		else
		{
			printf(" %d -",sorteio[l]);		
		}
	}
	printf("\n");
	
	printf("\n-> Números Apostados: ");
	for(l = 0;l < 6;l++)
	{
		if(numeros[l] < 10)
		{
			printf(" 0%d -",numeros[l]);	
		}
		else
		{
			printf(" %d -",numeros[l]);		
		}
	}
	printf("\n");
	printf("\n-> Pontuação Final:  %d\n",acertos);
	printf("\n---------------------------------------------\n");
	printf("Autor: Nicolas Aleixo Dias Dos Santos.\n\n");
	
	
	do
	{
		printf("-> Digite[1] - nova aposta / [2] - sair: ");
		scanf("%d",&opcao);
		
		if(opcao == 1)
		{
			//Zerando numeros e vetores.
			system("CLS");
			contnum = 1;
			acertos = 0;
			main();
		}
	}while(opcao != 2);
	// Console pause
	
    system("PAUSE");
    return 0;
}
