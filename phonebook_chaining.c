#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_chaining.h"

unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131;
    unsigned int hash = 0;

    while (*str) {
        hash = hash * seed + (*str++);
    }

    return (hash & 0x7FFFFFFF);
}

entry *findName(char lastName[], hashTable *table)
{
    unsigned int i = BKDRHash(lastName) % HASH_TABLE_SIZE;
    entry *head = table->cell[i];
    while (strcmp(head->lastName, lastName) != 0) {
        head = head->pNext;
        if (head == NULL) break;
    }
    return head;

}

void append(char lastName[], hashTable *table)
{
    unsigned int i = BKDRHash(lastName) % HASH_TABLE_SIZE;
    entry *e = (entry *) malloc(sizeof(entry));
    e->pInfo = (info *) malloc(sizeof(entry));
    e->pNext = NULL;
    strcpy(e->lastName, lastName);

    if (table->cell[i] == NULL) {
        table->cell[i] = e;
        return;
    }

    entry *head = table->cell[i];
    while (head->pNext != NULL) {
        head = head->pNext;
    }

    head->pNext = e;
}
