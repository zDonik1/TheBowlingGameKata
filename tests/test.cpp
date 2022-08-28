#include <gmock/gmock-matchers.h>

#include <game.h>

using namespace testing;

class BowlingGameTest : public Test
{
protected:
    void rollMany(unsigned int rolls, unsigned int pins)
    {
        for (auto i = 0U; i < rolls; ++i) {
            game.roll(pins);
        }
    }

    void rollSpare()
    {
        game.roll(5);
        game.roll(5);
    }

    void rollStrike() { game.roll(10); }

protected:
    Game game;
};

TEST_F(BowlingGameTest, TestGutterGame)
{
    rollMany(20, 0);
    EXPECT_THAT(game.score(), Eq(0));
}

TEST_F(BowlingGameTest, TestAllOnes)
{
    rollMany(20, 1);
    EXPECT_THAT(game.score(), Eq(20));
}

TEST_F(BowlingGameTest, TestOneSpare)
{
    rollSpare();
    game.roll(3);
    rollMany(17, 0);
    EXPECT_THAT(game.score(), Eq(16));
}

TEST_F(BowlingGameTest, TestOneStrike)
{
    rollStrike();
    game.roll(3);
    game.roll(4);
    rollMany(16, 0);
    EXPECT_THAT(game.score(), Eq(24));
}

TEST_F(BowlingGameTest, TestPerfectGame)
{
    rollMany(12, 10);
    EXPECT_THAT(game.score(), Eq(300));
}
