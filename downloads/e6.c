#include <stdio.h>
void main()
{
int i, j;
i = 0; j = 10; /* 迴圈外先設定初值 */
while( i < 6 )
{
printf( "i = %d, ", i );
printf( "j = %d \n", j );
i++;
j++; 
}
}
