#include "adventure.h"


/**Dynamically allocate memory for the item structs
 * and actually save the pointer to it into the pointer list of items.
 * Comparing the given String by the .txt file to the item database.
 */
Item *create_item(char item[])
{
    
    Item *i = malloc(sizeof(Item));
    
    if(0 == strcmp(item, "Bucket"))
    {
        epic_string_cpy("bucket", i->name);
        i->damage = 0;
        i->weight = 1;
        i->value = 5;
        i->quantity = 1;
        
        return i;
    }
    else if(0 == strcmp(item, "Sword"))
    {
        epic_string_cpy("sword", i->name);
        i->damage = 6;
        i->weight = 2;
        i->value = 30;
        i->quantity = 1;
        
        return i;
    }
    return i;
}