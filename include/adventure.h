#ifndef ADVENTURE_H
#define ADVENTURE_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "base.h"
#include "list.h"
#include "string_list.h"
#include "items.h"
#include "player.h"
#include "room.h"


#define FIELD_WIDTH 10
#define FIELD_HEIGHT 10


/**Playing field. Each field contains a
 * pointer of Room structs at a certain place.
 */
Room **field;
Player player;


/**Declarartions.
 */
void init_game(void);
void init_field(void);
void finish(void);
void epic_string_cpy(char from[], char to[]);
void * create_item(char item[]);
void print_field(void);
Room make_room(bool wall, char ambience[], char item1[], char item2[], char item3[], char item4[], char item5[], char item6[], char item7[], char item8[], char item9[], char item10[]);
Player init_player(char s[]);


#endif