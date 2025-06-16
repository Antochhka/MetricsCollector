#pragma once

#include <string>

/**
 * @brief Интерфейс метрики. Определяет базовые методы получения имени, значения и времени события.
 */
class IMetric {
public:
    /**
     * @brief Получить имя метрики.
     * @return Имя метрики в виде строки.
     */
    virtual std::string get_name() const = 0;

    /**
     * @brief Получить значение метрики.
     * @return Значение метрики в виде строки.
     */
    virtual std::string get_value() const = 0;

    /**
     * @brief Получить метку времени метрики.
     * @return Время в формате YYYY-MM-DD HH:MM:SS.mmm.
     */
    virtual std::string get_time() const = 0;

    /**
     * @brief Виртуальный деструктор.
     */
    virtual ~IMetric() = default;
};
