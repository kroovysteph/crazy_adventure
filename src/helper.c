#include "adventure.h"


//String copy function.
void epic_string_cpy(char from[], char to[])
{
    int i = 0;
    while(from[i] != '\0')
    {
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';
}



void finish(void)
{
    //List items
    for(int y = 0; y < FIELD_HEIGHT; y++)
    {
        for(int x = 0; x < FIELD_HEIGHT; x++)
        {
            l_free(field[y][x].items);
        }
    }
    
    
    //Room **field
    for(int i = 0; i < FIELD_HEIGHT; i++)
    {
        free(field[i]);
    }
    free(field);
    
    
    //List inventory
    l_free(player.inventory);
    
    exit(0);
}