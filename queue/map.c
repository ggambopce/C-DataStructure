#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int key;
    int value;
} Entry;

typedef struct
{
    Entry data[MAX_SIZE];
    int size;
} Map;

void initMap(Map *map)
{
    map->size = 0;
}

void put(Map *map, int key, int value)
{
    for (int i = 0; i < map->size; i++)
    {
        if (map->data[i].key == key)
        {
            map->data[i].value = value;
            return;
        }
    }
    if (map->size < MAX_SIZE)
    {
        map->data[map->size++] = (Entry){key, value};
    }
}

int get(Map *map, int key)
{
    for (int i = 0; i < map->size; i++)
    {
        if (map->data[i].key == key)
        {
            return map->data[i].value;
        }
    }
    return -1; // key not found
}
