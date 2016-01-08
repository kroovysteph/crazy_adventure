#include "adventure.h"


/**Create a Room and fill it with the cointaining elements.
 */
Room make_room(bool wall, char ambience[], char item1[], char item2[], char item3[], char item4[], char item5[], char item6[], char item7[], char item8[], char item9[], char item10[])
{
    Room room;
    room.wall = wall;
    epic_string_cpy(ambience, room.ambience);
    room.items = l_create(sizeof(Item));
    
    
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

/**Prints the current state of the field.
 * WWW == Wall
 * P == Player position
 * and the first letter of the Item.
 */
void print_field(void)
{
    int c = 0;
    int x = player.position.x;
    int y = player.position.y;
    
    
    //------------------------------------------------------------
    
    while(field[y][x].ambience[c] != '\0') {
        
        if(field[y][x].ambience[c] != '_') {
            
            printf("%c", field[y][x].ambience[c]);
        } else {
            printf(" ");
        }
        c++;
    }
    printf("\n");
    
    
    if(DEBUG_MODE)  {
        
        //print list of items
        print_itemlist(field[y][x].items);
        
        //print graphical field
        for(int y = 0; y < FIELD_HEIGHT; y++)
        {
            if(y > 0) {
                printf("\n");
            }
            for(int x = 0; x < FIELD_WIDTH; x++)
            {
                printf("[");
                
                if( field[y][x].wall )
                {
                    printf("WWW");
                }
                else
                {
                    if(player.position.x == x && player.position.y == y)
                    //Player is in this room.
                    {
                        printf("P");
                    }
                    else
                    {
                        printf(" ");
                    }
                    
                    
                    if(1 == l_length(field[y][x].items) )
                    {
                        //Should be void*, beucase we dont know which struct we´ll look at.
                        //Cant dereference void*!
                        Item * i1 = l_get(field[y][x].items, 0);
                        printf( "%c ", i1->name[0] );
                    }
                    else if(2 <= l_length(field[y][x].items))
                    {
                        Item * i1 = l_get(field[y][x].items, 0);
                        Item * i2 = l_get(field[y][x].items, 1);
                        
                        printf("%c%c", i1->name[0], i2->name[0]);
                    }
                    else
                    {
                        printf("  ");
                    }
                }
                printf("] ");
            }
        }
        printf("\n\n");
    }
}


Checkpoints create_checkpoints(void) {
    
    Checkpoints cp;
    
    cp.supermarket = false;
    cp.townhall = false;
    
    cp.church = false;
    cp.school = false;
    cp.trainstation = false;
    
    return cp;
}


void map(int sight_range) {
    
    int x_sight_range = sight_range;
    int y_sight_range = sight_range;
    
    //print graphical field
    for(int y = 0; y < FIELD_HEIGHT; y++)
    {
        for(int x = 0; x < FIELD_WIDTH; x++)
        {
            if(near_player(y, x, y_sight_range, x_sight_range)) {
                
                if(x == 0 || x == player.position.x - x_sight_range) {
                    printf("\n");
                } else if (at_baby(y, x) && x == player.position.x-1) {
                    printf("\n");
                }
                
                printf("[");
                
                if( field[y][x].wall )
                {
                    printf("===");
                }
                else
                {
                    if(player.position.x == x && player.position.y == y)
                    //Player is in this room.
                    {
                        printf("P");
                    }
                    else
                    {
                        printf(" ");
                    }
                    
                    
                    if(1 == l_length(field[y][x].items) )
                    {
                        //Should be void*, beucase we dont know which struct we´ll look at.
                        //Cant dereference void*!
                        Item * i1 = l_get(field[y][x].items, 0);
                        printf( "%c ", i1->name[0] );
                    }
                    else if(2 <= l_length(field[y][x].items))
                    {
                        Item * i1 = l_get(field[y][x].items, 0);
                        Item * i2 = l_get(field[y][x].items, 1);
                        
                        printf("%c%c", i1->name[0], i2->name[0]);
                    }
                    else
                    {
                        printf("  ");
                    }
                }
                printf("] ");
            }
        }
    }
    printf("\n");
}


/**Is the Room in range of the Player?
 * 
 * returns a boolean that tells if field[@y][@x] is in range of the player
 * @y_range and @x_range determine the (kinda) radius of the range
 */
bool near_player(int y, int x, int y_range, int x_range) {
    
    if(player.position.x-x_range <= x && x <= player.position.x+x_range
    && player.position.y-y_range <= y && y <= player.position.y+y_range) {
        
        if (at_home(player.position.y, player.position.x) && at_home(y, x)) {
            return true;
        } else if (at_city(player.position.y, player.position.x) && at_city(y, x)) {
            return true;
        } else if (at_friend(player.position.y, player.position.x) && at_friend(y, x)) {
            return true;
        } else if (at_baby(player.position.y, player.position.x) && at_baby(y, x)) {
            return true;
        } else {
            return false;
        }
        
    } else {
        
        return false;
    }
}


bool at_home(int given_y, int given_x) {
    
    Position top_left_corner;
    top_left_corner.y = 0;
    top_left_corner.x = 0;
    
    Position bot_right_corner;
    bot_right_corner.y = 9;
    bot_right_corner.x = 7;
    
    if( given_x <= bot_right_corner.x &&
        given_y <= bot_right_corner.y &&
        given_x >=  top_left_corner.x &&
        given_y >=  top_left_corner.y    ) {
            
            return true;
        } else {
            return false;
        }
}

bool at_city(int given_y, int given_x) {
    
    Position top_left_corner;
    top_left_corner.y = 11;
    top_left_corner.x = 0;
    
    Position bot_right_corner;
    bot_right_corner.y = 28;
    bot_right_corner.x = 10;
    
    if( given_x <= bot_right_corner.x &&
        given_y <= bot_right_corner.y &&
        given_x >=  top_left_corner.x &&
        given_y >=  top_left_corner.y    ) {
            
            return true;
        } else {
            return false;
        }
}

bool at_friend(int given_y, int given_x) {
    
    Position top_left_corner;
    top_left_corner.y = 31;
    top_left_corner.x = 0;
    
    Position bot_right_corner;
    bot_right_corner.y = 37;
    bot_right_corner.x = 4;
    
    if( given_x <= bot_right_corner.x &&
        given_y <= bot_right_corner.y &&
        given_x >=  top_left_corner.x &&
        given_y >=  top_left_corner.y    ) {
            
            return true;
        } else {
            return false;
        }
}

bool at_baby(int given_y, int given_x) {
    
    Position top_left_corner;
    top_left_corner.y = 31;
    top_left_corner.x = 6;
    
    Position bot_right_corner;
    bot_right_corner.y = 34;
    bot_right_corner.x = 8;
    
    if( given_x <= bot_right_corner.x &&
        given_y <= bot_right_corner.y &&
        given_x >=  top_left_corner.x &&
        given_y >=  top_left_corner.y    ) {
            
            return true;
        } else {
            return false;
        }
}