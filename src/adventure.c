/**
 * Compile and run: make adventure && ./adventure
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "base.h"
#include "list.h"
#include "string_list.h"
#include "items.h"

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
    char name[25];  //Can be chosen at the start of the game.
    List inventory;  //List contains pointers to Structs.
    Position position;
    int capacity;
    int weight_carrying;
    int health;
    int alignment;
} Player;

/**Declarartions.
 */
Player player;
void init_game(void);
void init_field(void);
void epic_string_cpy(char from[], char to[]);
void * create_item(char item[]);
Room make_room(bool wall, char ambience[], char item1[], char item2[], char item3[], char item4[], char item5[], char item6[], char item7[], char item8[], char item9[], char item10[]);
Player init_player(char s[]);
void finish(void);

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

//String copy function.
void epic_string_cpy(char from[], char to[])
{
    int i = 0;
    while(from[i] != '\0')
    {
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';
}

/**Dynamically allocate memory for the item structs
 * and actually save the pointer to it into the pointer list of items.
 * Comparing the given String by the .txt file to the item database.
 */
void * create_item(char item[])
{
    if(0 == strcmp(item, "Bucket"))
    {
        Bucket * p = malloc(sizeof(Bucket));
        Bucket bucket;
        p = &bucket;
        epic_string_cpy("Bucket", p->name);
        p->weight = 1;
        return p;
    }
    else if(0 == strcmp(item, "Sword"))
    {
        Sword * p = malloc(sizeof(Sword));
        Sword sword;
        p = &sword;
        epic_string_cpy("Sword", p->name);
        p->damage = 6;
        p->weight = 2;
        return p;
    }
    return NULL;
}

/**Create a Room and fill it with the given elements.
 */
Room make_room(bool wall, char ambience[], char item1[], char item2[], char item3[], char item4[], char item5[], char item6[], char item7[], char item8[], char item9[], char item10[])
{
    Room room;
    
    room.wall = wall;
    epic_string_cpy(ambience, room.ambience);
    room.items = l_create(sizeof(void*));
    
    //Ignore placeholder.
    if(item1[0] != '<')
    {
        l_append(room.items, create_item(item1));
    }
    if(item2[0] != '<')
    {
        l_append(room.items, create_item(item2));
    }
    if(item3[0] != '<')
    {
        l_append(room.items, create_item(item3));
    }
    if(item4[0] != '<')
    {
        l_append(room.items, create_item(item4));
    }
    if(item5[0] != '<')
    {
        l_append(room.items, create_item(item5));
    }
    if(item6[0] != '<')
    {
        l_append(room.items, create_item(item6));
    }
    if(item7[0] != '<')
    {
        l_append(room.items, create_item(item7));
    }
    if(item8[0] != '<')
    {
        l_append(room.items, create_item(item8));
    }
    if(item9[0] != '<')
    {
        l_append(room.items, create_item(item9));
    }
    if(item10[0] != '<')
    {
        l_append(room.items, create_item(item10));
    }
    
    return room;
}

//Init the player with it´s stats.
Player init_player(char s[])
{
    Player p;
    
    epic_string_cpy(s, p.name);
    
    p.inventory = l_create(sizeof(void*));
    
    p.position.x = 0;
    p.position.y = 0;
    
    p.capacity = 20;
    p.weight_carrying = 0;
    p.health = 10.0;
    p.alignment = 0;
    
    return p;
}

//TODO
void finish(void)
{
    //List items
    //Room **field
    //List inventory
    exit(0);
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