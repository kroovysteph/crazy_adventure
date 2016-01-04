#include "adventure.h"
//#include "base.h"

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

//TODO
void finish(void)
{
    //List items
    //Room **field
    //List inventory
    exit(0);
}