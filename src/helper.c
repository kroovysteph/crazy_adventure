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


int evaluate(Checkpoints cp) {
    
    char input2[25];
    int cp_counter = 0;
    
    if(cp.supermarket)  {cp_counter++;}
    if(cp.townhall)     {cp_counter++;}
    if(cp.church)        {cp_counter++;}
    if(cp.school)       {cp_counter++;}
    if(cp.trainstation) {cp_counter++;}
    
    int x = player.position.x;
    int y = player.position.y;

    //evaluate status/health
    if(player.health <= 0) {
        
        printf("\n%s died a tragical death...\n", player.name);
        
        //TODO: implement graphical Tombstone -> in ascii_graphics.c
        print_tombstone();
        
        return 0;
    }
    if(x == bear.position.x && y == bear.position.y && turn.bear_event) {
        
        printf("\nThe bear devours %s's body...\n", player.name);
        //TODO: implement graphical Tombstone -> in ascii_graphics.c
        print_tombstone();
        
        return 0;
    }
    
    //bear event
    if(x == 5 && y == 16 && !(turn.bear_event) && turn.bear_started == 0) {
        //bear event starts
        turn.bear_started = turn.current_turn;
        if(!turn.bear_event) {
            bear = init_bear(); //y=13, x=5
        }
        turn.bear_event   = true;
    }
    
    if(x == 5 && y == 24 && turn.bear_event)
        //player is able to "hide"
    {
        
        printf("> ");
        scanf("%s", input2);
        if(strcmp("hide", input2) == 0) {
            turn.bear_event = false;
            printf("\nThe bear is gone!\n");
            print_field();
        }
        else
        {
            printf("\n%s, it's definetly the best option to \"hide\"!\n", player.name);
        }
        
        while( !(strcmp("hide", input2) == 0) )
        {
            printf("> ");
            scanf("%s", input2);
            if(strcmp("hide", input2) == 0) {
                turn.bear_event = false;
                printf("\nThe bear is gone!\n");
                print_field();
            }
            else
            {
                printf("\n%s, it's definetly the best option to \"hide\"!\n", player.name);
            }
        }
    }
    
    if((turn.current_turn - turn.bear_started) == 1 && turn.bear_event) {
        //bear's turn 1
        printf("\nRoarr!.. Your hear the bear chasing you!\n");
        //set back ambience.
        bear.position.y++;
    }
    if(turn.current_turn - turn.bear_started == 2 && turn.bear_event) {
        //bear's turn 2
        printf("\nRoarr!.. You know that Grizzlys can weigh up to 680 kg!\n");
        //TODO: bear-movement to y=15 x=5
        bear.position.y++;
    }
    if(turn.current_turn - turn.bear_started == 3 && turn.bear_event) {
        //bear's turn 3
        printf("\nRoarr!.. They can become up to 2.5 meters tall.\n");
        //TODO: bear-movement to y=16 x=5
        bear.position.y++;
    }
    if(turn.current_turn - turn.bear_started == 4 && turn.bear_event) {
        //bear's turn 4
        //decide vehicle event with "left" "right"
        printf("\nYou can see a car and a motorcycle. ");
        printf("You feel like you can only shake off the bear if only ");
        printf("one of these vehicles works. Now you need to decide which ");
        printf("one you try by going \"left\" for the motorcycle, or \"right\" ");
        printf("for the car.\n");
        //TODO: 1.scanf left or right (maybe 1 error == extra bear movement!!)
        printf("> ");
        scanf("%s", input2);
        while( !(/*von hier*/(strcmp("left", input2) == 0) || (strcmp("right",input2) == 0)
                    || (strcmp("l", input2) == 0) || (strcmp("r", input2) == 0)/*bis hier*/) ) {
            printf("\nWhat do you mean by \"%s\"? Choose right or left...\n> ", input2);
            scanf("%s", input2);
        }
        printf("\nIt seems like you've chosen the wrong one, although the key is plugged into the ignition log, the motor doesn't turn on.\n");
        printf("> ");
        turn.current_turn++;
        bear.position.y++;
        
        scanf("%s", input2);
        if(strcmp("left", input2) == 0) {
            printf("\nMotorcycle runs, yeah! Maybe next time, bear!");
        } else {
            printf("\nThe car starts, yeah! Cya later, bear!");
        }
        
        player.position.y = 21;
        player.position.x = 5;
        bear.position.y++;
    }
    if(turn.current_turn - turn.bear_started == 5 && turn.bear_event) {
        //bear's turn 5
        printf("\nROOAAARRRRR!!!!!!1111\n");
        bear.position.y++;
    }
    if(turn.current_turn - turn.bear_started == 6 && turn.bear_event) {
        //bear's turn 6
        printf("\nROOAAARRRRR!!!!!!1111\n");
        bear.position.y++;
    }
    if(turn.current_turn - turn.bear_started == 7 && turn.bear_event) {
        //bear's turn 8
        printf("\nROOAAARRRRR!!!!!!1111\n");
        bear.position.y++;
    }
    if(turn.current_turn - turn.bear_started == 8 && turn.bear_event) {
        //bear's turn 8
        printf("\nROOAAARRRRR!!!!!!1111\n");
        bear.position.y++;
    }
    if(turn.current_turn - turn.bear_started == 9 && turn.bear_event) {
        //bear's turn 9
        printf("\nROOAAARRRRR!!!!!!1111\n");
        bear.position.y++;
    }
    if(turn.current_turn - turn.bear_started == 10 && turn.bear_event) {
        //bear's turn 10
        printf("\nROOAAARRRRR!!!!!!1111\n");
        bear.position.y++;
    }
    if(turn.current_turn - turn.bear_started == 11 && turn.bear_event) {
        //bear's turn 11
        printf("\nROOAAARRRRR!!!!!!1121 lol?\n");
        bear.position.y++;
    }
    if(turn.current_turn - turn.bear_started == 12 && turn.bear_event) {
        //bear's turn 12
        printf("\nROOAAARRRRR!!!!!!1121 lol?\n");
        bear.position.y++;
    }
    
    //evaluate positioning
    if(x == 6 && y == 5) {
        //exit of player's house
        player.position.x = 1;
        player.position.y = 12;
    }
    
    //supermarket
    if(x == 3 && y == 15 && !cp.supermarket) {
        
        cp.supermarket = true;
        cp_counter++;
        
        cp_event(cp_counter);
    }
    
    //townhall
    if(x == 1 && y == 18 && !cp.townhall) {
        
        cp.townhall = true;
        cp_counter++;
        
        cp_event(cp_counter);
    }
    
    //church
    if(x == 23 && y == 7 && !cp.church) {
        
        cp.church = true;
        cp_counter++;
        
        cp_event(cp_counter);
    }
    
    //school
    if(x == 2 && y == 21 && !cp.school) {
        
        cp.school = true;
        cp_counter++;
        
        cp_event(cp_counter);
    }
    
    //trainstation
    if(x == 7 && y == 16 && !cp.trainstation) {
        
        cp.trainstation = true;
        cp_counter++;
        
        cp_event(cp_counter);
    }
    
    return 1;
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