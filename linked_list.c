#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    char *data; 
    struct Node *next; 
    struct Node *prev;
} Node; 

menu(){
    printf("1. insert at the beginning\n");
    printf("2. insert at the end\n");
    printf("3. delete at the beginning\n");
    printf("4. delete at the end\n");
    printf("5. recursive print\n");
    printf("6. recursive backwards print\n");
    printf("7. search\n");
    printf("8. ascending sort the elements\n");
    printf("9. descending sort the elements\n");
    printf("0. quit");
}

int main(){
    menu();
}
