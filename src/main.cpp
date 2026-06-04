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

        if (playBtn && editorBtn && Mod::get()->getSettingValue<bool>("toggle")) {

            // save positions
            CCPoint playPos = playBtn->getPosition();
            CCPoint editorPos = editorBtn->getPosition();

            // reset scales first
            playBtn->setScale(1.f);
            editorBtn->setScale(1.f);

            // swap positions
            playBtn->setPosition(editorPos);
            editorBtn->setPosition(playPos);

            // THEN apply scaling
            playBtn->setScale(0.65f);
            editorBtn->setScale(0.5f);

            // update visuals
            playBtn->setContentSize(playBtn->getScaledContentSize());
            editorBtn->setContentSize(editorBtn->getScaledContentSize());
        }

        return true;
    }
};
