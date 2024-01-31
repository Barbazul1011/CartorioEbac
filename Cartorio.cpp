#include <stdio.h> //biblioteta de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em mémoria
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsavel por cadastrar os usuario  no sistema
{
	//inicio criação de variasveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variasveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do ususario
	scanf("%s", cpf); //%s refere-se a string

	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variável
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
		printf("Nao foi possivel abrir o arquivo, não localizado!.\n\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuario: ");
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
		printf("O usuario não se encontra no sistema! .\n\n");
		system("pause");
	}
	
}

int main()
	{
		int opcao=8; //definindo variáveis
		int laco=1;
		char senhadigitada[5]="a";
	
		printf("### Cartório da Ebac ###\n\n\n");
		printf("Login de administrador!\n\n\nDigite a sua senha: ");
		scanf("%s",senhadigitada);
	
		if(senhadigitada[5] =="admin")
		{
	
		
	
		for(laco=1;laco=10;)
 		{	
	
			system("cls");
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("### Cartório da Ebac ###\n\n\n"); //inicio do menu
			printf("Escolha a opção desejada do menu:\n\n\n");
			printf("\t1 - registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n\n"); 
			printf("opção: "); //fim do menu
		
			scanf("%d" , &opcao); //armazenamento a escolha do usuário

			system("cls"); //Responsavel por limpar a tela
		
			switch(opcao) //inicio da seleção
		
				{case 1:
			
				system("pause");
				registro(); //chamada de funções
				break;
				
				case 2:
			
				system("pause");
				consulta();
				break;
			
				case 3:
				deletar();
				break;
				
				default:
				printf("Essa opção nao esta disponivel!\n");
				system("pause");		
		
				} //fim da seleção
			}
	}
		else
		printf("Senha incorreta ! !");	
}
