#include <stdio.h>
#include <stdbool.h>
float getPrediction(int total_points[],int games_played[]);
int getOrder(int newOrder[]);
main()
{
      int weeks,i,c,j,w=0,g=0,t1,t2,num1,num2,team_index1,team_index2,score1,score2,week_counter,a,hold; 
      int games_played[]={0,0,0,0,0,0};
      int total_points[]={0,0,0,0,0,0};
      int points_against[]={0,0,0,0,0,0};
	  int team_index[]={0,1,2,3,4,5};
	  int team_order[]={0,0,0,0,0,0};
	  double win_percentage[]={0,0,0,0,0,0};
      printf("How many weeks total? (up to 10)  ");
      scanf("%i", &weeks);
      int team_number[]={0,0,0,0,0,0};
      int points_ordered[]={0,0,0,0,0,0};
      int points[]={0,0,0,0,0,0};											   
      int team_win[]={0,0,0,0,0,0};
	  int team_tied[]={0,0,0,0,0,0};
	  int team_loss[]={0,0,0,0,0,0};													  
	  // Note: That if is equal to else then pi is equal to life
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
                     	printf("Enter the two teams and their scores: ");
                     	scanf("%i%i%i%i",&num1,&num2,&score1,&score2);
                     	games_played[num1]+=1;
                     	games_played[num2]+=1;
                     	total_points[num1]+=score1;
                     	total_points[num2]+=score2;
                     	points_against[num1]+=score2;
                     	points_against[num2]+=score1;
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
               for(i=0;i<6;i++){
            		team_index[i]=points[i];
			   }
               //Points
                for(j=0;j<6;j++){
            		points[j]= (team_win[j]*2) + (team_tied[j]*1);
			    }
                printf("\n----------------------------------------\n\nLeague Standings after %i weeks\n\n",weeks);
				printf("\t         W  T  L\n");
				for(j=0;j<6;j++){
					printf("\tTeam %i:  %i  %i  %i\n",j,team_win[j],team_tied[j],team_loss[j]);
				}
				for(i=0;i<6;i++){
					win_percentage[i]=(float)team_win[i]/(float)games_played[i];
					printf("\nTeam %i winning percentage: %.2f\n",i,win_percentage[i]);
				}
				printf("\n----------------------------------------\nTotal Points For:\n");
				//'Modify to compute and print for each team the total points scored for and against'
				for(i=0;i<6;i++){
					printf("Team %i: %i\n",i,total_points[i]);
				}
				printf("\n\nTotal Points Against\n");
				for(i=0;i<6;i++){
					printf("Team %i: %i\n",i,points_against[i]);
				}
				printf("\n\n----------------------------------------\n");
				int newOrder[6];
				for(i=0;i<6;i++){
                    newOrder[i] = points[i];
                    }
				int order = getOrder(newOrder);
				//Next block of code calls a test for a new prediction algorithm function written below
				int prediction = getPrediction(total_points,games_played);	 
		}
        getch();    
}
//Probability algorithm sets the home team with an at-home advatage of 10%
//Algorithm takes the total points scored for and compares the two teams by it
//Study represented in an article by SBNation.com showed that the NBA had an average at-home advantage of 10%
//Asks user to repeat prediction algorithm
float getPrediction(int total_points[],int games_played[])
{
	int home,away;
    float home_advantage;
	char answer;
    _Bool again = true;
	while(again = true)
	{
		printf("\n\nInput the home team's number: ");
		scanf("%i",&home);
		printf("Input the away team's number: ");
		scanf("%i",&away);
		float home_avg = (float)total_points[home]/(float)games_played[home];
		float away_avg = (float)total_points[away]/(float)games_played[away];
		home_avg = home_avg*1.1;
		if(home_avg<away_avg)
			printf("Winning prediction is Team %i",away);
		else if(away_avg<home_avg)
		{
			printf("Winning prediction is Team %i",home);
		}
		else
			printf("Winning prediction outcome is even between both teams");
			printf("\n\nWould you like to run the prediction algorithm again? (y for yes, n for no) ");
		    scanf(" %c", &answer);
		    if(answer == 'y')
		              again = true;
	        else if(answer == 'n'){
				again = false;
	        	break;
	        }
	}
}
//This method orders the teams' scores by descending order
int getOrder(int points[])
{
    int i,j,a,b;
    int teamNumber[]={0,1,2,3,4,5};
    printf("Points Table:\n");
     for (i = 0; i < 6; ++i)
	    {
	        for (j = i + 1; j < 6; ++j)
	        { 	
	            if (points[i] < points[j])
	            {
                    b = teamNumber[i];
                    teamNumber[i]= teamNumber[j];
                    teamNumber[j]=b;
                    a = points[i];
	                points[i] = points[j];
	                points[j] = a;
	            }
	        }
	    }
	    for (i = 0; i < 6; ++i)
	    {		    	
	        printf("Team %i: %i\n",teamNumber[i],points[i]);
	    }	    
}
