#ifndef COMPONENT_CLASS
#define COMPONENT_CLASS


#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include <memory>

namespace sf
{
	class Event;
}

/**
 * @brief Mother class for the components created, which compiles SFML functions
 * 
 */
class Component : 
    public sf::Drawable, 
    public sf::Transformable, 
    private sf::NonCopyable

{

	public:
        /**
         * @brief Construct a new Component object
         * 
         */
							Component();
        virtual				~Component();

        /**
         * @brief get a confirmation bool
         * 
         * @return the state  
         */
        virtual bool		isSelectable() const = 0;

        /**
         * @brief get a confirmation bool
         * 
         * @return the state  
         */
		bool				isSelected() const;

        /**
         * @brief select the component
         * 
         */
        virtual void		select();

        /**
         * @brief deselect the component
         * 
         */
        virtual void		deselect();

        /**
         * @brief get a confirmation bool
         * 
         * @return the state  
         */
        virtual bool		isActive() const;

        /**
         * @brief active the component
         * 
         */
        virtual void		activate();

        /**
         * @brief deactive the component
         * 
         */
        virtual void		deactivate();
        virtual bool        update(sf::Time dt) = 0;
        virtual void		handleEvent(const sf::Event& event) = 0;


    private:
        bool				mIsSelected;
        bool				mIsActive;
};


#endif