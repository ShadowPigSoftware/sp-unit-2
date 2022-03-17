#include "fixture/global_fixture.hpp"

namespace SPUnit {
    GlobalFixture::GlobalFixture():
        Fixture{}
    {}

    void GlobalFixture::run(Reporter& reporter, OutputStream& stream) const {
        for (const Runnable* runnable: _runnables) {
            Fixture::run(runnable, reporter, stream);
        }
    }
    
    ::SPUnit::GlobalFixture _global_spunit_fixture;
    ::SPUnit::Fixture* const _spunit_fixture = &_global_spunit_fixture;
}
