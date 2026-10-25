#pragma once

#include <string>
#include <filesystem>

#include <gtest/gtest.h>

#include "TestUtils.hpp"
#include "exqudens/data/Value.hpp"

#define CALL_INFO std::string(__FUNCTION__) + "(" + std::filesystem::path(__FILE__).filename().string() + ":" + std::to_string(__LINE__) + ")"

class ValueUnitTests : public testing::Test {

    protected:

        inline static const char* LOGGER_ID = "ValueUnitTests";

};

TEST_F(ValueUnitTests, test_1) {
    try {
        std::string testGroup = testing::UnitTest::GetInstance()->current_test_info()->test_suite_name();
        std::string testCase = testing::UnitTest::GetInstance()->current_test_info()->name();
        std::cout << LOGGER_ID << " " << '"' << testGroup << '.' << testCase << '"' << " bgn" << std::endl;

        intmax_t expectedInteger = 123;
        std::cout << LOGGER_ID << " expectedInteger: '" << expectedInteger << std::endl;

        std::string expectedString = "Abc123!";
        std::cout << LOGGER_ID << " expectedString: '" << expectedString << "'" << std::endl;

        exqudens::data::Value value = exqudens::data::Value()
        .setObject()
        .ifObjectSet("id", exqudens::data::Value().setInteger(expectedInteger))
        .ifObjectSet("name", exqudens::data::Value().setString(expectedString));

        std::cout << LOGGER_ID << " value.isObject: " << value.isObject() << std::endl;
        std::cout << LOGGER_ID << " value['id']: " << value.asObject().at("id").asInteger() << std::endl;
        std::cout << LOGGER_ID << " value['name']: '" << value.asObject().at("name").asString() << "'" << std::endl;

        ASSERT_TRUE(value.isObject());
        ASSERT_TRUE(expectedInteger == value.asObject().at("id").asInteger());
        ASSERT_TRUE(expectedString == value.asObject().at("name").asString());

        std::cout << LOGGER_ID << " " << '"' << testGroup << '.' << testCase << '"' << " end" << std::endl;
    } catch (const std::exception& e) {
        std::string errorMessage = TestUtils::toString(e);
        std::cout << LOGGER_ID << " ERROR: " << errorMessage << std::endl;
        FAIL() << errorMessage;
    }
}
