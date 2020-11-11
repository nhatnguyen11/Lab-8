#include "lab8.h"

const int MAX = 100;

/*
void stripCarriageReturn(char* str)
{
  int len = strlen(str);
  int x = 0;

  while(str[x] != '\0' && x < len)
  {
    if(str[x] == '\r')
      str[x] = '\0';

    else if(str[x] == '\n')
      str[x] = '\0';

    x++;
  }// end while
}// end function
*/
char * readString(char * str2)
{
  char * str;
  str = (char *)calloc(strlen(str2), sizeof(char));
  strncpy(str, str2, strlen(str2) - 1);
  
  return str;
}// end function


int readAmountToShift(char * str)
{
  //stripCarriageReturn(str);
  int rot;
  while(fgetc(stdin) != '\n'){}
  printf("Please enter the amount to shift: ");
  scanf("%d", &rot);
  while (rot <= 0)
  {
    printf("Invalid \n");    
    printf("Please enter the amount to shift: ");
    scanf("%d", &rot);
  }
  

  return rot;
}// end function


char readDirection()
{
  char dir;
  while(fgetc(stdin) != '\n'){}
  do 
  {
    printf("Please enter the direction to shift (R/L): ");
    scanf("%c", &dir);

    if (dir != 'R' && dir != 'L' && dir != 'l' && dir != 'r')
    {
      printf("Invalid\n");
      while(fgetc(stdin) != '\n'){}
    }
  }while (dir != 'R' && dir != 'L' && dir != 'l' && dir != 'r');
  while(fgetc(stdin) != '\n'){}
  return dir;
}// end function

int menu()
{
  int choice=4;
    do
    {
    printf("The menu choices are\n");
    printf("1. Read a New String\n");
    printf("2. Encrypt\n");
    printf("3. Decrypt\n");
    printf("4. Quit the program\n");
    printf("Choose: ");
    scanf("%d", &choice);

    if (choice == '4')
    {
      printf("Good Bye\n");
    }
    if (choice < 1 || choice >4)
    {
      printf("Invalid choice \n");
    }
 
    
    }while (choice < 1 || choice > 4);
  

  return choice;
}// end function

char* encryptString(char* str, int rotAmount, char direction)
{
  char * encryptstr = NULL;
  int rot = rotAmount % 26;
  
  if (rot < 10)
    {
    encryptstr = (char*)calloc(strlen(str) + 3, sizeof(char));
    // +3 bc we add /0 rotAMount, direction 
  
    encryptstr[0] = (char)rot;
    encryptstr[1] = direction;
    for(int i = 2; i < strlen(str) + 3 ; i++)
      {
        encryptstr[i] = str[i - 2];
        //i = str[i] + rotAmount;
      }
    
    }
  else
    {
      int firstdig = rot / 10;
      int secondig = rot % 10;
      encryptstr = (char*)calloc(strlen(str) + 4, sizeof(char));
      encryptstr[0]= (char)firstdig;
      encryptstr[1]= (char)secondig;
      encryptstr[2]= direction;
      for(int i = 3; i < strlen(str) + 3 ; i++)
      {
        char ltr= str[i-3];
        if (ltr >= 'a' && ltr <= 'z')
        {
          if ((ltr + rot) < 97)
          {
            encryptstr[i+2] = ltr + 26 + rot;
          }
          else if ((ltr + rot) > 122 )
          {
            encryptstr[i+2] = ltr - 26 + rot;

          }
          else 
          encryptstr[i] = str[i - 2];
        }
        
      }
    }
  
  
  
  

  return encryptstr;
}// end function


char getDirection(char* encryptedString)
{
  char dir;
  
  return dir;
}// end function


int getRotation(char* encryptedString)
{
  int rot = 0 ;
  rot = (int) encryptedString[0] - 65;
  return rot;
}// end function


char* decryptString(char* str, int rotAmount, char direction)
{
  return NULL;
}// end function






void cleanUp(char* str)
{
  free(str);
  str = NULL;
}// end function


void stripCarriageReturn(char* str)
{
  int len = strlen(str);
  int x = 0;

  while(str[x] != '\0' && x < len)
  {
    if(str[x] == '\r')
      str[x] = '\0';

    else if(str[x] == '\n')
      str[x] = '\0';

    x++;
  }// end while
}// end function

