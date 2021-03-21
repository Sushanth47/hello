#include "Food.h"

void Food::gen_food()
{
    pos.X = rand()%(width - 3) + 1;
    pos.Y = rand()%(height - 3) + 1;

}

COORD Food::get_pos(){ return pos;}
