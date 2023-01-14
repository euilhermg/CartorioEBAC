#include <stdio.h> // Biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca de aloca��o de texto por regi�o
#include <string.h> // Biblioteca respons�vel pelas strings

int registro()
{ // Coment�rio
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo [40];

	printf("Digite CPF a ser cadastrado: ");
	scanf("%s", cpf); // Coment�rio

	strcpy(arquivo, cpf); // Coment�rio

	FILE *file; // Coment�rio
	file = fopen(arquivo, "w");
	fprintf(file, "CPF: ");
	fprintf(file, cpf);
	fclose(file);

	file = fopen(arquivo, "a"); // Coment�rio
	fprintf(file, ", ");
	fclose(file);

	printf("Digite nome a ser cadastrado: "); // Coment�rio
	scanf("%s",nome);

	file = fopen(arquivo, "a");
	fprintf(file, "Nome: "); // Coment�rio
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ", "); // Coment�rio
	fclose(file);

	printf("Digite sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Sobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);

	printf("Digite cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Cargo: ");
	fprintf(file,cargo);
	fclose(file);

	system("pause");
}

int consulta()
{
	char cpf[40];
	char conteudo[200];
	setlocale(LC_ALL, "Portuguese");	

	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	printf("Usu�rio n�o localizado \n");
	}
	
	while(fgets(conteudo, 200,file) != NULL);
	{
	printf("Essas s�o as informa��es do usu�rio: \n");
	printf("%s", conteudo);
	printf("\n\n");
	}
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: \n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("CPF n�o encontrado! \n");
		system("pause");
	}
}

int main()
{
	int opcao=0;
	int laco=1;
	{
		for(laco=1;laco=10;) 
		{
			
			system("cls"); 

			setlocale(LC_ALL, "Portuguese"); 

			printf("\t\t\t Cart�rio da Silva\n\n");
			printf("Escolha a op��o desejada abaixo: \n\n");
			printf("\t 1 - Registro de nomes \n");
			printf("\t 2 - Cadastro de nomes \n");
			printf("\t 3 - Exclus�o de nomes \n"); 
			printf("\t 4- Sair para �rea de trabalho \n");
			printf("Opc�o: \t");

			scanf("%d", &opcao); 

			system("cls"); 

			switch(opcao) 
			{
				case 1:
				registro();
		  		break;

				case 2:
				consulta();
				break;

				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar nosso sistema de registro :D \n");
				return 0;
				break;
			
				default: 
				printf("Esta op��o n�o existe \n");
				system("pause");
				break;
			}
		}
	}
}
