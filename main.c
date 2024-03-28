#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "lib.h"
int main() {
	setlocale(LC_ALL, "Portuguese");
    
	int tamanho;
	int i;
    printf("Digite o tamanho do vetor desejado: ");
    scanf("%d", &tamanho);
	
	Data aniversarios[tamanho];
	Horario alarme[tamanho];
	Pessoa gurizada[tamanho];

	for(i=0; i<tamanho; i++){
		printf("Aniversário %i\n", i+1);
		aniversarios[i]=lerData();
		printf("Alarme %i\n", i+1);
		alarme[i] = lerHorario();
		printf("Gurizada %i\n", 1+i);
		gurizada[i]=lerPessoa();
		system("cls");
	}
	
	for(i=0; i<tamanho; i++){
		printf("\nDados da Pessoa: %i\n", i+1);
		imprimirData(aniversarios[i]);
		imprimirHorario(alarme[i]);
		imprimirPessoa(gurizada[i]);
	}
	
	int mes;
	printf("Escolha um mês para detectar suas ocorrências: ");
	scanf("%i", &mes);
	char *meses[12] = {"janeiro", "fevereiro", "março", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
	printf("\nO mês de %s teve %i ocorrências", meses[mes-1], contaDatasNoMes(&aniversarios, tamanho, mes));
	
	int hora;
	printf("\nDigite as horas: ");
	scanf("%i", &hora);
	printf("\nExiste(m) %i compromissos após às %i horas", contaCompromissosAposHora(&alarme, tamanho, hora), hora);

	printf("\nA média de IMC da pessoas registradas é: %.2f", mediaDePessoalIMC(&gurizada, tamanho));

	Pessoa *maisNova = consultaPessoaMaisNova(gurizada, tamanho);

    if (maisNova != NULL) {
        printf("\nA pessoa mais nova é:\n");
        imprimirPessoa(*maisNova); 
    } else {
        printf("\nErro: Nenhuma pessoa encontrada.\n");
    }
    
	Pessoa *maisBaixa = consultaPessoaMaisBaixa(gurizada, tamanho);

    if (maisBaixa != NULL) {
        printf("\nA pessoa mais baixa é:\n");
        imprimirPessoa(*maisBaixa); 
    } else {
        printf("\nErro: Nenhuma pessoa encontrada.\n");
    }
    
    free(aniversarios);
    free(alarme);
    free(gurizada);

    return 0;
}

