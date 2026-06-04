#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        // get main menu
        auto mainMenu = this->getChildByID("main-menu");
        if (!mainMenu)
            return true;

        // get buttons
        auto playBtn = mainMenu->getChildByID("play-button");
        auto editorBtn = mainMenu->getChildByID("editor-button");

        // check if buttons exist and mod is enabled
        if (
            playBtn &&
            editorBtn &&
            Mod::get()->getSettingValue<bool>("toggle")
        ) {

            // save positions
            CCPoint playPos = playBtn->getPosition();
            CCPoint editorPos = editorBtn->getPosition();

            // save ORIGINAL scales
            float playScale = playBtn->getScale();
            float editorScale = editorBtn->getScale();

            // make anchor points consistent
            playBtn->setAnchorPoint({ 0.5f, 0.5f });
            editorBtn->setAnchorPoint({ 0.5f, 0.5f });

            // swap positions
            playBtn->setPosition(editorPos);
            editorBtn->setPosition(playPos);

            // swap scales too
            playBtn->setScale(editorScale);
            editorBtn->setScale(playScale);

            // refresh sizes
            playBtn->setContentSize(playBtn->getScaledContentSize());
            editorBtn->setContentSize(editorBtn->getScaledContentSize());
        }

        return true;
    }
};
