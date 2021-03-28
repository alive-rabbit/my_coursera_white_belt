#include <exception>
#include <system_error>

class TimeServer 
{
public:
    std::string GetCurrentTime()
    {
        // поместим вызов функции AskTimeServer в try-catch блок
        try 
        {
            last_fetched_time = AskTimeServer();
        }
        catch (const std::system_error&)
        {  // ловим только system_error
        }
        // возвращаем значение поля — либо обновлённое, либо нет
        return last_fetched_time;
    }

private:
    std::string last_fetched_time = "00:00:00";
};