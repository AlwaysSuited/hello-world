//THIS PROGRAM WAS CREATED BY DEVIN BROWN
#include <stdio.h>
#include <stdlib.h>
typedef struct letter {
 char ch;
 struct letter *next;
} Letter;
int main(void) {
 Letter *words[13];
int i;
 for(i=0; i<13; i++)
	words[i] = (Letter *)malloc(sizeof(Letter));


 words[0]->ch = 'E'; words[0]->next = words[1];
 words[1]->ch = 'L'; words[1]->next = words[2];
 words[2]->ch = 'E'; words[2]->next = words[3];
 words[3]->ch= 'V'; words[3]->next = words[4];
 words[4]->ch = 'E'; words[4]->next = words[5];
 words[5]->ch = 'N'; words[5]->next = words[6];
 words[6]->ch = 'P'; words[6]->next = words[7];
 words[7]->ch = 'L'; words[7]->next = words[8];
 words[8]->ch = 'U'; words[8]->next = words[9];
 words[9]->ch = 'S'; words[9]->next = words[10];
 words[10]->ch = 'T'; words[10]->next = words[11];
 words[11]->ch = 'W'; words[11]->next = words[12];
 words[12]->ch = 'O'; words[12]->next = NULL;
 Letter *ptr = words[0];
 while ( ptr != NULL ) {
 printf("%c ", ptr->ch);
 ptr = ptr->next;
 }
 printf("\n");


 //AEHFICBGD
 // rearrange pointers so that it spells "TWELVEPLUSONE"
 ptr = words[10];
 words[10]->next = words[11];
 words[11]->next = words[0];
 words[0]->next = words[1];
 words[1]->next = words[3];
 words[3]->next = words[2];
 words[2]->next = words[6];
 words[6]->next = words[7];
 words[7]->next = words[8];
 words[8]->next = words[9];
 words[9]->next = words[12];
 words[12]->next = words[5];
 words[5]->next = words[4];
 words[4]->next = NULL;

 while ( ptr != NULL ) {
 printf("%c ", ptr->ch);
 ptr = ptr->next;
 }
 printf("\n");
 return 0;
}
