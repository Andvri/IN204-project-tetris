#ifndef LABEL_CLASS
#define LABEL_CLASS
#include "Component.hpp"
#include "SFML/Graphics.hpp"

enum Effect {
    NONE,
    TOGGLE_LOOP,
    HIGHLIGHTED
};


class Label
    : public Component
{
private:
    /* data */


public:
    

    Label(const std::string& text, const std::string& path, bool activate, float size, bool toogle = false, bool highlighted = false);
    virtual bool		isSelectable() const;
    void				setText(const std::string& text);
    virtual bool		update(sf::Time dt);
    virtual void		handleEvent(const sf::Event& event);
    
private:
    void				draw(sf::RenderTarget& target, sf::RenderStates states) const;
private: 
    sf::Text			    mText;
    sf::Font                mFont;
    sf::Time                mTextEffectTime;
    Effect                  mEffect;
};

#endif