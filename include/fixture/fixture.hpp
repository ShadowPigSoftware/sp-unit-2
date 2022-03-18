#pragma once

#include "common/runnable.hpp"
#include "common/common_flags.hpp"
#include "fixture_scenario_attorney.hpp"
#include "fixture_before_each_attorney.hpp"
#include "fixture_after_each_attorney.hpp"
#include "fixture_before_attorney.hpp"
#include "fixture_after_attorney.hpp"

namespace SPUnit {
    class Scenario;
    class BeforeEach;
    class AfterEach;
    class After;
    class Before;
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
    private:
        friend class Internal::FixtureBeforeEachAttorney;
        void addBeforeEach(const BeforeEach& beforeEach);
    private:
        friend class Internal::FixtureAfterEachAttorney;
        void addAfterEach(const AfterEach& afterEach);
    private:
        friend class Internal::FixtureBeforeAttorney;
        void addBefore(const Before& before);
    private:
        friend class Internal::FixtureAfterAttorney;
        void addAfter(const After& after);
    protected:
        void run(Reporter& reporter) const override;
        static void run(const Runnable* runnable, Reporter& reporter);
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
        RunnableList _beforeEachs;
        RunnableList _afterEachs;
        RunnableList _befores;
        RunnableList _afters;
    };

    extern ::SPUnit::Fixture* const _spunit_fixture;
}
