#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

/*
APS - ALG 2 - Questão 1
Grupo:
Bruna de Oliveira Kaneco
Dalton Cabral de Oliveira
João Fillipi Madureira de Oliveira
Jorge Luiz de Santana dos Santos
Matheus David Vasconcelos
*/

int vetor[50];
int i = 0;


bool NumVet(int x){
	for  (int j = 0; j < i; j++){
		if (vetor[j] == x){
			return 1;
		}
	}
	return 0;
}

void Add(){
    int valnum;
	system("cls");
	cout<<"ADICIONAR NUMERO ("<<i+1<<")"<<endl;
	do {
	if (i<50){
		cout<<"DIGITE O NUMERO A SER ADICIONADO: "<<endl; 
		cin>>valnum;
				if ((valnum >= 1 && valnum <= 20) || (valnum >= 50 && valnum <=60) || (valnum >= 100 && valnum <= 120)){
					if (NumVet(valnum) == 1){
					cout<<"NUMERO JA ADICIONADO AO VETOR."<<endl;
					} else {
					vetor[i] = valnum;
					cout<<"NUMERO ADICIONADO AO VETOR COM SUCESSO."<<endl;
					i++;
					break;
					}
				} else 
				cout<<"NUMERO FORA DAS FAIXAS ACEITAS."<<endl;
			} else {
			cout<<"VETOR LOTADO";
			break; 
			}
	} while (i);
	system("pause");

}


int Buscar(int y){
	int resp = -1;
	for (int m=0; m<i; m++){
		if (vetor[m] == y)
			resp = m;
	}
	return resp;
}


int ordenado(){
    int tam = i;
	for(int pq=1; pq<tam; pq++){
		if (vetor[pq] < vetor[pq - 1])
		return 1;
	}	
	return 0;
}

int BuscaBinaria(int r){
	int esquerda = 0; 
	int direita = i - 1;

	while(esquerda <= direita){
		int meio = esquerda + (direita - esquerda) / 2;

		if(vetor[meio] == r){
			return meio;
		}else if(vetor[meio] < r){
			esquerda = meio + 1; 
		}else{
			direita = meio - 1;
		}
	}
	return -1;
}

void BubbleSort(int n){
    int aux;
    for (int j=n; j>=0; j--){
        for (int q=0; q<=j-1; q++){
            if (vetor[q] > vetor[q+1]){
            aux = vetor[q];
            vetor[q] = vetor[q+1];
            vetor[q+1] = aux;
            }
        }
    }
}

void InsertionSort(int tam) {
  for (int l = 1; l < tam; l++) {
    int valorNum = vetor[l];
    int b = l;
    while (b >= 1 && vetor[b - 1] > valorNum) {
      vetor[b] = vetor[b - 1];
      b--;
    }
    vetor[b] = valorNum;
  }
}

void BuscarMenu(){
	int b;
	int op2;
	int op3;

	system("cls");
	cout<<"PROGRAMA"<<endl;
	if (i==0)
		cout<<endl<<endl<<"PROGRAMA VAZIO"<<endl;
	else{
		cout<<"[1] PESQUISA SEQUENCIAL"<<endl;
		cout<<"[2] PESQUISA BINARIA"<<endl;
		cout<<"OPCAO: ";	cin>>op2;
		switch(op2){
			case 1: 
			cout<<"INSIRA O NUMERO A SER PESQUISADO: ";	cin>>b; 
			b = Buscar(b); 
			if (b == -1){
			cout<<"NUMERO NAO ENCONTRADO."<<endl;
			} else {
			cout<<"NUMERO ENCONTRADO."<<endl;
			cout<<"NUMEROS REGISTRADOS: ";
			for (int u = 0; u < i; u++){
			cout<<vetor[u]<<" ";
			}
			cout<<endl;
			}
			break;
	
			case 2:
			if(ordenado() == 1){
				cout<<"VETOR NAO ESTA ORDENADO."<<endl;
				cout<<"ESCOLHA O METODO DE ORDENACAO: "<<endl;
				cout<<"[1] BUBBLE SORT"<<endl;
				cout<<"[2] INSERTION SORT"<<endl;
				cout<<"OPCAO: ";	cin>>op3;
				
				if(op3 == 1){
				BubbleSort(i-1);
				}
				else{
				InsertionSort(i);
				}
				cout<<"VETOR ORDENADO COM SUCESSO."<<endl;
				cout<<"INSIRA O NUMERO A SER PESQUISADO: ";	cin>>b;
				if(BuscaBinaria(b) == -1){
					cout<<"NUMERO NAO ENCONTRADO NO VETOR."<<endl;			
				}else{
					cout<<"NUMERO ENCONTRADO."<<endl;
					cout<<"NUMEROS REGISTRADOS: " ;
                    for(int k = 0; k < i; k++){
					cout<<vetor[k]<<" ";
                    }
					cout<<endl;
				}

				}else{
				cout<<"NUMERO PARA PESQUISA: "<<endl;	cin>>b;
				if(BuscaBinaria(b) == -1){
					cout<<"NUMERO NAO ENCONTRADO NO VETOR."<<endl;
			
				}else{
					cout<<"NUMERO ENCONTRADO."<<endl;
					cout<<"NUMEROS REGISTRADOS: " ;
                    for(int k = 0; k < i; k++){
					cout<<vetor[k]<<" ";
                    }
					cout<<endl;
				}
				break;
				}
			} 	
		}
		
	system("pause");
}

void OrdenarMenu(){
	int op4;
	system("cls");
	if (ordenado() == 1){
	cout<<"SELECIONE O METODO DE ORDENACAO"<<endl;
	cout<<"[1] BUBBLE SORT"<<endl;
	cout<<"[2] INSERTION SORT"<<endl;
	cout<<"OPCAO: "; cin>> op4;
	switch (op4){
		case 1: 
		BubbleSort(i-1);
		cout<<"VETOR ORDENADO COM SUCESSO."<<endl;
		break;

		case 2: InsertionSort(i);
		cout<<"VETOR ORDENADO COM SUCESSO"<<endl;
		break;
	}
	} else {
		cout<<"VETOR JA ORDENADO."<<endl;
	}
	system("pause");
}

main(){
	int op;
	do{
	system("cls");
	cout<<"PROGRAMA"<<endl;
	cout<<"[1] ADICIONAR"<<endl;	
	cout<<"[2] BUSCAR"<<endl;
	cout<<"[3] ORDENAR"<<endl;
	cout<<"[0] SAIR"<<endl;
	cout<<"OPCAO: "; cin>>op;
	switch (op){
		case 1: Add(); break;
		case 2: BuscarMenu(); break;
		case 3: OrdenarMenu(); break;
	}
		
	} while (op!=0);
					
}