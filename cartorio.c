#include <stdio.h> // Biblioteca de comunicação com o usuário 
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocação de texto por região
#include <string.h> // Biblioteca responsável pelas strings

int registro()
{ // Comentário
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo [40];

	printf("Digite CPF a ser cadastrado: ");
	scanf("%s", cpf); // Comentário

	strcpy(arquivo, cpf); // Comentário

	FILE *file; // Comentário
	file = fopen(arquivo, "w");
	fprintf(file, "CPF: ");
	fprintf(file, cpf);
	fclose(file);

	file = fopen(arquivo, "a"); // Comentário
	fprintf(file, ", ");
	fclose(file);

	printf("Digite nome a ser cadastrado: "); // Comentário
	scanf("%s",nome);

	file = fopen(arquivo, "a");
	fprintf(file, "Nome: "); // Comentário
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ", "); // Comentário
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
	printf("Usuário não localizado \n");
	}
	
	while(fgets(conteudo, 200,file) != NULL);
	{
	printf("Essas são as informações do usuário: \n");
	printf("%s", conteudo);
	printf("\n\n");
	}
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: \n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("CPF não encontrado! \n");
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

			printf("\t\t\t Cartório da Silva\n\n");
			printf("Escolha a opção desejada abaixo: \n\n");
			printf("\t 1 - Registro de nomes \n");
			printf("\t 2 - Cadastro de nomes \n");
			printf("\t 3 - Exclusão de nomes \n"); 
			printf("\t 4- Sair para Área de trabalho \n");
			printf("Opcão: \t");

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
				printf("Esta opção não existe \n");
				system("pause");
				break;
			}
		}
	}
}
