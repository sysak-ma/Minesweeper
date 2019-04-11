#include "MenuScene.hpp"
#include "source/UIObjects/Buttons/Button.hpp"
#include "source/UIObjects/Buttons/FunnyButton.h"
#include "SceneEvent.hpp"

#include "source/UIObjects/DrawArray.h"

#include <vector>

int MenuScene::process() {
    for(int i = 0; i < uiobjects.size(); i++) {
        uiobjects[i]->process();
    }

    std::queue<SceneEvent> *events = UIinformation::events;

    while(!events->empty()) {
        SceneEvent event = events->front();
        events->pop();
        if (event.eCode == SceneEvent::Pressed && event.id == Events::Exit) {
            changeTo = UIinformation::Scenes::Exit;
        } else if (event.eCode == SceneEvent::Pressed && event.id == Events::Play) {
            //changeTo = ???;
        }
    }

    draw();

    return 0;
}

int MenuScene::draw() {
    //???
}

MenuScene::MenuScene() : Scene() {
    for(int i = 0; i < 2; i++)
        textures.emplace_back(sf::Texture());
    textures[Textures::BackGroundT].loadFromFile("../textures/MainMenu/MainMenuBG.jpg");
    textures[Textures::ButtonsT].loadFromFile("../textures/MainMenu/buttons.png");

    sf::Font font;
    font.loadFromFile("../fonts/arial.ttf");
    fonts.emplace_back(font);

    DrawArray::setLayerTexture(0, &textures[Textures::BackGroundT]);
    std::vector<sf::Vertex> vertex;
    vertex.emplace_back(sf::Vertex(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f)));
    vertex.emplace_back(sf::Vertex(sf::Vector2f(1920.f, 0.f), sf::Vector2f(1920.f, 0.f)));
    vertex.emplace_back(sf::Vertex(sf::Vector2f(1920.f, 1080.f), sf::Vector2f(1920.f, 1080.f)));
    vertex.emplace_back(sf::Vertex(sf::Vector2f(0.f, 1080.f), sf::Vector2f(0.f, 1080.f)));
    BGid = DrawArray::addToLayer(0, vertex);

    sf::Text textBG("Stratagy game", fonts[0], 180);
    textBG.setFillColor(sf::Color::Red);
    HeadTextid = DrawArray::addTextToLayer(0, textBG);
    DrawArray::updateText(HeadTextid, sf::Vector2f(sf::Vector2i(1920, 0) / 2
    - sf::Vector2i(DrawArray::getTextSize(HeadTextid).x, -100) / 2));

    sf::Text text("Play", fonts[0], 120);
    text.setFillColor(sf::Color::White);
    std::vector<sf::Vector2i> vect = {DrawArray::addTextToLayer(1, text)};
    DrawArray::setLayerTexture(1, &textures[Textures::ButtonsT]);
    std::vector<sf::Vector2i> vec = {DrawArray::addToLayer(1, sf::IntRect(22, 12, 16, 8), sf::IntRect(0, 0, 2, 1))};
    uiobjects.push_back(new FunnyButton(Events::Play, &vec, &vect));

    text = sf::Text("Exit", fonts[0], 120);
    text.setFillColor(sf::Color::White);
    std::vector<sf::Vector2i> vec2t = {DrawArray::addTextToLayer(1, text)};
    std::vector<sf::Vector2i> vec2 = {DrawArray::addToLayer(1, sf::IntRect(22, 22, 16, 8), sf::IntRect(0, 1, 2, 1))};
    uiobjects.push_back(new FunnyButton(Events::Exit, &vec2, &vec2t));
}

