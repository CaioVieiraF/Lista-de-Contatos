#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct contatos {
    char name[50], email[50], detalhes[500];
    int number;
} ct[200];


char input(long size, int min){
    char term;
    int valid, option;

    valid = scanf("%d%c", &option, &term);
    if (option>size || option<min || valid != 2 || term != '\n') {
        printf("\nValor inválido!\n\n");
        return 0;
    }
    return option;
}


bool verifyEmail(char mail[50]){
    bool valid = false;

    char* contais = strchr(mail, '@');
    if (contais!=NULL) {
        contais = strstr(contais, ".com");
        if (contais!=NULL) {
            valid = true;
        }
        contais = strchr(mail, '@');
        contais = strstr(contais, ".br");
        if (contais!=NULL) {
            valid = true;
        }
    }

    return valid;

}


int menu(const char *list[5]){
    int i, option;
    printf("--------------------------\n" );
    for (i = 0; i < 5; i++) {
        printf("[%d] - %s\n", i+1, list[i]);
    }

    printf("\n|O que você escolhe: ");
    option = input(5,1);
    printf("\n");

    return option;
}


int verify(bool show){

    bool stop = false;
    int i = 0;
    int size;
    while (!stop) {
        for (size = 0; ct[i].name[size] != '\0'; ++size);
        if (size > 0) {
            if (show) {
                printf("%d - %s:\n", i+1, ct[i].name);
                printf("    |-%s\n", ct[i].email);
                printf("    |-%d\n", ct[i].number);
                printf("    |-%s\n", ct[i].detalhes);
            }
            i++;
        }else{
            stop = true;
        }
    }
    return i;

}


void add(bool save, const char *pwd){
    FILE *file;
    char name[50], email[50], detalhes[500];
    int size, number;
    size = verify(false);

    if (save) {
        file = fopen(pwd, "w");
        for (int i = 0; i < size; i++) {
            fprintf(file, "\n%s,", ct[i].name);
            fprintf(file, "%s,", ct[i].email);
            fprintf(file, "%d,", ct[i].number);
            fprintf(file, "%s", ct[i].detalhes);
        }
        fclose(file);

    } else {
        bool loop = true;
        while (loop) {
            printf("Escreva o nome: ");
            scanf("%s", name);
            printf("\nEscreva o email: ");
            scanf("%s", email);
            if (!verifyEmail(email)) {
                printf("Endereço de E-mail inválido!\n\n");
                continue;
            }
            printf("\nEscreva o numero: ");
            scanf("%d", &number);
            printf("\nEscreva algum detalhe: ");
            scanf("%s", detalhes);
            loop = false;
            strcpy(ct[size].name, name);
            strcpy(ct[size].email, email);
            ct[size].number = number;
            strcpy(ct[size].detalhes, detalhes);
        }
    }
}


void rm(){
    int option, size, i;
    size = verify(true);

    printf("\nNumero do contato a ser removido: ");
    option = input(size,1);
    option--;

    for (i=0; i<size; i++) {
        if (i>=option) {
            strcpy(ct[i].name, ct[i+1].name);
            strcpy(ct[i].email, ct[i+1].email);
            ct[i].number = ct[i+1].number;
            strcpy(ct[i].detalhes, ct[i+1].detalhes);
        }
    }
}


int edit(){
    int optionContact, optionAttribute, valid, size;
    char term, change[50];
    size = verify(true);

    printf("\nNumero do contato a ser editado: ");
    valid = scanf("%d%c", &optionContact, &term);
    if (optionContact>size || optionContact<1 || valid != 2 || term != '\n') {
        printf("\nValor inválido!\n\n");
        return 0;
    }
    optionContact--;

    printf("[1] Nome: %s\n", ct[optionContact].name);
    printf("[2] E-mail: %s\n", ct[optionContact].email);
    printf("[3] Número: %d\n", ct[optionContact].number);
    printf("[4] descrição: %s\n", ct[optionContact].detalhes);
    printf("\nEscolha o que vai mudar: ");
    valid = scanf("%d%c", &optionAttribute, &term);
    if (optionAttribute>4 || optionAttribute<1 || valid != 2 || term != '\n') {
        printf("\nValor inválido!\n\n");
        return 0;
    }

    switch (optionAttribute) {
        case 1:
            printf("Novo nome: ");
            scanf("%s", change);
            strcpy(ct[optionContact].name, change);
            break;
        case 2:
            printf("Novo email: ");
            scanf("%s", change);
            strcpy(ct[optionContact].email, change);
            break;
        case 3:
            printf("Novo número: ");
            scanf("%s", change);
            ct[optionContact].number = atoi(change);
            break;
        case 4:
            printf("Nova descrição: ");
            scanf("%s", change);
            strcpy(ct[optionContact].detalhes, change);
            break;
        default:
            printf("Erro\n");
    }

    return 0;
}


int main(int argc, char *argv[]){
    FILE *file;
    char *defaultFile = getenv("HOME");
    strcat(defaultFile, "/.contatos.txt");
    const char *fileName = (argv[1]==NULL)? defaultFile:argv[1];
    file = fopen (fileName,"r");
    char buff[255], c;
    int choose;
    bool condition = true;

    if (file!=NULL){
        int i, x;
        i = 0;
        c = fgetc(file);

        while (c != EOF) {
            x = 0;

            fscanf(file, "%s", buff);
            char *name = strtok(buff, ",");
            char *res[4];

            if (name != NULL) {
                while (x < 4 ) {
                    res[x] = name;
                    name = strtok(NULL, ",");
                    x++;
                }

                strcpy(ct[i].name, res[0]);
                strcpy(ct[i].email, res[1]);
                ct[i].number = atoi(res[2]);
                strcpy(ct[i].detalhes, res[3]);

            }
            i++;
            c = fgetc(file);
        }
        fclose (file);
    }

    while (condition) {
        const char *list[5] = {"Verificar", "Adicionar", "Remover", "editar", "Sair"};
        choose = menu(list);

        switch (choose) {
            case 1:
                verify(true);
                break;
            case 2:
                add(false, argv[1]);
                break;
            case 3:
                rm();
                break;
            case 4:
                edit();
                break;
            case 5:
                printf("Tchau!\n");
                condition = false;
                break;
            case 0:
                printf("Esse valor é inválido!\n");
                return 1;
                printf("Saindo...\n");
                condition = false;
                break;
            default:
                printf("%d\n", choose);
                printf("Erro!\n");
                break;
        }
    }
    add(true, fileName);
    return 0;
}
