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
      return 0; // if fopen fails, return false
    } // do not use fclose since fopen already fails

  // count the number of lines to determine the number of students
  int ch;
  int numLines = 1; // start at 1 because the last line doesn't have a '\n' so we need to account for that 
  while ((ch = fgetc(fptr)) != EOF){
      if (ch == '\n'){
        numLines++;
    }
  }
  *numelem = numLines;
  
  // return to the beginning of the file
  // you can use fseek or
  // fclose followed by fopen
  // You need to check whether fseek or fopen fails
  // Do not use rewind because it does not report whether it fails
  fclose(fptr);
  FILE * newfptr = fopen(filename, "r");

 // allocate memory for the data
  (*stu) = malloc(sizeof(Student) * (*numelem));
  
  // check whether memory allocation fails
  
 if ( (*stu) == NULL)
  return EXIT_FAILURE;

  // read the data from the file and store the data in the allocated memory
  int i;
  for( i = 0; i < (*numelem); i++){
   fscanf(newfptr, "%d %s %s\n", &stu[i]->ID, stu[i]->firstname, stu[i]->lastname);
}
  // close the file
  fclose(newfptr);

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
   // open the file to write
  FILE * outptr = fopen(filename, "w");
   if (outptr == NULL)
    {
      return false; // if fopen fails, return false
    } // do not use fclose since fopen already fails

  // write the students to the output file  
  int i = 0;
  for( i = 0; i < numelem; i++){
   fprintf(outptr, "%d %s %s\n", stu[i].ID, stu[i].firstname, stu[i].lastname);
   }
  fclose(outptr);
  return true;
}
#endif 

#ifdef TEST_SORTID
int comparefuncint(const void * arg1, const void * arg2) 
{
  Student * ptr1 = (Student *) arg1; 
  Student * ptr2 = (Student *) arg2;  
  
  if( (ptr1->ID) < (ptr2->ID) )
	return -1;
  else if( (ptr1->ID) == (ptr2->ID) )
	return 0;
  else
	return 1;
} 
 
 void StudentSortbyID(Student * stu, int numelem)
{
  qsort(stu, numelem, sizeof(Student), comparefuncint );

}
#endif

#ifdef TEST_SORTFIRSTNAME
 int cmpstring1(const void *arg1, const void *arg2)
{
  Student * ptr1 = (Student *) arg1; 
  Student * ptr2 = (Student *) arg2; 
  return strcmp( (*ptr1).firstname, (*ptr2).firstname);
}

void StudentSortbyFirstName(Student * stu, int numelem)
{
  qsort(stu, numelem, sizeof(Student), cmpstring1);
}
#endif

#ifdef TEST_SORTLASTNAME
 int cmpstring(const void *arg1, const void *arg2)
{
  Student * ptr1 = (Student *) arg1; 
  Student * ptr2 = (Student *) arg2; 

  return strcmp( (*ptr1).lastname, (*ptr2).lastname );
}

void StudentSortbyLastName(Student * stu, int numelem)
{
  qsort(stu, numelem, sizeof(Student), cmpstring);
}
#endif
