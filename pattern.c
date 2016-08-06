#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	FILE *FILE_INPUT, *FILE_OUTPUT;

	void write_to_file ( char *string_to_write ) {
		strcat (string_to_write, "\r\n");
		fputs(string_to_write, FILE_OUTPUT);
	}

	void checkForPattern ( const char *string, const char *pattern ) {

		int found = 0;
		int indices[100];
		const char *temp = string;
		int i;
		char output_string[100];

		while ((temp = strstr(temp, pattern)) != NULL) {
			indices[found++] = (int) ( temp - string );
			temp++;
		}

		if ( found != 0 ) {

			

			strcpy (output_string, "");
			strcat (output_string, "Pattern found at index ");

			for ( i = 0; i < found; i++ ) {

				char temp_index[5];
				
				sprintf(temp_index, "%d", indices[i]);
				
				strcat (output_string, temp_index);
				
				strcat (output_string, ",");
			}

			output_string[ strlen(output_string) - 1 ] = '\0';

			write_to_file(output_string);
		}
		
	}


	int main ( int argc, char* args[] ) {

		FILE_INPUT = fopen(args[1], "r");
		FILE_OUTPUT = fopen(args[2], "w");

		//FILE_INPUT = fopen("int.txt", "r");
		//FILE_OUTPUT = fopen("ou.txt", "w");

		int pos = 0;

		char line[1000];
		char pattern[100];

		while ( ( fgets( line, 1000, FILE_INPUT ) ) != NULL ) {

		line[ strlen(line) - 1 ] = '\0';

			if ( pos == 0 ) {
				strcpy(pattern, line);
			}

			else {
				checkForPattern(line, pattern);
			}

			pos = -1;	
		}

		fclose(FILE_INPUT);
		fclose(FILE_OUTPUT);

		return 0;
	}
