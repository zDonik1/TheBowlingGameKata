/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 06/08/2022
 *
 *************************************************************************/

#pragma once

#include <array>

class Game
{
public:
    void roll(int pins);
    int score();

private:
    bool isSpare(int frameIndex) const;
    bool isStrike(int frameIndex) const;
    int sumOfBallsInFrame(int frameIndex) const;
    int spareBonus(int frameIndex) const;
    int strikeBonus(int frameIndex) const;

private:
    std::array<unsigned int, 21> _rolls;
    unsigned int _currentRoll = 0;
};
