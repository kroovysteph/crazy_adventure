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
    
    print_title();
    //Init Player with a chosen name (using standard-input-output).
    char s[25] = "";
    printf("\nPlease enter your name: ");
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
        char ambience[1000] = "";
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
    
    char input1[25] = "";
    
    while(true)
    {
        int c = 0;
        printf("> ");
        scanf("%s", input1);
        
        
        while(input1[c] != '\0')
        {
            input1[c] = tolower(input1[c]);
            c++;
        }
        
        
        if(strcmp(input1, "left") == 0 || 0 == strcmp(input1, "l"))
        {
            go_left(input1);
            print_field();
        }
        else if(strcmp(input1, "down") == 0 || 0 == strcmp(input1, "d"))
        {
            go_down(input1);
            print_field();
        }
        else if(strcmp(input1, "up") == 0 || 0 == strcmp(input1, "u"))
        {
            go_up(input1);
            print_field();
        }
        else if(strcmp(input1, "right") == 0 || 0 == strcmp(input1, "r"))
        {
            go_right(input1);
            print_field();
        }
        else if(strcmp(input1, "get") == 0 || 0 == strcmp(input1, "g"))
        {
            get_item();
        }
        else if(strcmp(input1, "put") == 0 || 0 == strcmp(input1, "p"))
        {
            put_item();
        }
        else if(0 == strcmp(input1, "look"))
        {
            look();
        }
        else if(strcmp(input1, "examine") == 0 || 0 == strcmp(input1, "ex"))
        {
            examine();
        }
        else if(0 == strcmp(input1, "ls"))
        {
            list_items();
        }
        else if(strcmp(input1, "quit") == 0 || 0 == strcmp(input1, "q"))
        {
            printf("You have successfully closed the game.\n");
            break;
        }
        else
        {
            random_error_string();
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