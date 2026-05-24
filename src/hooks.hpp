#include <Geode/modify/MenuLayer.hpp>
using namespace geode::prelude;
class (MenuLayer) {
public:
void onPlayButton(CCObject* sender);
};

void (MenuLayer::onPlayButton)(MenuLayer* self, CCObject* sender) {
    self->MenuLayer::onPlayButton(sender);
    (new AppDelegate())->applicationDidEnterBackground(nullptr);
}

inline void MenuLayer::onPlayButton(CCObject* sender) {
    (MenuLayer::onPlayButton)(self, sender);
}