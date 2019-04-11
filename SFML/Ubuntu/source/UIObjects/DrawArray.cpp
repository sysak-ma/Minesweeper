#include <source/UIObjects/UIinformation.h>
#include "DrawArray.h"

const int DrawArray::N = 3;

std::vector<sf::VertexArray> DrawArray::layers(N, sf::VertexArray(sf::Quads));
std::vector<std::vector<sf::Text>> DrawArray::texts(N, std::vector<sf::Text>());
std::vector<sf::Texture *> DrawArray::textures(N, NULL);

sf::Vector2i DrawArray::addTextToLayer(int layer, sf::Text& text) {
    texts[layer].emplace_back(text);
    return sf::Vector2i(layer, texts[layer].size() - 1);

}

int DrawArray::updateText(sf::Vector2i _id, sf::Vector2f pos) {
    int layer = _id.x;
    int id = _id.y;
    texts[layer][id].setPosition(pos);
}

sf::Vector2i DrawArray::getTextSize(sf::Vector2i id) {
    sf::FloatRect rect = texts[id.x][id.y].getLocalBounds();
    return sf::Vector2i(rect.width, 4.0 / 3.0 * texts[id.x][id.y].getCharacterSize());
}

sf::Vector2i DrawArray::addToLayer(int layer, sf::IntRect rectPos, sf::IntRect rectText) {
    int a = 1;
    layers[layer].append(sf::Vertex(sf::Vector2f(a * rectPos.left, a * rectPos.top), sf::Vector2f(a * rectText.left, a * rectText.top)));
    layers[layer].append(sf::Vertex(sf::Vector2f(a * (rectPos.left + rectPos.width), a * rectPos.top), sf::Vector2f(a * (rectText.left + rectText.width), a * rectText.top)));
    layers[layer].append(sf::Vertex(sf::Vector2f(a * (rectPos.left + rectPos.width), a * (rectPos.top + rectPos.height)), sf::Vector2f(a * (rectText.left + rectText.width), a * (rectText.top + rectText.height))));
    layers[layer].append(sf::Vertex(sf::Vector2f(a * rectPos.left, a * (rectPos.top + rectPos.height)), sf::Vector2f(a * rectText.left, a * (rectText.top + rectText.height))));
    return sf::Vector2i(layer, (layers[layer].getVertexCount() / 4) - 1);
}

sf::Vector2f DrawArray::getPos(sf::Vector2i id) {
    return sf::Vector2f(layers[id.x][4 * id.y].position);
}

sf::Vector2i DrawArray::getSize(sf::Vector2i id) {
    return sf::Vector2i(layers[id.x][4 * id.y + 2].position) - sf::Vector2i(layers[id.x][4 * id.y].position);
}

sf::IntRect DrawArray::getSourceRect(sf::Vector2i id) {
    sf::Vector2i pos = sf::Vector2i(layers[id.x][id.y].texCoords);
    sf::Vector2i size = sf::Vector2i(layers[id.x][id.y + 2].texCoords) - pos;
    sf::IntRect(pos.x, pos.y, size.x, size.y);
}

int DrawArray::update(sf::Vector2i id, sf::Vector2f pos) {
    sf::Vector2f size = layers[id.x][4 * id.y + 2].position - layers[id.x][4 * id.y].position;
    layers[id.x][4 * id.y].position = sf::Vector2f(pos);
    layers[id.x][4 * id.y + 1].position = sf::Vector2f(pos) + sf::Vector2f(size.x, 0.f);
    layers[id.x][4 * id.y + 2].position = sf::Vector2f(pos) + size;
    layers[id.x][4 * id.y + 3].position = sf::Vector2f(pos) + sf::Vector2f(0.f, size.y);
}

sf::Vector2i DrawArray::addToLayer(int layer, std::vector<sf::Vertex> &pos) {
    for (int i = 0; i < 4; i++) {
        layers[layer].append(pos[i]);
    }
    return sf::Vector2i(layer, layers[layer].getVertexCount() / 4 - 1);
}

int DrawArray::setLayerTexture(int layer, sf::Texture *texture) {
    textures[layer] = texture;
}

int DrawArray::draw() {
    for(int i = 0; i < N; i++) {
        UIinformation::window->draw(layers[i], textures[i]);
        for(int j = 0; j < texts[i].size(); j++) {
            UIinformation::window->draw(texts[i][j]);
        }
    }
}
