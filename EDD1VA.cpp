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

typedef struct aluno 
{
    int matricula;
    char nome[30];
    int telefone;
    char email[30];
    char curso[30];
    char disciplina[30];
};


typedef struct listaAluno  {
      aluno conteudo; 
      struct listaAluno *prox;
};

listaAluno* inicializaAluno()
{
 return NULL;
}


int perguntaInserir(){
	int resposta;
	printf("\n*****  DESEJA INSERIR MAIS ? ******\n");
	printf("* [1] - SIM                         *\n");
	printf("* [0] - NAO                         *\n");
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


aluno preecheAluno(){
	
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
	printf("\nTelefone: ");
	scanf("%d",&novoAluno.telefone);
	limparBuffer();
	printf("\nEmail: ");
	scanf("%[^\n]",&novoAluno.email);
	limparBuffer();
	printf("\nCurso: ");
	scanf("%[^\n]",&novoAluno.curso);
	limparBuffer();
	printf("\nDisciplica: ");
	scanf("%[^\n]",&novoAluno.disciplina);
	limparBuffer();
	
	return novoAluno;
	
}
listaAluno* insereAluno(listaAluno *l){
	
	int i = 1;	
	while (i==1){
		aluno novoAluno = preecheAluno();
		l = insere(l,novoAluno);
		i = perguntaInserir();
	}
	
	
	return l;
}


void imprimeAluno (listaAluno* l)
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
 	printf("****************************************\n");
 	printf("Matricula: %d", p->conteudo.matricula); 
 	printf("\nNome: %s", p->conteudo.nome); 
 	printf("\nTelefone: %d", p->conteudo.telefone);
	printf("\nEmail: %s", p->conteudo.email);  
	printf("\nCurso: %s", p->conteudo.curso);
	printf("\nDisciplina: %s", p->conteudo.disciplina);
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
