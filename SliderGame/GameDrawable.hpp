#pragma once

class GameDrawable {
public:
	virtual void draw() = 0;
	virtual ~GameDrawable() = default;
};