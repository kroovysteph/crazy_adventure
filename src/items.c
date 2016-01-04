#include "adventure.h"
//#include "base.h"

/**Dynamically allocate memory for the item structs
 * and actually save the pointer to it into the pointer list of items.
 * Comparing the given String by the .txt file to the item database.
 */
void * create_item(char item[])
{
    if(0 == strcmp(item, "Bucket"))
    {
        Bucket * p = malloc(sizeof(Bucket));
        Bucket bucket;
        p = &bucket;
        epic_string_cpy("Bucket", p->name);
        p->weight = 1;
        return p;
    }
    else if(0 == strcmp(item, "Sword"))
    {
        Sword * p = malloc(sizeof(Sword));
        Sword sword;
        p = &sword;
        epic_string_cpy("Sword", p->name);
        p->damage = 6;
        p->weight = 2;
        return p;
    }
    return NULL;
}