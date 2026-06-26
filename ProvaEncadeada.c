#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int matr;
    int name[50];
} student;

typedef struct NOH
{
    student data;
    struct NOH *next;
} *tipolista;

tipolista createItem(student s)
{
    tipolista newNoh = malloc(sizeof(struct NOH));

    if (newNoh == NULL)
    {
        return NULL;
    }
    else
    {
        newNoh->data = s;
        newNoh->next = NULL;
        return newNoh;
    }
}

tipolista insertLeft(student s, tipolista list)
{
    tipolista newNoh = createItem(s);

    if (list == NULL)
    {
        return newNoh;
    }
    else
    {
        newNoh->next = list;
        return newNoh;
    }
}

tipolista insertRight(student s, tipolista list)
{
    tipolista newNoh = createItem(s);
    if (list == NULL)
    {
        return newNoh;
    }
    else
    {
        tipolista aux = list;

        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = newNoh;
        newNoh->next = NULL;
    }
    return list;
}

tipolista removeLeft(tipolista list)
{

    if (list == NULL)
    {
        return list;
    }
    else
    {
        tipolista aux = list;
        list = list->next;

        free(aux);
        aux = NULL;
    }
    return list;
}

tipolista removeRight(tipolista list)
{
    if (list == NULL)
    {
        return list;
    }
    else if (list->next == NULL)
    {
        free(list);
        list = NULL;
    }
    else
    {
        tipolista aux = list;
        while (aux->next->next != NULL)
        { // econtrar o penúltimo elemento
            aux = aux->next;
        }
        tipolista itemDiscart = aux->next; // o carinha está no ultimo vagão, então o ->proximo é o ultimo
        free(itemDiscart);
        itemDiscart = NULL;
        aux->next = NULL;
    }
    return list;
}

void display(tipolista list)
{
    if (list == NULL)
    {
        return list;
    }
    else
    {
        tipolista aux = list;
        while (aux->next != NULL)
        {
            printf("[%d], [%s]", aux->data.matr, aux->data.name);
            aux = aux->next;
        }
    }
}

void main()
{
    tipolista list = NULL;
    int op = -1;

    while (op != 0)
    {

        display(list);
        printf("1 - Insert right\n");
        printf("2 - Insert left\n");
        printf("3 - Remove right\n");
        printf("4 - Remove left\n");
    }
}