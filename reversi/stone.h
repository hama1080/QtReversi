#ifndef STONE_H
#define STONE_H

enum class STONE_COLOR
{
    BLACK,
    WHITE
};

class Stone
{
private:
    STONE_COLOR color_;

public:
    Stone(STONE_COLOR color);

    STONE_COLOR GetStoneColor();
    void SetStoneColor(STONE_COLOR color);

    void Reverse();
};

#endif // STONE_H
