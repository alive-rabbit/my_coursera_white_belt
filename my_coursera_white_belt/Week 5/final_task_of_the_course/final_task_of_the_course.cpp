#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

class Date 
{
public:
    // конструктор выбрасывает исключение, если его аргументы некорректны
    Date(int new_year, int new_month, int new_day) 
    {
        year = new_year;
        if (new_month > 12 || new_month < 1) 
        {
            throw std::logic_error("Month value is invalid: " + std::to_string(new_month));
        }
        month = new_month;
        if (new_day > 31 || new_day < 1) 
        {
            throw std::logic_error("Day value is invalid: " + std::to_string(new_day));
        }
        day = new_day;
    }

    int GetYear() const 
    {
        return year;
    }
    int GetMonth() const 
    {
        return month;
    }
    int GetDay() const 
    {
        return day;
    }

private:
    int year;
    int month;
    int day;
};

// определить сравнение для дат необходимо для использования их в качестве ключей словаря
bool operator<(const Date& lhs, const Date& rhs) 
{
    return std::vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
        std::vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

// даты будут по умолчанию выводиться в нужном формате
std::ostream& operator<<(std::ostream& stream, const Date& date) 
{
    stream << std::setw(4) << std::setfill('0') << date.GetYear() <<
        "-" << std::setw(2) << std::setfill('0') << date.GetMonth() <<
        "-" << std::setw(2) << std::setfill('0') << date.GetDay();
    return stream;
}

class Database 
{
public:
    void AddEvent(const Date& date, const std::string& event) 
    {
        storage[date].insert(event);
    }

    bool DeleteEvent(const Date& date, const std::string& event) 
    {
        if (storage.count(date) > 0 && storage[date].count(event) > 0) 
        {
            storage[date].erase(event);
            return true;
        }
        return false;
    }

    int DeleteDate(const Date& date) 
    {
        if (storage.count(date) == 0) 
        {
            return 0;
        }
        else 
        {
            const int event_count = storage[date].size();
            storage.erase(date);
            return event_count;
        }
    }

    std::set<std::string> Find(const Date& date) const
    {
        if (storage.count(date) > 0) 
        {
            return storage.at(date);
        }
        else 
        {
            return {};
        }
    }

    void Print() const 
    {
        for (const auto& item : storage) 
        {
            for (const std::string& event : item.second) 
            {
                std::cout << item.first << " " << event << std::endl;
            }
        }
    }

private:
    std::map<Date, std::set<std::string>> storage;
};

Date ParseDate(const std::string& date) 
{
    std::istringstream date_stream(date);
    bool ok = true;

    int year;
    ok = ok && (date_stream >> year);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int month;
    ok = ok && (date_stream >> month);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int day;
    ok = ok && (date_stream >> day);
    ok = ok && date_stream.eof();

    if (!ok) 
    {
        throw std::logic_error("Wrong date format: " + date);
    }
    return Date(year, month, day);
}

int main() 
{
    try 
    {
        Database db;

        std::string command_line;
        while (std::getline(std::cin, command_line)) 
        {
            std::stringstream ss(command_line);

            std::string command;
            ss >> command;

            if (command == "Add")
            {

                std::string date_str, event;
                ss >> date_str >> event;
                const Date date = ParseDate(date_str);
                db.AddEvent(date, event);

            }
            else if (command == "Del") 
            {

                std::string date_str;
                ss >> date_str;
                std::string event;
                if (!ss.eof()) 
                {
                    ss >> event;
                }
                const Date date = ParseDate(date_str);
                if (event.empty()) 
                {
                    const int count = db.DeleteDate(date);
                    std::cout << "Deleted " << count << " events" << std::endl;
                }
                else 
                {
                    if (db.DeleteEvent(date, event)) 
                    {
                        std::cout << "Deleted successfully" << std::endl;
                    }
                    else 
                    {
                        std::cout << "Event not found" << std::endl;
                    }
                }
            }
            else if (command == "Find") 
            {
                std::string date_str;
                ss >> date_str;
                const Date date = ParseDate(date_str);
                for (const std::string& event : db.Find(date)) 
                {
                    std::cout << event << std::endl;
                }
            }
            else if (command == "Print") 
            {
                db.Print();
            }
            else if (!command.empty()) 
            {
                throw std::logic_error("Unknown command: " + command);
            }
        }
    }
    catch (const std::exception& e) 
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}