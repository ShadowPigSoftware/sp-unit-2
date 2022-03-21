#pragma once

#include "fixture.hpp"

namespace SPUnit {
    class GlobalFixture: public Fixture {
        friend class Runner;
    public:
        GlobalFixture();
    private:
        void run(Reporter& reporter) override;
    };
    
    //reference for the global fixture (nullptr)
    extern ::SPUnit::GlobalFixture _global_spunit_fixture;
}
