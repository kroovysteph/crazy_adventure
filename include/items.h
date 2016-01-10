#ifndef ITEMS_H
#define ITEMS_H


typedef struct Item
{
    char name[50];
    char flavour_text[1000];
    int damage;
    int weight;
    int hp_regeneration;
    int additional_capacity;
    int health;
} Item;


#endif