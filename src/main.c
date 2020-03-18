/* Data de submissao:17.03.2020
 * Nome: Rafael Monteiro Marques
 * RA:204952
 */

#include <stdio.h>

#define TAM_PILHA 100

typedef struct {
	char dados[TAM_PILHA];			// vetor de caracteres de tamanho defined
	int n ;					// variavel inteira
} pilha, *Pilha;				// cada coisa nomeada como "pilha" possuira os dois itens acima.
						// o ponteiro com asterisco funciona da mesma forma, porem como ponteiro

void pilha_init(Pilha p) {			// funcao tem como parametro um ponteiro (P maiusculo)
	p->n = 0;				// a var int da estrutura "p" recebe o valor "0"			
}

void push(Pilha p, char c) {
/* Insere caractere c na pilha */
	if (p->n < TAM_PILHA) {			// se ( [var int da estrutra p] < 10)
		p->dados[p->n]=c;		// a [o caractere na posicao n da str da estrutura p] recebera o caractere c
		(p->n)++;			// a var int da estrutura p eh incrementada
	}
}

char pop(Pilha p) {
/* Remove caractere do topo da pilha */
	char c;
	if ((p->n)>0) {
		(p->n)--;
		c = p->dados[p->n];		// caractere c recebe caractere da str da estrutura p na posicao da var int n
	}
	return c;
}

int main() {
	pilha p1;	
	pilha p2; 	

	pilha_init(&p1);
	pilha_init(&p2);
	
	char c;
	int k = 0;
	int space = 0;
	int point_sp[20] = {0};
	int point_wr = 0;

	fgets(p1.dados, TAM_PILHA, stdin);
	
	for(k = 0; k < TAM_PILHA; k++){
		
		if ((p1.dados[k] == ' ' )||(p1.dados[k] == '\n')) {
			point_sp[space] = k;
			while (point_wr < point_sp[space]){
				p1.dados[point_wr] = pop(&p2);
				point_wr++;
			}
	
			if (p1.dados[k] != '\n'){
				p1.dados[point_wr] = ' ';
				point_wr++;
				space++;
			}
			
		}else{
			push(&p2, p1.dados[k]);
		}
	}

	k = 0;

	while (p1.dados[k] != '\n'){
		printf("%c", p1.dados[k]);
		k++;
	}
	
	printf("\n");
	return 0;
}
