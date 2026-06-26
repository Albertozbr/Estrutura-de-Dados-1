#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int matr;
    char name[50];
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
        {
            aux = aux->next;
        }
        tipolista itemDiscart = aux->next;
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
        printf("\nLista Vazia\n");
        return;
    }
    else
    {
        tipolista aux = list;
        printf("\n");
        while (aux != NULL)
        {
            printf("[%d, %s] -> ", aux->data.matr, aux->data.name);
            aux = aux->next;
        }
        printf("NULL\n\n");
    }
}

tipolista order(tipolista list)
{
    if (list == NULL || list->next == NULL)
    {
        return list;
    }
    int temp;
    tipolista aux;

    do
    {
        temp = 0;
        aux = list;

        while (aux->next != NULL)
        {
            if (strcmp(aux->data.name, aux->next->data.name) > 0)
            {
                student temp2 = aux->data;
                aux->data = aux->next->data;
                aux->next->data = temp2;
                temp = 1;
            }
            aux = aux->next;
        }
    } while (temp == 1);

    return list;
}

int main()
{
    tipolista list = NULL;
    int op = -1;
    student s;

    while (op != 0)
    {
        display(list);
        printf("1 - Insert right\n");
        printf("2 - Insert left\n");
        printf("3 - Remove right\n");
        printf("4 - Remove left\n");
        printf("5 - Order by name\n");
        printf("0 - Exit\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Enter your name: ");
            scanf("%s", s.name);
            printf("Enter your registration: ");
            scanf("%d", &s.matr);
            list = insertRight(s, list);
            break;

        case 2:
            printf("Enter your name: ");
            scanf("%s", s.name);
            printf("Enter your registration: ");
            scanf("%d", &s.matr);
            list = insertLeft(s, list);
            break;

        case 3:
            list = removeRight(list);
            break;

        case 4:
            list = removeLeft(list);
            break;

        case 5:
            list = order(list);
            break;

        case 0:
            break;

        default:
            printf("Invalid option!\n");
            break;
        }
    }

    return 0;
}