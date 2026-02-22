#include "GameShape.hpp"
#include <memory>

class GameRectangle : public GameShape, public sf::RectangleShape {
protected:
	GameRectangle() {}
public:
	bool visible = true;

	static std::shared_ptr<GameRectangle> create();

	virtual bool intersects(sf::Shape& shape) override;
	virtual void draw() override;
};