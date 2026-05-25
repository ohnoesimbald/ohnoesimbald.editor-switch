#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
using namespace geode::prelude;

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;
        auto mainMenu = this->getChildByID("main-menu");
        if (!mainMenu) return true;
        auto playBtn = mainMenu->getChildByID("play-button");
        auto editorBtn = mainMenu->getChildByID("editor-button");
        if (playBtn && editorBtn && Mod::get()->getSettingValue<bool>("toggle")) {        //the button thingy that toggles the mod
            auto playPos = playBtn->getPosition();
            auto editorPos = editorBtn->getPosition();
            playBtn->setPosition(editorPos);          //makes the play button switch places with the editor
            editorBtn->setPosition(playPos);
        }
        return true;
    }
};
