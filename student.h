// You must modify this file
#ifndef PA05_H
#define PA05_H
#include "constant.h"
#include <stdbool.h>
#define NAME_LENGTH 80

// create a structure type that has the following attributes
// please make sure the names are exactly the same
//  int- IO
//  char- firstname[NAME_LENGTH]
//  char- lastname[NAME_LENGTH]
typedef struct
{
  int ID;
  char firstname[NAME_LENGTH];
  char lastname[NAME_LENGTH];
} Student;

// functions to be implemented
bool StudentRead(char * filename, Student * * stu, int * numelem);
bool StudentWrite(char * filename, Student * stu, int numelem);
void StudentSortbyID(Student * stu, int numelem);
void StudentSortbyFirstName(Student * stu, int numelem);
void StudentSortbyLastName(Student * stu, int numelem);
int comparefuncint(const void * arg1, const void * arg2); 
int cmpstring1(const void *arg1, const void *arg2);
int cmpstring(const void *arg1, const void *arg2);

// function already impelemented for you
void StudentPrint(Student * stu, int num);
#endif
