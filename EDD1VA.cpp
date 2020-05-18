#include<stdio.h>
#include<stdlib.h>
#include <string.h> 

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

listaAluno* buscaNome (char nome[30], listaAluno* l)
{
   listaAluno *p;
   p = l;
   while (p != NULL && strcmp(p->conteudo.nome, nome) != 0) {
   
      p = p->prox; }
   return p;
}

listaAluno* buscaMatricula (int matricula, listaAluno* l)
{
   listaAluno *p;
   p = l;
   while (p != NULL && p->conteudo.matricula != matricula) {
   
      p = p->prox; }
   return p;	
}

listaAluno* buscaRemove (char nome[30], listaAluno *l)
{
   listaAluno *p, *q;
   p = l;
   q = l->prox;
   while (q != NULL && strcmp(q->conteudo.nome, nome) != 0) {
      p = q;
      q = q->prox;
   }
   if (q != NULL) {
      p->prox = q->prox;
      free (q);
   }
   return p;
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

imprimirAluno(aluno aluno){
 listaTelefone* t;
 listaDisciplina* d;
printf("**********     Dados do Aluno    *******\n");
 	printf("Matricula: %d", aluno.matricula); 
 	printf("\nNome: %s", aluno.nome); 
 	
 	for (t = aluno.telefone; t!= NULL; t = t->prox){		
 	printf("\nTelefone: %d", t->telefone);
 	}
 	
	printf("\nEmail: %s", aluno.email);  
	printf("\nCurso: %s", aluno.curso);
	
	for (d = aluno.disciplina; d!= NULL; d = d->prox){		
 	printf("\nDisciplina: %s", d->disciplina);
 	}
 	printf("\n****************************************\n");
}



void imprimeAlunos (listaAluno* l)
{
 listaAluno* p;
 limparTela();
 	printf("****************************************\n");
	printf("***          Lista de Alunos         ***\n");
	printf("****************************************\n");
	
	
	if (l == NULL){
		printf("\n******      Lista Vazia     ******\n");
	}
	else{
	
 for (p = l; p!= NULL; p = p->prox){
 imprimirAluno(p->conteudo);
}
}
 
 
 system("pause");
}

listaAluno* buscaInsere (aluno x, aluno y, listaAluno *le)
{
	
 listaAluno *p;
   p = le;
   while (p != NULL && strcmp(p->conteudo.nome, y.nome) != 0) {
      p = p->prox; }
      
      p->conteudo = x;
   return le;
}


void buscaCurso (char curso[30],listaAluno* l)
{
 listaAluno* p;
 limparTela();
 	printf("****************************************\n");
	printf("***          Lista de Alunos         ***\n");
	printf("****************************************\n");
	
	
	if (l == NULL){
		printf("\n******      Lista Vazia     ******\n");
	}
	else{
	
 for (p = l; p!= NULL; p = p->prox){
 	if(strcmp(p->conteudo.curso, curso) == 0){
 imprimirAluno(p->conteudo);
}
}
}
 
 
 system("pause");
}

int pergunta2(){
	
	int opcao;
	printf("* [1] - EDITAR		        *\n");
	printf("* [2] - EXCLUIR			        *\n");
	printf("* [0] - SAIR		 		*\n");
	scanf("%d", &opcao);
  	limparBuffer();
  
  return opcao;
}


listaAluno* buscar(listaAluno* l){
	int opcao;
	aluno novoAluno;
	listaAluno* le;
	limparTela();
 	printf("*****************************************\n");
	printf("Escolha por qual Informacao deseja Buscar\n");
	printf("*****************************************\n");
	printf("* [1] - MATRICULA		        *\n");
	printf("* [2] - NOME			        *\n");
	printf("* [0] - SAIR		 		*\n");
	printf ("Digite uma das Opcoes: ");
  scanf("%d", &opcao);
  limparBuffer();
  switch (opcao)
	{
	
	case 1:
		printf("**** Insira a Matricula do Aluno ********\n");
   		printf("\nMatricula: ");
		scanf("%d",&novoAluno.matricula);
		limparBuffer();
		le = NULL;
		le = buscaMatricula(novoAluno.matricula,l);


		if (le==NULL){
			printf("\nMatricula nao encontrado\n");
			 system("pause");
		}
		else{
			
			imprimirAluno(le->conteudo);
			int y = pergunta2();
			if(y==1){
				aluno novoAluno = preecheAluno();
				l = buscaInsere(novoAluno,le->conteudo,l);
				printf("\nAlterado\n");
				system("pause");
			}
			if(y==2){
			l = buscaRemove(le->conteudo.nome,l);
			printf("\nRemovido\n");
			system("pause");
			}
		}
   	break;

   	case 2:
   		printf("**** Insira o Nome do Aluno ********\n");
   		printf("\nNome: ");
		scanf("%[^\n]",&novoAluno.nome);
		limparBuffer();
		le = NULL;
		le = buscaNome(novoAluno.nome,l);
		if (le==NULL){
			printf("\nNome nao encontrado\n");
			system("pause");
		}
		else{
			
			imprimirAluno(le->conteudo);
			int y = pergunta2();
			if(y==1){
				aluno novoAluno = preecheAluno();
				l = buscaInsere(novoAluno,le->conteudo,l);
				printf("\nAlterado\n");
				system("pause");
				
			}
			if(y==2){
			l = buscaRemove(le->conteudo.nome,l);
			printf("\nRemovido\n");
			system("pause");
			}
		}
   	break;
   default:;
	}
	
	return l;
}

 int main() {
 	listaAluno* l = inicializaAluno();
 	aluno novoAluno;
	int opcao;
		
while(1){
	
limparTela();

	printf("****************************************\n");
	printf("***                MENU              ***\n");
	printf("****************************************\n");
	printf("* [1] - INSERIR		               *\n");
	printf("* [2] - LISTAR TODOS      	       *\n");
	printf("* [3] - BUSCAR (EDITAR/EXCLUIR)        *\n");
	printf("* [4] - BUSCA POR CURSO	     	       *\n");
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
   		imprimeAlunos(l);
   	break;
   	
   	case 3:
   		l = buscar(l);
   	break;
   	
   		case 4:
   		printf("**** Insira o Curso ********\n");
   		printf("\nCurso: ");
		scanf("%[^\n]",&novoAluno.curso);
   		buscaCurso(novoAluno.curso,l);
   	break;

   default:
   		exit(1);
	}
}
return 0;
}
