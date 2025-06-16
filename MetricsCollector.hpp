#pragma once

#include "IMetric.hpp"
#include <vector>
#include <memory>
#include <thread>
#include <mutex>
#include <atomic>
#include <string>
#include <iostream>

/**
 * @brief Класс для сбора и периодического сохранения метрик в лог-файл.
 */
class MetricsCollector {
private:
    std::vector<std::shared_ptr<IMetric>> metrics;
    std::thread work_thread;
    std::mutex mtx;
    std::atomic<bool> flag{false};

public:
    /**
     * @brief Конструктор. Запускает рабочий поток.
     */
    MetricsCollector();

    /**
     * @brief Деструктор. Завершает рабочий поток.
     */
    ~MetricsCollector();

    /**
     * @brief Добавить метрику в очередь на запись.
     * 
     * @param metric Умный указатель на метрику.
     */
    void add_metric(std::shared_ptr<IMetric> metric);

private:
    /**
     * @brief Фоновый рабочий процесс для периодической записи метрик в файл.
     */
    void work_process();

    /**
     * @brief Записать метрики в файл.
     * 
     * @param filename Имя файла.
     * @param metrics_copy Копия метрик, которую нужно записать.
     */
    void write_to_file(const std::string &filename, const std::vector<std::shared_ptr<IMetric>> &metrics_copy);

    /**
     * @brief Сформировать строку лога из метрик.
     * 
     * @param metrics_copy Список метрик.
     * @return Строка для записи в файл.
     */
    std::string create_log(const std::vector<std::shared_ptr<IMetric>> &metrics_copy);

    void process_message();
};
