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
		printf("Anivers�rio %i\n", i+1);
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
	printf("Escolha um m�s para detectar suas ocorr�ncias: ");
	scanf("%i", &mes);
	char *meses[12] = {"janeiro", "fevereiro", "mar�o", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
	printf("\nO m�s de %s teve %i ocorr�ncias", meses[mes-1], contaDatasNoMes(&aniversarios, tamanho, mes));
	
	int hora;
	printf("\nDigite as horas: ");
	scanf("%i", &hora);
	printf("\nExiste(m) %i compromissos ap�s �s %i horas", contaCompromissosAposHora(&alarme, tamanho, hora), hora);

	printf("\nA m�dia de IMC da pessoas registradas �: %.2f", mediaDePessoalIMC(&gurizada, tamanho));

	Pessoa *maisNova = consultaPessoaMaisNova(gurizada, tamanho);

    if (maisNova != NULL) {
        printf("\nA pessoa mais nova �:\n");
        imprimirPessoa(*maisNova); 
    } else {
        printf("\nErro: Nenhuma pessoa encontrada.\n");
    }
    
	Pessoa *maisBaixa = consultaPessoaMaisBaixa(gurizada, tamanho);

    if (maisBaixa != NULL) {
        printf("\nA pessoa mais baixa �:\n");
        imprimirPessoa(*maisBaixa); 
    } else {
        printf("\nErro: Nenhuma pessoa encontrada.\n");
    }
    
    free(aniversarios);
    free(alarme);
    free(gurizada);

    return 0;
}

