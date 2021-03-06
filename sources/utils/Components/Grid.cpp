
#include "Grid.hpp"
#include "../Utility.hpp"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "../../game/AvailableColors.hpp"
Grid::Grid(int mHeight, int mWidth, float mPixel):
    mHeight(mHeight),
    mWidth(mWidth),
    mPixel(mPixel),
    mTable(mWidth*mHeight, AvailableColors::TRANSPARENT),
    mBackground(sf::Vector2f(mWidth*mPixel, mHeight*mPixel))
{
    mBackground.setFillColor(sf::Color::Transparent);
    Utility::centerOrigin(mBackground);
}


bool Grid::update(sf::Time dt) 
{

}

void Grid::handleEvent(const sf::Event& event)
{

}

bool Grid::isSelectable () const
{
    return false;
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
    states.transform *= getTransform();
	target.draw(mBackground, states);
    sf::Vector2f posBase = mBackground.getPosition();
    posBase = sf::Vector2f((mPixel/2) + posBase.x - (mPixel*mWidth/2), (mPixel/2) + posBase.y - (mPixel*mHeight/2));
    if (mTable.size() != mHeight*mWidth) return;
    for (size_t i = 0; i < mHeight; i++)
    {
        for (size_t j = 0; j < mWidth; j++)
        {
            sf::RectangleShape tmp;
            int color = mTable[i*mWidth +j];
            sf::Color tmpC = ButtonsLabel[color];;
            tmp.setFillColor(tmpC);
            tmp.setOutlineColor(sf::Color(224, 224, 224));
            tmp.setOutlineThickness(mPixel/20);
            tmp.setSize(sf::Vector2f(mPixel, mPixel));
            tmp.setPosition(sf::Vector2f(posBase.x + (j*mPixel),posBase.y + (i*mPixel)));
            Utility::centerOrigin(tmp);
            target.draw(tmp, states);
        }
        
    }
    
}

void   Grid::setColors(const std::vector<int> &v)
{
    mTable = v;
}

void   Grid::restart()
{
    for (auto &&i : mTable)
    {
        i = AvailableColors::TRANSPARENT;
    }
    
}