#include <memory>
#include <vector>
#include <algorithm>
#include <cassert>
#include "SFML/Graphics.hpp"
class SceneNode: 
    public sf::Transformable, 
    public sf::Drawable,
    private sf::NonCopyable
{
    public:
    typedef std::unique_ptr<SceneNode> Ptr;
    SceneNode();
    private:
        std::vector<Ptr> mChildren;
        SceneNode       *mParent;

        void  attachChild(Ptr child);
        Ptr detachChild(const SceneNode& node);


        virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;

        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
};