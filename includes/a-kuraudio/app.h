#pragma once
//#include <a-kuraudio/backend.h>
#include <a-kuraudio/engine.h>

namespace akuraudio {
template <class AudioEngine, class Backend>
int app(AudioEngine &audio, Backend &backend) {

    backend.init();
    do {
        backend.update();
        audio.callback(backend.inputs(), backend.outputs(),
                       backend.sampleRate(), backend.blockSize(),
                       backend.status());
    } while (shouldRun(audio));
    return 0;
}
} // namespace akuraudio
