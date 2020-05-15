#pragma once
#include <a-kuraudio/engine.h>

namespace akuraudio {
template <class AudioEngine, class Backend>
int app(AudioEngine &audio, Backend &backend) {

    backend.init();
    do {
        backend.fetch();
        callback(audio);
    } while (shouldRun(audio));
    return 0;
}
} // namespace akuraudio
