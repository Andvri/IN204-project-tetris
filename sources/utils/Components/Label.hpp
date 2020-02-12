#ifndef LABEL_CLASS
#define LABEL_CLASS
#include "Component.hpp"
#include "SFML/Graphics.hpp"


enum Effect {
    NONE,
    TOGGLE_LOOP,
    HIGHLIGHTED
};

/**
 * @brief compiles within itself the tools to create a label through SFML
 * 
 */
class Label
    : public Component
{
public:
    
    /**
     * @brief Construct a new Label object, standart constructor, get all the information you need to get it started
     * 
     * @param text needed into label
     * @param path font path
     * @param activate visible or not
     * @param size text size
     * @param toogle 
     * @param highlighted 
     * @param color 
     */
    Label(const std::string& text, const std::string& path, bool activate, float size, bool toogle = false, bool highlighted = false, const sf::Color color = sf::Color::White);
    
    /**
     * @brief Open for check-in implementations
     * 
     * @return true 
     * @return false 
     */
    virtual bool		isSelectable() const;

    /**
     * @brief Set the Text object
     * 
     * @param text 
     */
    void				setText(const std::string& text);

    /**
     * @brief Responsible for the effects of the texts, such as shining or even appearing with outline
     * @param dt Fraction of time
     * @return true 
     * @return false if have a problem
     */
    virtual bool		update(sf::Time dt);
    
    /**
     * @brief Here in case you need an implementation
     * 
     * @param event getted action
     */
    virtual void		handleEvent(const sf::Event& event);

    /**
     * @brief Set the Border object
     * 
     * @param borderColor 
     * @param outline 
     * @param outlineSize 
     */
    void                setBorder(sf::Color borderColor, sf::Color outline, int outlineSize);
private:

    /**
     * @brief put the borders on the label
     * 
     * @param target 
     * @param states 
     */
    void				draw(sf::RenderTarget& target, sf::RenderStates states) const;
private: 
    sf::Text			    mText;
    sf::Font                mFont;
    sf::Time                mTextEffectTime;
    sf::Color               mColor;
    Effect                  mEffect;
    sf::RectangleShape      mBorder;

    /**
     * @brief cCnters the elements
     * 
     * @param void
     */
    void                    centerToOrigin();
};

#endif