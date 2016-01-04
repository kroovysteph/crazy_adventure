#include "adventure.h"


/**The Player with his name, his inventory, the actual position, health and moral.
 */
typedef struct Player
{
    char name[25];  //Can be chosen at the start of the game.
    List inventory;  //List contains pointers to Structs.
    Position position;
    int capacity;
    int weight_carrying;
    int health;
    int alignment;
} Player;