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
        epic_string_cpy("Looking out of the window you see a desolated city.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Bed"))
    {
        epic_string_cpy("bed", i->name);
        i->weight = 1000; //Cant carry a bed!
        epic_string_cpy("You can see a bed with a black duvet cover.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Watch"))
    {
        epic_string_cpy("watch", i->name);
        i->weight = 1;
        i->damage = 0;
        epic_string_cpy("This is a normal watch.", i->flavour_text);
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Desk"))
    {
        epic_string_cpy("desk", i->name);
        i->weight = 1000; //Cant carry a desk!
        epic_string_cpy("A desk with some stuff on it.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Picture_Partner"))
    {
        epic_string_cpy("picture", i->name);
        i->weight = 1;
        i->damage = 0;
        epic_string_cpy("A picture of yourself kissing another person. You don´t know that person, but it is definetly your life partner. A child is hugging you", i->flavour_text);
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Nightstand"))
    {
        epic_string_cpy("nightstand", i->name);
        i->weight = 1000; //Cant carry a Nightstand!
        epic_string_cpy("A little nightstand next to the bed.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Newspaper"))
    {
        epic_string_cpy("newspaper", i->name);
        i->weight = 1;
        i->damage = 0;
        epic_string_cpy("As you examine the newspaper, you notice the date. It says \"2016\". It contains some articles about the new years celebration.", i->flavour_text);
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Toys"))
    {
        epic_string_cpy("toys", i->name);
        i->weight = 1000;
        i->damage = 0;
        epic_string_cpy("Just many regular toys.", i->flavour_text);
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Picture_Child"))
    {
        epic_string_cpy("picture", i->name);
        i->weight = 1;
        i->damage = 0;
        epic_string_cpy("A framed picture of you, a child and another person. It seems to be your family.", i->flavour_text);
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Wardrobe"))
    {
        epic_string_cpy("wardrobe", i->name);
        i->weight = 1000; //Cant carry.
        epic_string_cpy("A big wardrobe. It just contains clothes that you don´t need.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Table"))
    {
        epic_string_cpy("table", i->name);
        i->weight = 1000; //Cant carry.
        epic_string_cpy("This is a wooden table. Rather darker wood.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Tables"))
    {
        epic_string_cpy("tables", i->name);
        i->weight = 1000; //Cant carry.
        epic_string_cpy("These are wooden tables. Rather brigther wood.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Dishes"))
    {
        epic_string_cpy("dishes", i->name);
        i->weight = 2;
        i->damage = 1;
        epic_string_cpy("Some normal dishes. You´re thinking about what would happen if you´d throw them at someone.", i->flavour_text);
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Drawer"))
    {
        epic_string_cpy("drawer", i->name);
        i->weight = 1000;
        epic_string_cpy("There are some pain pills in here.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Knife"))
    {
        epic_string_cpy("knife", i->name);
        i->weight = 2;
        i->damage = 2;
        epic_string_cpy("A pretty big and pretty sharp knife. It´s made of one piece of steel.", i->flavour_text);
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Pills"))
    {
        epic_string_cpy("pills", i->name);
        i->weight = 1;
        i->damage = 0;
        i->hp_regeneration = 2;
        epic_string_cpy("These could help if you´re in pain.", i->flavour_text);
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Couch"))
    {
        epic_string_cpy("couch", i->name);
        i->weight = 1000; //Cant carry.
        epic_string_cpy("This is a black leathern couch. It has enough space for a few people to sit on it.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "TV"))
    {
        epic_string_cpy("tv", i->name);
        i->weight = 1000; //Cant carry.
        epic_string_cpy("It´s a flatscreen.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Carpet"))
    {
        epic_string_cpy("carpet", i->name);
        i->weight = 1000; //Cant carry.
        epic_string_cpy("That´s a beatifully ormented, red carpet.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Front_Door_Key"))
    {
        //Opens the front door of the house.
        epic_string_cpy("key", i->name);
        i->weight = 1;
        i->damage = 0;
        epic_string_cpy("A bunch of keys that´ll unlock the front door.", i->flavour_text);
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Backpack"))
    {
        epic_string_cpy("backpack", i->name);
        i->weight = 2;
        i->damage = 0;
        i->additional_capacity = 20;
        epic_string_cpy("A grey backpack with a lot of space.", i->flavour_text);
        i->hp_regeneration = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Tree"))
    {
        epic_string_cpy("tree", i->name);
        i->weight = 1000;
        epic_string_cpy("It´s an apple tree. The apples aren´t ripe yet.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Bench"))
    {
        epic_string_cpy("bench", i->name);
        i->weight = 1000;
        epic_string_cpy("A wooden bench.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Benches"))
    {
        epic_string_cpy("benches", i->name);
        i->weight = 1000;
        epic_string_cpy("Wooden benches.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Glassy_Doors"))
    {
        epic_string_cpy("doors", i->name);
        i->weight = 1000;
        epic_string_cpy("One door says push, the other one says pull.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Grave"))
    {
        epic_string_cpy("grave", i->name);
        i->weight = 1000;
        epic_string_cpy("This is a grave. You can see a small gravestone on top of it. It says \"11. January 1975 - 02. January 2016. The only person that could be buried here is your life partner.\"", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Corpse"))
    {
        epic_string_cpy("corpse", i->name);
        i->weight = 1000;
        i->damage = 0;
        i->health = 0;
        epic_string_cpy("A corpse.", i->flavour_text);
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Wolf"))
    {
        epic_string_cpy("wolf", i->name);
        i->weight = 1000;
        i->damage = 1;
        i->health = 4;
        epic_string_cpy("A wolf that´s attacking you!", i->flavour_text);
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Dog"))
    {
        epic_string_cpy("dog", i->name);
        i->weight = 1000;
        i->damage = 2;
        i->health = 5;
        epic_string_cpy("A dog that´s attacking you!", i->flavour_text);
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Axe"))
    {
        epic_string_cpy("axe", i->name);
        i->weight = 3;
        i->damage = 3;
        epic_string_cpy("This is a great and sharp axe.", i->flavour_text);
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Map"))
    {
        epic_string_cpy("map", i->name);
        i->weight = 1;
        epic_string_cpy("A map of \"London\"", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Cash_Registers"))
    {
        epic_string_cpy("cashregisters", i->name);
        i->weight = 1000;
        epic_string_cpy("It´s a cash register.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Cash"))
    {
        epic_string_cpy("cash", i->name);
        i->weight = 1;
        epic_string_cpy("It´s money. British £", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Picture_Queen_Elizabeth"))
    {
        epic_string_cpy("picture", i->name);
        i->weight = 1000;
        epic_string_cpy("A framed picture of an older lady. A sign says \"Queen Elizabeth II.\"", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Donation_Box"))
    {
        epic_string_cpy("donation", i->name);
        i->weight = 1000;
        epic_string_cpy("You notice a donation box. You can´t imagine any reason to put money in there, becuase you seem to be the last person - at least - in this city, but you´re just feeling like money isn´t worth anything to you right now. The question is if you´ve got some \"cash\" in your pockets to \"put\" it in there.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Curtain"))
    {
        epic_string_cpy("curtain", i->name);
        i->weight = 1000;
        epic_string_cpy("This is a big black curtain.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Crucifix"))
    {
        epic_string_cpy("crucifix", i->name);
        i->weight = 1000;
        epic_string_cpy("A crucifix. A big one.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Locker"))
    {
        epic_string_cpy("locker", i->name);
        i->weight = 1000;
        epic_string_cpy("A locker. ", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "First_Aid_Kit"))
    {
        epic_string_cpy("kit", i->name);
        i->weight = 2;
        i->hp_regeneration = 5; //apply
        epic_string_cpy("This is a first aid kit. This could help you to care for your wounds.", i->flavour_text);
        i->damage = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Lectern"))
    {
        epic_string_cpy("lectern", i->name);
        i->weight = 1000;
        epic_string_cpy("This is a lectern with a microphone.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Bible"))
    {
        epic_string_cpy("bible", i->name);
        i->weight = 2;
        epic_string_cpy("You´re opening the bible. It says: \"The creation of the world.\".", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Chair"))
    {
        epic_string_cpy("chair", i->name);
        i->weight = 2;
        epic_string_cpy("A wooden chair.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Chairs"))
    {
        epic_string_cpy("chairs", i->name);
        i->weight = 2;
        epic_string_cpy("Some wooden chairs.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Shower"))
    {
        epic_string_cpy("shower", i->name);
        i->weight = 1000;
        epic_string_cpy("That´s a shower.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Washbin"))
    {
        epic_string_cpy("washbin", i->name);
        i->weight = 1000;
        epic_string_cpy("That´s a washbin.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Barrier"))
    {
        epic_string_cpy("barrier", i->name);
        i->weight = 1000;
        epic_string_cpy("This is a damn great barrier. It seems like an automatic system that opens by movement if the people behind the barrier want it to.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Cupboards"))
    {
        epic_string_cpy("cupboards", i->name);
        i->weight = 1000;
        epic_string_cpy("Empty cupboards.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Note"))
    {
        epic_string_cpy("note", i->name);
        i->weight = 1;
        epic_string_cpy("You regocnize the handwriting of your child. It´s just scribble, but you identify it as \"Stratford Olympic Stadium.\"", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Shelves"))
    {
        epic_string_cpy("shelves", i->name);
        i->weight = 1000;
        epic_string_cpy("You´re looking into a shelve.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Hero_Picture"))
    {
        epic_string_cpy("pictures", i->name);
        i->weight = 1;
        epic_string_cpy("Your child´s friend seems to like super heroes like every other child There´s a picture of Batman.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Car_Bed"))
    {
        epic_string_cpy("bed", i->name);
        i->weight = 1000;
        epic_string_cpy("The child like´s racing cars, that´s obvious. You can see his bed is painted like a car.", i->flavour_text);
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    else if(0 == strcmp(item, "Water_Bed"))
    {
        epic_string_cpy("bed", i->name);
        epic_string_cpy("You´re looking at a great water bed for two persons.", i->flavour_text);
        i->weight = 1000;
        i->damage = 0;
        i->hp_regeneration = 0;
        i->additional_capacity = 0;
        i->health = 0;
        
        return i;
    }
    
//--------------------add-before-this-line----------------------
    return i;
}


void print_itemlist(List list)
{
    
    Item *item;
    char current[25];
    
    printf("{ ");
    
    for(int i=0; i < l_length(list); i++)
    {
        item = l_get(list, i);
        
        epic_string_cpy(item->name, current);
        
        current[0] = toupper(current[0]);
        
        if(i < l_length(list)-1)
        {
            printf("%s, ", current);
        }
        else
        {
            printf("%s", current);
        }
    }
    printf(" }\n");
}
