#include "Button.hpp"
#include "../Utility.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


Button::Button(const std::string& text, const std::string& path,bool active, float size, bool pred) :
    Component(),
    mText(),
    mFont(),
    mSoundToggle(),
    mSoundSelect(),
    mBufferSoundSelect(),
    mBufferSoundToggle(),
    mBackground(),
    mActive(false)
{
    if (active) activate();
    if(!mFont.loadFromFile(path))
	{
	}

    if(!mBufferSoundToggle.loadFromFile("media/music/move-me-too.ogg"))
	{
	}
    mSoundToggle.setBuffer(mBufferSoundToggle);

    if(!mBufferSoundSelect.loadFromFile("media/music/select-when.ogg"))
	{
	}
    mSoundSelect.setBuffer(mBufferSoundSelect);


    mText.setFont(mFont);
    mText.setString(text);
    mText.setCharacterSize(size);
    mText.setOutlineColor(sf::Color(255,255,255,50));
    Utility::centerOrigin(mText);



    if(pred) 
    {
        mActive = pred;
        mText.setOutlineThickness(8);
    };
}

void Button::setCallback(Callback callback)
{
	mCallback = std::move(callback);
}

void Button::setText(const std::string& text)
{
	mText.setString(text);
	Utility::centerOrigin(mText);
}

bool Button::isSelectable() const
{
    return true;
}

void Button::select()
{
	Component::select();
    mText.setOutlineThickness(8);
    mSoundSelect.play();
    if (mCallback && mActive) mCallback();
}

void Button::deselect()
{
	Component::deselect();
    mText.setOutlineThickness(0);
}

void Button::activate()
{
	Component::activate();
    
    /**
     *  TODO: In the future place here what to do when selected 
     *  and activated or deactivated 
     */
}

void Button::deactivate()
{
	Component::deactivate();
    /**
     *  TODO: In the future place here what to do when selected 
     *  and activated or deactivated 
     */
}

void Button::handleEvent(const sf::Event&)
{
    
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(mText, states);
}

bool Button::update(sf::Time dt) 
{}

void Button::toggle()
{
    mText.setOutlineThickness((!mActive) ? 10 : 0);
    if(!mActive) mSoundToggle.play();
    mActive = !mActive;
}