/**
 * Compile and run: make adventure && ./adventure
 */


#include "adventure.h"


/**Initialise the field, Rooms and the Player.
 */
void init_game(void)
{
    //Init the playground containing the different rooms.
    init_field();
    
    //Init Player with a chosen name (using standard-input-output).
    char s[25] = "";
    printf("\nEnter your name: ");
    scanf("%s", s);
    player = init_player(s);
    printf("Your name is %s.\n\n", player.name);
}


//Fill the field with rooms.
void init_field(void)
{
    //Create the pointer-array and the file-pointer to the .txt containing the elements for the rooms.
    field = (Room **)malloc(FIELD_HEIGHT * sizeof(Room*));
    for(int i = 0; i < FIELD_HEIGHT; i++)
    {
        field[i] = (Room *)malloc(FIELD_WIDTH * sizeof(Room));
    }
    
    
    FILE * fp = fopen("field.txt", "r");
    
    
    //Iterate through the pointer-array.
    for(int i = 0; i < FIELD_WIDTH * FIELD_HEIGHT; i++)
    {
        bool wall = false;
        int coord_x = 0;
        int coord_y = 0;
        
        //Respect the maximum size for the objects of the room!
        char room_or_wall[5] = "";
        char ambience[100] = "";
        char item1[25] = "";
        char item2[25] = "";
        char item3[25] = "";
        char item4[25] = "";
        char item5[25] = "";
        char item6[25] = "";
        char item7[25] = "";
        char item8[25] = "";
        char item9[25] = "";
        char item10[25] = "";
        
        
        fscanf(fp, "%s %d %d %s %s %s %s %s %s %s %s %s %s %s", room_or_wall, &coord_y, &coord_x, ambience, item1, item2, item3, item4, item5, item6, item7, item8, item9, item10);
        
        
        //Boolean to represent a field as a wall.
        if(room_or_wall[0] == 'W')
        {
            wall = true;
        }
        else
        {
            wall = false;
        }
        
        
        //Fill the pointer-array with rooms using the make_room function.
        field[coord_y][coord_x] = make_room(wall, ambience, item1, item2, item3, item4, item5, item6, item7, item8, item9, item10);
    }
    fclose(fp);
}


void game_loop(void)
{
    print_field();
    
    int x;
    int y;
    bool found = false;
    char input1[25] = "";
    char input2[25] = "";
    
    while( input1[0] != 'q' )
    {
        printf("> ");
        scanf("%s", input1);
        
        x = player.position.x;
        y = player.position.y;
        
        switch(input1[0])
        {
            case 'l':
                if(x > 0 && !(field[y][x-1].wall))
                {
                    player.position.x--;
                    random_string(input1);
                }
                else
                {
                    printf("You cannot go that way...\n");
                }
                print_field();
                break;
            case 'd':
                if(y < FIELD_HEIGHT-1 && !(field[y+1][x].wall))
                {
                    player.position.y = (player.position.y + 1);
                    random_string(input1);
                }
                else
                {
                    printf("You cannot go that way...\n");
                }
                print_field();
                break;
            case 'u':
                if(y > 0 && !(field[y-1][x].wall))
                {
                    player.position.y--;
                    random_string(input1);
                }
                else
                {
                    printf("You cannot go that way...\n");
                }
                print_field();
                break;
            case 'r':
                if(x < FIELD_WIDTH-1 && !(field[y][x+1].wall))
                {
                    player.position.x++;
                    random_string(input1);
                }
                else
                {
                    printf("You cannot go that way...\n");
                }
                print_field();
                break;
            case 'g':
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
                break;
            case 'q':
                break;
            //TODO: Error if the player uses an unknown command.
            default:
                printf("Did you mean something else?...\n");
                break;
        }
    }
}


int main(void)
{
    //Freed memory check.
    base_init();
    base_set_memory_check(true);
    
    init_game();
    game_loop();
    
    finish();
    return 0;
}