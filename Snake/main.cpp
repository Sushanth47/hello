#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<ctime>



#include "Snake.h"
#include "Food.h"

#define width 50
#define height 25


using namespace std;

//const int width = 50, height = 25;


Snake snake({width/2, height/2}, 1);
//struct COORD {int X, Y};
Food food;

int score = 0;

void board()
{
    COORD snake_pos = snake.get_pos();
    COORD food_pos = food.get_pos();

    std::vector<COORD> snake_body = snake.get_body();

    cout<<"SCORE:" << score<<"\n\n";

    for(int i=0; i< height; i++)
    {
        cout<<"\t\t|";
        for(int j=0; j<(width-2); j++)
        {
            if(i==0 || i==height-1) cout<<'=';
            else if(i ==snake_pos.Y && j+1 == snake_pos.X) cout<<'O';
            else if(i == food_pos.Y && j+1 == food_pos.X) cout<<'*';
            else
            {
                bool isBodyPart = false;
                for(int k=0; k<snake_body.size()-1; k++){
                    if(i == snake_body[k].Y && j+1 == snake_body[k].X){
                        cout<<'o';
                        isBodyPart = true;
                        break;
                    }
                }
                if(!isBodyPart) cout<<' ';
            }
        }
        cout<<"|\n";
    }
}



int main(){

    score = 0;
    srand(time(NULL));
    food.gen_food();

    bool game_over = false;
    while(!game_over)
    {
        board();
        if(kbhit())
        {
            switch(getch())
            {
                case 72:snake.change_dir('u');break;
                case 80:snake.change_dir('d');break;
                case 75:snake.change_dir('l');break;
                case 77:snake.change_dir('r');break;
            }
        }


        if(snake.eaten(food.get_pos()))
           {
                food.gen_food();
                snake.grow();
                score+=10;
           }

        if(snake.collided()) game_over = true;
        snake.move_snake();
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    }

}
