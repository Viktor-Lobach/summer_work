#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "function.h"

Node* initList(  ){
    Node *head = NULL;
    #define init_list
    return head;
}

#ifdef init_list
    int lenght = 0;
#endif 


void push( Node** head, DATA _struct_, size_t size ){
    Node *tmp = (Node*)malloc(sizeof(Node));
    
    tmp -> _struct_data_ = malloc( size );

    memcpy(tmp->_struct_data_, _struct_, size);

    tmp -> next = *head;
    *head = tmp;
    lenght++;
}

void deleteList( Node **head ){
    Node *prev = NULL;
    while ( (*head) )
    {
        prev = *head;
        free( (*head) -> _struct_data_);
        (*head) = (*head) -> next;
        free(prev);
        lenght--;
    }
}

void pushBack( Node *head, DATA _struct_, size_t size){
    Node *tmp = (Node*)malloc(sizeof(Node));

    tmp -> _struct_data_ = malloc( size );
    memcpy(tmp -> _struct_data_, _struct_, size);
    tmp -> next = NULL;

    while( head ){
        if (head -> next == NULL){
            head -> next = tmp;
            lenght++;
            break;        
        }
        head = head -> next;
    }
}

void pushAdress(Node *obj, Node* pushed ){
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp -> next = obj -> next;
    tmp -> _struct_data_ = pushed -> _struct_data_;
    
    obj -> next = tmp;
    printf("\tPush successfull. Please enter another later...");
}

void pop( Node *head ){
    Node* tmp = head -> next;
    head -> next = tmp -> next;
    free(tmp);
    lenght--;
}

void popHead( Node** head ){
    if ( *head != NULL){
        Node* tmp = (*head);
        (*head) = tmp -> next;
        free(tmp);
        lenght--;
    }
}

void indexInsert( Node** head, int index ){
    int iter = 1;
    Node* pIter = (*head);

    if (index > lenght){
        printf("\n\tThe index goes beyond the bounds of the list...\n");
        return; }

    if ( *head == NULL )
        return;

    while ( pIter ){
        if (iter == index - 1){
            Node* tmp = pIter -> next;
            pIter -> next = tmp -> next;
            free(tmp);
            lenght--;
        }
        iter++;
        pIter = pIter -> next;
    }
    
}

void swap( Node **head, Node **obj ){

    if ( (*head) != (*obj) && (*head) != NULL && (*obj) != NULL ){
        if( (*head) -> next == (*obj) ){
            Node *tmp = (*head);
            Node *p_next = (*obj) -> next;

            (*head) = (*obj); 
            (*obj) -> next = tmp; 
            tmp -> next = p_next; 
        }
        else{
            Node* tmp = (*head), *p_next = (*obj)->next, *buf;
            (*head) = (*obj);
            (*head)->next = tmp->next;

            buf = (*head);
            while( (*head) ){
                if ( (*head) -> next == (*obj) ){
                    tmp -> next = p_next;
                    (*head)->next = tmp;
                    break;
                }

                (*head) = (*head) -> next;
            }
            (*head) = buf;
        }
    }
    printf("\tSwap successfull. Please enter another later...");
}

void sortList( Node *head, Node *(*func_sort)(Node *) ){
    Node *tmp = NULL;
    void *tmp_struct;
    do{
        tmp = func_sort( head );



        if(head != tmp){
            tmp_struct = head ->_struct_data_;
            head->_struct_data_ = tmp->_struct_data_;
            tmp->_struct_data_ = tmp_struct;
        }

        head = head -> next;
    }while( head );
    printf("\n\tList sorted!\n\tPleas, enter another later... "); fflush(stdin);
}

int getLenght(){ return lenght; }
