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
        printf("You cannot go that way...\n");
    }
    print_field();
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
        printf("You cannot go that way...\n");
    }
    print_field();
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
        printf("You cannot go that way...\n");
    }
    print_field();
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
        printf("You cannot go that way...\n");
    }
    print_field();
}


void get_item(void) {
    
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
    
    for(int i = 0; i < l_length(field[y][x].items); i++)
    {
        //geht durch die Liste
        item = l_get(field[y][x].items, i);
        
        if(strcmp(item->name, input2) == 0)
        {
            found = true;
            l_append( player.inventory, item);
            l_remove(field[y][x].items, i);
            printf("You have gained a %s.\n", item->name);
            print_field();
            break;
        }
    }
    
    if(!(found))
    {
        printf("There is nothing like \"%s\"...\n", input2);
        print_field();
    }
}