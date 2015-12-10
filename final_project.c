#include <stdio.h>
#include <stdbool.h>
int getPrediction(int win[], int tied[], int loss[],double win_percentage[]);
int getOrder(int newOrder[],int team_order[]);
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
                     	printf("\n---Week %i Game %i---\n", w, week_counter);
                     	printf("Enter the first team's number: ");
                     	scanf("%i",&num1);
                     	printf("Enter the second team's number: ");
                     	scanf("%i",&num2);
                     	printf("Enter team %i's score: ",num1);
                     	scanf("%i",&score1);
                     	printf("Enter team %i's score: ",num2);
                     	scanf("%i",&score2);
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
				int order = getOrder(newOrder,team_order);
				
				//Next block of code calls a test for a new prediction algorithm function written below
				int prediction = getPrediction(team_win, team_tied, team_loss,win_percentage);	 
		}
            
}

//Probability algorithm sets the home team with an at-home advatage of 10%
//Study represented in an article by SBNation.com showed that the NBA had an average at-home advantage of 10%
//Asks user to repeat prediction algorithm
int getPrediction(int win[], int tie[], int loss[], double win_percentage[])
{
	int home,away,home_advantage;
	char answer;
    _Bool again = true;
	while(again = true)
	{
		printf("\n\nInput the home team's number: ");
		scanf("%i",&home);
		printf("Input the away team's number: ");
		scanf("%i",&away);
		home_advantage = home *1.1;
		if(win_percentage[home]<win_percentage[away])
			printf("Winning prediction is Team %i",away);
		
			
		else if(win_percentage[away]<win_percentage[home])
		{
			printf("Winning prediction is Team %i",home_advantage);
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
int getOrder(int points[], int team_order[])
{
    int i,j,a,b=0;
    
    int teamNumber[6];
    
     for (i = 0; i < 6; ++i)
	    {
	        for (j = i + 1; j < 6; ++j)
	        { 
	        	
	            if (points[i] < points[j])
	            {
                    a = points[i];
	                points[i] = points[j];
	                points[j] = a;
	                
	                
	            }
	            else{
	            	team_order[j]=i;
	            }
	            teamNumber[b] = i;
	            b++;
	        }
	    }
	    for (i = 0; i < 6; ++i)
	    {		    	
	        printf("Team %i: %i\n",teamNumber[i],points[i]);
	    }	    
}

