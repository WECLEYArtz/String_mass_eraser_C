#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define safe_size 1000
// this is a test

void delete( char* to_erase_string, char* string, char* result);

int main(){
  // get and store inputs
  char string[ safe_size ];
  char to_erase_string[ safe_size ];

  printf("\nString to delet from:");
  fgets( string, safe_size,  stdin);
  printf("\nWord to delet:");
  scanf("%s", to_erase_string);

  char new_string[strlen(string)];

  //function
  delete( to_erase_string, string, new_string ); //delete to_erase_string in string
  printf("\nNew string :  (%s)\n\n press something to GTFO" , string);

  scanf("%d");
}


void delete( char* to_erase_string, char* string, char* result){

  int end = strlen(string) - strlen(to_erase_string)+1;//calculate when there is no need to check for word anymore
  bool targer_on = false;

  //calculate the size of word to delet and the string
  int slen = strlen(string);
  int tlen = strlen(to_erase_string);
  //this to determine where the deleting proccess happens, does get modified

  int delet_pose; //to reset "fuel" back
  int to_erase_pose;//for erasing process

  //the analyser for a target existance by moving trough characters of string

  for (int fuel = 0 ; fuel < end ; fuel++ )
  {
    printf( " %d," , fuel);
    //blocking the function until there is a similarity between the word n string
    if ( string[ fuel ] != to_erase_string[0] ){continue;}

    //verifying the rest of the chatracters and deciding to continue or not
    bool loop_continue = false;
    for (int fuel2 =1 ; fuel2 <tlen ; fuel2++)
    {

      if (string[ fuel + fuel2 ] != to_erase_string[ fuel2 ] ){  printf("\n   loop breaks in : %d/%d", fuel2 , tlen-1);loop_continue = true; break;}

    }
    if ( loop_continue ){printf(" ° delet canceled\n"); continue;}

    to_erase_pose = fuel;//which will keep getting modified, i will kand still on the first character of the word
    int to_move_pose = to_erase_pose + tlen;//the position where characters will be dragged

    //printf("  Dbug: updated to_erase_pose to (%d), i is currently (%d) ", to_erase_pose, i );

    //double space clearance
      if ( isspace( string[to_erase_pose - 1] )) { to_erase_pose = fuel-1;}
      //if ( isspace( string[to_erase_pose] )) { to_move_pose += 1;}


    //deleting/shifting

    for ( int fuel3 = end; fuel3 >0; fuel3--, to_erase_pose++, to_move_pose++)
    {

      string[ to_erase_pose ] = string[ to_move_pose ];

    }


    //fuel  = delet_pose-1;

    fuel -=1;//solves the word missing issue like a pussy lol
  }

}
