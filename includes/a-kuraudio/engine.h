#pragma once

namespace akuraudio {
template <class T>
class Engine {
  public:
    void callback() = delete;
    constexpr bool shouldRun() { return true; }

  private:
    friend inline bool shouldRun(Engine<T> &audio) {
        return static_cast<T &>(audio).shouldRun();
    }
    friend inline void callback(Engine<T> &audio) {
        static_cast<T &>(audio).callback();
    }
};
} // namespace akuraudio
