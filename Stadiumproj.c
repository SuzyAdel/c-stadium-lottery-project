#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<string.h>
#include<conio.h>

struct fan //structure
{
    char Name;
    int T,ID;
};

void make_lower(char *array) //lower case array no pointer needed to edit in it  
{   
    int i = 0;
    while ( *(array+i) != '\0')
    {
       array[i] = tolower(array[i]);
       i++;
    }
}
void ticket()
{
    int m,i;
    char *match[3];
    for(int k=0;k<3;k++)match[k]=(char*)malloc(3*sizeof(char));
if(match[0] !=NULL && match[1]!=NULL && match[2]!=NULL)
{
    printf("enter 3 top choices\n ");
    for(m=0;m<3;m++)
    {
    printf("\t\tenter choice %d",m+1);
    gets(match[m]);
    }
    int lower =0, upper =2, count = 1;//0 to 2 like 2d array index
    srand(time(0));
    for (int i = 0; i < count; i++)
    {
    int num = (rand() % (upper - lower + 1)) + lower;
    printf("you have won the ticket of this match from your choices %d\t",num+1);
    puts(match[num]);
    }
}
}

void flag()
{
  int i;
  char F[50];
  printf("Enter the country's flag:");
  scanf("%[^\n]s", F);
  make_lower(F); // unify the input like array to avoid run time error
  // file to search for the flag in the list
  FILE *f;
  char x[100][32];
  f = fopen("Flags.txt", "r");
  if (f != NULL)
  {
    for (i = 0; i < 32; i++){
      fscanf(f, "%s", x[i]);
    }
    int found = 0;
    for (i = 0; i < 32; i++)
    {
      if (strcmp(F, x[i]) == 0) {
        printf("Mabrouk You have won %s's flag", F);
        found = 1;
      }
    }
    if (found == 0)
      printf("This country is not available or you have entered incorrect spelling");
  }
  else
    printf("Can not open file");  
    }

void main() 
{
  char option[50];
  int N;
  struct fan fanpit[10];
  printf("Welcome To 2022 World Cup lottery Program !\n \n each spectator will win a marvelous Prize\n");
  while(1)
  {
    printf("Pick an Option(start,exit):");
    gets(option);
    make_lower(option);//to unify input
    if(strcmp(option,"exit")==0)break;

    else if (strcmp(option,"start")==0)
    {
      int N,S;
      printf("enter the number of spectators(max=10);");
      scanf("%d",&N);
      while(N<1 || N>10 )//to avoid negtive or max limit
      {
        printf("\nRe-enter number of spectators:\n");
        scanf("%d",&N);
      }

     for(int S=0;S<N;S++)
      {
        printf("\nEnter NAME os spectator %d: ", S+1);
        scanf("%s", fanpit[S].Name);

        printf("Enter TIICKET NUMBER for spectator %d:" ,S+1);
        scanf("%d",&fanpit[S].T);

        printf("Enter ID for spectator  %d:",S+1);
        scanf("%d",&fanpit[S].ID);
      }
    //now we took the number of spectators and their data we will start giving them prizes
    
    for(int x=0;x<N;x++)
    {
      printf("\nThis prize is for spectator number %d !\n",x+1);
      int lower = 1, upper = 5, count = 1;

      srand(time(0));

      printf("\nThe random prize numbers is: \n");
      for (int i = 0; i < count; i++) 
      {
          int num = (rand() % (upper - lower + 1)) + lower;
          printf("%d ", num);
          if (num==1)
          {
          printf("\nCongrats you won  A   GOLDEN  PRIZE\n You won A vip ticket for one of the choices you will enter \n ");
          ticket();
          }
          else if (num==2)
          {
          char player[50];
          printf("\nCongrats you won  A  SILVER  PRIZE\n You won a original signed Shirt\n Enter your favorie player's Name: ");  
          scanf("%s", player);
          printf("we will contact spectator %d to get %s's shirt",x+1,player);
          }
          else if (num==3)
          {
          printf("\nCongrats you won  A  BRONZE  PRIZE\n\n You won a signed flag by the captian ");   
          flag(); 
          }
          else if (num==4)printf("\nCongrats you won  A  YUMMY  PRIZE\n You won unlimited free popcorn for 2 matches ");   
      
          else if(num==5)printf("\nCongrats you won  A  NA7S  PRIZE\n You won a zomra");    
      
      }

    }
  }
  //else continue;
 } 
    printf("GOODBYE YA MOSHGE3"); 
getch();
}
//we included Structure,strings,files,search in the linked file,2d array & daynamic allocation.
//SUZY ADEL 211004476 