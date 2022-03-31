#include "fixture/global_fixture.hpp"
#include "runner/reporter.hpp"
namespace SPUnit {
    GlobalFixture::GlobalFixture():
        Fixture{}
    {}

    void GlobalFixture::run(Reporter& reporter) {
        for (Runnable* runnable: _runnables) {
            Fixture::run(runnable, reporter);
        }
        reporter.finalize();
    }
    
    ::SPUnit::GlobalFixture _global_spunit_fixture;
}

::SPUnit::Fixture* const _spunit_fixture = &::SPUnit::_global_spunit_fixture;
