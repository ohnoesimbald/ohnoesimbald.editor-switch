#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        auto mainMenu = this->getChildByID("main-menu");
        if (!mainMenu)
            return true;

        auto playBtn = mainMenu->getChildByID("play-button");
        auto editorBtn = mainMenu->getChildByID("editor-button");

        if (
            playBtn &&
            editorBtn &&
            Mod::get()->getSettingValue<bool>("toggle")
        ) {

            // save positions
            CCPoint playPos = playBtn->getPosition();
            CCPoint editorPos = editorBtn->getPosition();

            // swap positions
            playBtn->setPosition(editorPos);
            editorBtn->setPosition(playPos);

            // force visual scaling manually
            playBtn->setScale(0.55f);
            editorBtn->setScale(0.9f);

            // fix anchor points
            playBtn->setAnchorPoint({ 0.5f, 0.5f });
            editorBtn->setAnchorPoint({ 0.5f, 0.5f });
        }

        return true;
    }
};
