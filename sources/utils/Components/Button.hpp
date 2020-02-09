#ifndef BUTTON_CLASS
#define BUTTON_CLASS
#include "Component.hpp"
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>

#include <functional>

class Button
    : public Component
{
private:
    /* data */

public:
    typedef std::function<void()>		Callback;

public:
    

    Button(const std::string& text, const std::string& path,bool active, float size);

    void				setText(const std::string& text);
    void				setCallback(Callback callback);

    virtual bool		isSelectable() const;
    virtual void		select();
    virtual void		deselect();
    virtual void        activate();
    virtual void        deactivate();
    virtual bool		update(sf::Time dt);

    virtual void		handleEvent(const sf::Event& event);
    
private:
    void				draw(sf::RenderTarget& target, sf::RenderStates states) const;
private: 
    sf::Text			    mText;
    sf::Font                mFont;
    sf::Texture             mBackground;
    Callback				mCallback;
    sf::SoundBuffer         mBufferSound;
    sf::Sound               mSound;
};

#endif