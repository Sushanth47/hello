#include "Snake.h"
#include <vector>
Snake::Snake(COORD pos, float vel)
{
    //ctor
    this->pos = pos;
    this->vel = vel;
    len = 1;
    direction = 'n';

    body.push_back(pos);
}


void Snake::change_dir(char dir){direction = dir;}
void Snake::grow(){ len++;}
COORD Snake::get_pos(){return pos;}

std::vector<COORD> Snake::get_body(){return body;}

void Snake::move_snake()
{
    switch(direction)
    {
    case 'u': pos.Y-=vel;break;
    case 'd': pos.Y+=vel;break;
    case 'l': pos.X-=vel;break;
    case 'r': pos.X+=vel;break;
    }
// Teleportation through walls
    //if(pos.X> width-2) pos.X = 0;
    //if(pos.X <1) pos.X = width-2;


    body.push_back(pos);
    if(body.size() > len) body.erase(body.begin());

}

//COORD Snake::get_pos(){ return pos; }

bool Snake::eaten(COORD food_pos)
{
    if(food_pos.X == pos.X && food_pos.Y == pos.Y) return true;
    else return false;
}

//void Snake::grow(){len++;}

bool Snake::collided(){
    if(pos.X < 1 || pos.X> width-2 || pos.Y < 1 || pos.Y > height-2){return true;}
    else return false;

}
