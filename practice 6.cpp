#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    int cellSize = 40;
    const int gridSize = 10;

    RenderWindow window(VideoMode(400, 400), "grid");

    RectangleShape cells[gridSize][gridSize];

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                cells[i][j].setSize(Vector2f(cellSize - 2, cellSize - 2));
                cells[i][j].setPosition(i * cellSize, j * cellSize);
                cells[i][j].setFillColor(Color::Black);
                cells[i][i].setOutlineColor(Color::White);
                cells[i][j].setOutlineThickness(1);

                if (i == gridSize/2 - 1 and j == gridSize/2 - 1 || i == gridSize / 2 and j == gridSize / 2 || i == gridSize / 2 - 1 and j == gridSize / 2 || i == gridSize / 2 and j == gridSize / 2 - 1)
                    cells[i][j].setFillColor(Color::Green);

                window.draw(cells[i][j]);
            }
        }
        window.display();
    }
    return 0;
}