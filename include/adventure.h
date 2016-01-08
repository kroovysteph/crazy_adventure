#ifndef ADVENTURE_H
#define ADVENTURE_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "base.h"
#include "list.h"
#include "items.h"
#include "entities.h"
#include "room.h"


#define FIELD_WIDTH 11
#define FIELD_HEIGHT 38
#define DEBUG_MODE 0

/**Playing field. Each field contains a
 * pointer of Room structs at a certain place.
 */
Room **field;
Player player;
Enemy bear;
int difficulty;
Checkpoints cp;

typedef struct Turncounter {
    int current_turn;
    int bear_started;
    bool bear_event;
} Turncounter;
Turncounter turn;

//------------------------------------
typedef struct Level1 {
    bool picture;
    bool grave;
} Level1;

Level1 lv1;
//------------------------------------

/**Declarartions.
 */
void init_game(void);
int evaluate(void);
void init_field(void);
void game_loop(void);
void finish(void);
void epic_string_cpy(char from[], char to[]);
Item *create_item(char item[]);
void print_field(void);
Room make_room(bool wall, char ambience[], char item1[], char item2[], char item3[], char item4[], char item5[], char item6[], char item7[], char item8[], char item9[], char item10[]);
Player init_player(char s[]);
Enemy init_bear(void);
void random_string(char input[]);
void go_left(char input[]);
void go_down(char input[]);
void go_up(char input[]);
void go_right(char input[]);
void put_item(void);
void get_item(void);
void examine(void);
void print_stats(void);
void look(void);
int quit(void);
void list_items(void);
void random_error_string(void);
void print_itemlist(List list);
void print_title(void);
void print_manual(void);
void print_tombstone(void);
Checkpoints create_checkpoints(void);
Turncounter create_Turncounter(void);
void cp_event(int cp_counter);
void map(int sight_range);
bool near_player(int y, int x, int y_range, int x_range);
bool at_home(int given_y, int given_x);
bool at_city(int given_y, int given_x);
bool at_friend(int given_y, int given_x);
bool at_baby(int given_y, int given_x);
void print_prolog(void);
Level1 init_level1(void);
bool p_has_item(char item[]);
bool quest1_solved(void);
void place_bear_behind_player(void);
void apply(void);



#endif