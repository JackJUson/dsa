
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct collectionRep *Collection;

Collection newCollection();
Item *search(Collection, Key);
void insert(Collection, Item);
void delete(Collection, Key);

typedef struct CollectionRep {
    // data structure to hold multiple items ...
} CollectionRep;


typedef struct HashTabRep *HashTable;

HashTable newHashTable(int);
void HashInsert(HashTablem Item);
Item *HashGet(HashTable, Key);
void HashDelete(HashTable, Key);
void dropHashTable(HashTable);

typedef struct HashTabRep {
    Item **items;   // array of (Item *)
    int N;          // size of array
    int nitems;     // # Items in array
} HashTabRep;

HashTable newHashTable(int N) {
    HashTable new = malloc(sizeof(HashTabRep));
    new->items = malloc(N*sizeof(Item *));
    new->N = N;
    new->nitems = 0;
    for (int i = 0; i < N; i++) new->items[i] = NULL;
    return new;
}

void HashInsert(HashTable ht, Item it) {
    int h = hash(key(it), ht->N);
    // assume table slot empty!?
    ht->items[h] = copy(it);
    ht->nitems++;
}

Item *HashGet(HashTable ht, Key k) {
    int h = hash(k, ht->N);
    Item *itp = ht->items[h];
    if (itp != NULL && equal(key(*itp), k)) {
        return itp;
    } else {
        return NULL;
    }
}

void HashDelete(HashTable ht, Key k) {
    int h = hash(k, ht->N);
    Item *itp = ht->items[h];
    if (itp != NULL && equal(key(*itp), k)) {
        free(itp);
        ht->items[h] = NULL;
        ht->nitems--;
    }
}

void dropHashTable(HashTable ht) {
    for (int i = 0; i < ht->N; i++) {
        if (ht->items[i] != NULL) {
            free(ht->items[i]);
        }
        free(ht);
    }
}

