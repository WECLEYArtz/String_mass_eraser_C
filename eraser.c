#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define safe_size 1000
// this is a test


void input_request(char* to_erase_string, char* string);
void delete( char* to_erase_string, char* string, char* result);


int main(){
  // get and store inputs
  char string[ safe_size ];
  char to_erase_string[ safe_size ];

  input_request(to_erase_string, string);

  char result[strlen(string)]; // inisealise char for result string

  //function
  delete( to_erase_string, string, result ); //delete to_erase_string in string
  printf("\nNew string :  (%s)\n\n press something to GTFO" , string); //result




  scanf("%d"); //exiting request
}


void input_request(char* to_erase_string, char* string){
  printf("\nString to expugage:");
  fgets( string, safe_size,  stdin);
  printf("\nWord to delet:");
  scanf("%s", to_erase_string);
}



void delete( char* to_erase_string, char* string, char* result){

  int end = strlen(string) - strlen(to_erase_string)+1;//calculate when there is no need to check for word anymore, end is as a string_end


  int tlen = strlen(to_erase_string);
  //this to determine where the deleting proccess happens, does get modified
  //t(arget)len

  int delet_pose; //to reset "fuel" back
  int to_erase_pose;//for erasing process

  //the analyser for a target existance by moving trough characters of string
  //i think i've been hardcoding strcmp()


//string          = me when the when the (20)
//checker         =    ^

//fuel  position  =    ^


//to_erase_string = when (4)
//fuel2 position  =  ^

//fuel  = 3
//fuel2 = 1
//fuel3 = 
//end   = 16 


  for (int fuel = 0; fuel < end ; fuel++ ) //fuel is basically the position of the letter to compare, called fuel for rounds
  {
      //printf( " %d," , fuel);
    //blocking the function until there is a similarity between the letter of the to-earse word and string
    if ( string[ fuel ] != to_erase_string[0] ){continue;}

    //verifying the rest of the chatracters and deciding to continue or not
    bool loop_continue = false;

    //the whole new loop process that uses fuel2 is to start checking the similarity of the rest of the target word
    for (int fuel2 =1 ; fuel2 <tlen ; fuel2++)// to comment
    {
      //fuel and fuel2 usae to keep track of the position for both strings syncothinicazicly
      //fuek + fuek2 cz fuel has to be increase, we don't need to check the same character that triggered similarity check
      if (string[fuel + fuel2] != to_erase_string[fuel2] ){
        printf("\n   loop breaks in : %d/%d", fuel2 , tlen-1);
        loop_continue = true;//will triger if character isn't same
        break;
        }
      //you reach where the characters are the same, we go one position after fuel with the value fuel2 (1)
      //fuel2 is the fuel for the second loop, 
      //this is the method that resets the loop progress incase the letter isn't a target
    }

    if ( loop_continue ){printf(" ° DEBUG : delet canceled\n"); continue;}
    //willl execute incase a word turned out not to be the target

    to_erase_pose = fuel;//which will keep getting modified, i will land still on the first character of the word
    int to_move_pose = to_erase_pose + tlen;//the position where characters will be dragged

    //printf("  Dbug: updated to_erase_pose to (%d), i is currently (%d) ", to_erase_pose, i );

    //double space clearance
        if ( isspace( string[to_erase_pose - 1] )) { to_erase_pose--;}

    //deleting/shifting
    for ( int fuel3 = end; fuel3 >0; fuel3--, to_erase_pose++, to_move_pose++)
    {

      string[ to_erase_pose ] = string[ to_move_pose ];

    }

    fuel -=1;//solves the word missing issue like a pussy lmao
  }

}