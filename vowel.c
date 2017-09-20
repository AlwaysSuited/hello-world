#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main()
{
 int a=0,e=0,i=0,o=0,u=0;
 char c;
 printf("Enter string:-  ");
 while ((c=getchar())!=EOF)
 {
  if (c=='a'||c=='A')
   a=a+1;
  if (c=='e'||c=='E')
   e=e+1;
  if (c=='i'||c=='I')
   i=i+1;
  if (c=='o'||c=='O')
   o=o+1;
  if (c=='u'||c=='U')
   u=u+1;
 }
 printf("Frequency of vowel 'a' is %d.\n",a);
 printf("Frequency of vowel 'e' is %d.\n",e);
 printf("Frequency of vowel 'i' is %d.\n",i);
 printf("Frequency of vowel 'o' is %d.\n",o);
 printf("Frequency of vowel 'u' is %d.\n",u);
 return 0;
}
