// lookup time is O(1)
// contains an array with pointers to people
// and a hash function that when looking for a person returns the same index of the array
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ht.h"

person * hash_table[TABLE_SIZE];

int main(void)
{
    init_hash_table();

    person *p1 = createperson("shakes", 50);
    person *p2 = createperson("thakesp", 60);
    person *p3 = createperson("uhakespe", 70);
    person *p4 = createperson("vhakespea", 80);
    person *p5 = createperson("whakespear", 90);

    hash_insert(p1);
    hash_insert(p2);
    hash_insert(p3);
    hash_insert(p4);
    hash_insert(p5);

    print_table();

    printf("the age of shakes is %d\n", hash_lookup("shakes")->age);
    return 0;
}

person *createperson(char *name, int age)
{
    // because you are delegating this to a function
    // you'll need to place the memory for each person
    // on the heap.
    // creating new persons here and returning them
    // will not work because each function has its own stack
    person *p = malloc(sizeof(p));
    strcpy(p->name, name);
    p->age = age;
    return p;
}

void init_hash_table(void){
    for (int i = 0; i < TABLE_SIZE; i++) hash_table[i] = NULL;
}

void print_table(void)
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t---\t\n");
        } else {
            printf("\t%s\t\n", hash_table[i]->name);
        }
    }
}

unsigned int hash(char *name) {
    // check unsw for good implementation
    return strlen(name) % TABLE_SIZE;
}

bool hash_insert(person *p) {
    int i = hash(p->name);
    if (hash_table[i] == NULL) {
        hash_table[i] = p;
        return true;
    } else {
        return false;
    }
}

person * hash_lookup(char *name) {
    return hash_table[hash(name)];
}

