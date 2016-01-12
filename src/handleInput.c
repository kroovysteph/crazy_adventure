#include "adventure.h"

void go_left(char input[])
{
    int x = player.position.x;
    int y = player.position.y;
    
    if(x > 0 && !(field[y][x-1].wall))
    {
        player.position.x--;
        random_string(input);
    }
    else
    {
        printf("\nYou cannot go that way...\n");
    }
}


void go_down(char input[])
{
    int x = player.position.x;
    int y = player.position.y;
    
    if(y < FIELD_HEIGHT-1 && !(field[y+1][x].wall))
    {
        player.position.y = (player.position.y + 1);
        random_string(input);
    }
    else
    {
        printf("\nYou cannot go that way...\n");
    }
}


void go_up(char input[])
{
    
    int x = player.position.x;
    int y = player.position.y;
    
    if(y > 0 && !(field[y-1][x].wall))
    {
        player.position.y--;
        random_string(input);
    }
    else
    {
        printf("\nYou cannot go that way...\n");
    }
}



void go_right(char input[])
{
    
    int x = player.position.x;
    int y = player.position.y;
    
    if(x < FIELD_WIDTH-1 && !(field[y][x+1].wall))
    {
        player.position.x++;
        random_string(input);
    }
    else
    {
        printf("\nYou cannot go that way...\n");
    }
}


void get_item(void)
{
    
    bool found = false;
    char input2[25] = "";
    
    int x = player.position.x;
    int y = player.position.y;
    
    int max_load = player.capacity;
    int cur_load = player.weight_carrying;
    
    scanf("%s", input2);
    Item *item;
    found = false;
    
    int c = 0;
    while(input2[c] != '\0')
    {
        input2[c] = tolower(input2[c]);
        c++;
    }
    
    for(int i = 0; i < l_length(field[y][x].items); i++)
    {
        //geht durch die Liste
        item = l_get(field[y][x].items, i);
        
        
        if(strcmp(item->name, input2) == 0)
        {
            
            found = true;
            
            if(max_load > cur_load + item->weight)
            {
                
                player.weight_carrying += item->weight;
                player.damage += item->damage;
                l_append( player.inventory, item);
                
                if(strcmp(item->name, "backpack") == 0)
                {
                    player.capacity += item->additional_capacity;
                }
                
                printf("\nYou have gained a %s.\n", item->name);
                
                l_remove(field[y][x].items, i);
                break;
                
            }
            else
            {
                printf("\nA \"%s\" is too heavy for carrying.\n", item->name);
            }
        }
    }
    
    if(!(found))
    {
        printf("\nThere is nothing like \"%s\"...\n", input2);
    }
}


void put_item(void)
{
    
    bool found = false;
    char input2[25] = "";
    
    int x = player.position.x;
    int y = player.position.y;
    
    scanf("%s", input2);
    Item *item;
    found = false;
    
    int c = 0;
    while(input2[c] != '\0')
    {
        input2[c] = tolower(input2[c]);
        c++;
    }
    
    for(int i = 0; i < l_length(player.inventory); i++)
    {
        //iterate through the list
        item = l_get(player.inventory, i);
        
        if(strcmp(item->name, input2) == 0)
        {
            found = true;
            player.weight_carrying -= item->weight;
            player.damage -= item->damage;
            
            l_append(field[y][x].items, item);
            
            if(strcmp(item->name, "backpack") == 0)
            {
                player.capacity -= item->additional_capacity;
            }
            
            printf("\nYou dropped a %s.\n", item->name);
            l_remove(player.inventory, i);
            break;
        }
    }
    
    if(!(found))
    {
        printf("\nYou have nothing like \"%s\"...\n", input2);
    }
}

void apply(void)
{
    
    bool found = false;
    char input2[25] = "";
    
    scanf("%s", input2);
    Item *item;
    found = false;
    
    int c = 0;
    while(input2[c] != '\0')
    {
        input2[c] = tolower(input2[c]);
        c++;
    }
    
    for(int i = 0; i < l_length(player.inventory); i++)
    {
        //geht durch die Liste
        item = l_get(player.inventory, i);
        
        if(strcmp(item->name, input2) == 0)
        {
            found = true;
//------------------------------------------------------------------kit---------
            if(strcmp("kit", input2) == 0)
            {
                player.weight_carrying -= item->weight;
                player.health += item->hp_regeneration;
                printf("\nYou applied a medi-kit to yourself.\n");
                l_remove(player.inventory, i);
            }
//------------------------------------------------------------------pills-------
            else if(strcmp("pills", input2) == 0)
            {
                player.weight_carrying -= item->weight;
                player.health += item->hp_regeneration;
                printf("\nYou take some pills. You feel a bit better.\n");
                l_remove(player.inventory, i);
            }
//-------------------------------------------------------------------map--------
            else if(strcmp("map", input2) == 0)
            {
                printf("\nYou getter a better understanding of the environment.\n");
                difficulty = 1000;
            }
//------------------------------------------------------------------------------
            else
            {
                printf("\nThat is a silly thing to apply.\n");
            }
            break;
        }
    }
    
    if(!(found))
    {
        printf("\nYou have nothing like \"%s\"...\n", input2);
    }
}

void list_items(void)
{
    
    int x = player.position.x;
    int y = player.position.y;
    
    printf("\nRoom = ");
    print_itemlist(field[y][x].items);
    
    printf("You  = ");
    print_itemlist(player.inventory);
    
}


void examine(void)
{
    char input2[25] = "";
    
    int x = player.position.x;
    int y = player.position.y;
    
    scanf("%s", input2);
    Item *item;
    
    int c = 0;
    while(input2[c] != '\0')
    {
        input2[c] = tolower(input2[c]);
        c++;
    }
    
    for(int i = 0; i < l_length(field[y][x].items); i++)
    {
        
        //iterate through the list
        item = l_get(field[y][x].items, i);
        
        if(strcmp(item->name, input2) == 0)
        {
            printf("\n%s\n", item->flavour_text);
//---------------------------------------examine-event-handling-----------------
            if(strcmp(item->name, "picture") == 0)
            {
                //examined item IS in the current room
                lv1.picture = true;
            }
            if(strcmp(item->name, "grave") == 0)
            {
                //examined item IS in the current room
                lv1.grave = true;
            }
            if(strcmp(item->name, "note") == 0)
            {
                //examined item IS in the current room
                player.position.y = 32;
                player.position.x = 7;
                printf("%s\n", field[32][7].ambience);
            }
//------------------------------------------------------------------------------
            return;
        }
    }
    
    for(int i = 0; i < l_length(player.inventory); i++)
    {
        
        //iterate through the list
        item = l_get(player.inventory, i);
        
        if(strcmp(item->name, input2) == 0)
        {
            
            printf("\n%s\n", item->flavour_text);
//---------------------------------------examine-event-handling-----------------
            
            if(strcmp(item->name, "picture") == 0)
            {
                //examined item IS in the players inventory
                lv1.picture = true;
            }
            if(strcmp(item->name, "grave") == 0)
            {
                //examined item IS in the players inventory
                lv1.grave = true;
            }
            if(strcmp(item->name, "note") == 0)
            {
                //examined item IS in the current room
                player.position.y = 32;
                player.position.x = 7;
            }
//------------------------------------------------------------------------------
            return;
        }
    }
    
    printf("\nThere is nothing like \"%s\"...\n", input2);
}

void look(void)
{
    
    int x = player.position.x;
    int y = player.position.y;
    
    printf("\n");
    
    print_field();
    
    if(!DEBUG_MODE)
    {
        print_itemlist(field[y][x].items);
    }
}

int quit(void)
{
    
    char input2[25];
    
    printf("\nDo you really want to quit?\n> (yes/no): ");
    scanf("%s", input2);
    
    int c = 0;
    while(input2[c] != '\0')
    {
        input2[c] = tolower(input2[c]);
        c++;
    }
    
    if(strcmp(input2, "yes") == 0 || 0 == strcmp(input2, "y"))
    {
        printf("You have successfully closed the game.\n");
        return 1;
    }
    else if(strcmp(input2, "no") == 0 || 0 == strcmp(input2, "n"))
    {
        printf("\n...back to the game!\n");
        print_field();
        return 0;
    }
    else
    {
        printf("\nWhat do you mean by \"%s\"?", input2);
        return quit();
    }
}

void attack (void)
{
    char input3[25] = "";
    
    scanf("%s", input3);
    Item *item;
    
    int x = player.position.x;
    int y = player.position.y;
    
    int c = 0;
    while(input3[c] != '\0')
    {
        input3[c] = tolower(input3[c]);
        c++;
    }
    
    //No items in the room.
    if(l_length(field[y][x].items) == 0)
    {
        printf("\nHere´s nothing to be attacked!");
    }
    //There are items in the room.
    else
    {
        //There are definetly items in the room. Need to go through the itemlist.
        for(int i = 0; i < l_length(field[y][x].items); i++)
        {
            
            //Iterate through the list
            item = l_get(field[y][x].items, i);
            
            //The item the player wanted to attack is there.
            if(strcmp(input3, item->name) == 0)
            {
                //The player is attacking a wolf or a dog.
                if(strcmp(input3, "wolf") == 0 || strcmp(input3, "dog") == 0)
                {
                    printf("\nYou´re attacking the %s. You´re dealing %d damage.", input3, player.damage);
                    item->health = item->health - player.damage;
                    for(int i = 0; i < l_length(field[y][x].items); i++)
                    {
                        Item * item = l_get(field[y][x].items, i);
                        if(item->health <= 0)
                        {
                            printf("\nThe %s is dead.", item->name);
                            l_remove(field[y][x].items, i);
                            l_append(field[y][x].items, create_item("Corpse"));
                            wolf_event1 = false;
                            wolf_event2 = false;
                            dog_event = false;
                            break;
                        }
                        else if(item->health > 0)
                        {
                            printf("\nThe %s attacks you and deals %d damage.", item->name, item->damage);
                            player.health = player.health - item->damage;
                            break;
                        }
                    }
                }
                //The player is not trying to attack a wolf or a dog.
                else if(strcmp(input3, "wolf") != 0 || strcmp(input3, "dog") != 0)
                {
                        printf("\nYou´re trying to attack %s...", input3);
                        break;
                }
            }
            //The item the player wanted to attack is not there.
            else if(strcmp(input3, item->name) != 0)
            {
                    printf("\nHere´s nothing like %s!", input3);
                    break;
            }
        }
    }
}


void print_manual(void)
{
    printf("\n");
    printf("left,  l       :  go west\n");
    printf("right, r       :  go east\n");
    printf("up,    u       :  go north\n");
    printf("down,  d       :  go south\n");
    printf("look           :  look around (items included)\n");
    printf("get <item>     :  pick up an item (keyword is enough)\n");
    printf("put <item>     :  drop an item\n");
    printf("examine <item> :  get more details on an item/object\n");
    printf("quit           :  quits the game\n");
    printf("ls             :  lists items of inventory and room\n");
    printf("stats          :  lists player´s stats\n");
    printf("apply, a <item>:  use an item\n");
    printf("hide           :  hide before enemies, like bears and so on\n");
    printf("attack <enemy> :  attack an enemy\n");
    printf("man, help      :  shows this help menu\n");
}


void print_stats(void)
{
    int health    = player.health;
    int max_load  = player.capacity;
    int cur_load  = player.weight_carrying;
    int damage    = player.damage;
    int x         = player.position.x;
    int y         = player.position.y;
    
    printf("\n%s = { Health: %d | Load: %d/%d | Turn: %d | Damage: %d | Coords: (%d,%d) }\n",
            player.name, health, cur_load, max_load, turn.current_turn, damage, y, x);
}
