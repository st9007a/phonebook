#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "hash_func.h"
#include "phonebook.h"

typedef struct __PHONE_BOOK_INFO {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} info;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_INFO *pInfo;
} entry;

typedef struct __HASH_TABLE {
    entry *cell[HASH_TABLE_SIZE];
} hashTable;

hashTable *newHashTable()
{
    hashTable *table = (hashTable *)malloc(sizeof(hashTable));
    memset(table->cell, '\0', HASH_TABLE_SIZE);
    printf("init");
    return table;
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

long unsigned int getHashTableSize()
{
    return sizeof(hashTable);
}

char *getLastName(entry *pNode)
{
    return pNode->lastName;
}

long unsigned int getEntrySize()
{
    return sizeof(entry);
}
