#pragma once

#include "IMetric.hpp"
#include <string>
#include <sstream>
#include <iomanip>
#include <chrono>

/**
 * @brief Шаблонный класс метрики, реализующий интерфейс IMetric.
 * 
 * @tparam T Тип значения метрики (например, int, double).
 */
template <typename T>
class Metric : public IMetric {
private:
    std::string event_time;
    std::string event_name;
    T event_value;

public:
    /**
     * @brief Конструктор метрики.
     * 
     * @param event_name Имя метрики.
     * @param value Значение метрики.
     */
    Metric(const std::string &event_name, const T &value)
        : event_time(get_current_time()), event_name(event_name), event_value(value) {}

    /**
     * @brief Получить имя метрики.
     * @return Строка с именем метрики.
     */
    std::string get_name() const override {
        return this->event_name;
    }

    /**
     * @brief Получить значение метрики в строковом виде.
     * @return Строка с числом, форматированным с двумя знаками после запятой.
     */
    std::string get_value() const override {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2) << this->event_value;
        return ss.str();
    }

    /**
     * @brief Получить метку времени.
     * @return Время в формате YYYY-MM-DD HH:MM:SS.mmm.
     */
    std::string get_time() const override {
        return this->event_time;
    }

private:
    /**
     * @brief Получить текущую временную метку.
     * @return Строка с текущим временем.
     */
    static std::string get_current_time() {
        using namespace std::chrono;
        auto now = system_clock::now();
        auto ms = duration_cast<milliseconds>(now.time_since_epoch()) % 1000;
        std::time_t t = system_clock::to_time_t(now);
        std::tm local_tm = *std::localtime(&t);

        std::stringstream ss;
        ss << std::put_time(&local_tm, "%Y-%m-%d %H:%M:%S");
        ss << '.' << std::setfill('0') << std::setw(3) << ms.count();
        return ss.str();
    }
};
