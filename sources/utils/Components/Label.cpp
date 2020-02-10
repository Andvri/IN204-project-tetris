#include "Label.hpp"
#include "../Utility.hpp"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


Label::Label(const std::string& text, const std::string& path, bool active, float size, bool toogle, bool highlighted, const sf::Color color)
    : Component(),
    mEffect(NONE),
    mBorder()
{
    if (active) activate();
    if(!mFont.loadFromFile(path))
	{
	}
    mText.setFont(mFont);
    mText.setString(text);
    mText.setCharacterSize(size);
    mText.setFillColor(color);
    mText.setOutlineColor(color);
    mBorder.setSize(sf::Vector2f(mText.getLocalBounds().width + (2*size), size * 1.5f));
    mBorder.setFillColor(sf::Color::Transparent);
    mBorder.setOutlineColor(sf::Color::Transparent);
    mBorder.setOutlineThickness(0);


    if (toogle) mEffect = Effect::TOGGLE_LOOP;
    if (highlighted) {
        mEffect = Effect::HIGHLIGHTED;
    
        mText.setOutlineColor(sf::Color(255,255,255,25));
    
    }
    Utility::centerOrigin(mBorder);
    Utility::centerOrigin(mText);
}

bool Label::update(sf::Time dt) 
{
    mTextEffectTime += dt;
    
        switch (mEffect)
        {
            case TOGGLE_LOOP:
            {
                if (mTextEffectTime >= sf::seconds(0.5f))
                {
                   if (isActive()) deactivate();
                        else  activate();
                    mTextEffectTime = sf::Time::Zero;
                }
                break;
                
            }
                
            
            case HIGHLIGHTED:
            {
                float thickness = mTextEffectTime.asSeconds();
                mText.setOutlineThickness(15 + thickness);
                if (mTextEffectTime >= sf::seconds(5.0f)) mTextEffectTime = sf::Time::Zero;
                break;

            }
        }

    return true;
}

void Label::handleEvent(const sf::Event& event)
{

}

bool Label::isSelectable () const
{
    return false;
}

void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
    states.transform *= getTransform();
    if (mBorder.getFillColor() != sf::Color::Transparent)
        target.draw(mBorder, states);
	
    target.draw(mText, states);
}

void Label::setBorder(sf::Color borderColor, sf::Color outline, int outlineSize)
{
    mBorder.setFillColor(borderColor);
    mBorder.setOutlineColor(outline);
    mBorder.setOutlineThickness(outlineSize);
}