#include "database.hpp"
#include <sqlite3.h>
#include <iostream>

bool initializeDatabase()
{
    sqlite3* db = nullptr;

    if (sqlite3_open("goto.db", &db) != SQLITE_OK)
    {
        std::cerr << "Не удалось открыть базу: "
                  << (db ? sqlite3_errmsg(db) : "ошибка памяти") << '\n';
        if (db)
            sqlite3_close(db);
        return false;
    }

    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            login TEXT NOT NULL UNIQUE,
            password_hash TEXT NOT NULL,
            phone TEXT NOT NULL
        );
    )";

    char* errorMessage = nullptr;
    const int result = sqlite3_exec(db, sql, nullptr, nullptr, &errorMessage);

    if (result != SQLITE_OK)
    {
        std::cerr << "Не удалось создать таблицу: "
                  << (errorMessage ? errorMessage : "неизвестная ошибка") << '\n';
        sqlite3_free(errorMessage);
        sqlite3_close(db);
        return false;
    }

    sqlite3_close(db);
    std::cout << "База данных готова.\n";
    return true;
}

bool registerUser(const std::string& login,
                  const std::string& password,
                  const std::string& phone)
{
    if (login.empty() || password.empty() || phone.empty())
    {
        std::cerr << "Заполните все поля регистрации.\n";
        return false;
    }

    sqlite3* db = nullptr;
    if (sqlite3_open("goto.db", &db) != SQLITE_OK)
    {
        std::cerr << "Не удалось открыть базу для регистрации.\n";
        if (db)
            sqlite3_close(db);
        return false;
    }

    sqlite3_stmt* statement = nullptr;
    const char* sql =
        "INSERT INTO users(login, password_hash, phone) VALUES(?, ?, ?)";

    if (sqlite3_prepare_v2(db, sql, -1, &statement, nullptr) != SQLITE_OK)
    {
        std::cerr << "Ошибка SQL: " << sqlite3_errmsg(db) << '\n';
        sqlite3_close(db);
        return false;
    }

    sqlite3_bind_text(statement, 1, login.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(statement, 2, password.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(statement, 3, phone.c_str(), -1, SQLITE_TRANSIENT);

    const bool success = sqlite3_step(statement) == SQLITE_DONE;

    if (!success)
        std::cerr << "Регистрация не удалась. Возможно, такой логин уже занят.\n";

    sqlite3_finalize(statement);
    sqlite3_close(db);
    return success;
}

bool loginUser(const std::string& login, const std::string& password)
{
    if (login.empty() || password.empty())
    {
        std::cerr << "Введите логин и пароль.\n";
        return false;
    }

    sqlite3* db = nullptr;
    if (sqlite3_open("goto.db", &db) != SQLITE_OK)
    {
        std::cerr << "Не удалось открыть базу для входа.\n";
        if (db)
            sqlite3_close(db);
        return false;
    }

    sqlite3_stmt* statement = nullptr;
    const char* sql = "SELECT password_hash FROM users WHERE login = ? LIMIT 1";

    if (sqlite3_prepare_v2(db, sql, -1, &statement, nullptr) != SQLITE_OK)
    {
        std::cerr << "Ошибка SQL: " << sqlite3_errmsg(db) << '\n';
        sqlite3_close(db);
        return false;
    }

    sqlite3_bind_text(statement, 1, login.c_str(), -1, SQLITE_TRANSIENT);

    bool success = false;
    if (sqlite3_step(statement) == SQLITE_ROW)
    {
        const auto* storedPassword =
            reinterpret_cast<const char*>(sqlite3_column_text(statement, 0));

        success = storedPassword && password == storedPassword;
    }

    if (!success)
        std::cerr << "Неверный логин или пароль.\n";

    sqlite3_finalize(statement);
    sqlite3_close(db);
    return success;
}
