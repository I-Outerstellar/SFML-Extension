#pragma once

namespace GameObjects {

	/// <summary>
	/// Implement for representing drawable game objects.
	/// </summary>
	class GameDrawable {
	protected:
		unsigned int zIndex = 0;
	public:
		bool visible = true;
		/// <summary>
		/// Gets the Z-Index of the drawable object.
		/// </summary>
		/// <returns></returns>
		unsigned int getZIndex() const { return this->zIndex; }

		/// <summary>
		/// Draws the game object.
		/// </summary>
		virtual void draw() = 0;
		virtual ~GameDrawable() = default;
		void operator=(GameDrawable drawable) = delete;
	};

}