#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
char WhoisGettingtheGift [20];
char Whichone [20];
char Whattype [20];
char Answer [20];
char Answer1 [20];
printf("Who is getting the gift? ");
scanf("%s", WhoisGettingtheGift);
if (strcmp(WhoisGettingtheGift, "family")==0)
{
  printf("Which one? ");
  scanf("%s", Whichone);
  if (strcmp(Whichone, "parent")==0)
  {
    printf("Mom? ");
    scanf("%s", Answer);
    if(strcmp(Answer, "yes")==0)
    {
      printf("Still does your wash? ");
      scanf("%s", Answer);
      if (strcmp(Answer, "yes")==0)
      {
        printf("Get something nice (chocolate or flowers)\n");
      }
      else if (strcmp(Answer, "no")==0)
      {
        printf("A funny Valentine's Card\n");
      }
    }
    else if (strcmp(Answer, "no")==0)
    {
      printf("Calls you regularly? ");
      scanf("%s", Answer);
      if(strcmp(Answer, "yes")==0)
      {
        printf("A funny Valentine's Card\n");
      }
      else if(strcmp(Answer, "no")==0)
      {
        printf("Nothing\n");
      }
    }
  }
  if(strcmp(Whichone,"sibling")==0)
  {
    printf("Ever beat you up? ");
    scanf("%s",Answer);
    if(strcmp(Answer, "yes")==0)
    {
      printf("Deserve it? ");
      scanf("%s", Answer);
      if(strcmp(Answer, "yes")==0)
      {
        printf("A funny Valentine's day card\n");
      }
      else if(strcmp(Answer, "no")==0)
      {
        printf("Nothing\n");
      }
    }
    else if(strcmp(Answer, "no")==0)
    {
      printf("A funny Valentine's day card\n");
    }
  }
  if(strcmp(Whichone, "other")==0)
  {
    printf("Young or old? ");
    scanf("%s", Answer);
    if(strcmp(Answer, "young")==0)
    {
      printf("A funny Valentine's day card\n");
    }
    else if(strcmp(Answer, "old")==0)
    {
      printf("You in their will? ");
      scanf("%s", Answer);
      if(strcmp(Answer, "yes")==0)
      {
        printf("A funny Valentine's day card\n");
      }
      else if(strcmp(Answer, "no")==0)
      {
        printf("Nothing\n");
      }
    }
  }

}
else if(strcmp(WhoisGettingtheGift, "friend")==0)
{
  printf("What type? ");
  scanf("%s", Whattype);
  if(strcmp(Whattype, "childhood")==0)
  {
    printf("Still talk to them? ");
    scanf("%s", Answer);
    if(strcmp(Answer, "yes")==0)
    {
      printf("Ever date them? ");
      scanf("%s", Answer1);
      if(strcmp(Answer1, "yes")==0)
      {
        printf("A funny Valentine's day card\n");
      }
      else if(strcmp(Answer1, "no")==0)
      {
        printf("Nothing\n");
      }
    }
    if(strcmp(Answer, "sometimes")==0)
    {
      printf("Good Friend? ");
      scanf("%s", Answer1);
      if (strcmp(Answer1, "yes")==0)
      {
        printf("A funny Valentine's day card\n");
      }
      if(strcmp(Answer1, "no")==0)
      {
        printf("Nothing\n");
      }
    }
    if (strcmp(Answer, "no")==0)
    {
      printf("Nothing\n");
    }
  }
  if (strcmp(Whattype, "college")==0)
  {
    printf("Roommate? ");
    scanf("%s", Answer);
    if (strcmp(Answer, "yes")==0)
    {
      printf("A funny Valentine's day card\n");
    }
    if (strcmp(Answer, "no")==0)
    {
      printf("Dating them? ");
      scanf("%s", Answer);
      if (strcmp(Answer, "no")==0)
      {
        printf("Nothing\n");
      }
      if (strcmp(Answer, "yes")==0)
      {
        printf("Something nice (chocolate or flowers)\n");
      }
    }
  }
}

return 0;
}
