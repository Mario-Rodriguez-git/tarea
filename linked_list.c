#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static const int MAX_SIZE=1024; 

typedef struct Node {
    char * data; 
    struct Node *next; 
    struct Node *prev;
} Node; 

int menu() {
    printf("1. insert at the beginning\n2. insert at the end\n3. delete at the beginning\n4. delete at the end\n5. recursive print\n6. recursive backwards print\n7. search\n8. ascending sort the elements\n9. descending sort the elements\n0. quit\n");
    return 0;
}

char * ntr_str() {
    char * str = malloc(MAX_SIZE);
    fgets(str, MAX_SIZE-1, stdin); 
    return str;
}

Node * mk_nd() {
    Node * node = malloc(sizeof(Node));
    node -> data = ntr_str();
    return node;
}

int insrt_b(Node ** head, Node * node) {
    Node * tmp = * head;
    node -> next = * head;
    if(* head)
        tmp -> prev = node; 
    * head = node;
    return 0;
}

int insrt_e(Node ** head, Node * node) {
    Node * tmp = * head;
    Node * prev_node;
    if(tmp) {
        while(tmp -> next) {
            prev_node = tmp;
            tmp = tmp -> next; 
        }
    tmp -> next = node; 
    node -> prev = tmp;
    }
    else {
        * head = node;
    }
    return 0;
}

int dlte_b(Node ** head) {
    Node * tmp = * head; 
    if(tmp){
        if(tmp -> next) {
            Node * tmp_next = tmp -> next;
            * head = tmp_next;
            tmp_next -> prev = NULL;
        }
        else {
            * head = NULL; 
        }
        tmp -> prev = NULL;
        tmp -> next = NULL;
        tmp -> data = NULL;
        free(tmp);
    }
    return 0;
}

int dlte_e(Node ** head) {
    Node * tmp = * head; 
    if(tmp) {
        while(tmp -> next) {
           tmp = tmp -> next;    
        }
        if(tmp -> prev) {
            Node * tmp_prev = tmp -> prev; 
            tmp_prev -> next = NULL;
        }
        if(tmp == * head) {
            * head = NULL;
        }
        tmp -> prev = NULL;
        tmp -> next = NULL;
        tmp -> data = NULL;
        free(tmp);
    }
    return 0;
}

int rprint(Node * ptn) {
    if(ptn) {
        printf("Location: %p | Data: %s\n", ptn, ptn -> data); 
        rprint(ptn -> next);
    }
    return 0;
}

int rbprint(Node * ptn) {
    if(ptn) {
        rbprint(ptn -> next);
        printf("Location: %p | Data: %s\n", ptn, ptn -> data); 
    }
    return 0;
}

char * search(Node ** head, char * str) {
    Node * tmp = * head;
    while(tmp){
        if(!(strcmp(tmp -> data, str)))
            return ("FOUND\n");
        tmp = tmp -> next;
    }
    return "NOT FOUND\n";
}

int asort(Node ** head) {
    return 0;
}

int dsort(Node ** head) {
    return 0;
}

int main() {
    char str_val[MAX_SIZE];
    int slc = 1;
    Node * head = NULL;
    while(slc) {
        menu();
        fgets(str_val, MAX_SIZE-1, stdin); 
        slc = atoi(str_val);
        switch(slc) {
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
                rprint(head);
                break;
            case 6: 
                rbprint(head);
                break;
            case 7: 
                printf("%s", search(&head, ntr_str()));
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
