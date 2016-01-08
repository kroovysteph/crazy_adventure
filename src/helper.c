#include "adventure.h"


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


//Function that prints a randomly chosen String to represent a wrong player input.
void random_error_string(void)
{
    int random_number;
    srand(time(NULL));
    //Generate a random int between [1, 5].
    for(int i = 0; i < 10; i++)
    {
        random_number = rand() % 5 + 1;
    }
    //Print a random String, added by the direction.
    switch(random_number)
    {
        case 1:
            printf("\nDid you mean something else?");
            break;
        case 2:
            printf("\nThis isn´t the right way to do that.");
            break;
        case 3:
            printf("\nYou can´t do that like this.");
            break;
        case 4:
            printf("\nThat´s not possible!");
            break;
        case 5:
            printf("\nTry it another way.");
            break;
        default:
            break;
    }
    printf("\n");
}


//Function that prints a randomly chosen String and takes the players input.
void random_string(char input[])
{
    int random_number;
    srand(time(NULL));
    char direction[10];
    
    //Check for the direction given by the player.
    if(input[0] == 'l')
    {
        epic_string_cpy("west", direction);
    }
    else if(input[0] == 'r')
    {
        epic_string_cpy("east", direction);
    }
    else if(input[0] == 'u')
    {
        epic_string_cpy("north", direction);
    }
    else if(input[0] == 'd')
    {
        epic_string_cpy("south", direction);
    }
    
    //Generate a random int between [1, 5].
    for(int i = 0; i < 10; i++)
    {
        random_number = rand() % 5 + 1;
    }
    //Print a random String, added by the direction.
    switch(random_number)
    {
        case 1:
            printf("\nYou´re going %s.\n", direction);
            break;
        case 2:
            printf("\nYou´re walking across a way that´s headed %s.\n", direction);
            break;
        case 3:
            printf("\nAfter a long and burdened journey you reach the far %s.\n", direction);
            break;
        case 4:
            printf("\nWith great efford you reach your destination in the %s.\n", direction);
            break;
        case 5:
            printf("\nYou are finally there: The %s!\n", direction);
            break;
        default:
            break;
    }
}


//TODO
void finish(void)
{
    //List items
    for(int y = 0; y < FIELD_HEIGHT; y++)
    {
        for(int x = 0; x < FIELD_WIDTH; x++)
        {
            if(field[y][x].items != NULL)
            {
                l_free(field[y][x].items);
            }
        }
    }
    
    
    /*
    //Room **field
    for(int i = 0; i < FIELD_HEIGHT; i++)
    {
        if(field[i] != NULL)
        {
            free(field[i]);
        }
    }
    if(field != NULL)
    {
        free(field);
    }
    */
    
    //List inventory
    if(player.inventory != NULL)
    {
        l_free(player.inventory);
    }
    exit(0);
}


void cp_event(int cp_counter) {
    
    if(cp_counter == 3) {
        printf("\nYou checked three places that came to your mind, where people could be in a city if something terrible happens. ");
        printf("Slowly you're beginning to wonder if you'll ever find someone in this city.\n");
    }
    
    if(cp_counter == 4) {
        printf("\nYou can only think of one more place to look for people.\n");
    }
    
    if(cp_counter == 5) {
        printf("\nThat was the last place. You couldn't find anyone at all...\n");
        printf("\nYou remember the way back to the house you woke up in quite well. It should´ve been your own house before these strange things happened to you. All in all you just want to wape up from this horrible dream. But you can't. You're going back to the house. On the way it becomes night. You're just falling - shocked from the events - right into the bed you came from.");
        printf("\nThe next morning you wake up you're starting to remember about your child. You know you dreamt about it. The child on the picture you took. A place where your child used to hang out when the school was over comes to your mind. This last place you'll look up to find your child you're screaming. \"If I can't find my child, or anyone, I'll kill myself!\".");
        printf("\nYou're remembering the street and the number, so you`re traveling there. With bare strength and some stones you manage to get into the house and you find yourself in the entering room of the house.");
        player.position.x = 2;
        player.position.y = 32;
    }
}

Turncounter create_Turncounter(void) {
    
    Turncounter turn;
    
    turn.current_turn = 0;
    turn.bear_started = 0;
    turn.bear_event = false;
    
    return turn;
}