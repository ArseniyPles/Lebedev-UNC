#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>
#include <cmath>

using namespace sf;
using namespace std;


void drawGraph(sf::RenderWindow& window, std::function<float(float)> func, float xMin, float xMax, float scaleX, float scaleY, sf::Color color) {
    sf::VertexArray graph(sf::LinesStrip);

    for (float x = xMin; x <= xMax; x += 0.1f) {
        float y = func(x); // Вычисление значения функции

        // Преобразование координат в экранные
        float screenX = 400 + x * scaleX;
        float screenY = 300 - y * scaleY;

        // Добавление точки в массив вершин
        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
    }

    window.draw(graph);
}

int main()
{
    RenderWindow window(VideoMode(800, 600), "Graph control");


    CircleShape userPoint(5);
    userPoint.setFillColor(Color::Red);
    bool userPointExists = false;


    Font font;
    font.loadFromFile("timesnewromanps_italicmt.ttf");

    Text coordinatesText;
    coordinatesText.setFont(font);
    coordinatesText.setFillColor(Color::White);
    coordinatesText.setCharacterSize(20);
    coordinatesText.setPosition(10, 10);


    // Оси X и Y
    sf::VertexArray xAxis(Lines, 2);
    xAxis[0].position = Vector2f(50, 300); // Начало оси X
    xAxis[0].color = Color::White; // Цвет оси
    xAxis[1].position = Vector2f(750, 300); // Конец оси X
    xAxis[1].color = Color::White;

    sf::VertexArray yAxis(Lines, 2);
    yAxis[0].position = Vector2f(400, 50); // Начало оси Y
    yAxis[0].color = Color::White; // Цвет оси
    yAxis[1].position = Vector2f(400, 550); // Конец оси Y
    yAxis[1].color = Color::White;


    string section;
    while (window.isOpen()) {
        Event event;

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            // Проверка клика мышью
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    // Получение позиции клика
                    Vector2i mousePos = Mouse::getPosition(window);
                    
                    // Преобразование экранных координат в "математические"
                    float mathX = (mousePos.x - 400) / 30.0f;
                    float mathY = -(mousePos.y - 300) / 100.0f;
                    
                    // Установка новой пользовательской точки
                    userPoint.setPosition(mousePos.x - userPoint.getRadius(), mousePos.y - userPoint.getRadius());
                    userPointExists = true; // Помечаем, что точка существует
                    
                    double y = round(mathY);
                    double x = round(mathX);

                    if (y == -3*x + 1 and y == 2*x - 1)
                        section = "Granica";

                    if (y < 2*x - 1 and y > -3*x + 1)
                        section = "1";
                    else if (y < -3*x + 1 and y < 2*x - 1)
                        section = "2";
                    else if (y > -3 * x + 1 and y > 2 * x - 1)
                        section = "3";
                    else if (y < -3*x + 1 and y > 2*x - 1)
                        section = "4";
                    
                    // Обновление текста с координатами точки
                    coordinatesText.setString("Coordinates: (" + std::to_string(mathX) + ", " + std::to_string(mathY) + ") Position: " + section);
                    
                }

            }
        }

        window.clear();

        // Отрисовка осей
        window.draw(xAxis);
        window.draw(yAxis);

        drawGraph(window, [](float x) { return -3*x + 1; }, -10, 10, 30, 10, sf::Color::Blue);

        drawGraph(window, [](float x) { return 2*x - 1; }, -10, 10, 30, 10, sf::Color::Red);

        if (userPointExists) {
            window.draw(userPoint);
            window.draw(coordinatesText);
        }

        window.display();
    }

    return 0;
}