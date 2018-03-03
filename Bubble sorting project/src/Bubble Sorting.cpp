/* Class: CMSC140 CRN #22669
* Instructor: Madhvi Shah
* Student Name: Josue Ponce
* Project #7
* Description: Program generates 200 random integers between 1 to 200. The program then sorts these integers for the user.
 The user enters a number and the program will determine where the number is located within the sorted array by executing a binary and sequential search.
* Due Date: 12/15/2016
* I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here: Josue Ponce
*/
#include<iostream>
#include<fstream>	// open read and write
#include<cstdlib> // rand and srand
#include<iomanip> 
#include<ctime>  // For time function.
#include<string>
using namespace std;

void sortArray(int list[], int size);							// Sort numbers function.
void showArray(const int list[], int size);						// Display numbers function.
int binarySearch(const int list[], int elements, int value);    // Binary Search Function.
int searchList(const int list[], int elements, int value);		// Sequential search function.
int main() {

// Declaring variables.
	const int  MAX_VALUE = 200;			// Constant value of 200 for arrays.
	int value, hold = 0, index, meow;  // To hold numbers and functions.
	int neko[MAX_VALUE];					
	int num[MAX_VALUE];
	ofstream outFile;	// Create output Files.
	

	srand(time(0)); // Generates random numbers.

	for (int i = 0; i < MAX_VALUE; i++) {	
		value = rand() % MAX_VALUE + 1;		// Generates random numbers ranging from 1- 200. 
		num[i] = value;						// variable will hold 200 random numbers for function.
	}
	cout << "The sorted values are:\n";		// Displays random 200 numbers.
	sortArray(num, MAX_VALUE);				// Calls in function to bubble sort results.
	showArray(num, MAX_VALUE);				// Displays sorted results to the user.
	outFile.open("BinarySearchResults.txt"); // Creates an output in order to save binary search results.
	
	cout << "Please enter a random integer between 1 and 200." << endl;	// Displays message to user to input a number ranging from 1-200.
	cin >> hold;														// obtain user input.
	index = binarySearch(num, MAX_VALUE, hold);				// variable holds the binary search results.
	
	if (index == -1) {										// if results are equal to -1 the following sets of code will execute.
		cout << "Key doesn't exist in array. Executing a Sequential Search\n: " << endl;	// tells user key doesn't exist in the array.
		meow = searchList(num, hold, MAX_VALUE);								// Variable with hold sequencial search results.
		if (index == -1) {													// If results are equal to -1 the following lines of code will execute.
			cout << "Key does not exist in the array." << endl;				// Tells user the key doesn't exist in the array.
			return 0;														// Terminates program.
		}
	}
	else										// if the desired results are obtained the following lines will execute.
		cout << "Key: " << hold << " detected at index: " << index << " by Binary search." << endl; // Displays binary search results to the user.
		outFile << "Key: " << hold << " detected at index: " << index << " by Binary search." << endl; // Saves binary search results to the text file.
		outFile.close();													// Binary search text file will close.

		meow = searchList(num, MAX_VALUE, hold);	// Variable with hold sequencial search results.
		outFile.open("SequentialSearchResults.txt");	// Opens a new text file to hold sequential search results.
		cout << "Next, Find out the key through a Sequential Search: " << endl;	    // Display message to user telling them 
	    cout << "Key detected at position: " << meow << " by linear search." << endl;	// Displays sequential search results to user.
		outFile << "Key detected at position: " << meow << " by linear search." << endl; // Saves sequential search results to a text file.
		outFile.close();																// Closes sequential search file.
		
	



	
	return 0;
}

void sortArray(int list[], int size) // Function will perform an ascending order bubble sort.
{
	bool swap;
	int temp;           //Holding variable.
	
	do
	{
		swap = false;                       // Indicates that a swap has occured. 
		for (int count = 0; count < (size - 1); count++)
		{
			if (list[count] > list[count + 1])
			{
				temp = list[count];           // Swapping elements.
				list[count] = list[count + 1];
				list[count + 1] = temp;
				swap = true;				// Indicates that a swap has occured. 
			}
		}
	} while (swap);
}

void showArray(const int list[], int size)
{
	ofstream outputFile;				// Creating an output file.
	outputFile.open("sorted.txt");		// Opens output File.
	for (int count = 0; count < size; count++) {
		outputFile << list[count] << " " << endl;	// Sends sorted results to the output file.
		cout << list[count] << " " << endl;			// Displays sorted results to the user.
	}
	outputFile.close();								// Closes outputFile.
}

int binarySearch(const int list[], int elements, int value)
{
	int first = 0,				// First element.
		last = elements - 1,	// Last number in element.
		middle,					// Mid point search.
		position = -1;			// Position of the value.
	bool found = false;			// flag.

	
	while (!found && first <= last)
	{
		middle = (first + last) / 2;	
		if (list[middle] == value)		
		{
			found = true;				// Value found at midpoint.
			position = middle;			// Calculate mid point.
		}
		else if (list[middle] > value) // if value is lower half.
			last = middle - 1;  
		
		else
			first = middle + 1;		// if value is upper half.
	}	 
	return position;
}

int searchList(const int list[], int elements, int value)
{
	int index = 0;       // Used for subcript in order to search the array.
	int position = -1;   // To record the position of the value.
	bool found = false;  // Flag will determine if the number was found.

	while (index < elements && !found)
	{
		if (list[index] == value)  // If the number is found.
		{
			found = true;           // Flag
			position = index;		//Record the number's position or -1;
			
		}
		index++;      // Goes to the next element.  
									
	}
	return position;              // Returns the value's position or -1.
}