#include "adventure.h"


/**Create a Room and fill it with
 */
Room make_room(bool wall, char ambience[], char item1[], char item2[], char item3[], char item4[], char item5[], char item6[], char item7[], char item8[], char item9[], char item10[])
{
    Room room;
    
    room.wall = wall;
    epic_string_cpy(ambience, room.ambience);
    room.items = l_create(sizeof(void*));
    
    if(item1[0] != '<')
    {
        l_append(room.items, create_item(item1));
    }
    if(item2[0] != '<')
    {
        l_append(room.items, create_item(item2));
    }
    if(item3[0] != '<')
    {
        l_append(room.items, create_item(item3));
    }
    if(item4[0] != '<')
    {
        l_append(room.items, create_item(item4));
    }
    if(item5[0] != '<')
    {
        l_append(room.items, create_item(item5));
    }
    if(item6[0] != '<')
    {
        l_append(room.items, create_item(item6));
    }
    if(item7[0] != '<')
    {
        l_append(room.items, create_item(item7));
    }
    if(item8[0] != '<')
    {
        l_append(room.items, create_item(item8));
    }
    if(item9[0] != '<')
    {
        l_append(room.items, create_item(item9));
    }
    if(item10[0] != '<')
    {
        l_append(room.items, create_item(item10));
    }
    
    return room;
}