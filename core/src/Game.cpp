//
// Created by illya on 25/09/18.
//

#include "Game.h"
#include "Numbers.h"

using cows_and_bulls::Game;
using cows_and_bulls::Number;
using cows_and_bulls::Numbers;

Game::Game() :
  available_numbers(Numbers::nums.begin(), Numbers::nums.end())
{}
