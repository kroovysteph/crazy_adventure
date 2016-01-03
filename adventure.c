/*
Compile and run: make adventure && ./adventure
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "base.h"
#include "string.h"
#include "list.h"
#include "string_list.h"
#include "array.h"
#include "pointer_array.h"
#include "items.h"

/**A room at a certain point of the field.
 * Each Room struct contains gettable,
 * ungettable Stuff and the room description.
 */ 
typedef struct Room
{
    String ambience;
    bool wall;
    List gettableStuff;  //List contains pointers to Structs.
    List ungettableStuff;    //List contains pointers to Structs.
} Room;

/**Playing field. Each field contains a
 * pointer of Room structs at a certain place.
 */
Room **field;
#define FIELD_WIDTH 10
#define FIELD_HEIGHT 10

/**The actual Position of the Player.
 */
typedef struct Position
{
    int x;
    int y;
} Position;

/**The Player with his name, his inventory, the actual position, health and moral.
 */
typedef struct Player
{
    String name;  //Can be chosen at the start of the game.
    List inventory;  //List contains pointers to Structs.
    Position position;
    
    float health;
    int alignment;
} Player;
    


/**Declarartions
 */
Room make_room(bool wall, char ambience[], char item1[], char item2[], char item3[], char item4[], char item5[], char item6[], char item7[], char item8[], char item9[], char item10[]);
Player init_player(String s);
void init_game(void);
void init_field(void);
Player player;

/**Initialise the field, Rooms and the Player.
 * [Room][Room][xxxx][Room][Room]
 * [Room][Room][xxxx][Room][Room]    [Room]: ambience, gettable, ungettable, posoition
 * [Room][Room][xxxx][xxxx][xxxx]
 * [Room][Room][Room][Room][Room]
 * [Room][Room][Room][Room][Room]
 * [Room][Room][Room][Room][Room]
 * [Room][Room][Room][Room][Room]
 * [Room][Room][Room][Room][Room]
 */
void init_game(void)
{
    //Init the playground containing the different rooms.
    init_field();
    
    //Init Player with a chosen name (using standard-input-output).
    String s = "";
    printf("\nEnter your name: ");
    scanf("%s", s);
    player = init_player(s);
    printf("Your name is %s.\n\n", player.name);
}

//Fill the field with rooms
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
    //for(int i = 0; i < FIELD_WIDTH * FIELD_HEIGHT; i++)
    for(int i = 0; i < 2; i++)
    {
        bool wall = false;
        int coord_x = 0;
        int coord_y = 0;
        char room_or_wall[] = "";
        char ambience[] = "";
        char item1[] = "";
        char item2[] = "";
        char item3[] = "";
        char item4[] = "";
        char item5[] = "";
        char item6[] = "";
        char item7[] = "";
        char item8[] = "";
        char item9[] = "";
        char item10[] = "";
        
        //Boolean to represent a field as a wall.
        if(room_or_wall[0] == 'W')
        {
            wall = true;
        }
        else
        {
            wall = false;
        }
        
        for(int y = 0; y < FIELD_HEIGHT; y++)
        {
            for(int x = 0; x < FIELD_WIDTH; x++)
            {
                printf("field[%d][%d]: %s\n", y, x, field[y][x].ambience);
            }
        }
        
        //Fill the pointer-array with rooms using the make_room function.
        fscanf(fp, "%s %d %d %s %s %s %s %s %s %s %s %s %s %s", room_or_wall, &coord_x, &coord_y, ambience, item1, item2, item3, item4, item5, item6, item7, item8, item9, item10);
        field[coord_y][coord_x] = make_room(wall, ambience, item1, item2, item3, item4, item5, item6, item7, item8, item9, item10);
    }
    fclose(fp);
}

//TODO
Room make_room(bool wall, char ambience[], char item1[], char item2[], char item3[], char item4[], char item5[], char item6[], char item7[], char item8[], char item9[], char item10[])
{
    Room room;
    //content
    return room;
}

Player init_player(String s)
{
    Player p;
    
    p.name = s;
    
    //TODO:List inventory change NULL to List-Header!
    p.inventory = NULL;
    
    p.position.x = 0;
    p.position.y = 0;
    
    p.health = 10.0;
    p.alignment = 0;
    
    return p;
}




int main(void)
{
    //Freed memory check.
    base_init();
    base_set_memory_check(true);
    
    init_game();
    
    return 0;
}