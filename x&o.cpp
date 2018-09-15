#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;


void setcolor(unsigned short color){

HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hcon , color);
}

typedef unsigned int positive_int;  /// ..........



int main()
{
system("color f5");
     constexpr positive_int row = 3;
    constexpr positive_int column = 3;


   char game[row][column] = {
                                {' ',' ' ,' ',} ,

                                {' ',' ' ,' ',} , /// empty game board.....

                                {' ',' ',' '}
                                };

srand(static_cast<unsigned>( time(NULL)) );

bool gameover = false;
bool proceed = false;
bool end_menu = false;
positive_int checkins = 0;

bool computer_turn = true;
bool against_human = false;
bool Ai = true;
bool Ai_proceed = false;
bool Ai_proceed2 = false;
bool Ai_proceed3 = false;

bool game_menu = true;
bool against_comp = false;

bool ist_player = true;
bool nd_player = false;

bool engage = true;

string comp_won = " ";

positive_int rol(0);       /// computer values...........
positive_int col(0);

positive_int user_rol(0);         /// user values..........
positive_int user_col(0);

positive_int max_comp_count(0);
constexpr positive_int max_col = 3;
constexpr positive_int ended = row*column;

positive_int max_user_count(0);
positive_int stalemate(0);

positive_int count_Ai = 0;
positive_int count_Ai2 = 0;    /// counter variables///..
positive_int count_Ai3 = 0;
positive_int count_Ai4 = 0;



while(gameover == false){

max_user_count = 0;
max_comp_count = 0;

stalemate = 0;


while(game_menu == true){      /// game menu.......
string option  = " ";

cout<<"select option"<<endl;
cout<<"enter A to select player against player"<<endl;
cout<<"enter B to select player against computer"<<endl;
cin>>option;

if(option == "A" || option == "a"){

for(positive_int r = 0 ; r<row; ++r){
    for(positive_int c = 0 ; c<column ; ++c ){

        game[r][c] = ' ';
    }

}

  against_human = true;
ist_player = true;
nd_player = false;
against_comp = false;
game_menu = false;

       system("cls");

    }


else if(option == "B" || option == "b")
    {
    against_comp = true;
    computer_turn = true;
    game_menu = false;

    }
else{
    system("cls");
    cout<<"invalid option selected please select another"<<endl;
    game_menu = true;
    against_comp = false;
    break;
        }



}  /// end of menu (game)....

while(against_human == true){


positive_int user_count = 0;

if(stalemate == 0){

for(positive_int r = 0 ; r<row; ++r){
    for(positive_int c = 0 ; c<column ; ++c ){

        cout<<" | "<<game[r][c]<<" | ";
    }
    cout<<endl;
}

}

if(ist_player == true){





string op;

cout<<"player1 turn"<<endl;
cout<<"enter your coodinates"<<endl;
   cin>>op;                               /// set user coordinates.....

   if(op == "1"){

    user_rol = 0;
    user_col = 0;
   }
   else if(op == "2"){

     user_rol = 0;
    user_col = 1;
   }

    else if(op == "3"){

     user_rol = 0;
    user_col = 2;
   }

     else if(op == "4"){

     user_rol = 1;
    user_col = 0;
   }  /// automatic cooridinate mapping....##new feature.............

    else if(op == "5"){       /// 1-9
                /// each represents a seperate box....

     user_rol = 1;
    user_col = 1;

   }

else if(op == "6"){

     user_rol = 1;
    user_col = 2;
   }

   else if(op == "7"){

     user_rol = 2;
    user_col = 0;
   }

   else if(op == "8"){

     user_rol = 2;
    user_col = 1;
   }

   else if(op == "9"){

     user_rol = 2;
    user_col = 2;
   }
else {

    cout<<"invalid number"<<endl;
    ist_player = true;    /// still user turn...
      nd_player = false;    /// 2nd player still not allowed to play...
break;
}



    if(game[user_rol][user_col] == ' '){   /// to check if a box is empty..
 ///setcolor(249);
        game[user_rol][user_col] = 'X';   /// user player is "X";
stalemate += 1;
        system("cls");
   for(positive_int i = 0 ; i<row; ++i){
        for(positive_int j = 0 ; j<column; ++j){

                  cout<<" | "<<game[i][j]<<" | ";

        }  /// end of 2nd loop.......
        cout<<endl;
    }



ist_player = false;
nd_player = true;

    }
      /// ## if not empty try again then!!........

     else if(game[user_rol][user_col] != ' '){
            cout<<"INVALID SPACE SELECTED PLEASE CHOOSE ANOTHER"<<endl;

            ist_player = true;    /// still user turn...
            nd_player = false;   /// computer still not allowed to play...

    }



if(gameover == false){
/// horizonal user win...
positive_int x = user_rol; /// sets x to computer current rol value....
user_count = 0;
for(positive_int i = 0; i<column; ++i){    /// loops true the entire col on x row...

    if(game[x][i] == 'X'){

user_count += 1;
    }
}

if(user_count > max_user_count){

    max_user_count = user_count;
    user_count = 0;
}
else{

    max_user_count = max_user_count;
    user_count = 0 ;
}

}
if(gameover == false){
///............vertical test......
user_count = 0;

positive_int x2 = user_col;

for(positive_int i = 0; i<row; ++i){
if(game[i][x2] == 'X'){
    user_count  += 1;
}


} ///......
if(user_count > max_user_count){

    max_user_count = user_count;
    user_count = 0;
}
else{

    max_user_count = max_user_count;
    user_count = 0 ;
}
}

if(gameover == false){
/// diagonal test.................
positive_int x3 = 0;
user_count = 0 ;

for(positive_int i = 0 ; i<column ; ++i)
{
    if(game[x3][i] == 'X'){
        user_count +=1;
    }
    ++x3;
}
if(user_count > max_user_count){

    max_user_count = user_count;
    user_count = 0;
}
else{

    max_user_count = max_user_count;
   user_count = 0 ;
}

}


if(gameover == false){
/// diagonal test.................
positive_int x4 = column-1;
user_count = 0 ;

for(positive_int i = 0 ; i<row ; ++i)
{
    if(game[i][x4] == 'X'){
        user_count +=1;
    }
    --x4;
}
if(user_count > max_user_count){

    max_user_count = user_count;
    user_count = 0;
}
else{

    max_user_count = max_user_count;
    user_count = 0 ;
}

}



if(max_user_count  == max_col){

    ///gameover = true;
    ist_player = false;
    nd_player = false;
    against_human = false;

    cout<<"GAME OVER player1 WINS"<<endl;
system("pause");
end_menu = true;
}
  /// game over condition.......


if(gameover == false){

if(stalemate == ended){

     ///gameover = true;
     ist_player = false;
    nd_player = false;
    against_human = false;
        cout<<"STALEMATE NO WINNER"<<endl;
        system("pause");
        end_menu = true;
}

}


} /// end of ist player.....

///...............................................................

if(nd_player == true){   /// 2nd player



string op;
cout<<"player2 turn"<<endl;
cout<<"enter your coodinates"<<endl;
   cin>>op;                               /// set user coordinates.....

   if(op == "1"){

    user_rol = 0;
    user_col = 0;
   }
   else if(op == "2"){

     user_rol = 0;
    user_col = 1;
   }

    else if(op == "3"){

     user_rol = 0;
    user_col = 2;
   }

     else if(op == "4"){

     user_rol = 1;
    user_col = 0;
   }  /// automatic cooridinate mapping....##new feature.............

    else if(op == "5"){       /// 1-9
                /// each represents a seperate box....

     user_rol = 1;
    user_col = 1;

   }

else if(op == "6"){

     user_rol = 1;
    user_col = 2;
   }

   else if(op == "7"){

     user_rol = 2;
    user_col = 0;
   }

   else if(op == "8"){

     user_rol = 2;
    user_col = 1;
   }

   else if(op == "9"){

     user_rol = 2;
    user_col = 2;
   }
else {

    cout<<"invalid number"<<endl;

    nd_player = true;    /// still user turn...
      ist_player = false;
      break; /// 2nd player still not allowed to play...
}



    if(game[user_rol][user_col] == ' '){   /// to check if a box is empty..
///setcolor(252);
        game[user_rol][user_col] = 'O';   /// user player is "X";
stalemate += 1;
        system("cls");
   for(positive_int i = 0 ; i<row; ++i){
        for(positive_int j = 0 ; j<column; ++j){

                  cout<<" | "<<game[i][j]<<" | ";

        }  /// end of 2nd loop.......
        cout<<endl;
    }



nd_player = false;
ist_player = true;

    }
      /// ## if not empty try again then!!........

     else if(game[user_rol][user_col] != ' '){
            cout<<"INVALID SPACE SELECTED PLEASE CHOOSE ANOTHER"<<endl;

            nd_player = true;    /// still user turn...
            ist_player = false;   /// computer still not allowed to play...

    }






if(gameover == false){
/// horizonal user win...
positive_int x = user_rol; /// sets x to computer current rol value....
user_count = 0;
for(positive_int i = 0; i<column; ++i){    /// loops true the entire col on x row...

    if(game[x][i] == 'O'){

user_count += 1;
    }
}

if(user_count > max_user_count){

    max_user_count = user_count;
    user_count = 0;
}
else{

    max_user_count = max_user_count;
    user_count = 0 ;
}

}
if(gameover == false){
///............vertical test......
user_count = 0;

positive_int x2 = user_col;

for(positive_int i = 0; i<row; ++i){
if(game[i][x2] == 'O'){
    user_count  += 1;
}


} ///......
if(user_count > max_user_count){

    max_user_count = user_count;
    user_count = 0;
}
else{

    max_user_count = max_user_count;
    user_count = 0 ;
}
}

if(gameover == false){
/// diagonal test.................
positive_int x3 = 0;
user_count = 0 ;

for(positive_int i = 0 ; i<column ; ++i)
{
    if(game[x3][i] == 'O'){
        user_count +=1;
    }
    ++x3;
}
if(user_count > max_user_count){

    max_user_count = user_count;
    user_count = 0;
}
else{

    max_user_count = max_user_count;
   user_count = 0 ;
}

}


if(gameover == false){
/// diagonal test.................
positive_int x4 = column-1;
user_count = 0 ;

for(positive_int i = 0 ; i<row ; ++i)
{
    if(game[i][x4] == 'O'){
        user_count +=1;
    }
    --x4;
}
if(user_count > max_user_count){

    max_user_count = user_count;
    user_count = 0;
}
else{

    max_user_count = max_user_count;
    user_count = 0 ;
}

}



if(max_user_count  == max_col){

    ///gameover = true;
    nd_player = false;
    ist_player = false;
    against_human = false;
end_menu = true;
    cout<<"GAME OVER player2 WINS"<<endl;
system("pause");
}
  /// game over condition.......




}  ///

} /// while end.........

while(against_comp == true){



 count_Ai = 0;
 count_Ai2 = 0;
 count_Ai3 = 0;           /// resets value
 count_Ai4 = 0;

    rol = rand()%3;               /// computers choose of position....
    col = rand()%3;

positive_int comp_count = 0;         ///.......
positive_int user_count = 0;
positive_int temp_rol = 0;
positive_int temp_col = 0;
  /// max size of a the column..

  /// .....game end value..

Ai = true;

if(computer_turn == true){      /// computer turn logic........

if(Ai == true){

for(positive_int c = 0 ; c<column ;++c){
        count_Ai = 0;    /// resets counter...
for(positive_int r = 0 ; r<row ; ++r){


        if(game[r][c] == 'O'){

            count_Ai +=1;            /// resets vertical counter
            }

            if(count_Ai == row-1){                 /// vertical test...
                        Ai = false;
                        checkins = count_Ai;
                for(positive_int i = 0; i<row ; ++i){

                    if(game[i][c] == ' '){

        temp_col = c;
        temp_rol = i;

        rol = temp_rol;
        col = temp_col;
        count_Ai = 0;
comp_won = "vertical win";


                    }   /// loop if
                }  /// loop....logic
            }   ///.....end of Ai if...con...

            else{
                rol = rol;
                col = col;
                Ai = false;
                Ai_proceed = true;

            }
}
        }   ///...if....
}
if(Ai_proceed == true){


positive_int cc = column-1;

for(int r = 0  ; r<row ; ++r , --cc){

        if(game[r][cc] == 'O'){

            count_Ai2 +=1;
            }
            if(count_Ai2 == row-1){                 /// diagonal right test...
                Ai_proceed = false;
                checkins = count_Ai2;
                        positive_int cc3 = column-1;
                for(positive_int i = 0; i<row ; ++i ,--cc3){
                    if(game[i][cc3] == ' '){

        temp_col = cc3;
        temp_rol = i;

        rol = temp_rol;
        col = temp_col;
count_Ai2 = 0;
comp_won = "diagonal right win";
                    }   /// loop if
                }  /// loop....logic
            }   ///.....end of Ai if...con...

            else{
                rol = rol;
                col = col;
                Ai_proceed = false;
                Ai_proceed2 = true;
            }
}


}

if(Ai_proceed2 == true){

 positive_int c4 = 0;

for(int r = 0  ; r<row ; ++r , ++c4){

        if(game[r][c4] == 'O'){

            count_Ai3 +=1;
            }
            if(count_Ai3 == row-1){                 /// diagonal left test...
                Ai_proceed2 = false;
                    int cc3 = 0;
            checkins = count_Ai3;
                for(positive_int i = 0; i<row ; ++i , ++cc3){
                    if(game[i][cc3] == ' '){

        temp_col = cc3;
        temp_rol = i;

        rol = temp_rol;
        col = temp_col;
        count_Ai3 = 0;

comp_won = "diagonal left win";
                    }   /// loop if
                }  /// loop....logic
            }   ///.....end of Ai if...con...

            else{
                rol = rol;
                col = col;
                Ai_proceed2 = false;
                Ai_proceed3 = true;
            }
}

}

if(Ai_proceed3 == true){

for(positive_int r = 0; r<row; ++r){

    count_Ai4 = 0; /// resets counter....
    for(positive_int c = 0; c<column; ++c)

  {
      if(game[r][c] == 'O'){

      count_Ai4 +=1;

      }  ///....increment count....
      if(count_Ai4 == column-1){
checkins = count_Ai4;
      Ai_proceed3 = false;

       for(positive_int i = 0 ; i<column; ++i){    /// horizonal test....
        if(game[r][i] == ' '){

        temp_col = i;
        temp_rol = r;

        rol = temp_rol;
        col = temp_col;
        count_Ai4 = 0;
comp_won = "horizontal win";

        }   ///......
       }    ///........looping through the selected..

      }   ///.....if AI

      else{
        rol = rol;
        col = col;
Ai_proceed3 = false;
Ai = true;

      }
  }


}
}


}
/// new function to check if the opponent wants to win...
if(checkins <column-1){  ///
positive_int check = 0;

///.....condition
///starts.........
for(positive_int r =0 ;r<row; ++r){
check = 0;
for(positive_int c = 0; c<column; ++c){

    if(game[r][c] == 'X'){
check+=1;

    }

    if(check == column-1){

for(positive_int cc = 0 ; cc<column;++cc){

    if(game[r][cc] == ' '){

        col = cc;
        rol = r;

    }
}
break;

    }

    else if(check!=column-1){

        rol = rol;
        col = col;
    }
}

///condition
///.....end...
}
}

if(game[rol][col] == ' '){   /// checks if the board is  empty..
///setcolor(252);
game[rol][col] = 'O';   /// computer is player "O";
stalemate +=1;

/// stalemate increase... value...
system("cls");
   for(positive_int i = 0 ; i<row; ++i){
        for(positive_int j = 0 ; j<column; ++j){

            cout<<" | "<<game[i][j]<<" | ";

        }  /// end of 2nd loop.......
        cout<<endl;
    }
    proceed = true;            /// now users turn.......
    computer_turn = false;    /// computer is not allowed to play......


}  /// end of computer box empty condition...
cout<<checkins<<endl;
/*else if(game[rol][col] != ' '){
        cout<<"PLEASE COMPUTER IS STILL THINKING"<<endl;
system("pause");

    proceed = false;
    computer_turn = true;

  /// in testing stage  ## feature for slower systems
}
*/





if(gameover == false){
/// horizonal computer win...
positive_int x = rol;          /// sets x to computer current rol value....
comp_count = 0;
for(positive_int i = 0; i<column; ++i){       /// loops true the entire col on x row...

    if(game[x][i] == 'O'){

comp_count += 1;
    }
}

if(comp_count > max_comp_count){

    max_comp_count = comp_count;
    comp_count = 0;
}
else{

    max_comp_count = max_comp_count;
    comp_count = 0 ;
}

}
if(gameover == false){
///............vertical test......
comp_count = 0;

positive_int x2 = col;

for(positive_int i = 0; i<row; ++i){
if(game[i][x2] == 'O'){
    comp_count  += 1;
}

else{

    max_comp_count = max_comp_count;
    comp_count = 0 ;
}

} ///......
if(comp_count > max_comp_count){

    max_comp_count = comp_count;
    comp_count = 0;
}
else{

    max_comp_count = max_comp_count;
    comp_count = 0 ;
}

}

if(gameover == false){
/// diagonal test.................
positive_int x3 = 0;
comp_count = 0 ;

for(positive_int i = 0 ; i<column ; ++i)
{
    if(game[x3][i] == 'O'){
        comp_count +=1;
    }
    ++x3;
}
if(comp_count > max_comp_count){

    max_comp_count = comp_count;
    comp_count = 0;
}
else{

    max_comp_count = max_comp_count;
    comp_count = 0 ;
}

}


if(gameover == false){
/// diagonal test.................
positive_int x4 = column-1;
comp_count = 0 ;

for(positive_int i = 0 ; i<row ; ++i)
{
    if(game[i][x4] == 'O'){
        comp_count +=1;
    }
    --x4;
}
if(comp_count > max_comp_count){

    max_comp_count = comp_count;
    comp_count = 0;
}
else{

    max_comp_count = max_comp_count;
    comp_count = 0 ;
}

}


if(max_comp_count  == max_col){

    ///gameover = true;
    against_comp = false;
    proceed = false;
    computer_turn = false;
end_menu = true;
    cout<<"GAME OVER COMPUTER WINS"<<endl;
    cout<<endl;
    cout<<comp_won<<endl;
    cout<<checkins<<endl;
    cout<<endl;

system("pause");


}
  /// game over condition.......


///
if(gameover == false){

if(stalemate == ended){

     ///gameover = true;
     against_comp = false;
    proceed = false;
    computer_turn = false;
        cout<<"STALEMATE NO WINNER"<<endl;
        system("pause");
        end_menu = true;
}

}
                                    ///stalemate function

///.....................................................................................


if(proceed == true){   /// check user turn codition.... /// true??

string op;
    cout<<"enter your coodinates"<<endl;
   cin>>op;                               /// set user coordinates.....

   if(op == "1"){

    user_rol = 0;
    user_col = 0;
   }
   else if(op == "2"){

     user_rol = 0;
    user_col = 1;
   }

    else if(op == "3"){

     user_rol = 0;
    user_col = 2;
   }

     else if(op == "4"){

     user_rol = 1;
    user_col = 0;
   }  /// automatic cooridinate mapping....##new feature.............

    else if(op == "5"){       /// 1-9
                /// each represents a seperate box....

     user_rol = 1;
    user_col = 1;

   }

else if(op == "6"){

     user_rol = 1;
    user_col = 2;
   }

   else if(op == "7"){

     user_rol = 2;
    user_col = 0;
   }

   else if(op == "8"){

     user_rol = 2;
    user_col = 1;
   }

   else if(op == "9"){

     user_rol = 2;
    user_col = 2;
   }
else {

    cout<<"invalid number"<<endl;
    proceed = true;    /// still user turn...
            computer_turn = false;   /// computer still not allowed to play...

}



    if(game[user_rol][user_col] == ' '){   /// to check if a box is empty..
             ///setcolor(249);
        game[user_rol][user_col] = 'X';   /// user player is "X";
stalemate += 1;
        system("cls");
   for(positive_int i = 0 ; i<row; ++i){
        for(positive_int j = 0 ; j<column; ++j){

                  cout<<" | "<<game[i][j]<<" | ";

        }  /// end of 2nd loop.......
        cout<<endl;
    }



proceed = false;
computer_turn = true;

    }
      /// ## if not empty try again then!!........

     else if(game[user_rol][user_col] != ' '){
            cout<<"INVALID SPACE SELECTED PLEASE CHOOSE ANOTHER"<<endl;

            proceed = true;    /// still user turn...
            computer_turn = false;   /// computer still not allowed to play...

    }



}   ///..........


if(gameover == false){
/// horizonal user win...
positive_int x = user_rol; /// sets x to computer current rol value....
user_count = 0;
for(positive_int i = 0; i<column; ++i){    /// loops true the entire col on x row...

    if(game[x][i] == 'X'){

user_count += 1;
    }
}

if(user_count > max_user_count){

    max_user_count = user_count;
    user_count = 0;
}
else{

    max_user_count = max_user_count;
    user_count = 0 ;
}

}
if(gameover == false){
///............vertical test......
user_count = 0;

positive_int x2 = user_col;

for(positive_int i = 0; i<row; ++i){
if(game[i][x2] == 'X'){
    user_count  += 1;
}


} ///......
if(user_count > max_user_count){

    max_user_count = user_count;
    user_count = 0;
}
else{

    max_user_count = max_user_count;
    user_count = 0 ;
}
}

if(gameover == false){
/// diagonal test.................
positive_int x3 = 0;
user_count = 0 ;

for(positive_int i = 0 ; i<column ; ++i)
{
    if(game[x3][i] == 'X'){
        user_count +=1;
    }
    ++x3;
}
if(user_count > max_user_count){

    max_user_count = user_count;
    user_count = 0;
}
else{

    max_user_count = max_user_count;
   user_count = 0 ;
}

}


if(gameover == false){
/// diagonal test.................
positive_int x4 = column-1;
user_count = 0 ;

for(positive_int i = 0 ; i<row ; ++i)
{
    if(game[i][x4] == 'X'){
        user_count +=1;
    }
    --x4;
}
if(user_count > max_user_count){

    max_user_count = user_count;
    user_count = 0;
}
else{

    max_user_count = max_user_count;
    user_count = 0 ;
}

}



if(max_user_count  == max_col){

    ///gameover = true;
    against_comp = false;
    proceed = false;
    computer_turn = false;

    cout<<"GAME OVER YOU WIN"<<endl;
system("pause");
end_menu = true;
}
  /// game over condition.......




}
if(end_menu == true){

if(against_comp == false || against_human == false){
        string op;
    cout<<"DO YOU WANT TO PLAY AGAIN OR GO TO MAIN MENU?"<<endl;
    cout<<"1 for game menu"<<endl;
    cout<<"2 for against computer"<<endl;
    cout<<"3 for againt human"<<endl;
cin>>op;

if(op == "1"){

    game_menu = true;
       for(int i = 0 ; i<row ; ++i){

        for(int j = 0 ; j<column ; ++j){

            game[i][j] = ' ';
        }
    }
  system("cls");

  against_comp = false;
  against_human = false;
end_menu = false;
}


else if(op == "2"){


    for(int i = 0 ; i<row ; ++i){

        for(int j = 0 ; j<column ; ++j){

            game[i][j] = ' ';
        }
    }
  system("cls");
    against_comp = true;
    computer_turn = true;
end_menu = false;
    ///stalemate = 0;
}


if(op == "3"){

for(int i = 0 ; i<row ; ++i){

        for(int j = 0 ; j<column ; ++j){

            game[i][j] = ' ';
        }
    }

 system("cls");

against_human = true;
ist_player = true;
nd_player = false;
against_comp = false;
end_menu = false;

}

}

}   /// end .....
} /// end of game loop........(game over)



} /// end of main....

