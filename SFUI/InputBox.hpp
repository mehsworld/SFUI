#ifndef SFUI_TEXTBOX_HPP
#define SFUI_TEXTBOX_HPP

#include "Widget.hpp"
#include "Utils/Box.hpp"

// TODO: support lots of text
// TODO: setRows(int rowCount);
//		 amount of rows in the editor

// TODO: Text cursor

// TODO: support text editing stuff
// Undo
// Redo
// Select
// Select Word
// Select All
// Move selected

namespace SFUI
{

 // Single-line text editor.
class InputBox : public Widget
{
public:
	InputBox(float width = 200.f);

	void setText(const sf::String& string);
	const sf::String& getText() const;

	bool isEmpty() const;

	void setCursorPosition(size_t index);
	size_t getCursorPosition() const;

	void setBlinkPeriod(float period);
	float getBlinkPeriod() const;

protected:
	// Callbacks
	void onKeyPressed(sf::Keyboard::Key key);
	void onMousePressed(float x, float y);
	void onTextEntered(sf::Uint32 unicode);

	// FIXME: sometimes these keep the hovered state
	void onStateChanged(State state);

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	Box         m_box;

	std::string m_oldText;
	sf::Text    m_text;

	mutable sf::RectangleShape m_cursor;
	mutable sf::Clock  m_cursor_timer;
	float			   m_blink_period;
	// TODO: add cursor delay (.25s)

	size_t m_max_characters;
	size_t m_cursor_pos;
};

}

#endif // !SFUI_TEXTBOX_HPP
