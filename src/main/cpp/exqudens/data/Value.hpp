#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <variant>
#include <vector>
#include <map>

#include "exqudens/data/export.hpp"

namespace exqudens::data {

    class EXQUDENS_JSON_EXPORT Value {

        private:

            std::variant<std::nullptr_t, bool, long double, intmax_t, std::string, std::vector<exqudens::data::Value>, std::map<std::string, exqudens::data::Value>> data;

        public:

            Value& setNull();

            Value& setBoolean(bool value);

            Value& setNumber(long double value);

            Value& setInteger(intmax_t value);

            Value& setString(const std::string& value);

            Value& setArray(const std::vector<exqudens::data::Value>& value);

            Value& setObject(const std::map<std::string, exqudens::data::Value>& value);

            bool isNull() const;

            bool isBoolean() const;

            bool isNumber() const;

            bool isInteger() const;

            bool isString() const;

            bool isArray() const;

            bool isObject() const;

            std::nullptr_t getNull() const;

            bool getBoolean() const;

            long double getNumber() const;

            intmax_t getInteger() const;

            std::string getString() const;

            std::vector<exqudens::data::Value> getArray() const;

            std::map<std::string, exqudens::data::Value> getObject() const;

            std::variant<std::nullptr_t, bool, long double, intmax_t, std::string, std::vector<exqudens::data::Value>, std::map<std::string, exqudens::data::Value>> getData() const;

            bool operator==(const Value& other) const;

            bool operator!=(const Value& other) const;
    };
}

// implementation ---

namespace exqudens::data {

    EXQUDENS_JSON_INLINE Value& Value::setNull() {
        data = nullptr;
        return *this;
    }

    EXQUDENS_JSON_INLINE Value& Value::setBoolean(bool value) {
        data = value;
        return *this;
    }

    EXQUDENS_JSON_INLINE Value& Value::setNumber(long double value) {
        data = value;
        return *this;
    }

    EXQUDENS_JSON_INLINE Value& Value::setInteger(intmax_t value) {
        data = value;
        return *this;
    }

    EXQUDENS_JSON_INLINE Value& Value::setString(const std::string& value) {
        data = value;
        return *this;
    }

    EXQUDENS_JSON_INLINE Value& Value::setArray(const std::vector<exqudens::data::Value>& value) {
        data = value;
        return *this;
    }

    EXQUDENS_JSON_INLINE Value& Value::setObject(const std::map<std::string, exqudens::data::Value>& value) {
        data = value;
        return *this;
    }

    EXQUDENS_JSON_INLINE bool Value::isNull() const {
        return std::holds_alternative<std::nullptr_t>(data);
    }

    EXQUDENS_JSON_INLINE bool Value::isBoolean() const {
        return std::holds_alternative<bool>(data);
    }

    EXQUDENS_JSON_INLINE bool Value::isNumber() const {
        return std::holds_alternative<long double>(data);
    }

    EXQUDENS_JSON_INLINE bool Value::isInteger() const {
        return std::holds_alternative<intmax_t>(data);
    }

    EXQUDENS_JSON_INLINE bool Value::isString() const {
        return std::holds_alternative<std::string>(data);
    }

    EXQUDENS_JSON_INLINE bool Value::isArray() const {
        return std::holds_alternative<std::vector<exqudens::data::Value>>(data);
    }

    EXQUDENS_JSON_INLINE bool Value::isObject() const {
        return std::holds_alternative<std::map<std::string, exqudens::data::Value>>(data);
    }

    EXQUDENS_JSON_INLINE std::nullptr_t Value::getNull() const {
        return std::get<std::nullptr_t>(data);
    }

    EXQUDENS_JSON_INLINE bool Value::getBoolean() const {
        return std::get<bool>(data);
    }

    EXQUDENS_JSON_INLINE long double Value::getNumber() const {
        return std::get<long double>(data);
    }

    EXQUDENS_JSON_INLINE intmax_t Value::getInteger() const {
        return std::get<intmax_t>(data);
    }

    EXQUDENS_JSON_INLINE std::string Value::getString() const {
        return std::get<std::string>(data);
    }

    EXQUDENS_JSON_INLINE std::vector<exqudens::data::Value> Value::getArray() const {
        return std::get<std::vector<exqudens::data::Value>>(data);
    }

    EXQUDENS_JSON_INLINE std::map<std::string, exqudens::data::Value> Value::getObject() const {
        return std::get<std::map<std::string, exqudens::data::Value>>(data);
    }

    EXQUDENS_JSON_INLINE std::variant<std::nullptr_t, bool, long double, intmax_t, std::string, std::vector<exqudens::data::Value>, std::map<std::string, exqudens::data::Value>> Value::getData() const {
        return data;
    }

    EXQUDENS_JSON_INLINE bool Value::operator==(const Value& other) const = default;

    EXQUDENS_JSON_INLINE bool Value::operator!=(const Value& other) const = default;
}
