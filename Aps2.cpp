#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct{
    int mat;
    char nome[50];
    float media;
} UniCarioca;

UniCarioca aluno[50];
int i = 0;

bool MatriculaExiste(int mat) {
    for (int j = 0; j < i; j++) {
        if (aluno[j].mat == mat) {
            return true;
        }
    }
    return false;
}

void Add() {
    system("cls");
    cout << "PROGRAMA" << endl;
    if (i < 50) {
        int mat;
        cout << "ADICIONAR ALUNO " << i + 1 << endl;
        cout << "MATRICULA: "; cin >> mat;

        if (MatriculaExiste(mat)) {
            cout << "MATRICULA JA EXISTE!" << endl;
        } else {
            aluno[i].mat = mat;
            cout << "NOME: "; cin >> aluno[i].nome;
            cout << "MEDIA: "; cin >> aluno[i].media;
            i++;
        }
    } else {
        cout << endl << endl << "PROGRAMA LOTADO" << endl;
    }
    system("pause");
}

float Nota (){//APROVADO - - REPROVADO
	int k;
	
	if (aluno[k].media >=7){
		cout<<"+ APROVADO "<<endl;
	}else 
	cout<<"- REPROVADO "<<endl;
}



/*void printaaluno() { /////////////////////////////OLHAR
	for(int k=0;k<i;k++) {
		cout<<aluno[k].nome;
		cout<<aluno[k].mat;
	}
}*/

bool VerificarOrdenado() {
    for (int k = 0; k < i - 1; k++) {
        if (aluno[k].mat > aluno[k + 1].mat) {
            return false;
        }
    }
    return true;
}

void Selection() {
	
	int Menor;
	
	UniCarioca aux;
	
	for (int l=0; l<i-1;l++) {
		Menor=l;
		for (int j=l+1;j<i;j++) {
			if (aluno[Menor].mat > aluno[j].mat)
				Menor=j;
		}
		if (l != Menor) {
			aux=aluno[l];
			aluno[l]=aluno[Menor];
			aluno[Menor]=aux;
		}
	}
//	printaaluno();
}


void Insertion() {/////////////////OLHAR
    for (int k = 1; k < i; k++) {
        int aux = aluno[k].mat;
        int j = k - 1;

        while (j >= 0 && aluno[j].mat > aux) {
            aluno[j + 1] = aluno[j];
            j = j - 1;
        }
        aluno[j + 1].mat = aux;
    }
}

int BuscarBinaria(int x) {
    int e = 0, d = i - 1;
    while (e <= d) {
        int m = e + (d - e) / 2;
        if (aluno[m].mat == x) {
            return m;
        } else if (aluno[m].mat < x) {
            e = m + 1;
        } else {
            d = m - 1;
        }
    }
    return -1;
}

//-------------LISTA DE EXIBIR-------------

void Todos() { 
    system("cls"); 
    cout << "Lista de Alunos:" << endl;
    for (int k = 0; k < i; k++) {
        cout << "Matricula: " << aluno[k].mat << endl;
        cout << "Nome: " << aluno[k].nome << endl;
        cout << "Media: " << aluno[k].media << endl;
        if (aluno[k].media >= 7) {
            cout << "Status: Aprovado" << endl;
        } else {
            cout << "Status: Reprovado" << endl;
        }
        cout << "--------------------------" << endl;
    }
    system("pause"); 
}

void Aprovados() {
    system("cls"); 
    cout << "Lista de Alunos Aprovados:" << endl;
    for (int k = 0; k < i; k++) {
        if (aluno[k].media >= 7) {
            cout << "Matricula: " << aluno[k].mat << endl;
            cout << "Nome: " << aluno[k].nome << endl;
            cout << "Media: " << aluno[k].media << endl;
            cout << "Status: Aprovado" << endl;
            cout << "--------------------------" << endl;
        }
    }
    system("pause"); 
}

void Reprovados() {
    system("cls"); 
    cout << "Lista de Alunos Reprovados:" << endl;
    for (int k = 0; k < i; k++) {
        if (aluno[k].media < 7) {
            cout << "Matricula: " << aluno[k].mat << endl;
            cout << "Nome: " << aluno[k].nome << endl;
            cout << "Media: " << aluno[k].media << endl;
            cout << "Status: Reprovado" << endl;
            cout << "--------------------------" << endl;
        }
    }
    system("pause"); 
}

void Maior9() {
    system("cls"); 
    cout << "Lista de Alunos com Média Maior ou Igual a 9:" << endl;
    for (int k = 0; k < i; k++) {
        if (aluno[k].media >= 9) {
            cout << "Matricula: " << aluno[k].mat << endl;
            cout << "Nome: " << aluno[k].nome << endl;
            cout << "Media: " << aluno[k].media << endl;
            cout << "--------------------------" << endl;
        }
    }
    system("pause"); 
}

void Menor5() {
    system("cls"); 
    cout << "Lista de Alunos com Média Menor ou Igual a 5:" << endl;
    for (int k = 0; k < i; k++) {
        if (aluno[k].media <= 5) {
            cout << "Matricula: " << aluno[k].mat << endl;
            cout << "Nome: " << aluno[k].nome << endl;
            cout << "Media: " << aluno[k].media << endl;
            cout << "--------------------------" << endl;
        }
    }
    system("pause"); 
}

int Buscar(int x) {
    int resp = -1;
    for (int j = 0; j < i; j++) {
        if (aluno[j].mat == x)
            resp = j;
    }
    return resp;
}

int BuscarSentinela(int x) {
    int total = 0;
    aluno[i].mat = x;
    while (x != aluno[total].mat)
        total++;
    if (total < i)
        return total;
    else
        return -1;
}

void ExibirMenu() {
	
	int op4;
	
	do{
		system("cls");
		
		cout<<"EXIBIR: "<<endl;
		cout<<"[1] TODOS"<<endl;
		cout<<"[2] APROVADOS"<<endl;
		cout<<"[3] REPROVADOS"<<endl;
		cout<<"[4] MAIOR OU IGUAL 9"<<endl;
		cout<<"[5] MENOR OU IGUAL 5"<<endl;
		cout<<"[0] SAIR" << endl;
		cout << "OPCAO: "; cin >> op4;
		switch (op4) {
			case 1: Todos();break;
			case 2: Aprovados();break;
			case 3: Reprovados();break;
			case 4: Maior9();break;
			case 5: Menor5();break;
		}
	} while (op4 != 0);
}///
void ORDENAR(){
	int b, op2;
	system("cls");
	cout<<"PROGRAMA"<<endl;
	if (i==0)
		cout<<endl<<endl<<"PROGRAMA VAZIO"<<endl;
else{

		if (VerificarOrdenado()) {
					        cout << "O vetor ja esta ordenado!" << endl;
}	else{
	
		cout << "[1] SelectionSort" << endl; 
				    cout << "[2] InsertionSort" << endl;
		cout<<"OPCAO: "; cin>>op2;
}
		switch (op2){
			case 1:   Selection(); break;
			case 2: Insertion(); break;
		}
		
	}
	system("pause");
}

//-----------------------------------------------------

void BuscarMenu() {
    int b, op2, op3;
    system("cls");
    cout << "PROGRAMA" << endl;
    if (i == 0) {
        cout << endl << endl << "PROGRAMA VAZIO" << endl;
    } else {
        cout << "[1] PESQUISA SEQUENCIAL" << endl;
        cout << "[2] PESQUISA SEQUENCIAL COM SENTINELA" << endl;
        cout << "[3] PESQUISA BINARIA" << endl;
        cout << "OPCAO: "; cin >> op2;
        switch (op2) {
            case 1: cout << "MATRICULA PARA PESQUISA SEQUENCIAL: ";		cin >> b; 
			b = Buscar(b); break;
            case 2: cout << "MATRICULA PARA PESQUISA COM SENTINELA: ";		cin >> b; 
			b = BuscarSentinela(b); break;
			case 3: cout << "PESQUISA BINARIA: "<< endl; 			
					system("cls");
					
					if (VerificarOrdenado()) {
					        cout << "O vetor ja esta ordenado!" << endl;
					   cout << "MATRICULA PARA PESQUISA: "; 
					    cin >> b;
					    b = BuscarBinaria(b); 
					    Nota();	
				        if (b == -1)
				            cout << "MATRICULA NAO ENCONTRADA" << endl;
				        else
				            cout << "NOME: " << aluno[b].nome << endl << "MEDIA: " << aluno[b].media << endl << endl;
						break;
				    }else{
				
				 
						
			
				    cout << "VOCE DEVE ORDENAR ANTES DE PESQUISAR: "<< endl; 
				    cout << "[1] SelectionSort" << endl; 
				    cout << "[2] InsertionSort" << endl; 
				    cout << "OPCAO: ";		cin >> op3;
				    }
					if (b == -1)
				            cout << "MATRICULA NAO ENCONTRADA" << endl;
				        else
				            cout << "NOME: " << aluno[b].nome << endl << "MEDIA: " << aluno[b].media << endl << endl;
				            break;
						} 
					switch (op3) {
				        case 1: system("cls");
						Selection(); 
				                cout << "ORDENADO COM SUCESSO!" << endl; system("pause"); 
				               system("cls"); 
				        case 2: 
				        system("cls");
					    if (VerificarOrdenado()) {
					        cout << "O vetor ja esta ordenado!" << endl;
					    } else {
					        Insertion(); 
					        cout << "ORDENADO COM SUCESSO!" << endl; 
					    }
					    system("cls"); 
					    cout << "MATRICULA PARA PESQUISA: "; 
					    cin >> b;
					    b = BuscarBinaria(b); 
					    Nota();
					    if (b == -1)
				            cout << "MATRICULA NAO ENCONTRADA" << endl;
					    break;	
				    }
				       
						} 
				    system("pause");
	}///
	
	

int main() {
    int op;
    do {
        system("cls");
        cout << "PROGRAMA" << endl;
        cout << "[1] ADICIONAR" << endl;
        cout << "[2] BUSCAR" << endl;
        cout << "[3] EXIBIR" << endl;
        cout << "[4] ORDENAR" << endl;
        cout << "[0] SAIR" << endl;
        cout << "OPCAO: "; cin >> op;
        switch (op) {
            case 1: Add(); break;
            case 2: BuscarMenu(); break;
            case 3: ExibirMenu();break;
            case 4: ORDENAR();break;
       }
    } while (op != 0);
    return 0;
} /////
