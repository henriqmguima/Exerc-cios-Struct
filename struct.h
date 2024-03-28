#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

// Definição do tipo de dado Data
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

// Definição do tipo de dado Horario
typedef struct {
    int horas;
    int minutos;
    int segundos;
} Horario;

// Definição do tipo de dado Pessoa
typedef struct {
    float altura;
    int idade;
    char sexo;
    float peso;
} Pessoa;


Data lerData();
int validarData(Data data);
Horario lerHorario();
Pessoa lerPessoa();
int validarHorario(Horario horario);

void imprimirPessoa(Pessoa pessoa);
void imprimirData(Data data);
void imprimirHorario(Horario horario);

void escrevaDataExtenso(Data *data);
void escrevaHoraPadrao12h(Horario *hora);
float calculaIMC(Pessoa *alguem);

int contaDatasNoMes(Data *vetData, int tamanho, int mes);
int contaCompromissosAposHora(Horario *vetHorario, int tamanho, int hora);
float mediaDePessoalIMC(Pessoa *vetPessoa, int tamanho);
Pessoa *consultaPessoaMaisNova(Pessoa *vetPessoa, int tamanho);
Pessoa *consultaPessoaMaisBaixa(Pessoa *vetPessoa, int tamanho);
#endif /* STRUCT_H_INCLUDED */
