#include "GUI.hpp"

int main() {
	GUI *_gui = new GUI();
	
	_gui->run();

	delete _gui;

	return 0;
}
