#include <stdio.h>
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
				
				
				
				//Calculating winning percentage for each team
				
					//Adding up number of games played
				/*for(i=0;i<6;i++){
					games_played[i]=team_win[i]+team_tied[i]+team_loss[i];
				}*/
				
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
				
				//Outputs probability
				printf("Winning prediction for two teams:\n");
				int probability1,probability2;
				printf("Input the first team number: ");
				scanf("%i",&probability1);
				printf("Input the second team number: ");
				scanf("%i",&probability2);
				if(win_percentage[probability1]<win_percentage[probability2])
					printf("Winning prediction is Team %i",probability2);
					
				else if(win_percentage[probability2]<win_percentage[probability1])
					printf("Winning prediction is Team %i",probability1);
					
				else
					printf("Winning prediction outcome is even between both teams");
				
				//Orders the Point list from greatest to least
				
				//Works half way!! Can only get the scores to print in descending order
				
				/*printf("\n----------------------------------------\n\nPoints Table:\n\n");
                
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
			        }
			    }
			    
			    for (i = 0; i < 6; ++i)
			    {		    	
			        printf("%i\n",points[i]);
			    }*/
			    
					 
		}
      getch();      
      
}
