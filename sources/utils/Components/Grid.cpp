
#include "Grid.hpp"
#include "../Utility.hpp"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

Grid::Grid(int mHeight, int mWidth, float mPixel):
    mHeight(mHeight),
    mWidth(mWidth),
    mPixel(mPixel),
    mTable(mWidth*mHeight),
    mBackground(sf::Vector2f(mWidth*mPixel, mHeight*mPixel))
{
    mBackground.setFillColor(sf::Color::White);
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
            tmp.setFillColor(ButtonsLabel[color]);
            tmp.setOutlineColor(sf::Color::White);
            tmp.setOutlineThickness(mPixel/20);
            tmp.setSize(sf::Vector2f(mPixel, mPixel));
            tmp.setPosition(sf::Vector2f(posBase.x + (j*mPixel),posBase.y + (i*mPixel)));
            Utility::centerOrigin(tmp);
            target.draw(tmp, states);
        }
        
    }
    
}

void   Grid::setColors(std::vector<int> &v)
{
    mTable = v;
}