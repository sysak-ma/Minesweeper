#include "Core.hpp"

bool Core::stoped = false;

int Core::initCore() {}
/*
int Core::processMessage(ICMessage m) {
    if (m.type == ICMessage::types::endStep) {
        stop();
        printf(" \" Core \": Caught message from Interface\n");
        return 1;
        // break;
    } else if (m.type == ICMessage::types::changeUnit) {
        if (m.newState == Unit::states::Moving) {
            if (GameInformation::playMap[m.destination1][m.destination2].occupied) {
                GameInformation::CoreIntQ.push(ICMessage(ICMessage::types::actionError, -1, -1, -1, -1));
                //    continue;
            } else {
                GameInformation::CoreIntQ.push(ICMessage(ICMessage::types::moveUnit, m.id, -1, m.destination1, m.destination2));
            }
        } else if (m.newState == Unit::states::Attacking) {
            if (!GameInformation::playMap[m.destination1][m.destination2].occupied) {
                GameInformation::CoreIntQ.push(ICMessage(ICMessage::types::actionError, -1, -1, -1, -1));
                //    continue;
            } else {
                if (GameInformation::playMap[m.destination1][m.destination2].occupierType) {
                    GameInformation::buildings[GameInformation::playMap[m.destination1][m.destination2].occupierId].HP--;
                } else {
                    GameInformation::units[GameInformation::playMap[m.destination1][m.destination2].occupierId].HP--;
                }
            }
        }
    } else if (m.type == ICMessage::types::changeBuilding) {
        //GameInformation::buildings[m.id].state = m.newState;
    } else if (m.type == ICMessage::types::movedUnit) {
        GameInformation::units[m.id].state = Unit::states::Idle;
        GameInformation::playMap[GameInformation::units[m.id].x][GameInformation::units[m.id].y].occupied = false;
        GameInformation::units[m.id].y = m.destination2;
        GameInformation::units[m.id].x = m.destination1;
        GameInformation::playMap[m.destination1][m.destination2].occupied = true;
        GameInformation::playMap[m.destination1][m.destination2].occupierType = 0;
        GameInformation::playMap[m.destination1][m.destination2].occupierId = m.id;
    }
}
*/

/*int Core::processMessage(ICMessage m) {
    if (m.type == ICMessage::typesI::endStep) {
        stop();
        printf(" \" Core \": Caught message from Interface\n");
        return 1;
        // break;
    } else if (m.type == ICMessage::typesI::changeUnit) {
        GameInformation::CoreIntQ.push(ICMessage(ICMessage::typesC::actionError, -1, -1, -1, -1));
    }
}*/

int Core::run() {
    while(!stoped) {
        //printf("Hey from Core\n");
        sf::sleep(sf::milliseconds(30));
        /*while (true) {
            if (!GameInformation::IntCoreQ.empty()) {
                ICMessage m = GameInformation::IntCoreQ.front();
                GameInformation::IntCoreQ.pop();
                if (processMessage(m)) break;
            }
            sf::sleep(sf::milliseconds(30));
        }*/
    }
}

int Core::stop() {
    stoped = true;
}