#pragma once

typedef struct List List;

//Ñîçäà¸ò íîâûé ñòåê 
List* createNewList(void);

//Óäàëÿåò ëèñò, ïðèíèìàåò óêàçàòåëü íà óêàçàòåëü
int deleteList(List** list);

//Äîáàâëÿåò ýëåìåíò
int addElement(List* list, char* inputItem);

//Óäàëÿåò ýëåìåíò
int deleteElement(List* list);

//Çàïèñûâàåò êîëè÷åñòâî ýëåìåíòîâ
int getQuantity(int* quantity, List* list);

//Âîçâðàùàåò ïîñëåäíèé ïðåäìåò, çàïèñàííûé â ñòåê
char* getLastItem(List* list);