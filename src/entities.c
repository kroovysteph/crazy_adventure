#include "adventure.h"


Player init_player(char s[])
{
    Player p;
    
    epic_string_cpy(s, p.name);
    
    p.inventory = l_create(sizeof(Item));
    
    //regular start
    p.position.x = 1;
    p.position.y = 1;
    
    //bear event
    //p.position.x = 5;
    //p.position.y = 15;
    
    //friend's house
    //p.position.x = 2;
    //p.position.y = 32;
    
    p.capacity = 50;
    p.weight_carrying = 0;
    p.health = 10.0;
    p.alignment = 0;
    p.damage = 1;
    
    return p;
}

Enemy init_bear(void) {
    
    Enemy bear;
    
    epic_string_cpy("bear", bear.name);
    
    bear.position.y = 13;
    bear.position.x = 5;
    
    return bear;
}


void place_bear_behind_player(void) {
    
    int y;
    Item *item;
    Item *bear = malloc(sizeof(Item));
    
    epic_string_cpy("bear", bear->name);
    
    //remove old bears
    for (y=15; y<=25; y++) {
        for(int i=0; i < l_length(field[y][5].items); i++) {
            
            item = l_get(field[y][5].items, i);
            
            if( strcmp(item->name, "bear") == 0 ) {
                l_remove(field[y][5].items, i);
            }
        }
    }
    
    //place new bear
    if(turn.bear_event) {
        l_append(field[player.position.y-1][5].items, bear);
    }
}