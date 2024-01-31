#include <stdio.h> //biblioteta de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em m�moria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o responsavel por cadastrar os usuario  no sistema
{
	//inicio cria��o de variasveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de variasveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do ususario
	scanf("%s", cpf); //%s refere-se a string

	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s" , cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{ 
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Nao foi possivel abrir o arquivo, n�o localizado!.\n\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s",  conteudo);
		printf("\n\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do ususario a ser deletado: \n\n");
	scanf("%s" ,cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuario n�o se encontra no sistema! .\n\n");
		system("pause");
	}
	
}

int main()
	{
		int opcao=8; //definindo vari�veis
		int laco=1;
		char senhadigitada[5]="a";
	
		printf("### Cart�rio da Ebac ###\n\n\n");
		printf("Login de administrador!\n\n\nDigite a sua senha: ");
		scanf("%s",senhadigitada);
	
		if(senhadigitada[5] =="admin")
		{
	
		
	
		for(laco=1;laco=10;)
 		{	
	
			system("cls");
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("### Cart�rio da Ebac ###\n\n\n"); //inicio do menu
			printf("Escolha a op��o desejada do menu:\n\n\n");
			printf("\t1 - registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n\n"); 
			printf("op��o: "); //fim do menu
		
			scanf("%d" , &opcao); //armazenamento a escolha do usu�rio

			system("cls"); //Responsavel por limpar a tela
		
			switch(opcao) //inicio da sele��o
		
				{case 1:
			
				system("pause");
				registro(); //chamada de fun��es
				break;
				
				case 2:
			
				system("pause");
				consulta();
				break;
			
				case 3:
				deletar();
				break;
				
				default:
				printf("Essa op��o nao esta disponivel!\n");
				system("pause");		
		
				} //fim da sele��o
			}
	}
		else
		printf("Senha incorreta ! !");	
}
