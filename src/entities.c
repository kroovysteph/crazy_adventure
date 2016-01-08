#include "adventure.h"


Player init_player(char s[])
{
    Player p;
    
    epic_string_cpy(s, p.name);
    
    p.inventory = l_create(sizeof(Item));
    
    //regular start
    p.position.x = 1;
    p.position.y = 1;
    
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
