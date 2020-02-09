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

class Component : 
    public sf::Drawable, 
    public sf::Transformable, 
    private sf::NonCopyable

{

	public:
							Component();
        virtual				~Component();

        virtual bool		isSelectable() const = 0;
		bool				isSelected() const;
        virtual void		select();
        virtual void		deselect();

        virtual bool		isActive() const;
        virtual void		activate();
        virtual void		deactivate();
        virtual void        uupdate(sf::Time dt) = 0;
        virtual void		handleEvent(const sf::Event& event) = 0;


    private:
        bool				mIsSelected;
        bool				mIsActive;
};


#endif