#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <chrono>
#include <random>
#include <memory>
#include "SortAlgorithms.h" 
#include "Render.h"

using namespace std;

const unsigned int WIDTH = 1920;
const unsigned int HEIGHT = 720;

int main() {
	// Initialize the Window
	std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>(sf::VideoMode({ WIDTH, HEIGHT }), "Algorithm Visualizer");
	//window->setFramerateLimit(60);

	std::vector<int> data(100);
	std::srand(std::time(0));
	int speed = 15;


	for (int& num : data) {
		num = rand() % 100 + 1;
	}
	Render render(WIDTH, HEIGHT, data);
    HeapSort sorter;

	bool isSorting = false;

	while (window->isOpen()) {
		while (const std::optional event = window->pollEvent()) {
			if (event->is <sf::Event::Closed>()) {
				window->close();
			}

			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
				if (keyPressed->scancode == sf::Keyboard::Scancode::Space) {
					isSorting = !isSorting; 
				} 
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
					window->close();
				}

			}
			window->clear();
			render.drawArray(*window);
			if (isSorting) {
				sorter.sort(data, render, *window, speed);
				isSorting = false;
			}
		}
	}

    


    return 0;
}



