#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno{
    char* Nome;
    float nota1;
    float nota2;
    float media;
    char* Situacao;
}Aluno;

int main(int argc, char* argv[]){
    //argc - count, quantidade de argumentos
    //argv - value, valor que é passado

    //Abrir o arquivo
    FILE *stream_de = fopen(argv[1], "r");  

    if(stream_de == NULL){
        perror("Arquivo não encontrado");
        exit(1);
    }
    //contador
    int j = 0;
    Aluno alunos[100];
    char linhas[101];
    //Pegar os dados
    while(fgets(linhas, 101, stream_de)){
        char* linha = strdup(linhas); 

        char* token_nome = strtok(linha, ","); //primeiro valor antes da ,
        //printf("%s\n", token_nome);
        char *split1 = strtok(NULL, ""); // guarda resto da linha
        //printf("%s", split1);

        char *telefone = strtok(split1, ",");
        //printf("%s\n", telefone);

        char *split2 = strtok(NULL, "");
        char *curso = strtok(split2, ",");
        //printf("%s\n", curso);
        char *split3 = strtok(NULL, "");
        char *nota1 = strtok(split3, ",");
        //printf("%s\n", nota1);
        //printf("%s", nota1);
        char *split4 = strtok(NULL, "");
        char *nota2 = strtok(split4, ",");
       //printf("%s\n", nota2);

       alunos[j].Nome = strdup(token_nome);
        alunos[j].nota1 = atof(nota1);
        alunos[j].nota2 = atof(nota2);

        float media = (atof(nota1) + atof(nota2)) / 2;

        alunos[j].media = media;

        if(media >= 7.0){
            alunos[j].Situacao = "APROVADO";
        }
        else{
            alunos[j].Situacao = "REPROVADO";
        }

        j++;
        free(linha); //limpar a linha no buffer
    }
    fclose(stream_de);
    //Exportar um arquivo
    FILE* stream_sf = fopen("SituacaoFinal.csv", "w"); //criar um arquivo e escrever
    //Nome,Media,Situacao
     for(int i = 0; i < j; i++){
        if(i == 0)
        {
            fprintf(stream_sf, "Nome, Media, Situação\n");
        }
        else
        {
            fprintf(stream_sf, "%s, %.2f, %s\n", alunos[i].Nome, alunos[i].media, alunos[i].Situacao);
        }
    }
    
    return 0;
}