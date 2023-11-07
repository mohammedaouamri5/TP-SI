

#include"./../../Include/DataStructure/List.h"
#include".\..\Logic\Retired.h"

#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include <string.h>
#include ".\..\Logic\Retired.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int insertRetired(PGconn *conn, Retired retired);
PGconn *connectToDatabase() ; 
int insertHistory(PGconn *conn, Retired retired);
int updateRetired(PGconn *conn, const char *changes, int ID);
void atoRetired(PGresult *selectResult, Retired *retired);



























// #include "List.h"
// #include "..\Logic\Retired.h"

// Node is a stack
// __CLASS__LIST__SIMULATOR__(StackRetired, Retired)

// List is a list of stacks
// __CLASS__LIST__SIMULATOR__(Retireds, StackRetired)

// __CLASS__LIST__SIMULATOR__(Test, int)

//
// ```c
// RetiredUpDate(StackRetired *list, Retired element) <==> int push_front_StackRetired(StackRetired *list, Retired element)
// ```
// #define RetiredUpDate(StackRetired, Element) push_front_StackRetired(List, Element)

// void AddRetired(Test *list,int element)
// {

 
//     TestNode *newNode = (TestNode *)malloc(sizeof(TestNode));
//     if (newNode == NULL)
//     {

//         puts("[Erorr] : newNode == NULL  ");
//         exit(1) ; 
//     }

//     newNode->data  = element;
//     newNode->next = NULL;

//     if (list->head == NULL)
//     {
//         puts("[Erorr] : list->head == NULL ");
//         list->head = newNode;
//         return ;
//     }
    
//     TestNode *I = list->head ;

//     for ( ; I->next  && ( I->next->data < newNode->data ) ; I = I->next ) 
//     { }

//     newNode->next = I->next ; 
//     I->next = newNode;

//     return;
// }
// void AddRetired(Retireds *list, StackRetired element)
// {
//     RetiredsNode *newNode = (RetiredsNode *)malloc(sizeof(RetiredsNode));
//     if (newNode == NULL)
//     {
//         exit(1) ; 
//     }
//     newNode->data = element;
//     newNode->next = NULL;
//     if (list->head == NULL)
//     {
//         list->head = newNode;
//         return ;
//     }
//     RetiredsNode *I = list->head ;
//     for (; I->next && I->data.head->data.code < newNode->data.head->data.code ; I = I->next ) 
//     { }; 
//     newNode->next = I->next ; 
//     I->next = newNode;
//     return;
// }
