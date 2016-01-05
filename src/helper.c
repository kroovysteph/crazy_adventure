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
            printf("Did you mean something else?");
            break;
        case 2:
            printf("This isn´t the right way to do that.");
            break;
        case 3:
            printf("You can´t do that like this.");
            break;
        case 4:
            printf("That´s not possible!");
            break;
        case 5:
            printf("Try it another way.");
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
            printf("You´re going %s.\n", direction);
            break;
        case 2:
            printf("You´re walking across a way that´s headed %s.\n", direction);
            break;
        case 3:
            printf("After a long and burdened journey you reach the far %s.\n", direction);
            break;
        case 4:
            printf("With great efford you reach your destination in the %s.\n", direction);
            break;
        case 5:
            printf("You are finally there: The %s!\n", direction);
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