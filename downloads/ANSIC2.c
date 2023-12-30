#include <stdio.h>     // Include the standard input/output header file.

float temp_f;     /* degrees fahrenheit */
float temp_c;     /* degrees centigrade */
char line_text[50];        /* a line of input */

int main() {
printf("Input a temperature (in Centigrade): ");  // Prompt the user to input a temperature in centigrade.
fgets(line_text, sizeof(line_text), stdin);      // Read a line of input from the user and store it in 'line_text'.
sscanf(line_text, "%f", &temp_c);               // Convert the input from 'line_text' to a float and store it in 'temp_c'.

temp_f = ((9.0 / 5.0) * temp_c) + 32.0;         // Convert temperature from centigrade to fahrenheit and store it in 'temp_f'.
printf("%f degrees Fahrenheit.\n", temp_f);    // Print the temperature in fahrenheit.

return(0);   // Return 0 to indicate successful execution of the program.
}