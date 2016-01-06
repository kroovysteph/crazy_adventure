#include "adventure.h"


Player init_player(char s[])
{
    Player p;
    
    
    epic_string_cpy(s, p.name);
    
    
    p.inventory = l_create(sizeof(Item));
    
    
    p.position.x = 1;
    p.position.y = 1;
    
    
    p.capacity = 50;
    p.weight_carrying = 0;
    p.health = 10.0;
    p.alignment = 0;
    p.damage = 1;
    
    
    return p;
}