#define TABLE_SIZE 10
#define MAX_NAME 256

typedef struct {
    char name[MAX_NAME];
    int age;
} person;

person *createperson(char *, int);

void init_hash_table(void);
void print_table(void);
unsigned int hash(char *);
person * hash_lookup(char *);
bool hash_insert(person *);



