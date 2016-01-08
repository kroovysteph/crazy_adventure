/**
 * Compile and run: make adventure && ./adventure
 */


#include "adventure.h"


/**Initialise the field, Rooms and the Player.
 */
void init_game(void)
{
    char dump[1000];
    int status;
    lv1 = init_level1();
    //lv2 = init_level2();
    
    //Init the playground containing the different rooms.
    init_field();
    print_title();
    
    //read difficulty
    difficulty = 0;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    while ( !(difficulty == 1 || difficulty == 2 || difficulty == 3) ) {
        printf("\nPlease enter the difficulty: ");
        printf("\n(This effects, e.g. how far you can see when using \"map\".)");
        printf("\n(1) hard");
        printf("\n(2) medium");
        printf("\n(3) easy");
        printf("\n(1/2/3): ");
        status = scanf("%d", &difficulty);
        
        if (status == 0) {
            //catch wrong input (= String)
            scanf("%s", dump);
        }
    }
    switch (difficulty) {
        case (1):
            printf("You chose \"hard\".\n\n");
            break;
        case (2):
            printf("You chose \"medium\".\n\n");
            break;
        case (3):
            printf("You chose \"easy\".\n\n");
            break;
    }
    
    print_prolog();
    
    //Init Player with a chosen name (using standard-input-output).
    char s[25] = "";
    printf("\nPlease enter your name: ");
    scanf("%s", s);
    player = init_player(s);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("You remember your name. It's %s.\n", player.name);
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
    
    cp = create_checkpoints();
    turn = create_Turncounter();
    
    char input1[25] = "";
    
    while(evaluate())
    {
        if(difficulty != 1 && difficulty != 2) {
            map(difficulty);
        }
        turn.current_turn++;
        int c = 0;
        printf("> ");
        scanf("%s", input1);
        
        
        while(input1[c] != '\0')
        {
            input1[c] = tolower(input1[c]);
            c++;
        }
        

        if(strcmp(input1, "left") == 0 || 0 == strcmp(input1, "l") || strcmp(input1, "west") == 0 || 0 == strcmp(input1, "w"))
        {
            go_left(input1);
            print_field();
        }
        else if(strcmp(input1, "down") == 0 || 0 == strcmp(input1, "d") || strcmp(input1, "south") == 0 || 0 == strcmp(input1, "s"))
        {
            go_down(input1);
            print_field();
        }
        else if(strcmp(input1, "up") == 0 || 0 == strcmp(input1, "u") || strcmp(input1, "north") == 0 || 0 == strcmp(input1, "n"))
        {
            go_up(input1);
            print_field();
        }
        else if(strcmp(input1, "right") == 0 || 0 == strcmp(input1, "r") || strcmp(input1, "east") == 0 || 0 == strcmp(input1, "e"))
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
        else if(strcmp(input1, "map") == 0)
        {
            map(difficulty);
        }
        else if(strcmp(input1, "man") == 0 || 0 == strcmp(input1, "help"))
        {
            print_manual();
        }
        else if(0 == strcmp(input1, "stats"))
        {
            print_stats();
        }
        else if(strcmp(input1, "quit") == 0 || 0 == strcmp(input1, "q"))
        {
            if (quit()) {
                break;
            }
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