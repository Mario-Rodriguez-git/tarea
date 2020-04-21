#include <stdlib.h>
#include <stdio.h>

static const int MAX_SIZE=1024; 

typedef struct Node{
    char * data; 
    struct Node *next; 
    struct Node *prev;
} Node; 

int menu(int * slc){
    printf("1. insert at the beginning\n2. insert at the end\n3. delete at the beginning\n4. delete at the end\n5. recursive print\n6. recursive backwards print\n7. search\n8. ascending sort the elements\n9. descending sort the elements\n0. quit\n");
    scanf("%d *[^\n]",slc);
    return 0;
}

char * ntr_str(){
    char * str = malloc(MAX_SIZE);
    fgets(str, MAX_SIZE-1, stdin); 
    return str;
}

Node * mk_nd(){
    Node * node = malloc(sizeof(Node));
    node -> data = ntr_str();
    return node;
}

int insrt_b(Node ** head, Node *node){
    return 0;
}

int insrt_e(Node ** head, Node *node){
    return 0;
}

int dlte_b(Node ** head){
    return 0;
}

int dlte_e(Node ** head){
    return 0;
}

int rprint(Node ** head){
    return 0;
}

int rbprint(Node ** head){
    return 0;
}

int search(Node ** head, char * str){
    return 0;
}

int asort(Node ** head){
    return 0;
}

int dsort(Node ** head){
    return 0;
}

int main(){
    int slc;
    Node * head;
    while(slc){
        menu(&slc);
        switch(slc){
            case 1:
                insrt_b(&head, mk_nd());
                break;
            case 2:
                insrt_e(&head, mk_nd()); 
                break;
            case 3:
                dlte_b(&head);
                break;
            case 4: 
                dlte_e(&head);
                break;  
            case 5: 
                rprint(&head);
                break;
            case 6: 
                rbprint(&head);
                break;
            case 7: 
                search(&head, ntr_str());
                break;
            case 8:
                asort(&head);
                break;
            case 9:
                dsort(&head);
                break;
        }
    }
    return 0;
}
