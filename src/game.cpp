/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 06/08/2022
 *
 *************************************************************************/

#include "game.h"

void Game::roll(int pins)
{
    _rolls[_currentRoll++] = pins;
}

int Game::score()
{
    auto score = 0;
    for (auto frameIndex = 0, frame = 0; frame < 10; ++frame) {
        if (isStrike(frameIndex)) {
            score += 10 + strikeBonus(frameIndex);
            ++frameIndex;
        } else if (isSpare(frameIndex)) {
            score += 10 + spareBonus(frameIndex);
            frameIndex += 2;
        } else {
            score += sumOfBallsInFrame(frameIndex);
            frameIndex += 2;
        }
    }
    return score;
}

bool Game::isSpare(int frameIndex) const
{
    return _rolls.at(frameIndex) + _rolls.at(frameIndex + 1) == 10;
}

bool Game::isStrike(int frameIndex) const
{
    return _rolls.at(frameIndex) == 10;
}

int Game::sumOfBallsInFrame(int frameIndex) const
{
    return _rolls.at(frameIndex) + _rolls.at(frameIndex + 1);
}

int Game::spareBonus(int frameIndex) const
{
    return _rolls.at(frameIndex + 2);
}

int Game::strikeBonus(int frameIndex) const
{
    return _rolls.at(frameIndex + 1) + _rolls.at(frameIndex + 2);
}

