#include<stdio.h>
#include<stdlib.h>

void limparTela()
{
	system("cls");
}

void limparBuffer()
{
setbuf(stdin, NULL);
}


typedef struct listaTelefone {
      int telefone; 
      struct listaTelefone *prox;
};

typedef struct listaDisciplina {
      char disciplina[30]; 
      struct listaDisciplina *prox;
};

typedef struct aluno 
{
    int matricula;
    char nome[30];
    listaTelefone* telefone;
    char email[30];
    char curso[30];
    listaDisciplina* disciplina;
};


typedef struct listaAluno  {
      aluno conteudo; 
      struct listaAluno *prox;
};

listaTelefone* inicializaTelefone()
{
 return NULL;
}

listaDisciplina* inicializaDisciplina()
{
 return NULL;
}
listaAluno* inicializaAluno()
{
 return NULL;
}


int perguntaInserir(char tipo[20] ){
	int resposta;
	printf("\n*****  DESEJA INSERIR MAIS %s ? ******\n",tipo);
	printf("* [1] - SIM                      *\n");
	printf("* [0] - NAO                      *\n");
	scanf("%d",&resposta);
	limparBuffer();
	 return resposta;
}

listaAluno* insere(listaAluno* l, aluno conteudo)
{
		listaAluno* novoElemento = (listaAluno*)malloc(sizeof(listaAluno));
		novoElemento->conteudo = conteudo;
		novoElemento->prox = l;

		return novoElemento;	
}

listaTelefone* insereT(listaTelefone* l, int telefone)
{
		listaTelefone* novoElemento = (listaTelefone*)malloc(sizeof(listaTelefone));
		novoElemento->telefone = telefone;
		novoElemento->prox = l;

		return novoElemento;	
}

listaDisciplina* insereD(listaDisciplina* l, char disciplina[])
{
		listaDisciplina* novoElemento = (listaDisciplina*)malloc(sizeof(listaDisciplina));
		
	int i;
    for (i=0; i<30; i++) {
        novoElemento->disciplina[i] = disciplina[i];
    }
    novoElemento->disciplina[30] = '\0';
    novoElemento->prox = l;
		
		
		return novoElemento;
		
}



int preencherTelefone (){
	int novoTelefone;	
	printf("\nTelefone: ");
	scanf("%d",&novoTelefone);
	limparBuffer();
	
	return novoTelefone;
}

listaTelefone* insereTelefone(listaTelefone *l){
	
	int i = 1;
		
	while (i==1){
		int novoTelefone = preencherTelefone();
		l = insereT(l,novoTelefone);
		i = perguntaInserir("TELEFONES");
	}
	
	
	return l;
}

listaDisciplina* insereDisciplina(listaDisciplina *l){
	
	int i = 1;
		
	while (i==1){
		
		char novaDisciplina[30];
		printf("\nDisciplina: ");
		scanf("%[^\n]",&novaDisciplina);
		limparBuffer();
		
		l = insereD(l,novaDisciplina);
		i = perguntaInserir("DISCIPLINAS");
	}
	
	
	return l;
}


aluno preecheAluno(){
	
	
	listaTelefone* t = inicializaTelefone();
	listaDisciplina* d = inicializaDisciplina();
	aluno novoAluno;	
	limparTela();
	printf("****************************************\n");
	printf("***          Inserir Aluno           ***\n");
	printf("****************************************\n");
	printf("**     Entre com os dados do Aluno    **\n");
	
	printf("Matricula: ");
	scanf("%d",&novoAluno.matricula);
	limparBuffer();
	printf("\nNome: ");
	scanf("%[^\n]",&novoAluno.nome);
	limparBuffer();
	novoAluno.telefone = insereTelefone(t);
	limparBuffer();
	printf("\nEmail: ");
	scanf("%[^\n]",&novoAluno.email);
	limparBuffer();
	printf("\nCurso: ");
	scanf("%[^\n]",&novoAluno.curso);
	limparBuffer();
	novoAluno.disciplina = insereDisciplina(d);
	limparBuffer();
	
	return novoAluno;
	
}



listaAluno* insereAluno(listaAluno *l){
	
	int i = 1;
		
	while (i==1){
		aluno novoAluno = preecheAluno();
		l = insere(l,novoAluno);
		i = perguntaInserir("ALUNOS");
	}
	
	
	return l;
}





void imprimeAluno (listaAluno* l)
{
 listaAluno* p;
 listaTelefone* t;
 listaDisciplina* d;
 limparTela();
 	printf("****************************************\n");
	printf("***          Lista de Alunos         ***\n");
	printf("****************************************\n");
	
	
	if (l == NULL){
		printf("\n******      Lista Vazia     ******\n");
	}
	else{
	
 for (p = l; p!= NULL; p = p->prox){
 	printf("**********     Dados do Aluno    *******\n");
 	printf("Matricula: %d", p->conteudo.matricula); 
 	printf("\nNome: %s", p->conteudo.nome); 
 	
 	for (t = p->conteudo.telefone; t!= NULL; t = t->prox){		
 	printf("\nTelefone: %d", t->telefone);
 	}
 	
	printf("\nEmail: %s", p->conteudo.email);  
	printf("\nCurso: %s", p->conteudo.curso);
	
	for (d = p->conteudo.disciplina; d!= NULL; d = d->prox){		
 	printf("\nDisciplina: %s", d->disciplina);
 	}
 	printf("\n****************************************\n");
}

}
 
 
 system("pause");
}


 int main() {
 	listaAluno* l = inicializaAluno();
	int opcao;
		
while(1){
	
limparTela();

	printf("****************************************\n");
	printf("***                MENU              ***\n");
	printf("****************************************\n");
	printf("* [1] - INSERIR		               *\n");
	printf("* [2] - LISTAR		               *\n");
	printf("* [0] - SAIR		               *\n");
	printf("****************************************\n");
  
  printf ("Digite uma das Opcoes: ");
  scanf("%d", &opcao);
  limparBuffer();

	switch (opcao)
	{
	
	case 1:
		l = insereAluno(l);
   	break;

   	case 2:
   		imprimeAluno(l);
   	break;

   default:
   		exit(1);
	}
}
return 0;
}
