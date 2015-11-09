#include <stdio.h>
main()
{
      int weeks,i,c,j,w=0,g=0,t1,t2,num1,num2,team_index1,team_index2,score1,score2,week_counter;
      printf("How many weeks total? (up to 10)  ");
      scanf("%i", &weeks);
      /*int *team0 = malloc(sizeof(int) * weeks);
      int *team1 = malloc(sizeof(int) * weeks);
      int *team2 = malloc(sizeof(int) * weeks);
      int *team3 = malloc(sizeof(int) * weeks);
      int *team4 = malloc(sizeof(int) * weeks);
      int *team5 = malloc(sizeof(int) * weeks);*/
      
      
      /*int team0[] = {0,0,0};
      int team1[] = {0,0,0};
      int team2[] = {0,0,0};  //Experimental Programming -- need to see if I can change array index data
      int team3[] = {0,0,0};		//each array = {win,tied,loss} -- each win,tie,or loss will add 1 to that array index
      int team4[] = {0,0,0};
      int team5[] = {0,0,0};
      int teams[] = {team1,team2,team3,team4,team5,team6};*/ //if I have an array of arrays (if possible?) how do I access the
      													   // inside array's index
      													   
      int team_win[]={0,0,0,0,0,0};
	  int team_tied[]={0,0,0,0,0,0};
	  int team_loss[]={0,0,0,0,0,0};													   
      
      
      if(weeks > 10)
               printf("Error: Only up to 10 weeks can be entered.");
               
      else
      {
               for(i=0;i<weeks;i++) 	//runs for each week
               {
                     ++g;
                     ++w;              
                     if(g>=4){
                             w=1;
                             g=1;
                     }
                     for(j=0;j<3;j++){				//runs for each game
                     	week_counter= j+1;
                     	printf("\n---Week %i Game %i---\n", w, week_counter);
                     	printf("Enter the first team's number: ");
                     	scanf("%i",&num1);
                     	printf("Enter the second team's number: ");
                     	scanf("%i",&num2);
                     	printf("Enter team %i's score: ",num1);
                     	scanf("%i",&score1);
                     	printf("Enter team %i's score: ",num2);
                     	scanf("%i",&score2);
                     	if(score1<score2){
						 	team_win[num2]+=1;
							team_loss[num1]+=1;
						}
						else if(score2<score1){
							team_win[num1]+=1;
							team_loss[num2]+=1;                     	
                     	}
                     	else if(score1==score2){
                     		team_tied[num1]+=1;
                     		team_tied[num2]+=1;
						 }	
					 }    
					 
					
               }
               printf("\n----------------------------------------\n\nLeague Standings after %i weeks\n\n",weeks);
					 printf("\t         W  T  L\n");
					 for(j=0;j<6;j++){
					 	printf("\tTeam %i:  %i  %i  %i\n",j,team_win[j],team_tied[j],team_loss[j]);
					 }
		}
      getch();      
      
}
