#include "SFML/Graphics.hpp"
#include "GameDrawable.hpp"

class GameShape : public GameDrawable {
private:

public:
	virtual bool intersects(sf::Shape& shape) = 0;
};