#ifndef BUTTON_CLASS
#define BUTTON_CLASS
#include "Component.hpp"
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>

#include <functional>

/**
 * @brief abstraction of a button component to implement in the view
 * 
 */
class Button
    : public Component
{
public:
    typedef std::function<void()>		Callback;

public:
    
    /**
     * @brief Construct a new Button object
     * 
     * @param text button text
     * @param path font path
     * @param active visible or not
     * @param size 
     * @param pred selected or not
     */
    Button(const std::string& text, const std::string& path,bool active, float size, bool pred = false);

    /**
     * @brief Set the Text object
     * 
     * @param text 
     */
    void				setText(const std::string& text);

    /**
     * @brief Set the Callback function in which the button will then activate
     * 
     * @param callback 
     */
    void				setCallback(Callback callback);

    /**
     * @brief Return state of selecting
     * 
     * @return true 
     * @return false 
     */
    virtual bool		isSelectable() const;

    /**
     * @brief changes the button layout and plays selection music
     * 
     */
    virtual void		select();

    /**
     * @brief deselect the button
     * 
     */
    virtual void		deselect();
    
    /**
     * @brief Alternate button status and play switching music
     * 
     */
    void                toggle();
    
    /**
     * @brief Take action if this going to be activate
     * unimplemented
     */
    virtual void        activate();

    /**
     * @brief Take action if this going to be activate
     * unimplemented
     */
    virtual void        deactivate();
    virtual bool		update(sf::Time dt);

    virtual void		handleEvent(const sf::Event& event);
    
private:

    /**
     * @brief draw add-ons for the button
     * 
     * @param target 
     * @param states 
     */
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