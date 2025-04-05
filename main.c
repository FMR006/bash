#include <stdio.h>
#include <string.h>
#define flag_size 20
#define file_path_size 256

void input(char* flag);
int number_nonblank(char* file_path);
int end_char (char* file_path);

int main(){
char flag[flag_size] = {0};
char file_path[file_path_size] = {0};
input(flag);
input(file_path);
if (strcmp(flag, "-b") == 0 || strcmp(flag, "--number-nonblank") == 0){
    printf ("вы выбрали нумерацию не пустых строк...\n");
    printf ("вы выбрали файл %s...\n", file_path);
    number_nonblank(file_path);
}
else if (strcmp(flag, "-e") == 0 || strcmp(flag, "-E") == 0){
    printf ("вы выбрали отображение символа конца строки...\n");
    printf ("вы выбрали файл %s...\n", file_path);
    end_char(file_path);
}

else{
    printf ("вы ошиблись c флагом");
}

}

void input(char* flag){
    scanf("%s", flag);
}

int number_nonblank(char* file_path){
    FILE *file = fopen(file_path, "r"); 
if (file == NULL) {
    printf("Ошибка открытия файла");
    fclose(file);
    return 0;
}
else{
    char line[1024];
    int count = 1;
    while (fgets(line, sizeof(line), file)){
        if(strcmp(line, "\n") != 0){
            printf ("%d %s", count, line);
            count += 1;
        }
        else{
            printf("%s", line);
        }
    }
}
fclose(file);
return 1;
}

int end_char(char* file_path){
    FILE *file = fopen(file_path, "r"); 
    if (file == NULL) {
        printf("Ошибка открытия файла");
        fclose(file);
        return 0;
    }
    else{
        char line[1024];
        while (fgets(line, sizeof(line), file)){
            line[strcspn(line, "\n")] = 0;
            int next_char = fgetc(file);
        if (next_char == EOF) {
            printf("%s", line);
            fclose(file);
            return 1;
        } else {
            ungetc(next_char, file);
        }
            printf("%s$\n", line);
            }
    }
    fclose(file);
    return 1;
}
