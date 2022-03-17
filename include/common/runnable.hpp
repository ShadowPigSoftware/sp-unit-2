#pragma once

namespace SPUnit {
    class Reporter;
    class OutputStream;

    class Runnable {
    public:
        virtual ~Runnable() = default;
    protected:
        friend class Fixture; //The Fixture class is allowed to run any runnable;
        virtual void run(Reporter& reporter, OutputStream& stream) const = 0;
    };
}
