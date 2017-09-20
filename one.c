//THIS PROGRAM WAS CREATED BY DEVIN BROWN
#include <stdio.h>
#include <stdlib.h>
typedef struct letter {
 char ch;
 struct letter *next;
} Letter;
int main(void) {
 Letter a, b, c, d, e, f, g, h, i;
 a.ch = 'D'; a.next = &b;
 b.ch = 'O'; b.next = &c;
 c.ch = 'R'; c.next = &d;
 d.ch = 'M'; d.next = &e;
 e.ch = 'I'; e.next = &f;
 f.ch = 'T'; f.next = &g;
 g.ch = 'O'; g.next = &h;
 h.ch = 'R'; h.next = &i;
 i.ch = 'Y'; i.next = NULL;
 Letter *ptr = &a;
 while ( ptr != NULL ) {
 printf("%c ", ptr->ch);
 ptr = ptr->next;
 }
 printf("\n");


 //AEHFICBGD
 // rearrange pointers so that it spells "DIRTYROOM"
 ptr = &a;
 a.next = &e;
 e.next = &h;
 h.next = &f;
 f.next = &i;
 i.next = &c;
 c.next = &b;
 b.next = &g;
 g.next = &d;
 d.next = NULL;

 while ( ptr != NULL ) {
 printf("%c ", ptr->ch);
 ptr = ptr->next;
 }
 printf("\n");
 return 0;
}
