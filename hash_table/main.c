#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *cpf;
    char *name;
    char *email;
} people_t;

typedef struct node{
    char *key;
    people_t *people;
    struct node *next;
}node_t;

typedef struct dictionary{
    int size;
    node_t **array;
}dictionary_t;

dictionary_t *create(int m)
{
    dictionary_t *new = NULL;
    if(m < 1){
        return NULL;
    }

    if((new = (dictionary_t*) malloc(sizeof(dictionary_t))) == NULL){
        return NULL;
    }

    new->size = m;

    if((new->array = calloc(m,sizeof (dictionary_t))) == NULL){
        return NULL;
    }

    for(int i = 0;i < m; i++){
        new->array[i] = NULL;
    }
    return new;
}

void destruct_people(people_t *people)
{
    if(people->cpf != NULL){
        free(people->cpf);
    }
    if(people->name != NULL){
        free(people->name);
    }
    if(people->email != NULL){
        free(people->email);
    }
    free(people);
}

void destruct_node(node_t *node)
{
    if(node != NULL){
        free(node->key);
        destruct_people(node->people);
        free(node);
    }
}

void destruct_dictionary(dictionary_t *dictionary)
{
    if(dictionary != NULL){
        for(int i = 0; i < dictionary->size; i++){
            node_t *current = dictionary->array[i];
            while(current != NULL){
                node_t *next = current->next;
                destruct_node(current);
                current = next;
            }
            dictionary->array[i] = NULL;
        }
        free(dictionary->array);
        free(dictionary);
    }
}

int hash(const char *key, int m)
{
    int sum = 0;
    for(int i = 0; key[i] != '\0';i++){
        sum += (i+1) * key[i];
    }
    return sum % m;
}

bool insert(dictionary_t *dictionary,char *key, people_t *people)
{
    int index = hash(key,dictionary->size);
    node_t *node = malloc(sizeof(node_t));
    if(node == NULL){
        free(node);
        return false;
    }

    node->key = strdup(key);
    if(node->key == NULL){
        free(node);
        return false;
    }

    node->people = people;
    node->next = NULL;
    if(dictionary->array[index] == NULL){
        dictionary->array[index] = node;
    } else{
        node->next = dictionary->array[index];
        dictionary->array[index] = node;
    }

    return true;
}

people_t *search(dictionary_t *dictionary,char *key)
{
    int index = hash(key,dictionary->size);
        node_t *current = dictionary->array[index];
        while(current != NULL){
            if(strcmp(current->key,key) == 0){
                return current->people;
            }
            current = current->next;
        }

    return  NULL;
}

void print_people(dictionary_t *dictionary, char *key)
{
    people_t *people = search(dictionary,key);
    if(people != NULL){
        printf("CPF: %s\tNome: %s\tEmail: %s\n",people->cpf,people->name,people->email);
    } else{
        printf("Pessoa com o CPF %s não encontrada!\n",people->cpf);
    }
}

bool removeDictionary(dictionary_t *dictionary,char *key)
{
    int index = hash(key,dictionary->size);
    node_t *current = dictionary->array[index];
    node_t *previous = NULL;
    while(current != NULL){
        if(strcmp(key,current->key) == 0){
            if(previous == NULL){
                dictionary->array[index] = current->next;
                destruct_node(current);
                return true;
            }else{
                previous->next = current->next;
                destruct_node(current);
                return true;
            }
        }
        previous = current;
        current = current->next;
    }
    return false;
}

int main(int argc, char **argv){
    dictionary_t *dictionary = create(3);
    if(dictionary == NULL){
        printf("Não foi possível reservar memória!\n");
        exit(EXIT_FAILURE);
    }

    people_t *people = malloc(sizeof(people_t));

    people->cpf = strdup("123");
    people->email = strdup("juca@example.org");
    people->name = strdup("Juca");
    insert(dictionary,people->cpf,people);

    people_t *people2 = malloc(sizeof(people_t));
    people2->cpf = strdup("456");
    people2->email = strdup("juca2@example.org");
    people2->name = strdup("Juca2");
    insert(dictionary,people2->cpf,people2);


    people = malloc(sizeof(people_t));
    people->cpf = strdup("789");
    people->email = strdup("juca3@example.org");
    people->name = strdup("Juca3");
    insert(dictionary,people->cpf,people);

    print_people(dictionary,"123");
    print_people(dictionary,"456");
    print_people(dictionary,"789");

    removeDictionary(dictionary,"123");
//    print_people(dictionary,"123");

    destruct_dictionary(dictionary);

    return 0;
}