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


void go_up(char input[]) {
    
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



void go_right(char input[]) {
    
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


void get_item(void) {
    
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
        
        if(strcmp(item->name, input2) == 0) {
            
            found = true;
            
            if(max_load > cur_load + item->weight) {
                
                player.weight_carrying += item->weight;
                l_append( player.inventory, item);
                l_remove(field[y][x].items, i);
                printf("\nYou have gained a %s.\n", item->name);
                break;
            } else {
                printf("\nA \"%s\" is too heavy for carrying.\n", item->name);
            }
            
        }
    }
    
    if(!(found))
    {
        printf("\nThere is nothing like \"%s\"...\n", input2);
    }
}


void put_item(void) {
    
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
        //geht durch die Liste
        item = l_get(player.inventory, i);
        
        if(strcmp(item->name, input2) == 0) {
            
            found = true;
            player.weight_carrying += item->weight;
            
            l_append(field[y][x].items, item);
            l_remove(player.inventory, i);
            
            printf("\nYou dropped a %s.\n", item->name);
            break;
        }
    }
    
    if(!(found))
    {
        printf("\nYou have nothing like \"%s\"...\n", input2);
    }
}


void list_items(void) {
    
    int x = player.position.x;
    int y = player.position.y;
    
    printf("\nRoom = ");
    print_itemlist(field[y][x].items);
    
    printf("You  = ");
    print_itemlist(player.inventory);
    
}


void examine(void) {
    
    char input2[25] = "";
    
    int x = player.position.x;
    int y = player.position.y;
    
    scanf("%s", input2);
    Item *item;
    
    int c = 0;
    while(input2[c] != '\0') {
        input2[c] = tolower(input2[c]);
        c++;
    }
    
    for(int i = 0; i < l_length(field[y][x].items); i++) {
        
        //geht durch die Liste
        item = l_get(field[y][x].items, i);
        
        if(strcmp(item->name, input2) == 0) {
            
            printf("\n%s\n", item->flavour_text);
            return;
        }
    }
    
    for(int i = 0; i < l_length(player.inventory); i++) {
        
        //geht durch die Liste
        item = l_get(player.inventory, i);
        
        if(strcmp(item->name, input2) == 0) {
            
            printf("\n%s\n", item->flavour_text);
            return;
        }
    }
    
    printf("\nThere is nothing like \"%s\"...\n", input2);
}

void look(void) {
    
    int x = player.position.x;
    int y = player.position.y;
    
    printf("\n");
    
    print_field();
    
    if(!DEBUG_MODE) {
        print_itemlist(field[y][x].items);
    }
}