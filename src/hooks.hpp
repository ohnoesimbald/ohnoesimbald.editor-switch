#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    void onPlayButton(CCObject* sender) {
        MenuLayer::onPlayButton(sender);

        CCApplication::sharedApplication()->applicationDidEnterBackground();
    }
};
