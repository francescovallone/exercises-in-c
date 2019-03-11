#include <stdio.h>
#define SIZE 15

// function prototypes
void printHeader(void);
size_t binarySearch(const int b[], int searchKey, size_t low, size_t high);
void printRow(const int b[], size_t low, size_t mid, size_t high);

// function main begins program execution
int main(void){
   	int a[SIZE]; // create array a

   	// create data
   	for (size_t i = 0; i < SIZE; ++i) {
    	a[i] = 2 * i;
   	} 

   	printf("%s", "Enter a number between 0 and 28: ");
   	int key; // value to locate in array a
   	scanf("%d", &key);

   	printHeader();

   	// search for key in array a
   	size_t result = binarySearch(a, key, 0, SIZE - 1);

   	// display results
   	if (result != -1) {
      	printf("\n%d found at index %lu\n", key, result);
   	} 
   	else {
    	printf("\n%d not found\n", key);
   	} 
}

void printRow(const int b[], size_t low, size_t mid, size_t high)
{
   // loop through entire array
   for (size_t i = 0; i < SIZE; ++i) {

      // display spaces if outside current subarray range
      if (i < low || i > high) {
         printf("%s", "    ");
      }  
      else if (i == mid) { // display middle element
         printf("%3d*", b[i]); // mark middle value
      } 
      else { // display other elements in subarray
         printf("%3d ", b[i]);
      } 
   } 

   puts(""); // start new line of output
} 

void printHeader(void)
{
   puts("\nSubscripts:");

   // output column head
   for (unsigned int i = 0; i < SIZE; ++i) {
      printf("%3u ", i);
   } 

   puts(""); // start new line of output

   // output line of - characters
   for (unsigned int i = 1; i <= 4 * SIZE; ++i) {
      printf("%s", "-");
   } 

   puts(""); // start new line of output
}

size_t binarySearch(const int b[], int searchKey, size_t low, size_t high){
	size_t middle = (low+high)/2;
	printRow(b, low, middle, high);
	if(low > high){
		return -1;
	}else if(b[middle] == searchKey){
		return middle;
	}else if(b[middle] > searchKey){
		return binarySearch(b, searchKey, low, middle-1);
	}else if(b[middle] < searchKey){
		return binarySearch(b, searchKey, middle+1, high);
	}
}