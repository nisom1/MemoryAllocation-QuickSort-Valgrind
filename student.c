// Do not remove #ifdef ... #endif before and after each function.
// 
// They are used to test different functions in your program and give
// partial credits, in case your program does not work completely.

#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StudentPrint(Student * stu, int num)
{
  printf("There are %d students\n", num);
  int ind;
  for (ind = 0; ind < num; ind ++)
    {
      printf("ID = %d, First Name = %s, Last Name = %s\n",
	     stu[ind].ID,  stu[ind].firstname, stu[ind].lastname);
    }
}

#ifdef TEST_READ
// return false if anything is wrong 
// return true if reading the file successfully and the data is save in
// the allocated memory
// input: filename, the name of the input file
// output: address of the allocated memory
// output: number of students
bool StudentRead(char * filename, Student * * stu, int * numelem)
{
  // open the file to read
  FILE * fptr = fopen(filename, "r");
   if (fptr == NULL)
    {
      return false; // if fopen fails, return false
    } // do not use fclose since fopen already fails

  // count the number of lines to determine the number of students
  
  char character = fgetc(fptr);
  int numLines;
  while (character != EOF){
    if(character == '\n')
      numLines++;
  }
  
  numelem = &numLines; // not the right dereference-r
  
  // return to the beginning of the file
  // you can use fseek or
  // fclose followed by fopen
  // You need to check whether fseek or fopen fails
  // Do not use rewind because it does not report whether it fails
  fclose(fptr);
  fptr = fopen(filename, "r");

 // allocate memory for the data
  stu = malloc(sizeof(Student) * numelem);
  
  // check whether memory allocation fails
  
 if (stu = NULL)
  return EXIT_FAILURE;

  // read the data from the file and store the data in the allocated memory
  int i;
  for( i = 0; ind < numelem; i++){
   fscanf(filename, "%d %s %s\n", &stu[i].ID, &stu[i].firstname, & stu[i].lastname);

}
  // close the file
  fclose(fptr);

  return true;
}
#endif

#ifdef TEST_WRITE
// return false if anything is wrong 
// return true if writing the file successfully
// input: filename, the name of the output file
// input: address of the student array
// input: number of students

bool StudentWrite(char * filename, Student * stu, int numelem)
{
   // open the file to read
  FILE * fptr = fopen(filename, "r");
   if (fptr == NULL)
    {
      return false; // if fopen fails, return false
    } // do not use fclose since fopen already fails

  // write the students to the output file








}
#endif 

#ifdef TEST_SORTID
void StudentSortbyID(Student * stu, int numelem)
{


}
#endif

#ifdef TEST_SORTFIRSTNAME
void StudentSortbyFirstName(Student * stu, int numelem)
{

}
#endif

#ifdef TEST_SORTLASTNAME
}
void StudentSortbyLastName(Student * stu, int numelem)
{

}
#endif
