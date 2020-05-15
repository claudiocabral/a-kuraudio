#define CATCH_CONFIG_MAIN
#include <a-kuraudio/app.h>
#include <catch.hpp>

TEST_CASE("Instantiate app", "[compilation]") {
    class TestEngine : public akuraudio::Engine<TestEngine> {
      public:
        bool shouldRun() { return false; }
        void callback(int input, int output, int sampleRate, int blockSize,
                      int status) {
            (void)input;
            (void)output;
            (void)sampleRate;
            (void)blockSize;
            (void)status;
        }
    };
    class Backend {
      public:
        void init() {}
        void update() {}
        int inputs() { return 1; }
        int outputs() { return 1; }
        int sampleRate() { return 1; }
        int blockSize() { return 1; }
        int status() { return 1; }
    };
    TestEngine audio;
    Backend backend;
    akuraudio::app(audio, backend);
}
