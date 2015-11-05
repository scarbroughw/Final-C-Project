#include <stdio.h>
main()
{
      int weeks,i,w=0,g=0,t1,t2;
      printf("How many weeks total? (up to 10)  ");
      scanf("%i", &weeks);
      int *team1 = malloc(sizeof(int) * weeks);
      int *team2 = malloc(sizeof(int) * weeks);
      int *team3 = malloc(sizeof(int) * weeks);
      int *team4 = malloc(sizeof(int) * weeks);
      int *team5 = malloc(sizeof(int) * weeks);
      int *team6 = malloc(sizeof(int) * weeks);
      
      if(weeks > 10)
               printf("Error: Only up to 10 weeks can be entered.");
               
      else
      {
               for(i=0;i<weeks;i++)
               {
                     ++g;
                     ++w;              
                     if(g>=4){
                             w=1;
                             g=1;
                     }
                     printf("For week %i, game %i, enter the two teams and the score: ", w, g);
                     
                     scanf(" %i"," %i"," %i"," %i", t1, t2 );
               }
      
          
      }
      
      
      
      
      
      getch();      
      
}
