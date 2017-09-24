#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

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
    while (strcmp(table->cell[i]->lastName, lastName) != 0) {
        i = (i + 1) % HASH_TABLE_SIZE;
        if (!table->cell[i]) return NULL;
    }
    return table->cell[i];

}

void append(char lastName[], hashTable *table)
{
    unsigned int i = BKDRHash(lastName) % HASH_TABLE_SIZE;
    while (table->cell[i]) {
        i = (i + 1) % HASH_TABLE_SIZE;
    }

    entry *e = (entry *) malloc(sizeof(entry));
    e->pInfo = (info *) malloc(sizeof(entry));
    strcpy(e->lastName, lastName);
    table->cell[i] = e;
}
