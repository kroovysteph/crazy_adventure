/*
Compile: make adventure
Run: ./adventure
make adventure && ./adventure
*/

#include "base.h"          // http://hci.uni-hannover.de/files/prog1lib/base_8h.html
#include "string.h"        // http://hci.uni-hannover.de/files/prog1lib/string_8h.html
#include "list.h"          // http://hci.uni-hannover.de/files/prog1lib/list_8h.html
#include "string_list.h"   // http://hci.uni-hannover.de/files/prog1lib/string__list_8h.html
#include "array.h"         // http://hci.uni-hannover.de/files/prog1lib/array_8h.html
#include "pointer_array.h" // http://hci.uni-hannover.de/files/prog1lib/pointer__array_8h.html

/**
Playing field. Each field contains a string list of objects at that place.
*/
Array field = NULL;
#define FIELD_WIDTH 10
#define FIELD_HEIGHT 10

/**
String list of things that the player carries.
*/
List stuff = NULL;

/**
String list of things that cannot be picked up (e.g., walls).
*/
List cannot_get = NULL;

/**
A 2D position.
*/
typedef struct {
    int x;
    int y;
} Position; 

/**
Constructor function for a position.
*/
Position make_position(int x, int y) {
    Position p = { x, y };
    return p;
}

/**
Current player position on the field.
*/
Position position;

/**
Previous player position on the field.
*/
Position previous_position;

/**
What the player said in the last round.
*/
String statement = NULL;

/**
Convert 2D position to array index.
*/
int index_of_position(Position p) {
    return p.y * FIELD_WIDTH + p.x;
}

/**
Convert array index to 2D position.
*/
Position position_of_index(int i) {
    return make_position(i % FIELD_WIDTH, i / FIELD_WIDTH);
}

/**
Set field position (x,y) to the given string, which is parsed to a string list.
*/
void set(int x, int y, String s) {
    pa_set(field, index_of_position(make_position(x, y)), sl_of_string(s));
}

/**
Get the list of things at the given position.
*/
List get_place(Position p) {
    int i = index_of_position(p);
    List l = pa_get(field, i);
    if (l == NULL) {
        l = sl_create();
        pa_set(field, i, l);
    }
    return l;
}

/**
Get the list of things at the player's current position.
*/
List current_place(void) {
    return get_place(position);
}

/**
Get the list of things at the player's previous position.
*/
List previous_place(void) {
    return get_place(previous_position);
}

/**
Initialize the field
*/
void initialize_game(void) {
    position = make_position(0, 0);
    previous_position = make_position(0, 0);
    field = pa_create(FIELD_WIDTH * FIELD_HEIGHT, NULL);
    set(1, 0, "apple, key, goat");
    set(2, 0, "wall");
    set(2, 1, "wall");
    set(1, 1, "wall");
    set(0, 1, "door");
    set(0, 2, "hungry monster");
    set(4, 4, "friendly gnome");
    set(FIELD_WIDTH - 1, FIELD_HEIGHT - 1, "xmas tree");
    stuff = sl_create();
    cannot_get = sl_of_string("wall, door");
}

/**
Print the current state of the game, including the list of things the player 
has and the list of things in the current place.
*/
void print_situation(void) {
    // very simple output of the field
    int i = 0;
    for (int y = 0; y < FIELD_HEIGHT; y++) {
        for (int x = 0; x < FIELD_WIDTH; x++) {
            if (position.x == x && position.y == y) {
                prints("P"); // player marked as P
            } else {
                List place = pa_get(field, i);
                if (place == NULL || l_length(place) == 0) {
                    prints("."); // empty field marked as .
                } else {
                    prints("x"); // non-empty field marked as x
                }
            }
            i++;
        }
        println();
    }
    
    // printf("You are at %d, %d.\n", position.x, position.y);

    prints("You have: ");
    sl_println(stuff);

    prints("Here is: ");
    List place = current_place();
    sl_println(place);
    
    prints("> "); // prompt for user input
}

/**
Clean up state and end the game.
*/
void finish(void) {
    for (int i = 0; i < FIELD_WIDTH * FIELD_HEIGHT; i++) {
        List l = pa_get(field, i);
        sl_free(l);
    }
    a_free(field);
    sl_free(stuff);
    sl_free(cannot_get);
    if (statement != NULL) {
        s_free(statement);
    }
    exit(0);
}

/**
Removes the given string from the string list and deletes the string (if it is contained in the list).
*/
void remove_and_delete(List l, String s) {
    int i = sl_index(l, s);
    if (i >= 0) {
        s_free(sl_get(l, i));
        sl_remove(l, i);
    }
}

/**
Evaluate the current situation on the playing field according to the game rules.
*/
void evaluate_situation(void) {
    List place = current_place();
    if (sl_contains(place, "wall")) {
        printsln("There is a wall here. You cannot go through walls.");
        position = previous_position;
    }
    if (sl_contains(place, "door") && !sl_contains(stuff, "key")) {
        printsln("The door is locked. You cannot pass.");
        position = previous_position;
    }
    if (sl_contains(place, "hungry monster") && sl_contains(place, "apple")) {
        printsln("The monster eats the apple. It is full and sleeps now.");
        remove_and_delete(place, "hungry monster");
        remove_and_delete(place, "apple");
        sl_append(place, s_copy("sleeping monster")); // s_copy, because place contains dynamically allocated strings
    }
    if (sl_contains(previous_place(), "hungry monster")) {
        printsln("The monster eats you before you can get away.");
        finish();
    }
    if (sl_contains(place, "friendly gnome") && statement != NULL && s_starts_with(statement, "hello")) {
        printsln("Hello! I have some secret information for you: The Xmas tree is in the lower right corner of the field!");
    }
    if (sl_contains(stuff, "xmas tree")) {
        printsln("You won! Congratulations!");
        finish();
    }
}

/**
Returns true if (and only if) element starts with x.
*/
bool starts_with(String element, int index, String x) {
    return s_starts_with(element, x);
}

/**
Play the adventure using input from console. The commands are:
q: quit
l: go left
r: go right
u: go up
d: go down
g <object>: get the object, example: g key
p <object>: put the object, example: p apple
s <statement>: says something, example: s hello
*/
void play_adventure(void) {
    initialize_game();
    print_situation();

    String input, verb, object;
    while (!s_starts_with(input = s_input(100), "q")) {
        List place = current_place();
        previous_position = position;
        List linput = sl_split(input, ' ');
        int n = l_length(linput);
        verb = (n >= 1) ? sl_get(linput, 0) : "";
        object = (n >= 2) ? sl_get(linput, 1) : "";
        // printf("verb = %s, object = %s\n", verb, object);
        if (statement != NULL) {
            s_free(statement); 
            statement = NULL;
        }

        if (s_starts_with(verb, "l")) { // left
            if (position.x > 0) position.x--;
            else printsln("You cannot go further left.");
        }
        else if (s_starts_with(verb, "r")) { // right
            if (position.x < FIELD_WIDTH - 1) position.x++;
            else printsln("You cannot go further right.");
        }
        else if (s_starts_with(verb, "u")) { // up
            if (position.y > 0) position.y--;
            else printsln("You cannot go further up.");
        }
        else if (s_starts_with(verb, "d")) { // down
            if (position.y < FIELD_HEIGHT - 1) position.y++;
            else printsln("You cannot go further down.");
        }
        else if (n == 2 && s_starts_with(verb, "g") && 
            !sl_contains(cannot_get, object)) 
        { // get
            int i = sl_index_fn(place, starts_with, object);
            if (i >= 0) {
                String s = sl_get(place, i);
                sl_remove(place, i);
                sl_append(stuff, s);
            }
        }
        else if (n == 2 && s_starts_with(verb, "p")) { // put
            int i = sl_index_fn(stuff, starts_with, object);
            if (i >= 0) {
                String s = sl_get(stuff, i);
                sl_remove(stuff, i);
                sl_append(place, s);
            }
        }
        else if (n >= 2 && s_starts_with(verb, "s")) { // say
            int i = s_index(input, " ");
            if (i >= 0) {
                statement = s_sub(input, i + 1, s_length(input));
                // printf("statement = '%s'\n", statement);
            }
        }

        s_free(input);
        sl_free(linput);
        evaluate_situation();
        print_situation();
    }
    
    s_free(input);
    finish();
}

int main(void) {
    base_init();
    base_set_memory_check(true);
    play_adventure();
    return 0;
}
