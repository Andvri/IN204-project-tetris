#include "Label.hpp"
#include "../Utility.hpp"


Label::Label(const std::string& text, const std::string& path, bool active, float size, bool toogle, bool highlighted)
    : Component(),
    mEffect(NONE)
{
    if (active) activate();
    if(!mFont.loadFromFile(path))
	{
	}
    mText.setFont(mFont);
    mText.setString(text);
    mText.setCharacterSize(size);

    if (toogle) mEffect = Effect::TOGGLE_LOOP;
    if (highlighted) mEffect = Effect::HIGHLIGHTED;
    Utility::centerOrigin(mText);
}

bool Label::update(sf::Time dt) 
{
    mTextEffectTime += dt;
    if (mTextEffectTime >= sf::seconds(0.5f))
    {
        switch (mEffect)
        {
            case TOGGLE_LOOP:
            {
                if (isActive()) deactivate();
                    else  activate();
                break;
            }
                
            
            case HIGHLIGHTED:
            {

                break;

            }
        }

        mTextEffectTime = sf::Time::Zero;
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

void Label::draw(sf::RenderTarget&, sf::RenderStates) const 
{

}