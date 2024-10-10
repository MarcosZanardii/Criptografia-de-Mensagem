#include <stdio.h>

void transform(char v[], int tam, char a[], char b[]) {
    int i, j, cont;
    // passear por v examina cada letra
    for (i = 0; v[i] != '\0'; i++) {
        for (j = 0; a[j] != '\0'; j++) {
            if (v[i] == a[j]) {
                v[i] = b[j];//faz a troca da posicao 
                break;
            }
        }
    }
}
void advance(char v[], int tam, int adv) {
    char alfamin[26] = {"abcdefghijklmnopqrstuvwxyz"};
    char alfamai[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int i, j, cont;
    // loop para trocar o vetor inteiro
    for (i = 0; v[i] != '\0'; i++) {
        if ((v[i] == ' ') || (v[i] >= 0 && v[i] <= 9))
            continue;
        if (v[i] >= 'A' && v[i] <= 'Z') {
            for (j = 0; alfamai[j] != '\0'; j++) {
                if (v[i] == alfamai[j]) {
                    v[i] = alfamai[(j + adv) % 26];
                    break;
                }
            }
        } else {
            for (j = 0; alfamin[j] != '\0'; j++) {
                if (v[i] == alfamin[j]) {
                    v[i] = alfamin[(j + adv) % 26];
                    break;
                }
            }
        }
    }
}
void rolaEsquerda(char vetor[], int tam, int num) {
    if (num <= 0 || num >= tam) {
        return; // nao faz nada se num for inválido
    }

    char temp[num];

    for (int i = 0; i < num; i++) {
        temp[i] = vetor[i];
    }

    for (int i = 0; i < tam - num; i++) {
        vetor[i] = vetor[i + num];
    }

    for (int i = tam - num, j = 0; i < tam; i++, j++) {
        vetor[i] = temp[j];
    }
}

void viraPalavras(char v[], int tam) {
    int i, j, posicaoletra = 0, contl = 0;
    // loop para contar o n de letras em cada palavra e inverter as letras em cada palavra
    while (posicaoletra < tam) {
        contl = 0;
        // conta letras em uma palavra
        while (v[posicaoletra] != ' ' && v[posicaoletra] != '\0') {
            contl++;
            posicaoletra++;
        }
        // inverte as letras da palavra
        for (i = posicaoletra - contl, j = posicaoletra - 1; i < j; i++, j--) {
            char aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
        // avança para a próxima palavra (ou para o final da string)
        while (v[posicaoletra] == ' ') {
            posicaoletra++;
        }
    }
    // inverte o vetor
    for (i = 0, j = tam - 1; i < j; i++, j--) {
        char aux = v[i];
        v[i] = v[j];
        v[j] = aux;
    }
}
void main() {
    char vet[256] = {};
    int tam = 0, i;
	
    printf("Digite uma frase: ");
    fgets(vet, sizeof(tam), stdin);
	
	while(1){
		if(vet[i] == '\n'){
			vet[i] = '\0';
		break;}
	i++;}
		
    for (tam = 0; vet[tam] != '\0'; tam++){}
	

	i = 0;
	viraPalavras ( vet, tam );
	while ( i < 100 ) {
		rolaEsquerda ( vet, tam, i/2 );
			 advance ( vet, tam, i/3 );
		   transform ( vet, tam, "abcdefghijklm", "bamdfhgjcielk" );
		i++;
		printf("%s\n", vet);
	}
}