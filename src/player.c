#include "adventure.h"


Player init_player(char s[])
{
    Player p;
    
    
    epic_string_cpy(s, p.name);
    
    
    p.inventory = l_create(sizeof(void*));
    
    
    p.position.x = 0;
    p.position.y = 0;
    
    
    p.capacity = 20;
    p.weight_carrying = 0;
    p.health = 10.0;
    p.alignment = 0;
    
    
    return p;
}