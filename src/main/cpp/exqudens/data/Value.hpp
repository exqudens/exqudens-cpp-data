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

            std::variant<std::nullptr_t, bool, long double, intmax_t, std::string, std::vector<Value>, std::map<std::string, Value>> data;

        public:

            Value& setNull();

            Value& setBoolean(bool value);

            Value& setNumber(long double value);

            Value& setInteger(intmax_t value);

            Value& setString(const std::string& value);

            Value& setArray(const std::vector<Value>& value);

            Value& setArray();

            Value& setObject(const std::map<std::string, Value>& value);

            Value& setObject();

            bool isNull() const;

            bool isBoolean() const;

            bool isNumber() const;

            bool isInteger() const;

            bool isString() const;

            bool isArray() const;

            bool isObject() const;

            Value& ifArrayAdd(const Value& value);

            Value& ifObjectSet(const std::string& key, const Value& value);

            std::nullptr_t asNull() const;

            bool asBoolean() const;

            long double asNumber() const;

            intmax_t asInteger() const;

            std::string asString() const;

            std::vector<Value> asArray() const;

            std::map<std::string, Value> asObject() const;

            std::variant<std::nullptr_t, bool, long double, intmax_t, std::string, std::vector<Value>, std::map<std::string, Value>> asVariant() const;

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

    EXQUDENS_JSON_INLINE Value& Value::setArray(const std::vector<Value>& value) {
        data = value;
        return *this;
    }

    EXQUDENS_JSON_INLINE Value& Value::setArray() {
        std::vector<Value> value = {};
        data = value;
        return *this;
    }

    EXQUDENS_JSON_INLINE Value& Value::setObject(const std::map<std::string, Value>& value) {
        data = value;
        return *this;
    }

    EXQUDENS_JSON_INLINE Value& Value::setObject() {
        std::map<std::string, Value> value = {};
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
        return std::holds_alternative<std::vector<Value>>(data);
    }

    EXQUDENS_JSON_INLINE bool Value::isObject() const {
        return std::holds_alternative<std::map<std::string, Value>>(data);
    }

    EXQUDENS_JSON_INLINE Value& Value::ifArrayAdd(const Value& value) {
        if (isArray()) {
            std::get<std::vector<Value>>(data).emplace_back(value);
        }
        return *this;
    }

    EXQUDENS_JSON_INLINE Value& Value::ifObjectSet(const std::string& key, const Value& value) {
        if (isObject()) {
            std::get<std::map<std::string, Value>>(data).insert_or_assign(key, value);
        }
        return *this;
    }

    EXQUDENS_JSON_INLINE std::nullptr_t Value::asNull() const {
        return std::get<std::nullptr_t>(data);
    }

    EXQUDENS_JSON_INLINE bool Value::asBoolean() const {
        return std::get<bool>(data);
    }

    EXQUDENS_JSON_INLINE long double Value::asNumber() const {
        return std::get<long double>(data);
    }

    EXQUDENS_JSON_INLINE intmax_t Value::asInteger() const {
        return std::get<intmax_t>(data);
    }

    EXQUDENS_JSON_INLINE std::string Value::asString() const {
        return std::get<std::string>(data);
    }

    EXQUDENS_JSON_INLINE std::vector<Value> Value::asArray() const {
        return std::get<std::vector<Value>>(data);
    }

    EXQUDENS_JSON_INLINE std::map<std::string, Value> Value::asObject() const {
        return std::get<std::map<std::string, Value>>(data);
    }

    EXQUDENS_JSON_INLINE std::variant<std::nullptr_t, bool, long double, intmax_t, std::string, std::vector<Value>, std::map<std::string, Value>> Value::asVariant() const {
        return data;
    }

    EXQUDENS_JSON_INLINE bool Value::operator==(const Value& other) const = default;

    EXQUDENS_JSON_INLINE bool Value::operator!=(const Value& other) const = default;
}
