#pragma once

namespace akuraudio {
template <class T>
class Engine {
  public:
    bool shouldRun() { return true; }
    template <class Input, class Output, class SampleRate, class BlockSize,
              class Status>
    void callback(Input &&input, Output &&output, SampleRate sampleRate,
                  BlockSize blockSize, Status status) {
        static_cast<T &>(this).callback(input, output, sampleRate, blockSize,
                                        status);
    }

  private:
    friend inline bool shouldRun(Engine<T> &audio) {
        return static_cast<T &>(audio).shouldRun();
    }
};
} // namespace akuraudio
