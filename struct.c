#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include <locale.h>

// Fun��o para ler os dados da Data
Data lerData() {
    Data data;

    printf("Digite o dia: ");
    scanf("%d", &data.dia);

    printf("Digite o m�s: ");
    scanf("%d", &data.mes);

    printf("Digite o ano: ");
    scanf("%d", &data.ano);

    return data;
}

// Fun��o para validar a data
int validarData(Data data) {
    if (data.ano < 0 || data.mes < 1 || data.mes > 12)
        return 0;

    int dias_por_mes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Verifica se o ano bissexto
    if ((data.ano % 4 == 0 && data.ano % 100 != 0) || (data.ano % 400 == 0))
        dias_por_mes[1] = 29; // Fevereiro tem 29 dias em anos bissextos

    if (data.dia < 1 || data.dia > dias_por_mes[data.mes - 1])
        return 0;
        // Valida��o da data de nascimento
    if (!validarData(data)) {
        printf("Data de nascimento inv�lida!\n");
        // Tratamento de erro ou nova entrada de dados podem ser inclu�dos aqui
    }

    // Outras valida��es podem ser adicionadas aqui conforme necess�rio
    return 1;
}

// Fun��o para ler os dados do Horario
Horario lerHorario() {
    Horario horario;

    printf("Digite as horas: ");
    scanf("%d", &horario.horas);

    printf("Digite os minutos: ");
    scanf("%d", &horario.minutos);

    printf("Digite os segundos: ");
    scanf("%d", &horario.segundos);
	
	 // Valida��o do hor�rio
    if (!validarHorario(horario)) {
        printf("Hor�rio inv�lido!\n");
        // Tratamento de erro ou nova entrada de dados podem ser inclu�dos aqui
    }
    
    return horario;
}

// Fun��o para ler os dados da Pessoa
Pessoa lerPessoa() {
    Pessoa pessoa;
	Horario horario;
    printf("Digite a altura (metros): ");
    scanf("%f", &pessoa.altura);

    printf("Digite a idade: ");
    scanf("%i", &pessoa.idade);

    printf("Digite o sexo (M/F): ");
    scanf(" %c", &pessoa.sexo);

    printf("Digite o peso: ");
    scanf("%f", &pessoa.peso);

    return pessoa;
}

int validarHorario(Horario horario) {
    if (horario.horas < 0 || horario.horas > 23 ||
        horario.minutos < 0 || horario.minutos > 59 ||
        horario.segundos < 0 || horario.segundos > 59)
        return 0;
    // Outras valida��es podem ser adicionadas aqui conforme necess�rio
    return 1;
}

void escrevaDataExtenso(Data *data) {
    char *meses[12] = {"janeiro", "fevereiro", "mar�o", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
    printf("%d de %s de %d\n", data->dia, meses[data->mes - 1], data->ano);
}
void escrevaHoraPadrao12h(Horario *hora) {
    char periodo[3];
    if (hora->horas >= 12) {
        strcpy(periodo, "PM");
        if (hora->horas > 12)
            hora->horas -= 12;
    } else {
        strcpy(periodo, "AM");
        if (hora->horas == 0)
            hora->horas = 12;
    }
    printf("%02d:%02d:%02d %s\n", hora->horas, hora->minutos, hora->segundos, periodo);
}
float calculaIMC(Pessoa *alguem) {
    return alguem->peso / (alguem->altura * alguem->altura);
}

// Fun��o para imprimir os dados da Pessoa
void imprimirPessoa(Pessoa pessoa) {
    printf("Altura: %.2f metros\n", pessoa.altura);
    printf("Idade: %d anos\n", pessoa.idade);
    printf("Sexo: %c\n", pessoa.sexo);
    printf("Peso: %.2f kg\n", pessoa.peso);
	
    printf("IMC da pessoa: %.2f\n", calculaIMC(&pessoa));
}
void imprimirData(Data data) {
	printf("Data: %02d/%02d/%04d\n", data.dia, data.mes, data.ano);
	escrevaDataExtenso(&data);
}


void imprimirHorario(Horario horario){
	    printf("Hor�rio: %02d:%02d:%02d\n", horario.horas, horario.minutos, horario.segundos);
	escrevaHoraPadrao12h(&horario);
}

// Fun��o para contar quantas datas no vetor correspondem a um determinado m�s
int contaDatasNoMes(Data *vetData, int tamanho, int mes) {
    int contagem = 0, i = 0; // Inicializa o contador de datas no m�s especificado

    for (i = 0; i < tamanho; i++) {
        if (vetData[i].mes == mes) {
            contagem++; // Incrementa o contador se a data estiver no m�s especificado
        }
    }

    return contagem; // Retorna o total de datas no m�s especificado
}


// Fun��o para contar quantos compromissos no vetor ocorrem ap�s uma determinada hora
int contaCompromissosAposHora(Horario *vetHorario, int tamanho, int hora) {
    int contagem = 0, i = 0; // Inicializa o contador de compromissos ap�s a hora especificada

    for (i = 0; i < tamanho; i++) {
        if (vetHorario[i].horas > hora) {
            contagem++; // Incrementa o contador se o compromisso ocorrer ap�s a hora especificada
        } else if (vetHorario[i].horas == hora && vetHorario[i].minutos > 0) {
            contagem++; // Incrementa o contador se o compromisso ocorrer na mesma hora, mas ap�s os minutos 0
        }
    }

    return contagem; // Retorna o total de compromissos ap�s a hora especificada
}

// Fun��o para calcular a m�dia do IMC das pessoas no vetor
float mediaDePessoalIMC(Pessoa *vetPessoa, int tamanho) {
    float somaIMC = 0.0, i = 0; // Inicializa a soma dos IMCs das pessoas

    // Calcula a soma dos IMCs de todas as pessoas no vetor
	for (i = 0; i < tamanho; i++) {
		Pessoa pessoai = *vetPessoa;
    	somaIMC+= calculaIMC(&pessoai);
	}
	
    // Calcula a m�dia do IMC das pessoas
    float mediaIMC = somaIMC / tamanho;
    return mediaIMC;
}

// Fun��o para consultar a pessoa mais nova no vetor
Pessoa *consultaPessoaMaisNova(Pessoa *vetPessoa, int tamanho) {
	int i;
    if (tamanho <= 0 || vetPessoa == NULL) {
        return NULL; // Retorna NULL se o vetor for vazio ou inv�lido
    }

    Pessoa *maisNova = &vetPessoa[0]; // Assume que a primeira pessoa � a mais nova inicialmente

    for (i = 1; i < tamanho; i++) {
        if (vetPessoa[i].idade < maisNova->idade) {
            maisNova = &vetPessoa[i]; // Atualiza a pessoa mais nova encontrada at� agora
        }
    }

    return maisNova; // Retorna um ponteiro para a pessoa mais nova no vetor
}

// Fun��o para consultar a pessoa mais baixa no vetor
Pessoa *consultaPessoaMaisBaixa(Pessoa *vetPessoa, int tamanho) {
	int i;
    if (tamanho <= 0 || vetPessoa == NULL) {
        return NULL; // Retorna NULL se o vetor for vazio ou inv�lido
    }

    Pessoa *maisBaixa = &vetPessoa[0]; // Assume que a primeira pessoa � a mais baixa inicialmente

    for (i = 1; i < tamanho; i++) {
        if (vetPessoa[i].altura < maisBaixa->altura) {
            maisBaixa = &vetPessoa[i]; // Atualiza a pessoa mais baixa encontrada at� agora
        }
    }

    return maisBaixa; // Retorna um ponteiro para a pessoa mais baixa no vetor
}

