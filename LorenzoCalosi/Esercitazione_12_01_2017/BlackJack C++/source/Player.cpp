#include "Player.hpp"
#include <iostream>

Player::Player()
{

}

virtual bool Player::isHitting() const
{
    char input;
    cout << "Another card? (y/n)" << endl;
    do
    {
        cin << input;
    }
    while(input != 'y' || input != 'n');
    if(input == 'y')? return true : return false;
}

void Player::win() const
{
    cout << "This player wins!" << endl;
}

void Player::lose() const
{
    cout << "This player loses!" << endl;
}

void Player::push() const
{
    cout << "This player is even!" << endl;
}
