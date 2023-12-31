#include <stdio.h>
void main()
{
int i, j;
j = 10; /* 迴圈外先設定初值 */
for ( i = 0; i < 6; i++ )
{
printf( "i = %d, ", i );
printf( "j = %d \n", j );
j++; /* 迴圈後加上變更運算式 */
}
}