#pragma once

class GameDrawable {
protected:
	unsigned int zIndex = 0;
public:
	unsigned int getZIndex() const { return this->zIndex; }

	virtual void draw() = 0;
	virtual ~GameDrawable() = default;
	void operator=(GameDrawable drawable) = delete;
};