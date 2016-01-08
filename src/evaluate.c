#include "adventure.h"

int evaluate(Checkpoints cp) {
    
    char input2[25];
    int cp_counter = 0;
    
    if(cp.supermarket)  {cp_counter++;}
    if(cp.townhall)     {cp_counter++;}
    if(cp.church)       {cp_counter++;}
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
