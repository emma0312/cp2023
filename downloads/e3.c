#include <stdio.h>
void main()
{
char c;
printf( "Input a char:" );
scanf( "%c", &c );
switch( c )
{
case 'a':
printf(" you pressed a ");
break;
case 'b':
printf(" you pressed b ");
break;
case 'c':
printf(" you pressed c ");
break;
default:
printf(" not a, b, c ");
break;
}
}