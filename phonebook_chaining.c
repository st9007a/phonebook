#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

typedef struct __HASH_TABLE {
    entry *cell[HASH_TABLE_SIZE];
} hashTable;

static unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131;
    unsigned int hash = 0;

    while (*str) {
        hash = hash * seed + (*str++);
    }

    return (hash & 0x7FFFFFFF);
}

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
