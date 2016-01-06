#ifndef ITEMS_H
#define ITEMS_H


typedef struct Item
{
    char name[25];
    int damage;
    int weight;
    //TODO: Message if you´re looking at an item!
    int hp_regeneration;
    int holds_capacity;
} Item;


#endif