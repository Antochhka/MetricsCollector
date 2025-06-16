#pragma once

#include "../MetricsCollector/MetricsCollector.hpp"
#include "../MetricsCollector/Metric.hpp"
#include "../MetricsCollector/IMetric.hpp"

using namespace std;

#define CORES 4

enum class metric : int {
    CPU = 1,
    HTTP = 2,
    RAM = 3

};
/**
 * @brief Генерирует и добавляет случайные метрики: загрузку CPU, количество HTTP-запросов и использование RAM.
 * 
 * Функция создает три метрики со случайными значениями:
 * - "CPU" — дробное значение от 0 до CORES (используется `uniform_real_distribution`)
 * - "HTTP request" — целое значение от 20 до 150
 * - "RAM" — целое значение от 500 до 8000
 * 
 * Все сгенерированные метрики добавляются в переданный объект `MetricsCollector`.
 *
 * @param metrics Ссылка на объект MetricsCollector, в который будут добавлены метрики.
 */
void add_random_event(MetricsCollector & metrics);

