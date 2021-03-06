#ifndef SFUI_BUTTON_HPP
#define SFUI_BUTTON_HPP

#include "Widget.hpp"
#include "Utils/ItemBox.hpp"

namespace SFUI
{

// FIXME: if you click a button, then drag and release elsewhere, 
// and click again without moving the mouse after releasing it will trigger a button press.

// Simple press button.
// A callback is triggered when the button is activated.
class Button : public Widget
{
public:
	Button(const sf::String& string);

	// Set the displayed button label
	void setString(const sf::String& string);
	// Return the displayed button label.
	const sf::String& getString() const;

	// callbacks 
	void onStateChanged(State state);
	void onMouseMoved(float x, float y);
	void onMouseReleased(float x, float y);
	void onKeyPressed(sf::Keyboard::Key key);
	void onKeyReleased(sf::Keyboard::Key key);

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	ItemBox<sf::Text> m_box;
};

}

#endif // !SFUI_BUTTON_HPP
