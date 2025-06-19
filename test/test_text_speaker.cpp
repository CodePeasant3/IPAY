
#include <Common/mp3player.h>
#include <iostream>
#include <thread>
#include <chrono>

int main(int argc, char** argv) {

    MP3Player   obj;
    obj.preloadMultiple({{"1", ":/Resources/audio/pay_failed.mp3"},
                         {"2", ":/Resources/audio/pay_failed.mp3"},
                         {"3", ":/Resources/audio/refund_success.mp3"}});
    obj.setVolume(100);
    obj.play("1");

    std::this_thread::sleep_for(std::chrono::seconds(3));
    return 0;
}
