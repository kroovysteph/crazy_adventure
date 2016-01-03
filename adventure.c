/*
Compile and run: make adventure && ./adventure
*/

#include <stdio.h>
#include <stdlib.h>
#include "base.h"
#include "string.h"
#include "list.h"
#include "string_list.h"
#include "array.h"
#include "pointer_array.h"

/**Playing field. Each field contains a:
 * pointer of Room structs at a certain place.
 */
Array field = NULL;
#define FIELD_WIDTH 10
#define FIELD_HEIGHT 10

/**A room at a certain point of the field.
 * Each Room struct contains gettable,
 * ungettable Stuff and the room description.
 */ 
typedef struct Room
{
    String ambience;
    List gettableStuff;  //List contains pointers to Structs.
    List ungettableStuff;    //List contains pointers to Structs.
} Room;

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
Player init_player(String s);
void init_game(void);
Player player;

/**Initialise the field, Rooms and the Player.
 */
void init_game(void)
{
    //init playground
    field = pa_create(FIELD_WIDTH * FIELD_HEIGHT, NULL);
    
    //init Rooms
    
    //init Player with a chosen name.
    char s[50] = "";
    printf("\nEnter your name: ");
    scanf("%s", s);
    player = init_player(s);
    
    printf("Your name is %s.\n\n", player.name);
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









