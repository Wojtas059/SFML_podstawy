
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
#include "React.h"
#include "Block.h"

using namespace sf;
using namespace std;
template <class T1, class T2> bool isIntersecting(T1& A, T2& B)
{
    return A.right() >= B.left() && A.left() <= B.right() && A.bottom() >= B.top() && A.top() <= B.bottom();
}

bool collisionTest(React& react, Ball& ball)
{
    if (!isIntersecting(react, ball)) return false;

    ball.moveUp();
    if (ball.getPosition().x < react.getPosition().x)
    {
        ball.moveLeft();
    }
    else if (ball.getPosition().x > react.getPosition().x)
    {
        ball.moveRight();
    }

}

bool collisionTest(Block& block, Ball& ball) 
{
    if (!isIntersecting(block, ball)) return false;

    block.destroy();

    float overlapleft{ ball.right() - block.left() };
    float overlapright{ block.right() - ball.left() };
    float overlaptop{ ball.bottom() - block.top() };
    float overlapbottom{ block.bottom() - ball.top() };

    bool ballfromleft(abs(overlapleft) < abs(overlapright));
    bool ballfromtop(abs(overlaptop) < abs(overlapbottom));

    float minOverlapx{ ballfromleft ? overlapleft : overlapright };
    float minOverlapy{ ballfromtop ? overlaptop : overlapbottom };
    
    if (abs(minOverlapx) < abs(minOverlapy))
        ballfromleft ? ball.moveLeft() : ball.moveRight();
    else
        ballfromtop ? ball.moveUp() : ball.moveDown();

}


int main()

{
    Ball ball(400, 400);
    React react(600, 570);
    RenderWindow window{ VideoMode{800,600}, "SFML_podstawy" };

    window.setFramerateLimit(60);
    Event event;
    unsigned blocksX{ 10 }, blocksY{ 4 }, blocksW{ 60 }, blocksH{ 20 };

    vector<Block> blocks;

    for(int i =0; i< blocksY; i++)
        for (int j = 0; j < blocksX; j++)
        {
            blocks.emplace_back((j + 1)*(blocksW +10),(i + 2) * (blocksH + 5), blocksW, blocksH);
        }
        while (true)
    {
        window.clear(Color::Black);
        window.pollEvent(event);

        if (event.type == Event::Closed)
        {
            window.close();
            break;
        }
        ball.update();
        react.update();
        collisionTest(react, ball);
        for (auto& block : blocks)
            if (collisionTest(block, ball))
                break;
        auto iterator = remove_if(begin(blocks), end(blocks), [](Block& block) {return block.isDestroyed(); });
        blocks.erase(iterator, end(blocks));

        window.draw(ball);
        window.draw(react);
        for (auto& block : blocks)
            window.draw(block);
        window.display();
    }


    return 0;
}

