#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
// #define HASH_TABLE_SIZE 499857
// #define HASH_TABLE_SIZE 465533
#define HASH_TABLE_SIZE 437375
// #define HASH_TABLE_SIZE 388777
// #define HASH_TABLE_SIZE 350000
typedef struct __PHONE_BOOK_INFO info;
typedef struct __PHONE_BOOK_ENTRY entry;
typedef struct __HASH_TABLE hashTable;

hashTable *newHashTable();
entry *findName(char lastName[], hashTable *table);
void append(char lastName[], hashTable *table);

long unsigned int getHashTableSize();

char *getLastName(entry *pNone);
long unsigned int getEntrySize();

#endif
