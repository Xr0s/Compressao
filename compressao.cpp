#include <iostream>
#include <fstream>
#include <stdlib.h> 
using namespace std;

ifstream entrada;
ofstream escreve;

typedef struct{
	string nome;
	int cont=0;
}Histograma;

void imprimirRLE(Histograma* histograma, int aux, float txcompressaoRLE, int impressao){
	cout << impressao <<": [RLE ";
	printf("%.2f", txcompressaoRLE);
	cout<<"%]";
	for(int j=0;j<aux+1;j++){
		
				cout<<" 0x";
				printf("%.2X",histograma[j].cont);
				cout << " " << histograma[j].nome;		
	}
	cout<<endl;
return;	
}

int main(int argc, char **argv){
	int qtd, qtdDados, contadorRLE=0, impressao=0;
	float txcompressaoRLE;
	string line;
	//clock_t start = clock();
	entrada.open("entrada.txt");
	escreve.open("saida.txt");
	
		entrada>>line;
		qtd=atoi(line.c_str());
		for(int i=0;i<qtd;i++){
			entrada>>line;
			qtdDados=atoi(line.c_str());
			string *sequencia = new string[qtdDados];
			for(int j=0;j<qtdDados;j++){
					entrada>>line;
					sequencia[j]=line;
			}
			
			
			
			
			/*
			Histograma *histograma=new Histograma[qtdDados];
			for(int j=0;j<qtdDados;j++){
					if(j+1==qtdDados || sequencia[j]==sequencia[j+1]){
						histograma[contadorRLE].cont++;
						histograma[contadorRLE].nome=sequencia[j];
					}
					else{
						histograma[contadorRLE].cont++;
						histograma[contadorRLE].nome=sequencia[j];
						contadorRLE++;
					}
			 }
			 txcompressaoRLE=100*(((float)contadorRLE+1)*2/qtdDados);
			 imprimirRLE(histograma,contadorRLE,txcompressaoRLE, impressao);
			 
			contadorRLE=0;
			delete[]histograma;
			*/ 
			delete[]sequencia;
			impressao++;
		}
		

   //clock_t end = clock();	
   //printf("Duracao: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
	return 0;
}	
