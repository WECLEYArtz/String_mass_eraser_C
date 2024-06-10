#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define safe_size 1000
// this is a test


//functions inisialisation
int spaces_clear( char* string,int fuel , int* tlenXpand);
void input_request(char* to_erase_string, char* string);
void delete( char* to_erase_string, char* string, char* result);
void printpoint(char* string,int position);
void shoving(char* string, int end, int to_erase_pose, int tlen, int tlenXpand);
 


int main(){
  // get and store inputs
  char string[ safe_size ];
  char to_erase_string[ safe_size ];

  input_request(to_erase_string, string);

  char result[safe_size]; // inisealise char for result string

  //function
  delete( to_erase_string, string, result ); //delete to_erase_string in string

  printf("\nNew string :  (%s)\n\n press something to GTFO" , string); //result


  scanf("%d"); //exiting request
}

void delete( char* to_erase_string, char* string, char* result){

  int end = strlen(string) - strlen(to_erase_string)+1;
  //calculate when there is no need to check for word anymore, end is as a string_end
  int tlen = strlen(to_erase_string);
  int tlenXpand =0;
  //this to determine where the deleting proccess happens, does get modified
  //t(arget)len

  int delet_pose;     //to reset "fuel" back
  int to_erase_pose;  //for erasing process

  //the analyser for a target existance by moving trough characters of string
  //i think i've been hardcoding strcmp()



  for (int fuel = 0; fuel < end ; fuel++ ) //fuel is basically the position of the letter to compare, called fuel for rounds
  {
    //blocking the function until there is a similarity between the letter of the to-earse word and string
    if ( string[ fuel ] != to_erase_string[0] ){continue;} //locked door

    //door unlocked, verifying the rest of the chatracters and deciding to continue or not
    printf("Left door at: \"%c\"", string[fuel]);
    printpoint(string, fuel);
    bool loop_continue = false;


    //the whole new loop process that uses fuel2 is to start checking the similarity of the rest of the target word
    for (int fuel2 =1 ; fuel2 <tlen ; fuel2++)// to comment
    {
      //fuel and fuel2 usae to keep track of the position for both strings syncothinicazicly

      //fuel + fuel2 cz fuel has to be increase, we don't need to check the same character that triggered similarity check
      if (string[fuel + fuel2] != to_erase_string[fuel2] ){

        //DEBUG_____
        printf("\nloop breaks in : %d/%d", fuel2 , tlen-1);
        //DEBUG

        loop_continue = true;//will triger if character isn't same
        break;
        }
      //you reach where the characters are the same, we go one position after fuel with the value fuel2 (1)
      //fuel2 is the fuel for the second loop, 
      //this is the method that resets the loop progress incase the letter isn't a target
    }

    if ( loop_continue ){printf(" ° DEBUG : delet canceled\n"); continue;}
    //willl execute incase a word turned out not to be the target

    to_erase_pose = spaces_clear(string,fuel,&tlenXpand);
    //the position where characters will be dragged
    int arrowposition = to_erase_pose;

//DEBUG______
    printf("Starting shoving at:");
    printpoint(string,fuel);
//DEBUG

    //deleting/shifting to right
    shoving(string,end,to_erase_pose,tlen,tlenXpand);

//DEBUG_________
    printf("Current array:");
    printpoint(string,fuel);
//DEBUG

    fuel--;//solves the word missing issue like a pussy lmao
    tlenXpand=0;
  }
}

void shoving(char* string, int end, int to_erase_pose, int tlen, int tlenXpand){
  for ( int fuel3 = end; fuel3 >0; fuel3--, to_erase_pose++)
    {
      //printf("DEBUG : replacing %c with %c\n", string[ to_erase_pose ] , string[ to_erase_pose + tlen ]);
      string[ to_erase_pose ] = string[ to_erase_pose + tlen + tlenXpand ]; //for target lenght expend
    }
}

void input_request(char* to_erase_string, char* string){
  printf("\nString to expugage:");
  fgets( string, safe_size,  stdin);

  if(string[strlen(string)-1] == '\n'){
    string[strlen(string)-1] = ' ';
  }

  printf("\nWord to delet:");
  scanf("%s", to_erase_string);
}


int spaces_clear( char* string, int fuel,int* tlenXpand ){
  int to_erase_pose = fuel;
  if ( isspace( string[fuel-1])) { (to_erase_pose)--, (*tlenXpand)++;
  printf("DEBUG : going backwards\n");}

  return to_erase_pose;
  //the position where the shoving starts goes one position backwards
}


void printpoint(char* string,int position){
  printf("\n|%s", string);
  printf("\n|");
  for(int i =0; i<position; i++ ){
  printf(" ");
  }
  printf("^\n|position: %d\n", position);
}