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
    

    Button(const std::string& text, const std::string& path,bool active, float size, bool pred = false);

    void				setText(const std::string& text);
    void				setCallback(Callback callback);

    virtual bool		isSelectable() const;
    virtual void		select();
    virtual void		deselect();
    
    void                toggle();
    
    
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
    sf::SoundBuffer         mBufferSoundSelect;
    sf::Sound               mSoundSelect;
    sf::SoundBuffer         mBufferSoundToggle;
    sf::Sound               mSoundToggle;
    bool                    mActive;
};

#endif