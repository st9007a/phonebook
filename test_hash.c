#include <stdio.h>
#include <stdlib.h>

#include "hash_func.h"
#include "phonebook.h"

#define DICT_FILE "./dictionary/all-names.txt"
#define OUTPUT_FILE "./src/test_hash.txt"

int main()
{

    FILE *fp, *output;
    int i = 0;
    char line[MAX_LAST_NAME_SIZE];

    fp = fopen(DICT_FILE, "r");
    if (fp == NULL) {
        printf("cannot open the file\n");
        return -1;
    }

    output = fopen(OUTPUT_FILE, "w");
    if (output == NULL) {
        printf("cannot open the file\n");
        fclose(fp);
        return -1;
    }
    printf("hash table size: %d\n", HASH_TABLE_SIZE);

    while (fgets(line, sizeof(line), fp)) {
        while (line[i] != '\0')
            i++;
        line[i - 1] = '\0';
        i = 0;

        fprintf(output, "%u %u %u %u %u %u %u %u\n",
                SDBMHash(line) % HASH_TABLE_SIZE,
                RSHash(line) % HASH_TABLE_SIZE,
                JSHash(line) % HASH_TABLE_SIZE,
                PJWHash(line) % HASH_TABLE_SIZE,
                ELFHash(line) % HASH_TABLE_SIZE,
                BKDRHash(line) % HASH_TABLE_SIZE,
                DJBHash(line) % HASH_TABLE_SIZE,
                APHash(line) % HASH_TABLE_SIZE
               );

    }

    fclose(fp);
    fclose(output);

    return 0;
}
