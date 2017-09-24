#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define HASH_TABLE_SIZE 350000

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

typedef struct {
    entry *cell[HASH_TABLE_SIZE];
} hashTable;

unsigned int BKDRHash(char *str);
unsigned int APHash(char *str);
entry *findName(char lastName[], hashTable *table);
void append(char lastName[], hashTable *table);

#endif
