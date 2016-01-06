#ifndef PLAYER_H
#define PLAYER_H


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
    char name[25];  //Can be chosen at the start of the game.
    List inventory;  //List contains pointers to Structs.
    Position position;
    int capacity;
    int weight_carrying;
    int health;
    int alignment;
    int damage;
} Player;


#endif