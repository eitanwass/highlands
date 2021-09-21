#include <iostream>
#include <string>
#include "core/Game.h"

int main() {
    // For x11 gui forwarding
    setenv("DISPLAY", "127.0.0.1:0.0", false);

    Game game{};
    game.run();

    return 0;
}
