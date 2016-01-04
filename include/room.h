#ifndef ROOM_H
#define ROOM_H



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

#endif