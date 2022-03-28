#include "expect/expect_failure_message.hpp"

namespace SPUnit {
    std::string ExpectFailureMessage::makeNoOperator(const std::string& name, const std::string& operatorString) {
        return std::string("The ") + name + " operator (" + operatorString + ") is not supported on these objects";
    }

    std::string ExpectFailureMessage::makeNoComparisonOperator()
    {
        return makeNoOperator("comparison", "==");
    }

    std::string ExpectFailureMessage::makeNoDifferenceOperator()
    {
        return makeNoOperator("difference", "!=");
    }

    std::string ExpectFailureMessage::makeNoGreaterThanOrEqualOperator()
    {
        return makeNoOperator("greater than or equal", ">=");
    }

    std::string ExpectFailureMessage::makeNoGreaterThanOperator()
    {
        return makeNoOperator("greater than", ">");
    }

    std::string ExpectFailureMessage::makeNoLessThanOrEqualOperator()
    {
        return makeNoOperator("less than or equal", "<=");
    }

    std::string ExpectFailureMessage::makeNoLessThanOperator()
    {
        return makeNoOperator("greater than", "<");
    }

    std::string ExpectFailureMessage::makeNoThresholdOperator()
    {
        return makeNoOperator("threshold", "e-t <= a <= e+t");
    }
}