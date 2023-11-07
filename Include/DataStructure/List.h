#pragma once


#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>



// Define a generic linked list type
#define __CLASS__LIST__SIMULATOR__(LinkedListType, NodeType)                                                                        \
    typedef struct LinkedListType##Node                                                                                             \
    {                                                                                                                               \
        NodeType data;                                                                                                              \
        struct LinkedListType##Node *next;                                                                                          \
    } LinkedListType##Node;                                                                                                         \
                                                                                                                                    \
    typedef struct                                                                                                                  \
    {                                                                                                                               \
        LinkedListType##Node *head;                                                                                                 \
        size_t size;                                                                                                                \
    } LinkedListType;                                                                                                               \
                                                                                                                                    \
    /* Create a new linked list */                                                                                                  \
    LinkedListType *create_##LinkedListType()                                                                                       \
    {                                                                                                                               \
        LinkedListType *list = (LinkedListType *)malloc(sizeof(LinkedListType));                                                    \
        if (list == NULL)                                                                                                           \
        {                                                                                                                           \
            return NULL;                                                                                                            \
        }                                                                                                                           \
        list->head = NULL;                                                                                                          \
        list->size = 0;                                                                                                             \
        return list;                                                                                                                \
    }                                                                                                                               \
    void delet_##LinkedListType_Me(LinkedListType *list , \
                            LinkedListType##Node *Befor ,\
                            LinkedListType##Node *Me) \
    {\
        Befor->next = Me->next ;       \
        free(Me);\
        list->size--; \
    }\
                                                                                                                                    \
    /* Add an element to the end of the linked list */                                                                              \
    int push_back_##LinkedListType(LinkedListType *list, NodeType element)                                                          \
    {                                                                                                                               \
        LinkedListType##Node *newNode = (LinkedListType##Node *)malloc(sizeof(LinkedListType##Node));                               \
        if (newNode == NULL)                                                                                                        \
        {                                                                                                                           \
            return 0;                                                                                                               \
        }                                                                                                                           \
        newNode->data = element;                                                                                                    \
        newNode->next = NULL;                                                                                                       \
        if (list->head == NULL)                                                                                                     \
        {                                                                                                                           \
            list->head = newNode;                                                                                                   \
        }                                                                                                                           \
        else                                                                                                                        \
        {                                                                                                                           \
            LinkedListType##Node *current = list->head;                                                                             \
            while (current->next != NULL)                                                                                           \
            {                                                                                                                       \
                current = current->next;                                                                                            \
            }                                                                                                                       \
            current->next = newNode;                                                                                                \
        }                                                                                                                           \
        list->size++;                                                                                                               \
        return 1;                                                                                                                   \
    }                                                                                                                               \
                                                                                                                                    \
    /* Add an element to the front of the linked list */                                                                            \
    int push_front_##LinkedListType(LinkedListType *list, NodeType element)                                                         \
    {                                                                                                                               \
        LinkedListType##Node *newNode = (LinkedListType##Node *)malloc(sizeof(LinkedListType##Node));                               \
        if (newNode == NULL)                                                                                                        \
        {                                                                                                                           \
            return 0;                                                                                                               \
        }                                                                                                                           \
        newNode->data = element;                                                                                                    \
        newNode->next = list->head;                                                                                                 \
        list->head = newNode;                                                                                                       \
        list->size++;                                                                                                               \
        return 1;                                                                                                                   \
    }                                                                                                                               \
                                                                                                                                    \
    /* Get the current size of the linked list */                                                                                   \
    size_t size_##LinkedListType(const LinkedListType *list)                                                                        \
    {                                                                                                                               \
        return list->size;                                                                                                          \
    }                                                                                                                               \
                                                                                                                                    \
    /* Destroy the linked list and free memory */                                                                                   \
    void destroy_##LinkedListType(LinkedListType *list)                                                                             \
    {                                                                                                                               \
        LinkedListType##Node *current = list->head;                                                                                 \
        while (current != NULL)                                                                                                     \
        {                                                                                                                           \
            LinkedListType##Node *next = current->next;                                                                             \
            free(current);                                                                                                          \
            current = next;                                                                                                         \
        }                                                                                                                           \
        free(list);                                                                                                                 \
    }                                                                                                                               \
                                                                                                                                    \
     

// Define a function for printing integers
void Printint(int node);
void Printfloat(float node);
void Printdouble(double node);
void Printchar(char node);

// Define a macro for printing a linked list
#define PrintList(LinkedListType, ElementType, List, fmt, ...)                       \
    for (LinkedListType##Node *node = (List)->head; node != NULL; node = node->next) \
    {                                                                                \
        Print##ElementType(node->data);                                              \
        printf(fmt, ##__VA_ARGS__);                                                  \
    }

/*
    * @param  LIST_TYPE: This parameter should appear first because it will be generated.
    * @param NODE_TYPE: This parameter must already be defined, and it can be of any type, not limited to primary types.
    * 
    * @warning NODE_TYPE is not a primary type. You need to define `void Print{NODE_TYPE}({NODE_TYPE})`.
    * @warning If NODE_TYPE is 'foo', define `void Printfoo(foo)`.
    * @warning If NODE_TYPE is 'Egg', define `void PrintEgg(Egg)`.
    * @warning The function should be spelled as `Print{NODE_TYPE}`, not `print{NODE_TYPE}`.
    * @note to use the My iwn serch methon ferst defind a test function it woll run the ferst
    * @note odf eash sicel you it can take any number of parametter but you have to use it like that 
    *  `Full_Position_Search_{NODE_TYPE}({LIST_TYPE} , {LIST_TYPE}Node** , {LIST_TYPE}Node** , int* , your test function but as lamda , toyr parametr)`
    * @note `Full_Position_Search_` is not full testes so if you find bug say it

*/  
#define ___INIT_LIST___(LIST_TYPE, NODE_TYPE) __CLASS__LIST__SIMULATOR__(LIST_TYPE, NODE_TYPE)




// *  if you want to you this in a larger project  
// *  or simply fou need tou include it in another headers file  
// * you need to move this function to a List.c file to be safe 
// * 



#endif // ifndef _LIST_H_ 




// BY : Mohammed Aouamri 