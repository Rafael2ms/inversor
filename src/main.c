/* Data de submissao:17.03.2020
 * Nome: Rafael Monteiro Marques
 * RA:204952
 */

#include <stdio.h>
const int tam_buffer=100;
int point = 0;

char frase[100];

void push (char cvar){
	frase[point] = cvar;
}

char pop (){
	char cvar = frase[point]; 
	return cvar;	
}

int main() {
	char buffer[tam_buffer];
	char c;
	int var;
	int posi_palavra = 1;

	fgets(buffer, tam_buffer, stdin);

	while (buffer[point-1] != '\n'){
	
		if ((buffer[point] == ' ')||(buffer[point] == '\n')){ 
			//retira caractere da pilha;
			var = point+1;
			while (point >= posi_palavra){
				
				point--;
				c = pop();
				
				printf("%c", c);
			}
			if (buffer[point] != '\n'){
				printf(" ");
			}else{
				printf('\n');
			}
			point = var;
			posi_palavra = var;
				
		} else {
			//coloca caractere na pilha;
			push(buffer[point]);
			point++;	
		}
	}
	return 0;
}
