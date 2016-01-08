#include "adventure.h"


/**Dynamically allocate memory for the item structs
 * and actually save the pointer to it into the pointer list of items.
 * Comparing the given String by the .txt file to the item database.
 */
Item *create_item(char item[])
{
    
    Item *i = malloc(sizeof(Item));

    if(0 == strcmp(item, "Window"))
    {
        epic_string_cpy("window", i->name);
        i->weight = 1000; //Cant carry a windows!
        epic_string_cpy("Looking out of the window you see a desolated city.",
                                                               i->flavour_text);
        
        return i;
    }
    else if(0 == strcmp(item, "Bed"))
    {
        epic_string_cpy("bed", i->name);
        i->weight = 1000; //Cant carry a bed!
        
        return i;
    }
    else if(0 == strcmp(item, "Watch"))
    {
        epic_string_cpy("watch", i->name);
        i->weight = 1;
        i->damage = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Desk"))
    {
        epic_string_cpy("desk", i->name);
        i->weight = 1000; //Cant carry a desk!
        
        return i;
    }
    else if(0 == strcmp(item, "Picture_Partner"))
    {
        epic_string_cpy("picture", i->name);
        i->weight = 1;
        i->damage = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Nightstand"))
    {
        epic_string_cpy("nightstand", i->name);
        i->weight = 1000; //Cant carry a Nightstand!
        
        return i;
    }
    else if(0 == strcmp(item, "Newspaper"))
    {
        epic_string_cpy("newspaper", i->name);
        i->weight = 1;
        i->damage = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Picture_Child"))
    {
        epic_string_cpy("picture", i->name);
        i->weight = 1;
        i->damage = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Wardrobe"))
    {
        epic_string_cpy("wardrobe", i->name);
        i->weight = 1000; //Cant carry.
        
        return i;
    }
    else if(0 == strcmp(item, "Table"))
    {
        epic_string_cpy("table", i->name);
        i->weight = 1000; //Cant carry.
        
        return i;
    }
    else if(0 == strcmp(item, "Dishes"))
    {
        epic_string_cpy("dishes", i->name);
        i->weight = 2;
        i->damage = 1;
        
        return i;
    }
    else if(0 == strcmp(item, "Knife"))
    {
        epic_string_cpy("knife", i->name);
        i->weight = 2;
        i->damage = 3;
        
        return i;
    }
    else if(0 == strcmp(item, "Pills"))
    {
        epic_string_cpy("pills", i->name);
        i->weight = 1;
        i->damage = 0;
        i->hp_regeneration = 2;
        
        return i;
    }
    else if(0 == strcmp(item, "Couch"))
    {
        epic_string_cpy("couch", i->name);
        i->weight = 1000; //Cant carry.
        
        return i;
    }
    else if(0 == strcmp(item, "TV"))
    {
        epic_string_cpy("tv", i->name);
        i->weight = 1000; //Cant carry.
        
        return i;
    }
    else if(0 == strcmp(item, "Carpet"))
    {
        epic_string_cpy("carpet", i->name);
        i->weight = 1000; //Cant carry.
        
        return i;
    }
    else if(0 == strcmp(item, "Front_Door_Key"))
    {
        //Opens the front door of the house.
        epic_string_cpy("key", i->name);
        i->weight = 1;
        i->damage = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Backpack"))
    {
        epic_string_cpy("backpack", i->name);
        i->weight = 2;
        i->damage = 0;
        i->additional_capacity = 20;
        
        return i;
    }
    else if(0 == strcmp(item, "Tree"))
    {
        epic_string_cpy("tree", i->name);
        i->weight = 1000;
        
        return i;
    }
    else if(0 == strcmp(item, "Bench"))
    {
        epic_string_cpy("bench", i->name);
        i->weight = 1000;
        
        return i;
    }
    else if(0 == strcmp(item, "Grave"))
    {
        epic_string_cpy("grave", i->name);
        i->weight = 1000;
        
        return i;
    }
    else if(0 == strcmp(item, "Wolf"))
    {
        epic_string_cpy("wolf", i->name);
        i->damage = 1;
        i->health = 4;
        
        return i;
    }
    else if(0 == strcmp(item, "Dog"))
    {
        epic_string_cpy("dog", i->name);
        i->damage = 2;
        i->health = 4;
        
        return i;
    }
    else if(0 == strcmp(item, "Axe"))
    {
        epic_string_cpy("axe", i->name);
        i->weight = 3;
        i->damage = 4;
        
        return i;
    }
    else if(0 == strcmp(item, "Map"))
    {
        epic_string_cpy("map", i->name);
        i->weight = 1;
        
        return i;
    }
    else if(0 == strcmp(item, "Cash_Register"))
    {
        epic_string_cpy("cash", i->name);
        i->weight = 2;
        
        return i;
    }
    else if(0 == strcmp(item, "Picture_Queen_Elizabeth"))
    {
        epic_string_cpy("picture", i->name);
        i->weight = 1000;
        
        return i;
    }
    else if(0 == strcmp(item, "Donation_Box"))
    {
        epic_string_cpy("donation", i->name);
        i->weight = 1000;
        
        return i;
    }
    else if(0 == strcmp(item, "Crucifix"))
    {
        epic_string_cpy("crucifix", i->name);
        i->weight = 1000;
        
        return i;
    }
    else if(0 == strcmp(item, "Locker"))
    {
        epic_string_cpy("locker", i->name);
        i->weight = 1000;
        
        return i;
    }
    else if(0 == strcmp(item, "First_Aid_Kit"))
    {
        epic_string_cpy("kit", i->name);
        i->weight = 2;
        i->hp_regeneration = 5; //apply
        
        return i;
    }
    else if(0 == strcmp(item, "Lectern"))
    {
        epic_string_cpy("lectern", i->name);
        i->weight = 1000;
        
        return i;
    }
    else if(0 == strcmp(item, "Bible"))
    {
        epic_string_cpy("bible", i->name);
        i->weight = 2;
        
        return i;
    }
    else if(0 == strcmp(item, "Chair"))
    {
        epic_string_cpy("chair", i->name);
        i->weight = 2;
        
        return i;
    }
    
//--------------------add-before-this-line----------------------
    return i;
}


void print_itemlist(List list) {
    
    Item *item;
    char current[25];
    
    printf("{ ");
    
    for(int i=0; i < l_length(list); i++) {
        
        item = l_get(list, i);
        
        epic_string_cpy(item->name, current);
        
        current[0] = toupper(current[0]);
        
        if(i < l_length(list)-1) {
            printf("%s, ", current);
        } else {
            printf("%s", current);
        }
        
    }
    printf(" }\n");
}