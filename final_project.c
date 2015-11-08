#include <stdio.h>
main()
{
      int weeks,i,c,j,w=0,g=0,t1,t2,num1,num2,team_index1,team_index2;
      printf("How many weeks total? (up to 10)  ");
      scanf("%i", &weeks);
      /*int *team0 = malloc(sizeof(int) * weeks);
      int *team1 = malloc(sizeof(int) * weeks);
      int *team2 = malloc(sizeof(int) * weeks);
      int *team3 = malloc(sizeof(int) * weeks);
      int *team4 = malloc(sizeof(int) * weeks);
      int *team5 = malloc(sizeof(int) * weeks);*/
      int team0[] = {0,0,0};
      int team1[] = {0,0,0};
      int team2[] = {0,0,0};  //Experimental Programming -- need to see if I can change array index data
      int team3[] = {0,0,0};		//each array = {win,tied,loss} -- each win,tie,or loss will add 1 to that array index
      int team4[] = {0,0,0};
      int team5[] = {0,0,0};
      int teams[] = {team1,team2,team3,team4,team5,team6}; //if I have an array of arrays (if possible?) how do I access the
      													   // inside array's index
      
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
                     	printf("---Week %i Game %i---", w, g);
                     	printf("Enter the first team's number: ");
                     	scanf("%i",&num1);
                     	printf("Enter the second team's number: ");
                     	scanf("%i",&num2);
                     	if(num1==0)
                     		team_index=team0
                     	
                     	printf("Enter team %i's score",num1);
                     	for(c=0;c<6;c++){
                     	
                     	scanf("%i",&teams[team_index1]);
                     	}
                     	for(c=0;c<6;c++){
                     	printf("Enter team %i's score",num2);
                     	team_index2 = num2 - team_pointer;
                     	scanf("%i",&teams[team_index2]);
                     	}
					 }
                     
                     
                     scanf(" %i"," %i"," %i"," %i", t1, t2 );
               }
      
    
      }
      
    
      
      
      
      getch();      
      
}
