#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PlayerObject.hpp>
using namespace geode::prelude;

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;
        auto mainMenu = this->getChildByID("main-menu");
        if (!mainMenu) return true;
        auto playBtn = mainMenu->getChildByID("play-button");
        auto editorBtn = mainMenu->getChildByID("editor-button");
        if (playBtn && editorBtn && Mod::get()->getSettingValue<bool>("toggle")) {
            auto playPos = playBtn->getPosition();
            auto editorPos = editorBtn->getPosition();
            playBtn->setPosition(editorPos);
            editorBtn->setPosition(playPos);
        }
        return true;
    }
};

class $modify(PlayerObject) {
    void playerDestroyed(bool p0) {
        PlayerObject::playerDestroyed(p0);
        if (Mod::get()->getSettingValue<bool>("joke")) {
            FMODAudioEngine::get()->playEffect("ohnoesimbald.editor-switch/lobotomy-sound-effect.ogg");

            auto scene = CCDirector::get()->getRunningScene();
            auto image = CCSprite::create("ohnoesimbald.editor-switch/soggy imagae.png");
            if (image) {
                auto size = CCDirector::get()->getWinSize();
                image->setPosition({size.width / 2, size.height / 2});
                image->setScale(size.width / image->getContentSize().width);
                image->setZOrder(999);
                scene->addChild(image);
                image->runAction(CCSequence::create(
                    CCDelayTime::create(2.0f),
                    CCRemoveSelf::create(),
                    nullptr
                ));
            }
        }
    }
};
