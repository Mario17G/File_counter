//Program that counts the number of words and letters of a file 


#include <stdio.h>

//we define the function with a empty return
void counter(FILE *ARCH);

int main(){

	printf("\t\t-----------------------------------\n");
	printf("\t\tWORD AND LETTERS COUNTER OF A FILE\n");
	printf("\t\t-----------------------------------\n\n");

	//Define a variable of type file
	FILE *ARCHIVO;

	//We open the file with the function fopen and if the file doesn't exist, we print a message that we couldn't open the file and close the program
	ARCHIVO = fopen("your_file.txt","r");
	if(ARCHIVO == NULL){
		printf("Could not open the file!!");

		return 1;
	}

	//We call the function
	counter(ARCHIVO);

	//Finally we close the file
	fclose(ARCHIVO);

	return 0;
}


//How the function works
void counter(FILE *ARCH){
	//We define a variable that reads character by character
	char c;
	//Define a variable that indicates us if it is on a word or not
	int band = 0;
	//Define a variable that counts the number of letters
	int letras = 0;
	//Define a variable that counts the number of words
	int palabras = 0;

	//While the variable c isn't in the end of the file whats inside the while it works
	while((c = fgetc(ARCH)) != EOF){

		/*If c is equal to a number from 65 up to 90 that indicates us a capital letter or c is equal  to a number from 97 up to 122 that indicates us is 
		lower case we increase the variable letras*/
		if( (c>=65 && c<=90 ) || (c>=97 && c<=122))
			letras++;

		/*If c is equal to 32 that means is a space bar or c is a line break it means that band isn't a word
		And the codition is false and if the band is equal to 0 it means that band is a word and we change 
		the value of band to 1 and increase the variable palabras*/

		if(c == 32 || c == '\n'){
			band = 0;
		}else if(band == 0){
			band = 1;
			palabras++;
		}

	}

	//Finally we print the results of number of words and letters

	printf("Number of words: %d",palabras);
	printf("\nNmber of letters: %d",letras);

}