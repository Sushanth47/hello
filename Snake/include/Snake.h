#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include<windows.h>


#define width 50
#define height 25
class Snake
{
    private:
        COORD pos;
        int len;
        float vel;
        char direction;
        std::vector<COORD> body;
    public:
        Snake(COORD pos, float vel);
        void change_dir(char dir);
        void move_snake();
        std::vector<COORD> get_body();
        COORD get_pos();
        bool eaten(COORD food_pos);
        void grow();
        bool collided();
};

#endif // SNAKE_H
