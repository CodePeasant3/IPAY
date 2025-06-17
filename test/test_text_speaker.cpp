
#include <Common/mp3player.h>
#include <iostream>
#include <thread>
#include <chrono>

int main(int argc, char** argv) {

    MP3Player   obj;
    obj.preloadMultiple({{"1", "C:/Users/juhao/Desktop/pay_success.mp3"},
                         {"2", "C:/Users/juhao/Desktop/pay_failed.mp3"},
                         {"3", "C:/Users/juhao/Desktop/refund_success.mp3"}});
    obj.setVolume(100);
    obj.play("1");

    std::this_thread::sleep_for(std::chrono::seconds(3));
    return 0;
}
