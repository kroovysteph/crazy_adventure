/**
 * Compile and run: make adventure && ./adventure
 */

#include "adventure.h"

/**Playing field. Each field contains a
 * pointer of Room structs at a certain place.
 */
Room **field;
#define FIELD_WIDTH 10
#define FIELD_HEIGHT 10
Player player;



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
        fscanf(fp, "%s %d %d %s %s %s %s %s %s %s %s %s %s %s", room_or_wall, &coord_x, &coord_y, ambience, item1, item2, item3, item4, item5, item6, item7, item8, item9, item10);
        field[coord_y][coord_x] = make_room(wall, ambience, item1, item2, item3, item4, item5, item6, item7, item8, item9, item10);
    }
    fclose(fp);
}




int main(void)
{
    //Freed memory check.
    base_init();
    base_set_memory_check(true);
    //Not using xmalloc so we need to free the dinamically allocated memory!
    
    init_game();
    
    return 0;
}