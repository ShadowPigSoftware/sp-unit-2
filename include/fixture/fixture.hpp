#pragma once

#include "common/runnable.hpp"
#include "common/common_flags.hpp"
#include "fixture_scenario_attorney.hpp"

namespace SPUnit {
    class Scenario;
    class Fixture: public Runnable {
    public:
        using Flags = CommonFlags;
        Fixture(Fixture* parent, const char* description, const char* file, uint32_t line);
        Fixture(Fixture* parent, const char* description, const Flags& flags, const char* file, uint32_t line);

        const char* description() const;
    private:
        friend class Internal::FixtureScenarioAttorney;
        void addScenario(const Scenario& scenario);
        void addFixture(const Fixture& fixture);
    protected:
        void run(Reporter& reporter, OutputStream& stream) const override;
        static void run(const Runnable* runnable, Reporter& reporter, OutputStream& stream);
        Fixture();
    private:
        const Fixture* const _parent;
        const char* const _description;
        const Flags _flags;
        const char* const _file;
        const uint32_t _line;
    protected:
        using RunnableList = std::list<const Runnable*>;
        RunnableList _runnables;
    };

    extern ::SPUnit::Fixture* const _spunit_fixture;
}
