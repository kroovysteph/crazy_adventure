#include "adventure.h"



/**A room at a certain point of the field.
 * Each Room struct contains a List with pointers to items
 * and the room description.
 */ 
typedef struct Room
{
    char ambience[100];
    bool wall;
    List items;  //List contains pointers to Structs.
} Room;



/**The actual Position of the Player.
 */
typedef struct Position
{
    int x;
    int y;
} Position;