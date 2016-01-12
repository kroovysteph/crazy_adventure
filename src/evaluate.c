#include "adventure.h"

int evaluate(void)
{
    
    char input2[25];
    int cp_counter = 0;
    
    if(cp.supermarket)  {cp_counter++;}
    if(cp.townhall)     {cp_counter++;}
    if(cp.church)       {cp_counter++;}
    if(cp.school)       {cp_counter++;}
    if(cp.trainstation) {cp_counter++;}
    
    int x = player.position.x;
    int y = player.position.y;
    
    cash_donationbox_same();
    
    //The player is spawned back to the event position.
    if(wolf_event1)
    {
        player.position.y = 13;
        player.position.x = 2;
    }
    if(wolf_event2)
    {
        player.position.y = 25;
        player.position.x = 2;
    }
    if(dog_event)
    {
        player.position.y = 13;
        player.position.x = 9;
    }
    
    if(quest1_solved())
    {
        epic_string_cpy("You are leaving your house.\n", field[5][6].ambience);
    }

    //evaluate status/health
    if(player.health <= 0)
    {
        
        printf("\n%s died a tragical death...\n", player.name);                //printf("%s\n", field[32][7].ambience);
        
        print_tombstone();
        
        return 0;
    }
    if(x == bear.position.x && y == bear.position.y && turn.bear_event && !turn.bear_knocked_down)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\nThe bear devours %s´s body...\n", player.name);
        print_tombstone();
        
        return 0;
    }
    
    //bear event
    if(x == 5 && y == 16 && !(turn.bear_event) && turn.bear_started == 0)
    {
        //bear event starts
        turn.bear_started = turn.current_turn;
        if(!turn.bear_event)
        {
            bear = init_bear(); //y=13, x=5
        }
        turn.bear_event   = true;
        place_bear_behind_player();
    }

    if(x == 5 && y == 24 && turn.bear_event && !turn.bear_knocked_down)
        //player is able to "hide"
    {
        
        printf("> ");
        scanf("%s", input2);
        if(strcmp("hide", input2) == 0)
        {
            turn.bear_event = false;
            printf("\nThe bear is gone!\n");
            place_bear_behind_player();
//------------------------------------------------------------------------------
            epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[16][5].ambience);
            epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[17][5].ambience);
            epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[18][5].ambience);
            epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[19][5].ambience);
            epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[20][5].ambience);
            epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[21][5].ambience);
            epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[22][5].ambience);
            epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[23][5].ambience);
            epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[24][5].ambience);
//------------------------------------------------------------------------------
            print_field();
        }
        else
        {
            printf("\n%s, it´s definetly the best option to \"hide\"!\n", player.name);
        }
        
        while( !(strcmp("hide", input2) == 0) )
        {
            printf("> ");
            scanf("%s", input2);
            if(strcmp("hide", input2) == 0)
            {
                turn.bear_event = false;
                printf("\nThe bear is gone!\n");
                place_bear_behind_player();
//------------------------------------------------------------------------------
                epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[16][5].ambience);
                epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[17][5].ambience);
                epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[18][5].ambience);
                epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[19][5].ambience);
                epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[20][5].ambience);
                epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[21][5].ambience);
                epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[22][5].ambience);
                epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[23][5].ambience);
//------------------------------------------------------------------------------
                print_field();
            }
            else
            {
                printf("\n%s, it´s definetly the best option to \"hide\"!\n", player.name);
            }
        }
    }
    
    if((turn.current_turn - turn.bear_started) == 1 && turn.bear_event)
    {
        //bear´s turn 1
        printf("\nRoarr!.. Your hear the bear chasing you!\n");
        //set back ambience.
        bear.position.y++;
        place_bear_behind_player();
    }
    if(turn.current_turn - turn.bear_started == 2 && turn.bear_event)
    {                //printf("%s\n", field[32][7].ambience);
        //bear´s turn 2
        printf("\nRoarr!.. You know that Grizzlys can weigh up to 680 kg!\n");
        bear.position.y++;
        place_bear_behind_player();
    }
    if(turn.current_turn - turn.bear_started == 3 && turn.bear_event)
    {
        //bear´s turn 3
        printf("\nRoarr!.. They can become up to 2.5 meters tall.\n");
        bear.position.y++;
        place_bear_behind_player();
    }
    if(turn.current_turn - turn.bear_started == 4 && turn.bear_event)
    {
        epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[16][5].ambience);
        epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[17][5].ambience);
        epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[18][5].ambience);
        epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[19][5].ambience);
        epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[20][5].ambience);
        epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[21][5].ambience);
        epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[22][5].ambience);
        epic_string_cpy("You are still on a street. You can follow it in the northern and southern direction.", field[23][5].ambience);

        //bear´s turn 4
        //decide vehicle event with "left" "right"
        printf("\nYou can see a car and a motorcycle. ");
        printf("You feel like you can only shake off the bear if only ");
        printf("one of these vehicles works. Now you need to decide which ");
        printf("one you try by going \"left\" for the motorcycle, or \"right\" ");
        printf("for the car.\n");

        printf("> ");
        scanf("%s", input2);
        while( !(/*von hier*/(strcmp("left", input2) == 0) || (strcmp("right",input2) == 0)
                    || (strcmp("l", input2) == 0) || (strcmp("r", input2) == 0)/*bis hier*/) )
        {
            printf("\nWhat do you mean by \"%s\"? Choose right or left...\n> ", input2);
            scanf("%s", input2);
        }
        printf("\nIt seems like you´ve chosen the wrong one, although the key is plugged into the ignition log, the motor doesn´t turn on.\n");
        printf("> ");
        turn.current_turn++;
        bear.position.y++;
        place_bear_behind_player();
        
        scanf("%s", input2);
        if(strcmp("left", input2) == 0)
        {
            printf("\nMotorcycle runs, yeah! Maybe next time, bear!");
        }
        else
        {
            printf("\nThe car starts, yeah! Cya later, bear!");
        }
        
        player.position.y = 21;
        player.position.x = 5;
        bear.position.y++;
        place_bear_behind_player();
    }
    if(turn.current_turn - turn.bear_started == 5 && turn.bear_event)
    {
        //bear´s turn 5
        printf("\nROOAAARRRRR!!!!!!1111 The bear is STILL chasing you!\n");
        bear.position.y++;
        place_bear_behind_player();
    }
    if(turn.current_turn - turn.bear_started == 6 && turn.bear_event)
    {
        //bear´s turn 6
        printf("\nROOAAARRRRR!!!!!!1111 Run away!!\n");
        bear.position.y++;
        place_bear_behind_player();
    }
    if(turn.current_turn - turn.bear_started == 7 && turn.bear_event)
    {
        //bear´s turn 8
        printf("\nROOAAARRRRR!!!!!!1111 The bear is STILL chasing you!\n");
        bear.position.y++;
        place_bear_behind_player();
    }
    if(turn.current_turn - turn.bear_started == 8 && turn.bear_event)
    {
        //bear´s turn 8
        printf("\nROOAAARRRRR!!!!!!1111 Hurry up!\n");
        bear.position.y++;
        place_bear_behind_player();
    }
    if(turn.current_turn - turn.bear_started == 9 && turn.bear_event)
    {
        //bear´s turn 9
        printf("\nROOAAARRRRR!!!!!!1111 Fast! Fast! Fast!\n");                //printf("%s\n", field[32][7].ambience);
        bear.position.y++;
        place_bear_behind_player();
    }
    if(turn.current_turn - turn.bear_started == 10 && turn.bear_event)
    {
        //bear´s turn 10
        printf("\nROOAAARRRRR!!!!!!1111\n");
        bear.position.y++;
        place_bear_behind_player();
    }
    if(turn.current_turn - turn.bear_started == 11 && turn.bear_event)
    {
        //bear´s turn 11
        printf("\nROOAAARRRRR!!!!!!1121 lol?\n");
        bear.position.y++;
        place_bear_behind_player();
    }
    if(turn.current_turn - turn.bear_started == 12 && turn.bear_event)
    {
        //bear´s turn 12
        printf("\nOH MY GOD! You have knocked down the Bear!!!\n");
        bear.position.y++;
        place_bear_behind_player();
        turn.bear_knocked_down = true;
    }
    
    //evaluate positioning
    if(x == 6 && y == 5 && quest1_solved())
    {
        //exit of player´s house
        player.position.x = 1;
        player.position.y = 12;
    }
    
    //supermarket
    if(x == 3 && y == 15 && !cp.supermarket)
    {
        
        cp.supermarket = true;
        
        if(cp.supermarket) cp_counter++;
        
        cp_event(cp_counter);
    }
    
    //townhall
    if(x == 1 && y == 18 && !cp.townhall)
    {
        
        cp.townhall = true;
        
        if(cp.townhall) cp_counter++;
        
        cp_event(cp_counter);
    }
    
    //church
    if(x == 7 && y == 23 && !cp.church)
    {
        
        cp.church = true;
        
        if(cp.church) cp_counter++;
        
        cp_event(cp_counter);
    }
    
    //school
    if(x == 2 && y == 21 && !cp.school)
    {
        
        cp.school = true;
        
        if(cp.school) cp_counter++;
        
        cp_event(cp_counter);
    }
    
    //trainstation
    if(x == 7 && y == 16 && !cp.trainstation)
    {
        
        cp.trainstation = true;
        
        if(cp.trainstation) cp_counter++;
        
        cp_event(cp_counter);
    }
    
    if(x == 7 && y == 33)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\tAs  you´re moving  towards the barrier  it opens.\n");
        printf("\t\t\tYou´re entering the stadium and begin to wonder\n");
        printf("\t\t\thow it possibly could´ve worked. You know there´s\n");
        printf("\t\t\tno electricity or phone connection at all. As you\n");
        printf("\t\t\tmove forward you´re looking into peoples faces. \n");
        printf("\t\t\tYou can´t believe that  there are actually still\n");
        printf("\t\t\tpeople alive. In the astonished crowd you can hear\n");
        printf("\t\t\tsomeone screaming. You recognize that voice. Suddenly\n");
        printf("\t\t\tyou can see your  child crying and  running  in your \n");
        printf("\t\t\tdirection.  You´ve  managed  to  find  your  child.\n");
        printf("\n\n\n\n\n\n\t\t\t\t < press Enter to close the game >\n");
        getchar();
        getchar();
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        return 0;
    }
    if(x == 2 && y == 13 && wolf_event1 == false && wolf_event1_counter == 0)
    {
        l_append(field[13][2].items, create_item("Wolf"));
        wolf_event1 = true;
        wolf_event1_counter = 1;
	printf("\nSuddenly a wolf appears and attacks you!");
    }
    if(x == 2 && y == 25 && wolf_event2 == false && wolf_event2_counter == 0)
    {
        l_append(field[25][2].items, create_item("Wolf"));
        wolf_event2 = true;
        wolf_event2_counter = 1;
	printf("\nSuddenly a wolf appears and attacks you!");
    }
    if(x == 9 && y == 13 && dog_event == false && dog_event_counter == 0)
    {
        l_append(field[13][9].items, create_item("Dog"));
        dog_event = true;
        dog_event_counter = 1;
	printf("\nSuddenly a dog appears and attacks you!");
    }
    
    return 1;
}

bool quest1_solved(void)
{
    
    if(p_has_item("key") && lv1.picture && lv1.grave)
    {
        return true;
    }
    else
    {
        return false;
    }
}
