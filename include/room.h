#ifndef ROOM_H
#define ROOM_H


/**A room at a certain point of the field.
 * Each Room struct contains a List with pointers to items
 * and the room description.
 */ 
typedef struct Room
{
    char ambience[1000];    //Change the ambience, if an item has been picked up! -->evaluate function.
    bool wall;
    List items;  //List contains pointers to Structs.
} Room;

typedef struct Checkpoints
{
    //true if player was in that place
    bool supermarket;
    bool townhall;
    bool church;
    bool school;
    bool trainstation;
} Checkpoints;

#endif