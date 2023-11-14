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
    people_t *value;
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
        destruct_people(node->value);
        free(node);
    }
}

void destruct_dictionary(dictionary_t *dictionary)
{
    if(dictionary != NULL){
        for(int i = 0; i < dictionary->size; i++){
            //TODO destruir lista encadeada
            destruct_node(dictionary->array[i]);
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
        return false;
    }

    node->key = strdup(key);
    if(node->key == NULL){
        free(node);
        return false;
    }

    node->value = people;
    //TODO não está tratando colisões
    // se ouver colisão é necessária usar uma lista encadeada
    node->next = NULL;

    // Libera a memória se existir um nó anterior na posição
    destruct_node(dictionary->array[index]);
    dictionary->array[index] = node;
    return true;
}

people_t *search(dictionary_t *dictionary,char *key)
{
    int index = hash(key,dictionary->size);
    if(dictionary->array[index] != NULL){
        // TODO Abaixo só pega o primeiro elemento da lista encadeada
        // é necessário percorrer a lista encadeada e não apenas o primeiro elemento
        if(strcmp(dictionary->array[index]->key,key) == 0){
            return dictionary->array[index]->value;
        }
    }
    return  NULL;
}

void print_people(dictionary_t *dictionary, char *key)
{
    people_t *people = search(dictionary,key);
    if(people != NULL){
        printf("CPF: %s\tNome: %d\tEmail: %s\n",people->cpf,people->name,people->email);
    } else{
        printf("Pessoa com o CPF %s não encontrada!\n",people->cpf);
    }
}


int main()
{


    return 0;
}