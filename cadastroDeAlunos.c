#include <stdio.h>
#include <stdlib.h>

struct Aluno
{
    char name[20];
    long int mat;
    float note1;
    float note2;
    float note3;
    float note4;
};

struct Aluno arrAluno[2];

int len = sizeof(arrAluno) / sizeof(arrAluno[0]);

//--------- page Header --------------
void header()
{
    printf("========================\n");
    printf("   Cadastro de Alunos   \n");
    printf("========================\n");
}

void headerInsertStudent()
{
    printf("========================\n");
    printf("     Inserir Alunos     \n");
    printf("========================\n");
}

void headerSelectStudent()
{
    printf("========================\n");
    printf("     Mostrar Alunos     \n");
    printf("========================\n");
}

void headerUpdateStudent()
{
	printf("========================\n");
    printf("     Alterar Alunos     \n");
    printf("========================\n");
}
//------------------------------------

//---------- Insert Student ----------
void insertStudent(int i)
{
    printf("Nome......: ");
    scanf("%s", arrAluno[i].name);

    printf("Matricula.: ");
    scanf("%ld", &arrAluno[i].mat);

    printf("Nota 1....: ");
    scanf("%f", &arrAluno[i].note1);

    printf("Nota 2....: ");
    scanf("%f", &arrAluno[i].note2);

    printf("Nota 3....: ");
    scanf("%f", &arrAluno[i].note3);

    printf("Nota 4....: ");
    scanf("%f", &arrAluno[i].note4);
}
//-------------------------------------

/*//------ Insert Student File TXT ------
void saveStudentsTXTFile(){
	int i;
	FILE*file;
	file = fopen("file_students.txt", "a");
	
	for(i=0; i<len; i++){
		fprintf(file,"%s %ld %.2f %.2f %.2f %.2f\n", arrAluno[i].name, arrAluno[i].mat, arrAluno[i].note1, arrAluno[i].note2, arrAluno[i].note3, arrAluno[i].note4);
	}
	
	fclose(file);
}
//-------------------------------------*/

//----------- Select Student ----------
float calculateAverage(float note1, float note2, float note3, float note4)
{
    return ((note1 + note2 + note3 + note4) / 4);
}

void studentSituation(float average)
{
    if (average > 7)
    {
        printf("Situacao..: Aprovado");
    }
    else if (average > 4)
    {
        printf("Situacao..: Recuperacao");
    }
    else
    {
        printf("Situacao..: Reprovado");
    }
}

void selectStudent(int i)
{
	/*char name[20], student[200];
	int mat;
	float note1, note2, note3, note4;
	
	FILE *file;
    file = fopen("file_students.txt", "r");
	fscanf(file, "%s %i %f %f %f %f", &name, &mat, &note1, &note2, &note3, &note4);
	while (fgets(student,100,file) != NULL){
		printf(student);

    fclose(file);
	}*/
	
    float average = 0;
    printf("Nome......: %s\n", arrAluno[i].name);
    printf("Matricula.: %ld\n", arrAluno[i].mat);
    printf("1 nota...: %.2f\n", arrAluno[i].note1);
    printf("2 nota...: %.2f\n", arrAluno[i].note2);
    printf("3 nota...: %.2f\n", arrAluno[i].note3);
    printf("4 nota...: %.2f\n", arrAluno[i].note4);
    average = calculateAverage(arrAluno[i].note1, arrAluno[i].note2, arrAluno[i].note3, arrAluno[i].note4);
    printf("Media.....: %.2f\n", average);
    studentSituation(average);
}
//---------------------------------------

//----------- Change Student ------------
void changeStudent()
{
    int i;
    long int mat;
    printf("\nInforme a matricula digitada do aluno cadastrado: ");
    scanf("%ld", &mat);
    for (i = 0; i < len; i++)
    {
        if (arrAluno[i].mat == mat)
        {
            insertStudent(i);
            break;
        }
    }
    printf("\nO aluno foi alterado com sucesso.");
}

void choiceOfCase(int option)
{
    int i;
    switch (option)
    {
    case 1:
        system("cls");
        headerInsertStudent();
        for (i = 0; i < len; i++)
        {
            insertStudent(i);
            printf("\n------------------------\n");
        }
        /*saveStudentsTXTFile();*/
        break;

    case 2:
        system("cls");
        headerUpdateStudent();
        for (i = 0; i < len; i++)
        {
            selectStudent(i);
            printf("\n------------------------\n");
        }
        changeStudent();
        break;

    case 3:
    	system("cls");
        headerSelectStudent();
        for (i = 0; i < len; i++){
           
            selectStudent(i);
            printf("\n------------------------\n");
            
        }
        break;
    }
}

int main()
{
    int option = 0, flag = 1;
    system("cls");
    header();
    do
    {
        printf("O que deseja fazer: \n[1] Incluir \n[2] Alterar \n[3] Mostar\nR: ");
        scanf("%d", &option);

        choiceOfCase(option);

        printf("Deseja continuar no programa? [1] Sim e [0] Nao: ");
        scanf("%d", &flag);

        system("cls");
    } while (flag);
    return 0;
}
