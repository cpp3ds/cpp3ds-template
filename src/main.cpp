#include <cpp3ds/Graphics.hpp>
#include <cpp3ds/Window.hpp>

using namespace cpp3ds;

// Minimal derived Game class necessary for cpp3ds games
class MyGame: public Game {
private:
	Text text;
public:
	MyGame() {
		// Constructor for setting up initial game objects
		text.setColor(Color::Green);
		text.setCharacterSize(40);
		text.setString("Hello World");
	}

	~MyGame() {
		// Destructor called when game exits
	}

	void update(float delta) {
		// Update game state based on frame time delta
	}

	void processEvent(Event& event) {
		// Check for input Events here
	}

	void renderTopScreen(Window& window) {
		window.clear();
		window.draw(text);
	}

	void renderBottomScreen(Window& window) {
		window.clear();
	}
};

int main(int argc, char** argv) {
	MyGame game;
	game.console(BottomScreen); // Console for reading stdout
	game.run();
	return 0;
}